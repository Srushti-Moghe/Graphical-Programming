#include <stdio.h>

// Defining struct
struct SUM_MyData
{
	int SUM_i;
	float SUM_f;
	double SUM_d;
	char SUM_c;
} SUM_Data = { 300, 45.55f, 34.12131415, 'S' }; // Inline Initialization of struct variable SUM_Data with struct SUM_MyData (including 4 different datatypes).

int main(void)
{
	// Code
	// To Display the data values of the data members of 'struct SUM_MyData'
	printf("\n\n");
	printf("The data members of 'struct SUM_MyData' are : \n\n");
	printf("The integer value of i in 'struct SUM_MyData' is            = %d\n", SUM_Data.SUM_i);
	printf("The floating-point value of f in 'struct SUM_MyData' is     = %f\n", SUM_Data.SUM_f);
	printf("The double value of d in 'struct SUM_MyData' is             = %d\n", SUM_Data.SUM_d);
	printf("The character value of c in 'struct SUM_MyData' is          = %c\n", SUM_Data.SUM_c);
	printf("\n\n");	
	
	return(0);
}



