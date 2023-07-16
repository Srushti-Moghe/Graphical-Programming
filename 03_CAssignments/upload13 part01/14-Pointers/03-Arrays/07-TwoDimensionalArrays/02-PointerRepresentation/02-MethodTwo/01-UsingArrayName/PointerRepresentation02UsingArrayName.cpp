#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
	// Variable Declarations
	int S_iArray[NUM_ROWS][NUM_COLUMNS];
	int SUM_i, SUM_j;

	// Code

	// Name of an Array is its Base Address >> 'iArray' = Base Address of 2D integer iArray[][]
	
	// iArray[5][3]
	// iArray[0] => 0th row ... hence the base address of row 0
	// iArray[1] => 1st row ... hence the base address of row 1
	// iArray[2] => 2nd row ... hence the base address of row 2
	// iArray[3] => 3rd row ... hence the base address of row 3
	
	// (iArray[0] + 0) => Address of 0th integer from Base Address of 0th Row (IArray[0][0]) 
	// (iArray[0] + 1) => Address of 1st integer from Base Address of 0th Row (IArray[0][1]) 
	// (iArray[0] + 2) => Address of 2nd integer from Base Address of 0th Row (IArray[0][2]) 

	// (iArray[1] + 0) => Address of 0th integer from Base Address of 1st Row (IArray[1][0]) 
	// (iArray[1] + 1) => Address of 1st integer from Base Address of 1st Row (IArray[1][1]) 
	// (iArray[1] + 2) => Address of 2nd integer from Base Address of 1st Row (IArray[1][2]) 

	// iArray[0], iArray[1], ... are 1D integer Arrays and can be treated as 1D integer Arrays using pointers
	// 'iArray' = Name and Base Address of 2D integer iArray[][]

	// (*(iArray + 0) + 0) = (iArray[0] + 0) Address of 0th element from base address of 0th row = (iArray[0] + 0) = (iArray[0][0])
	// (*(iArray + 0) + 1) = (iArray[0] + 1) Address of 1st element from base address of 0th row = (iArray[0] + 1) = (iArray[0][1])
	// (*(iArray + 0) + 2) = (iArray[0] + 2) Address of 2nd element from base address of 0th row = (iArray[0] + 2) = (iArray[0][2])

	// (*(iArray + 1) + 0) = (iArray[1] + 0) Address of 0th element from base address of 1st row = (iArray[1] + 0) = (iArray[1][0])
	// (*(iArray + 1) + 1) = (iArray[1] + 1) Address of 1st element from base address of 1st row = (iArray[1] + 1) = (iArray[1][1])
	// (*(iArray + 1) + 2) = (iArray[1] + 2) Address of 2nd element from base address of 1st row = (iArray[1] + 2) = (iArray[1][2])

	for (SUM_i = 0; SUM_i < NUM_ROWS; SUM_i++)
	{
		for (SUM_j = 0; SUM_j < NUM_COLUMNS; SUM_j++)
		{
			*(*(S_iArray + SUM_i) + SUM_j) = (SUM_i + 1) * (SUM_j + 1); // S_iArray can be treated as 1D Array with pointers
		}
	}
	printf("\n\n");
	printf("2D Integer Array Elements along with addresses : \n\n");
	for (SUM_i = 0; SUM_i < NUM_ROWS; SUM_i++)
	{
		for (SUM_j = 0; SUM_j < NUM_COLUMNS; SUM_j++)
		{
			printf("*(*(S_iArray + %d) + %d) = %d\t\t At Address (*(S_iArray + %d) + %d) : %p\n", SUM_i, SUM_j, *(*(S_iArray + SUM_i) + SUM_j), SUM_i, SUM_j, (*(S_iArray + SUM_i) + SUM_j));
		}
		printf("\n\n");
	}
	return(0);
}




