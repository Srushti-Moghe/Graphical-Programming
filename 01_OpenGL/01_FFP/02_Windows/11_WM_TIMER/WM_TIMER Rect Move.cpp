 // Windows header files
#include <windows.h>
#define ID_TIMER 105

// Global Function Declarations / Function Prototype
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
// long_far_pascal WndProc(unsigned int, unsigned int, unsigned int, long); Calling Convention

// Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
// int WINAPI WinMain(HINSTANCE i, HINSTANCE j, LPSTR k, int k) Equivalent. But the standard CALLING CONVENTION needs to be followed.
{
	// Local Variable Declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("SUMWindow");
	// char str[] = "SUMWindow";
	// wchar_t >> typedef TCHAR
	
	// Code
	// WNDCLASSEX Initialization
	wndclass.cbSize = sizeof(WNDCLASSEX);                                   //1
	wndclass.style = CS_HREDRAW | CS_VREDRAW;                               //2 // Forces OS to send WM_PAINT to our window. Handling WM_PAINT for resizing
	wndclass.cbClsExtra = 0;                                                //3  
	wndclass.cbWndExtra = 0;                                                //4
	wndclass.lpfnWndProc = WndProc;                                         //5
	wndclass.hInstance = hInstance;                                         //6
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);           //7
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);                       //8
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);                         //9
	wndclass.lpszClassName = szAppName;                                     //10
	wndclass.lpszMenuName = NULL;                                           //11
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);                     //12

	// Register WNDCLASSEX
	RegisterClassEx(&wndclass);

	// Create the Window
	// The parameter - WS_OVERLAPPEDWINDOW commands window to be at the topmost position hence all the mouse clicks go to this particular window
	hwnd = CreateWindow(szAppName,
		TEXT("Srushti Umesh Moghe"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	// Show the Window
	ShowWindow(hwnd, iCmdShow);

	// Paint (or Redraw) the Window
	UpdateWindow(hwnd);

	// Message Loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return((int)msg.wParam);
}
// Claaback Function
// Always called by the O.S.
// WndProc is a user defined name
// HWND, UINT, WPARAM, LARAM - parameters and return value of callback function that are decided by the OS and cannot be changed by the user
LRESULT CALLBACK WndProc(HWND hwnd,
						 UINT iMsg,
						 WPARAM wParam, 
					     LPARAM lParam)

{
	// Code
	// Body of the callback() - WndProc [User Defined]

	HDC hdc;
	PAINTSTRUCT ps;
	static RECT rc;

	static int rect_left = 100, rect_top = 200;
	static int wHeight, wWidth;
	
	static int movx = 10, movy = 0;

	HBRUSH hbrColor;

	switch(iMsg)
	{

	case WM_CREATE:
		SetTimer(hwnd, ID_TIMER, 60, NULL);
		break;

	case WM_SIZE:
		GetClientRect(hwnd, &rc);
		wWidth = rc.right - rc.left;
		wHeight = rc.bottom - rc.top;

		break;

	case WM_TIMER:
		KillTimer(hwnd, ID_TIMER);

		rect_left = rect_left + movx;
		rect_top = rect_top + movy;

		if (rect_left >= wWidth)
		{
			rect_left = 0;
		}

		if (rect_left < 0)
		{
			rect_left = wWidth;
		}

		if (rect_top >= wHeight)
		{
			rect_top = 0;
		}

		if (rect_top < 0)
		{
			rect_top = wHeight;
		}

		InvalidateRect(hwnd, NULL, TRUE);
		// InvalidateRect(hwnd, NULL, FALSE);
		// InvalidateRect(hwnd, &rc, FALSE);

		SetTimer(hwnd, ID_TIMER, 60, NULL);
		break;

	case WM_PAINT:

		hdc = BeginPaint(hwnd, &ps);
		
		hbrColor = CreateSolidBrush(RGB(255, 0, 0));
		SelectObject(hdc, hbrColor);
		Rectangle(hdc, rect_left, rect_top, rect_left + 50, rect_top + 50);
		
		EndPaint(hwnd, &ps);
		break;

	case WM_KEYDOWN:
		switch (LOWORD(wParam)) 
		{
		case VK_UP:
			movy = -10;
			movx = 0;
		break;

		case VK_DOWN:
			movy = 10;
			movx = 0;
		break;

		case VK_RIGHT:
			movx = 10;
			movy = 0;
		break;

		case VK_LEFT:
			movx = -10;
			movy = 0;
		break;
		}
		break;
		
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}







