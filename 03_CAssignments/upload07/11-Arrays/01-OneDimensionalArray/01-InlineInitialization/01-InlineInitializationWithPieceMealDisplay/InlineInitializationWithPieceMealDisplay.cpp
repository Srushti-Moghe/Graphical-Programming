#include <stdio.h>

int main(void)
{
	//Variable declarations
	int SiArray[] = { 9, 30, 6, 12, 98, 30, 85, 45 };
	int Sint_size;
	int SiArray_size;
	int SiArray_num_elements;

	float SfArray[] = { 1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f, 7.8f, 8.9f };
	float Sfloat_size;
	float SfArray_size;
	float SfArray_num_elements;

	char ScArray[] = { 'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P' };
	char Schar_size;
	char ScArray_size;
	char ScArray_num_elements;
	//Code

	//***iArray[]***
	printf("\n\n");
	printf("In-Line Initialization and Piecemeal Display of Elements of 'iArray[]' : \n\n");
	printf("iArray[0] (1st Element) = %d\n", SiArray[0]);
	printf("iArray[1] (2nd Element) = %d\n", SiArray[1]);
	printf("iArray[2] (3rd Element) = %d\n", SiArray[2]);
	printf("iArray[3] (4th Element) = %d\n", SiArray[3]);
	printf("iArray[4] (5th Element) = %d\n", SiArray[4]);
	printf("iArray[5] (6th Element) = %d\n", SiArray[5]);
	printf("iArray[6] (7th Element) = %d\n", SiArray[6]);
	printf("iArray[7] (8th Element) = %d\n", SiArray[7]);
	printf("iArray[8] (9th Element) = %d\n", SiArray[8]);
	printf("iArray[9] (10th Element) = %d\n", SiArray[9]);

	Sint_size = sizeof(int);
	SiArray_size = sizeof(SiArray);
	SiArray_num_elements = SiArray_size / Sint_size;
	printf("Size of datatype 'int' = %d bytes\n", Sint_size);
	printf("Number of Elements in 'int' Array 'iArray[]' = %d Elements\n", SiArray_num_elements);
	printf("Size of Array 'iArray[]' (%d elements * %d bytes) = %d bytes\n\n", SiArray_num_elements, Sint_size, SiArray_size);

	//***fArray[]***
	printf("\n\n");
	printf("In-Line Initialization and Piecemeal Display of Elements of 'fArray[]' : \n\n");
	printf("fArray[0] (1st Element) = %f\n", SfArray[0]);
	printf("fArray[1] (2nd Element) = %f\n", SfArray[1]);
	printf("fArray[2] (3rd Element) = %f\n", SfArray[2]);
	printf("fArray[3] (4th Element) = %f\n", SfArray[3]);
	printf("fArray[4] (5th Element) = %f\n", SfArray[4]);
	printf("fArray[5] (6th Element) = %f\n", SfArray[5]);
	printf("fArray[6] (7th Element) = %f\n", SfArray[6]);
	printf("fArray[7] (8th Element) = %f\n", SfArray[7]);
	printf("fArray[8] (9th Element) = %f\n", SfArray[8]);
	printf("fArray[9] (10th Element) = %f\n", SfArray[9]);

	Sfloat_size = sizeof(float);
	SfArray_size = sizeof(SfArray);
	SiArray_num_elements = SiArray_size / Sint_size;
	printf("Size of datatype 'float' = %f bytes\n", Sfloat_size);
	printf("Number of Elements in 'float' Array 'fArray[]' = %f Elements\n", SfArray_num_elements);
	printf("Size of Array 'fArray[]' (%f elements * %f bytes) = %f bytes\n\n",SfArray_num_elements, Sfloat_size, SfArray_size);

	//***cArray[]***
	printf("\n\n");
	printf("In-Line Initialization and Piecemeal Display of Elements of 'cArray[]' : \n\n");
	printf("cArray[0] (1st Element) = %c\n", ScArray[0]);
	printf("cArray[1] (2nd Element) = %c\n", ScArray[1]);
	printf("cArray[2] (3rd Element) = %c\n", ScArray[2]);
	printf("cArray[3] (4th Element) = %c\n", ScArray[3]);
	printf("cArray[4] (5th Element) = %c\n", ScArray[4]);
	printf("cArray[5] (6th Element) = %c\n", ScArray[5]);
	printf("cArray[6] (7th Element) = %c\n", ScArray[6]);
	printf("cArray[7] (8th Element) = %c\n", ScArray[7]);
	printf("cArray[8] (9th Element) = %c\n", ScArray[8]);
	printf("cArray[9] (10th Element) = %c\n", ScArray[9]);
	printf("cArray[10] (11th Element) = %c\n", ScArray[10]);
	printf("cArray[11] (12th Element) = %c\n", ScArray[11]);
	printf("cArray[12] (13h Element) = %c\n", ScArray[13]);

	Schar_size = sizeof(char);
	ScArray_size = sizeof(ScArray);
	ScArray_num_elements = ScArray_size / Schar_size;
	printf("Size of datatype 'char' = %c bytes\n", Schar_size);
	printf("Number of Elements in 'char' Array 'cArray[]' = %c Elements\n", ScArray_num_elements);
	printf("Size of Array 'cArray[]' (%c elements * %c bytes) = %c bytes\n\n", ScArray_num_elements, Schar_size, ScArray_size);

	return(0);
}

















