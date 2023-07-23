#include <stdio.h>
#include <stdlib.h>

// Define struct
struct SUM_MyData
{
	int *ptr_SUM_i;
	int SUM_i;

	float *ptr_SUM_f;
	float SUM_f;

	double *ptr_SUM_d;
	double SUM_d;	
};

int main(void)
{
	// variable Declarations
	struct SUM_MyData *ptr_SUM_Data;

	// Code
	printf("\n\n");
	ptr_SUM_Data = (struct SUM_MyData*)malloc(sizeof(struct SUM_MyData));
	if (ptr_SUM_Data == NULL)
	{
		printf("Failed to Allocate Memory to 'struct MyData' !!! Exitting Now.....\n\n");
		exit(0);
	}
	else
	{
		printf("Successfully allocated Memory to 'struct MyData'!!!\n\n");
	}

	(*ptr_SUM_Data).SUM_i = 20;
	(*ptr_SUM_Data).ptr_SUM_i = &(*ptr_SUM_Data).SUM_i;

	(*ptr_SUM_Data).SUM_f = 14.8585f;
	(*ptr_SUM_Data).ptr_SUM_f = &(*ptr_SUM_Data).SUM_f;

	(*ptr_SUM_Data).SUM_d = 90.454545445;
	(*ptr_SUM_Data).ptr_SUM_d = &(*ptr_SUM_Data).SUM_d;

	// Displaying VAlues and addresses of the Datat Members of 'struct MyData'
	printf("\n\n");
	printf("Data Members of 'struct MyData' along with their Addresses are : \n\n");
	
	printf("\n\nValue at i    = %d\n", *((*ptr_SUM_Data).ptr_SUM_i));
	printf("Address of i  = %p\n", (*ptr_SUM_Data).ptr_SUM_i);

	printf("\n\nValue at f     = %f\n", *((*ptr_SUM_Data).ptr_SUM_f));
	printf("Address of f   = %p\n", (*ptr_SUM_Data).ptr_SUM_f);

	printf("\n\nValue at d     = %lf\n", *((*ptr_SUM_Data).ptr_SUM_d));
	printf("Address of d   = %p\n", (*ptr_SUM_Data).ptr_SUM_d);
	
	if (ptr_SUM_Data)
	{
		free(ptr_SUM_Data);
		ptr_SUM_Data = NULL;
		printf("memory allocated to 'struct Mydata' has been successfully Freed!!!\n\n");
	}

	return(0);
}







