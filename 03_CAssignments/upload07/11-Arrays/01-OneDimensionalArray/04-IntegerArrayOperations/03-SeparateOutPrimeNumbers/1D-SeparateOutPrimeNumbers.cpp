#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
	//Variable declarations
	int SiArray[NUM_ELEMENTS];
	int S_i, S_num, S_j, S_count = 0;
	
	//Code
	printf("\n\n");

	//***ARRAY ELEMENTS INPUT***
	printf("Enter Integer Elements for Array : \n\n");
	for (S_i = 0; S_i < NUM_ELEMENTS; S_i++)
	{
		scanf("%d", &S_num);
		//If 'num' is negative (<0), then convert it to positive int by multiplying it with (-1)
		if (S_num < 0)
		{
			S_num = -1 * S_num;
		}
		SiArray[S_i] = S_num;
	}

	//***printing Entire Array***
	printf("\n\n");
	printf("Array Elements are : \n\n");
	for (S_i = 0; S_i < NUM_ELEMENTS; S_i++)
	{
		printf("%d \n", SiArray[S_i]);
	}

	//***Separating the Even Numbers from the Array Elements
	printf("\n\n");
	printf("Prime Numbers Amongst all the Array Elements are : \n\n");
	for (S_i = 0; S_i < NUM_ELEMENTS; S_i++)
	{
		for (S_j = 1; S_j <= SiArray[S_i]; S_j++)
		{
			if ((SiArray[S_i]) % S_j == 0)
			{
				S_count++;
			}
		}
		//NUM 1 - neither Prime nor Constant
		//Condition for NUM to be Prime - It id only Divisible bt 1
		//Hence, if the number is Prime, value of 'COUNT' will exactly be '2'
		//If the value of 'COUNT' is grater than 2, the number is divisible by Numbers other than 1 and hence wont be a prime number
		//The value of 'COUNT' will be 1 only if iArray[i] is 1

		if (S_count >= 2)
		{
			printf("%d\n", SiArray[S_i]);
			S_count = 0; // reset count to 0 for checking next/ new number
		}
	}
	return(0);
}














