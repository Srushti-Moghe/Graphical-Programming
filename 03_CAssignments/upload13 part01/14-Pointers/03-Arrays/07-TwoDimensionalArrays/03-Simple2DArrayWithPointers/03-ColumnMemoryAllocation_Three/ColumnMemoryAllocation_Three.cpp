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

	// ONE (Allocating Memory for an Array of 3 Integers per row)
	printf("\n\n");
	printf("*****First Memory Allocation to 2D Integer Array*****\n\n");
	for (SUM_i = 0; SUM_i < NUM_ROWS; SUM_i++)
	{
		// Row 0 will have (NUM_COLUMNS - 0) = (5 - 0) = 5 Columns
		// Row 1 will have (NUM_COLUMNS - 1) = (5 - 1) = 4 Columns
		// Row 2 will have (NUM_COLUMNS - 2) = (5 - 2) = 3 Columns
		// Row 3 will have (NUM_COLUMNS - 3) = (5 - 3) = 2 Columns
		// Row 4 will have (NUM_COLUMNS - 4) = (5 - 4) = 1 Columns

		S_iArray[SUM_i] = (int*)malloc(NUM_COLUMNS * sizeof(int));
		if (S_iArray[SUM_i] == NULL)
		{
			printf("Failed to Allocate Memory to Row %d of 2D Integer Array !!! Exitting Now...\n\n", SUM_i);
			exit(0);
		}
		else
		{
			printf("Memory Allocation to Row %d of 2D Integer Array Succeed !!!\n\n", SUM_i);
		}
	}
	// Assigning Values to 2D Array
	for (SUM_i = 0; SUM_i < NUM_ROWS; SUM_i++)
	{
		for (SUM_j = 0; SUM_j < (NUM_COLUMNS - 1); SUM_j++)
		{
			S_iArray[SUM_i][SUM_j] = (SUM_i + 1) * (SUM_j + 1);
		}
	}

	// Displaying 2D Array
	printf("\n\n");
	printf("Displaying 2D Array : \n\n");
	for (SUM_i = 0; SUM_i < NUM_ROWS; SUM_i++)
	{
		for (SUM_j = 0; SUM_j < (NUM_COLUMNS); SUM_j++)
		{
			printf("iArray[%d][%d] = %d\n", SUM_i, SUM_j, S_iArray[SUM_i][SUM_j]);
		}
		printf("\n\n");
	}

	// Freeing Memory Assigned to 2D Array (in reverse order)
	for (SUM_i = (NUM_ROWS - 1); SUM_i >= 0; SUM_i--)
	{
		free(S_iArray[SUM_i]);
		S_iArray[SUM_i] = NULL;
		printf("Memory Allocated to the Row of %d of 2D Integer Array has been successfully Freed!!!\n\n", SUM_i);
	}

	// TWO (Allocating Memory for an Array of 8 Integers per row)
	printf("\n\n");
	printf("*****Second Memory Allocation to 2D Integer Array*****\n\n");
	for (SUM_i = 0; SUM_i < NUM_ROWS; SUM_i++)
	{
		S_iArray[SUM_i] = (int*)malloc(NUM_COLUMNS * sizeof(int));
		if (S_iArray[SUM_i] == NULL)
		{
			printf("Failed to Allocate Memory to Row %d of 2D Integer Array !!! Exitting Now...\n\n", SUM_i);
			exit(0);
		}
		else
		{
			printf("Memory Allocation to Row %d of 2D Integer Array Succeed !!!\n\n", SUM_i);
		}
	}
	
	return(0);
}






