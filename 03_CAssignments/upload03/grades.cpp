#include <stdio.h>

int main(void)
{
	//variable declarations 
	float G;

	printf("\n\n");
	printf("***********");
	printf("\n");

	printf("Enter your Gpa : ");
	scanf("%f", &G);

	//If Else Statements
	if ((G >= 3.2) && (G < 5))
	{
		printf("\n\n"); 
		printf("\n\n"); 
		printf("Yay! You can get into CMU SoA!\n\n");
	}
	else
	{
		printf("Work Harder! You've got a year!\n\n");
	}
	printf("\n\n");
	printf("***********");
	printf("\n");

	return (0);
} 









