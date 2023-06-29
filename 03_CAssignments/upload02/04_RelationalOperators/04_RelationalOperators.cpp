#include <stdio.h>

int main(void)
{
	//variable declarations
	int rum_a;
	int rum_b;
	int rum_result;
	printf("\n\n");
	printf(" * * * * RUM_Relational operators * * * *\n\n");
	//code
	printf("\n\n");
	printf("Enter one integer : ");
	scanf("%d", &rum_a);

	printf("\n\n");
	printf("Enter another integer : ");
	scanf("%d", &rum_b);

	printf("\n\n");
	printf("If Answer = 0, It is 'FALSE'.\n");
	printf("If Answer = 1, It is 'TRUE'.\n");
	
	rum_result = (rum_a < rum_b);
	printf("(a < b) A = %d is Less than B = %d\t Answer = %d\n", rum_a, rum_b, rum_result);

	rum_result = (rum_a > rum_b);
	printf("(a > b) A = %d is Greater than B = %d\t Answer = %d\n", rum_a, rum_b, rum_result);

	rum_result = (rum_a <= rum_b);
	printf("(a <= b) A = %d is Less than or Equal to B = %d\t Answer = %d\n", rum_a, rum_b, rum_result);

	rum_result = (rum_a >= rum_b);
	printf("(a >= b) A = %d is Greater than or Equal to B = %d\t Answer = %d\n", rum_a, rum_b, rum_result);

	rum_result = (rum_a == rum_b);
	printf("(a == b) A = %d is Equal to B = %d\t Answer = %d\n", rum_a, rum_b, rum_result);

	rum_result = (rum_a != rum_b);
	printf("(a != b) A = %d is NOT Equal to B = %d\t Answer = %d\n", rum_a, rum_b, rum_result);

	return(0);
}
