 // Windows header files
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <winuser.h>

#define ID_TIMER 102

 // Global Function Declarations / Function Prototype
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


// Global Variable Declarations
HWND ghwnd; // g-global hwnd-window handle
DWORD dwStyle = 0;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
BOOL gbFullscreen = FALSE;

int ballx, bally;		// Upper Left Corner
int xmov = 5, ymov = 5;		// x, y moving coords
int TimerSpeed = 40;
int ballsize = 100;

// Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// Local Variable Declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("SUMWindow");
	
	// Code
	// WNDCLASSEX Initialization
	wndclass.cbSize = sizeof(WNDCLASSEX);                                   //1
	wndclass.style = CS_HREDRAW | CS_VREDRAW;                               //2 
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
	// Change CreateWindow to CreateWindowEx
	// CreateWindowEx brings the Window above the task bar
	hwnd = CreateWindowEx(
		WS_EX_APPWINDOW,
		szAppName,
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

	ghwnd = hwnd;

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
LRESULT CALLBACK WndProc(HWND hwnd,
						 UINT iMsg,
						 WPARAM wParam, 
					     LPARAM lParam)

{
	// Function Declarations
	void ToggleFullscreen(void);

	// Code
	// Body of the callback() - WndProc [User Defined]

	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;

	static int wWidth, wHeight;
	static HBRUSH hbrBall;

	switch(iMsg)
	{
	case WM_CREATE:
		SetTimer(hwnd, ID_TIMER, TimerSpeed, NULL);
		break;

	case WM_SIZE:

		ToggleFullscreen();

		GetClientRect(hwnd, &rc);
		wWidth = rc.right - rc.left;
		wHeight = rc.bottom - rc.top;

		ballx = wWidth / 2;
		bally = wHeight / 2;
		
		break;

	case WM_TIMER:
		KillTimer(hwnd, ID_TIMER);

		ballx = ballx + xmov;
		bally = bally + ymov;

		if (ballx + ballsize >= wWidth || ballx <= 0)
		{
			xmov = -xmov;
			DeleteObject(hbrBall);
			hbrBall = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		}

		if (bally + ballsize >= wHeight || bally <= 0)
		{
			ymov = -ymov;
			DeleteObject(hbrBall);
			hbrBall = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		}

		InvalidateRect(hwnd, NULL, TRUE);
		SetTimer(hwnd, ID_TIMER, TimerSpeed, NULL);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		SelectObject(hdc, hbrBall);
		Ellipse(hdc, ballx, bally, ballx + ballsize, bally + ballsize);

		EndPaint(hwnd, &ps);
			break;

	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_ESCAPE:
			DestroyWindow(hwnd);
				break;
		}
	break;

	case WM_CHAR:
		switch (LOWORD(wParam))
		{
		case 'F':
		case 'f':
			
			ToggleFullscreen();
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

void ToggleFullscreen(void)
{
	// Local Variable Declarations
	MONITORINFO mi = { sizeof(MONITORINFO) };

	// code
	if (gbFullscreen == FALSE)		// 1
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);		// a

		if (dwStyle & WS_OVERLAPPEDWINDOW)		// b
		{
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))		// i and ii
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);		// iii - A
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);		// iii - B
			}
		}
		ShowCursor(FALSE);

		gbFullscreen = TRUE;
	}
	else // 2
	{
		SetWindowPlacement(ghwnd,&wpPrev);		// a
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);		//b
		// SetWindowPos(ghwnd, GWL_STYLE | WS_OVERLAPPEDWINDOW);	//b
		// SetWindowStyle(ghwnd, GWL_STYLE | WS_OVERLAPPEDWINDOW);		//b
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);		// c
		
		ShowCursor(TRUE);

		gbFullscreen = FALSE;
	}
}











