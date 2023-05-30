#include <stdio.h>

int main(void)
{
	//variable declarations 
	int SUMage;

	//code
	printf("\n\n");

	printf("Enter age : ");
	scanf("%d", &SUMage);

	if (SUMage >= 18)
	{
		printf("Entering if-block...\n\n");
		printf("You are Eligible for Voting !!!\n\n");
	}
	else
	{
		printf("Entering else-block...\n\n");
		printf("You are not eligible for Voting !!!\n\n");
	}

	printf("Byeee !!!\n\n");

	return(0);
}




