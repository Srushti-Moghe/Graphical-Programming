#include <stdio.h>
int main(void)
{
	//Variable Declarations 
	int SUMi, SUMj;

	//Code
	printf("\n\n");

	SUMi = 1;
	do
	{
		printf("i = %d\n", SUMi);
		printf("----------\n\n");

		SUMj = 1;
		do
		{
			printf("\tj = %d\n", SUMj);
			SUMj++;
		} while (SUMj <= 5);
		SUMi++;
		printf("\n\n");
	} while (SUMi <= 10);

	return(0);
}

