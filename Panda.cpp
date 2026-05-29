#include <windows.h>
#include <stdio.h>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define _UNIDCODE
#define UNICODE
const wchar_t wangyichen[]=L"wang";
HINSTANCE jj;
/*
HINSTANCE 实例的句柄.这是内存中模块的基址
*/
HBITMAP hbitmap=NULL;
LRESULT CALLBACK SXSYMXSYY(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam) {
	switch (uMsg) {
		case WM_CLOSE: {
			return 0;
		}
		case WM_DESTROY: {
			return 0;
		}
		case WM_SIZE: {
			InvalidateRect(hwnd,NULL,TRUE);
			/*
			InvalidateRect函数将矩形添加到指定窗口的更新区域,更新区域表示
			必须重绘的窗口工作区部分.
			InvalidateRect function adds a rectangle to the specified window's update region.The Update region represents the portion of the window's client area that must be redrawn
			hwnd更新区域已更改的窗口的句柄.
			A handle to the window whose update region has changed
			lpRect参数为NULL,则整个工作区将添加到更新区域
			the parameter is NULL,the entire client area is added to the update region.
			bErase参数为TRUE,则调用BeginPaint函数时将擦除背景.
			the parameter is TRUE,the background is erased when the Beginpaint function is called.
			*/
			break;
		}
		case WM_CREATE: {
			/*
			当应用程序请求通过调用CreateWindowEx函数创建窗口时发送
			sent when an application requests that a window be created by
			calling the CreateWindowEx function
			新窗口的窗口程序在创建窗口之后但在窗口变为可见之前接受此消息.
			The Window procedure of the new window receives this message
			after the window is created,but before the window becomes visible.
			#define WM_CREATE 0x0001
			*/
			hbitmap = (HBITMAP)LoadImageW(
			NULL,
			/*
			若要加载预定义的图像或独立资源(位图文件),请将此参数设置为NULL
			To load a predefined image or a standalone resource(bitmap file) set this parameter to NULL
			*/
			L"C:/Users/Administrator/Desktop/449.bmp",
			IMAGE_BITMAP,
			/*要加载的图像类型
			The Type of image to be load
			IMAGE_BITMAP:加载位图. loads a bitmap.
			*/
			0,
			/*图标的宽度(以像素为单位).
			the width,in pixels,of the icon
			*/
			0,
			/*
			图标的高度(以像素为单位).
			the height,in pixels,of the icon
			*/
			LR_LOADFROMFILE
			/*
			从名称(位图文件)指定的文件中加载独立图像.
			Loads the standalone image from the file specified by 
			name(bitmap file)
			*/
			);
			break;
		}
		case WM_ERASEBKGND:
			/*
			当必须擦除窗口背景时发送(例如,在调整窗口大小时发送).
			Sent when the window background must be erased(for example
			when a window is resized)
			发送该消息是为了准备用于绘制的窗口的无效部分.
			the message is sent to prepare an invalidated portion of a window for painting 
			#define WM_ERASEBKGND 0x0014
			*/
			return 0;
		case WM_PAINT: {
			
			//PAINTSTRUCT paintstruct;
			/*
			PAINTSTRUCT结构包含应用程序的信息.此信息可用于绘制该应用程序拥有的窗口的工作区.
			The PAINTSTRUCT structure contains information for an application.This information can be used to paint the client area of a window owned by that application.
			*/
			//HDC hdc=BeginPaint(hwnd,&paintstruct);
			/*
			BeginPaint函数准备用于绘制的指定窗口,并使用有关绘制的信息填充PAINTSTRUCT结构.
			The BeginPaint function prepares the specified window for painting and fills a PAINTSTRUCT structure with information about the painting.
			hwnd:要重新绘制的窗口的句柄.
			Handle to the window to be repainted 
			&paintstruct:指向将接受绘制信息PAINTSTRUCT结构的指针.
			Pointer to the PAINTSTRUCT structure that will receive painting information.
			指针是一个变量,可以存储一个对象的内存地址.
			A pointer is a variable that stores the memory address of an object
			*/
			//HDC hdcSrc=CreateCompatibleDC(hdc);
			/*
			CreateCompatibleDC函数创建与指定设备兼容的内存设备上下文.
			The CreateCompatibleDC function creates a memory device context(DC) compatible with the specified device.
			hdc现有DC的句柄.
			A handle to an existing DC.
			内存设备上下文.
			Memory Device Contexts.
			若要使应用程序能够将输出置于内存中,而不是将其发送给实际设备
			To enable applications to place output in memory rather than sending it to an actual device.
			请使用特殊的设备上下文进行位图操作,称为内存设备上下文
			use a special context for bitmap operations called a memory device context.
			位图是一个图形对象.
			A bitmap is a graphical object used to create.
			*/
			//HBITMAP selectobjecthbitmap=(HBITMAP)SelectObject(hdcSrc,hbitmap);
			/*HBITMAP 位图的句柄
			A handle to a bitmap
			*/
			//BITMAP bitmap;
			/*
			BITMAP结构定义位图的类型,宽度,高度,颜色格式和位值.
			*/
			//GetObject(hbitmap,sizeof(BITMAP),&bitmap);
			/*
			hbitmap:感兴趣的图形对象的句柄.
			An handle to the graphics object of interest.
			sizeof(BITMAP):要写入缓冲区的信息字节数.
			The number of bytes of information to be written to the buffer.
			&bitmap:指向接受指定图形对象相关信息的缓冲区的指针.
			A pointer to a buffer that receives the information about the specified graphics object.
			*/
			//RECT rect;
			/*
			RECT结构通过矩形的左下角和右下角的坐标来定义矩形.
			*/
			//GetClientRect(hwnd,&rect);
			/*
			hwnd:要检索其客户端坐标的窗口的句柄.
			a handle to the window whose client coordinates are to be retrieved.
			&rect:指向接收客户端坐标的RECT结构的指针.
			a pointer to a RECT structure that receives the client coordinates.
			*/
			//int x =(rect.right-bitmap.bmWidth) / 2;
			/*
			rect.right:指定矩形右下角的x坐标
			Specifies the x-coordinate of the lower-right corner of the rectangle.
			bitmap.bmWidth:位图的宽度.
			The width,in pixels,of the bitmap.
			*/
			//int y =(rect.bottom-bitmap.bmHeight) / 2;
			/*
			rect.bottom:指定矩形右下角的y坐标.
			specifies the y coordinate of the lower-right corner of the rectangle.
			bitmap.bmHeight:位图的高度.
			the height,in pixels,of the bitmap.
			*/
			//BitBlt(
			//hdc,
			/*
			目标设备上下文句柄.
			a handle to the destination device context
			*/
			//x,
			/*
			目标矩形左上角的x坐标
			the x-coordinate,of the upper-left corner of the destination rectangle.
			*/
			//y,
			/*
			目标矩形左上角的y坐标
			the y-coordinate,of the upper-left corner of the destination rectangle.
			*/
			//bitmap.bmWidth,
			/*
			目标矩形宽度.
			the width,of the destination rectangles
			*/
			//bitmap.bmHeight,
			/*
			目标矩形高度.
			the height,of the destination rectangles
			*/
			//hdcSrc,
			/*
			源设备上下文的句柄.
			a handle to the source device context
			*/
			//0,
			/*
			源矩形左上角的x坐标.
			the x-coordinate,of the upper-left corner of the source rectangle.
			*/
			//0,
			/*
			源矩形左上角的y坐标.
			the y-coordinate,of the upper-left corner of the source rectangle
			*/
			//SRCCOPY
			/*
			将原矩形直接复制到目标矩形.
			copies the source rectangle directly to the destination rectangle.		
			*/
			//);
			//SelectObject(hdcSrc,selectobjecthbitmap);
			/*
			将对象选择到指定的设备上下文中.
			select an object into the specified device cintext.			
			新对象替换上一个对象.
			The new object replaces the previous object.
			hdcSrc:DC的句柄.
			a handle to the DC
			selectobjecthbitmap:要选择的对象的句柄.
			a handle to the object to be selected
			*/
			//DeleteDC(hdcSrc);
			/*
			删除指定的设备上下文.
			delete the specified device context
			hdcSrc,设备上下文的句柄.
			A handle to the device context
			*/
			//EndPaint(hwnd,&paintstruct);
			/*
			EndPaint函数在指定窗口中标记绘制的结束.每次调用BeginPaint函数
			都需要此函数,但仅在绘制完成之后.
			hwnd 已重新绘制的窗口的句柄.
			Handle to the window that has been repainted 
			&paintstruct
			指向PAINTSTRUCT结构的指针.
			Pointer to a PAINTSTRUCT structure that contains the painting information retrieved by BeginPaint
			*/
			PAINTSTRUCT paintstruct;
			RECT rect;
			GetClientRect(hwnd,&rect);
			HDC hdc = BeginPaint(hwnd,&paintstruct);
			HFONT hfont = CreateFontW(
                55,                        
                0,                         
                0,                         
                0,                         
                FW_NORMAL,                 
                FALSE,                     
                FALSE,                     
                FALSE,                     
                DEFAULT_CHARSET,           
                OUT_OUTLINE_PRECIS,       
                CLIP_DEFAULT_PRECIS,       
                CLEARTYPE_QUALITY,        
                VARIABLE_PITCH,           
                L"SimSun"                
            );
			HFONT hselectfont = (HFONT)SelectObject(hdc,hfont);
			const wchar_t* content = L"好爽啊!\n我要尿尿.";
			SetTextColor(hdc,RGB(0,0,0));
			//DrawTextW(hdc,content,-1,&rect,DT_CENTER | DT_WORDBREAK | DT_LEFT | DT_TOP);
			DrawTextW(hdc,content,-1,&rect,DT_CENTER | DT_WORDBREAK | DT_LEFT | DT_VCENTER);
			SelectObject(hdc,hselectfont);
			DeleteObject(hfont);
			EndPaint(hwnd,&paintstruct);
			break;
		}
		default: {
			return DefWindowProcW(hwnd,uMsg,wParam,lParam);
			/*
			调用默认窗口过程,为应用程序未处理的任何窗口消息提供默认处理.
			Calls the default window procedure to provide default processing for any window messages that an application does not process.
			它使用窗口过程接收的相同参数调用.
			It is called with the same parameters received by the window procedure
			*/
		}
	}
	return 0;
}
bool USERCHENSIHAN(HINSTANCE hInstance) {
	WNDCLASSEXW w={};
	/*
	包含窗口类信息.
	*/
	w.cbSize = sizeof(WNDCLASSEXW);
	/*
	此结构的大小.
	*/
	w.style = CS_HREDRAW | CS_VREDRAW;
	/*
	CS_HREDRAW:如果移动或大小调整了更改了工作区的宽度,则重绘整个窗口.
	redraws the entire window if a movement or size adjustment changes the width of the client area
	CS_VREDRAW:如果移动或大小调整了更改了工作区的高度,则重绘整个窗口.
	redraws the entire window if a movement or size adjustment changes the height of the client area
	*/
	w.lpfnWndProc=SXSYMXSYY;
	/*
	指向窗口过程的指针.
	*/
	w.cbClsExtra=0;
	w.cbWndExtra=0;
	w.hInstance=hInstance;
	/*
	包含类的窗口过程的实例的句柄.
	a handle to the instance that contains the window procedure for the class.
	*/
	w.hIcon=LoadIconW(NULL,(LPCWSTR)IDI_APPLICATION);
	/*
	NULL:加载预定义的系统图标.
	load a predefined system icon
	IDI_APPLICATION:默认应用程序图标.
	default application icon
	*/
	w.hCursor=LoadCursorW(NULL,(LPCWSTR)IDC_NO);
	w.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
	//w.hbrBackground=NULL;
	w.lpszMenuName=NULL;
	w.lpszClassName=wangyichen;
	w.hIconSm=LoadIconW(NULL,(LPCWSTR)IDI_APPLICATION);
	return RegisterClassExW(&w);
	/*
	注册一个窗口类,以便在调用CreateWindowEx函数时使用
	Registers a window class for subsequent use in calls to the CreateWindowEx function
	&w 指向WNDCLASSEX结构的指针.
	A pointer to a WNDCLASSEXW structure
	*/
}
HWND PM(HINSTANCE hInstance,int z,int y) {
	HWND hwnd = CreateWindowExW(
	/*
	创建重叠窗口.
	Create overlapped windows
	*/
	0,//optional window style
	wangyichen,
	/*
	类名是注册到RegisterClassEx的名称
	the class name is a name that registered with RegisterClassEx
	*/
	NULL,
	/*
	窗口名称.
	The window name
	*/
	WS_OVERLAPPEDWINDOW,
	/*
	窗口是重叠的窗口
	The window is an overlapped window
	*/
	z,
	/*
	窗口左上角的初始x坐标
	the x parameter is the initial x-coordinate of the window's upper-left corner.
	*/
	y,
	/*
	窗口左上角的初始y坐标
	the y parameter is the initial y-coordinate of the upper-left corner.
	*/
	300,
	/*
	CW_USEDEFAULT
	选择窗口的默认宽度和高度.
	selects a default width and height for the window.
	仅适用于重叠窗口.
	is valid only for overlapped windows
	*/
	160,
	/*
	CW_USEDEFAULT
	忽略该参数.
	ignores nHeight
	*/
	NULL,
	/*
	正在创建的父窗口句柄.
	a handle to the parent window of the window being created 
	*/
	NULL,
	/*
	菜单的句柄.
	a handle to a menu
	*/
	hInstance,
	/*
	模块实例的句柄.
	a handle to the instance of the module.
	*/
	NULL
	/*
	不需要其他数据.
	no additional data is needed
	*/
	);
	ShowWindow(hwnd,SW_SHOW);
	/*
	ShowWindow:设置指定窗口的显示状态.
	sets the specified window's show state
	hwnd:窗口的句柄.
	a handle to the window
	SW_SHOW:激活窗口并以当前大小和位置显示窗口.
	activates the window and displays it in its current size and position
	*/
	UpdateWindow(hwnd);	
	/*
	UpdateWindow函数通过向窗口发送WM_PAINT消息来更新指定窗口的工作区.
	The UpdateWindow function updates the client area of the specified window by sending a WM_PAINT message to the window.
	*/
}
int main() {
	HWND foregroundhwnd = GetForegroundWindow();
	ShowWindow(foregroundhwnd,SW_MINIMIZE);
	srand(static_cast<unsigned int>(time(0)));
	ShellExecuteW(NULL,(LPCWSTR)L"open",(LPCWSTR)L"C:\\Users\\Administrator\\Desktop\\test.exe",NULL,NULL,SW_HIDE);
	ShellExecuteW(NULL,(LPCWSTR)L"open",(LPCWSTR)L"C:\\Users\\Administrator\\Desktop\\wang.exe",NULL,NULL,SW_HIDE);
	HINSTANCE hInstance = GetModuleHandleW(NULL);
	/*
	返回用于创建调用进程的文件的句柄.
	returns a handle to the file used to create the calling process.
	*/
	jj=hInstance;
	/*
	int WINAPI WinMain-> main
	*/
	USERCHENSIHAN(hInstance);
	RECT record;
	SystemParametersInfo(SPI_GETWORKAREA,0,&record,0);
	/*
	SPI_GETWORKAREA:检索主显示器上工作区的大小.
	Retrieves the size of the work area on the primary display monitor.
	0:未另行指示.
	not otherwise.
	&record:指向接受工作区坐标的RECT结构.
	point to a RECT structure that receives the coordinates of the work area
	0:不更新用户配置文件或广播WM_SETTINGCHANGE消息.
	not to update the user profile or broadcast the WM_SETTINGCHANGE message.
	*/
	int a = (record.right-record.left);
	/*
	record.right:指定矩形右下角的x坐标
	specifies the x-coordinate of the lower-right corner of the rectangle
	record.left:指定矩形左上角的x坐标
	specifies the x-coordinate of the upper-left corner of the rectangle
	*/
	int b = (record.bottom-record.top);
	/*
	record.bottom:指定矩形右下角的y坐标.
	specifies the y-coordinate of the lower-right corner of the rectangle.
	record.top:指定矩形左上角的y坐标.
	specifies the y-coordinate of the upper-left corner of the rectangle.
	*/
	for (int l=0;l<242424;l++) {
		int z = rand() % a;
		int w = rand() % b;
		PM(hInstance,z,w);
		//Sleep(500);
		//z+=16;
		//y+=16;
		//if (z > a) z=0;
		//if (y > b) y=0;
		SetCursorPos(0,0);
			
	}
	MSG uMsg;
	/* 
	消息.
	message.
	*/
	while (GetMessageW(&uMsg,NULL,0,0)) {
		/*
		GetMessageW:从调用线程的消息队列中检索消息.
		&uMsg:指向从线程的消息队列中接收消息信息的MSG结构的指针.
		NULL:处理窗口消息和线程消息.
		0,0:返回所有可用消息.
		*/
		TranslateMessage(&uMsg);
		/*
		将虚拟键消息转化为字符消息.
		Translates virtual-key message.
		*/
		DispatchMessageW(&uMsg);
		/*
		将消息调度到窗口过程.
		dispatch a message to a window procedure.
		*/
	}
}
/*
g++ Box.cpp -mwindows -lgdi32 -luser32
wingdi.h标头 winuser.h标头
*/
