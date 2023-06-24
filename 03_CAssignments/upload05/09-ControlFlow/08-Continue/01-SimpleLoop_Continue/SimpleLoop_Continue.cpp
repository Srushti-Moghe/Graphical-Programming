#include <stdio.h>
int main(void)
{
	//Variable Declarations 
	int SUMi;

	//Code
	printf("\n\n");

	printf("Printing Even Numbers from 0 to 100: \n\n");

	for (SUMi = 0; SUMi <= 100; SUMi++)
	{
		//For a number to be even, its division by 2 should give the remainder as zero 
		//When the remainder is not 0, it is an odd number

		if (SUMi % 2 != 0)
		{
			continue;
		}
		else
		{
			printf("\t%d\n", SUMi);
		}
	}

	printf("\n\n");
	
	return(0);
}

