#include <stdio.h>
int main(void)
{
	//Variable Declarations
	int SiArray[3][5]; //3Roows (0,1.2) and 5Columns (0,1,2,3,4)
	int S_int_size;
	int S_iArray_size;
	int S_iArray_num_elements, S_iArray_num_rows, S_iArray_num_columns;
	int S_i, S_j;

	//Code
	printf("\n\n");

	S_int_size = sizeof(int);

	S_iArray_size = sizeof(SiArray);
	printf("Size of two dimensional 2D IntegerArray is = %d\n\n", S_iArray_size);

	S_iArray_num_rows = S_iArray_size / sizeof(SiArray[0]);
	printf("Number of Rows in two dimensional 2D Integer array is = %d\n\n", S_iArray_num_rows);

	S_iArray_num_columns = sizeof(SiArray[0]) / S_int_size;
	printf("Number of Columns in two dimensional 2D Integer array is = %d\n\n", S_iArray_num_columns);

	S_iArray_num_elements = S_iArray_num_rows * S_iArray_num_columns;
	printf("Number of Elements in two dimensional 2D Integer array is = %d\n\n", S_iArray_num_elements);

	printf("\n\n");
	printf("Elements in 2D array : \n\n");

	//PIECE-MEAL ASSIGNMENT
	//Row1
	SiArray[0][0] = 21;
	SiArray[0][1] = 22;
	SiArray[0][2] = 23;
	SiArray[0][3] = 24;
	SiArray[0][4] = 25;

	//Row2
	SiArray[1][0] = 26;
	SiArray[1][1] = 27;
	SiArray[1][2] = 28;
	SiArray[1][3] = 29;
	SiArray[1][4] = 30;

	//Row3
	SiArray[2][0] = 31;
	SiArray[2][1] = 32;
	SiArray[2][2] = 33;
	SiArray[2][3] = 34;
	SiArray[2][4] = 35;

	//FOR DISPLAY
	for (S_i = 0; S_i < S_iArray_num_rows; S_i++)
	{
		printf("*****ROW %d*****\n", (S_i + 1));
		for (S_j = 0; S_j < S_iArray_num_columns; S_j++)
		{
			printf("iArray[%d][%d] = %d\n", S_i, S_j, SiArray[S_i][S_j]);
		}
		printf("\n\n");
	}
	return(0);
}




