#include <stdio.h>

int main(void)
{
	// Function Declarations
	void SUM_SwapNumbers(int, int);
	
	// Variable Declarations
	int SUM_a, SUM_b; 

	// Code
	printf("\n\n");
	printf("Enter value for 'A' : ");
	scanf("%d", &SUM_a);

	printf("\n\n");
	printf("Enter value for 'B' : ");
	scanf("%d", &SUM_b);

	printf("\n\n");
	printf("***** Before Swapping 1 *****\n\n");
	printf("Value of 'A' = %d\n", SUM_a);
	printf("Value of 'B' = %d\n", SUM_b);
	
	SUM_SwapNumbers(SUM_a, SUM_b);   // Arguments passed 'by value'

	printf("\n\n");
	printf("***** After Swapping 1 *****\n\n");
	printf("Value of 'A' = %d\n", SUM_a);
	printf("Value of 'B' = %d\n", SUM_b);

	return (0);
}
// Function Definition

// Value of a >> x and the value of b >> y
// This function swaps between x and y not a and b

void SUM_SwapNumbers(int Sx, int Sy)
{
	// Variable Declarations
	int temp;

	// Code
	printf("\n\n");
	printf("***** Before Swapping 2 *****\n\n");
	printf("Value of 'X' = %d\n", Sx);
	printf("Value of 'Y' = %d\n", Sy);

	temp = Sx;
	Sx = Sy;
	Sy = temp;

	printf("\n\n");
	printf("***** After Swapping 2 *****\n\n");
	printf("Value of 'X' = %d\n", Sx);
	printf("Value of 'Y' = %d\n", Sy);	
}








