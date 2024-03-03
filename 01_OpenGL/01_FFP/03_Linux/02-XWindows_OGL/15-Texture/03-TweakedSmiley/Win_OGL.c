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

// SOIL header files
#include <SOIL/SOIL.h>

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

GLint winHeight = WIN_HEIGHT;
GLint winWidth = WIN_WIDTH;

// GLfloat pAngle = 0.0f;	// For Rotating Pyramid
GLfloat cAngle = 0.0f;	// For Rotating Cube

// Texture Object
GLuint texture_smiley = 0;
// GLint PressedKey = -1;
int PressedKey = -1;

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
            GLX_DEPTH_SIZE, 24,
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
          if (bFullscreen == True)
            {
                winWidth = XWidthOfScreen(XScreenOfDisplay(display, xVisualInfo->screen));
                winHeight = XHeightOfScreen(XScreenOfDisplay(display, xVisualInfo->screen));
            }
            
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
                    fprintf(gpFile, "Program Terminated Successfully\n");
                    break;
                case XK_0:
                case XK_KP_0:
                    PressedKey = 1;
                    fprintf(gpFile, "%d\n",PressedKey);
                    glEnable(GL_TEXTURE_2D);
                    break;
                case XK_1:
                case XK_KP_1:
                    PressedKey = 2;
                    fprintf(gpFile, "%d\n",PressedKey);
                    glEnable(GL_TEXTURE_2D);
                    break;
                case XK_2:
                case XK_KP_2:
                    PressedKey = 3;
                    fprintf(gpFile, "%d\n",PressedKey);
                    glEnable(GL_TEXTURE_2D);
                    break;
                case XK_3:
                case XK_KP_3:
                    PressedKey = 4;
                    fprintf(gpFile, "%d\n",PressedKey);
                    glEnable(GL_TEXTURE_2D);
                    break;
                default:
                    glDisable(GL_TEXTURE_2D);
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
    GLuint loadGLTexture(const char *);
    
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

 // Create Texture
    texture_smiley = loadGLTexture("Smiley.bmp");
    if (texture_smiley == 0)
    {
        printf("loadGLTexture(Smiley.bmp) Failed\n");
        return -3;
    }

    // Enabling Depth

    glShadeModel(GL_SMOOTH);                           // Optional
    glClearDepth(1.0f);                                // Mandatory
    glEnable(GL_DEPTH_TEST);                           // Mandatory
    glDepthFunc(GL_LEQUAL);                            // Mandatory
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Optional


    //usual openGL code
    glClearColor(0.0f,0.0f,0.0f,1.0f);

// Tell OpenGL to enable the texture
	glEnable(GL_TEXTURE_2D);
	
    //Warm-up resize call
    resize(WIN_WIDTH,WIN_HEIGHT);
    
  }
  
    
GLuint loadGLTexture(const char *path)
{
    // Local Variables
    int width, height;
    unsigned char *imageData = NULL;
    GLuint texture;
    glEnable(GL_TEXTURE_2D);


    // Code
    imageData = SOIL_load_image(path, &width, &height, NULL, SOIL_LOAD_RGB);

    if (imageData == NULL)
    {
        fprintf(gpFile, "imageLoading() Failed...!!\n\n");
        return 0;
    }

    glPixelStorei(GL_UNPACK_ALIGNMENT, 4); // RGBA : 4

    // Create Textures objects
    glGenTextures(1, &texture);

    // Bind to the texture
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    // Create Multiple Mipmap Images
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, (void *)imageData);

    // Unbind from binding point
    glBindTexture(GL_TEXTURE_2D, 0);

    // Delete Image Resource From SOIL
    SOIL_free_image_data(imageData);

     fprintf(gpFile, "%d..!!\n",texture);

    return texture;
}

void resize(int width, int height)
{
    // code
    if (height <= 0)
        height = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
}

void draw(void)
{
    // function declarations

    /// Code

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Step 3 (Compulsory)	// To paint the window Blue after setting it in glClearColor()

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -4.0f);
	glScalef(0.75f, 0.75f, 0.75f);	// Position of glScalef(); is VVVIMP

	// glRotatef(cAngle, 1.0f, 0.0f, 0.0f);	// X-Rotation
	// glRotatef(cAngle, 0.0f, 1.0f, 0.0f);	// Y-Rotation
	// glRotatef(cAngle, 0.0f, 0.0f, 1.0f);	// Z-Rotation

	glBindTexture(GL_TEXTURE_2D, texture_smiley);

	if (PressedKey == 1)
	{
		glBegin(GL_QUADS);

		// RT
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		// LT
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		// LB
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		// RB
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);

		glEnd();
	}
	else if (PressedKey == 2)
	{
		glBegin(GL_QUADS);

		// RT
		glTexCoord2f(0.5f, 0.5f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		// LT
		glTexCoord2f(0.0f, 0.5f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		// LB
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		// RB
		glTexCoord2f(0.5f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);

		glEnd();
	}
	// BINDING or TILING
	else if (PressedKey == 3)
	{
		glBegin(GL_QUADS);

		// RT
		glTexCoord2f(2.0f, 2.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		// LT
		glTexCoord2f(0.0f, 2.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		// LB
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		// RB
		glTexCoord2f(2.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);

		glEnd();
	}
	else if (PressedKey == 4)
	{
		glBegin(GL_QUADS);

		// RT
		glTexCoord2f(0.5f, 0.5f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		// LT
		glTexCoord2f(0.5f, 0.5f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		// LB
		glTexCoord2f(0.5f, 0.5f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		// RB
		glTexCoord2f(0.5f, 0.5f);
		glVertex3f(1.0f, -1.0f, 0.0f);

		glEnd();
	}
	else
	{
		glBegin(GL_QUADS);

		// RT
		// glTexCoord2f(0.5f, 0.5f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		// LT
		// glTexCoord2f(0.5f, 0.5f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		// LB
		// glTexCoord2f(0.5f, 0.5f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		// RB
		// glTexCoord2f(0.5f, 0.5f);
		glVertex3f(1.0f, -1.0f, 0.0f);

		glEnd();
	}

	glBindTexture(GL_TEXTURE_2D, 0);		// Unbinding Discipline for Cube


    glXSwapBuffers(display,window);
}

void update(void)
{
    // Code

	// Cube
	cAngle = cAngle - 0.008f;		// cAngle in "degrees"

	if (cAngle <= 0.0f)
	{
		cAngle = cAngle + 360.0f;
		// cAngle = 0.0f; Also Works
	}
}

void uninitialize(void)
{

    // Local Variable Declarations
    GLXContext currentGLXContext;

    // code
    if(xVisualInfo)
    {
        free(xVisualInfo);
       xVisualInfo = NULL;
    }

    //UnCurrent the Context
    currentGLXContext = glXGetCurrentContext();
    if(currentGLXContext != NULL && currentGLXContext == glxContext)
    {
      glXMakeCurrent(display,0,0);
    }

    if(glxContext)
    {
        glXDestroyContext(display,glxContext);
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
    
    if(gpFile)
    {
        fprintf(gpFile,"Program Ended Successfully\n");
        gpFile = NULL;
    }

}



















