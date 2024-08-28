//(Phong Lighting Model)
//Ambient light = La (light ambient) * Ka (material ambient)
//deffused light = Ld(light difffused) * Kd*(s*n)
//specular light = Ls(light specular) *Ks (material specular) *(r.v) raise to f(material shininess)
//ADS(final)light ADSLight = A+D+sj

// only (r*v) to be find out in vrtex shader

//Common - Windows Header files 

# include <windows.h> // win32 API
# include <stdio.h>   // for file I/O
# include <stdlib.h>  // for for exit() func

# include <gl/glew.h> // this must be before # include<gl/GL.h>
# include<gl/GL.h> // PATH - C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um\gl
# include "OGL.h" //user cha - resorce file for icon MYICON
# include "Sphere.h"

# include "vmath.h"
using namespace vmath;

// link with openl library
#pragma comment(lib,"glew32.lib")
#pragma comment(lib,"OpenGL32.lib")
#pragma comment(lib,"Sphere.lib") //for sphere

// global function declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//OPENGL Header Files
HDC ghdc=NULL;		// DC - Device context
HGLRC ghrc = NULL;  // RC - Rendering Context

//Macros 
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// OpenGl - Global variables
FILE *gpFile = NULL; // handle for file

HWND ghwnd=NULL; //global window handle
BOOL GbActive = FALSE;

DWORD dwStyle = 0; 
WINDOWPLACEMENT wpPrev={sizeof(WINDOWPLACEMENT)}; // previous window size

BOOL gbFullScreen = FALSE; 

//vertex shader
GLuint shaderProgramObject = 0;

//variable for sphere
GLuint vao_sphere=0;
GLuint vbo_sphere_position = 0;
GLuint vbo_sphere_normals = 0;
GLuint vbo_sphere_texcoord = 0;
GLuint vbo_sphere_elements = 0;

GLuint numSphereElements = 0;

mat4 perspectiveProjectionMatrix; // mat4 is in vmath.h
//GLuint mvpMatrixUniform = 0;//
GLuint modelMatrixUniform =0;
GLuint viewMatrixUniform=0;
GLuint projectionMatrixUniform = 0;

GLuint lightAmbientUniform = 0; //new light ambient uniform 
GLuint lightSpeularUniform = 0; //new light source uniform 
GLuint lightDiffusedUniform = 0;
GLuint lightPositionUniform = 0;

GLuint materialAmbientUniform = 0; 
GLuint materialDiffusedUniform = 0; 
GLuint materialSpecularUniform = 0;
GLuint materialShininessUniform = 0;

GLuint keyPressedUniform=0;

BOOL bLightingEnabled = FALSE; 

GLfloat lightAmbient[] = { 0.1f,0.1f,0.1f,1.0f}; //gray clr
GLfloat lightDiffused[] = { 1.0f,1.0f,1.0f,1.0f}; // white clr intensity of light is decided by diffused light
GLfloat lightSpecular[] = {1.0f,1.0f,1.0f,1.0f}; // white clr 
//light kuthun padel (source) he khali declare kele
GLfloat lightPosition[] = { 100.0f,100.0f,100.0f,1.0f}; // w = 1.0f 

/* GLfloat materialAmbient[] = { 0.0f,0.0f,0.0f,1.0f};
GLfloat materialDiffused[] = { 1.0f,1.0f,1.0f,1.0f};
GLfloat materialSpecular[] = { 1.0f,1.0f,1.0f,1.0f};
GLfloat materialShininess = 50.0f;  */

 GLfloat materialAmbient[] = { 0.0f,0.0f,0.0f,0.0f};
GLfloat materialDiffused[] = { 0.5f,0.2f,0.7f,1.0f};
GLfloat materialSpecular[] = { 0.7f,0.7f,0.7f,1.0f};
GLfloat materialShininess = 50.0f;  // purple shpere values

// own data type enum
enum
{
	SUM_ATTRIBUTE_POSITION = 0,
	SUM_ATTRIBUTE_COLOR,
	SUM_ATTRIBUTE_TEXCORD,
	SUM_ATTRIBUTE_NORMAL
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
	TCHAR szAppName[] = TEXT( "SUM Window"); // Text macro
	int iresult=0;

	BOOL bDone = FALSE; //sdk madhla bool small letters

	int screenWidth = GetSystemMetrics(SM_CXSCREEN);  //calculate center x,y co-ordinates to get center
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	int centerX= (screenWidth)/2 - (WIN_WIDTH /2);
	int centerY= (screenHeight)/2 - (WIN_HEIGHT / 2);

	//code
	//gpFile = fopen_s("Log.txt","w"); //secured version of Fopen  - gpfile in write mode 
	if (fopen_s(&gpFile,"Log.txt","w") !=0 )
	{ 
		MessageBox(NULL, TEXT("Log file can not be opend ....."), TEXT("Error.....!"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	else

	{
		fprintf(gpFile,"====================================================================================\n"); 
		fprintf(gpFile,"Program started successfully.....!!\n"); //ANSI  is from string from <stdio.h > header file		
		fprintf(gpFile,"====================================================================================\n"); 
	}
	
	//  initialization  with 12 members
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; 
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance ,MAKEINTRESOURCE(MYICON)); //load myicon
	wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName =  NULL;
	wndclass.hIconSm = LoadIcon(hInstance ,MAKEINTRESOURCE(MYICON));
	
	//Register WNDCLASSEX class here
	RegisterClassEx(&wndclass);

	//Create window 11 parameters

	hwnd = CreateWindowEx(
		WS_EX_APPWINDOW, // Window on the Task Bar
		szAppName,
		TEXT("RADHIKA MOGHE"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		centerX,
		centerY,
		WIN_WIDTH,		// Macro definition
		WIN_HEIGHT,		// Macro definition
		NULL,
		NULL,
		hInstance,
		NULL);
		
	ghwnd=hwnd; // local window handle copy of - global window handle

	//initialization of window
	
	iresult = initialize();

	if (iresult != 0)
	{
		MessageBox(hwnd, TEXT("Window initialize() Failed...!"), TEXT("Error.....!"), MB_OK | MB_ICONERROR);
		DestroyWindow(hwnd);
	}
	
	ShowWindow(hwnd, iCmdShow); //winmain cha 4th parameter ithe 2nd parameter ahe

	SetForegroundWindow(hwnd); // Z-Order madhe window pudhe aan  Z-axis var
	SetFocus(hwnd);//internally this is send to wndproc 
	
	// Game loop 

	while (bDone == FALSE )
	{
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE)) //5th parameter kadhala nahi tar  it will stuck in the message queue
		{
			if(msg.message==WM_QUIT)
			{
				bDone=TRUE; //inital value -false ahe
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
				if (GbActive == TRUE) //GbActiveWindow
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

// ******** GAME LOOP **************//
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
	case WM_SIZE:   // WM_SIZE cha lparam - width and height 
		resize(LOWORD(lParam),HIWORD(lParam));  //0-15 lowword (width), 15-32 hiword (height) 
		break;
	case WM_ERASEBKGND:
		return(0); 
		break;
	case WM_KEYDOWN:
		switch(LOWORD(wParam))
		{
			case VK_ESCAPE: //ASCII-27 
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
			case 'L':
			case 'l':
				if(bLightingEnabled==FALSE)
				{
					bLightingEnabled=TRUE;
				}
				else
				{
					bLightingEnabled=FALSE;
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
	if(gbFullScreen==FALSE) // motha 1
	{
		dwStyle=GetWindowLong(ghwnd,GWL_STYLE); 
		if(dwStyle & WS_OVERLAPPEDWINDOW)  //  A -step
		{
			if(GetWindowPlacement(ghwnd,&wpPrev) && GetMonitorInfo(MonitorFromWindow (ghwnd,MONITORINFOF_PRIMARY ) , &mi) ) //small 'a'
			// --------------  a  --------------/   /------------------------  b  --------------------------------/,/--c--//     
			{
				SetWindowLong(ghwnd,GWL_STYLE,dwStyle & ~WS_OVERLAPPEDWINDOW); // i> completed
				// set 6 paramters
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
	else // motha '2'
	{
		SetWindowPlacement(ghwnd,&wpPrev); //1
		SetWindowLong(ghwnd,GWL_STYLE ,dwStyle | WS_OVERLAPPEDWINDOW); //2
		SetWindowPos(ghwnd,
		HWND_TOP,
		0,
		0,
		0,
		0,
		SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED); //3
		ShowCursor(TRUE);
	}
	
}
int initialize(void)
{
	void printGlInfo(void);
	void uninitialize(void);
	void resize(int ,int);	
	
	// 1- function declarations
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex=0;
	ZeroMemory(&pfd,sizeof(PIXELFORMATDESCRIPTOR)); //one of the way of initialising 

	// initialiszation -  9 members
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

	ghdc = GetDC(ghwnd);
	if(ghdc ==NULL)
	{
		fprintf(gpFile,"GET DC() Failed ...!!\n");
		return(-1);
	}

	// step 2- fetching the closet picture format descriptor (PFD) from operating system

	iPixelFormatIndex = ChoosePixelFormat(ghdc,&pfd); // ghdc compare with pfd here 
	if(iPixelFormatIndex == 0) // if fetches successfully then  it is > 0
	{
		fprintf(gpFile,"ChoosePixelFormat() Failed ...!!\n");
		return(-2);
	}

	//3- set the above obtained pixel format
	if ( (SetPixelFormat(ghdc,iPixelFormatIndex,&pfd) == FALSE) )
	{
		fprintf(gpFile,"SetPixelFormat() Failed ...!!\n");
		return(-3);		
	}

	// 4- Create  OpenGL context from Compatible Device Context using this ghdc 
	ghrc = wglCreateContext(ghdc);
	if (ghrc ==NULL)
	{
		fprintf(gpFile,"wglCreateContext() Failed ...!!\n");
		return(-4);		
	}

	// 5- Make rendering context as current
	if  ( wglMakeCurrent(ghdc,ghrc) == FALSE )
	{
		fprintf(gpFile,"wglMakeCurrent() Failed ...!!\n");
		return(-5);			
	}

	//Initialize glew here
	if(glewInit() != GLEW_OK)
	{
		fprintf(gpFile, "glewInit() failed to initialize -  glew ...\n");
		return (-6);		
	}

	//print glInfo in text file
	printGlInfo(); //call func to get Info

const GLchar * vertexShaderSourceCode = 
				"#version 440 core" \
				"\n" \
				"in vec4 aPosition;\n" \
				"in vec3 aNormal;\n" \
				"uniform mat4 uProjectionMatrix;\n" \
				"uniform mat4 uModelMatrix;\n" \
				"uniform mat4 uViewMatrix;\n" \
				"uniform vec3 uLightAmbient;\n" \
				"uniform vec3 uLightDiffused;\n" \
				"uniform vec3 uLightSpecular;\n" \
				"uniform vec4 uLightPosition;\n" \
				"uniform vec3 uMaterialAmbient;\n" \
				"uniform vec3 uMaterialDiffused;\n" \
				"uniform vec3 uMaterialSpecular;\n" \
				"uniform float uMaterialShininess;\n" \
				"uniform int uKeyPressed;\n" \
				"out vec3 oPhong_ADS_Light;\n" \
				"void main(void)\n" \
				"{\n" \
				"if(uKeyPressed == 1) \n" \
				"{\n" \
				"vec4 eyeCordinates = uViewMatrix * uModelMatrix * aPosition; \n" \
				"vec3 transformedNormals = normalize(mat3 (uViewMatrix * uModelMatrix) * aNormal); \n" \
				"vec3 lightDirection = normalize(vec3(uLightPosition - eyeCordinates)); \n" \
				"vec3 reflectionVector = reflect(-lightDirection,transformedNormals); \n"\
				"vec3 viewerVector = normalize(-eyeCordinates.xyz); \n"\
				"vec3 ambientLight = uLightAmbient * uMaterialAmbient;\n"\
				"vec3 diffussedLight = uLightDiffused * uMaterialDiffused * max(dot(lightDirection,transformedNormals),0.0);\n"\
				"vec3 specularlight = uLightSpecular * uMaterialSpecular * pow(max(dot(reflectionVector,viewerVector),0.0),uMaterialShininess);\n"\
				"oPhong_ADS_Light = ambientLight + diffussedLight + specularlight ;\n"\
				"}\n" \
				"else \n" \
				"{\n" \
				"oPhong_ADS_Light = vec3(0.0f, 0.0f, 0.0f); \n" \
				"}\n" \
				"gl_Position = uProjectionMatrix * uViewMatrix * uModelMatrix * aPosition;\n" \
				"}\n";
	
	// (s*n) = here s is LightDirection
	// eyeCordinates = model kuthe ahe & eye position kuthe ahe
	// normal matrix la fakt roation and scale matrix lagtat
	// upper 9 elements of matrix mhanun vec3 for normal matrix
	// dot product is associative 


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
			//step5 - c) 
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
											"#version 440 core" \
											"\n" \
											"in vec3 oPhong_ADS_Light;\n" \
											"uniform int uKeyPressed;\n" \
											"out vec4 FragColor;\n" \
											"void main(void)\n" \
											"{\n" \
											"if(uKeyPressed == 1) \n" \
											"{\n" \
											"FragColor = vec4(oPhong_ADS_Light, 1.0f);\n" \
											"}\n" \
											"else \n" \
											"{\n" \
											"FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n" \
											"}\n" \
											"}\n";												

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

	// step7 - Shader program

	shaderProgramObject = glCreateProgram();
	//step-8
	glAttachShader(shaderProgramObject,vertexShaderObject);
	glAttachShader(shaderProgramObject,fragmentShaderObject);

	// prelinking code
	glBindAttribLocation(shaderProgramObject,SUM_ATTRIBUTE_POSITION,"aPosition"); //check spelling of apostion
	glBindAttribLocation(shaderProgramObject,SUM_ATTRIBUTE_NORMAL,"aNormal"); //check spelling of normal
	
	//step10
	glLinkProgram(shaderProgramObject);

	//step 11
	status=0;
	infoLogLength=0;
	szInfoLog = NULL;
	//step5 - b) 	
	glGetProgramiv(shaderProgramObject,GL_LINK_STATUS,&status);
	if(status==GL_FALSE)
	{
		glGetProgramiv(shaderProgramObject,GL_INFO_LOG_LENGTH,&infoLogLength);
		if(infoLogLength >0)
		{
			//step5 - c) 
			szInfoLog = (GLchar*) malloc(infoLogLength);		
			if(infoLogLength != NULL)
			{
				//step5 - d) 
				glGetProgramInfoLog(shaderProgramObject,infoLogLength,NULL,szInfoLog);
				//step5 - e) 
				fprintf(gpFile,"Shader Program Linking error -  %s \n",szInfoLog);
				//step5 - f) 
				free(szInfoLog);
				szInfoLog = NULL;
				//step5 - g) 
				uninitialize();
			}
		}
		uninitialize();
	}

	//get Shader Uniform Locations

	//mvpMatrixUniform = glGetUniformLocation(shaderProgramObject,"uMVPMatrix");
/* 	modelViewMatrixUniform = glGetUniformLocation(shaderProgramObject,"uModelViewMatrix");
	projectionMatrixUniform = glGetUniformLocation(shaderProgramObject,"uProjectionMatrix");
	ldUniform = glGetUniformLocation(shaderProgramObject,"uLd");
	kdUniform = glGetUniformLocation(shaderProgramObject, "uKd");
	lightPositionUniform = glGetUniformLocation(shaderProgramObject, "uLightPosition");
	keyPressedUniform = glGetUniformLocation(shaderProgramObject, "uKeyPressed"); */

	modelMatrixUniform	 = glGetUniformLocation(shaderProgramObject,"uModelMatrix");
	viewMatrixUniform	 = glGetUniformLocation(shaderProgramObject,"uViewMatrix");
	projectionMatrixUniform	 = glGetUniformLocation(shaderProgramObject,"uProjectionMatrix");

	lightAmbientUniform = glGetUniformLocation(shaderProgramObject,"uLightAmbient");
	lightDiffusedUniform = glGetUniformLocation(shaderProgramObject,"uLightDiffused");
	lightSpeularUniform = glGetUniformLocation(shaderProgramObject,"uLightSpecular");
	lightPositionUniform = glGetUniformLocation(shaderProgramObject,"uLightPosition");

	materialAmbientUniform = glGetUniformLocation(shaderProgramObject,"uMaterialAmbient");
	materialDiffusedUniform = glGetUniformLocation(shaderProgramObject,"uMaterialDiffused");
	materialSpecularUniform = glGetUniformLocation(shaderProgramObject,"uMaterialSpecular");
	materialShininessUniform = glGetUniformLocation(shaderProgramObject,"uMaterialShininess");

	keyPressedUniform = glGetUniformLocation(shaderProgramObject, "uKeyPressed");

    float sphere_position[1146];
    float sphere_normals[1146];
    float sphere_textures[764];
    unsigned short sphere_elements[2280];	    
		
	getSphereVertexData(sphere_position, sphere_normals, sphere_textures, sphere_elements);

	numSphereElements = getNumberOfSphereElements();


	// ******************** step 13 - VAO  sphere steps  ***********************/

	glGenVertexArrays(1,&vao_sphere); 
	glBindVertexArray(vao_sphere);
	glGenBuffers(1,&vbo_sphere_position);
	glBindBuffer(GL_ARRAY_BUFFER,vbo_sphere_position);
	glBufferData(GL_ARRAY_BUFFER,sizeof(sphere_position) , sphere_position, GL_STATIC_DRAW);
	glVertexAttribPointer(SUM_ATTRIBUTE_POSITION,3,GL_FLOAT,GL_FALSE,0,NULL);
	glEnableVertexAttribArray(SUM_ATTRIBUTE_POSITION);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//VBO for elements			
		
	glGenBuffers(1, &vbo_sphere_normals);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_sphere_normals);
	glBufferData(GL_ARRAY_BUFFER, sizeof(sphere_normals), sphere_normals, GL_STATIC_DRAW);
	glVertexAttribPointer(SUM_ATTRIBUTE_NORMAL, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(SUM_ATTRIBUTE_NORMAL);
	glBindBuffer(GL_ARRAY_BUFFER, 0);	

	// vbo for elements
	
	glGenBuffers(1, &vbo_sphere_elements);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_sphere_elements);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(sphere_elements), sphere_elements, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	 
	// unbind vao
    glBindVertexArray(0);
	
	//enabling depth
	glClearDepth (1.0f); 
	glEnable(GL_DEPTH_TEST); 
	glDepthFunc(GL_LEQUAL); 	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // here OpelGl starts

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
	fprintf(gpFile,"====================================================================================\n"); 
	fprintf(gpFile,"OpenGL Vendor : %s \n",glGetString(GL_VENDOR)); //driver company name
	fprintf(gpFile,"OpenGL Renderer : %s \n",glGetString(GL_RENDERER)); // driver che version
	fprintf(gpFile,"OpenGL Version : %s\n",glGetString(GL_VERSION)); //OpenGL Version
	fprintf(gpFile,"OpenGL Shading Language (GLSL) Version : %s \n",glGetString(GL_SHADING_LANGUAGE_VERSION)); //Shadding language version
	fprintf(gpFile,"====================================================================================\n\n"); 
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

 	// Transformation
	mat4 modelViewMatrix = vmath::mat4::identity();
	mat4 translationMatrix = vmath::mat4::identity();
	//mat4 rotationMatrix = vmath::mat4::identity();
	translationMatrix = vmath::translate(0.0f, 0.0f, -2.0f);
	
	mat4 modelMatrix = translationMatrix ;
	mat4 viewMatrix = vmath::mat4::identity();

	//mat4 modelViewProjectionMatrix = perspectiveProjectionMatrix * modelViewMatrix; // order of multiplication is important
	//mat4  scaleMatrix = vmath::scale(0.75f,0.75f,0.75f);
	
	modelViewMatrix = translationMatrix  ;
	 //modelViewProjectionMatrix = perspectiveProjectionMatrix * modelViewMatrix; // order of multiplication is important
	 // push above mvp into vertex shader's mvpuniform
	glUniformMatrix4fv(modelMatrixUniform, 1, GL_FALSE, modelMatrix);
	glUniformMatrix4fv(viewMatrixUniform, 1, GL_FALSE, viewMatrix);
	glUniformMatrix4fv(projectionMatrixUniform,1,GL_FALSE,perspectiveProjectionMatrix);

	if(bLightingEnabled == TRUE)
	{
		glUniform1i(keyPressedUniform, 1);

		glUniform3fv(lightAmbientUniform,1,lightAmbient);
		glUniform3fv(lightDiffusedUniform,1,lightDiffused);
		glUniform3fv(lightSpeularUniform,1,lightSpecular);
		glUniform4fv(lightPositionUniform,1,lightPosition);

		glUniform3fv(materialAmbientUniform,1,materialAmbient);
		glUniform3fv(materialDiffusedUniform,1,materialDiffused);
		glUniform3fv(materialSpecularUniform,1,materialSpecular);
		glUniform1f(materialShininessUniform,materialShininess);	

		//glUniform3fv(ldUniform, 1, lightDiffused); // light diffused is of 4 elements array but passing only 3 elements as shader has vec3
		//glUniform3fv(kdUniform, 1, materialDiffused); 
		//glUniform4fv(lightPositionUniform, 1, lightPosition);
	}
	else
	{
		glUniform1i(keyPressedUniform, 0);
	}

	glBindVertexArray(vao_sphere);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_sphere_elements);
	
	glDrawElements(GL_TRIANGLES,numSphereElements,GL_UNSIGNED_SHORT,0) ;
	//draw with elements here, 3rd parameter type is the rray type of elements

	//glDrawArrays(GL_TRIANGLE_FAN, 0, 4); // draw with arrays - square  group of 4 vertices

	glBindVertexArray(0);
	glUseProgram(0);
	SwapBuffers(ghdc);
}

void update(void)
{
	//code
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
//*********************sphere

	//delete vbo of position
	if(vbo_sphere_texcoord)
	{
		glDeleteBuffers(1,&vbo_sphere_texcoord);
		vbo_sphere_texcoord=0;
	}
  	if(vbo_sphere_normals)
	{
		glDeleteBuffers(1,&vbo_sphere_normals);
		vbo_sphere_normals=0;
	}
	if(vbo_sphere_position)
	{
		glDeleteBuffers(1,&vbo_sphere_position);
		vbo_sphere_position=0;
	}

	if(vbo_sphere_position)
	{
		glDeleteBuffers(1,&vbo_sphere_position);
		vbo_sphere_position=0;
	}

	//delete vao_sphere
	if(vao_sphere)
	{
		glDeleteVertexArrays(1,&vao_sphere);
		vao_sphere=0;
	}	
/* 	if(vbo_color_sphere)
	{
		glDeleteVertexArrays(1,&vbo_color_sphere);
		vbo_color_sphere=0;
	}  */
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
		fprintf(gpFile,"====================================================================================\n"); 
		fprintf(gpFile,"Program ended successfully...!!\n");
		fprintf(gpFile,"====================================================================================\n"); 
		fclose(gpFile);
		gpFile=NULL;
	}	
}


