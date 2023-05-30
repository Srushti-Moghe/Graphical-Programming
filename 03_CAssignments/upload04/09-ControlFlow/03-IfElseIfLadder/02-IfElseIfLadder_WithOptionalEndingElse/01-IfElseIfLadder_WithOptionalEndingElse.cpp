#include <stdio.h>
int main(void)
{
	//variable declarations 
	int SUM_num;
	
	//code
	printf("\n\n");

	printf("Enter value for Num : ");
	scanf("%d", &SUM_num);
	
	//IF - ELSE -IF LADDER 
	if (SUM_num < 0)
		printf("Num = %d is LESS than 0 (Negative) !!!\n\n", SUM_num);

	else if ((SUM_num > 0) && (SUM_num <= 100))
		printf("Num = %d is between 0 and 100 !!!\n\n", SUM_num);

	else if ((SUM_num > 100) && (SUM_num <= 200))
		printf("Num = %d is between 100 and 200 !!!\n\n", SUM_num);

	else if ((SUM_num > 200) && (SUM_num <= 300))
		printf("Num = %d is between 200 and 300 !!!\n\n", SUM_num);

	else if ((SUM_num > 300) && (SUM_num <= 400))
		printf("Num = %d is between 300 and 400 !!!\n\n", SUM_num);

	else if ((SUM_num > 400) && (SUM_num <= 500))
		printf("Num = %d is between 400 and 500 !!!\n\n", SUM_num);

	else if ((SUM_num > 500) && (SUM_num <= 1000))
		printf("Num = %d is between 500 and 1000 !!!\n\n", SUM_num);

	else if (SUM_num > 1000)
		printf("Num = %d is GREATER than 1000 !!!\n\n", SUM_num);

	else // This is the terminating ELSE in this ladder
		printf("Invalid Value entered !!!");

	return(0);
}









