#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// Variable Declarations
	int* SUM_ptr_iArray = NULL;
	unsigned int S_iArrayLength = 0;
	int SUM_i;

	// Code
	printf("\n\n");
	printf("Enter the number of elements you want in your integer Array : ");
	scanf("%d", &S_iArrayLength);

	// Allocating as much memory required to the integer array
	// memory required for integer Array = size of bytes in one integer * number of integers to be stored in the integer Array
	// To allocate said amount of memory, function malloc() can be used
	// malloc() will allocate said amount of memory and will return the initial / starting / base address of the allocated memory, that can be stored in the pointer variable
	// This initial / starting / base address can be used to access the array

	SUM_ptr_iArray = (int *)malloc(sizeof(int) * S_iArrayLength);

	// If ptr iArray is still NULL, even after the call to malloc(), that means that malloc() has failed to allocate memory and no address has been returned by malloc() in ptr_iArray	if (SUM_ptr_iArray == NULL);
	if (SUM_ptr_iArray == NULL)
	{
		printf("\n\n");
		printf("Memory allocation for integer Array has failed ! Exiting now...\n\n");
		exit(0);
	}
	else    	
	{
		printf("\n\n");
		printf("Memory allocation for integer Array has succeeded !\n\n");
		printf("Memory addresses from %p to %p have been allocated to integer Array !\n\n", SUM_ptr_iArray, (SUM_ptr_iArray + (S_iArrayLength - 1)));
	}
	// If ptr iArray is not NULL, it means that it might contain valid address which is returned by malloc(), hence malloc() has succeeded in memory allocation 
	
	printf("\n\n");
	printf("The integer Array entered by you, consisting of %d elements : \n\n", S_iArrayLength);

	for (SUM_i = 0; SUM_i < S_iArrayLength; SUM_i++)
	{
		scanf("%d", (SUM_ptr_iArray + SUM_i));
	}
	printf("\n\n");
	printf("The Integer Array entered by you consisting of %d elements : \n\n", S_iArrayLength);

	for (SUM_i = 0; SUM_i < S_iArrayLength; SUM_i++)
	{
		printf("ptr_iArray[%d] = %d \t\t at address &ptr_iArray[%d] : %p\n", SUM_i, SUM_ptr_iArray[SUM_i], SUM_i, &SUM_ptr_iArray[SUM_i]);
	}
	printf("\n\n");
	if (SUM_ptr_iArray)
	{
		free(SUM_ptr_iArray);
		SUM_ptr_iArray = NULL;
		printf("\n\n");
		printf("Memory allocated for integer has been successfully freed!!");
	}
	return(0);
}







