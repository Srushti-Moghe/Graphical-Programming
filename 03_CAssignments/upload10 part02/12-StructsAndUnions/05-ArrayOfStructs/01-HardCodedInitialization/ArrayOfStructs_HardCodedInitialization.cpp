#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 100
#define MARITAL_STATUS 10

// Defining struct SUM_MyEmployee
struct SUM_MyEmployee
{
	char S_name[NAME_LENGTH];
    int S_age;
	float S_salary;
	char S_sex;
	char S_marital_status[MARITAL_STATUS];
};

int main(void)
{
	// Declaration of struct variable
	struct SUM_MyEmployee SUM_EmployeeRecord[5]; // Array of 5 structs each of type struct 'SUM_MyEmployee'

	char SUM_Employee_Rajesh[] = "Rajesh";
	char SUM_Employee_Sameer[] = "Sameer";
	char SUM_Employee_Kalyani[] = "Kalyani";
	char SUM_Employee_Sonali[] = "Sonali";
	char SUM_Employee_Shantanu[] = "Shantanu";

	int SUM_i;

	// Code 
	// Hard coded Initialization for 'struct SUM_MyEmployee'

	// Employee - 1
	strcpy(SUM_EmployeeRecord[0].S_name, SUM_Employee_Rajesh);
	SUM_EmployeeRecord[0].S_age = 30;
	SUM_EmployeeRecord[0].S_salary = 50000.00f;
	SUM_EmployeeRecord[0].S_sex = 'M';
	strcpy(SUM_EmployeeRecord[0].S_marital_status, "Unmarried");


	// Employee - 2
	strcpy(SUM_EmployeeRecord[1].S_name, SUM_Employee_Sameer);
	SUM_EmployeeRecord[1].S_age = 35;
	SUM_EmployeeRecord[1].S_salary = 45000.00f;
	SUM_EmployeeRecord[1].S_sex = 'M';
	strcpy(SUM_EmployeeRecord[1].S_marital_status, "Married");
	
	// Employee - 3
	strcpy(SUM_EmployeeRecord[2].S_name, SUM_Employee_Kalyani);
	SUM_EmployeeRecord[2].S_age = 25;
	SUM_EmployeeRecord[2].S_salary = 25000.00f;
	SUM_EmployeeRecord[2].S_sex = 'F';
	strcpy(SUM_EmployeeRecord[2].S_marital_status, "Unmarried");

	// Employee - 4
	strcpy(SUM_EmployeeRecord[3].S_name, SUM_Employee_Sonali);
	SUM_EmployeeRecord[3].S_age = 45;
	SUM_EmployeeRecord[3].S_salary = 90000.00f;
	SUM_EmployeeRecord[3].S_sex = 'F';
	strcpy(SUM_EmployeeRecord[3].S_marital_status, "Married");

	// Employee - 5
	strcpy(SUM_EmployeeRecord[4].S_name, SUM_Employee_Shantanu);
	SUM_EmployeeRecord[4].S_age = 40;
	SUM_EmployeeRecord[4].S_salary = 80000.00f;
	SUM_EmployeeRecord[4].S_sex = 'M';
	strcpy(SUM_EmployeeRecord[4].S_marital_status, "Married");

	// To display the values in the array
	printf("\n\n");
	printf("*****Displaying Employee Records*****\n\n");
	for (SUM_i = 0; SUM_i < 5; SUM_i++)
	{
		printf("***Employee Number %d ***\n", (SUM_i + 1));
		printf("Name                : %s\n", SUM_EmployeeRecord[SUM_i].S_name);
		printf("Age                 : %d\n", SUM_EmployeeRecord[SUM_i].S_age);
		if (SUM_EmployeeRecord[SUM_i].S_sex == 'F' || SUM_EmployeeRecord[SUM_i].S_sex == 'f')
		{
			printf("Sex                 : Female\n");
		}
		else
		{
			printf("Sex                 : Male\n");
		}
		printf("Salary              : %f\n", SUM_EmployeeRecord[SUM_i].S_salary);
		printf("Marital Status      : %s\n\n", SUM_EmployeeRecord[SUM_i].S_marital_status);
	}
	printf("\n\n");

	return(0);
}

