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
	for (SUM_i = 0; SUM_i < NUM_ROWS; SUM_i++)
	{
		for (SUM_j = 0; SUM_j < NUM_COLUMNS; SUM_j++)
		{
			S_iArray[SUM_i][SUM_j] = (SUM_i + 1) * (SUM_j + 1);
		}
	}
	printf("\n\n");
	printf("2D Integer Array Elements along with addresses : \n\n");
	for (SUM_i = 0; SUM_i < NUM_ROWS; SUM_i++)
	{
		for (SUM_j = 0; SUM_j < NUM_COLUMNS; SUM_j++)
		{
			printf("iArray[%d][%d] = %d\t\t At Address : %p\n", SUM_i, SUM_j, S_iArray[SUM_i][SUM_j], &S_iArray[SUM_i][SUM_j]);
		}
		printf("\n\n");
	}
	return(0);
}


