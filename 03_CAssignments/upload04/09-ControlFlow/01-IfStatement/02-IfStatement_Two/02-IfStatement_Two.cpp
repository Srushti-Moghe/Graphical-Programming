#include <stdio.h>

int main(void)
{
	//variable declarations 
	int age;

	//code
	printf("\n\n");
	printf("Enter Age : ");
	scanf("%d", &age);
	if (age >= 18)
	{
		printf("You are Eligible to VOTE !!!");
	}
	return(0);	
}


