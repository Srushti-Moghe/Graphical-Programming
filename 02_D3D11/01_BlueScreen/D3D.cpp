// SKELETON CODE
// BASE CODE for D3D, WINDOWS (FFP>OpenGL) and OpenGL(PP)

// Windows header files
#include <windows.h>
#include <stdlib.h> // For exit()
#include <stdio.h>	// For FileIO

#include <d3d11.h> // D3D related header files

#include "D3D.h" // User defined header file

#pragma comment(lib, "d3d11.lib") // D3D related liabriries

// Macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// Global Function Declarations / Function Prototype
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Global Variable Declarations

HWND ghwnd = NULL; // g-global hwnd-window handle

BOOL gbActive = FALSE; // By default the window is not active

FILE *gpFile = NULL;

DWORD dwStyle = 0;

WINDOWPLACEMENT wpPrev = {sizeof(WINDOWPLACEMENT)};

BOOL gbFullscreen = FALSE;

CHAR gszLogFileName[] = "log.txt";

// D3D related global variables

IDXGISwapChain *gpIDXGISwapChain = NULL;
ID3D11Device *gpID3D11Device = NULL;
ID3D11DeviceContext *gpID3D11DeviceContext = NULL;
ID3D11RenderTargetView *gpID3D11RenderTargetView = NULL;
float clearColor[4];

// Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// Local Variable Declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("SUMWindow");
	HRESULT hr = S_OK;

	// Function Declarations / Prototype

	HRESULT initialize(void);

	void uninitialize(void);
	void display(void);
	void update(void);

	int iResult = 0;
	BOOL bDone = FALSE;

	HDC hdc; // One of the two arguments required for GetDeviceCaps
	hdc = GetDC(NULL);

	// Centering Window

	// X, Y coordinates for SCREEN
	int ScreenWidth = GetDeviceCaps(hdc, HORZRES);
	int ScreenHeight = GetDeviceCaps(hdc, VERTRES);

	// X, Y coordinates for WINDOW
	int WindowX = (ScreenWidth / 2) - (WIN_WIDTH / 2);
	int WindowY = (ScreenHeight / 2) - (WIN_HEIGHT / 2);

	// Code

	fopen_s(&gpFile, gszLogFileName, "w");

	if (gpFile == NULL)
	{
		MessageBox(NULL, TEXT("LOG FILE OPENING ERROR"), TEXT("ERROR"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	else
	{
		fprintf(gpFile, "Programme Started Successfully\n");
		fclose(gpFile);
	}

	// WNDCLASSEX Initialization
	wndclass.cbSize = sizeof(WNDCLASSEX);							 // 1
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;			 // 2		// The window context that is created by CreateWindow() is under wndclass.style
	wndclass.cbClsExtra = 0;										 // 3
	wndclass.cbWndExtra = 0;										 // 4
	wndclass.lpfnWndProc = WndProc;									 // 5
	wndclass.hInstance = hInstance;									 // 6
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);	 // 7
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));	 // 8
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);					 // 9
	wndclass.lpszClassName = szAppName;								 // 10
	wndclass.lpszMenuName = NULL;									 // 11
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON)); // 12

	// Register WNDCLASSEX
	RegisterClassEx(&wndclass);

	// Create the Window
	// Change CreateWindow to CreateWindowEx
	// CreateWindowEx brings the Window above the task bar
	hwnd = CreateWindowEx(
		WS_EX_APPWINDOW, // Window above Task Bar
		szAppName,
		TEXT("Srushti Umesh Moghe"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		WindowX,
		WindowY,
		WIN_WIDTH,	// Macro
		WIN_HEIGHT, // Macro
		NULL,
		NULL,
		hInstance,
		NULL);

	ghwnd = hwnd;

	// Initialization

	hr = initialize();
	if (FAILED(hr))
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "initialise() Failed\n");
		fclose(gpFile);

		// MessageBox(hwnd, TEXT("Initialisation Failed"), TEXT("ERROR"), MB_OK | MB_ICONERROR);
		DestroyWindow(hwnd);
	}
	else
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "initialise() Success\n");
		fclose(gpFile);
	}

	/*
	if (iResult != 0)
	{
		MessageBox(hwnd, TEXT("initialize() failed !!!"), TEXT("Error"), MB_OK | MB_ICONERROR);
		// MessageBox(hwnd / ghwnd / NULL, TEXT("initialize() failed !!!"), TEXT("Error"), MB_OK | MB_ICONERROR);

		DestroyWindow(hwnd);
	}
	*/

	// Show the Window
	ShowWindow(hwnd, iCmdShow);

	SetForegroundWindow(hwnd);
	// SetForegroundWindow(ghwnd); To make sure the window is always in the Foreground

	SetFocus(hwnd); // To keep the window selected / highlighted; internally calls WM_SETFOCUS to WndProc()

	// UpdateWindow(hwnd); is sent to WM_PAINT hence to be removed

	/* Message Loop - GetMessage

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	*/

	// GAME LOOP
	while (bDone == FALSE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) // PM_REMOVE - removes message from the message queue
		{
			if (msg.message == WM_QUIT)
			{
				bDone = TRUE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if (gbActive == TRUE)
			{
				// RENDER
				display();

				// Update (For animation and changes)
				update();
			}
		}
	}
	// Uninitialization
	uninitialize();

	return ((int)msg.wParam);
}
// Claaback Function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// Function Declarations

	void ToggleFullscreen(void);
	HRESULT resize(int, int);
	// void resize(width, height);

	HRESULT hr = S_OK;

	// Code
	// Body of the callback() - WndProc [User Defined]
	switch (iMsg)
	{
	case WM_SETFOCUS: // Message for Active Window
		gbActive = TRUE;
		break;

	case WM_KILLFOCUS: // Message that deviates focus from the active window
		gbActive = FALSE;
		break;

	case WM_SIZE:
		if (gpID3D11DeviceContext)
		{
			hr = resize(LOWORD(lParam), HIWORD(lParam)); // void resize(width, height);
			if (FAILED(hr))
			{
				fopen_s(&gpFile, gszLogFileName, "a+");
				fprintf(gpFile, "resize() Failed\n");
				fclose(gpFile);
				return (hr);
			}
			else
			{
				fopen_s(&gpFile, gszLogFileName, "a+");
				fprintf(gpFile, "resize() Success\n");
				fclose(gpFile);
			}
		}
		break;

	case WM_ERASEBKGND:
		return (0); // Message does not go to DefWindowProc()
		break;

	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_ESCAPE:
			DestroyWindow(hwnd);
			break;
		}
		break;

	case WM_CHAR:
		switch (LOWORD(wParam))
		{
		case 'F':
		case 'f':

			if (gbFullscreen == FALSE)
			{
				ToggleFullscreen();
				gbFullscreen = TRUE;
			}
			else
			{
				ToggleFullscreen();
				gbFullscreen = FALSE;
			}
			break;
		}
		break;

	case WM_CLOSE:
		DestroyWindow(hwnd); // To destroy the program running in the background when the window is closed
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		break;
	}

	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void ToggleFullscreen(void)
{
	// Local Variable Declarations
	MONITORINFO mi = {sizeof(MONITORINFO)};

	// code
	if (gbFullscreen == FALSE)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);

		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED); // iii - B
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

HRESULT initialize(void)
{
	// Function Declarations
	HRESULT resize(int, int);

	// Variable declarations
	HRESULT hr = S_OK;

	// Code

	// Initialise SwapChain Descriptor sturcture
	DXGI_SWAP_CHAIN_DESC dxgiSwapChainDesc;
	ZeroMemory((void *)&dxgiSwapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

	dxgiSwapChainDesc.BufferDesc.Width = WIN_WIDTH;
	dxgiSwapChainDesc.BufferDesc.Height = WIN_HEIGHT;
	dxgiSwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	dxgiSwapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	dxgiSwapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	dxgiSwapChainDesc.SampleDesc.Count = 1;
	dxgiSwapChainDesc.SampleDesc.Quality = 0;
	dxgiSwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	dxgiSwapChainDesc.BufferCount = 1;
	dxgiSwapChainDesc.OutputWindow = ghwnd;
	dxgiSwapChainDesc.Windowed = TRUE;

	// Create D3D Swapchain,device,deviceContext,render target view
	D3D_DRIVER_TYPE d3dDriverType;
	D3D_DRIVER_TYPE d3dDriverTypes[] = {D3D_DRIVER_TYPE_HARDWARE,
										D3D_DRIVER_TYPE_WARP, // Windows Advanced Rasterization Platform
										D3D_DRIVER_TYPE_SOFTWARE,
										D3D_DRIVER_TYPE_REFERENCE,
										D3D_DRIVER_TYPE_NULL,
										D3D_DRIVER_TYPE_UNKNOWN};

	D3D_FEATURE_LEVEL d3dFeatureLevel_required = D3D_FEATURE_LEVEL_11_0;
	D3D_FEATURE_LEVEL d3dFeatureLevel_acquired = D3D_FEATURE_LEVEL_10_0;

	UINT numDriverTypes;
	UINT numFeatureLevels = 1;

	numDriverTypes = sizeof(d3dDriverTypes) / sizeof(d3dDriverTypes[0]);

	for (UINT i = 0; i < numDriverTypes; i++)
	{
		d3dDriverType = d3dDriverTypes[i];

		hr = D3D11CreateDeviceAndSwapChain(NULL,
										   d3dDriverType,
										   NULL,
										   0,
										   &d3dFeatureLevel_required,
										   numFeatureLevels,
										   D3D11_SDK_VERSION,
										   &dxgiSwapChainDesc,
										   &gpIDXGISwapChain,
										   &gpID3D11Device,
										   &d3dFeatureLevel_acquired,
										   &gpID3D11DeviceContext);
		if (SUCCEEDED(hr))
		{
			break;
		}
	}

	if (FAILED(hr))
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "d3dDriverandSwapChain() Failed\n");
		fclose(gpFile);
		return (hr);
	}
	else
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		// fprintf(gpFile, "d3dDriverandSwapChain() Success\n");

		if (d3dDriverType == D3D_DRIVER_TYPE_HARDWARE)
		{
			fprintf(gpFile, "Hardware driver Found\n");
		}
		// which driver is found

		else if (d3dDriverType == D3D_DRIVER_TYPE_WARP)
		{
			fprintf(gpFile, "Warp driver Found\n");
		}
		else if (d3dDriverType == D3D_DRIVER_TYPE_SOFTWARE)
		{
			fprintf(gpFile, "Software driver Found\n");
		}
		else if (d3dDriverType == D3D_DRIVER_TYPE_REFERENCE)
		{
			fprintf(gpFile, "Reference driver Found\n");
		}
		else if (d3dDriverType == D3D_DRIVER_TYPE_NULL)
		{
			fprintf(gpFile, "Null driver Found\n");
		}
		else if (d3dDriverType == D3D_DRIVER_TYPE_UNKNOWN)
		{
			fprintf(gpFile, "Unknown driver\n");
		}
		else
		{
			fprintf(gpFile, "Undefined driver found\n");
		}

		// Which feature level is found

		if (d3dFeatureLevel_acquired == D3D_FEATURE_LEVEL_11_0)
		{
			fprintf(gpFile, "11.0 Feature Level found\n");
		}
		else if (d3dFeatureLevel_acquired == D3D_FEATURE_LEVEL_10_1)
		{
			fprintf(gpFile, "10.1 Feature Level found\n");
		}
		else if (d3dFeatureLevel_acquired == D3D_FEATURE_LEVEL_10_0)
		{
			fprintf(gpFile, "10.0 Feature Level found\n");
		}
		else
		{
			fprintf(gpFile, "Unknown feature level found\n");
		}

		fclose(gpFile);
	}

	// Define Clear Color
	clearColor[0] = 0.0f;
	clearColor[1] = 0.0f;
	clearColor[2] = 1.0f;
	clearColor[3] = 1.0f;

	// Warmup resize
	if (gpID3D11DeviceContext)
	{
		hr = resize(WIN_WIDTH, WIN_HEIGHT);
		if (FAILED(hr))
		{
			fopen_s(&gpFile, gszLogFileName, "a+");
			fprintf(gpFile, "Warmup resize() Failed\n");
			fclose(gpFile);
			return hr;
		}
		else
		{
			fopen_s(&gpFile, gszLogFileName, "a+");
			fprintf(gpFile, "Warmup resize() Success\n");
			fclose(gpFile);
		}
	}

	return (hr);
}

HRESULT resize(int width, int height)
{
	HRESULT hr = S_OK;
	// Code
	if (height <= 0)
	{
		height = 1; // Precaution as height is a divisor, hence cannot be 0 or negative
	}

	// Release Render Target View
	if (gpID3D11RenderTargetView)
	{
		gpID3D11RenderTargetView->Release();
		gpID3D11RenderTargetView = NULL;
	}
	// Resize Swap Chain Buffers acc to changed size
	gpIDXGISwapChain->ResizeBuffers(1,
									width,
									height,
									DXGI_FORMAT_B8G8R8A8_UNORM,
									0);
	// Create new Render Target View
	// Create new Render Target View- get buffer fron Render Target View from Swap Chain into texture
	ID3D11Texture2D *pid3d11Texture2d = NULL;
	gpIDXGISwapChain->GetBuffer(0,
								__uuidof(ID3D11Texture2D),
								((void **)&pid3d11Texture2d));
	// Create new Render Target View- Create new Render Target View using above buffer
	hr = gpID3D11Device->CreateRenderTargetView(pid3d11Texture2d,
												NULL, // Mipmap lvl = 0
												&gpID3D11RenderTargetView);

	if (FAILED(hr))
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "Create Render TargetView() Failed\n");
		fclose(gpFile);
		return hr;
	}
	else
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "Create Render TargetView() Success\n");
		fclose(gpFile);
	}
	// Set this new Create Render Target View into pipeline

	pid3d11Texture2d->Release();
	pid3d11Texture2d = NULL;

	gpID3D11DeviceContext->OMSetRenderTargets(1, &gpID3D11RenderTargetView, NULL);

	// Initialise and Set The Viewport
	D3D11_VIEWPORT d3dViewPort;
	ZeroMemory((void *)&d3dViewPort, sizeof(D3D11_VIEWPORT));

	d3dViewPort.TopLeftX = 0.0f;
	d3dViewPort.TopLeftY = 0.0f;
	d3dViewPort.Width = (float)width;
	d3dViewPort.Height = (float)height;
	d3dViewPort.MinDepth = 0.0f;
	d3dViewPort.MaxDepth = 1.0f;

	// Set above viewport into pipeline 
	gpID3D11DeviceContext->RSSetViewports(1, &d3dViewPort);


	return (hr);
}

void display(void)
{
	// Code

	// Clear Render Target View using clear color
	// Clear The RTV using the Clear Color
	gpID3D11DeviceContext->ClearRenderTargetView(gpID3D11RenderTargetView, clearColor);

	// Do Double Buffering by presenting the Swap Chain
	gpIDXGISwapChain->Present(0, 0);
}

void update(void)
{
	// Code
}

void uninitialize(void)
{
	// Function Declarations
	void ToggleFullscreen(void);

	// Code

	if (gpID3D11RenderTargetView)
	{
		gpID3D11RenderTargetView->Release();
		gpID3D11RenderTargetView = NULL;
	}

	if (gpID3D11DeviceContext)
	{
		gpID3D11DeviceContext->Release();
		gpID3D11DeviceContext = NULL;
	}

	if (gpIDXGISwapChain)
	{
		gpIDXGISwapChain->Release();
		gpIDXGISwapChain = NULL;
	}

	// Always Last
	if (gpID3D11Device)
	{
		gpID3D11Device->Release();
		gpID3D11Device = NULL;
	}

	// If application is exitting in Fullscreen
	if (gbFullscreen == TRUE)
	{
		ToggleFullscreen();
		gbFullscreen = FALSE;
	}

	// get rid of Window handle / Destroy Window
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}

	// Close the log file
	if (gpFile)
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "Programme Ended Successfully\n");
		fclose(gpFile);
		gpFile = NULL;
	}
}
