#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
	//Variable declarations
	int SiArray[NUM_ELEMENTS];
	int Si, Snum, S_sum = 0;
	
	//Code
	printf("\n\n");
	printf("Enter Elements for Array : \n\n");
	for (Si = 0; Si < NUM_ELEMENTS; Si++)
	{
		scanf("%d", &Snum);
		SiArray[Si] = Snum;
	}
	
	for (Si = 0; Si < NUM_ELEMENTS; Si++)
	{
		S_sum = S_sum + SiArray[Si];
	}

	printf("\n\n");
	printf("Sum of all Elements of Array = %d\n\n", S_sum);

	return(0);
}














