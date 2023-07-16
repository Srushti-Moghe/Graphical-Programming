#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int SUM_num;
	int* SUM_ptr;
	int **SUM_pptr; // Declaration method01 - SUM_pptr is a pointer variable to integer datatype

	// Code
	SUM_num = 16;
	printf("\n\n");
	printf("***** Before ptr = &num *****\n\n");
	printf("Value of 'num'             = %d\n\n", SUM_num);
	printf("Address of 'num'           = %d\n\n", &SUM_num);
	printf("Value of Address at 'num'  = %d\n\n", *(&SUM_num));

	// Assigning the address of variable 'num' to pointer variable 'ptr'
	// 'ptr' now contains the address of variable 'num' 
	// 'ptr' = '&num' 
	SUM_ptr = &SUM_num;

	printf("\n\n");
	printf("***** After ptr = &num *****\n\n");
	printf("Value of 'num'             = %d\n\n", SUM_num);
	printf("Address of 'num'           = %d\n\n", &SUM_ptr);
	printf("Value of Address at 'num'  = %d\n\n", *SUM_ptr);

	// Assigning the address of variable 'ptr' to pointer to pointer variable 'pptr'
	// 'pptr' now contains the address of 'ptr' which in turn contains the address of 'num' i.e. '&num'
	// 'pptr' = '&ptr'
	// 'ptr' = '&num'
	// 'pptr' = '&ptr' = '&(&num)
	// 'ptr' = '&num' >>  Value at the address of 'num' = '*ptr' = *('&num')
	// 'pptr' = '&ptr' and '*pptr' = '*(&ptr)' = 'ptr' = Value at address of 'ptr'
	// '**pptr' = '**(&ptr)' = '*(*&ptr)' = '*ptr' = '*(&num)' = 'num' = '16'
	// Therefore 'num' = '*(&um)' = '*ptr' = '*(*pptr)' = '**pptr'
	SUM_pptr = &SUM_ptr;

	printf("\n\n");
	printf("***** After pptr = &ptr *****\n\n");
	printf("Value of 'num'                             = %d\n\n", SUM_num);
	printf("Address of 'num' (ptr)                     = %d\n\n", SUM_ptr);
	printf("Address of 'ptr' (pptr)                    = %d\n\n", SUM_pptr);
	printf("Value of Address at 'ptr' (*pptr )         = %d\n\n", *SUM_pptr);
	printf("Value of Address at 'num' (*ptr) (*pptr )  = %d\n\n", *SUM_pptr);
	
	return(0);
}


