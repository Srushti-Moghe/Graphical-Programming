#include <stdio.h>
int main(void)
{
	//variable declarations 
	int num_month_SUM;

	//code
	printf("\n\n");

	printf("Enter value for the Number of Month (1 to 12) : ");
	scanf("%d", &num_month_SUM);

	printf("\n\n");

	//IF - ELSE - IF ladder beginning
	if (num_month_SUM == 1)    //like "case 1"
		printf("Month Number %d is JANUARY !!!\n\n", num_month_SUM);

	else if (num_month_SUM == 2)    //like "case 2" 
		printf("Month Number %d is FEBRUARY !!!\n\n", num_month_SUM);

	else if (num_month_SUM == 3)    //like "case 3" 
		printf("Month Number %d is MARCH !!!\n\n", num_month_SUM);

	else if (num_month_SUM == 4)    //like "case 4" 
		printf("Month Number %d is APRIL !!!\n\n", num_month_SUM);

	else if (num_month_SUM == 5)    //like "case 5" 
		printf("Month Number %d is MAY !!!\n\n", num_month_SUM);

	else if (num_month_SUM == 6)    //like "case 6" 
		printf("Month Number %d is JUNE !!!\n\n", num_month_SUM);

	else if (num_month_SUM == 7)    //like "case 7" 
		printf("Month Number %d is JULY !!!\n\n", num_month_SUM);

	else if (num_month_SUM == 8)    //like "case 8" 
		printf("Month Number %d is AUGUST !!!\n\n", num_month_SUM);

	else if (num_month_SUM == 9)    //like "case 9" 
		printf("Month Number %d is SEPTEMBER !!!\n\n", num_month_SUM);

	else if (num_month_SUM == 10)    //like "case 10" 
		printf("Month Number %d is OCTOBER !!!\n\n", num_month_SUM);

	else if (num_month_SUM == 11)    //like "case 11" 
		printf("Month Number %d is NOVEMBER !!!\n\n", num_month_SUM);

	else if (num_month_SUM == 12)    //like "case 12" 
		printf("Month Number %d is DECEMBER !!!\n\n", num_month_SUM);

	else   //like "default"
		printf("Invalid Month Number %d entered !!! Please try again...\n\n", num_month_SUM);

	printf("IF - ELSE IF - ELSE ladder complete !!!\n\n");

	return(0);
}












