#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Function Declarations
	char* ReplaceVowels(char *);

	// Variable Declarations
	char SUM_string[MAX_STRING_LENGTH];
	char *SUM_replaced_string = NULL;

	// Code
	printf("\n\n");
	printf("Enter a string  :");
	gets_s(SUM_string, MAX_STRING_LENGTH);

	SUM_replaced_string = ReplaceVowels(SUM_string);
	if (SUM_replaced_string == NULL)
	{
		printf("ReplaceVowels() Function has failed !!!. Exitting the loop now '''\n\n");
		exit(0);
	}
	printf("\n\n");
	printf("Replaced String is : \n\n");
	printf("%s\n\n", SUM_replaced_string);

	if (SUM_replaced_string)
	{
		free(SUM_replaced_string);
		SUM_replaced_string = NULL;
	}
	return(0);
}

// Function Definition ReplaceVowels()
char* ReplaceVowels(char *S)
{
	// Function Prototype
	void MyStrcpy(char*, char*);
	int MyStrlen(char*);

	// Variable Declarations
	char* new_string = NULL;
	int SUM_i;

	// Code
	new_string = (char*)malloc(MyStrlen(S) * sizeof(char));
	if (new_string == NULL)
	{
		printf("Could not Allocate memory for new String !!!\n\n");
		return(NULL);
	}

	MyStrcpy(new_string, S);
	for (SUM_i = 0; SUM_i < MyStrlen(new_string); SUM_i++)
	{
		switch (new_string[SUM_i])
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
			new_string[SUM_i] = '#';
			break;
		default:
			break;
		}
	}
	return (new_string);
}


void MyStrcpy(char* str_destination, char* str_source)
{
	//Function Prototype
	int MyStrlen(char*);

	//Variable Declarations
	int S_istring_length = 0;
	int S_j;

	//Code
	S_istring_length = MyStrlen(str_source);
	for (S_j = 0; S_j < S_istring_length; S_j++)
	{
		*(str_destination + S_j) = *(str_source + S_j);
	}
	*(str_destination + S_j) = '\0';
}

int MyStrlen(char* str)
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




















