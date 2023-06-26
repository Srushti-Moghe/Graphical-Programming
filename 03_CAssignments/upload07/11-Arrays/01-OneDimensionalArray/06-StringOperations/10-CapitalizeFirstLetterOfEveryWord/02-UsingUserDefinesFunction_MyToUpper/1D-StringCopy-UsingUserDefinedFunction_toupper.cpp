#include <stdio.h>


#define MAX_STRING_LENGTH 512
#define SPACE ' '
#define FULLSTOP '.'
#define EXCLAMATION '!'
#define QUESTION_MARK '?'
#define COMMA ','

int main(void)
{
	//Function Prototype
	int MyStrlen(char[]);
	char MyToUpper(char);

	//Variable declarations
	//To capitalise a letter of every word variable used - S_chArray_CapitalisedLetter
	char S_chArray[MAX_STRING_LENGTH], S_chArray_CapitalisedLetter[MAX_STRING_LENGTH];//A Character Array is a String
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
		if (S_i == 0) //First Letter Of any Sentence must be a Capital Letter
		{
			S_chArray_CapitalisedLetter[S_j] = MyToUpper(S_chArray[S_i]);
		}
		else if (S_chArray[S_i] == SPACE) //First letter of everySentence must be a Capital Letter. Words are separated by Spaces.
		{
			S_chArray_CapitalisedLetter[S_j] = S_chArray[S_i];
			S_chArray_CapitalisedLetter[S_j + 1] = MyToUpper(S_chArray[S_i + 1]);
			//Since, Alredy two characters (at indices i and i+1) have been considered in the else block
			//We are incrementing i(S_i) and j(s_j) by 1
			S_j++;
			S_i++;
		}
		else if ((S_chArray[S_i]) == FULLSTOP || S_chArray[S_i] == COMMA || S_chArray[S_i] == EXCLAMATION || S_chArray[S_i] == QUESTION_MARK && (S_chArray[S_i] != SPACE)) // First Letter of every word after the punctuation mark, in the sentence must be a Capital Letter. Words are Separated by Punctuations
		{
			S_chArray_CapitalisedLetter[S_j] = S_chArray[S_i];
			S_chArray_CapitalisedLetter[S_j + 1] = SPACE;
			S_chArray_CapitalisedLetter[S_j + 2] = MyToUpper(S_chArray[S_i]);
			//Since, Alredy two characters (at indices i and i+1) have been considered in the else block
			//We are incrementing i(S_i) and j(s_j) by 1
			S_j = S_j + 2;
			S_i++;
		}
		else
		{
			S_chArray_CapitalisedLetter[S_j] = S_chArray[S_i];
		}
		S_j++; 
	}
	S_chArray_CapitalisedLetter[S_j] = '\0';

	//***STRING OUTPUT***
	printf("\n\n");
	printf("The String Entered by You is : \n\n");
	printf("%s\n", S_chArray);

	printf("\n\n");
	printf("String after Capitalising First Letter of Each Word : \n\n");
	printf("%s\n", S_chArray_CapitalisedLetter);
	
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

//Function - MyToUpper()
char MyToUpper(char S_ch)
{
	//Variable Declarations
	int S_num;
	int S_c;

	//Code

	//(ASCII value of 'a' - 97) - (ASCII value of 'A' - 65) == 32
	//This subtraction / difference will give the exact difference between the upper and lower case counterparts of each letter of the alphabet
	// If this difference is subtracted from the ASCII values of a lower case letter, the resultant ASCII value will be that of its Upper case counterpart
	//This is the LOGIC for the conversion of Upper Case to Lower Case and vice-versa
	//ASCII values 'A' - 'Z' = 65 - 90.
	//ASCII values 'a' - 'z' = 97 - 122.

	S_num = 'a' - 'A';
	if ((int)S_ch >= 97 && (int)S_ch <= 122)
	{
		S_c = (int)S_ch - S_num;
		return((char)S_c);
	}
	else
		return(S_ch);
}




