#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int SUM_num;
	const int* SUM_ptr = NULL;        // SUM_ptr is a variable to an integer constant 
	int SUM_ans;

	// Code
	SUM_num = 5;
	SUM_ptr = &SUM_num;
	printf("\n\n");
	printf(" Current value of num  = %d\n", SUM_num);
	printf(" Current 'ptr' address (Address of num) = %p\n", SUM_ptr);

	// Modificcation of the variables, indivisually
	SUM_num++;
	printf("\n\n");
	printf("After num++, value of 'num' = %d\n", SUM_num); 

	// (*ptr)++ Changes the value of the constant pointer which leads to an error
	// *(ptr)++ Changes the address of the value of the constant pointer which does not lead to an error
	SUM_ptr++;

	printf("\n\n");
	printf(" After 'ptr++', value of 'ptr'  = %p\n", SUM_ptr);
	printf(" Value at this new 'ptr'        = %d\n", *SUM_ptr);
	printf("\n\n");

	return(0);

}

/* SUM_ptr is a variable to an integer constant 
   hence, the value of 'ptr' can be changed
   value of num (addresss in 'ptr') can be changed indivisually
   value at aaddress of 'ptr' - unchangable
   aaddress of 'ptr'          - changable
*/



