#include <stdio.h>
int main(void)
{
	//Variable Declarations 
	int SUMi, SUMj;

	//Code
	printf("\n\n");

	printf("Outer loop prints Odd Numbers between 1 and 10. \n\n");
	printf("Inner loop prints Even Numbers between 1 and 10, for ever off number printed by outer loop. \n\n");

	for (SUMi = 0; SUMi <= 10; SUMi++)
	{
		if (SUMi % 2 != 0)	//When the remainder is not 0, it is an odd number
		{
			printf("i = %d\n", SUMi);
			printf("-------------\n");

			for (SUMj = 1; SUMj <= 10; SUMj++)
			{
				if (SUMj % 2 == 0)   //When the remainder is 0, it is an even number
				{
					printf("\tj = %d\n", SUMj);
				}
				else //i.e. When the the number is an odd number
				{
					continue;
				}
			}
			printf("\n\n");
		}
		else //i.e. When the the number is an even number
		{
			continue;
		}
	}

	printf("\n\n");
	
	return(0);
}

