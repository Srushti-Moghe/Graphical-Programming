#include <stdio.h>
int main(void)
{
	//Variable Declarations
	int SiArray[5][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15} }; //In-Line Initialization
	int S_int_size;
	int SiArray_size;
	int SiArray_num_elements, SiArray_num_rows, SiArray_num_columns;

	//Code
	printf("\n\n");

	S_int_size = sizeof(int);

	SiArray_size = sizeof(SiArray);
	printf("Size of 2 Dimensional (2D) Integer Array is = %d\n\n", SiArray_size);

	SiArray_num_rows = SiArray_size / sizeof(SiArray[0]);
	printf("Number of Rows in 2 Dimensional (2D) Integer Array is = %d\n\n", SiArray_num_rows);

	SiArray_num_columns = sizeof(SiArray[0]) / S_int_size;
	printf("Number of Columns in Two Dimensional (2D) Integer Array = 5d\n\n", SiArray_num_columns);

	SiArray_num_elements = SiArray_num_rows * SiArray_num_columns;
	printf("Number of Elements in Two Dimensional (2D) Integer Array = 5d\n\n", SiArray_num_elements);

	printf("\n\n");
	printf("Elements in Two Dimensional (2D) Array = \n\n");

	//*** Array indices begin from 0, hence Row1>Row0 AND Column1>Column0

	//ROW - 1
	printf("*****ROW - 1*****\n");
	printf("iArray[0][0] = %d\n", SiArray[0][0]); //COLUMN1 - ELEMENT0 => 1
	printf("iArray[0][1] = %d\n", SiArray[0][1]); //COLUMN2 - ELEMENT1 => 2
	printf("iArray[0][2] = %d\n", SiArray[0][2]); //COLUMN3 - ELEMENT2 => 3

	printf("\n\n");

	//ROW - 2
	printf("*****ROW - 2*****\n");
	printf("iArray[1][0] = %d\n", SiArray[1][0]); //COLUMN1 - ELEMENT0 => 4
	printf("iArray[1][1] = %d\n", SiArray[1][1]); //COLUMN2 - ELEMENT1 => 5
	printf("iArray[1][2] = %d\n", SiArray[1][2]); //COLUMN3 - ELEMENT2 => 6

	printf("\n\n");

	//ROW - 3
	printf("*****ROW - 3*****");
	printf("iArray[2][0] = %d\n", SiArray[2][0]); //COLUMN1 - ELEMENT0 => 7
	printf("iArray[2][1] = %d\n", SiArray[2][1]); //COLUMN2 - ELEMENT1 => 8
	printf("iArray[2][2] = %d\n", SiArray[2][2]); //COLUMN3 - ELEMENT2 => 9

	printf("\n\n");

	//ROW - 4
	printf("*****ROW - 4*****");
	printf("iArray[3][0] = %d\n", SiArray[3][0]); //COLUMN1 - ELEMENT0 => 10
	printf("iArray[3][1] = %d\n", SiArray[3][1]); //COLUMN2 - ELEMENT1 => 11
	printf("iArray[3][2] = %d\n", SiArray[3][2]); //COLUMN3 - ELEMENT2 => 12

	printf("\n\n");

	//ROW - 5
	printf("*****ROW - 5*****");
	printf("iArray[4][0] = %d\n", SiArray[4][0]); //COLUMN1 - ELEMENT0 => 13
	printf("iArray[4][1] = %d\n", SiArray[4][1]); //COLUMN2 - ELEMENT1 => 14
	printf("iArray[4][2] = %d\n", SiArray[4][2]); //COLUMN3 - ELEMENT2 => 15

	printf("\n\n");

	return(0);

}



