#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Variable declarations
	char S_chArray[MAX_STRING_LENGTH];//A Character Array is a String

	//Code
	printf("\n\n");
	printf("Enter a String : \n\n");
	gets_s(S_chArray, MAX_STRING_LENGTH); //STRING INPUT

	printf("\n\n");
	printf("String Entered by you is : \n\n");
	printf("%s \n", S_chArray); //STRING OUTPUT

	return(0);
}














