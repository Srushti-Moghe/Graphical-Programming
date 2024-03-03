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

// Lerp()

GLfloat lerp(GLfloat start, GLfloat end, GLfloat t)
{
	return (start + (end - start) * t);
}

// Colors

GLfloat orange_R = 1.0f;
GLfloat orange_G = 0.404f;
GLfloat orange_B = 0.122f;

GLfloat white_R = 1.0f;
GLfloat white_G = 1.0f;
GLfloat white_B = 1.0f;

GLfloat green_R = 0.157f;
GLfloat green_G = 0.416f;
GLfloat green_B = 0.219f;

// Letters Fly

GLfloat B_x = -2.0f;
GLfloat B_y = 0.0f;

GLfloat H_x = -3.0f;
GLfloat H_y = 1.0f;

GLfloat A_x = -3.0f;
GLfloat A_y = -1.0f;

GLfloat R_x = 0.0f;
GLfloat R_y = 0.0f;

GLfloat RA_x = 0.0f;
GLfloat RA_y = 0.0f;

GLfloat T_x = 0.0f;
GLfloat T_y = 0.0f;

// Plane Fly

GLfloat plane1_x = 0.0f;
GLfloat plane1_y = 0.0f;

GLfloat plane2_x = 0.0f;
GLfloat plane2_y = 0.0f;

GLfloat plane3_x = 0.0f;
GLfloat plane3_y = 0.0f;

GLfloat plane1_angle = 0.0f;
GLfloat plane3_angle = 0.0f;



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

	/*
	int WindowWidth = 800;
	int WindowHeight = 600;

	Centering Window

	int ScreenWidth = GetSystemMetrics(SM_CXSCREEN);      
	int ScreenHeight = GetSystemMetrics(SM_CYSCREEN);    
	int WindowWidth = 800;
	int WindowHeight = 600;
	*/

	// X, Y coordinates for WINDOW
	int WindowX = (ScreenWidth / 2) - (WIN_WIDTH / 2);
	int WindowY = (ScreenHeight / 2) - (WIN_HEIGHT / 2);

	
	// Code
	
	gpFile = fopen("27_DynamicBharat.txt", "w");
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
	glClearColor(0.6627f, 0.6627f, 0.6627f, 1.0f);

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

	void staticBharat();
	void plane(GLfloat color[]);

	GLfloat orange[] = {orange_R, orange_G, orange_B};
	GLfloat white[] = { white_R, white_G, white_B };
	GLfloat green[] = {green_R, green_G, green_B};

	glClear(GL_COLOR_BUFFER_BIT);		// To paint the window Blue after setting it in glClearColor()
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	staticBharat();
	
	glPushMatrix();
	glTranslatef(plane1_x, plane1_y, 0.0f);
	glRotatef(plane1_angle, 0.0f, 0.0f, 1.0f);
	plane(orange);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(plane2_x, plane2_y, 0.0f);
	plane(white);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(plane3_x, plane3_y, 0.0f);
	glRotatef(plane3_angle, 0.0f, 0.0f, 1.0f);
	plane(green);
	glPopMatrix();


	SwapBuffers(ghdc);		// Win32 API. ghrc not used as it is an gl API that the windows DC wont understand
}

void update(void)
{
	// Code

	// Letters Fly

	static GLfloat t1 = 0.0f;
	B_x = lerp(-3.0f, -1.5f, t1);	
	if (t1 < 1.0f)
	{
		t1 += 0.001f;
	}

	static GLfloat t2 = 0.0f;
	H_x = lerp(-3.0f, -1.0f, t2);
	H_y = lerp(1.0f, 0.0f, t2);
	
	if (t1 >= 1.0f && t2 < 1.0f)
	{
		t2 += 0.001f;
	}

	static GLfloat t3 = 0.0f;
	A_x = lerp(-3.0f, -0.5f, t3);
	A_y = lerp(-1.0f, 0.0f, t3);

	if (t2 >= 1.0f && t3 < 1.0f)
	{
		t3 += 0.001f;
	}

	static GLfloat t4 = 0.0f;
	R_x = lerp(3.0f, 0.0f, t4);
	R_y = lerp(1.0f, 0.0f, t4);

	if (t3 >= 1.0f && t4 < 1.0f)
	{
		t4 += 0.001f;
	}
	
	static GLfloat t5 = 0.0f;
	RA_x = lerp(3.0f, 0.5f, t5);
	RA_y = lerp(-1.0f, 0.0f, t5);

	if (t4 >= 1.0f && t5 < 1.0f)
	{
		t5 += 0.001f;
	}

	static GLfloat t6 = 0.0f;
	T_x = lerp(3.0f, 1.2f, t6);
	T_y = lerp(0.0f, 0.0f, t6);

	if (t5 >= 1.0f && t6 < 1.0f)
	{
		t6 += 0.001f;
	}

	// Plane Fly IN

	static GLfloat t1_plane = 0.0f;

	plane1_x = lerp(-3.0f, -1.5f, t1_plane);
	// plane1_y = lerp(1.5, 0.05f, t1_plane);
	plane1_y = lerp(3.5, 0.05f, t1_plane);
	plane1_angle = lerp(-90.0f, 0.0f, t1_plane);

	plane2_x = lerp(-3.0f, -1.5f, t1_plane);
	plane2_y = lerp(0.0, 0.0f, t1_plane);

	plane3_x = lerp(-3.0f, -1.5f, t1_plane);
	// plane3_y = lerp(-1.5, -0.05f, t1_plane);
	plane3_y = lerp(-3.5, -0.05f, t1_plane);
	plane3_angle = lerp(90.0f, 0.0f, t1_plane);


	if (t6 >= 1.0f && t1_plane < 1.0f)
	{
		t1_plane += 0.0001f;
	}

	// Plane Fly STRAIGHT

	static GLfloat t2_plane = 0.0f;

	if (t1_plane >= 1.0f)
	{
		plane1_x = lerp(-1.5f, 1.5f, t2_plane);		
		plane2_x = lerp(-1.5f, 1.5f, t2_plane);		
		plane3_x = lerp(-1.5f, 1.5f, t2_plane);		
		if (t1_plane >= 1.0f && t2_plane < 1.0f)
		{
			t2_plane += 0.0001f;
		}
	}
	
	// Plane Fly OUT

	static GLfloat t3_plane = 0.0f;

	if (t2_plane >= 1.0f)
	{
		plane1_x = lerp(1.5f, 3.0f, t3_plane);
		// plane1_y = lerp(0.0, 1.5f, t3_plane);
		plane1_y = lerp(0.0, 3.5f, t3_plane);
		plane1_angle = lerp(0.0f, 90.0f, t3_plane);

		plane2_x = lerp(1.5f, 3.0f, t3_plane);
		plane2_y = lerp(0.0, 0.0f, t3_plane);

		plane3_x = lerp(1.5f, 3.0f, t3_plane);
		// plane3_y = lerp(0.0, -1.5f, t3_plane);
		plane3_y = lerp(0.0, -3.5f, t3_plane);
		plane3_angle = lerp(0.0f, -90.0f, t3_plane);

		if (t2_plane >= 1.0f && t3_plane < 1.0f)
		{
			t3_plane += 0.0001f;
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

}


void plane(GLfloat color[])
{
	glScalef(0.5f, 0.5f, 0.5f);

	// T1
	glBegin(GL_QUADS);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.6f, 0.2f, 0.0f);		// LT

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.6f, 0.0f, 0.0f);		// LB

	glColor3f(0.662f, 0.662f, 0.662f);
	glVertex3f(0.55f, 0.0f, 0.0f);		// RB

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.35f, 0.2f, 0.0f);		// RT

	glEnd();

	// T2
	glBegin(GL_QUADS);

	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(-0.6f, 0.0f, 0.0f);		// LT
	glVertex3f(-0.6f, -0.15f, 0.0f);	// LB

	glColor3f(0.662f, 0.662f, 0.662f);
	glVertex3f(0.45f, -0.15f, 0.0f);	// RB

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.55f, 0.0f, 0.0f);		// RT

	glEnd();

	// T3
	glBegin(GL_QUADS);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.1f, 0.3f, 0.0f);		// LT

	glColor3f(0.662f, 0.662f, 0.662f);
	glVertex3f(0.05f, 0.2f, 0.0f);		// LB

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.35f, 0.2f, 0.0f);		// RB

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.3f, 0.0f);		// RT

	glEnd();

	// T4
	glBegin(GL_QUADS);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.6f, 0.6f, 0.0f);		// LT
	glVertex3f(-0.6f, 0.2f, 0.0f);		// LB
	glVertex3f(-0.4f, 0.2f, 0.0f);		// RB
	glVertex3f(-0.55f, 0.6f, 0.0f);		// RT
	
	glEnd();

	// Smoke 
	glBegin(GL_QUADS);

	glColor3fv(color);

	glVertex3f(-1.0f, 0.0f, 0.0f);		// LT
	glVertex3f(-1.0f, -0.15f, 0.0f);	// LB
	glVertex3f(-0.6f, -0.15f, 0.0f);	// RB
	glVertex3f(-0.6f, 0.0f, 0.0f);		// RT

	glEnd();

}

// staticBharat
void staticBharat(void)
{

	void draw_B();
	void draw_H();
	void draw_A();
	void draw_R();
	void draw2_A();
	void draw_T();
	

	glTranslatef(0.0f, 0.0f, -3.0f);

	glPushMatrix();	
	glTranslatef(B_x, 0.0f, 0.0f);
	draw_B();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(H_x, H_y, 0.0f);
	draw_H();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(A_x, A_y, 0.0f);
	draw_A();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(R_x, R_y, 0.0f);
	draw_R();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(RA_x, RA_y, 0.0f);
	draw2_A();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(T_x, T_y, 0.0f);
	draw_T();
	glPopMatrix();

}

void draw_B()
{
	glColor3f(0.5f, 0.5f, 0.5f);

	glBegin(GL_QUADS);
	glColor3f(orange_R, orange_G, orange_B);
	glVertex3f(0.1f, 0.5f, 0.0f);		// RT
	glVertex3f(0.0f, 0.5f, 0.0f);		// LT
	glColor3f(white_R, white_G, white_B);
	glVertex3f(0.0f, 0.0f, 0.0f);		// LB
	glVertex3f(0.1f, 0.0f, 0.0f);		// RB	
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(white_R, white_G, white_B);
	glVertex3f(0.1f, 0.0f, 0.0f);		// rt
	glVertex3f(0.0f, 0.0f, 0.0f);		// lt			
	glColor3f(green_R, green_G, green_B);
	glVertex3f(0.0f, -0.5f, 0.0f);
	glVertex3f(0.1f, -0.5f, 0.0f);
	glEnd();

	glBegin(GL_QUADS); // orange box 1
	glColor3f(orange_R, orange_G, orange_B);
	glVertex3f(0.4f, 0.5f, 0.0f);		// RT 				
	glVertex3f(0.1f, 0.5f, 0.0f);		// LT
	glColor3f(white_R, white_G, white_B);
	glVertex3f(0.1f, 0.0f, 0.0f);	//LB	
	glVertex3f(0.4f, 0.0f, 0.0f);	//RB
	glEnd();

	glBegin(GL_QUADS); //black box 1
	glColor3f(0.662f, 0.662f, 0.662f);

	glVertex3f(0.3f, 0.4f, 0.0f);		// RT 				
	glVertex3f(0.1f, 0.4f, 0.0f);		// LT
	glVertex3f(0.1f, 0.05f, 0.0f);	//LB	
	glVertex3f(0.3f, 0.05f, 0.0f);	//RB
	glEnd();

	glBegin(GL_QUADS); // green box 2
glColor3f(white_R, white_G, white_B);
	glVertex3f(0.4f, 0.0f, 0.0f);	//RT	
	glVertex3f(0.1f, 0.0f, 0.0f);	//LT
glColor3f(green_R, green_G, green_B);
	glVertex3f(0.1f, -0.5f, 0.0f);  //LB	
	glVertex3f(0.4f, -0.5f, 0.0f);	//RB
	glEnd();

	glBegin(GL_QUADS); //black box 2
	glColor3f(0.662f, 0.662f, 0.662f);

	glVertex3f(0.3f, -0.05f, 0.0f);	//RT	
	glVertex3f(0.1f, -0.05f, 0.0f);	//LT	
	glVertex3f(0.1f, -0.4f, 0.0f);  //LB	
	glVertex3f(0.3f, -0.4f, 0.0f);	//RB		
	glEnd();


}

void draw_H()
{
	glColor3f(0.5f, 0.5f, 0.5f);

	//upper main quad
	glBegin(GL_QUADS); // orange box 1
glColor3f(orange_R, orange_G, orange_B);
	glVertex3f(0.4f, 0.5f, 0.0f);		// RT 				
	glVertex3f(0.0f, 0.5f, 0.0f);		// LT
glColor3f(white_R, white_G, white_B);
	glVertex3f(0.0f, 0.0f, 0.0f);	//LB	
	glVertex3f(0.4f, 0.0f, 0.0f);	//RB
	glEnd();

	glBegin(GL_QUADS); // orange box 1
	glColor3f(white_R, white_G, white_B);
	glVertex3f(0.4f, 0.0f, 0.0f);		// RT 				
	glVertex3f(0.0f, 0.0f, 0.0f);		// LT
	glColor3f(green_R, green_G, green_B);
	glVertex3f(0.0f, -0.5f, 0.0f);	//LB	
	glVertex3f(0.4f, -0.5f, 0.0f);	//RB
	glEnd();

	glBegin(GL_QUADS); //black box 1
	glColor3f(0.662f, 0.662f, 0.662f);

	glVertex3f(0.3f, 0.5f, 0.0f);		// RT 				
	glVertex3f(0.1f, 0.5f, 0.0f);		// LT
	glVertex3f(0.1f, 0.05f, 0.0f);	//LB	
	glVertex3f(0.3f, 0.05f, 0.0f);	//RB
	glEnd();
	glBegin(GL_QUADS); //black box 2
	glColor3f(0.662f, 0.662f, 0.662f);

	glVertex3f(0.3f, -0.05f, 0.0f);	//RT	
	glVertex3f(0.1f, -0.05f, 0.0f);	//LT	
	glVertex3f(0.1f, -0.5f, 0.0f);  //LB	
	glVertex3f(0.3f, -0.5f, 0.0f);	//RB		
	glEnd();

}

void draw_A()
{
	glColor3f(0.5f, 0.5f, 0.5f);

	//upper main quad
	glBegin(GL_QUADS); // orange box 1
	glColor3f(orange_R, orange_G, orange_B);
	glVertex3f(0.4f, 0.5f, 0.0f);		// RT 				
	glVertex3f(0.0f, 0.5f, 0.0f);		// LT
	glColor3f(white_R, white_G, white_B);
	glVertex3f(0.0f, 0.0f, 0.0f);	//LB	
	glVertex3f(0.4f, 0.0f, 0.0f);	//RB
	glEnd();

	glBegin(GL_QUADS); // orange box 1
glColor3f(white_R, white_G, white_B);
	glVertex3f(0.4f, 0.0f, 0.0f);		// RT 				
	glVertex3f(0.0f, 0.0f, 0.0f);		// LT
glColor3f(green_R, green_G, green_B);
	glVertex3f(0.0f, -0.5f, 0.0f);	//LB	
	glVertex3f(0.4f, -0.5f, 0.0f);	//RB
	glEnd();

	glBegin(GL_QUADS); //black box 1
	glColor3f(0.662f, 0.662f, 0.662f);

	glVertex3f(0.3f, 0.4f, 0.0f);		// RT 				
	glVertex3f(0.1f, 0.4f, 0.0f);		// LT
	glVertex3f(0.1f, 0.05f, 0.0f);	//LB	
	glVertex3f(0.3f, 0.05f, 0.0f);	//RB
	glEnd();
	glBegin(GL_QUADS); //black box 2
glColor3f(0.662f, 0.662f, 0.662f);

	glVertex3f(0.3f, -0.05f, 0.0f);	//RT	
	glVertex3f(0.1f, -0.05f, 0.0f);	//LT	
	glVertex3f(0.1f, -0.5f, 0.0f);  //LB	
	glVertex3f(0.3f, -0.5f, 0.0f);	//RB		
	glEnd();

}

void draw_R()
{
	glColor3f(0.5f, 0.5f, 0.5f);

	//upper main quad
	glBegin(GL_QUADS); // orange box 1
	glColor3f(orange_R, orange_G, orange_B);
	glVertex3f(0.4f, 0.5f, 0.0f);		// RT 				
	glVertex3f(0.0f, 0.5f, 0.0f);		// LT
	glColor3f(white_R, white_G, white_B);
	glVertex3f(0.0f, 0.0f, 0.0f);	//LB	
	glVertex3f(0.4f, 0.0f, 0.0f);	//RB
	glEnd();

	glBegin(GL_QUADS); // green box 1
	glColor3f(white_R, white_G, white_B);
	glVertex3f(0.4f, 0.0f, 0.0f);		// RT 				
	glVertex3f(0.0f, 0.0f, 0.0f);		// LT
	glColor3f(green_R, green_G, green_B);
	glVertex3f(0.0f, -0.5f, 0.0f);	//LB	
	glVertex3f(0.4f, -0.5f, 0.0f);	//RB
	glEnd();

	glBegin(GL_QUADS); //black box 1
	glColor3f(0.662f, 0.662f, 0.662f);

	glVertex3f(0.3f, 0.4f, 0.0f);		// RT 				
	glVertex3f(0.1f, 0.4f, 0.0f);		// LT
	glVertex3f(0.1f, 0.05f, 0.0f);	//LB	
	glVertex3f(0.3f, 0.05f, 0.0f);	//RB
	glEnd();
	glBegin(GL_QUADS); //black box 2
	glColor3f(0.662f, 0.662f, 0.662f);

	glVertex3f(0.4f, -0.05f, 0.0f);	//RT	
	glVertex3f(0.1f, -0.05f, 0.0f);	//LT	
	glVertex3f(0.1f, -0.5f, 0.0f);  //LB	
	glVertex3f(0.4f, -0.5f, 0.0f);	//RB		
	glEnd();

	glBegin(GL_QUADS); // R slant
	glColor3f(white_R, white_G, white_B);
	glVertex3f(0.2f, -0.035f, 0.0f);		// RT 				
	glVertex3f(0.090f, -0.035f, 0.0f);		// LT
	glColor3f(green_R, green_G, green_B);
	glVertex3f(0.35f, -0.5f, 0.0f);	//LB	
	glVertex3f(0.45f, -0.5f, 0.0f);	//RB
	glEnd();
}
void draw2_A()
{
	glColor3f(0.5f, 0.5f, 0.5f);

	//upper main quad
	glBegin(GL_QUADS); // orange box 1
	glColor3f(orange_R, orange_G, orange_B);
	glVertex3f(0.4f, 0.5f, 0.0f);		// RT 				
	glVertex3f(0.0f, 0.5f, 0.0f);		// LT
	glColor3f(white_R, white_G, white_B);
	glVertex3f(0.0f, 0.0f, 0.0f);	//LB	
	glVertex3f(0.4f, 0.0f, 0.0f);	//RB
	glEnd();

	glBegin(GL_QUADS); // orange box 1
	glColor3f(white_R, white_G, white_B);
	glVertex3f(0.4f, 0.0f, 0.0f);		// RT 				
	glVertex3f(0.0f, 0.0f, 0.0f);		// LT
	glColor3f(green_R, green_G, green_B);
	glVertex3f(0.0f, -0.5f, 0.0f);	//LB	
	glVertex3f(0.4f, -0.5f, 0.0f);	//RB
	glEnd();

	glBegin(GL_QUADS); //black box 1
	glColor3f(0.662f, 0.662f, 0.662f);

	glVertex3f(0.3f, 0.4f, 0.0f);		// RT 				
	glVertex3f(0.1f, 0.4f, 0.0f);		// LT
	glVertex3f(0.1f, 0.05f, 0.0f);	//LB	
	glVertex3f(0.3f, 0.05f, 0.0f);	//RB
	glEnd();
	glBegin(GL_QUADS); //black box 2
	glColor3f(0.662f, 0.662f, 0.662f);

	glVertex3f(0.3f, -0.05f, 0.0f);	//RT	
	glVertex3f(0.1f, -0.05f, 0.0f);	//LT	
	glVertex3f(0.1f, -0.5f, 0.0f);  //LB	
	glVertex3f(0.3f, -0.5f, 0.0f);	//RB		
	glEnd();

}
void draw_T()
{
	glColor3f(0.5f, 0.5f, 0.5f);

	glBegin(GL_QUADS);
	glColor3f(orange_R, orange_G, orange_B);
	glVertex3f(0.1f, 0.4f, 0.0f);		// RT
	glVertex3f(0.0f, 0.4f, 0.0f);		// LT
	glColor3f(white_R, white_G, white_B);
	glVertex3f(0.0f, 0.0f, 0.0f);		// LB
	glVertex3f(0.1f, 0.0f, 0.0f);		// RB	
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(white_R, white_G, white_B);
	glVertex3f(0.1f, 0.0f, 0.0f);		// rt
	glVertex3f(0.0f, 0.0f, 0.0f);		// lt			
	glColor3f(green_R, green_G, green_B);
	glVertex3f(0.0f, -0.5f, 0.0f);
	glVertex3f(0.1f, -0.5f, 0.0f);
	glEnd();
	glBegin(GL_QUADS); // orange box 1
	glColor3f(orange_R, orange_G, orange_B);
	glVertex3f(0.3f, 0.5f, 0.0f);		// RT 		
	glVertex3f(-0.2f, 0.5f, 0.0f);		// LT	
	glVertex3f(-0.2f, 0.4f, 0.0f);		// LB 		
	glVertex3f(0.3f, 0.4f, 0.0f);		// RB		

	glEnd();
}




















