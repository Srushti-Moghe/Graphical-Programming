#include <stdio.h>

int main(void)
{
	// Variable Declarations
	double S_dArray[10]; 
	int SUM_i;  
	
	// Code 
	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		S_dArray[SUM_i] = (float)(SUM_i + 1) * 1.4545454545f;
	}
	printf("\n\n");
	printf("Elements of the double Aarray : \n\n");

	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		printf("dArray[%d] = %lf \t\t Address = %p\n", SUM_i, S_dArray[SUM_i], &S_dArray[SUM_i]);
	}
	printf("\n\n");
	
	return(0);
}






