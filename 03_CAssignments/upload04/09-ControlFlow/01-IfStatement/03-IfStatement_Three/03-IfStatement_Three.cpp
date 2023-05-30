#include <stdio.h>

int main(void)
{
	//variable declarations 
	int S_num;

	//code
	printf("\n\n");

	printf("Enter value for 'NUM' : ");
	scanf("%d", &S_num);

	if (S_num < 0)
	{
		printf("NUM = %d is less than 0 (Negative).\n\n", S_num);
	}

	if ((S_num > 0) && (S_num <= 100))
	{
		printf("NUM = %d is between 0 and 100.\n\n", S_num);
	}

	if ((S_num > 100) && (S_num <= 200))
	{
		printf("NUM = %d is between 100 and 200.\n\n", S_num);
	}

	if ((S_num > 200) && (S_num <= 300))
	{
		printf("NUM = %d is between 200 and 300.\n\n", S_num);
	}

	if ((S_num > 300) && (S_num <= 400))
	{
		printf("NUM = %d is between 300 and 400.\n\n", S_num);
	}

	if ((S_num > 400) && (S_num <= 500))
	{
		printf("NUM = %d is between 400 and 500.\n\n", S_num);
	}

	if (S_num > 500) 
	{
		printf("NUM = %d is between 0 and 100.\n\n", S_num);
	}
	
	return(0);	
}


