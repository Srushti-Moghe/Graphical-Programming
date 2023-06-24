#include <stdio.h>
int main(void)
{
	//variable declarations
	int SUMi, SUMj, SUMk;

	//code
	printf("\n\n");

	SUMi = 1;
	while (SUMi <= 10) 
	{
		printf("i = %d\n", SUMi);
		printf("-------\n\n");

		SUMj = 1;
		while (SUMj <= 5)
		{
			printf("\tj = %d\n", SUMj);
			printf("-------\n\n");

		    SUMk = 1;
			while (SUMk <= 3)
			{
				printf("\t\tk = %d\n", SUMk);
				SUMk++;
			}
			printf("\n\n");
			SUMj++;
		}
		printf("\n\n");
		SUMi++;
	}
	printf("\n\n");

	return(0);

}




