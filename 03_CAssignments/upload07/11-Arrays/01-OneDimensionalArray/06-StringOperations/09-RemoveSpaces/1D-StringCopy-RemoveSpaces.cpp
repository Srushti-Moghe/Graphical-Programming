#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Function Prototype
	void MyStrlen(char[]);
	void MyStrcpy(char[], char[]);

	//Variable declarations
	char S_chArray[MAX_STRING_LENGTH], S_chArray_SpacesRemoved[MAX_STRING_LENGTH];//A Character Array is a String
	int S_iStringLength;
	int S_i, S_j;

	//Code

	//***STRING INPUT***
	printf("\n\n");
	printf("Enter a String : \n\n");
	gets_s(S_chArray, MAX_STRING_LENGTH); //STRING INPUT

	S_iStringLength = MyStrlen(S_chArray);

	S_j = 0;
	for (S_i = 0; S_i < S_iStringLength; S_i++)
	{
		if ((S_chArray[S_i]) == ' ')
		{
			continue;
		}
		else
		{
			S_chArray_SpacesRemoved[S_j] = S_chArray[S_i];
			S_j++;
		}
	}
	S_chArray_SpacesRemoved[S_j] = '\0';

	//***STRING OUTPUT***
	printf("\n\n");
	printf("The String Entered by You is : \n\n");
	printf("%s\n", S_chArray);

	printf("\n\n");
	printf("String after Removal of Spaces is : \n\n");
	printf("%s\n", S_chArray_SpacesRemoved);
	
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




