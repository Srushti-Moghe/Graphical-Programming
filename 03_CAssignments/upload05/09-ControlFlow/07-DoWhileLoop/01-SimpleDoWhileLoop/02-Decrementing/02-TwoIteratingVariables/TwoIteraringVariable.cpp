 #include <stdio.h>
int main(void)
{
	// Variable declarations
	int SUMi, SUMj;

	//code
	printf("\n\n");

	printf("Printing Digits 10 - 1 and 100 - 10 : \n\n");

	SUMi = 10;
	SUMj = 100;
	do 
	{
		printf("\t %d \t %d \n", SUMi, SUMj);
		SUMi--;
		SUMj = SUMj - 10;
	} while (SUMi >= 1, SUMj >= 10);

	printf("\n\n");

	return(0);
}







