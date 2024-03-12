
#include <stdio.h>
#include <cuda.h>

#include "helper_timer.h"


// const int iNumberOfArrayElements = 5;

// const int iNumberOfArrayElements = 11444777;
const int iNumberOfArrayElements = 100;


float* hostInput1 = NULL;
float* hostInput2 = NULL;
float* hostOutput = NULL;
float* gold = NULL;

float* deviceInput1 = NULL;
float* deviceInput2 = NULL;
float* deviceOutput = NULL;

float timeOnCPU = 0.0f;
float timeOnGPU = 0.0f;

// CUDA kernel
__global__ void vecAddGPU(float* in1, float* in2, float* out, int len)

{
	// code
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < len)
	{
		out[i] = in1[i] + in2[i];
	}
}

// entry-point function
int main(void)
{
	// function declarations
	void fillFloatArrayWithRandomNumbers(float*, int);
	void vecAddCPU(const float*, const float*, float*, int);
	void cleanup(void);

	// variable declarations
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

	gold = (float*)malloc(size);
	if (gold == NULL)
	{
		printf("SUM: Host Memory allocation is Failed For gold array");
		cleanup();
		exit(EXIT_FAILURE);
	}
	
	// Filling value into host arrays

	fillFloatArrayWithRandomNumbers(hostInput1, iNumberOfArrayElements);
	fillFloatArrayWithRandomNumbers(hostInput2, iNumberOfArrayElements);


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
	  
	  // Copy data from host arrays into device arrays
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

	  // CUDA Kernel Configuration
	  dim3 dimGrid = dim3((int)ceil((float)iNumberOfArrayElements / 256.0f), 1, 1);


	  dim3 dimBlock = dim3(256, 1, 1);

	  // CUDA Kernel for Vector Addition
	  StopWatchInterface* timer = NULL;
	  sdkCreateTimer(&timer);
	  sdkStartTimer(&timer);


	  // CUDA kernel for Vector Addition
	  vecAddGPU <<<dimGrid, dimBlock >>> (deviceInput1, deviceInput2,
		  deviceOutput, iNumberOfArrayElements);

	  sdkStopTimer(&timer);
	  timeOnGPU = sdkGetTimerValue(&timer);
	  sdkDeleteTimer(&timer);
	  timer = NULL;

	  // copy data from device array into host array
	  result = cudaMemcpy(hostOutput, deviceOutput, size,
		  cudaMemcpyDeviceToHost);

	  if (result != cudaSuccess)
	  {
		  printf("SUM: Device to Host Data Copy is failed for hostOutput array.\n");

		  cleanup();
		  exit(EXIT_FAILURE);
	  }

	  // Vector addition on host
	  vecAddCPU(hostInput1, hostInput2, gold, iNumberOfArrayElements);

	  // Comparison

	  const float epsilon = 0.000001f;
	  int breakValue = -1;
	  bool bAccuracy = true;

	  for (int i = 0; i < iNumberOfArrayElements; i++)
	  {
		  float val1 = gold[i];
		  float val2 = hostOutput[i];

		  if (fabs(val1 - val2) > epsilon)
		  {
			  bAccuracy = false;
			  breakValue = i;
			  break;
		  }
	  }

	  char str[128];
	  if (bAccuracy == false)
		  sprintf(str, "Comparison of CPU and GPU Vector Addition is not within accuracy of 0.000001 at array index %d", breakValue);
	  else
		  sprintf(str, "Comparison of CPU and GPU Vector Addition is within accuracy of 0.000001");

	  // output

	  printf("SUM Output: Array1 begins from 0th index %.6f to %dth index %.6f     \n\n", hostInput1[0], iNumberOfArrayElements - 1, hostInput1[iNumberOfArrayElements - 1]);

	  printf("SUM Output: Array2 begins from 0th index %.6f to %dth index %.6f      \n\n", hostInput2[0], iNumberOfArrayElements - 1, hostInput2[iNumberOfArrayElements - 1]);

	  printf("SUM Output: CUDA Kernel Grid dimension = %d,%d,%d and Block Dimension =%d,%d,%d        \n\n", dimGrid.x, dimGrid.y, dimGrid.z, dimBlock.x, dimBlock.y, dimBlock.z);

	  printf("SUM Output: Output Array begins from 0th index %.6f to %dth index %.6f      \n\n", hostOutput[0], iNumberOfArrayElements - 1, hostOutput[iNumberOfArrayElements - 1]);

	  printf("SUM Output: Time Taken for Vector Addition on CPU = %.6f\n\n", timeOnCPU);
	  
	  printf("SUM Output: Time Taken for Vector Addition on GPU = %.6f\n\n", timeOnGPU);
	  printf("%s\n", str);


	  //Cleanup
	  cleanup();

	  return(0);
}

void fillFloatArrayWithRandomNumbers(float* arr, int len)
{
	//code
	const float fscale = 1.0f / (float)RAND_MAX;

	for (int i = 0; i < len; i++)
	{
		arr[i] = fscale * rand();
	}
}

void vecAddCPU(const float* arr1, const float* arr2, float* out, int len)
{
	//code
	StopWatchInterface* timer = NULL;
	sdkCreateTimer(&timer);
	sdkStartTimer(&timer);

	for (int i = 0; i < len; i++)
	{
		out[i] = arr1[i] + arr2[i];
	}

	sdkStopTimer(&timer);
	timeOnCPU = sdkGetTimerValue(&timer);
	sdkDeleteTimer(&timer);
	timer = NULL;
}

void cleanup(void)
{
	//code

	if (gold)
	{
		free(gold);
		gold = NULL;
	}

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