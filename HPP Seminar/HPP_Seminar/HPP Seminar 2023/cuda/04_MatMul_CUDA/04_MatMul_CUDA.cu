

#include <stdio.h>
#include <cuda.h>

#include "helper_timer.h"

//Macros

#define BLOCK_WIDTH 32

//const int iNumberOfArrayElements = 5;
//const int iNumberOfArrayElements = 11444777;
//const int iNumberOfArrayElements = 100;

int *hostA = NULL;
int *hostB = NULL;
int *hostC = NULL;
int *gold = NULL;

int *deviceA = NULL;
int *deviceB = NULL;
int *deviceC = NULL;

float timeOnCPU = 0.0f;
float timeOnGPU = 0.0f;

// CUDA kernel
__global__ void matMulGPU(int* A, int* B, int* C, int numARows,int numAColumns,int numBColumns,int numCColumns)
{
	//variable declarations
	int row = blockIdx.y * blockDim.y + threadIdx.y;
	int column = blockIdx.x * blockDim.x + threadIdx.x;

	// code
	if ((row < numARows) && column < numAColumns)
	{
		int value = 0.0;
		for (int k = 0; k < numAColumns; k++)
		{
			int a = A[row * numAColumns + k];
			int b = B[k * numBColumns + column];
			value += a * b;
		}
		C[row * numCColumns + column] = value;
	}
}

// entry-point function
int main(void)
{
	// function declarations
	void InitA(int* data, int, int);
	void InitB(int* data, int, int);
	void matMulCPU(int*, int*, int*, int, int, int, int);
	void cleanup(void);

	// variable declarations

	int numARows = BLOCK_WIDTH;
	int numAColumns = BLOCK_WIDTH;
	int numBRows = BLOCK_WIDTH;
	int numBColumns = BLOCK_WIDTH;

	int numCRows = numARows;
	int numCColumns = numBColumns;
	int numGoldRows = numARows;
	int numGoldColumns = numBColumns;

	int sizeA = numARows * numAColumns * sizeof(int);
	int sizeB = numBRows * numBColumns * sizeof(int);
	int sizeC = numCRows * numCColumns * sizeof(int); 

	int sizeGold = numGoldRows * numGoldColumns * sizeof(int);

	cudaError_t result = cudaSuccess;

	// code

    // host memory allocation
	hostA = (int*)malloc(sizeA);
	if (hostA == NULL)
	{
		printf("SUM: Host Memory allocation is Failed For hostA array");
		cleanup();
		exit(EXIT_FAILURE);
	}

	hostB = (int*)malloc(sizeB);
	if (hostB == NULL)
	{
		printf("SUM: Host Memory allocation is Failed For hostB array");
		cleanup();
		exit(EXIT_FAILURE);
	}
	
	hostC = (int*)malloc(sizeC);
	if (hostC == NULL)
	{
		printf("SUM: Host Memory allocation is Failed For hostC array");
		cleanup();
		exit(EXIT_FAILURE);
	}

	gold = (int*)malloc(sizeGold);
	if (gold == NULL)
	{
		printf("SUM: Host Memory allocation is Failed For gold array");
		cleanup();
		exit(EXIT_FAILURE);
	}
	
	//printing matrix dimensions and sizes
	printf("SUM Output: The Dimensions Of Matrix 'hostA' Are : %d x %d\n", numARows, numAColumns);

	printf("SUM Output: The Dimensions Of Matrix 'hostB' Are : %d x %d\n", numBRows, numBColumns);

	printf("SUM Output: The Dimensions Of Matrix 'hostC' Are : %d x %d\n", numCRows, numCColumns);

	printf("SUM Output: The Dimensions Of Matrix 'gold' Are : %d x %d\n", numGoldRows, numGoldColumns);

	printf("SUM Output: Size of Matrix hostA = %d\n", sizeA);

	printf("SUM Output: Size of Matrix hostB = %d\n", sizeB);

	printf("SUM Output: Size of Matrix hostC = %d\n", sizeC);

	printf("SUM Output: Size of Matrix hostGold = %d\n", sizeGold);

	//Fill source matrices

	InitA(hostA, numARows, numAColumns);
	InitB(hostB, numBRows, numBColumns);

	 // device memory allocation
	  result = cudaMalloc((void**)&deviceA, sizeA);
	  if (result != cudaSuccess)
	  {
		  printf("SUM: Device Memory allocation is failed	for deviceA array\n");
		  cleanup();
		  exit(EXIT_FAILURE);
	  }

	  result = cudaMalloc((void**)&deviceB, sizeB);
	  if (result != cudaSuccess)
	  {
		  printf("SUM: Device Memory allocation is failed	for deviceB.\n");
		  cleanup();
		  exit(EXIT_FAILURE);
	  }

	  result = cudaMalloc((void**)&deviceC, sizeC);
	  if (result != cudaSuccess)
	  {
		  printf("SUM: Device Memory allocation is failed	for deviceC array.\n");
		  cleanup();
		  exit(EXIT_FAILURE);
	  }
	  
	  //Copy data from host arrays into device arrays
	  result = cudaMemcpy(deviceA, hostA, sizeA, cudaMemcpyHostToDevice);
	  if (result != cudaSuccess)
	  {
		  printf("SUM: Host to Device Data copy is Failed for DeviceA array.\n");
		  cleanup();
		  exit(EXIT_FAILURE);
	  }

	  result = cudaMemcpy(deviceB, hostB, sizeB, cudaMemcpyHostToDevice);
	  if (result != cudaSuccess)
	  {
		  printf("SUM: Host to Device Data copy is Failed for DeviceInput2 array.\n");
		  cleanup();
		  exit(EXIT_FAILURE);
	  }

	  //CUDA Kernel Configuration
	  dim3 dimGrid = dim3(ceil((int)numBColumns / (int)BLOCK_WIDTH), ceil((int)numARows / (int)BLOCK_WIDTH), 1);

	  dim3 dimBlock = dim3(BLOCK_WIDTH,BLOCK_WIDTH,1);

	  //CUDA Kernel for Vector Addition
	  StopWatchInterface* timer = NULL;
	  sdkCreateTimer(&timer);
	  sdkStartTimer(&timer);


	  // CUDA kernel for Vector Addition
	  matMulGPU <<<dimGrid, dimBlock >>> (deviceA, deviceB,
		  deviceC, numARows,numAColumns,numBColumns,numCColumns);

	  sdkStopTimer(&timer);
	  timeOnGPU = sdkGetTimerValue(&timer);
	  sdkDeleteTimer(&timer);
	  timer = NULL;

	  // copy data from device matrix into host matrix
	  result = cudaMemcpy(hostC, deviceC, sizeC,
		  cudaMemcpyDeviceToHost);

	  if (result != cudaSuccess)
	  {
		  printf("SUM: Device to Host Data Copy is failed for hostC Matrix.\n");
		  cleanup();
		  exit(EXIT_FAILURE);
	  }

	  //Matrix Multiplication on host
	  matMulCPU(hostA, hostB, gold, numARows,numAColumns,numBColumns,numCColumns);

	  //Comparison

	  //const float epsilon = 0.000001f;
	  int breakValue = -1;
	  bool bAccuracy = true;

	  for (int i = 0; i < numCRows; i++)
	  {
		  float val1 = gold[i];
		  float val2 = hostC[i];

		  if (val1 != val2)
		  {
			  bAccuracy = false;
			  breakValue = i;
			  break;
		  }
	  }

	  char str[128];
	  if (bAccuracy == false)
		  sprintf(str, "SUM Output: Comparison of CPU and GPU Matrix Multiplication is not within accuracy of 0.000001 at array  index %d", breakValue);
	  else
		  sprintf(str, "SUM Output: Comparison of CPU and GPU Matrix Multiplication is within accuracy  of 0.000001");

	  printf("SUM Output: Time Taken for Matrix Multiplication on CPU = %.6f\n\n", timeOnCPU);
	  
	  printf("SUM Output: Time Taken for Matrix Multiplication on GPU = %.6f\n\n", timeOnGPU);
	  printf("%s\n", str);


	  //Cleanup
	  cleanup();

	  return(0);
}

void InitA(int* data, int row,int col)
{
	int num = 1;
	//code
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			*(data + i * col + j) = num;
			num++;
		}
	}
}

void InitB(int* data, int row, int col)
{
	int num = BLOCK_WIDTH;
	//code
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			*(data + i * col + j) = num;
			num--;
		}
	}
}

void matMulCPU( int *A, int* B, int* C,int numARows,int numAColumns,int numBColumns,int numCColumns)
{
	//code
	StopWatchInterface* timer = NULL;
	sdkCreateTimer(&timer);
	sdkStartTimer(&timer);

	for (int i = 0; i < numARows; ++i)
	{
		for (int j = 0; j < numBColumns; ++j)
		{
			int value = 0.0f;
			for (int k = 0; k < numAColumns; ++k)
			{
				int a = A[i * numAColumns + k];
				int b = B[k * numBColumns + j];
				value += a * b;
			}
			C[i * numCColumns + j] = value;
		}
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

	if (deviceC)
	{
		cudaFree(deviceC);
		deviceC = NULL;
	}

	if (deviceB)
	{
		cudaFree(deviceB);
		deviceB = NULL;
	}

	if (deviceA)
	{
		cudaFree(deviceA);
		deviceA = NULL;
	}

	if (hostC)
	{
		free(hostC);
		hostC = NULL;
	}

	if (hostB)
	{
		free(hostB);
		hostB = NULL;
	}

	if (hostA)
	{
		free(hostA);
		hostA = NULL;
	}
}