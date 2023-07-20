#include <stdio.h>

int main(void)
{
	//Function Prototype 
	void DecimalToOctal(unsigned int);

	//Variable declarations 
	unsigned int n1;

	// Code
	printf("\n\n");
	printf("Enter integer 'n1' to convert to Octal : ");
	scanf("%u", &n1);
	printf("\n\n");

	if (n1 < 8)
	{
		printf("The octal for %d is \n\n", n1);
	}

	DecimalToOctal(n1);

	return (0);
}

// DecimalToOctal()
void DecimalToOctal(unsigned int decimal)
{
	// Variables
	unsigned int number;
	unsigned int quotient, remainder;
	int i;
	unsigned int octal[8];

	for (i = 0; i < 8; i++)
	{
		octal[i] = 0;		
	}
	printf("The octal Form of the Decimal Integer %d is = \n\n", decimal);
	number = decimal;
	i = 7; 
	while (number != 0)
	{
		
		remainder = number % 8;
		octal[i] = remainder;
		i--;
		number = number / 8;
	}
	for (i = 0; i < 8; i++)
		printf("% u", octal[i]);
	printf("\n\n");
	// return type is void
}


