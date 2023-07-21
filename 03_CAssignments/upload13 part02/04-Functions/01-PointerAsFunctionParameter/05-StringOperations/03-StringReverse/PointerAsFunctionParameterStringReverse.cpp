#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Function Prototype
	void MyStrrev(char*, char*);
	int MyStrlen(char *);

	//Variable declarations
	char *S_chArray_Original = NULL;//A Character Array can be represented by a char pointer to mark the base address (char *)
	char *S_chArray_Reversed = NULL;//A Character Array can be represented by a char pointer to mark the base address (char *)
	int S_Original_Stringlength;

	//Code

	printf("\n\n");
	S_chArray_Original = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
	if (S_chArray_Original == NULL)
	{
		printf("Memory Allocation to character Array failed !!!Exitting now...\n\n");
		exit(0);
	}

	//***STRING INPUT***
	printf("Enter a String : \n\n");
	gets_s(S_chArray_Original, MAX_STRING_LENGTH);

	S_Original_Stringlength = MyStrlen(S_chArray_Original);
	S_chArray_Reversed = (char*)malloc(S_Original_Stringlength * sizeof(char));
	if (S_chArray_Reversed == NULL)
	{
		printf("Memory Allocation for copied string !!!Exitting now....\n\n");
		exit(0);
	}

	//*** STRING REV***
	MyStrrev(S_chArray_Reversed, S_chArray_Original);

	
	//***STRING OUTPUT***
	printf("\n\n");
	printf("String Entered by you (ch_Array_Original) is : \n\n");
	printf("%s \n", S_chArray_Original); //STRING OUTPUT

	//***STRING LENGTH Copied***
	printf("\n\n");
	printf("The reversed String is (ch_Array_reversed) =\n\n");
	printf("%s \n", S_chArray_Reversed);

	if (S_chArray_Reversed)
	{
		free(S_chArray_Reversed);
		S_chArray_Reversed = NULL;
		printf("\n\n");
		printf("Memory Allocated for copied string has been Freed!....\n\n");
	}

	if (S_chArray_Original)
	{
		free(S_chArray_Original);
		S_chArray_Original = NULL;
		printf("\n\n");
		printf("Memory Allocated for copied string has been Freed!....\n\n");
	}
	return(0);
}

//***Function***

void MyStrrev(char *str_destination, char *str_source)
{
	//Function Prototype
	int MyStrlen(char *);

	//Variable Declarations
	int S_istring_length = 0;
	int S_j, S_i, S_len;

	//Code
	S_istring_length = MyStrlen(str_source); 

	// Since Arrays begin from 0th index
	S_len = S_istring_length - 1;

	// char of 'str_source' 0th index >> 1st index of str_destination

	for (S_i = 0, S_j = S_len; S_i < S_istring_length; S_i++, S_j--)
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


















