#include <stdio.h>

int main(void)
{
	// Variable Declarations
	double SUM_num;
	double *SUM_ptr = NULL; // '*SUM_ptr' is a variable of type double

	// Code
	SUM_num = 384.5566778899;

	printf("\n\n");
	printf("***** Before ptr = &num *****\n\n");
	printf("Value of 'num'             = %lf\n\n", SUM_num);
	printf("Address of 'num'           = %p\n\n", &SUM_num);
	printf("Value at Address of 'num'  = %p\n\n", *(&SUM_num));

	// Assigning variable 'SUM_num' to a pointer variable 'SUM_ptr'
	// 'SUM_ptr' = Address of 'SUM_num'
	// i.e. 'SUM_ptr' = 'SUM_num'
	 
	SUM_ptr = &SUM_num;

	printf("\n\n");
	printf("***** After ptr = &num *****\n\n");
	printf("Value of 'num'             = %lf\n\n", SUM_num);
	printf("Address of 'num'           = %p\n\n", SUM_ptr);
	printf("Value at Address of 'num'  = %p\n\n", *SUM_ptr);

	return(0);
}




