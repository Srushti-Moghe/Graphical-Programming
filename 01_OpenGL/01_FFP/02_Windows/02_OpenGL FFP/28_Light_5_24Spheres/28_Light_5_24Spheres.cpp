// SKELETON CODE - BASE CODE for D3D, WINDOWS (FFP>OpenGL) and OpenGL(PP)

// Windows header files
#include <windows.h>	// Win32 API
#include <stdlib.h>		// For exit()
#include <stdio.h>		// For FileIO

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

// Light Variables

// GOROUD SHADING

BOOL gbLight = FALSE;

GLfloat lightAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat lightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat lightPosition[] = {0.0f, 0.0f, 0.0f, 1.0f};	// {0.0f, 0.0f, 0.0f,Central light 1.0fPositional Light}

GLUquadric* quadric = NULL;

GLfloat angleXRotation = 0.0f;
GLfloat angleYRotation = 0.0f;
GLfloat angleZRotation = 0.0f;

GLuint keyPressed = 0;

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
	
	gpFile = fopen("28_Light_5_24Spheres.txt", "w");
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

		case 'L':
		case 'l':

			if (gbLight == FALSE)
			{
				glEnable(GL_LIGHTING);
				gbLight = TRUE;
			}
			else
			{
				glDisable(GL_LIGHTING);
				gbLight = FALSE;
			}

			break;
			
			// Key Press for X,Y,Z angled rotation reset
			
		case 'X':
		case 'x':

			keyPressed = 1;
			angleXRotation = 0.0f;	// Reset
			break;
			
		case 'Y':
		case 'y':

			keyPressed = 2;
			angleYRotation = 0.0f;	// Reset
			break;
			
		case 'Z':
		case 'z':

			keyPressed = 3;
			angleZRotation = 0.0f;	// Reset
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

	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);	// Dark Grey
	// glClearColor(0.5f, 0.5f, 0.5f, 1.0f);	// Medium Grey
	// glClearColor(0.75f, 0.75f, 0.75f, 1.0f);	// light Grey

	// WarmUp Resize Call
	resize(WIN_WIDTH, WIN_HEIGHT);

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glEnable(GL_LIGHT0);

	// Initialize Quadric
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	quadric = gluNewQuadric();

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

		/*
		gluPerspective(45.0f,
					   (GLfloat)width / (GLfloat)height, 
					   0.1f, 
					   100.0f);
		*/
		
		// glOrtho(left, right, top (always multiplied), bottom (always multiplied), near, far);		// angle of 90deg
		if (width <= height)
		{
			glOrtho(0.0f,
					15.5f,
					0.0f * ((GLfloat)height / (GLfloat)width),	
					15.5f * ((GLfloat)height / (GLfloat)width),
					-10.0f,
					10.0f);
		}
		else   // (width >= height)
		{
			glOrtho(0.0f * ((GLfloat)width / (GLfloat)height),
					15.5f * ((GLfloat)width / (GLfloat)height),
					0.0f,
					15.5f,
					-10.0f,
					10.0f);
		}

		glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void display(void)
{
	// Code
	
	// Variable Declarations 

	GLfloat materialAmbient[4];
	GLfloat materialDiffuse[4];
	GLfloat materialSpecular[4];
	GLfloat materialShininess;	// Use glMaterialfv(); NOT glMaterialf();

	// glTranslate coords
	GLfloat xCoord = 1.5f;
	GLfloat yCoord = 14.0f;
	GLfloat zCoord = 0.0f;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Step 3 (Compulsory)	// To paint the window Blue after setting it in glClearColor()
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Animation 
	if (keyPressed == 1)
	{
		glRotatef(angleXRotation, 1.0f, 0.0f, 0.0f);
		lightPosition[2] = angleXRotation;
	}
	else if (keyPressed == 2)
	{
		glRotatef(angleYRotation, 0.0f, 1.0f, 0.0f);
		lightPosition[0] = angleYRotation;
	}
	else if (keyPressed == 3)
	{
		glRotatef(angleZRotation, 0.0f, 0.0f, 1.0f);
		lightPosition[1] = angleZRotation;
	}

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	// **************************************************************************************************************

	// ***************************First Column - Precious Stones***************************
	
	// Material - Emerald
	materialAmbient[0] = 0.0215; // r
	materialAmbient[1] = 0.1745; // g
	materialAmbient[2] = 0.0215; // b
	materialAmbient[3] = 1.0f;	 // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.07568; // r
	materialDiffuse[1] = 0.61424; // g
	materialDiffuse[2] = 0.07568; // b
	materialDiffuse[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.633;    // r
	materialSpecular[1] = 0.727811; // g
	materialSpecular[2] = 0.633;    // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.6 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(1.5f, 14.0f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);	// gluSphere() creates all needed normals internally
	// all glu objects creates all needed normals internally

	// Material - Jade
	materialAmbient[0] = 0.135;  // r
	materialAmbient[1] = 0.2225; // g
	materialAmbient[2] = 0.1575; // b
	materialAmbient[3] = 1.0f;   // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.54; // r
	materialDiffuse[1] = 0.89; // g
	materialDiffuse[2] = 0.63; // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.316228; // r
	materialSpecular[1] = 0.316228; // g
	materialSpecular[2] = 0.316228; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.1 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(1.5f, 11.5f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - obsidian
	materialAmbient[0] = 0.05375; // r
	materialAmbient[1] = 0.05;    // g
	materialAmbient[2] = 0.06625; // b
	materialAmbient[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.18275; // r
	materialDiffuse[1] = 0.17;    // g
	materialDiffuse[2] = 0.22525; // b
	materialDiffuse[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.332741; // r
	materialSpecular[1] = 0.328634; // g
	materialSpecular[2] = 0.346435; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.3 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(1.5f, 9.0f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - pearl
	materialAmbient[0] = 0.25;    // r
	materialAmbient[1] = 0.20725; // g
	materialAmbient[2] = 0.20725; // b
	materialAmbient[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 1.0;   // r
	materialDiffuse[1] = 0.829; // g
	materialDiffuse[2] = 0.829; // b
	materialDiffuse[3] = 1.0f;  // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.296648; // r
	materialSpecular[1] = 0.296648; // g
	materialSpecular[2] = 0.296648; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.088 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(1.5f, 6.5f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - Ruby
	materialAmbient[0] = 0.1745;  // r
	materialAmbient[1] = 0.01175; // g
	materialAmbient[2] = 0.01175; // b
	materialAmbient[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.61424; // r
	materialDiffuse[1] = 0.04136; // g
	materialDiffuse[2] = 0.04136; // b
	materialDiffuse[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.727811; // r
	materialSpecular[1] = 0.626959; // g
	materialSpecular[2] = 0.626959; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.6 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(1.5f, 4.0f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - Turquoise
	materialAmbient[0] = 0.1;     // r
	materialAmbient[1] = 0.18725; // g
	materialAmbient[2] = 0.1745;  // b
	materialAmbient[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.396;   // r
	materialDiffuse[1] = 0.74151; // g
	materialDiffuse[2] = 0.69102; // b
	materialDiffuse[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.297254; // r
	materialSpecular[1] = 0.30829;  // g
	materialSpecular[2] = 0.306678; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.1 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(1.5f, 1.5f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// ***************************Second Column - Metals***************************

	// Material - Brass
	materialAmbient[0] = 0.329412; // r
	materialAmbient[1] = 0.223529; // g
	materialAmbient[2] = 0.027451; // b
	materialAmbient[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.780392; // r
	materialDiffuse[1] = 0.568627; // g
	materialDiffuse[2] = 0.113725; // b
	materialDiffuse[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.992157; // r
	materialSpecular[1] = 0.941176; // g
	materialSpecular[2] = 0.807843; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.21794872 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
    glTranslatef(7.5f, 14.0f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - Bronze
	materialAmbient[0] = 0.2125; // r
	materialAmbient[1] = 0.1275; // g
	materialAmbient[2] = 0.054;  // b
	materialAmbient[3] = 1.0f;   // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.714;   // r
	materialDiffuse[1] = 0.4284;  // g
	materialDiffuse[2] = 0.18144; // b
	materialDiffuse[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.393548; // r
	materialSpecular[1] = 0.271906; // g
	materialSpecular[2] = 0.166721; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.2 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(7.5f, 11.5f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - Chrome
	materialAmbient[0] = 0.25; // r
	materialAmbient[1] = 0.25; // g
	materialAmbient[2] = 0.25; // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.4;  // r
	materialDiffuse[1] = 0.4;  // g
	materialDiffuse[2] = 0.4;  // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.774597; // r
	materialSpecular[1] = 0.774597; // g
	materialSpecular[2] = 0.774597; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.6 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(7.5f, 9.0f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - Copper
	materialAmbient[0] = 0.19125; // r
	materialAmbient[1] = 0.0735;  // g
	materialAmbient[2] = 0.0225;  // b
	materialAmbient[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.7038;  // r
	materialDiffuse[1] = 0.27048; // g
	materialDiffuse[2] = 0.0828;  // b
	materialDiffuse[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.256777; // r
	materialSpecular[1] = 0.137622; // g
	materialSpecular[2] = 0.086014; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.1 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(7.5f, 6.5f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - Gold
	materialAmbient[0] = 0.24725; // r
	materialAmbient[1] = 0.1995;  // g
	materialAmbient[2] = 0.0745;  // b
	materialAmbient[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.75164; // r
	materialDiffuse[1] = 0.60648; // g
	materialDiffuse[2] = 0.22648; // b
	materialDiffuse[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.628281; // r
	materialSpecular[1] = 0.555802; // g
	materialSpecular[2] = 0.366065; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.4 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(7.5f, 4.0f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - Silver
	materialAmbient[0] = 0.19225; // r
	materialAmbient[1] = 0.19225; // g
	materialAmbient[2] = 0.19225; // b
	materialAmbient[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.50754; // r
	materialDiffuse[1] = 0.50754; // g
	materialDiffuse[2] = 0.50754; // b
	materialDiffuse[3] = 1.0f;    // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.508273; // r
	materialSpecular[1] = 0.508273; // g
	materialSpecular[2] = 0.508273; // b
	materialSpecular[3] = 1.0f;     // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.4 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(7.5f, 1.5f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// ***************************Third Column - Plastics***************************
	
	// Material - Black
	materialAmbient[0] = 0.0;  // r
	materialAmbient[1] = 0.0;  // g
	materialAmbient[2] = 0.0;  // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.01; // r
	materialDiffuse[1] = 0.01; // g
	materialDiffuse[2] = 0.01; // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.50; // r
	materialSpecular[1] = 0.50; // g
	materialSpecular[2] = 0.50; // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.25 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(13.5f, 14.0f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - Cyan
	materialAmbient[0] = 0.0;  // r
	materialAmbient[1] = 0.1;  // g
	materialAmbient[2] = 0.06; // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.0;        // r
	materialDiffuse[1] = 0.50980392; // g
	materialDiffuse[2] = 0.50980392; // b
	materialDiffuse[3] = 1.0f;       // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.50196078; // r
	materialSpecular[1] = 0.50196078; // g
	materialSpecular[2] = 0.50196078; // b
	materialSpecular[3] = 1.0f;       // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.25 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(13.5f, 11.5f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - Green
	materialAmbient[0] = 0.0;  // r
	materialAmbient[1] = 0.0;  // g
	materialAmbient[2] = 0.0;  // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.1;  // r
	materialDiffuse[1] = 0.35; // g
	materialDiffuse[2] = 0.1;  // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.45; // r
	materialSpecular[1] = 0.55; // g
	materialSpecular[2] = 0.45; // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.25 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(13.5f, 9.0f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - red
	materialAmbient[0] = 0.0;  // r
	materialAmbient[1] = 0.0;  // g
	materialAmbient[2] = 0.0;  // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.5;  // r
	materialDiffuse[1] = 0.0;  // g
	materialDiffuse[2] = 0.0;  // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.7;  // r
	materialSpecular[1] = 0.6;  // g
	materialSpecular[2] = 0.6;  // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.25 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(13.5f, 6.5f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - White
	materialAmbient[0] = 0.0;  // r
	materialAmbient[1] = 0.0;  // g
	materialAmbient[2] = 0.0;  // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.55; // r
	materialDiffuse[1] = 0.55; // g
	materialDiffuse[2] = 0.55; // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.70; // r
	materialSpecular[1] = 0.70; // g
	materialSpecular[2] = 0.70; // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.25 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(13.5f, 4.0f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - Yellow
	materialAmbient[0] = 0.0;  // r
	materialAmbient[1] = 0.0;  // g
	materialAmbient[2] = 0.0;  // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.5;  // r
	materialDiffuse[1] = 0.5;  // g
	materialDiffuse[2] = 0.0;  // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.60; // r
	materialSpecular[1] = 0.60; // g
	materialSpecular[2] = 0.50; // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.25 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(13.5f, 1.5f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// ***************************Fourth Column - Metals***************************
	
	// Material - Black
	materialAmbient[0] = 0.02; // r
	materialAmbient[1] = 0.02; // g
	materialAmbient[2] = 0.02; // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.01; // r
	materialDiffuse[1] = 0.01; // g
	materialDiffuse[2] = 0.01; // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.4;  // r
	materialSpecular[1] = 0.4;  // g
	materialSpecular[2] = 0.4;  // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.078125 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(19.5f, 14.0f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - Cyan
	materialAmbient[0] = 0.0;  // r
	materialAmbient[1] = 0.05; // g
	materialAmbient[2] = 0.05; // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.4;  // r
	materialDiffuse[1] = 0.5;  // g
	materialDiffuse[2] = 0.5;  // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.04; // r
	materialSpecular[1] = 0.7;  // g
	materialSpecular[2] = 0.7;  // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.078125 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(19.5f, 11.5f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - Green
	materialAmbient[0] = 0.0;  // r
	materialAmbient[1] = 0.05; // g
	materialAmbient[2] = 0.0;  // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.4;  // r
	materialDiffuse[1] = 0.5;  // g
	materialDiffuse[2] = 0.4;  // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.04; // r
	materialSpecular[1] = 0.7;  // g
	materialSpecular[2] = 0.04; // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.078125 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(19.5f, 9.0f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - Red
	materialAmbient[0] = 0.05; // r
	materialAmbient[1] = 0.0;  // g
	materialAmbient[2] = 0.0;  // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.5;  // r
	materialDiffuse[1] = 0.4;  // g
	materialDiffuse[2] = 0.4;  // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.7;  // r
	materialSpecular[1] = 0.04; // g
	materialSpecular[2] = 0.04; // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.078125 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(19.5f, 6.5f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - White
	materialAmbient[0] = 0.05; // r
	materialAmbient[1] = 0.05; // g
	materialAmbient[2] = 0.05; // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.5;  // r
	materialDiffuse[1] = 0.5;  // g
	materialDiffuse[2] = 0.5;  // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.7;  // r
	materialSpecular[1] = 0.7;  // g
	materialSpecular[2] = 0.7;  // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.078125 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(19.5f, 4.0f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);

	// Material - Yellow
	materialAmbient[0] = 0.05; // r
	materialAmbient[1] = 0.05; // g
	materialAmbient[2] = 0.0;  // b
	materialAmbient[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);

	materialDiffuse[0] = 0.5;  // r
	materialDiffuse[1] = 0.5;  // g
	materialDiffuse[2] = 0.4;  // b
	materialDiffuse[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

	materialSpecular[0] = 0.7;  // r
	materialSpecular[1] = 0.7;  // g
	materialSpecular[2] = 0.04; // b
	materialSpecular[3] = 1.0f; // a
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

	materialShininess = 0.078125 * 128;
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glLoadIdentity();
	glTranslatef(19.5f, 1.5f, 0.0f);
	gluSphere(quadric, 1.0f, 30, 30);
	// **************************************************************************************************************

	SwapBuffers(ghdc);		// Win32 API. ghrc not used as it is an gl API that the windows DC wont understand
}

void update(void)
{
	// Code

	if (keyPressed == 1)
	{
		angleXRotation = angleXRotation + 0.2f;
		if (angleXRotation >= 360.0f)
		{
			angleXRotation = angleXRotation - 360.0f;
		}
	}

	if (keyPressed == 2)
	{
		angleYRotation = angleYRotation + 0.2f;
		if (angleYRotation >= 360.0f)
		{
			angleYRotation = angleYRotation - 360.0f;
		}
	}

	if (keyPressed == 3)
	{
		angleZRotation = angleZRotation + 0.2f;
		if (angleZRotation >= 360.0f)
		{
			angleZRotation = angleZRotation - 360.0f;
		}	
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

	if (quadric)
	{
		gluDeleteQuadric(quadric);
		quadric = NULL;
	}

}





















