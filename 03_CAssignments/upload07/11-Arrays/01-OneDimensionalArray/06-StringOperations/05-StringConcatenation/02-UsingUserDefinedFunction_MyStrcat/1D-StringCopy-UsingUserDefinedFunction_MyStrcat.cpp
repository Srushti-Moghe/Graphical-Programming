#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Function Prototype
	void MyStrcat(char[], char[]);

	//Variable declarations
	char S_chArray_One[MAX_STRING_LENGTH], S_chArray_Two[MAX_STRING_LENGTH];//A Character Array is a String
	
	//Code

	//***STRING INPUT***
	printf("\n\n");
	printf("Enter First String : \n\n");
	gets_s(S_chArray_One, MAX_STRING_LENGTH); //STRING INPUT

	printf("\n\n");
	printf("Enter Second String : \n\n");
	gets_s(S_chArray_Two, MAX_STRING_LENGTH); //STRING INPUT

	//***STRING CONCAT***
	printf("\n\n");
	printf("***** BEFORE CONCATENATION *****");
	//String-1
	printf("\n\n");
	printf("The Original First String Entered by the user (i.e.'chArray_One[]' is :\n\n");
	printf("%s\n", S_chArray_One);
	//String-2
	printf("\n\n");
	printf("The Original Second String Entered by the user (i.e.'chArray_Two[]' is :\n\n");
	printf("%s\n", S_chArray_Two);

	//Concatenation
	
	MyStrcat(S_chArray_One, S_chArray_Two);

	printf("\n\n");
	printf("***** AFTER CONCATENATION *****");
	//String-1
	printf("\n\n");
	printf(" 'ch_Array_One[]' :\n\n");
	printf("%s\n", S_chArray_One);
	//String-2
	printf("\n\n");
	printf(" 'ch_Array_Two[]' :\n\n");
	printf("%s\n", S_chArray_Two);
	
	return(0);
}

//Function - MyStrcat
void MyStrcat(char str_destination[], char str_source[])
{
	//Function Prototype
	int MyStrlen(char[]);

	//Variable Declarations
	int S_iStringLength_source = 0, S_iStringLength_destination = 0;
	int S_i, S_j;

	//Code
	S_iStringLength_source = MyStrlen(str_source);
	S_iStringLength_destination = MyStrlen(str_destination);

	//Array indices begin from 0, hence last valid index of Array will always be (Length - 1)
	//So Concatenation must begin from index number equal to the length of array 'str_destination'
	//We need to put the character which is at first index of 'str_source' to the (Last Index + 1) of 'str_destination'

	for (S_i = S_iStringLength_destination, S_j = 0; S_j < S_iStringLength_source; S_i++, S_j++)
	{
		str_destination[S_i] = str_source[S_j];
	}
	str_destination[S_i] = '\0';
}

//Function - MyStrlen()
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





