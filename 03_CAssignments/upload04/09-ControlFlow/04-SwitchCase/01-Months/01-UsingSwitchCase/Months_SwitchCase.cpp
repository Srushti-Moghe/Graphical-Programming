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
	
	switch (num_month_SUM)
	{
	case 1: //like IF
		printf("Month Number %d is JANUARY !!!!\n\n", num_month_SUM);
		break;

	case 2: //like ELSE - IF
		printf("Month Number %d is FEBRUARY !!!!\n\n", num_month_SUM);
		break;

	case 3: //like ELSE - IF
		printf("Month Number %d is MARCH !!!!\n\n", num_month_SUM);
		break;

	case 4: //like ELSE - IF
		printf("Month Number %d is APRIL !!!!\n\n", num_month_SUM);
		break;

	case 5: //like ELSE - IF
		printf("Month Number %d is MAY !!!!\n\n", num_month_SUM);
		break;

	case 6: //like ELSE - IF
		printf("Month Number %d is JUNE !!!!\n\n", num_month_SUM);
		break;

	case 7: //like ELSE - IF
		printf("Month Number %d is JULY !!!!\n\n", num_month_SUM);
		break;

	case 8: //like ELSE - IF
		printf("Month Number %d is AUGUST !!!!\n\n", num_month_SUM);
		break;

	case 9: //like ELSE - IF
		printf("Month Number %d is SEPTEMBER !!!!\n\n", num_month_SUM);
		break;

	case 10: //like ELSE - IF
		printf("Month Number %d is OCTOBER !!!!\n\n", num_month_SUM);
		break;

	case 11: //like ELSE - IF
		printf("Month Number %d is NOVEMBER !!!!\n\n", num_month_SUM);
		break;

	case 12: //like ELSE - IF
		printf("Month Number %d is DECEMBER !!!!\n\n", num_month_SUM);
		break;

	default: //corresponds to optional ELSE. 
		printf("Invalid Month Number Entered !!! Please try again...\n\n", num_month_SUM);
		break;
	}

	printf("Switch Case Block Complete !!!\n");

	return(0);
}









