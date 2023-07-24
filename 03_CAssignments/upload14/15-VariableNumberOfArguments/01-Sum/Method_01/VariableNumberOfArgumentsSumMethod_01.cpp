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

	SUM_answer = CalculateSum(5, 10, 20, 30, 40, 50); // 5 - arg count 
	printf("Answer = %d\n\n", SUM_answer);

	SUM_answer = CalculateSum(10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1); // 10 - arg count
	printf("Answer = %d\n\n", SUM_answer);

	SUM_answer = CalculateSum(0);
	printf("Answer = %d\n\n", SUM_answer);
	
	return(0);
}

// Function Definition
int CalculateSum(int num, ...) // Varidic Function
{
	int sum_total = 0;
	int n;

	va_list  numbers_list;

	// Code
	va_start(numbers_list, num);
	while (num)
	{
		n = va_arg(numbers_list, int);
		sum_total = sum_total + n;
		num--;
	}
	va_end(numbers_list);
	return(sum_total);
}




