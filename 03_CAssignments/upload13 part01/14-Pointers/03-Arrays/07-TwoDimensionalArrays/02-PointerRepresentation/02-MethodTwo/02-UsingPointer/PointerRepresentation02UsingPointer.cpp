#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
	// Variable Declarations
	int SUM_i, SUM_j;
	int **SUM_ptr_iArray = NULL;

	// Code

	// Every Row of a 2D Array is an integer Array itself comprising of 'NUM_COLUMNS' integer elements
	// There are 3 Columns and 5 Rows in an integer Array. Each of the rows is an 1D Array of 3 integers
	// Hence each of the 5 rows themselvesbeing arrays, will be the base addresses of their respective rows
	printf("\n\n");

	// ***Memory Allocation***
	SUM_ptr_iArray = (int**)malloc(NUM_ROWS * sizeof(int*));  // ptr_iArray is the name and base address of 1D Array containing 5 integer pointers to 5 integer arrays .. hence it is an array containing elements of datatype (int *)
	if (SUM_ptr_iArray == NULL)
	{
		printf("Memory Allocation to the 1D Array of Base addresses of %d rows Failed !!! Exitting Now ...\n\n", NUM_ROWS);
		exit(0);
	}
	else
	{
		printf("Memory Allocation to the 1D Array of Base addresses of %d rows Succeeded !!!\n\n", NUM_ROWS);
	}
	// Allocating Memory to each row
	for (SUM_i = 0; SUM_i < NUM_ROWS; SUM_i++)
	{
		SUM_ptr_iArray[SUM_i] = (int*)malloc(NUM_COLUMNS * sizeof(int)); // ptr_iArray[i] is the base addrtess of ith row

		if (SUM_ptr_iArray == NULL)
		{
			printf("Memory Allocation to the Column of %d Row Failed !!! Exitting Now ...\n\n", SUM_i);
			exit(0);

		}
		else
		{
			printf("Memory Allocation to the Columns of %d rows Succeeded !!!\n\n", SUM_i);
		}
	}
	
	for (SUM_i = 0; SUM_i < NUM_ROWS; SUM_i++)
	{
		for (SUM_j = 0; SUM_j < NUM_COLUMNS; SUM_j++)
		{
			*(*(SUM_ptr_iArray + SUM_i) + SUM_j) = (SUM_i + 1) * (SUM_j);
		}
	}
	// Displaying Values
	printf("\n\n");
	printf("2D Integer Arrays Elements along with Addreses : \n\n");
	for (SUM_i = 0; SUM_i < NUM_ROWS; SUM_i++)
	{
		for (SUM_j = 0; SUM_j < NUM_COLUMNS; SUM_j++)
		{
			printf("ptr_iArray_Row[%d][%d] = %d \t\t At Address &ptr_iArray_Row[%d][%d] : %p\n", SUM_i, SUM_j, SUM_ptr_iArray[SUM_i][SUM_j], SUM_i, SUM_j, &SUM_ptr_iArray[SUM_i][SUM_j]);
		}
		printf("\n\n");
	}
	// Freeing Allocated Memory
	// Freeing Memory of Each Row
	for (SUM_i = (NUM_ROWS - 1); SUM_i >= 0; SUM_i--)
	{
		if (*(SUM_ptr_iArray + SUM_i)) // if(ptr_iArray[i])
		{
			free(*(SUM_ptr_iArray + SUM_i));  // free(ptr_iArray[i])
			*(SUM_ptr_iArray + SUM_i) = NULL; // ptr_iArray[i] = NULL
			printf("Memory Allocated to Row %d has been successfully freed !!!\n\n", SUM_i);
		}
	}
	// Freeing Memory of ptr_iArray[i] which isarray of 5 integer pointers
	// That is it is an array having 6 integer addresses (int*)
	if (SUM_ptr_iArray)
	{
		free(SUM_ptr_iArray);
		SUM_ptr_iArray = NULL;
		printf("Memory Allocated to ptr_iArray has been successfully freed !!!\n\n");
	}
	return(0);
}




