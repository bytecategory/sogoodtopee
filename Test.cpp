#include <windows.h>
HHOOK hhk = NULL;
HHOOK hhkk = NULL;
LRESULT CALLBACK KeyboardProc(int nCode,WPARAM wParam,LPARAM lParam)
{
	if (nCode==HC_ACTION) {
		return 1;
	}
	return CallNextHookEx(hhk, nCode, wParam, lParam);
}
int main() {
	hhk =SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, GetModuleHandle(NULL), 0);
	hhkk = SetWindowsHookEx(WH_MOUSE_LL,KeyboardProc,GetModuleHandle(NULL),0);
	MSG uMsg;
	while (GetMessageW(&uMsg,NULL,0,0)) {
		TranslateMessage(&uMsg);
		DispatchMessageW(&uMsg);
		
	}

}