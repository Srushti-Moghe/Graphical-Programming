#include <stdio.h> //for printf()
#include <conio.h> //for getch()

int main(void)
{
	//variable declarations
	int SUMa, SUMb;
	int SUMresult;

	char SUM_option, option_division;

	//code
	printf("\n\n");

	printf("Enter value for 'A' : ");
	scanf("%d", &SUMa);

	printf("Enter value for 'B' : ");
	scanf("%d", &SUMb);

	printf("Enter Option in character : \n\n");
	printf("'A' or 'a' for ADDITION : \n");
	printf("'S' or 's for SUBTRACTION : \n");
	printf("'M' or 'm' for MULTIPLICATION : \n");
	printf("'D' or 'd' for DIVISION : \n");

	printf("Enter option : ");
	SUM_option = getch();

	printf("\n\n");

	if (SUM_option == 'A' || SUM_option == 'a')
	{
		SUMresult = SUMa + SUMb;
		printf("Addition of A = %d and B = %d gives result %d !!!\n\n", SUMa, SUMb, SUMresult);
	}

	else if (SUM_option == 'S' || SUM_option == 's')
	{
		if (SUMa >= SUMb)
		{
			SUMresult = SUMa - SUMb;
			printf("Subtraction of B = %d from A = %d gives result %d !!!\n\n", SUMa, SUMb, SUMresult);
		}
		else
		{
			SUMresult = SUMb - SUMa;
			printf("Subtraction of A = %d from B = %d gives result %d !!!\n\n", SUMa, SUMb, SUMresult);
		}
	}

	else if (SUM_option == 'M' || SUM_option == 'm')
	{
		SUMresult = SUMa * SUMb;
		printf("Multiplication of A = %d and B = %d gives result %d !!!\n\n", SUMa, SUMb, SUMresult);
	}

	else if (SUM_option == 'D' || SUM_option == 'd')
	{
		printf("Enter option in Character : \n\n");
		printf("'Q' or 'q' or '/' for Quotient upon division : \n");
		printf("'R' or 'r' or '%%' for Remainder upon division : \n");

		printf("Enter option : ");
		option_division = getch();

		printf("\n\n");

		if (option_division == 'Q' || option_division == 'q' || option_division == -'/')
		{
			if (SUMa >= SUMb)
			{
				SUMresult = SUMa % SUMb;
				printf("Division of 'A' = %d by 'B' = %d gives remainder = %d !!!\n\n", SUMa, SUMb, SUMresult);
			}
			else
			{
				SUMresult = SUMa % SUMb;
				printf("Division of 'A' = %d by 'B' = %d gives remainder = %d !!!\n\n", SUMa, SUMb, SUMresult);
			}
		}

		else if (option_division == 'R' || option_division == 'r' || option_division == '%')
		{
			if (SUMa >= SUMb)
			{
				SUMresult = SUMa % SUMb;
				printf("Division of 'A' = %d by 'B' = %d gives remainder = %d !!!\n\n", SUMa, SUMb, SUMresult);
			}
			else
			{
				SUMresult = SUMb % SUMa;
				printf("Division of 'B' = %d by 'A' = %d gives remainder = %d !!!\n\n", SUMa, SUMb, SUMresult);
			}
		}
		else
		{
			printf("Invalid character %c Entered !!!\n\n", option_division);
		}
	}

	else
		printf("Invalid character %c Entered !!! Please Try again....\n\n", SUM_option);
	
	printf("If - Else If - Else Ladder Complete !!!\n");

	return(0);
}





