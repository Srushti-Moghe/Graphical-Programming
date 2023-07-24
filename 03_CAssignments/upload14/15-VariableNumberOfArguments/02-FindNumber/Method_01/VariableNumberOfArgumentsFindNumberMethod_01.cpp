#include <stdio.h>
#include <stdarg.h>		//  defines macros used to access arguments in functions with variable-length argument lists


#define NUM_TO_BE_FOUND 8
#define NUM_ELEMENTS 10

int main(void)
{
	// Function Prototypes
	void FindNumber(int, int, ...);

	// Code
	printf("\n\n");

	FindNumber(NUM_TO_BE_FOUND, NUM_ELEMENTS, 3, 5, 9, 2, 3, 6, 9, 3, 1, 3, 1, 3);
	
	return(0);
}

// Function Definition
void FindNumber(int num_to_be_found, int num, ...) // Varidic Function
{
	// Variable Declarations
	int count = 0;
	int n;

	va_list  numbers_list;

	// Code
	va_start(numbers_list, num);
	while (num)
	{
		n = va_arg(numbers_list, int);
		if (n == num_to_be_found)
		{
			count++;
		}
		num--;		
	}
	if (count == 0)
	{
		printf("Number %d could not be found !!!\n\n", num_to_be_found);
	}
	else
	{
		printf("Number %d found %d times !!!\n\n", num_to_be_found, count);

	}
	va_end(numbers_list);
}



