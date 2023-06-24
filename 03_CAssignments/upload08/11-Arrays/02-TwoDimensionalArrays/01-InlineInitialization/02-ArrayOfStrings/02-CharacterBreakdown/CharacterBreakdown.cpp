#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Function Prototype
	int MyStrlen(char[]);

	//Variable Declarations

	//*** A 'STRING' is an array of characters ... so char[] is a char array and hence char[] is a STRING
	//***!!! An array of char Arrays is an Array of Strings !!!***
	//Hence, char[] is one char array and hence, is ONE STRING
	//Hence, char[][] is an array of char arrays and hence, is an ARRAY OF STRINGS

	//Here, the string array can allow a maximum number of 10 Strings (10rows) and each of these 10 strings can have only upto 15 characters max (15 Columns)
	char S_strArray[10][15] = { "Hello", "Welcome", "To", "Real", "Time", "Rendering", "Batch", "(2023-24", "Of", "ASTROMEDICOMP." }; //In Line Initialization
	int S_iStrLengths[10]; //1D integer Stores lengths of those strings at corresponding indices in 'str array[]'
	int S_strArray_size;
	int S_strArray_num_rows;
	int S_i, S_j;

	//Code
	S_strArray_size = sizeof(S_strArray);
	S_strArray_num_rows = S_strArray_size / sizeof(S_strArray[0]);

	//Sorting in lengths of all strings
	for (S_i = 0; S_i < S_strArray_num_rows; S_i++)
		S_iStrLengths[S_i] = MyStrlen(S_strArray[S_i]);

	printf("\n\n");
	printf("The Entire String Array : ");
	for (S_i = 0; S_i < S_strArray_num_rows; S_i++)
		printf("%s", S_strArray[S_i]);

	printf("\n\n");
	printf("Strings in the 2D Array : ");

	//Since char[][] is an array of strings, referencing only by row numbers will give thw Row of the strinhg
	//The column numbre is the particular character in that string / Row
	for (S_i = 0; S_i < S_strArray_num_rows; S_i++)
	{
		printf("String Number %d = %s\n\n", (S_i + 1), S_strArray[S_i]);
		for (S_j = 0; S_j < S_iStrLengths[S_i]; S_j++)
		{
			printf("SCharacter %d = %c\n", (S_j + 1), S_strArray[S_i][S_j]);
		}
	}
	return(0);
}

int MyStrlen(char str[])
{
	//Variable Declarations
	int S_j;
	int S_string_length = 0;

	//Code
	//Determining the exact length of string (without\0), by detecting the occurence of NullTerminating Character
	for (S_j = 0; S_j < MAX_STRING_LENGTH; S_j++)
	{
		if (str[S_j] == '\0')
			break;
		else
			S_string_length++;
	}
	return(S_string_length);
}




