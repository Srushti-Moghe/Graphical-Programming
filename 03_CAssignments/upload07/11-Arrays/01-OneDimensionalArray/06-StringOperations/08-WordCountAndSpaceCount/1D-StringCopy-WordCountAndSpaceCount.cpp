#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Function Prototype
	void MyStrlen(char[]);
	void MyStrcpy(char[], char[]);

	//Variable declarations
	char S_chArray[MAX_STRING_LENGTH];//A Character Array is a String
	int S_iStringLength;
	int S_i;
	int S_word_count = 0, S_space_count = 0;

	//Code

	//***STRING INPUT***
	printf("\n\n");
	printf("Enter a String : \n\n");
	gets_s(S_chArray, MAX_STRING_LENGTH); //STRING INPUT

	S_iStringLength = MyStrlen(S_chArray);
	
	for (S_i = 0; S_i < S_iStringLength; S_i++)
	{
		switch (S_chArray[S_i])
		{
		case 32:      //ASCII Value forr space = 32
			S_space_count++;
			break;
		default:
			break;
		}
	}
	S_word_count = S_space_count + 1;

	//***STRING OUTPUT***
	printf("\n\n");
	printf("The String Entered by You is : \n\n");
	printf("%s\n", S_chArray);

	printf("\n\n");
	printf("Number of Spaces in the Input String = %d\n\n", S_space_count);
	printf("Number of Words in the Input String = %d\n\n", S_word_count);

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




