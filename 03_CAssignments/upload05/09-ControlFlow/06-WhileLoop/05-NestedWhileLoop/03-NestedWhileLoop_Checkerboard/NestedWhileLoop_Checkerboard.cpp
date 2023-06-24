#include <stdio.h>
int main(void)
{
	//variable declarations
	int SUMi, SUMj, SUMc;

	//code
	printf("\n\n");

	SUMi = 0;
	while (SUMi < 64)
	{
		SUMj = 0;
		while (SUMj < 64)
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
			SUMj++;
		}
		printf("\n\n");
		SUMi++;
	}
	return(0);

}





