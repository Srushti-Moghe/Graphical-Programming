//Common - Windows Header files
# include <windows.h> // win32 API
# include <stdio.h>   // for file I/O
# include <stdlib.h>  // for for exit()

//OPENGL Header Files
HDC ghdc=NULL;		// DC - Device context
HGLRC ghrc = NULL;  // RC - Rendering Context

# include <gl/glew.h> // this must be before # include<gl/GL.h>
# include<gl/GL.h> // PATH - C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um\gl
# include "OGL.h" //USER DEFINED - resorce file for icon

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
//GLfloat	pyramidAngle = 0.0f;
GLfloat cubeAngle = 0.0f;


// OpenGl - Global variables
FILE *gpFile = NULL; 

HWND ghwnd=NULL; 
BOOL GbActive = FALSE;

DWORD dwStyle = 0; 
WINDOWPLACEMENT wpPrev={sizeof(WINDOWPLACEMENT)}; 

BOOL gbFullScreen = FALSE; 
//vertex shader

GLuint shaderProgramObject = 0;

//variable for cube
GLuint vao_cube=0;
GLuint vbo_position_cube = 0;
GLuint vbo_color_cube = 0;

mat4 perspectiveProjectionMatrix; // mat4 is in vmath.h
GLuint mvpMatrixUniform = 0;
 
// own data type enum
enum
{
	SUM_ATTRIBUTE_POSITION = 0,
	SUM_ATTRIBUTE_COLOR
};

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
	TCHAR szAppName[] = TEXT( "SUM Window"); 
	int iresult=0;

	BOOL bDone = FALSE; 

	int screenWidth = GetSystemMetrics(SM_CXSCREEN);  
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	int centerX= (screenWidth)/2 - (WIN_WIDTH /2);
	int centerY= (screenHeight)/2 - (WIN_HEIGHT / 2);

	//code

	if (fopen_s(&gpFile,"Log.txt","w") !=0 )
	{ 
		MessageBox(NULL, TEXT("LOG FILE CAN NOT BE OPENED........"), TEXT("ERROR....."), MB_OK | MB_ICONERROR);
		exit(0);
	}
	else

	{
		fprintf(gpFile,"************************************************************************************\n"); 
		fprintf(gpFile,"Program started successfully.........!!!\n"); 
		fprintf(gpFile,"************************************************************************************\n"); 
	}
	
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
		WS_EX_APPWINDOW, // Window above Task Bar
		szAppName,
		TEXT("Srushti Umesh Moghe"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		centerX,
		centerY,
		WIN_WIDTH,		// Macro
		WIN_HEIGHT,		// Macro
		NULL,
		NULL,
		hInstance,
		NULL);
		
	//show the window  

	ghwnd=hwnd; // local window handle to global window handle

	//initialization of window
	
	iresult = initialize();

	if (iresult != 0)
	{
		MessageBox(hwnd, TEXT("Window initialize() Failed........"), TEXT("ERROR....."), MB_OK | MB_ICONERROR);
		DestroyWindow(hwnd);
	}
	
	ShowWindow(hwnd, iCmdShow); 

	SetForegroundWindow(hwnd); 
	SetFocus(hwnd);

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
					//render
					display();

					// update
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

// GAME LOOP 
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
				if(gbFullScreen==FALSE)
				{
					ToggleFullscreen();
					gbFullScreen=TRUE;
				}
				else
				{
					ToggleFullscreen();
					gbFullScreen=FALSE;
				}
			break;		
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd); 
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default :
		break;
	}
	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void ToggleFullscreen(void)
{
	//local variable declarations
	MONITORINFO  mi ={sizeof(MONITORINFO)};

	//code
	if(gbFullScreen==FALSE) 
	{
		dwStyle=GetWindowLong(ghwnd,GWL_STYLE); 
		if(dwStyle & WS_OVERLAPPEDWINDOW)  
		{
			if(GetWindowPlacement(ghwnd,&wpPrev) && GetMonitorInfo(MonitorFromWindow (ghwnd,MONITORINFOF_PRIMARY ) , &mi) ) 
			{
				SetWindowLong(ghwnd,GWL_STYLE,dwStyle & ~WS_OVERLAPPEDWINDOW); 
				
 				SetWindowPos(ghwnd,
				HWND_TOP, 
				mi.rcMonitor.left, 
				mi.rcMonitor.top,
				mi.rcMonitor.right - mi.rcMonitor.left, 
				mi.rcMonitor.bottom - mi.rcMonitor.top, 
				SWP_NOZORDER | SWP_FRAMECHANGED );  
			}
		}
		ShowCursor(FALSE);
	}
	else 
	{
		SetWindowPlacement(ghwnd,&wpPrev); 
		SetWindowLong(ghwnd,GWL_STYLE ,dwStyle | WS_OVERLAPPEDWINDOW); 
		SetWindowPos(ghwnd,
		HWND_TOP,
		0,
		0,
		0,
		0,
		SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED); 
		ShowCursor(TRUE);
	}
	
}
int initialize(void)
{
	void printGlInfo(void);
	void uninitialize(void);

	void resize(int ,int);	
	
	// function declarations
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex=0;
	ZeroMemory(&pfd,sizeof(PIXELFORMATDESCRIPTOR)); 

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
	pfd.cDepthBits = 32; 
	// get the DC  - Device context

	ghdc = GetDC(ghwnd);
	if(ghdc ==NULL)
	{
		fprintf(gpFile,"GET DC() FAILED .....!!!\n");
		return(-1);
	}

	// fetching the closet picture format descriptor from O/s

	iPixelFormatIndex = ChoosePixelFormat(ghdc,&pfd); // take ghdc compare with pfd 
	if(iPixelFormatIndex == 0) // if fetches successfully it is >0
	{
		fprintf(gpFile,"ChoosePixelFormat() FAILED .....!!!\n");
		return(-2);
	}

	// set the above obtained pixel format
	if ( (SetPixelFormat(ghdc,iPixelFormatIndex,&pfd) == FALSE) )
	{
		fprintf(gpFile,"SetPixelFormat() FAILED .....!!!\n");
		return(-3);		
	}

	// create  OpenGL context from Compatible DC using this ghdc 
	ghrc = wglCreateContext(ghdc);
	if (ghrc ==NULL)
	{
		fprintf(gpFile,"wglCreateContext() FAILED .....!!!\n");
		return(-4);		
	}

	// ghdc will give control to do further drawing - Make rendering context current
	if  ( wglMakeCurrent(ghdc,ghrc) == FALSE )
	{
		fprintf(gpFile,"wglMakeCurrent() FAILED .....!!!\n");
		return(-5);			
	}

	// Initialize GLEW 
	if(glewInit() != GLEW_OK)
	{
		fprintf(gpFile, "glew-Init() failed to initialize() GLEW...\n");
		return (-6);		
	}

	//print GLINFO
	printGlInfo(); 

	// Vertex shader
	const GLchar * vertexShaderSourceCode = 
											"#version 440 core\n" \
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

	// create vertex shader object
	GLuint vertexShaderObject = glCreateShader(GL_VERTEX_SHADER);

	// send vertexShaderSourceCode to OpenGL
	glShaderSource(vertexShaderObject,1,(const GLchar **)&vertexShaderSourceCode,NULL);

	// compile vertexShader by openGL
	glCompileShader(vertexShaderObject);

	// check vertex Shader compilation information and handle it
	 
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
				 
				fprintf(gpFile,"vertex Shader compilation error log %s \n",szInfoLog);
				
				free(szInfoLog);
				szInfoLog = NULL;
								
			}
		}
		uninitialize();
	}


	// Fragment shader

	const GLchar *fragementShaderSourceCode = 
											"#version 440 core \n" \
											"\n" \
											"in vec4 oColor; \n" \
											"out vec4 fragColor; \n" \
											"void main(void) \n" \
											"{ \n" \
											"fragColor = oColor; \n" \
											"} \n" ;

	// create fragment Shader object
	GLuint fragmentShaderObject = glCreateShader(GL_FRAGMENT_SHADER);

	// send fragment ShaderSourceCode to OpenGL
	glShaderSource(fragmentShaderObject,1,(const GLchar **)&fragementShaderSourceCode,NULL);

	// compile fragment Shader by openGL
	glCompileShader(fragmentShaderObject);

	// check fragment Shader compilation information and handle it
	 
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
				 
				fprintf(gpFile,"Fragment Shader compilation error log %s \n",szInfoLog);
				
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
	
	// binding points in between output and input steps -cpu to gpu
	// Prelinking
	glBindAttribLocation(shaderProgramObject,SUM_ATTRIBUTE_POSITION,"aPosition"); 
	glBindAttribLocation(shaderProgramObject,SUM_ATTRIBUTE_COLOR,"aColor"); 
	
	
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
				
				fprintf(gpFile,"Shader Program Linking error log %s \n",szInfoLog);
				 
				free(szInfoLog);
				szInfoLog = NULL;
				
				uninitialize();
			}
		}
		uninitialize();
	}

	//get Shader Uniform Locations
	mvpMatrixUniform = glGetUniformLocation(shaderProgramObject,"uMVPMatrix");
	
	
/* 	const GLfloat pyramid_position[] = 
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

									}; */
 	const GLfloat cube_position[] = 
								{
								// front
								1.0f,  1.0f,  1.0f, // top-right of front
								-1.0f,  1.0f,  1.0f, // top-left of front
								-1.0f, -1.0f,  1.0f, // bottom-left of front
								1.0f, -1.0f,  1.0f, // bottom-right of front

								// right
								1.0f,  1.0f, -1.0f, // top-right of right
								1.0f,  1.0f,  1.0f, // top-left of right
								1.0f, -1.0f,  1.0f, // bottom-left of right
								1.0f, -1.0f, -1.0f, // bottom-right of right

								// back
								1.0f,  1.0f, -1.0f, // top-right of back
								-1.0f,  1.0f, -1.0f, // top-left of back
								-1.0f, -1.0f, -1.0f, // bottom-left of back
								1.0f, -1.0f, -1.0f, // bottom-right of back

								// left
								-1.0f,  1.0f,  1.0f, // top-right of left
								-1.0f,  1.0f, -1.0f, // top-left of left
								-1.0f, -1.0f, -1.0f, // bottom-left of left
								-1.0f, -1.0f,  1.0f, // bottom-right of left

								// top
								1.0f,  1.0f, -1.0f, // top-right of top
								-1.0f,  1.0f, -1.0f, // top-left of top
								-1.0f,  1.0f,  1.0f, // bottom-left of top
								1.0f,  1.0f,  1.0f, // bottom-right of top

								// bottom
								1.0f, -1.0f,  1.0f, // top-right of bottom
								-1.0f, -1.0f,  1.0f, // top-left of bottom
								-1.0f, -1.0f, -1.0f, // bottom-left of bottom
								1.0f, -1.0f, -1.0f, // bottom-right of bottom
								};
	const GLfloat cube_color[] = {
								// front
								1.0f, 0.0f, 0.0f, // top-right of front
								1.0f, 0.0f, 0.0f, // top-left of front
								1.0f, 0.0f, 0.0f, // bottom-left of front
								1.0f, 0.0f, 0.0f, // bottom-right of front

								// right
								0.0f, 0.0f, 1.0f, // top-right of right
								0.0f, 0.0f, 1.0f, // top-left of right
								0.0f, 0.0f, 1.0f, // bottom-left of right
								0.0f, 0.0f, 1.0f, // bottom-right of right

								// back
								1.0f, 1.0f, 0.0f, // top-right of back
								1.0f, 1.0f, 0.0f, // top-left of back
								1.0f, 1.0f, 0.0f, // bottom-left of back
								1.0f, 1.0f, 0.0f, // bottom-right of back

								// left
								1.0f, 0.0f, 1.0f, // top-right of left
								1.0f, 0.0f, 1.0f, // top-left of left
								1.0f, 0.0f, 1.0f, // bottom-left of left
								1.0f, 0.0f, 1.0f, // bottom-right of left

								// top
								0.0f, 1.0f, 0.0f, // top-right of top
								0.0f, 1.0f, 0.0f, // top-left of top
								0.0f, 1.0f, 0.0f, // bottom-left of top
								0.0f, 1.0f, 0.0f, // bottom-right of top

								// bottom
								1.0f, 0.5f, 0.0f, // top-right of bottom
								1.0f, 0.5f, 0.0f, // top-left of bottom
								1.0f, 0.5f, 0.0f, // bottom-left of bottom
								1.0f, 0.5f, 0.0f, // bottom-right of bottom
							}; 

	// ******************** step 13 - VAO  pyramid steps ********************//

/* 	glGenVertexArrays(1,&vao_pyramid); 
	
	glBindVertexArray(vao_pyramid);

	// VBO for Position
	glGenBuffers(1,&vbo_position_pyramid);
	
	glBindBuffer(GL_ARRAY_BUFFER,vbo_position_pyramid);
	glBufferData(GL_ARRAY_BUFFER,sizeof(pyramid_position) , pyramid_position, GL_STATIC_DRAW);
	glVertexAttribPointer(SUM_ATTRIBUTE_POSITION,3,GL_FLOAT,GL_FALSE,0,NULL);
	glEnableVertexAttribArray(SUM_ATTRIBUTE_POSITION);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1,&vbo_color_pyramid);
	glBindBuffer(GL_ARRAY_BUFFER,vbo_color_pyramid);
	glBufferData(GL_ARRAY_BUFFER,sizeof(pyramid_color) , pyramid_color, GL_STATIC_DRAW);
	glVertexAttribPointer(SUM_ATTRIBUTE_COLOR,3,GL_FLOAT,GL_FALSE,0,NULL);
	glEnableVertexAttribArray(SUM_ATTRIBUTE_COLOR);	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	glBindVertexArray(0); */

	// ******************** VAO  cube steps  ***********************/

	glGenVertexArrays(1,&vao_cube); 
	
	glBindVertexArray(vao_cube);

	// VBO for Position
	glGenBuffers(1,&vbo_position_cube);
	
	glBindBuffer(GL_ARRAY_BUFFER,vbo_position_cube);
	glBufferData(GL_ARRAY_BUFFER,sizeof(cube_position) , cube_position, GL_STATIC_DRAW);
	glVertexAttribPointer(SUM_ATTRIBUTE_POSITION,3,GL_FLOAT,GL_FALSE,0,NULL);
	glEnableVertexAttribArray(SUM_ATTRIBUTE_POSITION);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1,&vbo_color_cube);
	glBindBuffer(GL_ARRAY_BUFFER,vbo_color_cube);
	glBufferData(GL_ARRAY_BUFFER,sizeof(cube_color) , cube_color, GL_STATIC_DRAW);
	glVertexAttribPointer(SUM_ATTRIBUTE_COLOR,3,GL_FLOAT,GL_FALSE,0,NULL);
	glEnableVertexAttribArray(SUM_ATTRIBUTE_COLOR);	
	glBindBuffer(GL_ARRAY_BUFFER, 0); 

	//vbo for color

	//glVertexAttrib3f(SUM_ATTRIBUTE_COLOR,0.0f,0.0f,1.0f);
	glBindVertexArray(0);	

	//enabling depth
	glClearDepth (1.0f); //2-compulsory  depth buffer clear karayla 1.0f vapraychi
	glEnable(GL_DEPTH_TEST); // 3rd compulsory
	glDepthFunc(GL_LEQUAL); //4 compulsory
	
	// set the clear color of window to BLUE
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // here OpelGL starts

	// initialise perspectiveProjectionMatrix
	perspectiveProjectionMatrix = vmath::mat4::identity();

	resize(WIN_WIDTH,WIN_HEIGHT);

	return(0);

}

void printGlInfo(void)
{
	//variable declarations
	GLint numExtensions;
	GLint i;
	//code
	fprintf(gpFile,"**************************************************************************************\n"); 
	fprintf(gpFile,"OpenGL Vendor : %s \n",glGetString(GL_VENDOR)); //driver company name
	fprintf(gpFile,"OpenGL Renderer : %s \n",glGetString(GL_RENDERER)); // driver che version
	fprintf(gpFile,"OpenGL Version : %s\n",glGetString(GL_VERSION)); //OpenGL Version
	fprintf(gpFile,"OpenGL Shading Language (GLSL) Version : %s \n",glGetString(GL_SHADING_LANGUAGE_VERSION)); //Shadding language version
	fprintf(gpFile,"**************************************************************************************\n\n"); 
	//list of supported extenions
	glGetIntegerv(GL_NUM_EXTENSIONS,&numExtensions);
	for (i=0;i<numExtensions;i++)
	{
		fprintf(gpFile," %d : %s \n",i,glGetStringi(GL_EXTENSIONS,i));		
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

	//pyramid
 	// Transformation
	mat4 modelViewMatrix = vmath::mat4::identity();
	mat4 translationMatrix = vmath::mat4::identity();
	mat4 rotationMatrix = vmath::mat4::identity();
	translationMatrix = vmath::translate(0.0f, 0.0f, -6.0f);
	
	//	rotationMatrix = vmath::rotate(pyramidAngle, 0.0f, 1.0f, 0.0f);
	modelViewMatrix = translationMatrix * rotationMatrix;
	mat4 modelViewProjectionMatrix = perspectiveProjectionMatrix * modelViewMatrix; // order of multiplication is important
	// push above mvp into vertex shader's mvpuniform
	//glUniformMatrix4fv(mvpMatrixUniform, 1, GL_FALSE, modelViewProjectionMatrix);

	//glBindVertexArray(vao_pyramid);
	//glDrawArrays(GL_TRIANGLES, 0, 12); //pyramid 3*4 sides
	//glBindVertexArray(0); */

	//cube

	// Transformation
/* 	modelViewMatrix = vmath::mat4::identity();
	translationMatrix = vmath::mat4::identity();
	rotationMatrix = vmath::mat4::identity();
	mat4 scaleMatrix = vmath::mat4::identity(); 
*/

	mat4  scaleMatrix = vmath::scale(0.75f,0.75f,0.75f);
	translationMatrix = vmath::translate(0.0f, 0.0f, -6.0f);
	 mat4 rotationMatrix1 = vmath::rotate(cubeAngle, 1.0f, 0.0f, 0.0f);
	 mat4 rotationMatrix2 = vmath::rotate(cubeAngle, 0.0f, 1.0f, 0.0f);
	 mat4 rotationMatrix3 = vmath::rotate(cubeAngle, 0.0f, 0.0f, 1.0f); 

	 modelViewMatrix = translationMatrix * scaleMatrix  * rotationMatrix1 * rotationMatrix2 * rotationMatrix3  ;

	 modelViewProjectionMatrix = perspectiveProjectionMatrix * modelViewMatrix; // order of multiplication is important

	 // push above mvp into vertex shader's mvpuniform
	glUniformMatrix4fv(mvpMatrixUniform, 1, GL_FALSE, modelViewProjectionMatrix);
	glBindVertexArray(vao_cube);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4); // square  group of 4 vertices
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
 	cubeAngle =cubeAngle - 0.05f;		// pyramidAngle in "degrees"
	if (cubeAngle <= 0.0f)
	{
		cubeAngle =cubeAngle + 360.0f;
		//cubeAngle = 0.0f; Also Works
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
 	if(vbo_position_cube)
	{
		glDeleteBuffers(1,&vbo_position_cube);
		vbo_position_cube=0;
	}
	//delete vao_cube
	if(vao_cube)
	{
		glDeleteVertexArrays(1,&vao_cube);
		vao_cube=0;
	}	
	if(vbo_color_cube)
	{
		glDeleteVertexArrays(1,&vbo_color_cube);
		vbo_color_cube=0;
	} 
/*	
//*********************pyramid
	//delete vbo of color
	if(vbo_color_pyramid)
	{
		glDeleteBuffers(1,&vbo_color_pyramid);
		vbo_color_pyramid=0;
	}
	//delete vbo of position
	if(vbo_position_pyramid)
	{
		glDeleteBuffers(1,&vbo_position_pyramid);
		vbo_position_pyramid=0;
	}
	//delete vao_pyramid
	if(vao_pyramid)
	{
		glDeleteVertexArrays(1,&vao_pyramid);
		vao_pyramid=0;
	}*/
	
	//application is exitting in full screen
	if(gbFullScreen == TRUE) //on ESCAPE Key- pressed event
	{
		ToggleFullscreen();
		gbFullScreen = FALSE;
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
		fprintf(gpFile,"************************************************************************************\n"); 
		fprintf(gpFile,"Program ended successfully.....!!!\n");
		fprintf(gpFile,"************************************************************************************\n"); 
		fclose(gpFile);
		gpFile=NULL;
	}	
}

