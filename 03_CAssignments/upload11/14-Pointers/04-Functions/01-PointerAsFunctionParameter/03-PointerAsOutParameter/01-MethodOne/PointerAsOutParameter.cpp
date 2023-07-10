#include <stdio.h>

int main(void)
{
	// Function Declarations
	void MathematicalOperations(int, int, int*, int*, int*, int*, int*);
	
	// Variable Declarations
	int SUM_a, SUM_b; 
	int S_answer_sum;
	int S_answer_difference;
	int S_answer_product;
	int S_answer_quotient;
	int S_answer_remainder;

	// Code
	printf("\n\n");
	printf("Enter value for 'A' : ");
	scanf("%d", &SUM_a);

	printf("\n\n");
	printf("Enter value for 'B' : ");
	scanf("%d", &SUM_b);

	// Passing Addresses to the Function
	// Input parameters of the function - addresses > Output parameters valid values
	// Return values of functions coming out of parameters = OUT PARAMETERS or PARAMETERIZED RETURN VALUES
	// (S_answer_sum, int S_answer_difference, int S_answer_product, int S_answer_quotient, int S_answer_remainder)
	// Although each function has one return value, using the concept of 'Parameterized Return Values' the function Mathematical Operations() gives five return values

	MathematicalOperations(SUM_a, SUM_b, &S_answer_sum, &S_answer_difference, &S_answer_product, &S_answer_quotient, &S_answer_remainder);

	printf("\n\n");
	printf("  ***** Results *****\n\n");
	printf("Sum         = %d\n", S_answer_sum);
	printf("Difference  = %d\n", S_answer_difference);
	printf("Product     = %d\n", S_answer_product);
	printf("Quotient    = %d\n", S_answer_quotient);
	printf("Remainder   = %d\n", S_answer_remainder);
	
	return (0);
}
// Function Definition

void MathematicalOperations(int x, int y, int *sum, int *difference, int *product, int *quotient, int *remainder)
{
	// Code
	*sum = x + y;			// Value at address 'sum' = (x + y)
	*difference = x - y; 	// Value at address 'difference' = (x - y)
	*product = x * y;		// Value at address 'product' = (x * y)
	*quotient = x / y;		// Value at address 'quotient' = (x / y)
	*remainder = x % y;		// Value at address 'remainder' = (x % y)
}










