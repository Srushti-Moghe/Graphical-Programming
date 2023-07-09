#include <stdio.h>

int main(void)
{
	// Variable Declarations
	float S_fArray[10]; 
	float *ptr_S_fArray = NULL;
	int SUM_i;  
	
	// Code 
	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		S_fArray[SUM_i] = (float)(SUM_i + 1) * 1.5f;
	}
	// Name of any Array == its Base Address i.e.
	// fArray[] == fArray OR
	// fArray == fArray[0]
	// Assigning the Base Address of Array 'fArray[]' to an integer pointer 'ptr_fArray'
	
	ptr_S_fArray = S_fArray;  // Equivalent to ptr_S_fArray = &S_fArray[0]

	printf("\n\n");
	printf("Elements of the Float Aarray : \n\n"); for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		printf("iArray[%d] = %f\n", SUM_i, *(ptr_S_fArray + SUM_i));
	}
	printf("\n\n");

	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		printf("iArray[%d] = %f \t\t Address = %p\n", SUM_i, *(S_fArray + SUM_i), (ptr_S_fArray + SUM_i));
	}
	printf("\n\n");
	
	return(0);
}



