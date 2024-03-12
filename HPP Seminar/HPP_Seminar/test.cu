#include <stdio.h>
#include <cuda.h>

int main(void)
{
	cudaDeviceProp pCuda;
	int count;

	cudaGetDeviceCount(&count);

	for (int i = 0; i < count; i++)
	{
		cudaGetDeviceProperties(&pCuda, i);
			printf("Name %s\n", pCuda.name);
			printf("computeCapability %d .%d\n", pCuda.major, pCuda.minor);
	}
	return(0);
}
// build
// nvcc


