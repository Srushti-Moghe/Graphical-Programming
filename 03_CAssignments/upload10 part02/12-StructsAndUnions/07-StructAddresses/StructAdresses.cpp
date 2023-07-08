#include <stdio.h>
struct SUM_MyData
{
	int SUM_i;
	float SUM_f;
	double SUM_d;
	char SUM_c;
 };
int main(void)
{
	// Variable Declarations 
	struct SUM_MyData SUM_Data;

	// Code
	// Assigning data values to the data members of 'struct SUM_MyData'

	SUM_Data.SUM_i = 50;
	SUM_Data.SUM_f = 5.645f;
	SUM_Data.SUM_d = 3.4455;
	SUM_Data.SUM_c = 'S';

	// Displaying the values of the data members of 'struct SUM_MyData'
	printf("\n\n");
	printf("Data members of the 'struct SUM_MyData' are : \n");
	printf("The value of integer member 'i'          = %d\n", SUM_Data.SUM_i);
	printf("The value of floating-point member 'f'   = %f\n", SUM_Data.SUM_f);
	printf("The value of double member 'd'           = %lf\n", SUM_Data.SUM_d);
	printf("The value of character member 'c'        = %c\n", SUM_Data.SUM_c);

	// Displaying the Addresses of the values of the data members of 'struct SUM_MyData'
	printf("\n\n");
	printf("Addresses of the Data members of the 'struct SUM_MyData' are : \n");
	printf("The value of integer member 'i' occupies address from          : %p\n", &SUM_Data.SUM_i);
	printf("The value of floating-point member 'f' occupies address from   : %p\n", &SUM_Data.SUM_f);
	printf("The value of double member 'd' occupies address from           : %p\n", &SUM_Data.SUM_d);
	printf("The value of character member 'c' occupies address from        : %p\n", &SUM_Data.SUM_c);

	printf("\n\n");
	printf("The Starting Address of 'struct SUM_MyData' variable 'SUM_Data' = %p \n\n", &SUM_Data);

	return(0);
}


