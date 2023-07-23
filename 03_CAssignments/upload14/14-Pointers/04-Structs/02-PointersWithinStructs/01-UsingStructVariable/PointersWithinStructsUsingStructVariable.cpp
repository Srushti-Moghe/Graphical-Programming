#include <stdio.h>

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
	struct SUM_MyData SUM_Data;

	// Code
	SUM_Data.SUM_i = 10;
	SUM_Data.ptr_SUM_i = &SUM_Data.SUM_i;

	SUM_Data.SUM_f = 14.8585f;
	SUM_Data.ptr_SUM_f = &SUM_Data.SUM_f;

	SUM_Data.SUM_d = 90.454545445;
	SUM_Data.ptr_SUM_d = &SUM_Data.SUM_d;

	// Displaying VAlues and addresses of the Datat Members of 'struct MyData'
	printf("\n\n");
	printf("Data Members of 'struct MyData' along with their Addresses are : \n\n");
	
	printf("\n\nValue at i    = %d\n", *(SUM_Data.ptr_SUM_i));
	printf("Address of i  = %p\n", SUM_Data.ptr_SUM_i);

	printf("\n\nValue at f     = %f\n", *(SUM_Data.ptr_SUM_f));
	printf("Address of f   = %p\n", SUM_Data.ptr_SUM_f);

	printf("\n\nValue at d     = %lf\n", *(SUM_Data.ptr_SUM_d));
	printf("Address of d   = %p\n", SUM_Data.ptr_SUM_d);
	
	return(0);
}






