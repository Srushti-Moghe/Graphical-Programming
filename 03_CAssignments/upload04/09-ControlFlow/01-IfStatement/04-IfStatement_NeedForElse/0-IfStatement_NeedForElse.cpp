#include <stdio.h>

int main(void)
{
	//variable declarations 
	int S_age;

	//code
	printf("\n\n");

	printf("Enter Age : ");
	scanf("%d", &S_age);

	if (S_age >= 18)
	{
		printf("You are Eligible for Voting !!!\n\n", S_age);
	}
	printf("You are Eligible for Voting !!!\n\n", S_age);
	
	return(0);	
}


