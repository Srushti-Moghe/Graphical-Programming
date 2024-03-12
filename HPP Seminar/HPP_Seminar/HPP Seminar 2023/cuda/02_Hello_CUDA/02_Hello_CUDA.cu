#include <stdio.h>
#include <cuda.h>

const int iNumberOfArrayElements = 5;

float* hostInput1 = NULL;
float* hostInput2 = NULL;
float* hostOutput = NULL;

float* deviceInput1 = NULL;
float* deviceInput2 = NULL;
float* deviceOutput = NULL;

// CUDA kernel
__global__ void vecAddGPU(float* in1, float* in2, float* out, int len)
{
// Code
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < len)
	{
		out[i] = in1[i] + in2[i];
	}
}

// Entry-point Function
int main(void)
{
	// Function Declarations

	void cleanup(void);

	// Variable Declarations

	int size = iNumberOfArrayElements * sizeof(float);

	cudaError_t result = cudaSuccess;

	// code

// host memory allocation

	hostInput1 = (float*)malloc(size);
	if (hostInput1 == NULL)
	{
		printf("SUM: Host Memory allocation is Failed For hostInput1 array");
		cleanup();
		exit(EXIT_FAILURE);
	}

	hostInput2 = (float*)malloc(size);
	if (hostInput2 == NULL)
	{
		printf("SUM: Host Memory allocation is Failed For hostInput2 array");
		cleanup();
		exit(EXIT_FAILURE);
	}
	
	hostOutput = (float*)malloc(size);
	if (hostOutput == NULL)
	{
		printf("SUM: Host Memory allocation is Failed For hostOutput array");
		cleanup();
		exit(EXIT_FAILURE);
	}

	 // filling values into host arrays
	 hostInput1[0] = 501.0;
	 hostInput1[1] = 502.0;
	 hostInput1[2] = 503.0;
	 hostInput1[3] = 504.0;
	 hostInput1[4] = 505.0;
	
	 hostInput2[0] = 101.0;
	 hostInput2[1] = 102.0;
	 hostInput2[2] = 103.0;
	 hostInput2[3] = 104.0;
	 hostInput2[4] = 105.0;

	 // device memory allocation
	  result = cudaMalloc((void**)&deviceInput1, size);
	  if (result != cudaSuccess)
	  {
		  printf("SUM: Device Memory allocation isfailed	for deviceInput1 array\n");
		  cleanup();
		  exit(EXIT_FAILURE);
	  }

	  result = cudaMalloc((void**)&deviceInput2, size);
	  if (result != cudaSuccess)
	  {
		  printf("SUM: Device Memory allocation isfailed	for deviceInput12array.\n");
		  cleanup();
		  exit(EXIT_FAILURE);
	  }

	  result = cudaMalloc((void**)&deviceOutput, size);
	  if (result != cudaSuccess)
	  {
		  printf("SUM: Device Memory allocation isfailed	for deviceOutput array.\n");
		  cleanup();
		  exit(EXIT_FAILURE);
	  }
	  
	  //Copy data from host arrays into device arrays
	  result = cudaMemcpy(deviceInput1, hostInput1, size, cudaMemcpyHostToDevice);
	  if (result != cudaSuccess)
	  {
		  printf("SUM: Host to Device Data copy is Failed for DeviceInput1 array.\n");
		  cleanup();
		  exit(EXIT_FAILURE);
	  }

	  result = cudaMemcpy(deviceInput2, hostInput2, size, cudaMemcpyHostToDevice);
	  if (result != cudaSuccess)
	  {
		  printf("SUM: Host to Device Data copy is Failed for DeviceInput2 array.\n");
		  cleanup();
		  exit(EXIT_FAILURE);
	  }

	  dim3 dimGrid = dim3(iNumberOfArrayElements, 1, 1);
	  dim3 dimBlock = dim3(1, 1, 1);

	  // CUDA kernel for Vector Addition
	  vecAddGPU <<<dimGrid, dimBlock >>> (deviceInput1, deviceInput2,
		  deviceOutput, iNumberOfArrayElements);

	  // copy data from device array into host array
	  result = cudaMemcpy(hostOutput, deviceOutput, size,
		  cudaMemcpyDeviceToHost);

	  if (result != cudaSuccess)

	  {
		  printf("SUM: Device to Host Data Copy is failed for hostOutput array.\n");
		  cleanup();
		  exit(EXIT_FAILURE);

	  }

	  //Vector addition on host
	  for (int i = 0; i < iNumberOfArrayElements; i++)
	  {
		  printf("SUM Output : %f + %f = %f\n", hostInput1[i], hostInput2[i], hostOutput[i]);
	  }

	  //Cleanup
	  cleanup();

	  return(0);
}

void cleanup(void)
{
	//code
	if (deviceOutput)
	{
		cudaFree(deviceOutput);
		deviceOutput = NULL;
	}

	if (deviceInput2)
	{
		cudaFree(deviceInput2);
		deviceInput2 = NULL;
	}

	if (deviceInput1)
	{
		cudaFree(deviceInput1);
		deviceInput1 = NULL;
	}

	if (hostOutput)
	{
		free(hostOutput);
		hostOutput = NULL;
	}

	if (hostInput2)
	{
		free(hostInput2);
		hostInput2 = NULL;
	}

	if (hostInput1)
	{
		free(hostInput1);
		hostInput1 = NULL;
	}
}