 // Windows header files
#include <windows.h>

#define ID_TIMER 102

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
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;
	HBRUSH hbrBackground;

	static int bColorFlag = 0;

	// Code
	// Body of the callback() - WndProc [User Defined]
	switch (iMsg)
	{
	case WM_CREATE:
		SetTimer(hwnd, ID_TIMER, 1000, NULL);
		break;

	case WM_TIMER:
		KillTimer(hwnd, ID_TIMER);

		bColorFlag++;
		if (bColorFlag > 11)
		{
			bColorFlag = 1;
		}

		InvalidateRect(hwnd, NULL, TRUE);


		SetTimer(hwnd, ID_TIMER, 1000, NULL);
		break;

	case WM_PAINT:

		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rc);

		if (bColorFlag == 1)
		{
			hbrBackground = CreateSolidBrush(RGB(255, 0, 0));
		}
		else if (bColorFlag == 2)
		{
			hbrBackground = CreateSolidBrush(RGB(0, 255, 0));
		}
		else if (bColorFlag == 3)
		{
			hbrBackground = CreateSolidBrush(RGB(0, 0, 255));
		}
		else if (bColorFlag == 4)
		{
			hbrBackground = CreateSolidBrush(RGB(255, 0, 0));
		}
		else if (bColorFlag == 5)
		{
			hbrBackground = CreateSolidBrush(RGB(0, 255, 0));
		}
		else if (bColorFlag == 6)
		{
			hbrBackground = CreateSolidBrush(RGB(0, 0, 255));
		}
		else if (bColorFlag == 7)
		{
			hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
		}
		else if (bColorFlag == 8)
		{
			hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
		}
		else if (bColorFlag == 9)
		{
			hbrBackground = CreateSolidBrush(RGB(128, 128, 128));
		}
		else if (bColorFlag == 10)
		{
			hbrBackground = CreateSolidBrush(RGB(215, 215, 215));
		}
		
		SelectObject(hdc, hbrBackground);
		FillRect(hdc, &rc, hbrBackground);
		DeleteObject(hbrBackground);

		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:

		KillTimer(hwnd, ID_TIMER);

		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}








