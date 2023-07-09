#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int S_iArray[10]; 
	int SUM_i;  
	
	// Code 
	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		S_iArray[SUM_i] = (SUM_i + 1) * 3;
	}
	printf("\n\n");
	printf("Elements of the Integer Aarray : \n\n");

	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		printf("iArray[%d] = %d \t\t Address = %p\n", SUM_i, S_iArray[SUM_i], &S_iArray[SUM_i]);
	}
	printf("\n\n");
	
	return(0);
}



