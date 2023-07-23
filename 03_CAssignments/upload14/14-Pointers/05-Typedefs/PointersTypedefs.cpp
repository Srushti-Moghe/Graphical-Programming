#include <stdio.h>
#include <stdlib.h>

// Define struct
struct SUM_MyData
{
	int SUM_i;
	float SUM_f;
	double SUM_d;
};

int main(void)
{
	// variable Declarations
	int SUM_iSize;
	int SUM_fSize;
	int SUM_dSize;
	int struct_SUM_MyData_size;
	int ptr_struct_SUM_MyData_size;

	typedef struct SUM_MyData* SUM_MyData_ptr;
	SUM_MyData_ptr SUM_ptr_Data;

	// Code
	printf("\n\n");

	SUM_ptr_Data = (SUM_MyData_ptr)malloc(sizeof(struct SUM_MyData));
	if (SUM_ptr_Data == NULL)
	{
		printf("Failed to Allocate the memory to 'struct MyData' !!! Exitting Now...\n\n");
		exit(0);
	}
	else
	{
		printf("Memory allocation to'struct MyData' done Successfully !!!\n\n");
	}

	// Assigning data values to the members of 'struct MyData'
	SUM_ptr_Data->SUM_i = 100;
	SUM_ptr_Data->SUM_f = 13.234f;
	SUM_ptr_Data->SUM_d = 85.678967986798;
	
	// Displaying data members of the 'struct MyData'
	printf("\n\n");
	printf("Data members of 'struct MyData' are : \n\n");
	printf("Integer Member 'i'         : %d\n", SUM_ptr_Data->SUM_i);
	printf("Floating-Point Member 'f'  : %f\n", SUM_ptr_Data->SUM_f);
	printf("Double Member 'd'          : %lf\n", SUM_ptr_Data->SUM_d);

	// Calculating the sizes in bytes of the Data Members of 'struct MyData'
	SUM_iSize = sizeof(SUM_ptr_Data->SUM_i);
	SUM_fSize = sizeof(SUM_ptr_Data->SUM_f);
	SUM_dSize = sizeof(SUM_ptr_Data->SUM_d);

	// Displaying sizes in bytes of data members of the 'struct MyData'
	printf("\n\n");
	printf("Size (in bytes) of Data members of 'struct MyData' are : \n\n");
	printf("Size of Integer Member 'i'         : %d\n", SUM_iSize);
	printf("Size of Floating-Point Member 'f'  : %d\n", SUM_fSize);
	printf("Size of Double Member 'd'          : %d\n", SUM_dSize);

	//Calculating sizes in bytes of the 'struct MyData'
	struct_SUM_MyData_size = sizeof(struct SUM_MyData);
	ptr_struct_SUM_MyData_size = sizeof(SUM_MyData_ptr);

	// Displaying sizes in bytes of data members of the 'struct MyData'
	printf("\n\n");
	printf("Size (in bytes) of 'struct MyData'              : %dbytes\n\n", struct_SUM_MyData_size);
	printf("Size (in bytes) of pointer to 'struct MyData'   : %dbytes\n\n", ptr_struct_SUM_MyData_size);

	if (SUM_ptr_Data)
	{
		free(SUM_ptr_Data);
		SUM_ptr_Data = NULL;
		printf("Memory allocated to'struct MyData' has been successfully Freed!!!\n\n");
	}
	return(0);
}






