#include <stdio.h>
int main(void)
{
	// Variable declarations
	int SUMi, SUMj;
	//code
	printf("\n\n");
	printf("Printing Digits 10 - 1 and 100 - 1 : \n\n");

	for (SUMi = 10, SUMj = 100; SUMi >= 1, SUMj >= 10; SUMi--, SUMj = SUMj - 10)
	{
		printf("\t %d \t %d \n", SUMi, SUMj);
	}

	printf("\n\n");

	return(0);
}

