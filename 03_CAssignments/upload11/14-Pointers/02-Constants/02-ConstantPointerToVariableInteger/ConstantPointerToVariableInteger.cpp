#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int SUM_num;
	int* const SUM_ptr = &SUM_num;        // SUM_ptr is a constant pointer to an integer 
	
	// Code
	SUM_num = 5;

	printf("\n\n");
	printf(" Current value of num  = %d\n", SUM_num);
	printf(" Current 'ptr' address (Address of 'num') = %p\n", SUM_ptr);

	// Modificcation of the variables, indivisually
	SUM_num++;
	printf("\n\n");
	printf("After 'num++', value of 'num' = %d\n", SUM_num); 

	// (ptr++) Changes the value of the constant pointer which leads to an error
	// (*ptr++) Changes the address of the value of the constant pointer which does not lead to an error
	// The pointer is constant. The value to which the pointer is NOT constant
	(*SUM_ptr)++;

	printf("\n\n");
	printf(" After '(*ptr)++', value of 'ptr'  = %p\n", SUM_ptr);
	printf(" Value at this new 'ptr'        = %d\n", *SUM_ptr);
	printf("\n\n");

	return(0);

}

/* SUM_ptr is a constant pointer to an integer 
   hence, the address at the value of 'ptr' can be changed
   value of num (variable) can be changed indivisually
   value at aaddress of 'ptr' - changable
   aaddress of 'ptr'          - unchangable
*/



