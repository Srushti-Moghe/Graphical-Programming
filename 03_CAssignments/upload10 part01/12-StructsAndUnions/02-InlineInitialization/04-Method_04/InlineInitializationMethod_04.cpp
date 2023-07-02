#include <stdio.h>

// Defining struct
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
	
	/*
	100 will be assigned to 'SUM_i' of 'SUM_Data_1' of 'struct SUM_MyData'
	23.33 will be assigned to 'SUM_f' of 'SUM_Data_1' of 'struct SUM_MyData'
	45.6677 will be assigned to 'SUM_d' of 'SUM_Data_1' of 'struct SUM_MyData'
	'E' will be assigned to 'SUM_c' of 'SUM_Data_1' of 'struct SUM_MyData'
	*/
	struct SUM_MyData SUM_Data_1 = {100, 23.33f, 45.6677, 'E'};


	/*
	550 will be assigned to 'SUM_i' of 'SUM_Data_1' of 'struct SUM_MyData'
	109.3 will be assigned to 'SUM_f' of 'SUM_Data_1' of 'struct SUM_MyData'
	9.10101010 will be assigned to 'SUM_d' of 'SUM_Data_1' of 'struct SUM_MyData'
	'G' will be assigned to 'SUM_c' of 'SUM_Data_1' of 'struct SUM_MyData'
	*/
	struct SUM_MyData SUM_Data_2 = { 550, 109.3f, 9.10101010, 'Q' };


	/*
	1100 will be assigned to 'SUM_i' of 'SUM_Data_1' of 'struct SUM_MyData'
	3.33 will be assigned to 'SUM_f' of 'SUM_Data_1' of 'struct SUM_MyData'
	5.6677 will be assigned to 'SUM_d' of 'SUM_Data_1' of 'struct SUM_MyData'
	'G' will be assigned to 'SUM_c' of 'SUM_Data_1' of 'struct SUM_MyData'
	*/
	struct SUM_MyData SUM_Data_3 = { 1100, 3.33f, 5.6677, 'G' };


	/*
	300 will be assigned to 'SUM_i' of 'SUM_Data_1' of 'struct SUM_MyData'
	12.13 will be assigned to 'SUM_f' of 'SUM_Data_1' of 'struct SUM_MyData'
	67.8899 will be assigned to 'SUM_d' of 'SUM_Data_1' of 'struct SUM_MyData'
	'V' will be assigned to 'SUM_c' of 'SUM_Data_1' of 'struct SUM_MyData'
	*/
	struct SUM_MyData SUM_Data_4 = { 300, 12.13f, 67.8899, 'V' };

	/*
	800 will be assigned to 'SUM_i' of 'SUM_Data_1' of 'struct SUM_MyData'
	20.30 will be assigned to 'SUM_f' of 'SUM_Data_1' of 'struct SUM_MyData'
	123.45678 will be assigned to 'SUM_d' of 'SUM_Data_1' of 'struct SUM_MyData'
	'U' will be assigned to 'SUM_c' of 'SUM_Data_1' of 'struct SUM_MyData'
	*/
	struct SUM_MyData SUM_Data_5 = { 800, 20.30f, 123.45678, 'U' };

	// Code
	// To Display the data values of the data members of 'struct SUM_MyData'
	printf("\n\n");
	printf("The data members of 'struct SUM_MyData' are : \n\n");

	// Displaying Values for SUM_Data_1
	printf("The data members of 'struct SUM_MyData_1' are : \n\n");
	printf("The integer value of i in 'struct SUM_MyData_1' is            = %d\n", SUM_Data_1.SUM_i);
	printf("The floating-point value of f in 'struct SUM_MyData_1' is     = %f\n", SUM_Data_1.SUM_f);
	printf("The double value of d in 'struct SUM_MyData_1' is             = %lf\n", SUM_Data_1.SUM_d);
	printf("The character value of c in 'struct SUM_MyData_1' is          = %c\n", SUM_Data_1.SUM_c);
	printf("\n\n");	

	// Displaying Values for SUM_Data_2
	printf("The data members of 'struct SUM_MyData_2' are : \n\n");
	printf("The integer value of i in 'struct SUM_MyData_2' is            = %d\n", SUM_Data_2.SUM_i);
	printf("The floating-point value of f in 'struct SUM_MyData_2' is     = %f\n", SUM_Data_2.SUM_f);
	printf("The double value of d in 'struct SUM_MyData_2' is             = %lf\n", SUM_Data_2.SUM_d);
	printf("The character value of c in 'struct SUM_MyData_2' is          = %c\n", SUM_Data_2.SUM_c);
	printf("\n\n");

	// Displaying Values for SUM_Data_3
	printf("The data members of 'struct SUM_MyData_3' are : \n\n");
	printf("The integer value of i in 'struct SUM_MyData_3' is            = %d\n", SUM_Data_3.SUM_i);
	printf("The floating-point value of f in 'struct SUM_MyData_3' is     = %f\n", SUM_Data_3.SUM_f);
	printf("The double value of d in 'struct SUM_MyData_3' is             = %lf\n", SUM_Data_3.SUM_d);
	printf("The character value of c in 'struct SUM_MyData_3' is          = %c\n", SUM_Data_3.SUM_c);
	printf("\n\n");

	// Displaying Values for SUM_Data_4
	printf("The data members of 'struct SUM_MyData_4' are : \n\n");
	printf("The integer value of i in 'struct SUM_MyData_4' is            = %d\n", SUM_Data_4.SUM_i);
	printf("The floating-point value of f in 'struct SUM_MyData_4' is     = %f\n", SUM_Data_4.SUM_f);
	printf("The double value of d in 'struct SUM_MyData_4' is             = %lf\n", SUM_Data_4.SUM_d);
	printf("The character value of c in 'struct SUM_MyData_4' is          = %c\n", SUM_Data_4.SUM_c);
	printf("\n\n");

	// Displaying Values for SUM_Data_5
	printf("The data members of 'struct SUM_MyData_5' are : \n\n");
	printf("The integer value of i in 'struct SUM_MyData_5' is            = %d\n", SUM_Data_5.SUM_i);
	printf("The floating-point value of f in 'struct SUM_MyData_5' is     = %f\n", SUM_Data_5.SUM_f);
	printf("The double value of d in 'struct SUM_MyData_5' is             = %lf\n", SUM_Data_5.SUM_d);
	printf("The character value of c in 'struct SUM_MyData_5' is          = %c\n", SUM_Data_5.SUM_c);
	printf("\n\n");
	
	return(0);
}



