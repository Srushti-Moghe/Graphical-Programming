#include <stdio.h>

int main(void)
{
	//variable declarations 
	int i = 1;
	int j = 1;
	int k = 1;

	printf("\n\n");

	do
	{
		printf("i = %d\n", i);
		do
		{
			printf("j = %d\n\n", j);
			do 
			{
				printf("k = %d\n\n\n", k);
				k++;
			} while (k <= 1);
			j++;
		} while (j <= 3);
		i++;
	} while (i <= 5);

	printf("\n\n");
	printf("NESTED DO WHILE LOOP EXECUTED !!!");		
	printf("\n\n");
	

	return(0);
}













