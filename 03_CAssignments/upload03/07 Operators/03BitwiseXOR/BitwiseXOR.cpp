#include <stdio.h>

int main(void)
{
	//Function Prototypes 
	void PrintBinaryFormOfNumber(unsigned int);

	//Variable declarations //The variables a, b, result correspond to SUMa, SUMb, SUMresult
	unsigned int SUMa;
	unsigned int SUMb;
	unsigned int SUMresult;

	//code
	printf("\n\n");
	printf("Enter an integer : ");
	scanf("%u", &SUMa);

	printf("\n\n");
	printf("Enter another integer : ");
	scanf("%u", &SUMb);

	printf("\n\n\n\n");
	SUMresult = SUMa | SUMb;
	printf("Bitwise XOR-ing of \nSUMa = %d (Decimal) and B = %d (Decimal) gives result %d (Decimal). \n\n", SUMa, SUMb, SUMresult);

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
		printf("% u", binary_array[i]);

	printf("\n\n");
}



 