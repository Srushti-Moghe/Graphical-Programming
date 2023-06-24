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
	int S_char_size;
	int S_strArray_size;
	int S_strArray_num_elements, S_strArray_num_rows, S_strArray_num_columns;
	int S_strActual_num_chars = 0;
	int S_i;

	//Code
	printf("\n\n");

	S_char_size = sizeof(char);

	S_strArray_size = sizeof(S_strArray);
	printf("Size of two dimensional 2D Character Array (String Array) is = %d\n\n", S_strArray_size);

	S_strArray_num_rows = S_strArray_size / sizeof(S_strArray[0]);
	printf("Number of Rows (Strings) in two dimensional 2D Character Array (String Array) is = %d\n\n", S_strArray_num_rows);

	S_strArray_num_columns = sizeof(S_strArray[0]) / S_char_size;
	printf("Number of Columns (Strings) in two dimensional 2D Character Array (String Array) is = %d\n\n", S_strArray_num_columns);

	S_strArray_num_elements = S_strArray_num_rows * S_strArray_num_rows;
	printf("Number of Elements (Characters) in two dimensional 2D Character Array (String Array) is = %d\n\n", S_strArray_num_elements);

	for (S_i = 0; S_i < S_strArray_num_rows; S_i++)
	{
		S_strActual_num_chars = S_strActual_num_chars + MySterlen(S_strArray[S_i]);
	}
	printf("Actual Number of Elements (Characters) in Two Dimensional (2D) Char Array (String Array i = %d\n\n", S_strActual_num_chars);

	printf("\n\n");
	printf("Strings in the 2D Array : \n\n");

	//Since char[][] is an array of strings, referencing only by the row number (first []) will give the row or string
	//The Column Number (second[]) is the particular character in that string / row
	printf("%s", S_strArray[0]);
	printf("%s", S_strArray[1]);
	printf("%s", S_strArray[2]);
	printf("%s", S_strArray[3]);
	printf("%s", S_strArray[4]);
	printf("%s", S_strArray[5]);
	printf("%s", S_strArray[6]);
	printf("%s", S_strArray[7]);
	printf("%s", S_strArray[8]);
	printf("%s\n\n", S_strArray[9]);

	return(0);
}

int MySterlen(char str[])
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



