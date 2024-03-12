#include <stdio.h>
#include <stdlib.h>
#include <CL/opencl.h>

int main()
{
	cl_platform_id cid;
	cl_uint count;
	char info[512];

	clGetPlatformIDs(1, &cid, NULL);
	clGetDeviceIDs(cid, CL_DEVICE_TYPE_CPU, 0, NULL, &count);

	clGetPlatformInfo(cid, CL_PLATFORM_NAME, 500, &info, NULL);
	printf("OpenCL supporting GPU Platform name %s\n", info);

	clGetPlatformInfo(cid, CL_PLATFORM_VERSION, 500, &info, NULL);
	printf("OpenCL supporting GPU Platform version %s\n", info);

	printf("Number of OpenCL supporting Device %d\n", count);

	return(0);
}

// build
// cl.exe test.cpp /I "C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.2\include" /link /LIBPATH:"C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.2\lib\x64" OpenCL.lib /OUT:"test.exe"
