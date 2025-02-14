// SKELETON CODE - BASE CODE for D3D, WINDOWS (FFP>OpenGL) and OpenGL(PP)

// Windows header files
#include <windows.h>	// Win32 API
#include <stdlib.h>		// For exit()
#include <stdio.h>		// For FileIO
		
#define _USE_MATH_DEFINES
#include <math.h>		// For math equations


// OpenGL Header Files
#include <GL/gl.h>		// #include <gl\GL.h> Windows - not case sensitive
#include <GL/glu.h>		
#include "OGL.h"		// User defined header file

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

	// Function Declarations
	void GraphPaper();
	void Circle();
	void Rectangle();
	void Triangle();

	int iResult = 0;
	BOOL bDone = FALSE;

	HDC hdc; // One of the two arguments required for GetDeviceCaps
	hdc = GetDC(NULL);

	

	// Centering Window

	// X, Y coordinates for SCREEN
	int ScreenWidth = GetDeviceCaps(hdc, HORZRES);
	int ScreenHeight = GetDeviceCaps(hdc, VERTRES);

	// X, Y coordinates for WINDOW
	int WindowX = (ScreenWidth / 2) - (WIN_WIDTH / 2);
	int WindowY = (ScreenHeight / 2) - (WIN_HEIGHT / 2);

	
	// Code
	
	gpFile = fopen("10_KeyboardShapes.txt", "w");
	if (gpFile == NULL)
	{
		MessageBox(NULL, TEXT("Log File cannot be opened"), TEXT("Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	fprintf(gpFile, "SUM Triangle without GLUT Program started Successfully...\n");

	// WNDCLASSEX Initialization
	wndclass.cbSize = sizeof(WNDCLASSEX);                                   //1
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;                    //2		// The window context that is created by CreateWindow() is under wndclass.style
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
		WIN_WIDTH,		// Macro
		WIN_HEIGHT,		// Macro
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

	SetFocus(hwnd); // To keep the window selected / highlighted; internally calls WM_SETFOCUS to WndProc()

	
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
	void resize(int, int);
	// void resize(width, height);

	// Function Declarations
	void GraphPaper();
	void Circle();
	void Rectangle();
	void Triangle();
	
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
		resize(LOWORD(lParam), HIWORD(lParam));		
	break;

	case WM_ERASEBKGND:
			return(0);	
	break;

	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_ESCAPE:
			DestroyWindow(hwnd);
		break;
		}
	break;

	/* 
	case WM_RBUTTONDOWN:
		DestroyWindow(hwnd);
	break;
	*/

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

		case 'G':
		case 'g':
			GraphPaper();
			// GraphPaper = GraphPaper();
		break;

		case 'C':
		case 'c':
			Circle();
			// Circle = Circle();
			break;

		case 'T':
		case 't':
			Triangle();
			// Triangle = Triangle();
			break;

		case 'R':
		case 'r':
			Rectangle();
			// Rectangle = Rectangle();
			break;

		}
	break;
		

	case WM_CLOSE:
		DestroyWindow(hwnd);
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

	// Function Declarations
	void GraphPaper();
	void Circle();
	void Rectangle();
	void Triangle();

	// Function Declarations
	void GraphPaper();
	void Circle();
	void Rectangle();
	void Triangle();

	glClear(GL_COLOR_BUFFER_BIT);	
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);

	// Graph Paper Background
	
	// Circle	

	// Rectangle	

	// Triangle	

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

// Graph Paper
void GraphPaper(void)
{
	// Yellow Center Point
	glPointSize(3.00f);
	glBegin(GL_POINTS);

	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	// Blue Vertical Lines

	GLint totalcount_v = 80;
	GLfloat linespacing_v = 1.0 / totalcount_v;

	GLfloat xCoord = 0.0;

	// glLineWidth(0.50f);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	for (GLint i = 0; i <= totalcount_v; i++)
	{
		if (i == 40)
		{
			glLineWidth(3.00f);
			glColor3f(0.0, 1.0, 0.0);
		}
		else if (i % 5 == 0)
		{
			glLineWidth(2.00f);
			glColor3f(0.184, 0.184, 0.929);
		}
		else
		{
			glLineWidth(0.001f);
			glColor3f(0.0, 0.0, 1.0);
		}
		xCoord = -1.0 + i * 2.0f * linespacing_v;
		glVertex3f(xCoord, -1.0, 0.0f);
		glVertex3f(xCoord, 1.0, 0.0f);
	}
	glEnd();

	// Blue Horizontal Lines


	GLint totalcount_h = 80;
	GLfloat linespacing_h = 1.0 / totalcount_h;

	GLfloat yCoord = 0.0;

	// glLineWidth(0.50f);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	for (GLint i = 0; i <= totalcount_h; i++)
	{
		if (i == 40)
		{
			glLineWidth(3.00f);
			glColor3f(1.0, 0.0, 0.0);
		}
		else if (i % 5 == 0)
		{
			glLineWidth(2.00f);
			glColor3f(0.184, 0.184, 0.929);
		}
		else
		{
			glLineWidth(0.001f);
			glColor3f(0.0, 0.0, 1.0);
		}

		yCoord = -1.0 + i * 2.0f * linespacing_h;
		glVertex3f(-1.0, yCoord, 0.0f);
		glVertex3f(1.0, yCoord, 0.0f);
	}
	glEnd();

}

// Circle
void Circle(void)
{
	glColor3f(1.0f, 1.0f, 0.0f);
	glLineWidth(1.50f);
	glBegin(GL_LINE_STRIP);

	float radius = 0.50f;
	float x_centre = 0.0f;		// distance from X-Axis
	float y_centre = 0.0f;		// distance from Y-Axis
	for (int i = 0; i < 1000; i++)
	{
		float angle = 2.0f * M_PI * i / 1000;
		glVertex3f(radius * cos(angle), radius * sin(angle), 0.0f);		// centering circle
	}
	glEnd();

}

// Rectangle
void Rectangle(void)
{
	glColor3f(1.0f, 1.0f, 0.0f);
	glLineWidth(1.50f);
	glBegin(GL_LINE_STRIP);

	glVertex3f(-0.5f, -0.5f, 0.0f);	// LB
	glVertex3f(-0.5f, 0.5f, 0.0f);	// LT
	glVertex3f(0.5f, 0.5f, 0.0f);	// RT
	glVertex3f(0.5f, -0.5f, 0.0f);	// RB
	glVertex3f(-0.5f, -0.5f, 0.0f);	// LB

	glEnd();
}

// Triangle
void Triangle(void)
{
	glColor3f(1.0f, 1.0f, 0.0f);
	glLineWidth(1.50f);
	glBegin(GL_LINE_STRIP);

	glVertex3f(0.0f, 0.5f, 0.0f);	// Top
	glVertex3f(0.5f, -0.5f, 0.0f);	// Right
	glVertex3f(-0.5f, -0.5f, 0.0f);	// Left
	glVertex3f(0.0f, 0.5f, 0.0f);	// Top

	glEnd();
}






















