#include <stdio.h>

int main(void)
{
	//variable declarations variables a, b correspond to SUMa, SUMb respectively
	int SUMa = 5;
	int SUMb = 15;

	//code
	printf("\n\n");
	printf("SUMa = %d\n", SUMa);
	printf("SUMa = %d\n", SUMa++);
	printf("SUMa = %d\n", SUMa);
	printf("SUMa = %d\n", ++SUMa);

	printf("SUMb = %d\n", SUMb);
	printf("SUMb = %d\n", SUMb--);
	printf("SUMb = %d\n", SUMb);
	printf("SUMb = %d\n", --SUMb);

	return(0);
}



