#include <stdio.h>

int main(void)
{
	// variable declarations a,b,x correspond to SUMa,SUMb,SUMx respectively
	int SUMa;
	int SUMb;
	int SUMx;

	//code
	printf("\n\n");
	printf("Enter a Number : ");
	scanf("%d", &SUMa);

	printf("\n\n");
	printf("Enter Another Number : ");
	scanf("%d", &SUMb);

	printf("\n\n");

	//Since in all the following 5 cases, the Operand on Left 'SUMa' is getting repeated immediately on the Right (ex: a = a + b or a = a - b), 
	//We are usingCompound Assignment Operators +=, -=, *=, %=

	//Since 'SUMa' will be assigned the value of (a + b) at the expression (a += b), We must save the original value of 'SUMa' to another variable 'SUMx'
	SUMx = SUMa;
	SUMa += SUMb; // a = a + b
	printf("Addition of SUMa =  %d and SUMb = %d Gives %d.\n", SUMa, SUMb, SUMx);

	//Value of 'SUMa' altered in the above expression is used here
	//Since 'SUMa' will be assigned the value of (a - b) at the expression (a -= b), we must save the original value of 'SUMa' to another variable (SUMx)
	SUMx = SUMa;
	SUMa -= SUMb; // a = a - b
	printf("Subtraction of SUMa = %d and SUMb = %d Gives %d.\n", SUMa, SUMb, SUMx);

	//Value of'SUMa' altered in the above expression is used here
	//Since 'SUMa' will be assigned the value of (a * b) at the expression (a *= b), we must save the original value of 'SUMa' to another variable (SUMx)
	SUMx = SUMa;
	SUMa *= SUMb; // a = a * b
	printf("Multiplication of SUMa = %d and SUMb = %d Gives %d.\n", SUMa, SUMb, SUMx);

	//Value of 'SUMa' altered in the above expression is used here
	//Since 'SUMa' will be assigned the value of (a / b) at the expression (a /= b), we must save the original value of 'SUMa' to another variable (SUMx)
	SUMx = SUMa;
	SUMa /= SUMb; //a = a / b
	printf("Division of SUMa = %d and SUMb = %d Gives Quotient %d.\n", SUMa, SUMb, SUMx);

	//Value of 'SUMa' altered in the above expression is used here
	//Since 'SUMa' will be assigned the value of (a % b) at the expression (a %= b), we must save the original value of 'SUMa' to another variable (SUMx)
	SUMx = SUMa;
	SUMa %= SUMb; //a = a % b
	printf("Division of SUMa = %d and SUMb = %d Gives Remainder %d.\n", SUMa, SUMb, SUMx);

	printf("\n\n");

	return(0);
}



