#include <stdio.h>

int main(void)
{
	// Variable Declarations
	float S_fArray[10]; 
	int SUM_i;  
	
	// Code 
	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		S_fArray[SUM_i] = (float)(SUM_i + 1) * 1.5f;
	}
	printf("\n\n");
	printf("Elements of the Float  Aarray : \n\n");

	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		printf("fArray[%d] = %f \t\t Address = %p\n", SUM_i, S_fArray[SUM_i], &S_fArray[SUM_i]);
	}
	printf("\n\n");
	
	return(0);
}




