#include <stdio.h>

enum
{
	NEGATIVE = -1,
	ZERO,
	POSITIVE
};

int main(void)
{
	// Function Declarations
	int Difference(int, int, int*);
	
	// Variable Declarations
	int SUM_a, SUM_b; 
	int SUM_answer;
	int SUM_return;
	
	// Code
	printf("\n\n");
	printf("Enter value for 'A' : ");
	scanf("%d", &SUM_a);

	printf("\n\n");
	printf("Enter value for 'B' : ");
	scanf("%d", &SUM_b);

	SUM_return = Difference(SUM_a, SUM_b, &SUM_answer);

	printf("\n\n");
	printf("Difference of %d and %d = %d\n\n", SUM_a, SUM_b, SUM_answer);

	if (SUM_return == POSITIVE)
	{
		printf("The difference of %d and %d is Positive !!!\n\n", SUM_a, SUM_b);
	}
	else if (SUM_return == NEGATIVE)
	{
		printf("The difference of %d and %d is Negative !!!\n\n", SUM_a, SUM_b);
	}
	else
	{
		printf("The difference of %d and %d is Zero !!!\n\n", SUM_a, SUM_b);
	}
	
	return (0);
}
// Difference() performs 2 jobs
// SUbtraction of 'x' and 'y' and teells if the difference is positive, negative or zero
// Here, the return value - Actual difference of 'x' and 'y' can be returned as Out Parameter/Parameterized Return Value

// Function Definition

int Difference(int x, int y, int *diff)
{
	// Code
	*diff = x - y;
	if (*diff > 0)
	{
		return (POSITIVE);
	}
	else if (*diff < 0)
	{
		return (NEGATIVE);
	}
	else
	{
		return(ZERO);
	}
}








