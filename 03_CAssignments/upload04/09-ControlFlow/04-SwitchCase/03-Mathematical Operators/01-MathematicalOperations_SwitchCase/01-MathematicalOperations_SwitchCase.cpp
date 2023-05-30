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

	switch (SUM_option)
	{
		//Fall Through Condition for 'A' and 'a'
	case 'A':
	case 'a':
		SUMresult = SUMa + SUMb;
		printf("Addition of A = %d and B = %d gives result %d !!!\n\n", SUMa, SUMb, SUMresult);
		break;

		//Fall Through Condition for 'S' and 's'
	case 'S':
	case 's':
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
		break;

		//Fall Through Condition for 'M' and 'm'
	case 'M':
	case 'm':
		SUMresult = SUMa * SUMb;
		printf("Multiplication of A = %d and B = %d gives result %d !!!\n\n", SUMa, SUMb, SUMresult);
		break;

		//Fall Through Condition for 'D' and 'd'
	case 'D':
	case 'd':
		printf("Enter option in Character : \n\n");
		printf("'Q' or 'q' or '/' for Quotient upon division : \n");
		printf("'R' or 'r' or '%%' for Remainder upon division : \n");

		printf("Enter option : ");
		option_division = getch();

		printf("\n\n");

		switch (option_division)
		{
			//Fall Through Condition for 'Q' and 'q'
		case 'Q':
		case 'q':
		case '/':
			if (SUMa > SUMb)
			{
				SUMresult = SUMa / SUMb;
				printf("Division of 'A' = %d by 'B' = %d gives Quotient = %d !!!\n\n", SUMa, SUMb, SUMresult);
			}
			else
			{
				SUMresult = SUMb / SUMa;
				printf("Division of 'B' = %d by 'A' = %d gives Quotient = %d !!!\n\n", SUMa, SUMb, SUMresult);
			}
			break; //To break the 'Q' or 'q' or '/' case

			//Fall Through Condition for 'R' and 'r'
		case 'R':
		case 'r':
		case '%':
			if (SUMa > SUMb)
			{
				SUMresult = SUMa % SUMb;
				printf("Division of 'A' = %d by 'B' = %d gives Remainder = %d !!!\n\n", SUMa, SUMb, SUMresult);
			}
			else
			{
				SUMresult = SUMb % SUMa;
				printf("Division of 'B' = %d by 'A' = %d gives Remainder = %d !!!\n\n", SUMa, SUMb, SUMresult);
			}
			break; //To break the 'R' or 'r' or '%' case

		default: //'default' case for switch(option_division)
			printf("Invalid character %c Entered !!!\n\n", option_division);
			break; // 'break of 'default' of switch (option_division)

		} // Ending braces for switch (option_division)

		break; //To break the 'D' or 'd' 

	default: //'default' case for switch (SUM_option)
		printf("Invalid character %c Entered !!!\n\n", SUM_option);
		break; // 'break of 'default' of switch (SUM_option)
	} // Ending braces for switch (SUM_option)

	printf("If - Else If - Else Ladder Complete !!!\n");

	return(0);
}
















