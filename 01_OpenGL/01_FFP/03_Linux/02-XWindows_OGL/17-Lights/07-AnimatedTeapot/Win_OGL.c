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

#include "Model.h"

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

GLfloat pAngle = 0.0f;	// For Rotating Pyramid

// Light Variables

Bool gbLight = False;

// Light Variables

// GOROUD SHADING - ALBEDO PROGRAM

GLfloat lightAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f};			
GLfloat lightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};			// White Diffused Light
GLfloat lightSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};			// White Specular Light
GLfloat lightPosition[] = {100.0f, 100.0f, 100.0f, 1.0f};	// GLfloat lightPosition[] = {x, y, z, w=0/1};

GLfloat materialAmbient[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat materialDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat materialSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat materialShininess[] = {128.0f};			

// Texture Object

Bool bTexture = False;

GLuint texture_model = 0;

// For Animation

Bool bAnimate = False;

GLfloat angle = 0.0f;

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
				// glEnable(GL_LIGHTING);
				// Not a good discipline to call in WndProc()
				gbLight = True;
			}
			else
			{
				// glDisable(GL_LIGHTING);
				// Not a good discipline to call in WndProc()
				gbLight = False;
			}

		break;
		
		case 'T':
		case 't':

			if (bTexture == False)
			{
				// glEnable(GL_LIGHTING);
				bTexture = True;
			}
			else
			{
				// glDisable(GL_LIGHTING);
				bTexture = False;
			}
			break;
		
			case 'A':
			case 'a':

				if (bAnimate == False)
				{
					bAnimate = True;
				}
				else
				{
					bAnimate = False;
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

    // Enabling Depth

	glShadeModel(GL_SMOOTH);								// Step 2.4 (Optional)

	glClearDepth(1.0f);										// Step 2.1 (Compulsory)
	glEnable(GL_DEPTH_TEST);								// Step 2.2 (Compulsory)
	glDepthFunc(GL_LEQUAL);									// Step 2.3 (Compulsory) Comparing Function LEQUAL is Less than or Equal to glClearDepth(valuef)

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);		// Step 2.5 (Optional)

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//Light related initialization

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glEnable(GL_LIGHT0);
	
	//Mateerial Properties
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // usual openGL code
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Warm-up resize call
    resize(WIN_WIDTH, WIN_HEIGHT);
}

GLuint loadGLTexture(const char *path)
{
    // Local Variables
    int width, height;
    unsigned char *imageData = NULL;
    GLuint texture;
    glEnable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);

    // Code
    imageData = SOIL_load_image(path, &width, &height, NULL, SOIL_LOAD_RGB);

    if (imageData == NULL)
    {
        fprintf(gpFile, "SOIL_load_image() Failed...!!\n\n");
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

     fprintf(gpFile, "%d..!!\n\n",texture);

    return texture;
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
   //Local Variable declarations
	int i, j;
	int vi, ni, ti;

    // function declarations

    // code
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


	glTranslatef(0.0f, 0.0f, -1.5f);

    // Toggle lighting
	if (gbLight == True)
	{
		glEnable(GL_LIGHTING);
	}
	else
	{
		glDisable(GL_LIGHTING);
	}

	// Toggle Texture
	if (bTexture == True)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture_model);
	}
	else
	{
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	glRotatef(pAngle, 0.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES);

	for (i = 0; i < sizeof(face_indicies) / sizeof(face_indicies[0]); i++)
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
    
	//unbind texture
	glBindTexture(GL_TEXTURE_2D, 0);

    glXSwapBuffers(display,window);
}

void update(void)
{
    // Code
    if(bAnimate)
    {
         if (pAngle <= 360.0f)
		    pAngle = pAngle + 0.9f;
	    else
		    pAngle = 0.0f;
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






