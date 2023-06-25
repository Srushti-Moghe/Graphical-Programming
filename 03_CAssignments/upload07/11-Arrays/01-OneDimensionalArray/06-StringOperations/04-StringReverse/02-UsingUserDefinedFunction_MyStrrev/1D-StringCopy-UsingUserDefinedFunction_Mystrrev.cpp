#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Function Prototype
	void MyStrrev(char[], char[]);

	//Variable declarations
	char S_chArray_Original[MAX_STRING_LENGTH], S_chArray_Reversed[MAX_STRING_LENGTH];//A Character Array is a String
	
	//Code

	//***STRING INPUT***
	printf("\n\n");
	printf("Enter a String : \n\n");
	gets_s(S_chArray_Original, MAX_STRING_LENGTH); //STRING INPUT

	//***STRING REVERSE***
	MyStrrev(S_chArray_Reversed, S_chArray_Original);

	//***STRING OUTPUT***
	//for S_chArray_Original
	printf("\n\n");
	printf("The Original String (ch_Array_Original[]) Entered by you is : \n\n");
	printf("%s \n", S_chArray_Original); //STRING OUTPUT
	//for S_chArray_Reversed
	printf("\n\n");
	printf("The Reversed String (chArray_Reverse[]) is : \n\n");
	printf("%s \n", (S_chArray_Reversed)); //STRING OUTPUT for REVERSED STRING

	return(0);
}

//***Function - MyStrrev()***
void MyStrrev(char str_destination[], char str_source[])
{
	//Function Prototype
	int MyStrlen(char[]);

	//Variable Declarations
	int S_iString_length = 0;
	int S_i, S_j, S_len;
	
	//Code
	S_iString_length = MyStrlen(str_source);

	//Array indices begin with 0, hence the last index will always be (Length - 1)
	S_len = S_iString_length - 1;

	//We need to put the character which is at last index of 'str_source' to the first index of 'str_destination'
	//The Second Last characterof 'str_destination'
	//And second last character of 'str_source' to the second character of 'str_destination' and so on
	for (S_i = 0, S_j = S_len; S_i < S_iString_length, S_j >= 0; S_i++, S_j--)
	{
		str_destination[S_i] = str_source[S_j];
	}
	str_destination[S_i] = '\0';
}

//***Function - MyStrlen()***
int MyStrlen(char str[])
{
	//Variable Declarations
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







