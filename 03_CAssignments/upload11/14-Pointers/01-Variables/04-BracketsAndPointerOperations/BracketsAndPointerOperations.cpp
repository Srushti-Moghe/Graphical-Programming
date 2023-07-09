#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int SUM_num;
	int *SUM_ptr = NULL;        // SUM_ptr is a pointer variable to integer
	int SUM_ans;

	// Code
	SUM_num = 5;
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

	printf("Answer for *(SUM_ptr + 10) = %d\n", *(SUM_ptr + 10));

	// Add 10 to '*ptr' which is the address of num (value - 1025) and give new value without any change in address
	// Now, 10 will be added to the '*ptr' (num = 1025) and the resultant value will be given (*ptr + 10) = (num + 10) = (5 + 10) = 15

	printf("Answer of (*SUM_ptr + 10) = %d\n\n", (*SUM_ptr + 10));

	//*** Associativity of *(Value at address) AND ++ AND -- operators is from RIGHT to LEFT ***

	// (Right to Left) Consider value *ptr ... preincrement *ptr ... that is value at address 'ptr' i.e. *ptr is pre incremented (++*ptr)

	++*SUM_ptr;  // *ptr is pre incremented (*ptr = 5 >> *ptr = 6 and so on)
	printf("Answer of ++*SUM_ptr : %d\n", *SUM_ptr);
	
	// (Right to Left) Post increment address ptr ... That is the address of ptr is post - incremented (ptr++) and then the value at the new address is dissplayed (*ptr++)
	*SUM_ptr++;     // Incorrect method of post incrementing a pointer
	printf("Answer of *SUM_ptr++ : %d\n", *SUM_ptr);

	// (Right to Left) Post increment value *ptr ... that is value at address 'ptr' i.e. *ptr is post incremented (++*ptr)

	SUM_ptr = &SUM_num;
	(*SUM_ptr)++;        // *ptr is post incremented (*ptr = 6 >> *ptr = 7 and so on)
	// Incorrect method of post incrementing a pointer 

	printf("Answer of (*SUM_ptr)++ : %d\n", *SUM_ptr);

	return(0);

}


