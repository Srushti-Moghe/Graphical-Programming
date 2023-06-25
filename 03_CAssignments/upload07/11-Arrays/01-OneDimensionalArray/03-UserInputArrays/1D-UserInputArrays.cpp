#include <stdio.h>
#include <conio.h>

//MACRO constant used as arraysize in subscript and as an array lemngth.
//Hence, this program's Array Sizes can be simply changed by changing these following three Global MACRO constant values, before Compiling, Linking and Executing the Program!

#define INT_ARRAY_NUM_ELEMENTS 5
#define FLOAT_ARRAY_NUM_ELEMENTS 3
#define CHAR_ARRAY_NUM_ELEMENTS 15

int main(void)
{
	//Variable declarations
	int SiArray[INT_ARRAY_NUM_ELEMENTS];
	float SfArray[FLOAT_ARRAY_NUM_ELEMENTS];
	char ScArray[CHAR_ARRAY_NUM_ELEMENTS];
	int Si, Snum;
	
	//Code

	//***ARRAY ELEMENTS INPUT***
	printf("\n\n");
	printf("Enter Elements for 'Integer' Array : \n");
	for (Si = 0; Si < INT_ARRAY_NUM_ELEMENTS; Si++)
	{
		scanf("%d", &SiArray[Si]);
	}
	printf("\n\n");
	printf("Enter Elements for 'Floating-Point' Array : \n");
	for (Si = 0; Si < FLOAT_ARRAY_NUM_ELEMENTS; Si++)
	{
		scanf("%f", &SfArray[Si]);
	}
	printf("\n\n");
	printf("Enter Elements for 'Character' Array : \n");
	for (Si = 0; Si < CHAR_ARRAY_NUM_ELEMENTS; Si++)
	{
		ScArray[Si] = getch();
		printf("%c\n", ScArray[Si]);
	}

	//***ARRAY ELEMENTS OUTPUT***
	printf("\n\n");
	printf("Integer Array Entered by the user : \n\n");
	for (Si = 0; Si < INT_ARRAY_NUM_ELEMENTS; Si++)
	{
		printf("%d\n", SiArray[Si]);
	}

	printf("\n\n");
	printf("Float Array Entered by the user : \n\n");
	for (Si = 0; Si < FLOAT_ARRAY_NUM_ELEMENTS; Si++)
	{
		printf("%f\n", SfArray[Si]);
	}

	printf("\n\n");
	printf("Character Array Entered by the user : \n\n");
	for (Si = 0; Si < CHAR_ARRAY_NUM_ELEMENTS; Si++)
	{
		printf("%c\n", ScArray[Si]);
	}

	return(0);
}














