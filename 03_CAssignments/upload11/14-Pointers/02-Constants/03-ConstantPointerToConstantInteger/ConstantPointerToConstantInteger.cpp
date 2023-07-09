#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int SUM_num;
	const int* const SUM_ptr = &SUM_num;        // SUM_ptr is a constant pointer to an integer constant
	
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
	// (*ptr++) Changes the address of the value of the constant pointer which also leads to an error
	// The pointer is constant. The value to which the pointer is also constant
	(*SUM_ptr++);
	printf(" Current value at 'ptr' address (Address of 'num') = %p\n", *SUM_ptr);
	printf("\n\n");

	return(0);
}

/* SUM_ptr is a constant pointer to an integer constant
   hence, the address at the value of 'ptr' cannot be changed
   value of num (variable) can be changed indivisually
   value at aaddress of 'ptr' - unchangable
   aaddress of 'ptr'          - unchangable
*/



