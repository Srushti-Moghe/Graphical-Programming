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
	printf("Sizes of Datatypes are : \n\n");
	printf("Size of (int) : %d\tsize of pointer to int (int*) : %d\tsize of pointer to pointer to int (int**) : %d \n\n", sizeof(int), sizeof(int*), sizeof(int**));
	printf("Size of (float) : %d\tsize of pointer to float (float*) : %d\tsize of pointer to pointer to float (float**) : %d \n\n", sizeof(float), sizeof(float*), sizeof(float**));
	printf("Size of (double) : %d\tsize of pointer to double (double*) : %d\tsize of pointer to pointer to double (double**) : %d \n\n", sizeof(double), sizeof(double*), sizeof(double**));
	printf("Size of (char) : %d\tsize of pointer to char (char*) : %d\tsize of pointer to pointer to char (char**) : %d \n\n", sizeof(char), sizeof(char*), sizeof(char**));
	printf("Size of (struct SUM_Employee): %d size of pointer to struct SUM_Employee (struct SUM_Employee*): %d size of pointer to pointer to struct SUM_Employee (struct SUM_Employee**): %d \n\n", sizeof(struct SUM_Employee), sizeof(struct SUM_Employee*), sizeof(struct SUM_Employee**));

	return(0);
}


