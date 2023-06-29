#include <stdio.h>

//Defining Struct
struct SUM_MyData
{
	int SUM_i;
	float SUM_f;
	double SUM_d;
	char SUM_c;
} SUM_data; // Global Declaration of variable SUM_Data (that includes 4 different data types), with SUM_MyData as its datatype

int main(void)
{
	//Variable Declarations
	int SUM_i_size;
	int SUM_f_size;
	int SUM_d_size;

	int struct_SUM_MyData_size;

	//Code 
	//Assigning Data values to the Data members of 'SUM_MyData'
	SUM_data.SUM_i = 50;
	SUM_data.SUM_f = 12.25f;
	SUM_data.SUM_d = 4.5555;
	SUM_data.SUM_c = 'S';

	//To display the members of 'SUM_MyData'
	printf("\n\n");
	printf("The Data Members of 'struct MyData' are : \n\n");
	printf("integer value of i        = %d\n", SUM_data.SUM_i);
	printf("floating point value f    = %f\n", SUM_data.SUM_f);
	printf("double value d            = %d\n", SUM_data.SUM_d);

	/*
	Calculating the sizes of Data members (struct SUM_MyData) in bytes 

	SUM_i_size = sizeof(SUM_data.SUM_i);
	SUM_f_size = sizeof(SUM_data.SUM_f);
	SUM_d_size = sizeof(SUM_data.SUM_d);
	printf("\n\n");
	printf("The Size (in Bytes) of Data Members of 'struct MyData' are : \n\n");
	printf("Size of integer value i           = %d Bytes\n", SUM_data.SUM_i);
	printf("Size of floating point value f    = %d Bytes\n", SUM_data.SUM_f);
	printf("Size of double value d            = %d Bytes\n", SUM_data.SUM_d);
	
	OR 

	Calculating the sizes of Data members (struct SUM_MyData) in bytes

	printf("\n\n");
	printf("The Size (in Bytes) of Data Members of 'struct MyData' are : \n\n");
	printf("Size of integer value i           = %d Bytes\n", sizeof(SUM_data.SUM_i));
	printf("Size of floating point value f    = %d Bytes\n", sizeof(SUM_data.SUM_f));
	printf("Size of double value d            = %d Bytes\n", sizeof(SUM_data.SUM_d));
	*/

	//To display the size in bytes of the members of (struct SUM_MyData)
	printf("\n\n");
	printf("The Size (in Bytes) of Data Members of 'struct MyData' are : \n\n");
	printf("Size of integer value i           = %d Bytes\n", sizeof(SUM_data.SUM_i));
	printf("Size of floating point value f    = %d Bytes\n", sizeof(SUM_data.SUM_f));
	printf("Size of double value d            = %d Bytes\n", sizeof(SUM_data.SUM_d));
	
	//To CAlculate the size in bytes for the enire (srtuct SUM_MyData)
	struct_SUM_MyData_size = sizeof(struct SUM_MyData);
	//To Display the size in bytes for the enire (srtuct SUM_MyData)
	printf("\n\n");
	printf("The Size (in Bytes) of 'struct MyData' is = %d Bytes \n\n", struct_SUM_MyData_size);

	return(0);
}


