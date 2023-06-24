#include <stdio.h>
int main(void)
{
	//Variable Declarations 
	int SUMi, SUMj, SUMc;

	//Code
	printf("\n\n");

	SUMi = 0;
	do
	{
		SUMj = 0;
		do
		{
			SUMc = ((SUMi & 0x8) == 0) ^ ((SUMj & 0x8) == 0);

			if (SUMc == 0)
				printf(" ");

			if (SUMc == 1)
				printf("* ");

			SUMj++;

		} while (SUMj < 64);

				printf("\n\n");
				
				SUMi++;

	} while (SUMi < 64);

	return(0);
}

