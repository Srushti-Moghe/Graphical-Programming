#include <stdio.h>
int main(void)
{
	// Variable declarations
	int SUMi, SUMj;
	//code
	printf("\n\n");

	printf("Printing Digits 1 - 10 and 10 - 100 : \n\n");

	SUMi = 1;
	SUMj = 10;
	do 
	{
		printf("\t %d \t %d \n", SUMi, SUMj);
		SUMi++;
		SUMj = SUMj + 10;
	} while (SUMi <= 10, SUMj <= 100);

	printf("\n\n");

	return(0);
}





