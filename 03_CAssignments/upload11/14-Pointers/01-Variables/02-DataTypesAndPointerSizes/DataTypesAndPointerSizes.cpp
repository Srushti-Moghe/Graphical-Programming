#include <stdio.h>

struct SUM_Employee
{
	char SUM_name[100];
	int SUM_age;
	float SUM_salary;
	char SUM_sex;
	char SUM_marital_status;
} SUM_MyEmployee;

int main(void)
{
	// Code 
	printf("\n\n");
	printf("Sizes of Data Types and Pointers to those respective Data types are : \n\n");
	printf("Size of (int)                   : %zd \t\t\t Size of pointer to int (int*)                                 : %zd \n\n", sizeof(int), sizeof(int*));
	printf("Size of (float)                 : %zd \t\t\t Size of pointer to float (float*)                             : %zd \n\n", sizeof(float), sizeof(float*));
	printf("Size of (double)                : %zd \t\t\t Size of pointer to double (double*)                           : %zd \n\n", sizeof(double), sizeof(double*));
	printf("Size of (char)                  : %zd \t\t\t Size of pointer to character (char*)                          : %zd \n\n", sizeof(char), sizeof(char*));
	printf("Size of (struct SUM_Employee)   : %zd \t\t\tSize of pointer to struct SUM_Employee (struct SUM_Employee*)  : %zd \n\n", sizeof(struct SUM_Employee), sizeof(struct SUM_Employee*));

	return(0);

}