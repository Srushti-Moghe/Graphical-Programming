#include <stdio.h>

#define MAX_NAME_LENGTH 100

struct Employee
{
	char S_name[MAX_NAME_LENGTH];
	unsigned int S_age;
	char S_gender;
	double S_salary;
};

struct MyData
{
	int S_i;
	float S_f;
	double S_d;
	char S_c;
};

int main(void)
{
	//typedef 's
	typedef struct Employee MY_EMPLOYEE_TYPE;
	typedef struct MyData MY_DATA_TYPE;

	//Variable Declarations
	struct Employee emp = { "Avinash", 25, 'M', 10000.00 };
	MY_EMPLOYEE_TYPE emp_typedef = { "Aarya", 35, 'F', 100000.00 };

	struct MyData md = { 30, 22.22f, 54.78654, 'S' };
	MY_DATA_TYPE md_typedef;

	//Code
	md_typedef.S_i = 90;
	md_typedef.S_f = 4.66f;
	md_typedef.S_d = 95.834756;
	md_typedef.S_c = 'I';

	printf("\n\n");
	printf("struct Employee : \n\n");
	printf("emp.name      = %s\n", emp.S_name);
	printf("emp.age       = %d\n", emp.S_age);
	printf("emp.gender    = %c\n", emp.S_gender);
	printf("emp.salary    = %lf\n", emp.S_salary);

	printf("\n\n");
	printf("MY_EMPLOYEE_TYPE : \n\n");
	printf("emp_typedef.name      = %s\n", emp_typedef.S_name);
	printf("emp_typedef.age       = %d\n", emp_typedef.S_age);
	printf("emp_typedef.gender    = %c\n", emp_typedef.S_gender);
	printf("emp_typedef.salary    = %lf\n", emp_typedef.S_salary);

	printf("\n\n");
	printf("struct MyData : \n\n");
	printf("md.S_i     =%d\n", md.S_i);
	printf("md.S_f     =%f\n", md.S_f);
	printf("md.S_d     =%lf\n", md.S_d);
	printf("md.S_c     =%c\n", md.S_c);

	printf("\n\n");
	printf("MY_DATA_TYPE : \n\n");
	printf("md_typedef.S_i     =%d\n", md_typedef.S_i);
	printf("md_typedef.S_f     =%f\n", md_typedef.S_f);
	printf("md_typedef.S_d     =%lf\n", md_typedef.S_d);
	printf("md_typedef.S_c     =%c\n", md_typedef.S_c);

	printf("\n\n");

	return (0);
}



























