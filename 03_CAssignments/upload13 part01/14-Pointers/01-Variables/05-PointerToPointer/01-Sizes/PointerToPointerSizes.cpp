#include <stdio.h>
struct SUM_Employee
{
	char SUM_name[100];
	int SUM_age;
	float SUM_salary;
	char SUM_sex;
	char SUM_marital_status;
};
int main(void)
{
	// Code
	printf("\n\n");
	printf("Sizes of Datatypes are : ");
	printf("Size of (int)     : %d \t\t\t size of pointer to int (int*)         : %d \t\t\t size of pointer to pointer to int (int**)          : %d \n\n", sizeof(int), sizeof(int*), sizeof(int**));
	printf("Size of (float)   : %d \t\t\t size of pointer to float (float*)     : %d \t\t\t size of pointer to pointer to float (float**)      : %d \n\n", sizeof(float), sizeof(float*), sizeof(float**));
	printf("Size of (double)  : %d \t\t\t size of pointer to double (double*)   : %d \t\t\t size of pointer to pointer to double (double**)    : %d \n\n", sizeof(double), sizeof(double*), sizeof(double**));
	printf("Size of (char)    : %d \t\t\t size of pointer to char (char*)       : %d \t\t\t size of pointer to pointer to char (char**)        : %d \n\n", sizeof(char), sizeof(char*), sizeof(char**));


}
