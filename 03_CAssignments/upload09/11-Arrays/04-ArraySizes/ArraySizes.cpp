#include <stdio.h>

int main(void)
{
	//Variable Declarations
	int SiArray_One[5];
	int SiArray_Two[5][3];
	int SiArray_Three[100][100][5];

	int S_num_rows_2D;
	int S_num_columns_2D;

	int S_num_rows_3D;
	int S_num_columns_3D;
	int S_depth_3D;

	//Code
	printf("\n\n");
	printf("Size of 1D integer array iArray_One = %lu\n", sizeof(SiArray_One));
	printf("Number of Elements in 1D integer array iArray_One = %lu\n", (sizeof(SiArray_One) / sizeof(int)));
	
	printf("\n\n");
	printf("Size of 2D integer array iArray_Two = %lu\n", sizeof(SiArray_Two));

	printf("Number of Rows in 2D integer array iArray_Two = %lu\n", (sizeof(SiArray_Two) / sizeof(SiArray_Two[0])));
	S_num_rows_2D = (sizeof(SiArray_Two) / sizeof(SiArray_Two[0]));

	printf("Number of Elements (Column) in each Row in 2D integer array iArray_Two = %lu\n", (sizeof(SiArray_Two[0]) / sizeof(SiArray_Two[0][0])));
	S_num_columns_2D = (sizeof(SiArray_Two[0]) / sizeof(SiArray_Two[0][0]));

	printf("Number of Elements in total in 2D Array iArray_Two = %d\n", (S_num_rows_2D * S_num_columns_2D));

	printf("\n\n");

	printf("\n\n");
	printf("Size of 3D integer Array iArray_Three = %lu\n", sizeof(SiArray_Three));

	printf("Number of Rows in 3D integer Array iArray_Three = %lu\n", (sizeof(SiArray_Three) / sizeof(SiArray_Three[0])));
	S_num_rows_3D = (sizeof(SiArray_Three) / sizeof(SiArray_Three[0]));

	printf("Number of Elements (Columns) in one row in 3D integer array iArray_Three = %lu\n", (sizeof(SiArray_Three[0]) / sizeof(SiArray_Three[0][0])));
	S_num_columns_3D = (sizeof(SiArray_Three[0]) / sizeof(SiArray_Three[0][0]));

	printf("Number of Elements (depth) in one column in one row in 3D integer array iArray_Three = %lu\n", (sizeof(SiArray_Three[0][0]) / sizeof(SiArray_Three[0][0][0])));
	S_depth_3D = (sizeof(SiArray_Three[0][0]) / sizeof(SiArray_Three[0][0][0]));

	printf("Number of Elements in total in 3D Array iArray_Three = %d  \n", (S_num_rows_3D * S_num_columns_3D * S_depth_3D));

	printf("\n\n");

	return(0);

}



