#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Variable Declarations

	//*** A 'STRING' is an array of characters ... so char[] is a char array and hence char[] is a STRING
	//***!!! An array of char Arrays is an Array of Strings !!!***
	//Hence, char[] is one char array and hence, is ONE STRING
	//Hence, char[][] is an array of char arrays and hence, is an ARRAY OF STRINGS

	//Here, the string array can allow a maximum number of 10 Strings (10rows) and each of these 10 strings can have only upto 15 characters max (15 Columns)
	char S_strArray[5][10]; //5Rows (0,1.2,3,4) and 5 Strings (each can have MAxof 10 characters)
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
	printf("Maximum Number of Elements in two dimensional 2D Character array (String) is = %d\n\n", S_strArray_num_elements);
 
	//PIECE-MEAL ASSIGNMENT
	//ROW1 - STRING-1
	S_strArray[0][0] = 'M';
	S_strArray[0][1] = 'y';
	S_strArray[0][2] = '\0'; //Null-Terminating Character
	
	//ROW2 - STRING-2
	S_strArray[1][0] = 'N';
	S_strArray[1][1] = 'a';
	S_strArray[1][2] = 'm';
	S_strArray[1][3] = 'e';
	S_strArray[1][4] = '\0'; //Null-Terminating Character

	//ROW3 - STRING-3 
	S_strArray[2][0] = 'I';
	S_strArray[2][1] = 's';
	S_strArray[2][2] = '\0'; //Null-Terminating Character

	//ROW4 - STRING-4
	S_strArray[3][0] = 'S';
	S_strArray[3][1] = 'r';
	S_strArray[3][2] = 'u';
	S_strArray[3][3] = 's';
	S_strArray[3][4] = 'h';
	S_strArray[3][5] = 't';
	S_strArray[3][6] = 'i';
	S_strArray[3][7] = '\0'; //Null-Terminating Character

	//ROW5 - STRING-5
	S_strArray[4][0] = 'M';
	S_strArray[4][1] = 'o';
	S_strArray[4][2] = 'g';
	S_strArray[4][3] = 'h';
	S_strArray[4][4] = 'e';
	S_strArray[4][5] = '\0'; //Null-Terminating Character
	
	printf("\n\n");
	printf("The strings in the 2D character array are : \n\n");

	for (S_i = 0; S_i < S_strArray_num_rows; S_i++)
	{
		printf("%s ", S_strArray[S_i]);
	}
	printf("\n\n");

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





