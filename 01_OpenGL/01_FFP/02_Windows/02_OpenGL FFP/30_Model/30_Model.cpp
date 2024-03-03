// SKELETON CODE - BASE CODE for D3D, WINDOWS (FFP>OpenGL) and OpenGL(PP)

// Windows header files
#include <windows.h>	// Win32 API
#include <stdlib.h>		// For exit()
#include <stdio.h>		// For FileIO

// OpenGL Header Files
#include <GL/gl.h>		// #include <gl\GL.h> Windows - not case sensitive
#include <GL/glu.h>		
#include "OGL.h"		// User defined header file

#include "Model.h"

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

// GOROUD SHADING - ALBEDO PROGRAM

BOOL gbLight = FALSE;

GLfloat lightAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f};			
GLfloat lightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};			// White Diffused Light
GLfloat lightSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};			// White Specular Light
GLfloat lightPosition[] = {100.0f, 100.0f, 100.0f, 1.0f};	// GLfloat lightPosition[] = {x, y, z, w=0/1};

GLfloat materialAmbient[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat materialDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat materialSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat materialShininess[] = {128.0f};			

// Texture Object

BOOL bTexture = FALSE;

GLuint texture_model = 0;

// For Animation

BOOL bAnimate = FALSE;

GLfloat angle = 0.0f;

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
	
	gpFile = fopen("30_model.txt", "w");
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

				// Update (For animation and changes

				if (bAnimate == TRUE)
				{
					update();
				}

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
				// glEnable(GL_LIGHTING);
				// Not a good discipline to call in WndProc()
				gbLight = TRUE;
			}
			else
			{
				// glDisable(GL_LIGHTING);
				// Not a good discipline to call in WndProc()
				gbLight = FALSE;
			}

		break;
		
		case 'T':
		case 't':

			if (bTexture == FALSE)
			{
				// glEnable(GL_LIGHTING);
				bTexture = TRUE;
			}
			else
			{
				// glDisable(GL_LIGHTING);
				bTexture = FALSE;
			}
			break;
		
			case 'A':
			case 'a':

				if (bAnimate == FALSE)
				{
					bAnimate = TRUE;
				}
				else
				{
					bAnimate = FALSE;
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

	BOOL loadGLTexture(GLuint*, TCHAR[]);

	BOOL bResult;

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

	bResult = loadGLTexture(&texture_model, MAKEINTRESOURCE(IDBITMAP_MARBLE));
	// Error Checking
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of model texture thread Failed...\n");
		return(-6);
	}

	// WarmUp Resize Call
	resize(WIN_WIDTH, WIN_HEIGHT);

	// Light Properties
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);		// Enabling light1 out of 8 lights
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glEnable(GL_LIGHT0);								// Enabling all the above set properties

	// Material Properties
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	return(0);
}


BOOL loadGLTexture(GLuint* texture, TCHAR imageResourceID[])
{
	// Local Variable Declarations
	HBITMAP hBitmap = NULL;
	BITMAP bmp;

	// Load the Image
	hBitmap = (HBITMAP)LoadImage(GetModuleHandle(NULL), imageResourceID, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);			// HMODULE GetModuleHandle (LPCTSTR lpModuleName);
	/* 
	if (hBitmap == NULL)
	{
		fprintf(gpFile, "Loading of Image Failed...\n");
		return(FALSE);
	}
	*/

	// Step 6
	GetObject(hBitmap, sizeof(BITMAP), &bmp);
	// Step 7
	glGenTextures(1, texture);

	// Step 7 glBindTexture
	glBindTexture(GL_TEXTURE_2D, *texture);		// glBindTexture(Binding Point (cuz of state machine) Macro, texture value);

	// Step 8
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);				// glPixelStorei(GL_UNPACK_ALIGNMENT- checking the compression (compressed/uncompressed) of the image, 4- for R,G,B,alpha);
	// glPixelStorei(GL_UNPACK_ALIGNMENT, 1);		   // glPixelStorei(GL_UNPACK_ALIGNMENT- checking the compression (compressed/uncompressed) of the image, 1); for Programmable Pipeline

	// Set texture parameters Step 10
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);					// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER- magnifies the texture closer to viewer/camera, GL_LINEAR- give the image data linearly of high quality);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);		// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER- minifies the texture closer to viewer/camera, GL_LINEAR_MIPMAP_LINEAR- give the image data after MIPMAPPING depending on the Mipmap quality);

	// Create multiple mipmap images Step 10

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, bmp.bmWidth, bmp.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, (void*)bmp.bmBits);

	glBindTexture(GL_TEXTURE_2D, 0);		// glBindTexture(GL_TEXTURE_2D, 0- unbinding of the texture);

	// Delete Image Resource Object Step 12 
	DeleteObject(hBitmap);
	hBitmap = NULL;

	return(TRUE);
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
	// Local Variable Declarations
	
	int i, j;
	int vi, ni, ti;

	// Code

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Step 3 (Compulsory)	// To paint the window Blue after setting it in glClearColor()
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -1.5f);
	glRotatef(angle, 0.0f, 1.0f, 0.0f);

	// Toggle Lighting
	// Variable that changes state is called FLAG

	if (gbLight == TRUE)
	{
		glEnable(GL_LIGHTING);
	}
	else
	{
		glDisable(GL_LIGHTING);
	}

	// Toggle Texture
	if (bTexture == TRUE)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture_model);
	}
	else
	{
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	glBegin(GL_TRIANGLES);

	for (i = 0; i < (sizeof(face_indicies)/ sizeof(face_indicies[0])); i++)
	{
		for (j = 0; j < 3; j++) 
		{
			vi = face_indicies[i][j];
			ni = face_indicies[i][j + 3];
			ti = face_indicies[i][j + 6];

			glNormal3f(normals[ni][0], normals[ni][1], normals[ni][2]);
			glTexCoord2f(textures[ti][0], textures[ti][1]);
			glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		}
	}
	
	glEnd();

	SwapBuffers(ghdc);		// Win32 API. ghrc not used as it is an gl API that the windows DC wont understand
}

void update(void)
{
	// Code

	angle = angle - 0.05f;		// cAngle in "degrees"

	if (angle <= 0.0f)
	{
		angle = angle + 360.0f;
		// angle = 0.0f; Also Works
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

	if (texture_model)
	{
		glDeleteTextures(1, &texture_model);
		texture_model = 0;
	}

}
























