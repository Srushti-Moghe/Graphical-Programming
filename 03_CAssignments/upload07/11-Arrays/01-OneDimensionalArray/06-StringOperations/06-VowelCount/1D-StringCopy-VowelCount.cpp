#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Function Prototype
	void MyStrlen(char[]);

	//Variable declarations
	char S_chArray[MAX_STRING_LENGTH];//A Character Array is a String
	int S_iStringLength;
	int S_count_A = 0, S_count_E = 0, S_count_I = 0, S_count_O = 0, S_count_U = 0; //Inital COunts for the vowels = 0
	int S_i;

	//Code

	//***STRING INPUT***
	printf("\n\n");
	printf("Enter First String : \n\n");
	gets_s(S_chArray, MAX_STRING_LENGTH); //STRING INPUT

	//***STRING OUTPUT***
	printf("\n\n");
	printf("String Entered by you is : \n\n");
	printf("%s\n", S_chArray); //STRING OUTPUT

	S_iStringLength = MyStrlen(S_chArray);

	for (S_i = 0; S_i < S_iStringLength; S_i++)
	{
		switch (S_chArray[S_i])
		{
		case 'A':
		case 'a':
			S_count_A++;
			break;
		case 'E':
		case 'e':
			S_count_E++;
			break;
		case 'I':
		case 'i':
			S_count_I++;
			break;
		case 'O':
		case 'o':
			S_count_O++;
			break;
		case 'U':
		case 'u':
			S_count_U++;
			break;
		default:
			break;
		}
	}

	printf("\n\n");
	printf("In the string entered by you, the vowels and the number of their Occurences are as follows : \n\n");

	printf("'A' has occured = %d times !!! \n\n", S_count_A);
	printf("'E' has occured = %d times !!! \n\n", S_count_E);
	printf("'I' has occured = %d times !!! \n\n", S_count_I);
	printf("'O' has occured = %d times !!! \n\n", S_count_O);
	printf("'U' has occured = %d times !!! \n\n", S_count_U);

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




