// Standard Header Files
#include <stdio.h>    // For printf()
#include <stdlib.h>     // For exit()
#include <memory.h>   // memset()   

// X11 Header Files
#include <X11/Xlib.h>   // For all Xwindow APIs
#include <X11/Xutil.h>  // For XVisualInfo() and related APIs
#include <X11/XKBlib.h>

// Global Variable Declarations
Display *display = NULL;
Colormap colormap;
Window window;

// MACROS
#define WINWIDTH 800
#define WINHEIGHT 600

// main()
int main(void)
{
    // Local Function Declarations
    void uninitialize(void);

    // Local Variable Declarations

    int defaultScreen;
    int defaultDepth;
    XVisualInfo visualInfo;
    Status status;  // Status is internally integer
    XSetWindowAttributes windowAttributes;
    int StyleMask;
    Atom windowManagerDelete;
    XEvent event;
    KeySym keySym;

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
    memset((void*)&visualInfo, 0, sizeof(XVisualInfo));
    status = XMatchVisualInfo(display, defaultScreen, defaultDepth, TrueColor, &visualInfo);
    if (status == 0)
    {
        printf("'XMatchVisualInfo() failed !!!' /n");
        uninitialize();
        exit(1);    // exit(0) --> exit(SUCCESS) exit(1) --> exit(FAILED)
    }

    // STEP5: Set window attributes/ properties
    memset((void*)&windowAttributes, 0, sizeof(XSetWindowAttributes));
    windowAttributes.border_pixel = 0;  // Border colour for the window
    windowAttributes.background_pixel = XBlackPixel(display, visualInfo.screen);    // Background colour for window
    windowAttributes.background_pixmap = 0;   // Background image for the window
    windowAttributes.colormap = XCreateColormap(display,
                                                XRootWindow(display, visualInfo.screen),
                                                visualInfo.visual,
                                                AllocNone);   // Group of colour cells is called as colormap

    // STEP6: Assign this colormap to global colormap
    colormap = windowAttributes.colormap;

    // STEP7: Set StyleMask
    StyleMask = CWBorderPixel | CWBackPixel | CWColormap | CWEventMask;

    // STEP8: Create Window
    window = XCreateWindow(display,
                            XRootWindow(display, visualInfo.screen),
                            0,
                            0,
                            WINWIDTH,
                            WINHEIGHT,
                            0,
                            visualInfo.depth,
                            InputOutput,
                            visualInfo.visual,
                            StyleMask,
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

    // Event Loop
    while (1)
    {
        XNextEvent(display, &event);
        switch (event.type)
        {
        case KeyPress:
        keySym = XkbKeycodeToKeysym(display, event.xkey.keycode, 0, 0);
        switch (keySym)
        {
        case XK_Escape:
            uninitialize();
            exit(0);

        break;
        default:
            break;
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
    uninitialize();

    return (0);
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





