#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Function Prototype
	void MyStrcat(char*, char*);
	int MyStrlen(char *);

	//Variable declarations
	char *S_chArray_One = NULL;		// A Character Array can be represented by a char pointer to mark the base address (char *)
	char *S_chArray_Two = NULL;		// A Character Array can be represented by a char pointer to mark the base address (char *)
	int S_Original_Stringlength;

	//Code

	printf("\n\n");
	S_chArray_One = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
	if (S_chArray_One == NULL)
	{
		printf("Memory Allocation to character Array failed !!!Exitting now...\n\n");
		exit(0);
	}

	//***STRING INPUT 01***
	printf("Enter a String : ");
	gets_s(S_chArray_One, MAX_STRING_LENGTH);

	S_chArray_Two = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
	if (S_chArray_Two == NULL)
	{
		printf("Memory Allocation to character Array failed !!!Exitting now...\n\n");
		exit(0);
	}

	//***STRING INPUT 02***
	printf("\n\n");
	printf("Enter another String : ");

	gets_s(S_chArray_Two, MAX_STRING_LENGTH);

	//*** STRING CONCAT***
	printf("\n\n");
	printf("***** Before Concatnation ****");
	printf("\n\n");
	printf("The first string entered by you is (chArray_One) : ");
	printf("%s\n", S_chArray_One);
	printf("\n\n");
	printf("The second string entered by you is (chArray_Two) : ");
	printf("%s\n", S_chArray_Two);

	MyStrcat(S_chArray_One, S_chArray_Two);

	//***STRING OUTPUT***
	printf("\n\n");
	printf("***** After Concatnation ****");
	printf("\n\n");
	printf("The first concatenated string is  : ");
	printf("%s\n", S_chArray_One);

	if (S_chArray_Two)
	{
		free(S_chArray_Two);
		S_chArray_Two = NULL;
		printf("\n\n");
		printf("Memory Allocated for second string has been Freed!....\n\n");
	}

	if (S_chArray_One)
	{
		free(S_chArray_One);
		S_chArray_One = NULL;
		printf("\n\n");
		printf("Memory Allocated for first string has been Freed!....\n\n");
	}
	return(0);
}

//***Function***

void MyStrcat(char *str_destination, char *str_source)
{
	//Function Prototype
	int MyStrlen(char *);

	//Variable Declarations
	int S_istring_length_Source = 0;
	int S_istring_length_Destination = 0;
	int S_j, S_i;

	//Code
	S_istring_length_Source = MyStrlen(str_source); 
	S_istring_length_Destination = MyStrlen(str_destination); 

	// Since Arrays begin from 0th index
	// char of 'str_source' 0th index >> 1st index of str_destination
	// Concatenation begins from the index equal to the length of array 'str_destination'
	// We need to put character at first index of 'str_source' to the last + 1 index of'str_destination'

	for (S_i = S_istring_length_Destination, S_j = 0; S_j < S_istring_length_Source; S_i++, S_j++)
	{
		*(str_destination + S_i) = *(str_source + S_j);
	}
	*(str_destination + S_i) = '\0';
}

int MyStrlen(char *str)
{
	int S_j;
	int S_string_length = 0;

	//Code
	//***Determining exact Length of the String, by detecting the first occurence of Null-Terminating Character (\0)***

	for (S_j = 0; S_j < MAX_STRING_LENGTH; S_j++)
	{
		if (str[S_j] == '\0')
		{
			break;
		}
		else
		{
			S_string_length++;
		}
	}
	return(S_string_length);
}


















