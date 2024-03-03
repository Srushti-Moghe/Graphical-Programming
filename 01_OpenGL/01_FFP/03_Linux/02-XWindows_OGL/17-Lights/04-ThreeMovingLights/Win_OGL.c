// Standard Header Files
#include <stdio.h>  // for printf
#include <stdlib.h> // for e.g exit() function
#include <memory.h> // for memset (zeromemory in windows)

// x11 header files
#include <X11/Xlib.h>  // For All xWindow API
#include <X11/Xutil.h> // For XVisualInfo and rrelated API
#include <X11/XKBlib.h>

// OpenGL Header Files
#include <GL/gl.h>
#include <GL/glx.h>

#include <GL/gl.h>
#include <GL/glu.h>

// Global Variable Declarations
Display *display = NULL;
Colormap colormap;
Window window;

XVisualInfo *xVisualInfo = NULL;

// Opengl Global Variables
GLXContext glxContext = NULL;
Bool bFullscreen = False;
Bool bActiveWindow = False;

FILE *gpFile =NULL;

// Macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

GLfloat cAngle = 0.0f;	// For Rotating Pyramid

// Light Variables

// GOROUD SHADING

Bool gbLight = False;

GLUquadric* quadric = NULL;

GLfloat lightAmbientZero[] = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat lightDiffuseZero[] = {1.0f, 0.0f, 0.0f, 1.0f};
GLfloat lightSpecularZero[] = {1.0f, 0.0f, 0.0f, 1.0f};
GLfloat lightPositionZero[4];

GLfloat lightAmbientOne[] = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat lightDiffuseOne[] = {0.0f, 1.0f, 0.0f, 1.0f};
GLfloat lightSpecularOne[] = {0.0f, 1.0f, 0.0f, 1.0f};
GLfloat lightPositionOne[4];

GLfloat lightAmbientTwo[] = {0.0f, 0.0f, 1.0f, 1.0f};
GLfloat lightDiffuseTwo[] = {0.0f, 0.0f, 1.0f, 1.0f};
GLfloat lightSpecularTwo[] = {0.0f, 0.0f, 1.0f, 1.0f};
GLfloat lightPositionTwo[4];

GLfloat materialAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat materialDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat materialSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat materialShininess = 128.0f;

GLfloat lightAngleZero = 0.0f;
GLfloat lightAngleOne = 0.0f;
GLfloat lightAngleTwo = 0.0f;

int main(void)
{
    // Local function Declarations
    void toggleFullscreen(void);
    int initialize(void);
    void resize(int, int);
    void draw(void);
    void update(void);
    void uninitialize(void);

    // Local Variable declarations
    int defaultScreen;
    XSetWindowAttributes windowAttributes;
    int styleMask;
    Atom windowMangerDelete;
    XEvent event;
    KeySym keySymbol;
    int framebufferAttrubutes[] =
        {
            GLX_DOUBLEBUFFER, True,
            GLX_RGBA,
            GLX_RED_SIZE, 8,
            GLX_GREEN_SIZE, 8,
            GLX_BLUE_SIZE, 8,
            GLX_ALPHA_SIZE, 8,
            None};
    Bool bDone = False;

    int screenWidth, screenHeight;
    char keys[26];

    // code

    gpFile = fopen("logFile.txt","w");
    if(gpFile == NULL)
    {
        printf("fopen() Failed");
    }
    else
    {
       fprintf(gpFile,"Program Started Successfully\n");
    }
    // Step 1 : Open Connection with xServer and get display Interface
    display = XOpenDisplay(NULL); 
    if (display == NULL)
    {
        printf("XOpenDisplay() Failed\n");
        uninitialize();
        exit(1);
    }

    // Step 2: Get default screen from above function
    defaultScreen = XDefaultScreen(display); 

    // Step 4: Get Visual info from above Three steps
    xVisualInfo = glXChooseVisual(display, defaultScreen, framebufferAttrubutes);

    if (xVisualInfo == NULL)
    {
        printf("glXChooseVisual() Failed\n");
        uninitialize();
        exit(1);
    }

    // Step 5 : Set Window Attributes/Properties
    memset((void *)&windowAttributes, 0, sizeof(XSetWindowAttributes));

    windowAttributes.border_pixel = 0;
    windowAttributes.background_pixel = XBlackPixel(display, xVisualInfo->screen); 
    windowAttributes.background_pixmap = 0;
    windowAttributes.colormap = XCreateColormap(display, XRootWindow(display, xVisualInfo->screen), xVisualInfo->visual, AllocNone); 

    // Assign this colormap to global colormap
    colormap = windowAttributes.colormap;

    // Set the Style Of Window
    styleMask = CWBorderPixel | CWBackPixel | CWColormap | CWEventMask;

    // Step 6 : Create Window
    window = XCreateWindow(display,
                           XRootWindow(display, xVisualInfo->screen),
                           0,
                           0,
                           WIN_WIDTH,
                           WIN_HEIGHT,
                           0,
                           xVisualInfo->depth,
                           InputOutput,
                           xVisualInfo->visual,
                           styleMask,
                           &windowAttributes); 

    if (!window)
    {
        printf("XCreateWindow() Failed\n");
        uninitialize();
        exit(1);
    }

    // Step 7 :  Specify to which event this Window should Responsed
    XSelectInput(display, 
		  window, 
		  ExposureMask | VisibilityChangeMask | StructureNotifyMask | KeyPressMask | 	ButtonPressMask | PointerMotionMask | FocusChangeMask); 

    // Step 8: Specify Window Manager Delete Atom
    windowMangerDelete = XInternAtom(display, "WM_DELETE_WINDOW", True); 
    
    // Step 9 : Add/Set above atom as Protocol for Window Manager
    XSetWMProtocols(display, window, &windowMangerDelete, 1); 

    // Step 10 : Give Caption To the Window
    XStoreName(display, window, "Srushti Moghe: X WIndows"); 

    // Step 11 : Map/Show the Window
    XMapWindow(display, window); 

    // Center the Window
    screenWidth = XWidthOfScreen(XScreenOfDisplay(display, xVisualInfo->screen));
    screenHeight = XHeightOfScreen(XScreenOfDisplay(display, xVisualInfo->screen));

    XMoveWindow(display, window, (screenWidth - WIN_WIDTH) / 2, (screenHeight - WIN_HEIGHT) / 2);

    // openGL Initialization

    initialize();

    // Step 12 : Game Loop
    while (bDone == False)
    {
        

        while (XPending(display))
        {
            // memset the event structure
            memset((void *)&event, 0, sizeof(XEvent));
            XNextEvent(display, &event); 

            switch (event.type)
            {
            case MapNotify:
                break;
            case FocusIn:
                bActiveWindow = True;
                break;
            case FocusOut:
                bActiveWindow = False;
                break;
            case ConfigureNotify:
                resize(event.xconfigure.width,event.xconfigure.height);
                break;
            case ButtonPress:
                switch (event.xbutton.button)
                {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;

                default:
                    break;
                }
                break;

            case KeyPress:
            {
                keySymbol = XkbKeycodeToKeysym(display, event.xkey.keycode, 0, 0); 
                switch (keySymbol)
                {
                case XK_Escape:
                bDone = True;
                fprintf(gpFile,"Program Ended Successfully\n");
                    break;

                default:
                    break;
                }
            }
                XLookupString(&event.xkey, keys, sizeof(keys), NULL, NULL);
                switch (keys[0])
                {
                case 'F':
                case 'f':

                    // code 
                    
                    if (bFullscreen == False)
                    {
                        toggleFullscreen();
                        bFullscreen = True;
                    }
                    else
                    {
                        toggleFullscreen();
                        bFullscreen = False;
                    }
                    break;

  		case 'L':
                case 'l':

                    if (gbLight == False)
                    {
                        glEnable(GL_LIGHTING);
                        gbLight = True;
                    }
                    else
                    {
                        glDisable(GL_LIGHTING);
                        gbLight = False;
                    }
                    break;
                    
                default:
                    break;
                }
                break;
            case 33:
                bDone = True;
                break;

            default:
                break;
            }
        }
        
        // Rendering
        if(bActiveWindow==True)
        {
            draw();
            
            update();
        }
        
    }

    return 0;
}

void toggleFullscreen(void)
{
    // Local Variable Declarations
    Atom windowManagerStateNormal;
    Atom windowManagerStateFullscreen;
    XEvent event;

    // Code
    // Step 1 : Get Atom from Window Manager
    windowManagerStateNormal = XInternAtom(display, "_NET_WM_STATE", False);
    // Step 2 : Window Manager State Full Screen
    windowManagerStateFullscreen = XInternAtom(display, "_NET_WM_STATE_FULLSCREEN", False);
    // Step 3 : memset the event structure and fill it above two Atom
    memset((void *)&event, 0, sizeof(XEvent));

    event.type = ClientMessage;
    event.xclient.window = window;
    event.xclient.message_type = windowManagerStateNormal;
    event.xclient.format = 32;
    event.xclient.data.l[0] = bFullscreen ? 0 : 1;
    event.xclient.data.l[1] = windowManagerStateFullscreen;

    // Step 4 :  Send the event
    XSendEvent(display,
               XRootWindow(display, xVisualInfo->screen),
               False,                  // Dont pass event to child window / event propagation to child
               SubstructureNotifyMask, // It informs that your size is changing, Substructure Notify Mask
               &event);
}

int initialize(void)
{
    //Local Function Declarations
    void resize(int,int);
    // code
    glxContext = glXCreateContext(display,xVisualInfo,NULL,True);

    if(glxContext == NULL)
    {
        printf("glXCreateContext() Failed");
        return -1;
    }

    //Make this context as current context
    if(glXMakeCurrent(display,window,glxContext) == False)
    {
        printf("glXMakeCurrent() Failed");
        return -2;
    }

    //usual openGL code
    glClearColor(0.0f,0.0f,0.0f,1.0f);

// Initializing or Enabling Light0
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbientZero);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuseZero);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecularZero);
	glEnable(GL_LIGHT0);

	// Initializing or Enabling Light1
	glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbientOne);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuseOne);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpecularOne);
	glEnable(GL_LIGHT1);

	// Initializing or Enabling Light2
	glLightfv(GL_LIGHT2, GL_AMBIENT, lightAmbientTwo);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lightDiffuseTwo);
	glLightfv(GL_LIGHT2, GL_SPECULAR, lightSpecularTwo);
	glEnable(GL_LIGHT2);

	// Initializing or Enabling Material
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

    //Warm-up resize call
    resize(WIN_WIDTH,WIN_HEIGHT);
    
   // Initialize Quadric
	quadric = gluNewQuadric();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
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


void draw(void)
{
   // Code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Step 3 (Compulsory)	// To paint the window Blue after setting it in glClearColor()
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();

	// Camera Transformation
	gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	// Rendering Light0 (Red Light, X-Rotation)
	glPushMatrix();
	glRotatef(lightAngleZero, 1.0f, 0.0f, 0.0f);
	lightPositionZero[0] = 0.0f;			// x (By rule)
	lightPositionZero[1] = 0.0f;			// y (For prescision)
	lightPositionZero[2] = lightAngleZero;	// z (Light angle)
	lightPositionZero[3] = 1.0f;			// w (Constant)
	glLightfv(GL_LIGHT0, GL_POSITION, lightPositionZero);
	glPopMatrix();

	// Rendering Light1 (Green Light, Y-Rotation)
	glPushMatrix();
	glRotatef(lightAngleOne, 0.0f, 1.0f, 0.0f);
	lightPositionOne[0] = lightAngleOne;	// x (Light angle)
	lightPositionOne[1] = 0.0f;				// y (By rule)
	lightPositionOne[2] = 0.0f;				// z (For prescision)
	lightPositionOne[3] = 1.0f;				// w (Constant)
	glLightfv(GL_LIGHT1, GL_POSITION, lightPositionOne);
	glPopMatrix();

	// Rendering Light0 (Blue Light, Z-Rotation)
	glPushMatrix();
	glRotatef(lightAngleTwo, 0.0f, 0.0f, 1.0f);
	lightPositionTwo[0] = 0.0f;				// x (For prescision)
	lightPositionTwo[1] = lightAngleTwo;	// y (Light angle)
	lightPositionTwo[2] = 0.0f;				// z (By rule)
	lightPositionTwo[3] = 1.0f;				// w (Constant)
	glLightfv(GL_LIGHT2, GL_POSITION, lightPositionTwo);
	glPopMatrix();

	gluSphere(quadric, 0.8f, 50, 50);	// gluSphere() creates all needed normals internally
	// all glu objects creates all needed normals internally

	glPopMatrix();	


    glXSwapBuffers(display,window);
}

void update(void)
{
	// Code

	cAngle = cAngle - 0.8f;		// cAngle in "degrees"

	if (cAngle <= 0.0f)
	{
		cAngle = cAngle + 360.0f;
		// cAngle = 0.0f; Also Works
	}

	// Animating Light0
	lightAngleZero = lightAngleZero + 0.05f;
	if (lightAngleZero <= 0.0f)
	// if (lightAngleZero >= 0.0f)
	{
		lightAngleZero = lightAngleZero + 360.0f;
		// lightAngleZero = lightAngleZero - 360.0f;
	}

	// Animating Light1
	lightAngleOne = lightAngleOne + 0.05f;
	if (lightAngleOne <= 0.0f)
		// if (lightAngleOne >= 0.0f)
	{
		lightAngleOne = lightAngleOne + 360.0f;
		// lightAngleOne = lightAngleOne - 360.0f;
	}

	// Animating Light2
	lightAngleTwo = lightAngleTwo + 0.05f;
	if (lightAngleTwo <= 0.0f)
		// if (lightAngleTwo >= 0.0f)
		{
			lightAngleTwo = lightAngleTwo + 360.0f;
			// lightAngleTwo = lightAngleTwo - 360.0f;
		}
}
void uninitialize(void)
{

    // Local Variable Declarations
    GLXContext currentGLXContext;

    // code
    if (xVisualInfo)
    {
        free(xVisualInfo);
        xVisualInfo = NULL;
    }

    // UnCurrent the Context
    currentGLXContext = glXGetCurrentContext();
    if (currentGLXContext != NULL && currentGLXContext == glxContext)
    {
        glXMakeCurrent(display, 0, 0);
    }

    if (glxContext)
    {
        glXDestroyContext(display, glxContext);
        glxContext = NULL;
    }

    if (window)
    {
        XDestroyWindow(display, window); 
    }

    if (colormap)
    {
        XFreeColormap(display, colormap); 
    }

    if (display)
    {
        XCloseDisplay(display); 
        display = NULL;
    }

    if (gpFile)
    {
        fprintf(gpFile, "Program Ended Successfully\n");
        gpFile = NULL;
    }
}






