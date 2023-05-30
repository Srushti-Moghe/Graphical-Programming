#include <stdio.h>

int main(void)
{
	//variable declarations
	int a;
	int b;
	int c;
	int result;

	//code
	printf("\n\n");
	printf("Enter First Integer : ");
	scanf("%d", &a);

	printf("\n\n");
	printf("Enter Second Integer : ");
	scanf("%d", &b);

	printf("\n\n");
	printf("Enter Third Integer : ");
	scanf("%d", &c);

	printf("\n\n");
	printf("If Answer = 0, It is 'False'. \n");
	printf("If the Answer = 1, It is 'TRUE'. \n");

	result = (a <= b) && (b != c);
	printf("LOGICAL && : Answer is TRUE (1) If and Only IF Both the conditions are True. The Answer is FALSE (0), If anyone or both conditions are False. \n\n");
	printf("A = %d Is  LEss than or Equal to B = %d is Not Equaal to C = %d \t Answer = %d\n\n", a, b, c, result);

	result = (b >= a) || (a == c);
	printf("LOGICAL OPERATOR OR (||) : Answer is FALSE (0) if and only if BOTH conditions are False. Tha answer is TRUE (1), If any one or both Conditions are TRUE. \n\n");
	printf("Either B = %d is Greater than or Equal to A = %d OR A = %d Is equal to c = %d \t Answer = %d\n\n", b, a, a, c, result);

	result = !a;
	printf("A = %d And using Logical NOT (!) Operator on A gives Result = %d\n\n", a, result);

	result = !b;
	printf("B = %d and using Logical NOT (!) Operator on B Gives Result = %d\n\n", b, result);

	result = !c;
	printf("C = %d and using Logical NOT (!) Operator on C gives result = %d\n\n", c, result);

	result = (!(a < +b) && !(b != c));
	printf("Using Logical NOT (!) on (a <= B) and also on (b != c) and then Adding them afterwards gives the result = %d\n", result);

	printf("\n\n");

	result = !((b >= a) || (a == c));
	printf("Using Logical NOT (!) on Entire Logical Expression (b >= a) || (a ==c) gives result = %d\n", result);

	printf("\n\n");

	return(0);
}



