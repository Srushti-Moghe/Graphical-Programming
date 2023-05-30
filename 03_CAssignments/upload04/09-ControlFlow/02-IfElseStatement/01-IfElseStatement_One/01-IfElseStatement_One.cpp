#include <stdio.h>

int main(void)
{
	//variable declarations 
	int SUMa, SUMb, SUMp;

	//code
	SUMa = 9;
	SUMb = 30;
	SUMp = 30;

	//If-Else - 1
	printf("\n\n");
	if (SUMa < SUMb)
	{
		printf("Entering first if-block...\n\n");
		printf("A is Less than B !!!");
	}
	else
	{
		printf("Entering first else-block...\n\n");
		printf("A is Not Less than B !!!");
	}
	printf("First If-Else pair is done !!!\n\n");

	//If-Else - 2
	printf("\n\n");
	if (SUMb != SUMp)
	{
		printf("Entering second if-block...\n\n");
		printf("B is Not Equal to P !!!\n\n");
	}
	else
	{
		printf("Entering second else-block....\n\n");
		printf("A is Not Less than B !!!\n\n");
	}
	printf("Second If-Else pair is done !!!\n\n");
	
	return(0);
}




