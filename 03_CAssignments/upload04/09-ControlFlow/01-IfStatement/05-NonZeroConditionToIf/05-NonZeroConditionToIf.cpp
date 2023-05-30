#include <stdio.h>

int main(void)
{
	//variable declarations 
	int SUMa;

	//code
	printf("\n\n");

	SUMa = -5;
	if (SUMa) // Non Zero Positive Value
	{
		printf("if-block 1 : 'A' Exists and has value = %d !!!\n\n", SUMa);
	}

	SUMa = 5;
	if (SUMa) // Non Zero Negative Value
	{
		printf("if-block 2 : 'A' Exists and has value = %d !!!\n\n", SUMa);
	}

	SUMa = 0;
	if (SUMa) // Zero Value
	{
		printf("if-block 3 : 'A' Exists and has value = %d !!!\n\n", SUMa);
	}

	printf("All Three if-statements are done !!!\n\n", SUMa);

	return(0);
}


