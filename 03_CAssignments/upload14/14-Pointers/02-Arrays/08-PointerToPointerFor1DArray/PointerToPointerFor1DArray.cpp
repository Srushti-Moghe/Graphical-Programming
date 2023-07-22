#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//Function Prototype
	void MyAlloc(int** SUM_ptr, unsigned int SUM_num_elements);
	int *S_piArray = NULL;
	unsigned int SUM_num_elements;
	int SUM_i;

	// Code
	printf("\n\nHow many elements you want in an Integer Array : \n\n");
	scanf("%u", &SUM_num_elements);

	printf("\n\n");
	MyAlloc(&S_piArray, SUM_num_elements);

	printf("Enter %u elements to fill up the Integer Array : \n\n", SUM_num_elements);
	for (SUM_i = 0; SUM_i < SUM_num_elements; SUM_i++)
	{
		scanf("%d", &S_piArray[SUM_i]);
	}

	printf("\n\n");
	printf("The %u elements entered by you in the Integer Array : \n\n", SUM_num_elements);;
	for (SUM_i = 0; SUM_i < SUM_num_elements; SUM_i++)
	{
		printf("%u\t", S_piArray[SUM_i]);
	}
	
	printf("\n\n");
	if (S_piArray)
	{
		free(S_piArray);
			S_piArray = NULL;
		printf("Memory Allocated to the pointer integer array has now been Successfully Freed !!!\n\n");
	}
	return(0);
}

// Function Definition
void MyAlloc(int** S_ptr, unsigned int S_numelements)
{
	// Code
	*S_ptr = (int*)malloc(S_numelements * sizeof(int));
	if (*S_ptr == NULL)
	{
		printf("Couldnot Allocate Memory !!! Exitting Now...\n\n");
		exit(0);
	}
	printf("MyAlloc() has successfully alloted %zu bytes for the Integer Array !!!\n\n", (S_numelements * sizeof(int)));
	return;
}














