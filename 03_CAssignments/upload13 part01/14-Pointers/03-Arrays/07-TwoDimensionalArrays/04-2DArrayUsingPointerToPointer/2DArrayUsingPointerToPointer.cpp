#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// Variable Declarations
	int **SUM_ptr_iArray = NULL; // SUM_ptr_iArray is a pointer to pointer variable to an integer constant
	int SUM_num_rows, SUM_num_columns;
	int SUM_i, SUM_j;

	// Code

	// To Get the number of Rows from the user
	printf("\n\n");
	printf("Enter the number of Rows : ");
	scanf("%d", &SUM_num_rows);

	// To Get the number of Columns from the user
	printf("\n\n");
	printf("Enter the number of Columns : ");
	scanf("%d", &SUM_num_columns);

	// Allocating Memory to 1D Array consisting of Base Address of Rows 
	printf("\n\n");
	printf("*****Memory Allocation to 2D integer Array*****");
	SUM_ptr_iArray = (int**)malloc(SUM_num_rows * sizeof(int*));
	if (SUM_ptr_iArray == NULL)
	{
		printf("Failed to Allocate Memory to %d Rows of 2D integer Array !!! Exitting Now...\n\n", SUM_num_rows);
		exit(0);
	}
	else
	{
		printf("Memory Allocation to %d Rows of 2D integer Array Succeeded !!! Exitting Now...\n\n", SUM_num_rows);
	}

	// Allocating Memory to each Row which is a 1D integer Array consisting of Columns which contain actual integers
	for (SUM_i = 0; SUM_i < SUM_num_rows; SUM_i++)
	{
		SUM_ptr_iArray[SUM_i] = (int*)malloc(SUM_num_columns * sizeof(int));
		if (SUM_ptr_iArray[SUM_i] == NULL)
		{
			printf("Failed to Allocate Memory to Row %d of 2D Integer Array !!! Exitting Now...\n\n", SUM_i);
			exit(0);
		}
		else
		{
			printf("Memory Allocation to Row %d of 2D Integer Array Succeed !!!\n\n", SUM_i);
		}
	}
	// Filling up values
	for (SUM_i = 0; SUM_i < SUM_num_rows; SUM_i++)
	{
		for (SUM_j = 0; SUM_j < SUM_num_columns; SUM_j++)
		{
			SUM_ptr_iArray[SUM_i][SUM_j] = (SUM_i + 1) * (SUM_j + 1);
			// *(*SUM_ptr_iArray + SUM_i) + SUM_j) = (SUM_i * 1) + (SUM_j * 1);
		}
	}

	// Displaying Values
	printf("\n\n");
	printf("Displaying Values : \n\n");
	for (SUM_i = 0; SUM_i < SUM_num_rows; SUM_i++)
	{
		printf("Base Address of Row %d : SUM_ptr_iArray[%d] = %p \t at address : %p\n", SUM_i, SUM_i, &SUM_ptr_iArray[SUM_i]);
	}
	printf("\n\n");

	for (SUM_i = 0; SUM_i < SUM_num_rows; SUM_i++)
	{
		for (SUM_j = 0; SUM_j < SUM_num_columns; SUM_j++)
		{
			printf("SUM_ptr_iArray[%d][%d] = %d \t at Address : %p\n", SUM_i, SUM_j, SUM_ptr_iArray[SUM_i][SUM_j]);
		}
		printf("\n");
	}
	// Freeing Memory Assigned each Row
	for (SUM_i = (SUM_num_rows - 1); SUM_i >= 0; SUM_i--)
	{
		if (SUM_ptr_iArray[SUM_i])
		free(SUM_ptr_iArray[SUM_i]);
		SUM_ptr_iArray[SUM_i] = NULL;
		printf("Memory Allocated to the Row of %d of 2D Integer Array has been successfully Freed!!!\n\n", SUM_i);
	}

	// Freeing Memory Assigned to 1D Array consisting of Base Addresses of Rows
	if (SUM_ptr_iArray)
	{
		free(SUM_ptr_iArray);
		SUM_ptr_iArray = NULL;
		printf("Memory Allocated to SUM_ptr_iArray has been successfully Freed!!!\n\n");
	}
	return(0);
}






