#include <stdio.h>
#include <stdlib.h>

// Define struct
struct SUM_MyData
{
	int SUM_i;
	float SUM_f;
	double SUM_d;
};

int main(void)
{
	// variable Declarations
	int SUM_iSize = 0;
	int SUM_fSize = 0;
	int SUM_dSize = 0;
	int SUM_Mydata_Size;
	int SUM_ptr_MyData_Size;
	struct SUM_MyData *SUM_pData = NULL;

	// Code
	printf("\n\n");
	SUM_pData = (struct SUM_MyData*)malloc(sizeof(struct SUM_MyData));
	if (SUM_pData == NULL) 
	{
		printf("Failed to allocate Memory to 'struct MyData'!!!\n\n");
		exit(0);
	}
	else
	{
		printf("Successfully Allocated Memory to 'struct MyData' !!!\n\n");
	}
	// Asssigning Data Values to the Data Members of 'struct MyData'
	(*SUM_pData).SUM_i = 30;
	(*SUM_pData).SUM_f = 18.56f;
	(*SUM_pData).SUM_d = 1.565656556;

	// Displaying VAlues of the Datat Members of 'struct MyData'
	printf("\n\n");
	printf("Data Members of 'struct MyData' are : \n\n");
	printf("i = %d\n", (*SUM_pData).SUM_i);
	printf("f = %f\n", (*SUM_pData).SUM_f);
	printf("d = %lf\n", (*SUM_pData).SUM_d);

	// Displaying Sizes in bytes, of the 'struct MyData'
	printf("\n\n");
	printf("Sizes (in bytes) of Data Members of 'struct MyData' are : \n\n");
	printf("Size of i = %zd bytes\n", sizeof(int));
	printf("Size of f = %zd bytes\n", sizeof(float));
	printf("Size of d = %zd bytes\n", sizeof(double));

	// Calculating size in bytes of the entire 'struct MyData'
	SUM_Mydata_Size = sizeof(struct SUM_MyData);
	SUM_ptr_MyData_Size = sizeof(struct SUM_MyData*);

	// Displaying the sizes in bytes of 'struct MyData'
	printf("\n\n");
	printf("Size of 'struct MyData'              : %d bytes\n\n", SUM_Mydata_Size);
	printf("Size of pointer to 'struct MyData'   : %d bytes\n\n", SUM_ptr_MyData_Size);
	return(0);
}






