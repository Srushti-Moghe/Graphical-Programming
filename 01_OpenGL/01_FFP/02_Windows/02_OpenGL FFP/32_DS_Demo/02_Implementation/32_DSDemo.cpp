  
//Common - Windows Header files
# include <windows.h> // win32 APIplay
# include <stdio.h>   // for file I/O
# include <stdlib.h>  // for for exit()
# include <mmsystem.h>

//OPENGL Header Files
HDC ghdc=NULL;		// DC - Device context
HGLRC ghrc = NULL;  // RC - Rendering Context

# include<gl/GL.h>
# include <GL/glu.h>
# include "OGL.h" //USER DEFINED - resorce file for icon
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


#pragma comment(lib,"OpenGL32.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib, "winmm.lib") // for playsound

// global function declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Macros 
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

//global variable declaration
// OpenGl - Global variables

FILE *gpFile = NULL; // file handle pointer for gpFile

HWND ghwnd=NULL; //global window handle
BOOL GbActive = FALSE;

DWORD dwStyle = 0; // global window style (32Dword - 16+16 /8+8+8+8 Dword/loword/highword)
WINDOWPLACEMENT wpPrev={sizeof(WINDOWPLACEMENT)}; // golbal initialization of window structure

BOOL gbFullScreen = FALSE; // Toggle Boolean (TRUE/FALSE) -  variable for window full screen

BOOL cube1 = TRUE;
BOOL cube2 = FALSE;

GLfloat cubeangle = 0.0f;

//texture object variables
GLuint texture_title =0;
GLuint texture_credits =0;

// Lerp()
GLfloat lerp(GLfloat start, GLfloat end, GLfloat t)
{
	return (start + (end - start) * t);
}

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
	TCHAR szAppName[] = TEXT( "Srushti Umesh Moghe"); // Text macro
	int iresult=0;

	BOOL bDone = FALSE; //sdk cha bool (not capital)

	int screenWidth = GetSystemMetrics(SM_CXSCREEN);  //calculate center x,y co-ordinates
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	int centerX= (screenWidth)/2 - (WIN_WIDTH /2);
	int centerY= (screenHeight)/2 - (WIN_HEIGHT / 2);

	//code
	gpFile = fopen("Log.txt","w"); //open gpfile in write mode 
	//MessageBox(NULL, TEXT("initialize OPENED........"), TEXT("ERROR....."), MB_OK | MB_ICONERROR);
	if (gpFile == NULL)
	{
		MessageBox(NULL, TEXT("LOG FILE CAN NOT BE OPENED........"), TEXT("ERROR....."), MB_OK | MB_ICONERROR);
		exit(0);
	}
	fprintf(gpFile," Program started successfully......!!!\n"); //ANSI string from stdio.h not from sys32lib
	
	// WNDCLASSEX initialization - Struct def with 12 members
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; // CS_OWNDC - maza device context-Class chya ownership(user chya) madhe rahil
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance ,MAKEINTRESOURCE(MYICON) ); //load myicon
	wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName =  NULL;
	wndclass.hIconSm = LoadIcon(hInstance ,MAKEINTRESOURCE(MYICON));
	
	//Register WNDCLASSEX
	RegisterClassEx(&wndclass); 

	//Create window 11 parameters

	hwnd = CreateWindowExA(
		WS_EX_APPWINDOW,
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

	ghwnd = hwnd; // local window handle to global window handle

	//initialization of window
	
	iresult = initialize();

	if (iresult != 0)
	{
		//fprintf(gpFile," iresult  %d",iresult);
		MessageBox(hwnd, TEXT(" Window initialize() Failed........"), TEXT("ERROR....."), MB_OK | MB_ICONERROR);
		DestroyWindow(hwnd);
	}
	
	ShowWindow(hwnd, iCmdShow); 

	SetForegroundWindow(hwnd); // ZORDER - madhe hi window pudhe aan 
	SetFocus(hwnd);//internally this is send to wndproc la pathavto
	
	// Game loop 

	while (bDone == FALSE )
	{
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE)) //5th param- remove nahi kela msg tar it will stuck in the msg-queue
		{
			if(msg.message==WM_QUIT)
			{
				bDone=TRUE; //exits the loop (inital value is FALSE!)
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

//cllaback fucntion definition 
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//function declaraion
	void ToggleFullscreen(void);
	void resize(int , int);

	//code
	switch(iMsg)
	{
	case WM_CREATE:
		PlaySound(MAKEINTRESOURCE(MYSOUND), NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);
		break;
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
				mi.rcMonitor.right - mi.rcMonitor.left, //width
				mi.rcMonitor.bottom - mi.rcMonitor.top, // height
				SWP_NOZORDER | SWP_FRAMECHANGED ); 
			}
		}
		ShowCursor(FALSE);
	}
	else 
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
	void resize(int ,int );
	BOOL loadGlTexture (GLuint*, TCHAR[]);
	GLuint createTexture2D(const char* filePath);
	
	// function declarations
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex=0;
	ZeroMemory(&pfd,sizeof(PIXELFORMATDESCRIPTOR)); //one of the way of initialising 
	BOOL bResult ;

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

	ghdc = GetDC(ghwnd);
	if(ghdc ==NULL)
	{
		fprintf(gpFile,"GET DC() FAILED .....!!!\n");
		return(-1);
	}

	iPixelFormatIndex = ChoosePixelFormat(ghdc,&pfd); // take ghdc compare with pfd 
	if(iPixelFormatIndex == 0) // if fetches successfully it is >0
	{
		fprintf(gpFile,"ChoosePixelFormat() FAILED .....!!!\n");
		return(-2);
	}

	if ( (SetPixelFormat(ghdc,iPixelFormatIndex,&pfd) == FALSE) )
	{
		fprintf(gpFile,"SetPixelFormat() FAILED .....!!!\n");
		return(-3);		
	}

	ghrc = wglCreateContext(ghdc);
	if (ghrc ==NULL)
	{
		fprintf(gpFile,"wglCreateContext() FAILED .....!!!\n");
		return(-4);		
	}

	if  ( wglMakeCurrent(ghdc,ghrc) == FALSE )
	{
		fprintf(gpFile,"wglMakeCurrent() FAILED .....!!!\n");
		return(-5);			
	}

	//enabling depth
	glShadeModel (GL_SMOOTH); // lighting  and cloring shades smooth krayla //beautification
	glClearDepth (1.0f); //2-compulsory  depth buffer clear karayla 1.0f vapyaychi
	glEnable(GL_DEPTH_TEST); // 3rd compulsory
	glDepthFunc(GL_LEQUAL); //4 compulsory
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);		// Step 2.5 (Optional beautification)

	// set the clear color of window to BLUE
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // here OpelGl starts

	//loading images to create texture

texture_title = createTexture2D("title.jpg");

texture_credits = createTexture2D("credits.jpg");

	glEnable(GL_TEXTURE_2D); 
	
	resize(WIN_WIDTH,WIN_HEIGHT);
	
	return(0);

}

BOOL loadGlTexture(GLuint *texture,TCHAR imageResourceId[])
{
//local variable declarations
HBITMAP hBitMap = NULL;
BITMAP bmp;

hBitMap = (HBITMAP)LoadImage(GetModuleHandle(NULL) , imageResourceId, IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION);
//GetObject(hBitMap);
if(hBitMap == NULL)
{
	fprintf(gpFile,"Loading image FAILED .....!!!\n");
	return(FALSE);
}

GetObject(hBitMap, sizeof(BITMAP), &bmp);

glGenTextures(1, texture);

glBindTexture(GL_TEXTURE_2D,*texture); //binding point slit

glPixelStorei(GL_UNPACK_ALIGNMENT, 4); 
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

//gluBuild2DMipmaps(GL_TEXTURE_2D,3, bmp.bmWidth, bmp.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, (void*)bmp.bmBits);
gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bmp.bmWidth, bmp.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, (void*)bmp.bmBits);

glBindTexture(GL_TEXTURE_2D, 0);

DeleteObject(hBitMap);

hBitMap = NULL;

return TRUE;

}

GLuint createTexture2D(const char* filePath)
{
	stbi_set_flip_vertically_on_load(true);
	int width, height, channel;
	unsigned char* data = stbi_load(filePath, &width, &height, &channel, 0);

	if (!data)
	{
		fprintf(gpFile, "Failed To Load %s Texture\n", filePath);
		return -1;
	}

	GLenum format = GL_RGBA;

	if (channel == STBI_grey)
		format = GL_RED;
	else if (channel == STBI_rgb)
		format = GL_RGB;
	else if (channel == STBI_rgb_alpha)
		format = GL_RGBA;

	GLuint texture;
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(data);
	return texture;
}



void resize(int width ,int height)
{
	//code
	if (height <= 0)
		height = 1; // precaution for division	
	
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	glViewport(0, 0, (GLsizei)width, (GLsizei)height ); //zoomed binacular view (limited)
	gluPerspective (45.0f,( (GLfloat)width / (GLfloat)height ), 0.1f, 100.0f);	
}

void display()
{
	void drawcube(int picno1, int picno2, int picno3, int picno4,  GLfloat  transX, GLfloat transY, GLfloat transZ , GLfloat scaleX, GLfloat scaleY,  GLfloat scaleZ);	

	void title(void);
	void scene(void);
	void credits(void);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 
	glTranslatef(0.0f,0.0f,0.0f); 	

	if (cube1)
	{
		glPushMatrix();
		drawcube(texture_title, texture_title, texture_title, texture_title, 0.0f,0.2f, 0.0f,  1.0f,1.0f,1.0f);
		glPopMatrix();  
	}
	
	scene();

	if (cube2 )
	{  
		glPushMatrix();
		drawcube(texture_credits, texture_credits, texture_credits, texture_credits, 0.0f,0.2f, 0.0f,  1.0f,1.0f,1.0f);
		glPopMatrix();  	
 	}

	glBindTexture(GL_TEXTURE_2D, 0);
	SwapBuffers(ghdc);

}

void update(void)
{
 // Code
			
		
}

void drawcube(int picno1, int picno2, int picno3, int picno4,  GLfloat  transX, GLfloat transY, GLfloat transZ , GLfloat scaleX, GLfloat scaleY,  GLfloat scaleZ)
{
	
	glTranslatef(transX, transY,  transZ);
	glScalef(scaleX,scaleY,scaleZ);
	glRotatef (cubeangle,0.0f,1.0f,0.0f); // Y-axis roration	
		
	glBindTexture(GL_TEXTURE_2D, picno1);	
	glBegin(GL_QUADS);	
	// FRONT FACE - R	

	glTexCoord2f( 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);		// RT
	glTexCoord2f( 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);		// LT
	glTexCoord2f( 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);		// LB
	glTexCoord2f( 0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);		// RB
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	// RIGHT FACE - G	

	glBindTexture(GL_TEXTURE_2D, picno2);
	glBegin(GL_QUADS);
	
	glTexCoord2f( 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);		// RT
	glTexCoord2f( 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);		// LT
	glTexCoord2f( 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);		// LB
	glTexCoord2f( 0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);		// RB
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	
	glBindTexture(GL_TEXTURE_2D, picno3);
	glBegin(GL_QUADS);

	// BACK FACE - B
	glTexCoord2f( 0.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);		// RT
	glTexCoord2f(  1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);		// LT
	glTexCoord2f( 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);		// LB
	glTexCoord2f(  0.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);	// RB
	glEnd();	
	glBindTexture(GL_TEXTURE_2D, 0);
	
	// LEFT FACE - C

	glBindTexture(GL_TEXTURE_2D, picno4);

	glBegin(GL_QUADS);
	glTexCoord2f( 0.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);		// RT
	glTexCoord2f( 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);		// LT
	glTexCoord2f( 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);	// LB
	glTexCoord2f( 0.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);		// RB
	glEnd();	
	glBindTexture(GL_TEXTURE_2D, 0);
	
	// TOP FACE - M
	
	glBegin(GL_QUADS);
	glTexCoord2f( 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);		// RT
	glTexCoord2f( 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);		// LT
	glTexCoord2f( 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);		// LB
	glTexCoord2f( 0.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);		// RB

	// BOTTOM FACE - Y	
	
	glTexCoord2f( 0.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);		// RT
	glTexCoord2f( 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);	// LT
	glTexCoord2f( 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);		// LB
	glTexCoord2f( 0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);		// RB

	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	}

void uninitialize(void)
{
	//function declarations
	
	void ToggleFullscreen(void);
	
	//code
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

	if (texture_credits)
	{
		glDeleteTextures(1,&texture_credits);
		texture_credits = 0;
	}
	
	if (texture_title)
	{
		glDeleteTextures(1,&texture_title);
		texture_title = 0;
	}

	//close the log file
	if(gpFile)
	{
		fprintf(gpFile,"Program ended successfully.....!!!");
		fclose(gpFile);
		gpFile=NULL;
	}	

}


// Background Lines
void BackgroundLines(void)
{
	static int flag = 0;
	static float move = 0;
	// glLineWidth(0.5f);
	glColor4f(0.047f, 0.271f, 0.008, 0.5f);

	// Lines
	// glTranslatef(0.0f, 0.0f, -3.0f);

	int i, j, n = 35;
	float lineHeight_1 = 0.01f;
	// float lineHeight_2 = 0.6f;

	GLfloat t = 0.0f;
	for (j = 0; j < n; j++)
	{

		t = rand() % RAND_MAX * move / 100000.0f;
		glPushMatrix();
		glTranslatef(0.0f, -t, 0.0f);
		for (i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				lineHeight_1 = 0.01f;
			}
			else
			{
				lineHeight_1 = 0.05f;
			}
			// srand(time(0));
			glBegin(GL_LINES);

			// glColor4f(0.173f, 0.91f, 0.039f, 0.5f);
			glVertex3f(lerp(2.00f, -2.00f, (GLfloat)j / (GLfloat)n), lerp(1.0f, -1.0f, (GLfloat)i / (GLfloat)n), 0.0f);

			// glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
			glVertex3f(lerp(2.00f, -2.00f, (GLfloat)j / (GLfloat)n), lerp(1.0f, -1.0f, (GLfloat)i / (GLfloat)n) - lineHeight_1, 0.0f);

			glEnd();
		}
		glPopMatrix();
	}

	move += 0.0008f;
}


// scene
void scene(void)
{

}








