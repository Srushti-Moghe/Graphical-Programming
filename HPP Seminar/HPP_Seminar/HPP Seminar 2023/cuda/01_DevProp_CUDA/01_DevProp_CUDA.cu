#include<stdio.h>
#include<cuda.h>

int main(void)
{
	//Function Declarations
	void PrintCUDADeviceProperties(void);

	//code
	PrintCUDADeviceProperties();
}

void PrintCUDADeviceProperties(void)
{
	//code
	printf("Srushti Moghe CUDA Information : \n");
	printf("------------------------\n");

	printf("CUDA Information : \n");
	printf("******============******\n");

	cudaError_t ret_cuda_rt;
	int dev_count;
	ret_cuda_rt = cudaGetDeviceCount(&dev_count);
	if (ret_cuda_rt != cudaSuccess)
	{
		printf("CUDA Runtime API Error - cudaGetDeviceCount() Failed due to %s.\n", cudaGetErrorString(ret_cuda_rt));
	}
	else if (dev_count == 0)
	{
		printf("There is no CUDA Supported Device On This System.\n");
		return;
	}
	else
	{

		printf("Total Number Of CUDA Supporting GPU Device/Devices On This System : %d\n", dev_count);

		for (int i = 0; i < dev_count; i++)
		{
			cudaDeviceProp dev_prop;
			int driverVersion = 0, runtimeVersion = 0;
			ret_cuda_rt = cudaGetDeviceProperties(&dev_prop, i);
			if (ret_cuda_rt != cudaSuccess)
			{
				printf("%s in %s at line %d\n", cudaGetErrorString(ret_cuda_rt), __FILE__, __LINE__);
				return;
			}
			printf("\n");
			cudaDriverGetVersion(&driverVersion);
			cudaRuntimeGetVersion(&runtimeVersion);
			printf("********** CUDA DRIVER and RUNTIME INFORMATION **********\n\n");
			printf("======================================================================================================\n\n");
			printf("SUM CUDA Driver Version          :%d.%d\n", driverVersion / 1000, (driverVersion % 100) / 10);
			printf("SUM CUDA Runtime Version         :%d.%d\n", runtimeVersion / 1000, (runtimeVersion / 100) / 10);
			printf("\n");
			printf("======================================================================================================\n\n");
			printf("********** GPU DEVICE GENERAL INFORMATION **********\n\n");
			printf("======================================================================================================\n\n");
			printf("SUM GPU Device Number                : %d\n", i);
			printf("SUM GPU Device Name                  : %s\n", dev_prop.name);
			printf("SUM GPU Device Compute Capability    :%d.%d\n", dev_prop.major, dev_prop.minor);
			printf("SUM GPU Device Clock rate            :%d\n", dev_prop.clockRate);

			printf("SUM GPU Device Type                  :\n");
			if (dev_prop.integrated)
				printf("Integrated   (On - Board)        :\n");
			else
				printf("Discrete (Card)                  :\n");

			printf("\n");

			printf("********** GPU DEVICE MEMORY INFORMATION **********\n\n");
			printf("======================================================================================================\n\n");
			printf("SUM GPU Device Total Memory						 :  %.0f GB  = %.0f MB == %llu Bytes\n", ((float)dev_prop.totalGlobalMem / 1048576.0f) / 1024.0f, (float)dev_prop.totalGlobalMem / 1048576.0f, (unsigned long long)dev_prop.totalGlobalMem);

			printf("SUM GPU Device Constant Memory                   : %lu Bytes \n", (unsigned long)dev_prop.totalConstMem);
			printf("SUM GPU Device Shared Memory per SMProcessor     : %lu Bytes \n", (unsigned long)dev_prop.sharedMemPerBlock);
			printf("\n");

			printf("**************GPU DEVICE MULTIPROCESSOR INFORMATION ******************\n");
			printf("======================================================================================================\n\n");

			printf("SUM GPU Device Number of SMProcessors                  : %lu Bytes \n", dev_prop.multiProcessorCount);
			printf("SUM GPU Device Number Of Registers Per SMProcessor     : %lu Bytes \n", (unsigned long)dev_prop.regsPerBlock);

			printf("\n");

			printf("************************  GPU DEVICE THREAD INFORMATION  ***********************\n");
			printf("======================================================================================================\n\n");

			printf("SUM GPU Device Maximum Number Of Threads Per SMProcessor : %d\n", dev_prop.maxThreadsPerMultiProcessor);
			printf("SUM GPU Device Maximum Number Of Threads Per Block       :%d\n", dev_prop.maxThreadsPerBlock);

			printf("SUM GPU Device Threads In Warp                           : %d\n", dev_prop.warpSize);

			printf("SUM GPU Device Maximum Thread Dimensions                 : (%d, %d, %d) \n", dev_prop.maxThreadsDim[0], dev_prop.maxThreadsDim[1], dev_prop.maxThreadsDim[2]);

			printf("SUM GPU Device Maximum Grid Dimensions                   : (%d, %d, %d) \n", dev_prop.maxGridSize[0], dev_prop.maxGridSize[1], dev_prop.maxGridSize[2]);

			printf("\n");

			printf("======================================================================================================\n\n");
			printf("*************************GPU DEVICE DRIVER INFORMATION ********************\n");
			printf("======================================================================================================\n\n");
			printf("SUM GPU Device has ECC support				  : %s\n", dev_prop.ECCEnabled ? "Enabled" : "Disabled");

#if defined (WIN32) || defined(_WIN32) || defined(WIN64) || defined( WINE64)
			printf("SUM GPU Device CUDA Driver mode (TCC Or WDDM) :%s \n", dev_prop.tccDriver ? "TCC (Tesla Compute Cluster Driver)" : "WDDM (Windows Display Driver Model)\n");

#endif
			printf("************************************************** END ******************************************************\n\n");
		}
	}
}