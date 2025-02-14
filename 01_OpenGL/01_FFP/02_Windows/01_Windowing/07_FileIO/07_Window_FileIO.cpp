 // Windows header files
#include <windows.h>
#include <stdio.h>		// For FileIO
#include <stdlib.h>		// For exit()

// Global Function Declarations / Function Prototype
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Global Variable Declarations

FILE *gpFile = NULL;	// Created in WinMain() but used in WndProc()

// Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)

{
	// Local Variable Declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("SUMWindow");

	// Code
	gpFile = fopen("Log.txt", "w");
	if (gpFile == NULL)
	{
		MessageBox(NULL, TEXT("Log File cannot be opened"), TEXT("Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	fprintf(gpFile, "Program started Successfully...\n");

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
// WndProc is a user defined name
LRESULT CALLBACK WndProc(HWND hwnd,
						 UINT iMsg,
						 WPARAM wParam, 
					     LPARAM lParam)

{
	// Code
	// Body of the callback() - WndProc [User Defined]
	switch(iMsg)
	{
	case WM_DESTROY:
		if (gpFile)
		{
			fprintf(gpFile, "Program ended Successfully...\n");
			fclose(gpFile);
			gpFile = NULL;
		}
		PostQuitMessage(0);		// Never write code after PostQuitMessage(0);
		break;
	default:
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}








