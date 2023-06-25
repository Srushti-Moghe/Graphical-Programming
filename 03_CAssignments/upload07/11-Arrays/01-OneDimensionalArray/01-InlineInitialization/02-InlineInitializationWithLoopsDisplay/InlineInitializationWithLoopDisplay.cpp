#include <stdio.h>
int main(void)
{
	//Variable declarations
	int SiArray[] = { 9, 30, 6, 12, 98, 30, 85, 45 };
	int Sint_size;
	int SiArray_size;
	int SiArray_num_elements;

	float SfArray[] = { 1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f, 7.8f, 8.9f };
	int Sfloat_size;
	int SfArray_size;
	int SfArray_num_elements;

	char ScArray[] = { 'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P' };
	int Schar_size;
	int ScArray_size;
	int  ScArray_num_elements;

	int Si;

	//Code

	//***iArray[]***
	printf("\n\n");
	printf("In-Line Initialization and Loop(for) Display of Elements of 'iArray[]' : \n\n");
	
	Sint_size = sizeof(int);
	SiArray_size = sizeof(SiArray);
	SiArray_num_elements = SiArray_size / Sint_size;

	for (Si = 0; Si < SiArray_num_elements; Si++)
	{
		printf("iArray[%d] (Element %d) = %d\n", Si, (Si + 1), SiArray[Si]);
	}
	printf("\n\n");
	printf("Size of datatype 'int' = %d bytes\n", Sint_size);
	printf("Number of Elements in 'int' Array 'iArray[]' = %d Elements\n", SiArray_num_elements);
	printf("Size of Array 'iArray[]' (%d elements * %d bytes) = %d bytes\n\n", SiArray_num_elements, Sint_size, SiArray_size);

	//***fArray[]***
	printf("\n\n");
	printf("In-Line Initialization and Piecemeal Display of Elements of 'fArray[]' : \n\n");

	Sfloat_size = sizeof(float);
	SfArray_size = sizeof(SfArray);
	SfArray_num_elements = SfArray_size / Sfloat_size;

	for (Si = 0; Si < SfArray_num_elements; Si++)
	{
		printf("fArray[%d] (Element %d) = %f\n", Si, (Si + 1), SfArray[Si]);
		//printf("cArray[%d] (Element %d) = %c\n", Si, (Si + 1), ScArray[Si]);
	}
	printf("\n\n");
	printf("Size of datatype 'float' = %d bytes\n", Sfloat_size);
	printf("Number of Elements in 'float' Array 'fArray[]' = %d Elements\n", SfArray_num_elements);
	printf("Size of Array 'fArray[]' (%d elements * %d bytes) = %d bytes\n\n", SfArray_num_elements, Sfloat_size, SfArray_size);

	//***cArray[]***
	printf("\n\n");
	printf("In-Line Initialization and Piecemeal Display of Elements of 'cArray[]' : \n\n");

	Schar_size = sizeof(char);
	ScArray_size = sizeof(ScArray);
	ScArray_num_elements = ScArray_size / Schar_size;

	for (Si = 0; Si < ScArray_num_elements; Si++)
	{
		printf("cArray[%d] (Element %d) = %c\n", Si, (Si + 1), ScArray[Si]);
	}

	printf("Size of datatype 'char' = %d bytes\n", Schar_size);
	printf("Number of Elements in 'char' Array 'cArray[]' = %d Elements\n", ScArray_num_elements);
	printf("Size of Array 'cArray[]' (%c elements * %c bytes) = %d bytes\n\n", ScArray_num_elements, Schar_size, ScArray_size);

	return(0);
}














