#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Function Prototype
	int MyStrlen(char[]);

	//Variable declarations
	char S_chArray[MAX_STRING_LENGTH];//A Character Array is a String
	int S_iString_length = 0;

	//Code

	//***STRING INPUT***
	printf("\n\n");
	printf("Enter a String : \n\n");
	gets_s(S_chArray, MAX_STRING_LENGTH); //STRING INPUT
	
	//***STRING OUTPUT***
	printf("\n\n");
	printf("String Entered by you is : \n\n");
	printf("%s \n", S_chArray); //STRING OUTPUT

	//***STRING LENGTH***
	printf("\n\n");
	S_iString_length = MyStrlen(S_chArray);
	printf("Length of String is = %d Characters !!!\n\n", S_iString_length);

	return(0);
}

//***Function***
int MyStrlen(char str[])
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














