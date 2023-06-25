#include <stdio.h>
int main(void)
{
	//Variable Declarations
	
	//In Line Initialization
	int SiArray[5][3][2] = { {{9, 18}, {27, 36}, {45, 54}},
							 {{8, 16}, {24, 32}, {40, 48}},
							 {{7, 14}, {21, 28}, {35, 42}},
							 {{6, 12}, {18, 24}, {30, 36}},
							 {{5, 10}, {15, 20}, {25, 30}} };
	int Sint_size;
	int SiArray_size;
	int SiArray_num_elements, SiArray_width, SiArray_height, SiArray_depth;

	//Code
	printf("\n\n");

	Sint_size = sizeof(int);

	SiArray_size = sizeof(SiArray);
	printf("Size of Three Dimensional 3D Integer Array is = %d\n\n", SiArray_size);

	SiArray_width = SiArray_size / sizeof(SiArray[0][0]);
	printf("Number of Columns in the Three Dimensional 3D Integer Array is = %d\n\n", SiArray_width);

	SiArray_height = sizeof(SiArray[0]) / sizeof(SiArray[0][0]);
	printf("Number of Columns(Height) in the Three Dimensional 3D Integer Array is = %d\n\n", SiArray_height);

	SiArray_depth = sizeof(SiArray[0][0]) / Sint_size;
	printf("Depth in the Three Dimensional 3D Integer Array is = %d\n\n", SiArray_depth);

	SiArray_num_elements = SiArray_width * SiArray_height * SiArray_depth;
	printf("Number of elements in the Three Dimensional 3D Integer Array is = %d\n\n", SiArray_num_elements);

	printf("\n\n");
	printf("Elements in the Three Dimensional 3D Integer Array is :\n\n");

	//PIECEMEAL DISPLAY
	//***ROW1***
	printf("*****ROW - 1*****\n");
	printf("*****COLUMN - 1*****\n");
	printf("SiArray[0][0][0] = %d\n", SiArray[0][0][0]);
	printf("SiArray[0][0][1] = %d\n", SiArray[0][0][1]);
	printf("\n");

	printf("*****COLUMN - 2*****\n");
	printf("SiArray[0][1][0] = %d\n", SiArray[0][1][0]);
	printf("SiArray[0][1][1] = %d\n", SiArray[0][1][1]);
	printf("\n");

	printf("*****COLUMN - 3*****\n");
	printf("SiArray[0][2][0] = %d\n", SiArray[0][2][0]);
	printf("SiArray[0][2][1] = %d\n", SiArray[0][2][1]);
	printf("\n\n");

	//***ROW2***
	printf("*****ROW - 2*****\n");
	printf("*****COLUMN - 1*****\n");
	printf("SiArray[1][0][0] = %d\n", SiArray[1][0][0]);
	printf("SiArray[1][0][1] = %d\n", SiArray[1][0][1]);
	printf("\n");

	printf("*****COLUMN - 2*****\n");
	printf("SiArray[1][1][0] = %d\n", SiArray[1][1][0]);
	printf("SiArray[1][1][1] = %d\n", SiArray[1][1][1]);
	printf("\n");

	printf("*****COLUMN - 3*****\n");
	printf("SiArray[1][2][0] = %d\n", SiArray[1][2][0]);
	printf("SiArray[1][2][1] = %d\n", SiArray[1][2][1]);
	printf("\n\n");

	//***ROW3***
	printf("*****ROW - 3*****\n");
	printf("*****COLUMN - 1*****\n");
	printf("SiArray[2][0][0] = %d\n", SiArray[2][0][0]);
	printf("SiArray[2][0][1] = %d\n", SiArray[2][0][1]);
	printf("\n");

	printf("*****COLUMN - 2*****\n");
	printf("SiArray[2][1][0] = %d\n", SiArray[2][1][0]);
	printf("SiArray[2][1][1] = %d\n", SiArray[2][1][1]);
	printf("\n");

	printf("*****COLUMN - 3*****\n");
	printf("SiArray[2][2][0] = %d\n", SiArray[2][2][0]);
	printf("SiArray[2][2][1] = %d\n", SiArray[2][2][1]);
	printf("\n\n");

	//***ROW4***
	printf("*****ROW - 4*****\n");
	printf("*****COLUMN - 1*****\n");
	printf("SiArray[3][0][0] = %d\n", SiArray[3][0][0]);
	printf("SiArray[3][0][1] = %d\n", SiArray[3][0][1]);
	printf("\n");

	printf("*****COLUMN - 2*****\n");
	printf("SiArray[3][1][0] = %d\n", SiArray[3][1][0]);
	printf("SiArray[3][1][1] = %d\n", SiArray[3][1][1]);
	printf("\n");

	printf("*****COLUMN - 3*****\n");
	printf("SiArray[3][2][0] = %d\n", SiArray[3][2][0]);
	printf("SiArray[3][2][1] = %d\n", SiArray[3][2][1]);
	printf("\n\n");

	//***ROW5***
	printf("*****ROW - 5*****\n");
	printf("*****COLUMN - 1*****\n");
	printf("SiArray[4][0][0] = %d\n", SiArray[4][0][0]);
	printf("SiArray[4][0][1] = %d\n", SiArray[4][0][1]);
	printf("\n");

	printf("*****COLUMN - 2*****\n");
	printf("SiArray[4][1][0] = %d\n", SiArray[4][1][0]);
	printf("SiArray[4][1][1] = %d\n", SiArray[4][1][1]);
	printf("\n");

	printf("*****COLUMN - 3*****\n");
	printf("SiArray[4][2][0] = %d\n", SiArray[4][2][0]);
	printf("SiArray[4][2][1] = %d\n", SiArray[4][2][1]);
	printf("\n\n");

	return(0);
}


