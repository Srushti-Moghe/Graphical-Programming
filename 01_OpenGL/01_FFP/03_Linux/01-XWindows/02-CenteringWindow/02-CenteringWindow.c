// Standard Header Files
//Standard Header Files
#include<stdio.h> // for printf
#include<stdlib.h> // for e.g exit() function
#include<memory.h>// for memset (zeromemory in windows)

//x11 header files
#include<X11/Xlib.h> // For All xWindow API
#include<X11/Xutil.h> // For XVisualInfo and rrelated API
#include<X11/XKBlib.h> 


//Global Variable Declarations
Display *display = NULL;
Colormap colormap;
Window window;

// MACROS
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// main()
int main(void)
{
    // Local Function Declarations
    void uninitialize(void);

    // Local Variable Declarations

    int defaultScreen;
    int defaultDepth;
    XVisualInfo xVisualInfo;
    Status status;  // Status is internally integer
    XSetWindowAttributes windowAttributes;
    int styleMask;
    Atom windowManagerDelete;
    XEvent event;
    KeySym keySymbol;

 int screenWidth,screenHeight;
 
    // Code
    // STEP1: Open the connection with Xserver & get the display interface
    
    display = XOpenDisplay(NULL);   // Open connection and display to the client
    if (display == NULL)
    {
        printf("'XOpenDisplay() failed !!!' /n");
        uninitialize();
        exit(1);    // exit(0) --> exit(SUCCESS) exit(1) --> exit(FAILED)
    }

    // STEP2: Get default screen from above display
    defaultScreen = XDefaultScreen(display);

    // STEP3: Get default depth from above two steps
    defaultDepth = XDefaultDepth(display, defaultScreen);

    // STEP4: Get visual info from above three
    memset((void*)&xVisualInfo, 0, sizeof(XVisualInfo));
    status = XMatchVisualInfo(display, defaultScreen, defaultDepth, TrueColor, &xVisualInfo);
    if (status == 0)
    {
        printf("'XMatchVisualInfo() failed !!!' /n");
        uninitialize();
        exit(1);    // exit(0) --> exit(SUCCESS) exit(1) --> exit(FAILED)
    }

    // STEP5: Set window attributes/ properties
    memset((void*)&windowAttributes, 0, sizeof(XSetWindowAttributes));
    windowAttributes.border_pixel = 0;  // Border colour for the window
    windowAttributes.background_pixel = XBlackPixel(display, xVisualInfo.screen);    // Background colour for window
    windowAttributes.background_pixmap = 0;   // Background image for the window
    windowAttributes.colormap = XCreateColormap(display,
                                                XRootWindow(display, xVisualInfo.screen),
                                                xVisualInfo.visual,
                                                AllocNone);   // Group of colour cells is called as colormap

    // STEP6: Assign this colormap to global colormap
    colormap = windowAttributes.colormap;

    // STEP7: Set StyleMask
    styleMask = CWBorderPixel | CWBackPixel | CWColormap | CWEventMask;

    // STEP8: Create Window
   window = XCreateWindow(display, 
                            XRootWindow(display, xVisualInfo.screen),
                            0,
                            0,
                            WIN_WIDTH,
                            WIN_HEIGHT,
                            0,
                            xVisualInfo.depth,
                            InputOutput,
                            xVisualInfo.visual,
                            styleMask,
                            &windowAttributes);

    if (!window)
    {
        printf("'XCreateWindow() failed !!!' /n");
        uninitialize();
        exit(1);    // exit(0) --> exit(SUCCESS) exit(1) --> exit(FAILED)
    }

    // STEP9: Specify to which events the window should respond
    XSelectInput(display, 
                 window, 
                 ExposureMask | VisibilityChangeMask | StructureNotifyMask | KeyPressMask | ButtonPressMask | PointerMotionMask);
    
    
    // STEP10: Specify window manager delete atom
    windowManagerDelete = XInternAtom(display, "WM_DELETE_WINDOW", True);

    // STEP11: Add/set above atom as protocol for window manager
    XSetWMProtocols(display, window, &windowManagerDelete, 1);

    // STEP12: Captioning the Window
    XStoreName(display, window, "SrushtiUmeshMoghe: XWindow");

    // STEP13: Show/Map the Window
    XMapWindow(display, window);

	//Centering of the Window
    screenWidth = XWidthOfScreen(XScreenOfDisplay(display,xVisualInfo.screen));
    screenHeight = XHeightOfScreen(XScreenOfDisplay(display,xVisualInfo.screen));

    XMoveWindow(display,window,(screenWidth-WIN_WIDTH)/2,(screenHeight-WIN_HEIGHT)/2);
    
    // Event Loop
    while (1)
    while(1)
    {
        XNextEvent(display, &event); 

        switch(event.type)
        {
            case KeyPress:
                {
                    keySymbol = XkbKeycodeToKeysym(display, event.xkey.keycode, 0, 0); 

                    switch (keySymbol)
                    {
                        case XK_Escape:
                            uninitialize();
                            exit(0);
                            break;
                        
                        default:
                            break;
                    }
                }
                break;
            case 33:
                uninitialize();
                exit(0); 
                break;

            default:
                break;
        }
    } 

    return 0;
}

void uninitialize (void)
{
    // Code
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
        XCloseDisplay(display = NULL);
    }
}





