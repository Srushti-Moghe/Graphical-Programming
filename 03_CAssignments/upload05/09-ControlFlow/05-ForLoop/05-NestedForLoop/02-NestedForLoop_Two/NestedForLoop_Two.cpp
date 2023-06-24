#include <stdio.h>
int main(void)
{
	//variable declarations
	int SUMi, SUMj, SUMk;

	//code
	printf("\n\n");

	for (SUMi = 1; SUMi <= 10; SUMi++)
	{
		printf("i = %d\n", SUMi);
		printf("-------\n\n");
		for (SUMj = 1; SUMj <= 5; SUMj++)
		{
			printf("\tj = %d\n", SUMj);
			printf("-------\n\n");
			for (SUMk = 1; SUMk <= 3; SUMk++)
			{
				printf("\t\tk = %d\n", SUMk);
			}
			printf("\n\n");
		}
		printf("\n\n");
	}
	printf("\n\n");

	return(0);

}


