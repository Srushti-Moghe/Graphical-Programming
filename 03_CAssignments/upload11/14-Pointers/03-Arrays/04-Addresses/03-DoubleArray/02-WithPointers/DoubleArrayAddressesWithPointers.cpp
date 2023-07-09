#include <stdio.h>

int main(void)
{
	// Variable Declarations
	double S_dArray[10]; 
	double *ptr_S_dArray = NULL;
	int SUM_i;  
	
	// Code 
	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		S_dArray[SUM_i] = (float)(SUM_i + 1) * 1.555555f;
	}
	// Name of any Array == its Base Address i.e.
	// dArray[] == dArray OR
	// dfArray == dArray[0]
	// Assigning the Base Address of Array 'dArray[]' to an integer pointer 'ptr_dArray'
	
	ptr_S_dArray = S_dArray;  // Equivalent to ptr_S_dArray = &S_dArray[0]

	printf("\n\n");
	printf("Elements of the double Aarray : \n\n"); for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		printf("iArray[%d] = %lf\n", SUM_i, *(ptr_S_dArray + SUM_i));
	}
	printf("\n\n");

	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		printf("iArray[%d] = %lf \t\t Address = %p\n", SUM_i, *(S_dArray + SUM_i), (ptr_S_dArray + SUM_i));
	}
	printf("\n\n");
	
	return(0);
}





