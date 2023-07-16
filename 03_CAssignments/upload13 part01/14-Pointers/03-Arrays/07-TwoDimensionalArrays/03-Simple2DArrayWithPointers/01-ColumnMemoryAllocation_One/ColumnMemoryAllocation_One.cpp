#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
	// Variable Declarations
	int *S_iArray[NUM_ROWS];
	int SUM_i, SUM_j;

	// Code
	printf("\n\n");
	for (SUM_i = 0; SUM_i < NUM_ROWS; SUM_i++)
	{
		S_iArray[SUM_i] = (int*)malloc(NUM_COLUMNS * sizeof(int));
		if (S_iArray[SUM_i] == NULL)
		{
			printf("Memory Allocation to the Column of %d Row Failed !!! Exitting Now ...\n\n", SUM_i);
			exit(0);
		}
		else
		{
			printf("Memory Allocation to the Column of %d Row Succeeded !!!\n\n", SUM_i);
		}
	}
	// Assigning Values to 2D Array
	for (SUM_i = 0; SUM_i < NUM_ROWS; SUM_i++)
	{
		for (SUM_j = 0; SUM_j < NUM_COLUMNS; SUM_j++)
		{
			S_iArray[SUM_i][SUM_j] = (SUM_i + 1) * (SUM_j + 1);
		}
	}

	// Displaying 2D Array
	printf("\n\n");
	printf("Displaying 2D Array : \n\n");
	for (SUM_i = 0; SUM_i < NUM_ROWS; SUM_i++)
	{
		for (SUM_j = 0; SUM_j < NUM_COLUMNS; SUM_j++)
		{
			printf("iArray[%d][%d] = %d\n", SUM_i, SUM_j, S_iArray[SUM_i][SUM_j]);
		}
		printf("\n\n");
	}
	printf("\n\n");

	// Freeing Memory Assigned to 2D Array (in reverse order)
	for (SUM_i = (NUM_ROWS - 1); SUM_i >= 0; SUM_i--)
	{
		free(S_iArray[SUM_i]);
		S_iArray[SUM_i] = NULL;
		printf("Memory Allocated to the Row of %d of Integer Array has been successfully Freed!!!\n\n", SUM_i);
	}
	return(0);
}




