#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int SUM_num;
	int *SUM_ptr = NULL;        // SUM_ptr is a pointer variable to integer
	int SUM_ans;

	// Code
	SUM_num = 1025;
	SUM_ptr = &SUM_num;

	printf("\n\n");
	printf(" SUM_num       = %d\n", SUM_num);
	printf(" &SUM_num      = %p\n", &SUM_num);
	printf(" *(&SUM_num)   = %d\n", *(& SUM_num));
	printf(" SUM_ptr       = %p\n", SUM_ptr);
	printf(" *SUM_ptr      = %d\n", *SUM_ptr);
	printf("\n\n");

	// Add 10 to ptr which is the address of num
	// Now, 10 will be added to the address of num and the resultant address will be displayed
	
	printf("Answer for (SUM_ptr + 10) = %p\n", (SUM_ptr + 10));

	// Add 10 to ptr which is the address of num and give value at the new address
	// Now, 10 will be added to the address of num and the resultant address will be displayed


	// SUM_ptr is an integer pointer variable (can hold the address of an integer variable)
	// SUM_ptr = &SUM_num ('ptr' contains the address of the integer variable 'num')
	// SUM_ptr = copy_ptr (ie copy_ptr contains the address of the integer variable 'num')
	// Hence both ptr and copy_ptr will point to num

	SUM_copy_ptr = SUM_ptr;  //SUM_copy_ptr = SUM_ptr = &SUM_num

	printf("\n\n");
	printf("***** After SUM_copy_ptr = SUM_ptr *****\n\n");
	printf(" SUM_num       = %d\n", SUM_num);
	printf(" &SUM_num      = %p\n", &SUM_num);
	printf(" *(&SUM_num)   = %d\n", *(&SUM_num));
	printf(" SUM_ptr       = %p\n", SUM_ptr);
	printf(" *SUM_ptr      = %d\n", *SUM_ptr);
	printf(" SUM_copy_ptr  = %p\n", SUM_copy_ptr);
	printf(" *SUM_copy_ptr = %d\n", *SUM_copy_ptr);
	
	return(0);

}
