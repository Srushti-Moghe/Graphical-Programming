#include <stdio.h>

int main(void)
{
	//function prototypes
	void PrintBinaryFormOfNumber(unsigned int);

	//variable declarations //the variables a, b, result correspond to SUMa, SUMb, SUMresult
	unsigned int SUMa;
	unsigned int SUMb;
	unsigned int SUMresult;

	//code
	printf("\n\n");
	printf("Enter an Integer : ");
	scanf("%u", &SUMa);

	printf("\n\n");
	printf("Enter another Integer : ");
	scanf("%u", &SUMb);

	printf("\n\n\n\n");
	SUMresult = SUMa & SUMb;
	printf("Bitwise AND-ing of \n A = %d (Decimal) and B = %d (Decimal) gives result %d (Decimal). \n\n", SUMa, SUMb, SUMresult);

	PrintBinaryFormOfNumber(SUMa);
	PrintBinaryFormOfNumber(SUMb);
	PrintBinaryFormOfNumber(SUMresult);

	return(0);
}


//code objective : To Obtain the binary representation of decimal integers so that bitwise AND-ing, OR-ing, COMPLEMENT and BIT SHIFTING could be easily understood

void PrintBinaryFormOfNumber(unsigned int decimal_number)
{
	//variable declarations
	unsigned int quotient, remainder;
	unsigned int num;
	unsigned int binary_array[8];
	int i;

	//code
	for (i = 0; i < 8; i++)
		binary_array[i] = 0;
	printf("The Binary Form of the Decimal Integer %d is\t=\t", decimal_number);
	num = decimal_number;
	i = 7;
	while (num != 0)
	{
		quotient = num / 2;
		remainder = num % 2;
		binary_array[i] = remainder;
		num = quotient;
		i--;
	}

	for (i = 0; i < 8; i++)
		printf(" %u", binary_array[i]);

	printf("\n\n");
}






