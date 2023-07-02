#include <stdio.h>
#include <string.h>
 
#define INT_ARRAY_SIZE 10    // Number of elements in the Integer Array
#define FLOAT_ARRAY_SIZE 5  // Number of elements in the Floating-Point Array
#define CHAR_ARRAY_SIZE 26 // Number of elements in the Character Array

#define NUM_STRINGS 10
#define MAX_CHARACTERS_PER_STRING 10

#define ALPHABET_BEGINNINGS 65 // ASCII value for 'A'

struct SUM_MyData_1   // Defining struct 1
{
	int S_iArray[INT_ARRAY_SIZE];
	float S_fArray[FLOAT_ARRAY_SIZE];
};

struct SUM_MyData_2  // Defining struct 2
{
	char S_cArray[CHAR_ARRAY_SIZE];
	char S_strArray[NUM_STRINGS][MAX_CHARACTERS_PER_STRING];
};

int main(void)
{
	// struct variable declarations
	struct SUM_MyData_1 SUM_Data_1;
	struct SUM_MyData_2 SUM_Data_2;

	int SUM_i;

	// Code
	
	//Piece-Meal hard coded struct values
	// For 'struct SUM_Data_1 >> S_fArray
	SUM_Data_1.S_fArray[0] = 0.1f;
	SUM_Data_1.S_fArray[1] = 1.2f;
	SUM_Data_1.S_fArray[2] = 2.3f;
	SUM_Data_1.S_fArray[3] = 3.4f;
	SUM_Data_1.S_fArray[4] = 4.5f;

	// User-Input Integer Array using Loop
	printf("\n\n");
	printf("Enter %d Integers : \n", INT_ARRAY_SIZE);
	for (SUM_i = 0; SUM_i < INT_ARRAY_SIZE; SUM_i++)
	{
		scanf("%d", &SUM_Data_1.S_iArray[SUM_i]);
	}

	// User-Input Character Array using Loop
	printf("\n\n");
	for (SUM_i = 0; SUM_i < CHAR_ARRAY_SIZE; SUM_i++)
	{
		SUM_Data_2.S_cArray[SUM_i] = (char)(SUM_i + ALPHABET_BEGINNINGS);
	}

	//Piece-Meal hard coded struct values
	// For 'struct SUM_Data_2 >> S_strArray
	strcpy(SUM_Data_2.S_strArray[0], "Welcome !!!");
	strcpy(SUM_Data_2.S_strArray[1], "This");
	strcpy(SUM_Data_2.S_strArray[2], "Is");
	strcpy(SUM_Data_2.S_strArray[3], "Astromedicomp's");
	strcpy(SUM_Data_2.S_strArray[4], "Real");
	strcpy(SUM_Data_2.S_strArray[5], "Time");
	strcpy(SUM_Data_2.S_strArray[6], "Rendering");
	strcpy(SUM_Data_2.S_strArray[7], "Batch");
	strcpy(SUM_Data_2.S_strArray[8], "Of");
	strcpy(SUM_Data_2.S_strArray[9], "2023-2024");

	// To Display the Data members of 'struct SUM_Data_1' and their values
	printf("\n\n");
	printf("Members of 'struct SUM_Data_1' along with their assigned values are : \n\n ");

	printf("\n\n");
	printf("Integer Array (SUM_Data_1.S_iArray[]) : \n\n");
	for (SUM_i = 0; SUM_i < INT_ARRAY_SIZE; SUM_i++)
	{
		printf("SUM_Data_1.S_iArray[%d] = %d\n", SUM_i, SUM_Data_1.S_iArray[SUM_i]);
	}

	printf("\n\n");
	printf("Floating-Point Array (SUM_Data_1.S_fArray[]) : \n\n");
	for (SUM_i = 0; SUM_i < FLOAT_ARRAY_SIZE; SUM_i++)
	{
		printf("SUM_Data_1.S_fArray[%d] = %f\n", SUM_i, SUM_Data_1.S_fArray[SUM_i]);
	}

	// To Display the Data members of 'struct SUM_Data_2' and their values
	printf("\n\n");
	printf("Members of 'struct SUM_Data_2' along with their assigned values are : \n\n ");

	printf("\n\n");
	printf("Character Array (SUM_Data_2.S_cArray[]) : \n\n");
	for (SUM_i = 0; SUM_i < CHAR_ARRAY_SIZE; SUM_i++)
	{
		printf("SUM_Data_2.S_cArray[%d] = %c\n", SUM_i, SUM_Data_2.S_cArray[SUM_i]);
	}

	printf("\n\n");
	printf("String Array (SUM_Data_2.S_strArray[]) : \n\n");
	for (SUM_i = 0; SUM_i < NUM_STRINGS; SUM_i++)
	{
		printf("SUM_Data_2.S_cArray = %s\n", SUM_Data_2.S_strArray[SUM_i]);
	}

	printf("\n\n");
}


