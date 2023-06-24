#include <stdio.h>
int main(void)
{
	//variable declarations
	int SUMi, SUMj, SUMc;

	//code
	printf("\n\n");

	for (SUMi = 0; SUMi < 64; SUMi++)
	{
		for (SUMj = 0; SUMj < 64; SUMj++)
		{
			SUMc = ((SUMi & 0x8) == 0) ^ ((SUMj & 0x8) == 0);

			if (SUMc == 0)
			{
				printf("  ");
			}
			if (SUMc == 1)
			{
				printf("*  ");
			}
		}
		printf("\n\n");
	}
	return(0);

}


