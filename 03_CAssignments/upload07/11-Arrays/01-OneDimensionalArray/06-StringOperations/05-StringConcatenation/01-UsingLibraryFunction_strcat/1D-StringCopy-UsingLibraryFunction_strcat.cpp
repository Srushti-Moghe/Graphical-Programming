#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Variable declarations
	char S_chArray_One[MAX_STRING_LENGTH], S_chArray_Two[MAX_STRING_LENGTH];//A Character Array is a String
	
	//Code

	//***STRING INPUT***
	printf("\n\n");
	printf("Enter First String : \n\n");
	gets_s(S_chArray_One, MAX_STRING_LENGTH); //STRING INPUT

	printf("\n\n");
	printf("Enter Second String : \n\n");
	gets_s(S_chArray_Two, MAX_STRING_LENGTH); //STRING INPUT

	//***STRING CONCAT***
	printf("\n\n");
	printf("***** BEFORE CONCATENATION*****");
	//String-1
	printf("\n\n");
	printf("The Original First String Entered by the user (i.e.'chArray_One[]' is :\n\n");
	printf("%s\n", S_chArray_One);
	//String-2
	printf("\n\n");
	printf("The Original Second String Entered by the user (i.e.'chArray_Two[]' is :\n\n");
	printf("%s\n", S_chArray_Two);

	//Concatenation
	
	strcat(S_chArray_One, S_chArray_Two);

	printf("\n\n");
	printf("***** AFTER CONCATENATION*****");
	//String-1
	printf("\n\n");
	printf(" 'ch_Array_One[]' :\n\n");
	printf("%s\n", S_chArray_One);
	//String-2
	printf("\n\n");
	printf(" 'ch_Array_Two[]' :\n\n");
	printf("%s\n", S_chArray_Two);
	
	return(0);
}



