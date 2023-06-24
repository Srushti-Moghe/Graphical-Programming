#include <stdio.h>

int main(void)
{
	//variable declarations 
	int a;

	printf("\n\n");

	for (int a = 1; a <= 100; a++)
	{
		if (a == 51)
		{
			break;
		}
		printf("%d\n", a);
	}

	printf("\n\n");
	printf("Numbers from 1 - 50 are printed !!!");		
	printf("\n\n");
	return(0);
}

