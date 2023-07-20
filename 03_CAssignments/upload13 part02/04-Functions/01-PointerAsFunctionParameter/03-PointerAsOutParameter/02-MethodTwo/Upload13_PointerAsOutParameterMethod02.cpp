#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// Function Declarations
	void MathematicalOperations(int, int, int*, int*, int*, int*, int*);
	
	// Variable Declarations
	int SUM_a, SUM_b; 
	int *S_answer_sum = NULL;
	int *S_answer_difference = NULL;
	int *S_answer_product = NULL;
	int *S_answer_quotient = NULL;
	int *S_answer_remainder = NULL;

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

	S_answer_sum = (int*)malloc(1 * sizeof(int));
	if (S_answer_sum == NULL)
	{
		printf("Could not allocate memory for 'answer_sum' Exitting now...\n\n");
		exit(0);
	}

	S_answer_difference = (int*)malloc(1 * sizeof(int));
	if (S_answer_difference == NULL)
	{
		printf("Could not allocate memory for 'answer_difference' Exitting now...\n\n");
		exit(0);
	}

	S_answer_product = (int*)malloc(1 * sizeof(int));
	if (S_answer_product == NULL)
	{
		printf("Could not allocate memory for 'answer_product' Exitting now...\n\n");
		exit(0);
	}

	S_answer_quotient = (int*)malloc(1 * sizeof(int));
	if (S_answer_quotient == NULL)
	{
		printf("Could not allocate memory for 'answer_quotient' Exitting now...\n\n");
		exit(0);
	}

	S_answer_remainder = (int*)malloc(1 * sizeof(int));
	if (S_answer_remainder == NULL)
	{
		printf("Could not allocate memory for 'answer_remainder' Exitting now...\n\n");
		exit(0);
	}

	MathematicalOperations(SUM_a, SUM_b, S_answer_sum, S_answer_difference, S_answer_product, S_answer_quotient, S_answer_remainder);

	printf("\n\n");
	printf("  ***** Results *****\n\n");
	printf("Sum         = %d\n", *S_answer_sum);
	printf("Difference  = %d\n", *S_answer_difference);
	printf("Product     = %d\n", *S_answer_product);
	printf("Quotient    = %d\n", *S_answer_quotient);
	printf("Remainder   = %d\n", *S_answer_remainder);

	if (S_answer_remainder)
	{
		free(S_answer_remainder);
		S_answer_remainder = NULL;
		printf("Memory allocated to S_answer_remainder successfully Freed !!!\n\n");
	}

	if (S_answer_quotient)
	{
		free(S_answer_quotient);
		S_answer_quotient = NULL;
		printf("Memory allocated to S_answer_quotient successfully Freed !!!\n\n");
	}

	if (S_answer_product)
	{
		free(S_answer_product);
		S_answer_product = NULL;
		printf("Memory allocated to S_answer_product successfully Freed !!!\n\n");
	}

	if (S_answer_difference)
	{
		free(S_answer_difference);
		S_answer_difference = NULL;
		printf("Memory allocated to S_answer_difference successfully Freed !!!\n\n");
	}

	if (S_answer_sum)
	{
		free(S_answer_sum);
		S_answer_sum = NULL;
		printf("Memory allocated to S_answer_sum successfully Freed !!!\n\n");
	}
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













