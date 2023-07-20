#include <stdio.h>
int main(void)
{
	//Function Prototype 
	void DecimalToBinary(unsigned int);

	//Variable declarations 
	unsigned int n1;

	// Code
	printf("\n\n");
	printf("Enter integer 'n1' to convert to Binary : ");
	scanf("%u", &n1);
	printf("\n\n");

	printf("The binary for %d is \n\n", n1);

	DecimalToBinary(n1);

	return (0);
}
// DecimalToBinary()
void DecimalToBinary(unsigned int decimal)
{
	// Variables
	unsigned int number;
	unsigned int quotient, remainder;
	int i;
	unsigned int binary[8];

	for (i = 0; i < 8; i++)
	{
		binary[i] = 0;		
	}
	printf("The Binary Form of the Decimal Integer %d is = \n\n", decimal);
	number = decimal;
	i = 7; 
	while (number != 0)
	{
		
		remainder = number % 2;
		binary[i] = remainder;
		i--;
		number = number / 2;
	}
	for (i = 0; i < 8; i++)
		printf("% u", binary[i]);
	printf("\n\n");
	// return type is void
}
