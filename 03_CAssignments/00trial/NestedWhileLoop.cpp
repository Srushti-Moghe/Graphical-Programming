#include <stdio.h>

int main(void)
{
	//variable declarations 
	int i = 1;
	int j = 1;
	int k = 1;

	printf("\n\n");

	while (i <= 5)
	{
		printf("i = %d\n", i);
		while (j <= 3)
		{
			printf("j = %d\n\n", j);
			while (k <= 1)
			{
				printf("k = %d\n\n\n", k);
				k++;
			}
			j++;
		}
		i++;
	}
	printf("\n\n");
	printf("NESTED WHILE LOOP EXECUTED !!!");		
	printf("\n\n");
	

	return(0);
}









