#include <stdio.h>
#include <stdarg.h>		//  defines macros used to access arguments in functions with variable-length argument lists

int main(void)
{
	// Function Prototypes
	int CalculateSum(int, ...);

	// Variable Declarations
	int SUM_answer;

	// Code
	printf("\n\n");

	SUM_answer = CalculateSum(5, 100, 20, 30, 400, 500);
	printf("Answer = %d\n\n", SUM_answer);

	SUM_answer = CalculateSum(10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);
	printf("Answer = %d\n\n", SUM_answer);

	SUM_answer = CalculateSum(0);
	printf("Answer = %d\n\n", SUM_answer);
	
	return(0);
}

// Function Definition
int CalculateSum(int num, ...) // Varidic Function
{
	// Function Declaration
	int va_CalculateSum(int, va_list);

	// Variable Declarations
	va_list SUM_list;
	int SUM_total = 0;

	va_start(SUM_list, num);
	SUM_total = va_CalculateSum(num, SUM_list);
	va_end(SUM_list);

	return(SUM_total);
}

int va_CalculateSum(int num, va_list SUM_list)
{
	int SUM_i = 0;
	int SUM_total = 0;

	while (SUM_i < num)
	{
		SUM_total = SUM_total + va_arg(SUM_list, int);
		SUM_i++;
	}

	return (SUM_total);
}




