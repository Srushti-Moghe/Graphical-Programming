#include <stdio.h>
#include <conio.h>

int main(void)
{
	//Variable Declarations 
	int SUMi, SUMj;
	
	//Code
	printf("\n\n");

	for (SUMi = 1; SUMi <= 20; SUMi++)
	{
		for (SUMj = 1; SUMj <= 20; SUMj++)
		{
			if (SUMj > SUMi)
			{
				break;
			}
			else
			{
				printf("* ");
			}
		}
		printf("\n");
		
	}
	printf("\n\n");
			
	return(0);
}

