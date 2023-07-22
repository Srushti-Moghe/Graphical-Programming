#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Function Prototype
	int MyStrlen(char *);

	//Variable declarations
	char *S_chArray = NULL;//A Character Array can be represented by a chhara pointer to mark the base address (char *)
	int S_iString_length = 0;

	//Code

	printf("\n\n");
	S_chArray = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
	if (S_chArray == NULL)
	{
		printf("Memory Allocation to character Array failed !!!Exitting now...\n\n");

	}

	//***STRING INPUT***
	printf("Enter a String : \n\n");
	gets_s(S_chArray, MAX_STRING_LENGTH);
	
	//***STRING OUTPUT***
	printf("\n\n");
	printf("String Entered by you is : \n\n");
	printf("%s \n", S_chArray); //STRING OUTPUT

	//***STRING LENGTH***
	printf("\n\n");
	S_iString_length = MyStrlen(S_chArray);
	printf("Length of String is = %d Characters !!!\n\n", S_iString_length);

	if (S_chArray)
	{
		free(S_chArray);
		S_chArray = NULL;
	}

	return(0);
}

//***Function***
int MyStrlen(char *str)
{
	int S_j;
	int S_string_length = 0;

	//Code
	//***Determining exact Length of the String, by detecting the first occurence of Null-Terminating Character (\0)***

	for (S_j = 0; S_j < MAX_STRING_LENGTH; S_j++)
	{
		if (*(str + S_j) == '\0')
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


















