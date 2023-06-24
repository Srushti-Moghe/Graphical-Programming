#include <stdio.h>

int main(void)
{
	//variable declarations 
	int a;
	printf("\n\n");

	for (int a = 1; a <= 100; a++)
	{
		if (a % 2 == 0)
			continue;
		printf("%d \n\n", a);
	}

	printf("\n\n");
	printf("INFINITE LOOP IS EXECUTED !!!");		
	printf("\n\n");
	

	return(0);
}







