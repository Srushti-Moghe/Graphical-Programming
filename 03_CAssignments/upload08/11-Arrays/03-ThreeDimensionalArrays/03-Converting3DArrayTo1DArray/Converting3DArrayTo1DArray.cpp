#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 5
#define DEPTH 5

int main(void)
{
	//Variable Declarations
	
	//In Line Initialization
	int SiArray[NUM_ROWS][NUM_COLUMNS][DEPTH] = { {{ 10,  20},  {30,   40}, {50,  60}},
							                      {{ 70,  80},  {90,  100}, {110, 120}},
							                      {{ 130, 140}, {150, 160}, {170, 180}},
							                      {{ 190, 200}, {210, 220}, {230, 240}},
							                      {{ 250, 260}, {270, 280}, {290, 300}} };
	int Si, Sj, Sk;

	int SiArray_1D[NUM_ROWS * NUM_COLUMNS * DEPTH]; // 5 * 3 * 2 Elements => 30 elements in the 1D Array
	
	//Code

	//Display 3D Array
	printf("\n\n");
	printf("Elements in the Three Dimensional 3D Array : \n\n");
	for (Si = 0; Si < NUM_ROWS; Si++)
	{
		printf("*****Row - %d*****\n", (Si + 1));
		for (Sj = 0; Sj < NUM_COLUMNS; Sj++)
		{
			printf("*****Column - %d*****\n", (Sj + 1));
			for (Sk = 0; Sk < DEPTH; Sk++)
			{
				printf("iArray[%d][%d][%d] = %d\n", Si, Sj, Sk, SiArray[Si][Sj][Sk]);
			}
			printf("\n");
		}
		printf("\n\n");
	}

	//Converting 3D to 1D
	for (Si = 0; Si < NUM_ROWS; Si++)
	{
		for (Sj = 0; Sj < NUM_COLUMNS; Sj++)
		{
			for (Sk = 0; Sk < DEPTH; Sk++)
			{
				SiArray_1D[(Si * NUM_COLUMNS * DEPTH) + (Sj * DEPTH) + Sk] = SiArray[Si][Sj][Sk];
			}
		}
	}

	//Display 1D Array
	printf("\n\n\n\n");
	printf("Elements in the 1D Array : \n\n");
	for (Si = 0; Si < (NUM_ROWS * NUM_COLUMNS * DEPTH); Si++)
	{
		printf("iArray_1D[%d] = %d\n", Si, SiArray_1D[Si]);
	}
	
	return(0);
}


