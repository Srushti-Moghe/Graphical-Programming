#include <stdio.h>

int main(void)
{
	// Variable Declarations
	char S_cArray[10]; 
	int SUM_i;  
	
	// Code 
	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		S_cArray[SUM_i] = (char)(SUM_i + 65);
	}
	printf("\n\n");
	printf("Elements of the character Aarray : \n\n");

	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		printf("cArray[%d] = %c \t\t Address = %p\n", SUM_i, S_cArray[SUM_i], &S_cArray[SUM_i]);
	}
	printf("\n\n");
	
	return(0);
}






