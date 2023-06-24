#include <stdio.h>

int main(void)
{
	//variable declarations 
	int i;
	int j;
	int k;

	printf("\n\n");

	for (i = 1; i <= 5; i++)
	{
		printf("i = %d\n", i);
		for (j = 1; j <= 3; j++)
		{
			printf("j = %d\n\n", j);
			for (k = 1; k <= 1; k++)
			{
				printf("k = %d\n\n\n", k);
			}

		}
		
	}
	printf("\n\n");
	printf("NESTED FOR LOOP EXECUTED !!!");		
	printf("\n\n");
	

	return(0);
}









