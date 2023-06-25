#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Function Prototype
	void MyStrcpy(char[], char[]);

	//Variable declarations
	char S_chArray_Original[MAX_STRING_LENGTH];//A Character Array is a String
	
	//Code

	//***STRING INPUT***
	printf("\n\n");
	printf("Enter a String : \n\n");
	gets_s(S_chArray_Original, MAX_STRING_LENGTH); //STRING INPUT

	//***STRING OUTPUT***
	//for S_chArray_Original
	printf("\n\n");
	printf("The Original String (ch_Array_Original[]) Entered by you is : \n\n");
	printf("%s \n", S_chArray_Original); //STRING OUTPUT
	//for S_chArray_Reversed
	printf("\n\n");
	printf("The Reversed String (chArray_Reverse[]) is : \n\n");
	printf("%s \n", strrev(S_chArray_Original)); //STRING OUTPUT for REVERSED STRING

	return(0);
}







