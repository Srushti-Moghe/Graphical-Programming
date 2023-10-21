// SKELETON CODE - BASE CODE for D3D, WINDOWS (FFP>OpenGL) and OpenGL(PP)

// Windows header files
#include <windows.h>	
#include <stdlib.h>		
#include <stdio.h>		

// OpenGL Header Files
#include <GL/gl.h>		
#include <GL/glu.h>		
#include "OGL.h"		

// Macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// Link with OpenGL library
#pragma comment(lib, "OpenGL32.lib")

#pragma comment(lib, "glu32.lib")

 // Global Function Declarations / Function Prototype
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


// Global Variable Declarations

HWND ghwnd = NULL;			

BOOL gbActive = FALSE;		

FILE *gpFile = NULL;

DWORD dwStyle = 0;

WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };		

BOOL gbFullscreen = FALSE;

// OpenGL related Global Variables
HDC ghdc = NULL;
HGLRC ghrc = NULL;		// Handle to GL Rendering Context

int ScreenWidth = 0;
int ScreenHeight = 0;

// Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// Local Variable Declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("SUMWindow");
	
	// Function Declarations / Prototype

	int initialize(void);
	void uninitialize(void);
	void display(void);
	void update(void);

	int iResult = 0;
	BOOL bDone = FALSE;

	HDC hdc; 
	hdc = GetDC(NULL);

	

	// Centering Window

	// X, Y coordinates for SCREEN
	ScreenWidth = GetDeviceCaps(hdc, HORZRES);
	ScreenHeight = GetDeviceCaps(hdc, VERTRES);

	// X, Y coordinates for WINDOW
	int WindowX = (ScreenWidth / 2) - (WIN_WIDTH / 2);
	int WindowY = (ScreenHeight / 2) - (WIN_HEIGHT / 2);

	
	// Code
	
	gpFile = fopen("13_MultiViewPort.txt", "w");
	if (gpFile == NULL)
	{
		MessageBox(NULL, TEXT("Log File cannot be opened"), TEXT("Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	fprintf(gpFile, "SUM Triangle without GLUT Program started Successfully...\n");

	// WNDCLASSEX Initialization
	wndclass.cbSize = sizeof(WNDCLASSEX);                                   //1
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;                    //2		
	wndclass.cbClsExtra = 0;                                                //3  
	wndclass.cbWndExtra = 0;                                                //4
	wndclass.lpfnWndProc = WndProc;                                         //5
	wndclass.hInstance = hInstance;                                         //6
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);           //7
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));          //8
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);                         //9
	wndclass.lpszClassName = szAppName;                                     //10
	wndclass.lpszMenuName = NULL;                                           //11
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));        //12

	// Register WNDCLASSEX
	RegisterClassEx(&wndclass);

	// Create the Window
	// Change CreateWindow to CreateWindowEx
	// CreateWindowEx brings the Window above the task bar
	hwnd = CreateWindowEx(
		WS_EX_APPWINDOW, // Window above Task Bar
		szAppName,
		TEXT("Srushti Umesh Moghe"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		WindowX,
		WindowY,
		WIN_WIDTH,		
		WIN_HEIGHT,		
		NULL,
		NULL,
		hInstance,
		NULL);

	ghwnd = hwnd;

	// Initialization
	iResult = initialize();

	if (iResult != 0)
	{
		MessageBox(hwnd, TEXT("initialize() failed !!!"), TEXT("Error"), MB_OK | MB_ICONERROR);
		// MessageBox(hwnd / ghwnd / NULL, TEXT("initialize() failed !!!"), TEXT("Error"), MB_OK | MB_ICONERROR);

		DestroyWindow(hwnd);
	}

	// Show the Window
	ShowWindow(hwnd, iCmdShow);

	SetForegroundWindow(hwnd);
	// SetForegroundWindow(ghwnd); To make sure the window is always in the Foreground

	SetFocus(hwnd); 

	// UpdateWindow(hwnd); is sent to WM_PAINT hence to be removed

	/* Message Loop - GetMessage
	 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	*/

	// GAME LOOP
	while (bDone == FALSE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// PM_REMOVE - removes message from the message queue
		{
			if (msg.message == WM_QUIT)
			{
				bDone = TRUE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if (gbActive == TRUE)
			{
				// RENDER
				display();

				// Update (For animation and changes)
				update();

			}
		}
	}
	// Uninitialization
	uninitialize();

	return((int)msg.wParam);
}
// Claaback Function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// Function Declarations

	void ToggleFullscreen(void);
	
	void resize(int , int);

	// Code
	// Body of the callback() - WndProc [User Defined]
	switch(iMsg)
	{
	case WM_SETFOCUS:		// Message for Active Window 
		gbActive = TRUE;
		break;

	case WM_KILLFOCUS:		// Message that deviates focus from the active window
		gbActive = FALSE;
		break;

	case WM_SIZE:
		resize(LOWORD(lParam), HIWORD(lParam));		// void resize(width, height);
	break;

	case WM_ERASEBKGND:
			return(0);	// Message does not go to DefWindowProc()
	break;

	case WM_RBUTTONDOWN:		// Mouse Button click
		DestroyWindow(hwnd);
	break;

	case WM_CHAR:
		switch (LOWORD(wParam))
		{
		case 'F':
		case 'f':
			
			if (gbFullscreen == FALSE)
			{
				ToggleFullscreen();
				gbFullscreen = TRUE;
			}
			else
			{
				ToggleFullscreen();
				gbFullscreen = FALSE;
			}
		break;

		}
	break;

	case WM_CLOSE:
		DestroyWindow(hwnd);	// To destroy the program running in the background when the window is closed
	break;

	case WM_DESTROY:
		PostQuitMessage(0);
	break;
	
	// MultiViewPort

	case WM_KEYDOWN:

	switch (LOWORD(wParam))
	{
		case VK_ESCAPE:
			DestroyWindow(hwnd);
		break;

		case 0x0030:	//0
		// VK_NUMPAD0:

			glViewport(0, 0, (GLsizei)ScreenWidth, (GLsizei)ScreenHeight);
		break;

		case 0x0031:	//1
		// VK_NUMPAD1:

			glViewport(0, 0, (GLsizei)ScreenWidth / 2, (GLsizei)ScreenHeight / 2);
		break;

		case 0x0032:	//2
		// VK_NUMPAD4:

			glViewport((GLsizei)ScreenWidth / 2, 0, (GLsizei)ScreenWidth / 2, (GLsizei)ScreenHeight / 2);
		break;

		case 0x0033:	//3
		// VK_NUMPAD3:

			glViewport((GLsizei)ScreenWidth / 2, (GLsizei)ScreenHeight / 2, (GLsizei)ScreenWidth / 2, (GLsizei)ScreenHeight / 2);
		break;

		case 0x0034:	//4
		// VK_NUMPAD4:

			glViewport(0, (GLsizei)ScreenHeight / 2, (GLsizei)ScreenWidth / 2, (GLsizei)ScreenHeight / 2);
		break;

		case 0x0035:	//5
		// VK_NUMPAD5:

			glViewport(0, 0, (GLsizei)ScreenWidth, (GLsizei)ScreenHeight / 2);
		break;

		case 0x0036:	//6
		// VK_NUMPAD6:

			glViewport(0, (GLsizei)ScreenHeight / 2, (GLsizei)ScreenWidth, (GLsizei)ScreenHeight / 2);
		break;

		case 0x0037: //7
		// VK_NUMPAD7:

			glViewport(0, 0, (GLsizei)ScreenWidth / 2, (GLsizei)ScreenHeight);
		break;

		case 0x0038: //8
		// VK_NUMPAD8:
			glViewport((GLsizei)ScreenWidth / 2, 0, (GLsizei)ScreenWidth / 2, (GLsizei)ScreenHeight);
		break;

		case 0x0039: //9
		// VK_NUMPAD9:
			glViewport((GLsizei)ScreenWidth / 4, (GLsizei)ScreenHeight / 4, (GLsizei)ScreenWidth / 2, (GLsizei)ScreenHeight / 2);
		break;		

		default:
			glViewport(0, 0, (GLsizei)ScreenWidth, (GLsizei)ScreenHeight);
		break;
	}

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
	if (gbFullscreen == FALSE)		
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);		

		if (dwStyle & WS_OVERLAPPEDWINDOW)		
		{
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))		
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);		
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);		// iii - B
			}
		}
		ShowCursor(FALSE);
	}
	else 
	{
		SetWindowPlacement(ghwnd,&wpPrev);		
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);		
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);		
		ShowCursor(TRUE);
	}
}

int initialize(void)
{
	// Function Declarations

	// Prototype Declarations
	void resize(int, int);	// Warmup resize call

	// Code
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));			

	// Step1 Initialization of PIXELFORMATDESCRIPTOR
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;		// Conventionally version 1
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;		
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;

	// Step2 Get DC
	ghdc = GetDC(ghwnd);
	if (ghdc == NULL)
	{
		fprintf(gpFile, "GetDC() Failed...\n");
		return(-1);
	}
	
	// Step3
	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (iPixelFormatIndex == 0) // NON ZERO POSITIVE value is the success of iPixelFormatIndex
	{
		fprintf(gpFile, "ChoosePixelFormat() Failed...\n");
		return(-2);
	}

	// Step4 Set obtained Pixel Format
	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFile, "SetPixelFormat() Failed...\n");
		return(-3);
	}

	// Step5 Tell Windows Graphics Library (Bridging Library) to give OpenGL compatible DC from this device context - 'ghdc'
	// Step5 Create OpenGL Context from Device Context
	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		fprintf(gpFile, "wglCreateContext() Failed...\n");
		return(-4);
	}
	// Step6 Make Rendering Context Current
	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFile, "wglMakeCurrent() Failed...\n");
		return(-5);
	}

	// OpenGL starts here
	// To Set Clear Color of window to Blue DOESNOT paint the window Blue
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	resize(WIN_WIDTH, WIN_HEIGHT);


	return(0);
}

void resize(int width, int height)
{
	// Code
	if (height <= 0)
	{
		height = 1;		// Precaution as height is a divisor, hence cannot be 0 or negative
	}
		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(45.0f, 
					   (GLfloat)width / (GLfloat)height, 
					   0.1f, 
					   100.0f);

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void display(void)
{
	// Code
	glClear(GL_COLOR_BUFFER_BIT);		
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -3.0f);

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);

	glEnd();

	SwapBuffers(ghdc);		// Win32 API. ghrc not used as it is an gl API that the windows DC wont understand

}

void update(void)
{
	// Code
}

void uninitialize(void)
{
	// Function Declarations
	void ToggleFullscreen(void);

	// Code
	// If application is exitting in Fullscreen
	if (gbFullscreen == TRUE)
	{
		ToggleFullscreen();
		gbFullscreen = FALSE;
	}
	// Make HDC as current DC
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}
	// Destroy / Delete Rendering Context
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}
	// Release HDC
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}
	// Get rid of Window handle / Destroy Window
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}
	// Close the log file 
	if (gpFile)
		{
			fprintf(gpFile, "SUM Triangle without GLUT Program ended Successfully...\n");
			fclose(gpFile);
			gpFile = NULL;
		}

}





















