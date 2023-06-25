#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
	//Variable declarations
	int SiArray[NUM_ELEMENTS];
	int S_i, S_num, S_sum = 0;
	
	//Code
	printf("\n\n");

	//***ARRAY ELEMENTS INPUT***
	printf("Enter Integer Elements for Array : \n\n");
	for (S_i = 0; S_i < NUM_ELEMENTS; S_i++)
	{
		scanf("%d", &S_num);
		SiArray[S_i] = S_num;
	}

	//***Separating the Even Numbers from the Array Elements
	printf("\n\n");
	printf("Even Numbers Amongst all the Arrays are : \n\n");
	for (S_i = 0; S_i < NUM_ELEMENTS; S_i++)
	{
		if ((SiArray[S_i] % 2) == 0)
			printf("%d \n", SiArray[S_i]);
	}

	//***Separating the Odd Numbers from the Array Elements
	printf("\n\n");
	printf("Odd Numbers Amongst all the Arrays are : \n\n");
	for (S_i = 0; S_i < NUM_ELEMENTS; S_i++)
	{
		if ((SiArray[S_i] % 2) != 0)
			printf("%d \n", SiArray[S_i]);
	}
	return(0);
}














