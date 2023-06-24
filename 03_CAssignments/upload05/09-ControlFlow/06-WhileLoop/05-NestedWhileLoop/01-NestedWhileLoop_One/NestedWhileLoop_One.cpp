#include <stdio.h>
int main(void)
{
	//variable declarations
	int SUMi, SUMj;

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
			SUMj++;
		}
		SUMi++;
		printf("\n\n");
	}
	printf("\n\n");

	return(0);

}





