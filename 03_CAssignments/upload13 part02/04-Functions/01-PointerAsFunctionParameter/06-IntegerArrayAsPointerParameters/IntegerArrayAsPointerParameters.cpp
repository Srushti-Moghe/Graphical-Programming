#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Function Declarations
	void MultipleArrayElementsByNumber(int *, int, int);

	// Variable Declarations
	
	int *S_iArray = NULL;
	int SUM_num_elements;
	int SUM_i, SUM_num;

	//Code
	printf("\n\n");
	printf("Enter the number of elements you want in an Integer Array: \n\n");
	scanf("%d", &SUM_num_elements);

	S_iArray = (int *)malloc(SUM_num_elements * sizeof(int));
	if (S_iArray == NULL)
	{
		printf("Memory Allocation to 'iArray' failed !!!Exitting now...\n\n");
		exit(0);
	}

	printf("\n\n");
	printf("Enter %d elements of the Integer Array: \n\n", SUM_num_elements);
	for (SUM_i = 0; SUM_i < SUM_num_elements; SUM_i++)
	{
		scanf("%d", &S_iArray[SUM_i]);
	}

	printf("\n\n");
	printf("Array before passing to function MultipleArrayElementsByNumber() : \n\n");
	for (SUM_i = 0; SUM_i < SUM_num_elements; SUM_i++)
	{
		printf("iArray[%d] = %d\n", SUM_i, S_iArray[SUM_i]);
	}

	printf("Enter the number by which you want to Multiply each Array element : \n\n");
	scanf("%d", &SUM_num);

	MultipleArrayElementsByNumber(S_iArray, SUM_num_elements, SUM_num);

	printf("\n\n");
	printf("Array returned by function MultipleArrayElementsByNumber() : \n\n");

	for (SUM_i = 0; SUM_i < SUM_num_elements; SUM_i++)
	{
		printf("iArray[%d] = %d\n", SUM_i, S_iArray[SUM_i]);
	}

	if(S_iArray)
	{
		free(S_iArray);
		S_iArray = NULL;
		printf("The memory allocated to 'iArray' has been successfully Freeed !!!\n\n");
	}

	return(0);
}

//***Function***

void MultipleArrayElementsByNumber(int *arr, int iNumElements, int n)
{
	//Variable Declarations
	int S_i;

	//Code
	for (S_i = 0; S_i < iNumElements; S_i++)
	{
		arr[S_i] = arr[S_i] * n;
	}
}

















