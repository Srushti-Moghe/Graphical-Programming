#include <stdio.h>

int main(void)
{
	// Variable Declarations
	char SUM_ch;
	char *SUM_ptr = NULL; // '*SUM_ptr' is a variable of type character

	// Code
	SUM_ch = 'S';

	printf("\n\n");
	printf("***** Before ptr = &ch *****\n\n");
	printf("Value of 'ch'             = %c\n\n", SUM_ch);
	printf("Address of 'ch'           = %p\n\n", &SUM_ch);
	printf("Value at Address of 'ch'  = %p\n\n", *(&SUM_ch));

	// Assigning variable 'SUM_num' to a pointer variable 'SUM_ptr'
	// 'SUM_ptr' = Address of 'SUM_num'
	// i.e. 'SUM_ptr' = 'SUM_num'
	 
	SUM_ptr = &SUM_ch;

	printf("\n\n");
	printf("***** After ptr = &ch *****\n\n");
	printf("Value of 'ch'             = %c\n\n", SUM_ch);
	printf("Address of 'ch'           = %p\n\n", SUM_ptr);
	printf("Value at Address of 'ch'  = %p\n\n", *SUM_ptr);

	return(0);
}




