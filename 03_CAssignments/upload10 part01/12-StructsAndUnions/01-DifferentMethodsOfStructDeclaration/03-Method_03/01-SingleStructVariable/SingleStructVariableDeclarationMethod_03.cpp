#include <stdio.h>


int main(void)
{
	// Defining Struct
	struct SUM_MyData
	{
		int SUM_i;
		float SUM_f;
		double SUM_d;
		char SUM_c;
	};
	struct SUM_MyData SUM_Data; // Local Declaration of variable SUM_Data (that includes 4 different data types), with SUM_MyData as its datatype

	// Variable Declarations
	int SUM_i_size;
	int SUM_f_size;
	int SUM_d_size;
	int SUM_c_size;

	int SUM_struct_MyData_size;


	// Code
	// Assigning Data values to the members of SUM_Data

	SUM_Data.SUM_i = 30;
	SUM_Data.SUM_f = 42.13f;
	SUM_Data.SUM_d = 94.350345;
	SUM_Data.SUM_c = 'A';

	// Printing the members of struct 'SUM_Data' (with 'SUM_MyData' as its datatype)
	printf("\n\n");
	printf("The Members of struct 'SUM_Data' (with Datatype 'SUM_MyData') are : \n\n");
	printf("The Integer member of struct 'SUM_Data' i           = %d \n", SUM_Data.SUM_i);
	printf("The Floating-Point member of struct 'SUM_Data' f    = %f \n", SUM_Data.SUM_f);
	printf("The Double member of struct 'SUM_Data' d            = %lf \n", SUM_Data.SUM_d);
	printf("The Character member of struct 'SUM_Data' c         = %c \n", SUM_Data.SUM_c);
	printf("\n\n");

	// Getting the sizes (In Bytes) of each variable of the struct 'SUM_MyData' based on their different datatypes
	SUM_i_size = sizeof(SUM_Data.SUM_i);
	SUM_f_size = sizeof(SUM_Data.SUM_f);
	SUM_d_size = sizeof(SUM_Data.SUM_d);
	SUM_c_size = sizeof(SUM_Data.SUM_c);

	/*
	Getting the sizes (In Bytes) of each variable of the struct 'SUM_MyData' based on their different datatypes

	printf("The Size (in Bytes) of Data Members of 'struct MyData' are : \n");
	printf("Size of integer value i           = %d Bytes\n", sizeof(SUM_data.SUM_i));
	printf("Size of floating point value f    = %d Bytes\n", sizeof(SUM_data.SUM_f));
	printf("Size of double value d            = %d Bytes\n", sizeof(SUM_data.SUM_d));
	printf("Size of character value c         = %d Bytes\n", sizeof(SUM_data.SUM_c));
	*/

	// Printing the sizes (In Bytes) of each variable of the struct 'SUM_MyData' based on their different datatypes
	printf("\n\n");
	printf("The size of Members of struct 'SUM_Data' (with Datatype 'SUM_MyData') are : \n");
	printf("The size of Integer member of struct 'SUM_Data' i           = %d Bytes \n", SUM_i_size);
	printf("The size of Floating-Point member of struct 'SUM_Data' f    = %d Bytes \n", SUM_f_size);
	printf("The size of Double member of struct 'SUM_Data' d            = %d Bytes \n", SUM_d_size);
	printf("The size of Character member of struct 'SUM_Data' c         = %d Bytes \n", SUM_c_size);
	printf("\n\n");

	/*
	To Calculate the size in bytes for the enire (srtuct SUM_MyData)

	struct_SUM_MyData_size = sizeof(struct SUM_MyData);
	printf("\n\n");
	printf("The size of struct 'SUM_Data' (with Datatype 'SUM_MyData') is : %d Bytes \n", sizeof(SUM_Data));
	*/

	// Printing the sizes (In Bytes) of the struct 'SUM_MyData' 
	printf("\n\n");
	printf("The size of struct 'SUM_Data' (with Datatype 'SUM_MyData') is : %d Bytes \n", sizeof(SUM_Data));

	return (0);
}


