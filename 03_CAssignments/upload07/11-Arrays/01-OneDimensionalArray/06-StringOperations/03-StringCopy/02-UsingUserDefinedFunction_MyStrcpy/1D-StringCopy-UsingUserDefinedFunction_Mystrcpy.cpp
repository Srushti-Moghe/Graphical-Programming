#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Function Prototype
	void MyStrcpy(char[], char[]);

	//Variable declarations
	char S_chArray_Original[MAX_STRING_LENGTH], S_chArray_Copy[MAX_STRING_LENGTH];//A Character Array is a String
	
	//Code

	//***STRING INPUT***
	printf("\n\n");
	printf("Enter a String : \n\n");
	gets_s(S_chArray_Original, MAX_STRING_LENGTH); //STRING INPUT

	//***STRING COPY***
	MyStrcpy(S_chArray_Copy, S_chArray_Original);
	
	//***STRING OUTPUT***
	//for S_chArray_Original
	printf("\n\n");
	printf("The Original String (ch_Array_Original[]) Entered by you is : \n\n");
	printf("%s \n", S_chArray_Original); //STRING OUTPUT
	//for S_chArray_Copy
	printf("\n\n");
	printf("The Copied String (chArray_Copy[]) is : \n\n");
	printf("%s \n", S_chArray_Copy); //STRING OUTPUT

	return(0);
}
//***Function MyStrcpy()***
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
//***Function MyStrlen()***
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















