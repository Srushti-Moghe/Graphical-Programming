#include <stdio.h>

int main(void)
{
	//variable declarations variables a, b correspond to SUMa, SUMb respectively
	int SUMa;
	int SUMb;
	int result;

	//code
	printf("\n\n");
	printf("Enter a number : ");
	scanf("%d", &SUMa);

	printf("\n\n");
	printf("Enter another number : ");
	scanf("%d", &SUMb);

	printf("\n\n");

	//***The following are 5 arithmatic operators =, -, *, / and % ***
	//*** Also, the resultantsof the the arithmatic operations in all the below 5 caseshave been assigned to the variable 'result' Using the Assignment OPerator (=)  ***
	result = SUMa + SUMb;
	printf("Addition of SUMa = %d And SUMb = %d Gives %d.\n", SUMa, SUMb, result);

	result = SUMa - SUMb;
	printf("Subtraction of SUMa = %d And SUMb = %d Gives %d.\n", SUMa, SUMb, result);

	result = SUMa * SUMb;
	printf("Multiplication of SUMa = %d And SUMb = %d Gives %d.\n", SUMa, SUMb, result);

	result = SUMa / SUMb;
	printf("Division of SUMa = %d And SUMb = %d Gives Quotient %d.\n", SUMa, SUMb, result);

	result = SUMa % SUMb;
	printf("Division of SUMa = %d And SUMb = %d Gives Remainder %d.\n", SUMa, SUMb, result);

	printf("\n\n");

	return(0);
}


