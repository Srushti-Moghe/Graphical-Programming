//Common - Windows Header files
# include <windows.h> // win32 API
# include <stdio.h>   // for file I/O
# include <stdlib.h>  // for for exit() func

//OPENGL Header Files
HDC ghdc=NULL;		// DC - Device context
HGLRC ghrc = NULL;  // RC - Rendering Context

# include <gl/glew.h> // this must be before # include<gl/GL.h>
# include<gl/GL.h> // PATH - C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um\gl
# include "OGL.h" //user cha - resorce file for icon MYICON

# include "vmath.h"
using namespace vmath;

// link with openl library
#pragma comment(lib,"glew32.lib")
#pragma comment(lib,"OpenGL32.lib")

// global function declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Macros 
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// OpenGl - Global variables
FILE *gpFile = NULL; // handle for file

HWND ghwnd=NULL; //global window handle
BOOL gbActive = FALSE;

DWORD dwStyle = 0; // global window style 32 bit =16+16 /8+8+8+8 lowword/highword
WINDOWPLACEMENT wpPrev={sizeof(WINDOWPLACEMENT)}; 

BOOL gbFullscreen = FALSE; 

//vertex shader
GLuint shaderProgramObject = 0;

//variable for pyramid
GLuint vao_pyramid = 0;
GLuint vbo_position_pyramid = 0;
GLuint vbo_color_pyramid = 0;

//variable for cube
GLuint vao_cube = 0;
GLuint vbo_position_cube = 0;
GLuint vbo_color_cube = 0;

mat4 perspectiveProjectionMatrix; // mat4 -> vmath.h
GLuint mvpMatrixUniform = 0;
 
//global variable declaration
GLfloat	pyramidAngle = 0.0f;
GLfloat cubeAngle = 0.0f;

// own data type enum
enum
{
	AMC_ATTRIBUTE_POSITION = 0,
	AMC_ATTRIBUTE_COLOR
};

// entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// Local Variable Declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("SUM Window");

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
	gpFile = fopen("Log.txt", "w");
	if (gpFile == NULL)
	{
		MessageBox(NULL, TEXT("Log File cannot be opened"), TEXT("Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	fprintf(gpFile, "Program started Successfully...\n\n");

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
		WS_EX_APPWINDOW,
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

		DestroyWindow(hwnd);
	}

	// Show the Window
	ShowWindow(hwnd, iCmdShow);

	SetForegroundWindow(hwnd);

	SetFocus(hwnd);

	// UpdateWindow(hwnd); is sent to WM_PAINT hence to be removed

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
	switch (iMsg)
	{
	case WM_SETFOCUS:		// Message for Active Window 
		gbActive = TRUE;
		break;

	case WM_KILLFOCUS:		// Message that deviates focus from the active window
		gbActive = FALSE;
		break;

	case WM_SIZE:
		resize(LOWORD(lParam), HIWORD(lParam));
		// void resize(width, height);
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
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
		ShowCursor(TRUE);
	}
}

int initialize(void)
{
	// Function Declarations
	void printGLInfo(void);
	void uninitialize(void);
	void resize(int, int);

	// Prototype Declarations

	// Code
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));		// struct initialization method02	

	// Initialization of PIXELFORMATDESCRIPTOR
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
	pfd.cDepthBits = 32;

	ghdc = GetDC(ghwnd);
	if (ghdc == NULL)
	{
		fprintf(gpFile, "GetDC() Failed...\n");
		return(-1);
	}

	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (iPixelFormatIndex == 0) // NON ZERO POSITIVE value is the success of iPixelFormatIndex
	{
		fprintf(gpFile, "ChoosePixelFormat() Failed...\n");
		return(-2);
	}

	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFile, "SetPixelFormat() Failed...\n");
		return(-3);
	}

	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		fprintf(gpFile, "wglCreateContext() Failed...\n");
		return(-4);
	}
	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFile, "wglMakeCurrent() Failed...\n");
		return(-5);
	}

	// Initialize GLEW
	if (glewInit() != GLEW_OK)
	{
		fprintf(gpFile, "glewInit() Failed...\n");
		return(-6);
	}

	// Print GL info
	printGLInfo();

	// step1 - vertex shader code
	const GLchar * vertexShaderSourceCode = 
											"#version 460 core\n" \
											"\n" \
											"in vec4 aPosition;\n" \
											"uniform mat4 uMVPMatrix;\n" \
											"in vec4 aColor;\n" \
											"out vec4 oColor;\n" \
											"void main(void)\n" \
											"{\n" \
											"gl_Position= uMVPMatrix*aPosition;\n" \
											"oColor=aColor;\n" \
											"}\n";

	GLuint vertexShaderObject = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderObject,1,(const GLchar **)&vertexShaderSourceCode,NULL);
	glCompileShader(vertexShaderObject);
	GLint status=0;
	GLint infoLogLength=0;
	GLchar *szInfoLog = NULL;
	glGetShaderiv(vertexShaderObject,GL_COMPILE_STATUS,&status);
	if(status==GL_FALSE)
	{
		glGetShaderiv(vertexShaderObject,GL_INFO_LOG_LENGTH,&infoLogLength); 
		if(infoLogLength >0)
		{
			szInfoLog = (GLchar*) malloc(infoLogLength);		
			if(infoLogLength != NULL)
			{
				glGetShaderInfoLog(vertexShaderObject,infoLogLength,NULL,szInfoLog);
				fprintf(gpFile,"vertex Shader compilation error -  %s \n",szInfoLog);
				free(szInfoLog);
				szInfoLog = NULL;
				
			}
		}
		uninitialize();
	}


	// Fragment shader code

	const GLchar *fragementShaderSourceCode = 
											"#version 460 core \n" \
											"\n" \
											"in vec4 oColor; \n" \
											"out vec4 FragColor; \n" \
											"void main(void) \n" \
											"{ \n" \
											"FragColor = oColor; \n" \
											"} \n" ;

	GLuint fragmentShaderObject = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderObject,1,(const GLchar **)&fragementShaderSourceCode,NULL);
	glCompileShader(fragmentShaderObject);
	status=0;
	infoLogLength=0;
	szInfoLog = NULL;
	glGetShaderiv(fragmentShaderObject,GL_COMPILE_STATUS,&status);
	if(status==GL_FALSE)
	{
		glGetShaderiv(fragmentShaderObject,GL_INFO_LOG_LENGTH,&infoLogLength);
		if(infoLogLength >0)
		{
			szInfoLog = (GLchar*) malloc(infoLogLength);		
			if(szInfoLog != NULL)
			{
				glGetShaderInfoLog(fragmentShaderObject,infoLogLength,NULL,szInfoLog);
				fprintf(gpFile,"Fragment Shader compilation error -  %s \n",szInfoLog);
				free(szInfoLog);
				szInfoLog = NULL;
				uninitialize();
			}

		}
		uninitialize();
	}

	shaderProgramObject = glCreateProgram();
	glAttachShader(shaderProgramObject,vertexShaderObject);
	glAttachShader(shaderProgramObject,fragmentShaderObject);
	
	// prelinking code
	glBindAttribLocation(shaderProgramObject,AMC_ATTRIBUTE_POSITION,"aPosition"); //check spelling of apostion
	glBindAttribLocation(shaderProgramObject,AMC_ATTRIBUTE_COLOR,"aColor"); //check spelling of color
	
	glLinkProgram(shaderProgramObject);

	status=0;
	infoLogLength=0;
	szInfoLog = NULL;
	glGetProgramiv(shaderProgramObject,GL_LINK_STATUS,&status);
	if(status==GL_FALSE)
	{
		glGetProgramiv(shaderProgramObject,GL_INFO_LOG_LENGTH,&infoLogLength);
		if(infoLogLength >0)
		{
			szInfoLog = (GLchar*) malloc(infoLogLength);		
			if(infoLogLength != NULL)
			{
				glGetProgramInfoLog(shaderProgramObject,infoLogLength,NULL,szInfoLog);
				fprintf(gpFile,"Shader Program Linking error -  %s \n",szInfoLog);
				free(szInfoLog);
				szInfoLog = NULL;
				uninitialize();
			}
		}
		uninitialize();
	}

	//get Shader Uniform Locations
	mvpMatrixUniform = glGetUniformLocation(shaderProgramObject,"uMVPMatrix");
	
	// PYRAMID
	const GLfloat pyramid_position[] =
	{
		// front
	0.0f, 1.0f, 0.0f,
	-1.0f, -1.0f, 1.0f,
	1.0f, -1.0f, 1.0f,

	// right
0.0f, 1.0f, 0.0f,
1.0f, -1.0f, 1.0f,
1.0f, -1.0f, -1.0f,

// back
0.0f, 1.0f, 0.0f,
1.0f, -1.0f, -1.0f,
-1.0f, -1.0f, -1.0f,

// left
0.0f, 1.0f, 0.0f,
-1.0f, -1.0f, -1.0f,
-1.0f, -1.0f, 1.0f

	};
	const GLfloat pyramid_color[] =
	{
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f,

	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f

	};
	const GLfloat cube_position[] =
	{
		// top
		1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		// bottom
		1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f,  1.0f,

		// front
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, -1.0f, 1.0f,
		1.0f, -1.0f, 1.0f,

		// back
		1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,

		// right
		1.0f, 1.0f, -1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, -1.0f, 1.0f,
		1.0f, -1.0f, -1.0f,

		// left
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f, 1.0f

	};

	const GLfloat cube_color[] =
	{
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,

		0.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 1.0f,

		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,

		1.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,

		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,

		1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f
	};


	// Pyramid

	glGenVertexArrays(1, &vao_pyramid);
	glBindVertexArray(vao_pyramid);

	glGenBuffers(1, &vbo_position_pyramid);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_position_pyramid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(pyramid_position), pyramid_position, GL_STATIC_DRAW);
	glVertexAttribPointer(AMC_ATTRIBUTE_POSITION, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(AMC_ATTRIBUTE_POSITION);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &vbo_color_pyramid);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_color_pyramid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(pyramid_color), pyramid_color, GL_STATIC_DRAW);
	glVertexAttribPointer(AMC_ATTRIBUTE_COLOR, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(AMC_ATTRIBUTE_COLOR);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	// Cube

	glGenVertexArrays(1, &vao_cube);
	glBindVertexArray(vao_cube);

	glGenBuffers(1, &vbo_position_cube);
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo_position_cube);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_position), cube_position, GL_STATIC_DRAW);
	glVertexAttribPointer(AMC_ATTRIBUTE_POSITION, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(AMC_ATTRIBUTE_POSITION);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &vbo_color_cube);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_color_cube);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_color), cube_color, GL_STATIC_DRAW);
	glVertexAttribPointer(AMC_ATTRIBUTE_COLOR, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(AMC_ATTRIBUTE_COLOR);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//vbo for color

	glVertexAttrib3f(AMC_ATTRIBUTE_COLOR, 0.0f, 0.0f, 1.0f);
	glBindVertexArray(0);

	// Enabling Depth

	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	perspectiveProjectionMatrix = vmath::mat4::identity();

	resize(WIN_WIDTH, WIN_HEIGHT);

	return(0);

}

void printGLInfo(void)
{
	// Variable Declarations
	GLint numExtensions;
	GLint i;

	// Code

	fprintf(gpFile, "OpenGL Vendor   : %s \n", glGetString(GL_VENDOR));						// OpenGL Graphic Card
	fprintf(gpFile, "OpenGL Renderer : %s \n", glGetString(GL_RENDERER));						// OpenGL Driver Version
	fprintf(gpFile, "OpenGL Version  : %s \n", glGetString(GL_VERSION));					// OpenGL Version
	fprintf(gpFile, "GLSL Version    : %s \n\n", glGetString(GL_SHADING_LANGUAGE_VERSION));	// Graphic Library Shading Language Version

	// Listing of Supported Extensions
	glGetIntegerv(GL_EXTENSIONS, &numExtensions);

	for (i = 0; i < numExtensions; i++)
	{
		fprintf(gpFile, "%s \n", glGetStringi(GL_EXTENSIONS, i));
	}

}

void resize(int width ,int height)
{
	//code
	if (height <= 0)
		height = 1; // precaution for division	
	glViewport(0, 0, (GLsizei)width, (GLsizei)height ); //zoomed binacular view (limited)

	// set perspective projection matrix
	perspectiveProjectionMatrix = vmath::perspective(45.0f,( (GLfloat)width / (GLfloat)height ), 0.1f, 100.0f);	
}

void display(void)
{
	//Code

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(shaderProgramObject);


	// pyramid
	// Transformation
	mat4 modelViewMatrix = vmath::mat4::identity();
	mat4 translationMatrix = vmath::mat4::identity();
	mat4 rotationMatrix = vmath::mat4::identity();

	translationMatrix = vmath::translate(-1.5f, 0.0f, -6.0f);
	rotationMatrix = vmath::rotate(pyramidAngle, 0.0f, 1.0f, 0.0f);
	modelViewMatrix = translationMatrix * rotationMatrix;
	mat4 modelViewProjectionMatrix = perspectiveProjectionMatrix * modelViewMatrix; // order of multiplication is important


	// push above mvp into vertex shader's mvpuniform
	glUniformMatrix4fv(mvpMatrixUniform, 1, GL_FALSE, modelViewProjectionMatrix);
	glBindVertexArray(vao_pyramid);
	glDrawArrays(GL_TRIANGLES, 0, 12); //pyramid 3*4 sides
	glBindVertexArray(0);

	// cube
	// Transformation
	modelViewMatrix = vmath::mat4::identity();
	translationMatrix = vmath::mat4::identity();
	rotationMatrix = vmath::mat4::identity();
	mat4 scaleMatrix = vmath::mat4::identity();

	scaleMatrix = vmath::scale(0.75f, 0.75f, 0.75f);
	translationMatrix = vmath::translate(1.5f, 0.0f, -6.0f);
	mat4 rotationMatrix1 = vmath::rotate(cubeAngle, 1.0f, 0.0f, 0.0f);
	mat4 rotationMatrix2 = vmath::rotate(cubeAngle, 0.0f, 1.0f, 0.0f);
	mat4 rotationMatrix3 = vmath::rotate(cubeAngle, 0.0f, 0.0f, 1.0f);

	modelViewMatrix = translationMatrix * scaleMatrix * rotationMatrix1 * rotationMatrix2 * rotationMatrix3;

	modelViewProjectionMatrix = perspectiveProjectionMatrix * modelViewMatrix; // order of multiplication is important

	// push above mvp into vertex shader's mvpuniform
	glUniformMatrix4fv(mvpMatrixUniform, 1, GL_FALSE, modelViewProjectionMatrix);
	glBindVertexArray(vao_cube);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4); 
	glDrawArrays(GL_TRIANGLE_FAN, 4, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 8, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 12, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 16, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 20, 4);

	glBindVertexArray(0);
	glUseProgram(0);

	SwapBuffers(ghdc);
}

void update(void)
{
		// Code
	cubeAngle = cubeAngle - 0.05f;		// pyramidAngle in "degrees"
	if (cubeAngle <= 0.0f)
	{
		cubeAngle = cubeAngle + 360.0f;
		//cubeAngle = 0.0f; 
	}
	pyramidAngle = pyramidAngle + 0.1f; //update pyramidAngle value 
	if (pyramidAngle >= 360.0f)
	{
		pyramidAngle = pyramidAngle - 360.0f; // reset pyramidAngle to zero

	}
}

void uninitialize(void)
{
	//function declarations
	
	void ToggleFullscreen(void);
	
	//code
	if(shaderProgramObject)
	{
		glUseProgram(shaderProgramObject);
		GLint numShaders =0;	
		glGetProgramiv(shaderProgramObject,GL_ATTACHED_SHADERS,&numShaders);
		if(numShaders > 0)
		{
			GLuint *pShaders = (GLuint*) malloc(numShaders * sizeof(GLuint));

			if(numShaders !=NULL)
			{
				glGetAttachedShaders(shaderProgramObject,numShaders,NULL,pShaders);
			}
			for(GLint i =0;i< numShaders;i++)
			{
				glDetachShader(shaderProgramObject,pShaders[i]);
				glDeleteShader(pShaders[i]);
				pShaders[i]=0;
			}
			free(pShaders);
			pShaders = NULL;
		}
		glUseProgram(0);
		glDeleteProgram(shaderProgramObject);
		shaderProgramObject = 0;
	}
	
	// cube
	//delete vbo of position
		if (vbo_position_cube)
		{
			glDeleteBuffers(1, &vbo_position_cube);
			vbo_position_cube = 0;
		}
	//delete vao_cube
	if (vao_cube)
	{
		glDeleteVertexArrays(1, &vao_cube);
		vao_cube = 0;
	}
	if (vbo_color_cube)
	{
		glDeleteVertexArrays(1, &vbo_color_cube);
		vbo_color_cube = 0;
	}

	// Pyramid
	//delete vbo of color
	if (vbo_color_pyramid)
	{
		glDeleteBuffers(1, &vbo_color_pyramid);
		vbo_color_pyramid = 0;
	}
	//delete vbo of position
	if (vbo_position_pyramid)
	{
		glDeleteBuffers(1, &vbo_position_pyramid);
		vbo_position_pyramid = 0;
	}
	//delete vao_pyramid
	if (vao_pyramid)
	{
		glDeleteVertexArrays(1, &vao_pyramid);
		vao_pyramid = 0;
	}
	
	//application is exitting in full screen
	if(gbFullscreen == TRUE) //on ESCAPE Key- pressed event
	{
		ToggleFullscreen();
		gbFullscreen = FALSE;
	}

	//Make the hdc as current dc

	if(wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL,NULL);
	}

	//Destroy rendering context
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	//Release hdc
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	// Destroy window
	if(ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd=NULL;

	}

	//close the log file
	if(gpFile)
	{
		fprintf(gpFile,"Program ended successfully...!!\n");
		fclose(gpFile);
		gpFile=NULL;
	}	
}


