#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Function Prototype
	void MyStrcpy(char[], char[]);

	//Variable Declarations

	//*** A 'STRING' is an array of characters ... so char[] is a char array and hence char[] is a STRING
	//***!!! An array of char Arrays is an Array of Strings !!!***
	//Hence, char[] is one char array and hence, is ONE STRING
	//Hence, char[][] is an array of char arrays and hence, is an ARRAY OF STRINGS

	//Here, the string array can allow a maximum number of 10 Strings (10rows) and each of these 10 strings can have only upto 15 characters max (15 Columns)
	char S_strArray[5][10]; //5Roows (0,1.2,3,4) and 5 Strings (each can have MAxof 10 characters)
	int S_char_size;
	int S_strArray_size;
	int S_strArray_num_elements, S_strArray_num_rows, S_strArray_num_columns;
	int S_i;

	//Code
	printf("\n\n");

	S_char_size = sizeof(char);

	S_strArray_size = sizeof(S_strArray);
	printf("Size of two dimensional 2D Character Array (String) is = %d\n\n", S_strArray_size);

	S_strArray_num_rows = S_strArray_size / sizeof(S_strArray[0]);
	printf("Number of Rows in two dimensional 2D Character (String) array is = %d\n\n", S_strArray_num_rows);

	S_strArray_num_columns = sizeof(S_strArray[0]) / S_char_size;
	printf("Number of Columns in two dimensional 2D Character array (String) is = %d\n\n", S_strArray_num_columns);

	S_strArray_num_elements = S_strArray_num_rows * S_strArray_num_columns;
	printf("Number of Elements in two dimensional 2D Character array (String) is = %d\n\n", S_strArray_num_elements);

	printf("\n\n");
	printf("Elements in 2D array : \n\n");

	//PIECE-MEAL ASSIGNMENT
	MyStrcpy(S_strArray[0], "My");
	MyStrcpy(S_strArray[1], "Name");
	MyStrcpy(S_strArray[2], "is");
	MyStrcpy(S_strArray[3], "Srushti");
	MyStrcpy(S_strArray[4], "Moghe");

	printf("\n\n");
	printf("The strings in the 2D character array are : \n\n");

	for (S_i = 0; S_i < S_strArray_num_rows; S_i++)
	{
		printf("%s ", S_strArray[S_i]);
	}
	printf("\n\n");

	return(0);
}

void MyStrcpy(char str_destination[], char str_source[])
{
	//Function Prototype
	int MyStrlen(char[]);

	//Variable Declarations
	int SiStringLength = 0;
	int S_j;

	//Code
	SiStringLength = MyStrlen(str_source);
	for (S_j = 0; S_j < SiStringLength; S_j++)
		str_destination[S_j] = str_source[S_j];

	str_destination[S_j] = '\0';
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





