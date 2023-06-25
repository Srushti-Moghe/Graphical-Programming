// THis program replaces att the 'Vowels' with '*'
//ASTROMEDICOMP >> *STR*M*D*C*MP

#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Function Prototype
	void MyStrlen(char[]);
	void MyStrcpy(char[], char[]);

	//Variable declarations
	char S_chArray_Original[MAX_STRING_LENGTH], S_chArray_VowelsReplaced[MAX_STRING_LENGTH];//A Character Array is a String
	int S_iStringLength;
	int S_i;

	//Code

	//***STRING INPUT***
	printf("\n\n");
	printf("Enter a String : \n\n");
	gets_s(S_chArray_Original, MAX_STRING_LENGTH); //STRING INPUT

	MyStrcpy(S_chArray_VowelsReplaced, S_chArray_Original);

	S_iStringLength = MyStrlen(S_chArray_VowelsReplaced);
	
	for (S_i = 0; S_i < S_iStringLength; S_i++)
	{
		switch (S_chArray_VowelsReplaced[S_i])
		{
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'U':
		case 'u':
			S_chArray_VowelsReplaced[S_i] = '*';
			break;
		default:
			break;
		}
	}

	//***STRING OUTPUT***
	printf("\n\n");
	printf("The String Entered by You is : \n\n");
	printf("%s\n", S_chArray_Original);

	printf("\n\n");
	printf("String after Replacement of Vowels by'*' is : \n\n");
	printf("%s\n", S_chArray_VowelsReplaced);

	return(0);
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

//Function - MyStrcpy()
void MyStrcpy(char str_destination[], char str_source[])
{
	//Function Prototype
	int MyStrlen(char[]);

	//Variable Declarations
	int S_istring_length = 0;
	int S_j;

	//Code
	S_istring_length = MyStrlen(str_source);
	for (S_j = 0; S_j < S_istring_length; S_j++)
	{
		str_destination[S_j] = str_source[S_j];
	}
	str_destination[S_j] = '\0';
}



