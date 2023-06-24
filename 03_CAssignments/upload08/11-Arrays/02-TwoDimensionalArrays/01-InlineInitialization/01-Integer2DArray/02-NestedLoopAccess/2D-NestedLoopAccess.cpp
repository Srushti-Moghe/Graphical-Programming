#include <stdio.h>
int main(void)
{
	//Variable Declarations
	int SiArray[5][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15} }; //In-Line Initialization
	int S_int_size;
	int SiArray_size;
	int SiArray_num_elements, SiArray_num_rows, SiArray_num_columns;
	int SUMi, SUMj;

	//Code
	printf("\n\n");

	S_int_size = sizeof(int);

	SiArray_size = sizeof(SiArray);
	printf("Size of 2 Dimensional (2D) Integer Array is = %d\n\n", SiArray_size);

	SiArray_num_rows = SiArray_size / sizeof(SiArray[0]);
	printf("Number of Rows in 2 Dimensional (2D) Integer Array is = %d\n\n", SiArray_num_rows);

	SiArray_num_columns = sizeof(SiArray[0]) / S_int_size;
	printf("Number of Columns in Two Dimensional (2D) Integer Array = %d\n\n", SiArray_num_columns);

	SiArray_num_elements = SiArray_num_rows * SiArray_num_columns;
	printf("Number of Elements in Two Dimensional (2D) Integer Array = %d\n\n", SiArray_num_elements);

	printf("\n\n");
	printf("Elements in Two Dimensional (2D) Array = \n\n");

	//*** Array indices begin from 0, hence Row1>Row0 AND Column1>Column0
	for (SUMi = 0; SUMi < SiArray_num_rows; SUMi++)
	{
		printf("*****Row - %d*****\n", (SUMi + 1));
		for (SUMj = 0; SUMj < SiArray_num_columns; SUMj++)
		{
			printf("iArray[%d][%d] = %d\n", SUMi, SUMj, SiArray[SUMi][SUMj]);
		}
		printf("\n\n");
	}
	
	return(0);
}



