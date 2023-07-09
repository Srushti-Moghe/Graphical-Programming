#include <stdio.h>

int main(void)
{
	// Variable Declarations
	char S_cArray[10]; 
	char *ptr_S_cArray = NULL;
	int SUM_i;  
	
	// Code 
	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		S_cArray[SUM_i] = (char)(SUM_i + 65);
	}
	// Name of any Array == its Base Address i.e.
	// cArray[] == cArray OR
	// cfArray == cArray[0]
	// Assigning the Base Address of Array 'cArray[]' to an integer pointer 'ptr_cArray'
	
	ptr_S_cArray = S_cArray;  // Equivalent to ptr_S_cArray = &S_cArray[0]

	printf("\n\n");
	printf("Elements of the Character Aarray : \n\n"); for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		printf("cArray[%d] = %c\n", SUM_i, *(ptr_S_cArray + SUM_i));
	}
	printf("\n\n");

	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		printf("cArray[%d] = %c \t\t Address = %p\n", SUM_i, *(S_cArray + SUM_i), (ptr_S_cArray + SUM_i));
	}
	printf("\n\n");
	
	return(0);
}





