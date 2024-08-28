  
//Common - Windows Header files

# include <windows.h> // win32 API
# include <stdio.h>   // for file I/O
# include <stdlib.h>  // for for exit()
#include <iostream>

//OPENGL Header Files
HDC ghdc=NULL;		// DC - Device context
HGLRC ghrc = NULL;  // RC - Rendering Context

# include <gl/glew.h> 
# include<gl/GL.h> 
# include "OGL.h" 

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

//global variable declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// OpenGl - Global variables
FILE *gpFILE = NULL; // file handle pointer for gpFile

HWND ghwnd=NULL; //global window handle
BOOL GbActive = FALSE;

DWORD dwStyle = 0; 
WINDOWPLACEMENT wpPrev={sizeof(WINDOWPLACEMENT)}; 

BOOL gbFullscreen = FALSE; 

int centerX;
int centerY;

//vertex shader

GLuint shaderProgramObject = 0;
GLuint vao=0;

mat4 perspectiveProjectionMatrix; 
mat4 modelViewMatrix; 
GLuint mvpMatrixUniform = 0;
 
enum
{
	AMC_ATTRIBUTE_POSITION = 0,
	AMC_ATTRIBUTE_COLOR,
	AMC_ATTRIBUTE_TEXCOORD
};

GLuint vbo_position = 0;
GLuint vbo_texcoord = 0;
GLuint vbo_color = 0;

GLuint textureSamplerUniform = 0;
GLuint texture_smiley = 0;

// GLuint vao_pyramid = 0;
// GLuint vbo_position_pyramid = 0;
// GLuint vbo_color_pyramid = 0;
// GLuint vbo_texcoord_pyramid = 0;

GLuint vao_cube = 0;
GLuint vbo_position_cube = 0;
GLuint vbo_color_cube = 0;
GLuint vbo_texcoord_cube = 0;

// Angle
// GLfloat angle_pyramid = 0.0f;
GLfloat angle_cube = 0.0f;

// entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//function Declarations
	
	int initialize(void);
	void uninitialize(void);
	void display(void);
	void update(void);

	// Local variable declarations

	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT( "Srushti Umesh Moghe Window"); 
	int iresult=0;

	BOOL bDone = FALSE; 
	// Centering Window
	// X, Y coordinates for SCREEN
	HDC hdc=GetDC(NULL);
	int ScreenWidth = GetDeviceCaps(hdc, HORZRES);
	int ScreenHeight = GetDeviceCaps(hdc, VERTRES);

	// X, Y coordinates for WINDOW
	int WindowX = (ScreenWidth / 2) - (WIN_WIDTH / 2);
	int WindowY = (ScreenHeight / 2) - (WIN_HEIGHT / 2);


	//code
	//	gpFILE = fopen("Log.txt", "w");
	//	fopen_s 

	if (!AttachConsole(ATTACH_PARENT_PROCESS))
	{
		AllocConsole();
	}
	freopen("CONOUT$", "w", stdout);
	std::cout << "Log On Console" << std::endl;


	if (fopen_s(&gpFILE, "Log.txt", "w") != 0)
	{
		MessageBox(NULL, TEXT("Log File Cannot Be Opend"), TEXT("Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}

	fprintf(gpFILE, "Program Started Successfully\n");
	fprintf(gpFILE, "-------------------------------------------\n");
		
	// WNDCLASSEX initialization - Struct def with 12 members
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; 
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance ,MAKEINTRESOURCE(MYICON)); 
	wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName =  NULL;
	wndclass.hIconSm = LoadIcon(hInstance ,MAKEINTRESOURCE(MYICON));
	
	//Register WNDCLASSEX
	RegisterClassEx(&wndclass);

	//Create window 11 parameters

	hwnd = CreateWindowEx(
		WS_EX_APPWINDOW, 
		szAppName,
		TEXT("Srushti Umesh Moghe"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		centerX,
		centerY,
		WIN_WIDTH,		
		WIN_HEIGHT,		
		NULL,
		NULL,
		hInstance,
		NULL);
		
	//show the window  
	//WS_EX_APPWINDOW, - special for taskbar hiding

	ghwnd=hwnd;

	//initialization of window
	
	iresult = initialize();

	if (iresult != 0)
	{
		MessageBox(hwnd, TEXT("Window initialize() Failed........"), TEXT("ERROR....."), MB_OK | MB_ICONERROR);
		DestroyWindow(hwnd);
	}
	
	// Show The Window
	ShowWindow(hwnd, iCmdShow);
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);
	
	// Paint/Re-Draw The Window
	UpdateWindow(hwnd);

	// Game loop 

	while (bDone == FALSE )
	{
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE)) 
		{
			if(msg.message==WM_QUIT)
			{
				bDone=TRUE; 
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			
		}
		else
		{

			{

				if (GbActive == TRUE)
				{
					//RENDER
					display();

					//UPDATE
					update();
				}
			}
		}
			
	}

	//uninitialization
	uninitialize();
	return ((int)msg.wParam);
}

//callback fucntion definition 

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//function declaraion
	void ToggleFullscreen(void);
	void resize(int , int);

	//code
	switch(iMsg)
	{
	case WM_SETFOCUS:
		GbActive=TRUE;
		break;
	case WM_KILLFOCUS:
		GbActive=FALSE;
		break;
	case WM_SIZE:   
		resize(LOWORD(lParam),HIWORD(lParam));  
		break;
	case WM_ERASEBKGND:
		return(0); 
		break;
	case WM_KEYDOWN:
		switch(LOWORD(wParam))
		{
			case VK_ESCAPE: 
				DestroyWindow(hwnd);
				break;		
		}
		break;
	case WM_CHAR:
		switch(LOWORD(wParam))
		{
			case 'F':
			case 'f':
				if(gbFullscreen==FALSE)
				{
					ToggleFullscreen();
					gbFullscreen=TRUE;
				}
				else
				{
					ToggleFullscreen();
					gbFullscreen=FALSE;
				}
			break;		
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd); 
		break;
	case WM_DESTROY:
		if (gpFILE)
		{
			fprintf(gpFILE, "Program Ended Successfully...\n");
			fclose(gpFILE);
			gpFILE = NULL;
		}

		PostQuitMessage(0);
		break;
	default :
		break;
	}
	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void  ToggleFullscreen(void)
{
	// local variable declarations
	MONITORINFO  mi ={sizeof(MONITORINFO)};

	// Code

	if(gbFullscreen==FALSE) 
	{
		dwStyle=GetWindowLong(ghwnd,GWL_STYLE); 
		if(dwStyle & WS_OVERLAPPEDWINDOW)  
		{
			if(GetWindowPlacement(ghwnd,&wpPrev) && GetMonitorInfo(MonitorFromWindow (ghwnd,MONITORINFOF_PRIMARY ) , &mi) ) // a
			{
				SetWindowLong(ghwnd,GWL_STYLE,dwStyle & ~WS_OVERLAPPEDWINDOW); 
				SetWindowPos(ghwnd,
				HWND_TOP, // we are bringing back WS_Overlapped_window
				mi.rcMonitor.left, 
				mi.rcMonitor.top,
				mi.rcMonitor.right - mi.rcMonitor.left, //width
				mi.rcMonitor.bottom - mi.rcMonitor.top, // height
				SWP_NOZORDER | SWP_FRAMECHANGED );  // forces window WM_CALCSIZE calculate kar
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
	//function declarations
	void printGLInfo(void);
	void resize(int ,int);
	void uninitialize(void);
	void ToggleFullscreen(void);

	BOOL loadGLTexture(GLuint * texture, TCHAR imageResourceID[]);

	//code
	//variable declaration
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex=0;

	BOOL bResult;

	ZeroMemory(&pfd,sizeof(PIXELFORMATDESCRIPTOR)); //one of the way of initialising 

	// initialiszation of pfd 9 members
	pfd.nSize=sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion=1;
	pfd.dwFlags=PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER ; 
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;
	pfd.cDepthBits = 32; // 1st compulsory condition
	// 1- get the DC  - Device context

	ghdc = GetDC(ghwnd);
	if(ghdc ==NULL)
	{
		fprintf(gpFILE,"GET DC() FAILED .....!!!\n");
		return(-1);
	}

	// 2- fetching the closet picture format descriptor from O/s

	iPixelFormatIndex = ChoosePixelFormat(ghdc,&pfd); // take ghdc compare with pfd 
	if(iPixelFormatIndex == 0) // if fetches successfully it is >0
	{
		fprintf(gpFILE,"ChoosePixelFormat() FAILED .....!!!\n");
		return(-2);
	}

	//3- set the above obtained pixel format
	if ( (SetPixelFormat(ghdc,iPixelFormatIndex,&pfd) == FALSE) )
	{
		fprintf(gpFILE,"SetPixelFormat() FAILED .....!!!\n");
		return(-3);		
	}

	// 4- create  OpenGL context from Compatible DC using this ghdc 
	ghrc = wglCreateContext(ghdc);
	if (ghrc ==NULL)
	{
		fprintf(gpFILE,"wglCreateContext() FAILED .....!!!\n");
		return(-4);		
	}

	// 5- ghdc will give control to do further drawing - Make rendering context current
	if  ( wglMakeCurrent(ghdc,ghrc) == FALSE )
	{
		fprintf(gpFILE,"wglMakeCurrent() FAILED .....!!!\n");
		return(-5);			
	}

	//Initialize GLEW 
	if(glewInit() != GLEW_OK)
	{
		fprintf(gpFILE, "glew-Init() failed to initialize() GLEW...\n");
		return (-6);		
	}

	//print GLINFO
	printGLInfo(); //call func

	// Vertex Shader
	const GLchar* vertexShaderSourceCode =
									"#version 460 core" \
									"\n" \
									"in vec4 aPosition;" \
									"in vec2 aTexCoord;" \
									"out vec2 oTexCoord;" \
									"uniform mat4 uMVPMatrix;" \
									"void main(void)" \
									"{" \
									"gl_Position = uMVPMatrix * aPosition;" \
									"oTexCoord = aTexCoord;" \
									"}";

	GLuint vertexShaderObject = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShaderObject, 1, (const GLchar**)&vertexShaderSourceCode, NULL);

	glCompileShader(vertexShaderObject);

	GLint status = 0;
	GLint infoLogLength = 0;
	GLchar* szInfoLog = NULL;

	glGetShaderiv(vertexShaderObject, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		glGetShaderiv(vertexShaderObject, GL_INFO_LOG_LENGTH, &infoLogLength);
		if (infoLogLength > 0)
		{
			szInfoLog = (GLchar*)malloc(infoLogLength);
			if (szInfoLog != NULL)
			{
				glGetShaderInfoLog(vertexShaderObject, GL_INFO_LOG_LENGTH, NULL, szInfoLog);
				fprintf(gpFILE, "VertexShader Compilation error log : %s\n", szInfoLog);
				free(szInfoLog);
				szInfoLog = NULL;
			}
		}
		uninitialize();
	}


	//fragment shader
	const GLchar* fragmentShaderSourceCode =
										"#version 460 core" \
										"\n" \
										"in vec2 oTexCoord;" \
										"uniform sampler2D uTextureSampler;" \
										"out vec4 FragColor; " \
										"void main(void)" \
										"{" \
										"FragColor=texture(uTextureSampler, oTexCoord);" \
										"}";

	GLuint fragmentShaderObject = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShaderObject, 1, (const GLchar**)&fragmentShaderSourceCode, NULL);

	glCompileShader(fragmentShaderObject);

	status = 0;
	infoLogLength = 0;
	szInfoLog = NULL;

	glGetShaderiv(fragmentShaderObject,GL_COMPILE_STATUS,&status);
	if(status==GL_FALSE)
	{
		glGetShaderiv(fragmentShaderObject,GL_INFO_LOG_LENGTH,&infoLogLength);
		if(infoLogLength >0)
		{
			//step5- c) 
			szInfoLog = (GLchar*) malloc(infoLogLength);		
			if(szInfoLog != NULL)
			{
				//step5- d) 
				glGetShaderInfoLog(fragmentShaderObject,infoLogLength,NULL,szInfoLog);
				//step5- e) 
				fprintf(gpFILE,"Fragment Shader compilation error log %s \n",szInfoLog);
				//step5- f) 
				free(szInfoLog);
				szInfoLog = NULL;
				//step5- g) 
				uninitialize();
			}

		}
		uninitialize();
	}

	// Shader program

	shaderProgramObject = glCreateProgram();

	glAttachShader(shaderProgramObject, vertexShaderObject);
	glAttachShader(shaderProgramObject, fragmentShaderObject);

	glBindAttribLocation(shaderProgramObject, AMC_ATTRIBUTE_POSITION, "aPosition");
	glBindAttribLocation(shaderProgramObject, AMC_ATTRIBUTE_TEXCOORD, "aTexCoord");

	glLinkProgram(shaderProgramObject);

	status = 0;
	infoLogLength = 0;
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
			
				fprintf(gpFILE,"Shader Program Linking error log %s \n",szInfoLog);
				
				free(szInfoLog);
				szInfoLog = NULL;
				
				uninitialize();
			}
		}
		uninitialize();
	}

	//get Shader Uniform Locations
	mvpMatrixUniform = glGetUniformLocation(shaderProgramObject,"uMVPMatrix");

	//get shader uniform locations
	mvpMatrixUniform = glGetUniformLocation(shaderProgramObject, "uMVPMatrix");

	textureSamplerUniform = glGetUniformLocation(shaderProgramObject, "uTextureSampler");

	const GLfloat cube_position[] =
	{
		// front
		 1.0f,  1.0f,  1.0f, // top-right of front
		-1.0f,  1.0f,  1.0f, // top-left of front
		-1.0f, -1.0f,  1.0f, // bottom-left of front
		 1.0f, -1.0f,  1.0f, // bottom-right of front
	};

	const GLfloat cube_texcoords[] =
	{
		// RT
		1.0f, 1.0f, 
		0.0f, 1.0f, 
		0.0f, 0.0f, 
		1.0f, 0.0f, 
	};
	
	//CUBE
	//VAO

	glGenVertexArrays(1, &vao_cube);
	glBindVertexArray(vao_cube);

	//VBO for position
	glGenBuffers(1, &vbo_position_cube);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_position_cube);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_position), cube_position, GL_STATIC_DRAW);
	glVertexAttribPointer(AMC_ATTRIBUTE_POSITION, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(AMC_ATTRIBUTE_POSITION);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//VBO for texcoords
	glGenBuffers(1, &vbo_texcoord);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_texcoord);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_texcoords), cube_texcoords, GL_STATIC_DRAW);
	glVertexAttribPointer(AMC_ATTRIBUTE_TEXCOORD, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(AMC_ATTRIBUTE_TEXCOORD);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Unbind with VAO (Vertex Array Object)
	glBindVertexArray(0);

	bResult = loadGLTexture(&texture_smiley, MAKEINTRESOURCE(MY_SMILEY_BMP));
	// Error Checking
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Smiley texture thread Failed...\n");
		return(-7);
	}

	//enabling depth
	glClearDepth (1.0f); 
	glEnable(GL_DEPTH_TEST); 
	glDepthFunc(GL_LEQUAL); 
	
	// set the clear color of window to BLUE
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // here OpelGl starts

	// initialise perspectiveProjectionMatrix
	perspectiveProjectionMatrix = vmath::mat4::identity();

	// Tell OpenGL to enable the texture
	glEnable(GL_TEXTURE_2D);

	resize(WIN_WIDTH,WIN_HEIGHT);

	return(0);

}

// Function Definition

BOOL loadGLTexture(GLuint* texture, TCHAR imageResourceID[])
{
	// Local Variable Declarations
	HBITMAP hBitmap = NULL;
	BITMAP bmp;

	// Load the Image
	hBitmap = (HBITMAP)LoadImage(GetModuleHandle(NULL), imageResourceID, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);			// HMODULE GetModuleHandle (LPCTSTR lpModuleName);
	if (hBitmap == NULL)
	{
		fprintf(gpFILE, "Loading of Image Failed...\n");
		return(FALSE);
	}

	GetObject(hBitmap, sizeof(BITMAP), &bmp);

	glGenTextures(1, texture);

	glBindTexture(GL_TEXTURE_2D, *texture);		// glBindTexture(Binding Point (cuz of state machine) Macro, texture value);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);				
	// glPixelStorei(GL_UNPACK_ALIGNMENT, 4); For FFP

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);					// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER- magnifies the texture closer to viewer/camera, GL_LINEAR- give the image data linearly of high quality);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);		// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER- minifies the texture closer to viewer/camera, GL_LINEAR_MIPMAP_LINEAR- give the image data after MIPMAPPING depending on the Mipmap quality);
	
	// gluBuild2DMipmaps(GL_TEXTURE_2D, 3, bmp.bmWidth, bmp.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, (void*)bmp.bmBits); For FFP 7 params
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bmp.bmWidth, bmp.bmHeight, 0, GL_BGR, GL_UNSIGNED_BYTE, (void*)bmp.bmBits);	// 9 params
	glGenerateMipmap(GL_TEXTURE_2D);
	
	glBindTexture(GL_TEXTURE_2D, 0);		// glBindTexture(GL_TEXTURE_2D, 0- unbinding of the texture);

	// Delete Image Resource Object Step 12 
	DeleteObject(hBitmap);
	hBitmap = NULL;

	return(TRUE);
}


void printGLInfo(void)
{
	//variable declaratios
	GLint numExtensions;
	GLint i;

	//code
	fprintf(gpFILE, "OpenGL Vendor : %s\n", glGetString(GL_VENDOR));
	fprintf(gpFILE, "OpenGL Renderer : %s\n", glGetString(GL_RENDERER));
	fprintf(gpFILE, "OpenGL Version : %s\n", glGetString(GL_VERSION));
	fprintf(gpFILE, "OpenGL GLSL Version : %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	fprintf(gpFILE, "-------------------------------------------\n");
	//listing of supported extensions
	glGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);

	for (i = 0; i < numExtensions; i++)
	{
		fprintf(gpFILE, "%s\n", glGetStringi(GL_EXTENSIONS, i));
	}
	fprintf(gpFILE, "-------------------------------------------\n");

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
	//code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(shaderProgramObject);

	//transformation
	vmath::mat4 modelViewMatrix = vmath::mat4::identity();
	modelViewMatrix = vmath::translate(0.0f, 0.0f, -6.0f);

	vmath::mat4 modelViewProjectionMatrix = vmath::mat4::identity();
	modelViewProjectionMatrix = perspectiveProjectionMatrix * modelViewMatrix; 	//order is very important

	//push above mvp into vertex shaders mvpuniform
	glUniformMatrix4fv(mvpMatrixUniform, 1, GL_FALSE, modelViewProjectionMatrix);

	//for texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture_smiley);
	glUniform1i(textureSamplerUniform, 0);

	glBindVertexArray(vao_cube);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0);

	glUseProgram(0);


	SwapBuffers(ghdc);
}

void update(void)
{
	//code
	
}

void uninitialize(void)
{
	//fucntion declarations
	void  ToggleFullscreen(void);

	//code
	if (shaderProgramObject)
	{
		glUseProgram(shaderProgramObject);

		GLint numShaders = 0;
		glGetProgramiv(shaderProgramObject, GL_ATTACHED_SHADERS, &numShaders);

		if (numShaders > 0)
		{
			GLuint* pShaders = (GLuint*)malloc(numShaders * sizeof(GLuint));
			if (pShaders != NULL)
			{
				glGetAttachedShaders(shaderProgramObject, numShaders, NULL, pShaders);
				for (GLint i = 0; i < numShaders; i++)
				{
					glDetachObjectARB(shaderProgramObject, pShaders[i]);
					glDeleteShader(pShaders[i]);
					pShaders[i] = 0;
				}
				free(pShaders);
				pShaders = NULL;
			}
		}
		glUseProgram(0);
		glDeleteProgram(shaderProgramObject);
		shaderProgramObject = 0;
	}

	//cube
	
	//delete vbo of positoion
	if (vbo_texcoord)
	{
		glDeleteBuffers(1, &vbo_texcoord);
		vbo_texcoord = 0;
	}

	//delete vbo of positoion
	if (vbo_position)
	{
		glDeleteBuffers(1, &vbo_position);
		vbo_position = 0;
	}

	//delete vbo of positoion

	if (vbo_position_cube)
	{
		glDeleteBuffers(1, &vbo_position_cube);
		vbo_position_cube = 0;
	}

	//delete vao
	if (vao_cube)
	{
		glDeleteVertexArrays(1, &vao_cube);
		vao_cube = 0;
	}

	//if application is exiting in fullscreen
	if (gbFullscreen == TRUE)
	{
		ToggleFullscreen();
		gbFullscreen = FALSE;
	}

	//make the hdc as current context
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}

	//Delete rendering context
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	//release the hdc
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}


	//DestroyWindow
	if (ghwnd)
	{
		fclose(stdout);
		FreeConsole();

		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}

	//close the log file
	if (gpFILE)
	{
		fprintf(gpFILE, "Program Ended Successfully...\n");
		fclose(gpFILE);
		gpFILE = NULL;
	}


	if (texture_smiley)
	{
		glDeleteTextures(1, &texture_smiley);
		texture_smiley = 0;
	}

}



