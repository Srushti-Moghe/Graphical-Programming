#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
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
	S_iString_length = strlen(S_chArray);
	printf("Length of String is = %d Characters !!!\n\n", S_iString_length);

	return(0);
}














