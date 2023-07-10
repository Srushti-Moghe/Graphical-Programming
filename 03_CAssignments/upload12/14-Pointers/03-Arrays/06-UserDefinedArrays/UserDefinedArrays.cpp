#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define INT_SIZE sizeof(int)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)
#define CHAR_SIZE sizeof(char)

int main(void)
{
	// Variable Declarations
	int *SUM_ptr_iArray = NULL;
	unsigned int S_iArrayLength = 0;

	float *SUM_ptr_fArray = NULL;
	unsigned int S_fArrayLength = 0;

	double *SUM_ptr_dArray = NULL;
	unsigned int S_dArrayLength = 0;

	char *SUM_ptr_cArray = NULL;
	unsigned int S_cArrayLength = 0;

	int SUM_i;

	// Code

	// Integer Array
	printf("\n\n");
	printf("Enter the number of elements you want in the Integer Array : ");
	scanf("%u", &S_iArrayLength);

	SUM_ptr_iArray = (int *)malloc(INT_SIZE * S_iArrayLength);
	if (SUM_ptr_iArray == NULL)
	{
		printf("\n\n");
		printf("Memory allocation for Integer Array failed !!! Exitting now...\n\n");
		exit(0);
	}
	else
	{
		printf("\n\n");
		printf("Memory Allocation for the Integer Array Succeeded !!!");
	}
	printf("\n\n");
	printf("Enter the %d Integer elements to fill up the Integer Array : \n\n", S_iArrayLength);
	for (SUM_i = 0; SUM_i < S_iArrayLength; SUM_i++)
	{
		scanf("%d", (SUM_ptr_iArray + SUM_i));
	}

	// Floating-point Array
	printf("\n\n");
	printf("Enter the number of elements you want in the Floating-Point Array : ");
	scanf("%u", &S_fArrayLength);

	SUM_ptr_fArray = (float *)malloc(FLOAT_SIZE * S_fArrayLength);
	if (SUM_ptr_fArray == NULL)
	{
		printf("\n\n");
		printf("Memory allocation for Floating-point Array failed !!! Exitting now...\n\n");
		exit(0);
	}
	else
	{
		printf("\n\n");
		printf("Memory Allocation for the Floating-point Array Succeeded !!!");
	}
	printf("\n\n");
	printf("Enter the %d Float elements to fill up the Floating-point Array : \n\n", S_fArrayLength);
	for (SUM_i = 0; SUM_i < S_fArrayLength; SUM_i++)
	{
		scanf("%f", (SUM_ptr_fArray + SUM_i));
	}

	// Double Array
	printf("\n\n");
	printf("Enter the number of elements you want in the Double Array : ");
	scanf("%u", &S_dArrayLength);

	SUM_ptr_dArray = (double *)malloc(DOUBLE_SIZE * S_dArrayLength);
	if (SUM_ptr_dArray == NULL)
	{
		printf("\n\n");
		printf("Memory allocation for Double Array failed !!! Exitting now...\n\n");
		exit(0);
	}
	else
	{
		printf("\n\n");
		printf("Memory Allocation for the Double Array Succeeded !!!");
	}
	printf("\n\n");
	printf("Enter the %d Double elements to fill up the Double Array : \n\n", S_dArrayLength);
	for (SUM_i = 0; SUM_i < S_dArrayLength; SUM_i++)
	{
		scanf("%lf", (SUM_ptr_dArray + SUM_i));
	}

	// Character Array
	printf("\n\n");
	printf("Enter the number of elements you want in the Character Array : ");
	scanf("%u", &S_cArrayLength);

	SUM_ptr_cArray = (char *)malloc(CHAR_SIZE * S_cArrayLength);
	if (SUM_ptr_cArray == NULL)
	{
		printf("\n\n");
		printf("Memory allocation for Character Array failed !!! Exitting now...\n\n");
		exit(0);
	}
	else
	{
		printf("\n\n");
		printf("Memory Allocation for the Character Array Succeeded !!!");
	}
	printf("\n\n");
	printf("Enter the %d Char elements to fill up the Character Array : \n\n", S_cArrayLength);
	for (SUM_i = 0; SUM_i < S_cArrayLength; SUM_i++)
	{
		*(SUM_ptr_cArray + SUM_i) = getch();
		printf("%c\n", *(SUM_ptr_cArray + SUM_i));
	}

	// DISPLAY of ARRAYS

	// Integer Array
	printf("\n\n");
	printf("The Integer Array entered by you and consisting of %d elements is as follows : \n\n", S_iArrayLength);
	for (SUM_i = 0; SUM_i < S_iArrayLength; SUM_i++)
	{
		printf("%d\t\t at address : %p\n", *(SUM_ptr_iArray + SUM_i), (SUM_ptr_iArray + SUM_i));
	}

	// Floating-point Array
	printf("\n\n");
	printf("The Floating-point Array entered by you and consisting of %d elements is as follows : \n\n", S_fArrayLength);
	for (SUM_i = 0; SUM_i < S_fArrayLength; SUM_i++)
	{
		printf("%f\t\t at address : %p\n", *(SUM_ptr_fArray + SUM_i), (SUM_ptr_fArray + SUM_i));
	}

	// Double Array
	printf("\n\n");
	printf("The Double Array entered by you and consisting of %d elements is as follows : \n\n", S_dArrayLength);
	for (SUM_i = 0; SUM_i < S_dArrayLength; SUM_i++)
	{
		printf("%lf\t\t at address : %p\n", *(SUM_ptr_dArray + SUM_i), (SUM_ptr_dArray + SUM_i));
	}
	// Character Array
	printf("\n\n");
	printf("The Character Array entered by you and consisting of %d elements is as follows : \n\n", S_cArrayLength);
	for (SUM_i = 0; SUM_i < S_cArrayLength; SUM_i++)
	{
		printf("%c\t\t at address : %p\n", *(SUM_ptr_cArray + SUM_i), (SUM_ptr_cArray + SUM_i));
	}

	// FREEING MEMORY OCCUPIED BY ARRAYS (Reverse Order)

	// Freeing Memory for Character Array
	if (SUM_ptr_cArray)
	{
		free(SUM_ptr_cArray);
		SUM_ptr_cArray = NULL;
		printf("\n\n");
		printf("Memory occupied by Character Array has been successfully Freed!!!\n\n");
	}
	// Freeing Memory for Double Array
	if (SUM_ptr_dArray)
	{
		free(SUM_ptr_dArray);
		SUM_ptr_dArray = NULL;
		printf("\n\n");
		printf("Memory occupied by Double Array has been successfully Freed!!!\n\n");
	}
	// Freeing Memory for Floating-point Array
	if (SUM_ptr_fArray)
	{
		free(SUM_ptr_fArray);
		SUM_ptr_fArray = NULL;
		printf("\n\n");
		printf("Memory occupied by Floating-point Array has been successfully Freed!!!\n\n");
	}
	// Freeing Memory for Integer Array
	if (SUM_ptr_iArray)
	{
		free(SUM_ptr_iArray);
		SUM_ptr_iArray = NULL;
		printf("\n\n");
		printf("Memory occupied by Integer Array has been successfully Freed!!!\n\n");
	}
	return (0);
}












