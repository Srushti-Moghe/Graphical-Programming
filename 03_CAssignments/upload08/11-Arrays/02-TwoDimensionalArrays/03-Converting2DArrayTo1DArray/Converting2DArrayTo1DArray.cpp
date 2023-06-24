#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
	//Variable Declarations
	int SiArray_2D[NUM_ROWS][NUM_COLUMNS]; //Total Elements = No of Rows * No of Columns
	int SiArray_1D[NUM_ROWS * NUM_COLUMNS];

	int Si, Sj;
	int Snum;

	//Code
	printf("Enter Elements of your choice to fill up an 2D integer Array : \n\n");
	for (Si = 0; Si < NUM_ROWS; Si++)
	{
		printf("For ROW number %d : \n", (Si + 1));
		for (Sj = 0; Sj < NUM_COLUMNS; Sj++)
		{
			printf("Enter Element Number %d : \n", (Sj + 1));
			scanf("%d", &Snum);
			SiArray_2D[Si][Sj] = Snum;
		}
		printf("\n\n");
	}

	//Display of 2D Array
	printf("\n\n");
	printf("Two Dimensional 2D Array of Integers : \n\n");
	for (Si = 0; Si < NUM_ROWS; Si++)
	{
		printf("***ROW %d***\n", (Si + 1));
		for (Sj = 0; Sj < NUM_COLUMNS; Sj++)
		{
			printf("iArray_2D[%d][%d] = %d\n", Si, Sj, SiArray_2D[Si][Sj]);
		}
		printf("\n\n");
	}

	//Converting 2D >> 1D Integer Array
	for (Si = 0; Si < NUM_ROWS; Si++)
	{
		for (Sj = 0; Sj < NUM_COLUMNS; Sj++)
		{
			SiArray_1D[(Si * NUM_COLUMNS) + Sj] = SiArray_2D[Si][Sj];
		}
	}

	//Printing Array
	printf("\n\n");
	printf("One Dimensional 1D Array of Integers : \n\n");
	for (Si = 0; Si < (NUM_ROWS * NUM_COLUMNS); Si++)
	{
		printf("iArray_1D[%d] = %d\n", Si, SiArray_1D[Si]);
	}
	printf("\n\n");

	return(0);
}




