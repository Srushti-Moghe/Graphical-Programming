#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Variable declarations
	char S_chArray_Original[MAX_STRING_LENGTH], S_chArray_Copy[MAX_STRING_LENGTH];//A Character Array is a String
	
	//Code

	//***STRING INPUT***
	printf("\n\n");
	printf("Enter a String : \n\n");
	gets_s(S_chArray_Original, MAX_STRING_LENGTH); //STRING INPUT

	//***STRING COPY***
	strcpy(S_chArray_Copy, S_chArray_Original);
	
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















