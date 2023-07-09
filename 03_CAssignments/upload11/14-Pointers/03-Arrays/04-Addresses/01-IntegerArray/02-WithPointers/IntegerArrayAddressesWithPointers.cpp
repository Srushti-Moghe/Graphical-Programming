#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int S_iArray[10]; 
	int *ptr_S_iArray = NULL;
	int SUM_i;  
	
	// Code 
	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		S_iArray[SUM_i] = (SUM_i + 1) * 3;
	}
	// Name of any Array == its Base Address i.e.
	// iArray[] == iArray OR
	// iArray == iArray[0]
	// Assigning the Base Address of Array 'iArray[]' to an integer pointer 'ptr_iArray'
	
	ptr_S_iArray = S_iArray;  // Equivalent to ptr_S_iArray = &S_iArray[0]

	printf("\n\n");
	printf("Elements of the Integer Aarray : \n\n"); for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		printf("iArray[%d] = %d\n", SUM_i, *(ptr_S_iArray + SUM_i));
	}
	printf("\n\n");

	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		printf("iArray[%d] = %d \t\t Address = %p\n", SUM_i, *(S_iArray + SUM_i), (ptr_S_iArray + SUM_i));
	}
	printf("\n\n");
	
	return(0);
}



