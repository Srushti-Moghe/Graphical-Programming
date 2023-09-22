// SKELETON CODE - BASE CODE for D3D, WINDOWS (FFP>OpenGL) and OpenGL(PP)

// Windows header files
#include <windows.h>	// Win32 API
#include <stdlib.h>		// For exit()
#include <stdio.h>		// For FileIO

#define _USE_MATH_DEFINES 1	// Enables the macros in the math.h
#include <math.h>		// For Mathematical Operations


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

HWND ghwnd = NULL;			// g-global hwnd-window handle

BOOL gbActive = FALSE;		// By default the window is not active

FILE *gpFile = NULL;

DWORD dwStyle = 0;

WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };		// struct initialization method01

BOOL gbFullscreen = FALSE;

// OpenGL related Global Variables
HDC ghdc = NULL;
HGLRC ghrc = NULL;		// Handle to GL Rendering Context

GLfloat cAngle = 0.0f;	// For Rotating Cube

// Array Declarations

GLfloat identityMatrix[16];
GLfloat translationMatrix[16];
GLfloat scaleMatrix[16];
GLfloat rotationMatrix_X[16];
GLfloat rotationMatrix_Y[16];
GLfloat rotationMatrix_Z[16];

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
	
	gpFile = fopen("01_ModelViewTransformation.txt", "w");
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
	void resize(int, int);
	// void resize(width, height);

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

	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_ESCAPE:
			DestroyWindow(hwnd);
		break;
		}
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
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));		// struct initialization method02	

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

	// Enabling Depth
	pfd.cDepthBits = 32;	// Step 1 (Compulsory)

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

	// Enabling Depth

	glShadeModel(GL_SMOOTH);								// Step 2.4 (Optional)

	glClearDepth(1.0f);										// Step 2.1 (Compulsory)
	glEnable(GL_DEPTH_TEST);								// Step 2.2 (Compulsory)
	glDepthFunc(GL_LEQUAL);									// Step 2.3 (Compulsory) Comparing Function LEQUAL is Less than or Equal to glClearDepth(valuef)

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);		// Step 2.5 (Optional)

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Initialization  of Indices

	// GLfloat identityMatrix[16]; Initialization

	identityMatrix[0] = 1.0f;
	identityMatrix[1] = 0.0f;
	identityMatrix[2] = 0.0f;
	identityMatrix[3] = 0.0f;
	identityMatrix[4] = 0.0f;
	identityMatrix[5] = 1.0f;
	identityMatrix[6] = 0.0f;
	identityMatrix[7] = 0.0f;
	identityMatrix[8] = 0.0f;
	identityMatrix[9] = 0.0f;
	identityMatrix[10] = 1.0f;
	identityMatrix[11] = 0.0f;
	identityMatrix[12] = 0.0f;
	identityMatrix[13] = 0.0f;
	identityMatrix[14] = 0.0f;
	identityMatrix[15] = 1.0f;
	
	// GLfloat translationMatrix[16]; Initialization

	translationMatrix[0] = 1.0f;
	translationMatrix[1] = 0.0f;
	translationMatrix[2] = 0.0f;
	translationMatrix[3] = 0.0f;
	translationMatrix[4] = 0.0f;
	translationMatrix[5] = 1.0f;
	translationMatrix[6] = 0.0f;
	translationMatrix[7] = 0.0f;
	translationMatrix[8] = 0.0f;
	translationMatrix[9] = 0.0f;
	translationMatrix[10] = 1.0f;
	translationMatrix[11] = 0.0f;
	translationMatrix[12] = 0.0f;	// tx
	translationMatrix[13] = 0.0f;	// ty
	translationMatrix[14] = -5.0f;	// tz
	translationMatrix[15] = 1.0f;

	// GLfloat scaleMatrix[16]; Initialization

	scaleMatrix[0] = 0.75f;	// sx
	scaleMatrix[1] = 0.0f;
	scaleMatrix[2] = 0.0f;
	scaleMatrix[3] = 0.0f;
	scaleMatrix[4] = 0.0f;
	scaleMatrix[5] = 0.75f;	// sy
	scaleMatrix[6] = 0.0f;
	scaleMatrix[7] = 0.0f;
	scaleMatrix[8] = 0.0f;
	scaleMatrix[9] = 0.0f;
	scaleMatrix[10] = 0.75f;	// sz
	scaleMatrix[11] = 0.0f;
	scaleMatrix[12] = 0.0f;
	scaleMatrix[13] = 0.0f;
	scaleMatrix[14] = 0.0f;
	scaleMatrix[15] = 1.0f;

	// GLfloat rotationMatrix_X[16]; Initialization

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
	// Variable Declaration
	
	static GLfloat angle = 0.0f;

	// Code

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Step 3 (Compulsory)	// To paint the window Blue after setting it in glClearColor()
	
	glMatrixMode(GL_MODELVIEW);	// Shows the type of Transformation
	
	// glLoadIdentity();
	glLoadMatrixf(identityMatrix);

	// glTranslatef(0.0f, 0.0f, -4.0f);
	glMultMatrixf(translationMatrix);

	// glScalef(0.75f, 0.75f, 0.5f);
	glMultMatrixf(scaleMatrix);

	// glRotatef(cAngle, 1.0f, 0.0f, 0.0f);	// X-Rotation
	// glRotatef(cAngle, 0.0f, 1.0f, 0.0f);	// Y-Rotation
	// glRotatef(cAngle, 0.0f, 0.0f, 1.0f);	// Z-Rotation

	angle = cAngle * (M_PI / 180.0f);		// COnversion of Degrees --> Radian

	// GLfloat rotationMatrix_X[16]; Initialization

	rotationMatrix_X[0] = 1.0f;
	rotationMatrix_X[1] = 0.0f;
	rotationMatrix_X[2] = 0.0f;
	rotationMatrix_X[3] = 0.0f;
	rotationMatrix_X[4] = 0.0f;
	rotationMatrix_X[5] = cos(angle);
	rotationMatrix_X[6] = sin(angle);
	rotationMatrix_X[7] = 0.0f;
	rotationMatrix_X[8] = 0.0f;
	rotationMatrix_X[9] = -sin(angle);
	rotationMatrix_X[10] = cos(angle);
	rotationMatrix_X[11] = 0.0f;
	rotationMatrix_X[12] = 0.0f;
	rotationMatrix_X[13] = 0.0f;
	rotationMatrix_X[14] = 0.0f;
	rotationMatrix_X[15] = 1.0f;

	// GLfloat rotationMatrix_Y[16]; Initialization

	rotationMatrix_Y[0] = cos(angle);
	rotationMatrix_Y[1] = 0.0f;
	rotationMatrix_Y[2] = -sin(angle);
	rotationMatrix_Y[3] = 0.0f;
	rotationMatrix_Y[4] = 0.0f;
	rotationMatrix_Y[5] = 1.0f;
	rotationMatrix_Y[6] = 0.0f;
	rotationMatrix_Y[7] = 0.0f;
	rotationMatrix_Y[8] = sin(angle);
	rotationMatrix_Y[9] = 0.0f;
	rotationMatrix_Y[10] = cos(angle);
	rotationMatrix_Y[11] = 0.0f;
	rotationMatrix_Y[12] = 0.0f;
	rotationMatrix_Y[13] = 0.0f;
	rotationMatrix_Y[14] = 0.0f;
	rotationMatrix_Y[15] = 1.0f;

	// GLfloat rotationMatrix_Z[16]; Initialization

	rotationMatrix_Z[0] = cos(angle);
	rotationMatrix_Z[1] = sin(angle);
	rotationMatrix_Z[2] = 0.0f;
	rotationMatrix_Z[3] = 0.0f;
	rotationMatrix_Z[4] = -sin(angle);
	rotationMatrix_Z[5] = cos(angle);
	rotationMatrix_Z[6] = 0.0f;
	rotationMatrix_Z[7] = 0.0f;
	rotationMatrix_Z[8] = 0.0f;
	rotationMatrix_Z[9] = 0.0f;
	rotationMatrix_Z[10] = 1.0f;
	rotationMatrix_Z[11] = 0.0f;
	rotationMatrix_Z[12] = 0.0f;
	rotationMatrix_Z[13] = 0.0f;
	rotationMatrix_Z[14] = 0.0f;
	rotationMatrix_Z[15] = 1.0f;
	
	glMultMatrixf(rotationMatrix_X);
	glMultMatrixf(rotationMatrix_Y);
	glMultMatrixf(rotationMatrix_Z);

	// Step 4 (Compulsory) Use Z-Coordinates

	glBegin(GL_QUADS);

	// FRONT FACE - R	

	glColor3f(1.0f, 0.0f, 0.0f);	

	glVertex3f(1.0f, 1.0f, 1.0f);		// RT
	glVertex3f(-1.0f, 1.0f, 1.0f);		// LT
	glVertex3f(-1.0f, -1.0f, 1.0f);		// LB
	glVertex3f(1.0f, -1.0f, 1.0f);		// RB

	// RIGHT FACE - G	

	glColor3f(0.0f, 1.0f, 0.0f);

	glVertex3f(1.0f, 1.0f, -1.0f);		// RT
	glVertex3f(1.0f, 1.0f, 1.0f);		// LT
	glVertex3f(1.0f, -1.0f, 1.0f);		// LB
	glVertex3f(1.0f, -1.0f, -1.0f);		// RB

	// BACK FACE - B

	glColor3f(0.0f, 0.0f, 1.0f);

	glVertex3f(-1.0f, 1.0f, -1.0f);		// RT
	glVertex3f(1.0f, 1.0f, -1.0f);		// LT
	glVertex3f(1.0f, -1.0f, -1.0f);		// LB
	glVertex3f(-1.0f, -1.0f, -1.0f);		// RB

	// LEFT FACE - C	

	glVertex3f(-1.0f, 1.0f, 1.0f);		// RT
	glVertex3f(-1.0f, 1.0f, -1.0f);		// LT
	glVertex3f(-1.0f, -1.0f, -1.0f);	// LB
	glVertex3f(-1.0f, -1.0f, 1.0f);		// RB		

	// TOP FACE - M

	glColor3f(1.0f, 0.0f, 1.0f);

	glVertex3f(1.0f, 1.0f, -1.0f);		// RT
	glVertex3f(-1.0f, 1.0f, -1.0f);		// LT
	glVertex3f(-1.0f, 1.0f, 1.0f);		// LB
	glVertex3f(1.0f, 1.0f, 1.0f);		// RB

	// BOTTOM FACE - Y

	glColor3f(1.0f, 1.0f, 0.0f);

	glVertex3f(1.0f, -1.0f, -1.0f);		// RT
	glVertex3f(-1.0f, -1.0f, -1.0f);		// LT
	glVertex3f(-1.0f, -1.0f, 1.0f);		// LB
	glVertex3f(1.0f, -1.0f, 1.0f);		// RB
	glEnd();

	SwapBuffers(ghdc);		// Win32 API. ghrc not used as it is an gl API that the windows DC wont understand

}

void update(void)
{
	// Code

	cAngle = cAngle - 0.008f;		// cAngle in "degrees"

	if (cAngle <= 0.0f)
	{
		cAngle = cAngle + 360.0f;
		// cAngle = 0.0f; Also Works
	}
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





















