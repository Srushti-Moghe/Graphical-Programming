#include <stdio.h>
int main(void)
{
	//Variable Declarations
	
	//In Line Initialization
	int SiArray[5][3][2] = { {{10, 20}, {30, 40}, {50, 60}},
							 {{70, 80}, {90, 100}, {110, 120}},
							 {{130, 140}, {150, 160}, {170, 180}},
							 {{190, 200}, {210, 220}, {230, 240}},
							 {{250, 260}, {270, 280}, {290, 300}} };
	int Sint_size;
	int SiArray_size;
	int SiArray_num_elements, SiArray_width, SiArray_height, SiArray_depth;
	int Si, Sj, Sk;

	//Code
	printf("\n\n");

	Sint_size = sizeof(int);

	SiArray_size = sizeof(SiArray);
	printf("Size of Three Dimensional 3D Integer Array is = %d\n\n", SiArray_size);

	SiArray_width = SiArray_size / sizeof(SiArray[0]);
	printf("Number of Rows(Width) in the Three Dimensional 3D Integer Array is = %d\n\n", SiArray_width);

	SiArray_height = sizeof(SiArray[0]) / sizeof(SiArray[0][0]);
	printf("Number of Columns(Height) in the Three Dimensional 3D Integer Array is = %d\n\n", SiArray_height);

	SiArray_depth = sizeof(SiArray[0][0]) / Sint_size;
	printf("Depth in the Three Dimensional 3D Integer Array is = %d\n\n", SiArray_depth);

	SiArray_num_elements = SiArray_width * SiArray_height * SiArray_depth;
	printf("Number of elements in the Three Dimensional 3D Integer Array is = %d\n\n", SiArray_num_elements);

	printf("\n\n");
	printf("Elements in the Three Dimensional 3D Integer Array is :\n\n");

	for (Si = 0; Si < SiArray_width; Si++)
	{
		printf("***** Row - %d*****\n", (Si + 1));
		for (Sj = 0; Sj < SiArray_height; Sj++)
		{
			printf("***** Column - %d*****\n", (Sj + 1));
			for (Sk = 0; Sk < SiArray_depth; Sk++)
			{
				printf("iArray[%d][%d][%d] = %d\n", Si, Sj, Sk, SiArray[Si][Sj][Sk]);
			}
			printf("\n");
		}
		printf("\n\n");
	}

	return(0);
}


