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

GLfloat lightAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat lightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat lightPosition[] = {0.0f, 0.0f, 0.0f, 1.0f};	// {0.0f, 0.0f, 0.0f,Central light 1.0fPositional Light}

GLUquadric* quadric = NULL;

GLfloat angleXRotation = 0.0f;
GLfloat angleYRotation = 0.0f;
GLfloat angleZRotation = 0.0f;

GLuint keyPressed = 0;

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
                    
                case 'X':
                case 'x':
                    keyPressed = 1;
                    angleXRotation = 0.0f; // reset
                    break;

                case 'Y':
                case 'y':
                    keyPressed = 2;
                    angleYRotation = 0.0f; // reset
                    break;

                case 'Z':
                case 'z':
                    keyPressed = 3;
                    angleZRotation = 0.0f; // reset
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

   // Enabling Depth

	glShadeModel(GL_SMOOTH);				

	glClearDepth(1.0f);						
	glEnable(GL_DEPTH_TEST);					
	glDepthFunc(GL_LEQUAL);	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);		

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

void draw(void)
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



    glXSwapBuffers(display,window);
}

void update(void)
{
	/// Code

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






