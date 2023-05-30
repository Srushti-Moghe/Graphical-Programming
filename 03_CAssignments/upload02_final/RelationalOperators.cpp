#include <stdio.h>

int main(void)
{
	//variable declarations
	int a;
	int b;
	int result;

	//code
	printf("\n\n");
	printf("Enter one integer : ");
	scanf("%d", &a);

	printf("\n\n");
	printf("Enter another integer : ");
	scanf("%d", &b);

	printf("\n\n");
	printf("If Answer = 0, It is 'FALSE'.\n");
	printf("If Answer = 1, It is 'TRUE'.\n");
	
	result = (a < b);
	printf("(a < b) A = %d is Less than B = %d\t Answer = %d\n", a, b, result);

	result = (a > b);
	printf("(a > b) A = %d is Greater than B = %d\t Answer = %d\n", a, b, result);

	result = (a <= b);
	printf("(a <= b) A = %d is Less than or Equal to B = %d\t Answer = %d\n", a, b, result);

	result = (a >= b);
	printf("(a >= b) A = %d is Greater than or Equal to B = %d\t Answer = %d\n", a, b, result);

	result = (a == b);
	printf("(a == b) A = %d is Equal to B = %d\t Answer = %d\n", a, b, result);

	result = (a != b);
	printf("(a != b) A = %d is NOT Equal to B = %d\t Answer = %d\n", a, b, result);

	return(0);
}
