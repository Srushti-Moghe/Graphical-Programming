// SKELETON CODE
// BASE CODE for D3D, WINDOWS (FFP>OpenGL) and OpenGL(PP)

// Windows header files
#include <windows.h>
#include <stdlib.h> // For exit()
#include <stdio.h>	// For FileIO

#include <d3d11.h> // D3D related header files
#include <d3dcompiler.h>

#pragma warning(disable : 4838)	 // Suppressing warning number 4838 for below header file
#include "XNAMath_204/xnamath.h" //Math Library
#include "D3D.h"				 // User defined header file

#pragma comment(lib, "d3d11.lib")		// D3D related liabriries
#pragma comment(lib, "d3dcompiler.lib") // D3D related liabriries

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

ID3D11VertexShader *gpID3D11VertexShader = NULL;
ID3D11PixelShader *gpID3D11PixelShader = NULL;
ID3D11InputLayout *gpID3D11InputLayout = NULL;
ID3D11Buffer *gpID3D11Buffer_PositionBuffer = NULL;
ID3D11Buffer *gpID3D11Buffer_ConstantBuffer = NULL;

struct CBUFFER
{
	XMMATRIX worldViewProjectionMatrix;
};

XMMATRIX orthographicProjectionMatrix;

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

	// HLSL
	// Vertex Shader
	const char *vertexShaderSourceCode =
		"cbuffer ConstantBuffer \n"
		"{\n"
		"float4x4 worldViewProjectionMatrix; \n"
		"}\n"
		"float4 main(float4 pos:POSITION):SV_POSITION \n"
		"{\n"
		"float4 position = mul(worldViewProjectionMatrix,pos);\n"
		"return (position);\n"
		"}\n";

	ID3DBlob *pID3DBlob_VertexShaderSourceCode = NULL;
	ID3DBlob *pID3DBlob_Error = NULL;

	// Compile above shader
	hr = D3DCompile(vertexShaderSourceCode,
					lstrlenA(vertexShaderSourceCode) + 1,
					"VS", // Vertex Shader
					NULL,
					D3D_COMPILE_STANDARD_FILE_INCLUDE,
					"main",
					"vs_5_0",
					0,
					0,
					&pID3DBlob_VertexShaderSourceCode,
					&pID3DBlob_Error);

	if (FAILED(hr))
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "Vertex Shader Compilation Error = %s\n", (char *)pID3DBlob_Error->GetBufferPointer());
		fclose(gpFile);
		return hr;
	}
	else
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "Vertex Shader Compilation Success\n");
		fclose(gpFile);
	}

	// Create Vertex SHader from above code
	hr = gpID3D11Device->CreateVertexShader((void *)pID3DBlob_VertexShaderSourceCode->GetBufferPointer(),
											pID3DBlob_VertexShaderSourceCode->GetBufferSize(),
											NULL,
											&gpID3D11VertexShader);

	if (FAILED(hr))
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "Create Vertex Shader Failed\n");
		fclose(gpFile);
		return hr;
	}
	else
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "Create Vertex Shader Success\n");
		fclose(gpFile);
	}

	// Set above created Vertex shader into pipeline
	gpID3D11DeviceContext->VSSetShader(gpID3D11VertexShader,
									   NULL,
									   0);

	// Pixel Shader
	const char *pixelShaderSourceCode =
		"float4 main(void):SV_TARGET \n"
		"{\n"
		"float4 color = float4(1.0f, 1.0f, 1.0f, 1.0f); \n"
		"return (color); \n"
		"}\n";

	ID3DBlob *pID3DBlob_PixelShaderSourceCode = NULL;
	pID3DBlob_Error = NULL;

	// Compile above shader
	hr = D3DCompile(pixelShaderSourceCode,
					lstrlenA(pixelShaderSourceCode) + 1,
					"PS", // Pixel Shader
					NULL,
					D3D_COMPILE_STANDARD_FILE_INCLUDE,
					"main",
					"ps_5_0",
					0,
					0,
					&pID3DBlob_PixelShaderSourceCode,
					&pID3DBlob_Error);

	if (FAILED(hr))
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "Pixel Shader Compilation Error = %s\n", (char *)pID3DBlob_Error->GetBufferPointer());
		fclose(gpFile);
		return hr;
	}
	else
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "Pixel Shader Compilation Success\n");
		fclose(gpFile);
	}

	// Create the Pixel shader from above code
	hr = gpID3D11Device->CreatePixelShader((void *)pID3DBlob_PixelShaderSourceCode->GetBufferPointer(),
										   pID3DBlob_PixelShaderSourceCode->GetBufferSize(),
										   NULL,
										   &gpID3D11PixelShader);

	if (FAILED(hr))
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "Create Pixel Shader Failed\n");
		fclose(gpFile);
		return hr;
	}
	else
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "Create Pixel Shader Success\n");
		fclose(gpFile);
	}

	// Set above created Pixel shader into pipeline
	gpID3D11DeviceContext->PSSetShader(gpID3D11PixelShader,
									   NULL,
									   0);

	// Release Error Blob
	if (pID3DBlob_Error)
	{
		pID3DBlob_Error->Release();
		pID3DBlob_Error = NULL;
	}
	// Release Pixel Shader Blob
	if (pID3DBlob_PixelShaderSourceCode)
	{
		pID3DBlob_PixelShaderSourceCode->Release();
		pID3DBlob_PixelShaderSourceCode = NULL;
	}

	// Initialize input element structure
	D3D11_INPUT_ELEMENT_DESC d3dInputElementDesc;
	ZeroMemory((void *)&d3dInputElementDesc, sizeof(d3dInputElementDesc));

	d3dInputElementDesc.SemanticName = "POSITION";
	d3dInputElementDesc.SemanticIndex = 0;
	d3dInputElementDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	d3dInputElementDesc.InputSlot = 0;
	d3dInputElementDesc.AlignedByteOffset = 0;
	d3dInputElementDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	d3dInputElementDesc.InstanceDataStepRate = 0;

	// Input Layout
	hr = gpID3D11Device->CreateInputLayout(&d3dInputElementDesc,
										   1,
										   pID3DBlob_VertexShaderSourceCode->GetBufferPointer(),
										   pID3DBlob_VertexShaderSourceCode->GetBufferSize(),
										   &gpID3D11InputLayout);

	if (FAILED(hr))
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "Create Input Layout Failed\n");
		fclose(gpFile);
		return hr;
	}
	else
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "Create Input Layout Success\n");
		fclose(gpFile);
	}

	// Set above created Input Layout into pipeline
	gpID3D11DeviceContext->IASetInputLayout(gpID3D11InputLayout);

	// Release Vertex Shader Source Code Blob
	if (pID3DBlob_VertexShaderSourceCode)
	{
		pID3DBlob_VertexShaderSourceCode->Release();
		pID3DBlob_VertexShaderSourceCode = NULL;
	}

	// Declare triangle geomerty
	const float triangle_position[] = {
		0.0f, 50.0f, 0.0f,
		50.0f, -50.0f, 0.0f,
		-50.0f, -50.0f, 0.0f};

	// Create Vertex buffer for above triagle position
	D3D11_BUFFER_DESC d3d11BufferDesc;
	ZeroMemory((void *)&d3d11BufferDesc, sizeof(d3d11BufferDesc));

	d3d11BufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	d3d11BufferDesc.ByteWidth = sizeof(triangle_position);
	d3d11BufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	d3d11BufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	// Create Vertex buffer using above structure
	hr = gpID3D11Device->CreateBuffer(&d3d11BufferDesc,
									  NULL,
									  &gpID3D11Buffer_PositionBuffer);

	if (FAILED(hr))
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "Vertex buffer Failed\n");
		fclose(gpFile);
		return hr;
	}
	else
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "Vertex buffer Success\n");
		fclose(gpFile);
	}
	// Set above buffer in pipelin in "display" cuzit is dynamic

	// Copy manually vertex/ position data from CPU buffer to GPU Buffer

	D3D11_MAPPED_SUBRESOURCE d3d11MappedSubresource;
	ZeroMemory((void *)&d3d11MappedSubresource, sizeof(D3D11_MAPPED_SUBRESOURCE));

	// Map our position buffer with above resource
	gpID3D11DeviceContext->Map(gpID3D11Buffer_PositionBuffer,
							   0,
							   D3D11_MAP_WRITE_DISCARD,
							   0,
							   &d3d11MappedSubresource);
	// Now copy actual data
	memcpy(d3d11MappedSubresource.pData, triangle_position, sizeof(triangle_position));
	gpID3D11DeviceContext->Unmap(gpID3D11Buffer_PositionBuffer, 0);

	// Create constant buffer to send transformation like uniform data

	ZeroMemory((void *)&d3d11BufferDesc, sizeof(d3d11BufferDesc));

	d3d11BufferDesc.Usage = D3D11_USAGE_DEFAULT;
	d3d11BufferDesc.ByteWidth = sizeof(CBUFFER);
	d3d11BufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

	// Create Vertex buffer using above structure
	hr = gpID3D11Device->CreateBuffer(&d3d11BufferDesc,
									  NULL,
									  &gpID3D11Buffer_ConstantBuffer);

	if (FAILED(hr))
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "Create constant buffer Failed\n");
		fclose(gpFile);
		return hr;
	}
	else
	{
		fopen_s(&gpFile, gszLogFileName, "a+");
		fprintf(gpFile, "Create constant buffer Success\n");
		fclose(gpFile);
	}
	// Set above buffer into pipeline
	gpID3D11DeviceContext->VSSetConstantBuffers(0,
												1,
												&gpID3D11Buffer_ConstantBuffer);
	// Define Clear Color
	clearColor[0] = 0.0f;
	clearColor[1] = 0.0f;
	clearColor[2] = 1.0f;
	clearColor[3] = 1.0f;

	// Orthographic Projection matrix
	orthographicProjectionMatrix = XMMatrixIdentity();

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
									DXGI_FORMAT_R8G8B8A8_UNORM,
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

	// Initialise OrthoGraphic Matrix
	if (width <= height)
	{
		orthographicProjectionMatrix = XMMatrixOrthographicOffCenterLH(-100.0f,
																	   100.0f,
																	   -100.0f * ((float)height / (float)width),
																	   100.0f * ((float)height / (float)width),
																	   -100.0f,
																	   100.0f);
	}
	else
	{
		orthographicProjectionMatrix = XMMatrixOrthographicOffCenterLH(-100.0f * ((float)width / (float)height),
																	   100.0f * ((float)width / (float)height),
																	   -100.0f,
																	   100.0f,
																	   -100.0f,
																	   100.0f);
	}

	return (hr);
}

void display(void)
{
	// Code

	// Transformations
	XMMATRIX worldMatrix = XMMatrixIdentity();
	XMMATRIX viewMatrix = XMMatrixIdentity();
	XMMATRIX wvpMatrix = worldMatrix * viewMatrix * orthographicProjectionMatrix;

	CBUFFER constantBuffer;
	ZeroMemory((void *)&constantBuffer, sizeof(CBUFFER));

	constantBuffer.worldViewProjectionMatrix = wvpMatrix;

	gpID3D11DeviceContext->UpdateSubresource(gpID3D11Buffer_ConstantBuffer,
											 0,
											 NULL,
											 &constantBuffer,
											 0,
											 0);

	// Clear Render Target View using clear color

	// Set Position Buffer into the pipeline here
	UINT stride = sizeof(float) * 3;
	UINT offset = 0;

	gpID3D11DeviceContext->IASetVertexBuffers(0,
											  1,
											  &gpID3D11Buffer_PositionBuffer,
											  &stride,
											  &offset);
	// Set Primitive Geometry
	gpID3D11DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// draw the Geometry
	gpID3D11DeviceContext->Draw(3, 0);

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

	if (gpID3D11Buffer_ConstantBuffer)
	{
		gpID3D11Buffer_ConstantBuffer->Release();
		gpID3D11Buffer_ConstantBuffer = NULL;
	}

	if (gpID3D11Buffer_PositionBuffer)
	{
		gpID3D11Buffer_PositionBuffer->Release();
		gpID3D11Buffer_PositionBuffer = NULL;
	}

	if (gpID3D11InputLayout)
	{
		gpID3D11InputLayout->Release();
		gpID3D11InputLayout = NULL;
	}

	if (gpID3D11PixelShader)
	{
		gpID3D11PixelShader->Release();
		gpID3D11PixelShader = NULL;
	}

	if (gpID3D11VertexShader)
	{
		gpID3D11VertexShader->Release();
		gpID3D11VertexShader = NULL;
	}

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
