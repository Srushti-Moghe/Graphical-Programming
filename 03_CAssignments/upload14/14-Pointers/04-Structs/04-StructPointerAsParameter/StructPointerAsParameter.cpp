#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>		// [For toupper()] - can take an integer(ASCII value of the character) as an input. If the input is not an integer, it is typecasted internally in the function
#include <conio.h>
#include <string.h>

// Define struct
struct SUM_MyData
{
	int SUM_i;
	float SUM_f;
	double SUM_d;
};

int main(void)
{
	// Function Prototype
	void ChangeValues(struct SUM_MyData*);

	// variable Declarations
	struct SUM_MyData *ptr_SUM_MyData = NULL;
	
	// Code
	printf("\n\n");

	ptr_SUM_MyData = (struct SUM_MyData*)malloc(sizeof(struct SUM_MyData));
	if (ptr_SUM_MyData == NULL)
	{
		printf("Failed to Allocate the memory to 'struct MyData' !!! Exitting Now...\n\n");
		exit(0);
	}	
	else
	{
		printf("Memory allocation to'struct MyData' done Successfully !!!\n\n");
	}
	// Assigning data values to the members of 'struct MyData'
	ptr_SUM_MyData->SUM_i = 50;
	ptr_SUM_MyData->SUM_f = 15.9099f;
	ptr_SUM_MyData->SUM_d = 45.678967986798;

	// Displaying data members of the 'struct MyData'
	printf("\n\n");
	printf("Data members of 'struct MyData' are : \n\n");
	printf("Integer Member 'i'         : %d\n", ptr_SUM_MyData->SUM_i);
	printf("Floating-Point Member 'f'  : %f\n", ptr_SUM_MyData->SUM_f);
	printf("Double Member 'd'          : %lf\n", ptr_SUM_MyData->SUM_d);

	printf("\n\n");
	if (ptr_SUM_MyData)
	{
		free(ptr_SUM_MyData);
		ptr_SUM_MyData = NULL;
		printf("Memory allocated to'struct MyData' has been successfully Freed!!!\n\n");
	}
	return(0);
}

void ChangeValues(struct SUM_MyData *pParam_Data)
{
	// Code
	pParam_Data->SUM_i = 90;
	pParam_Data->SUM_f = 12.1313f;
	pParam_Data->SUM_d = 55.9099990090;

	return;
}






