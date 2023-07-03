#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#define NUM_EMPLOYEES 5
#define NAME_LENGTH 100
#define MARITAL_STATUS 10

// Defining struct SUM_MyEmployee
struct SUM_MyEmployee
{
	char S_name[NAME_LENGTH];
    int S_age;
	char S_sex;
	float S_salary;
	char S_marital_status;
};

int main(void)
{
	// Function Prototype
	void MyGetString(char[], int);
	// Declaration of struct variable
	struct SUM_MyEmployee SUM_EmployeeRecord[NUM_EMPLOYEES]; // Array of <NUM_EMPLOYEES> structs each of type struct 'SUM_MyEmployee'

	int SUM_i;

	// Code 
	// User-input Initialization for Array 'struct SUM_MyEmployee'
	printf("\n\n");
	for (SUM_i = 0; SUM_i < NUM_EMPLOYEES; SUM_i++)
	{
		printf("\n\n");
		printf("*****Data Entry for Employee Number %d *****\n\n", (SUM_i+1));
		printf("\n");
		printf("Enter Employee Name : ");
		MyGetString(SUM_EmployeeRecord[SUM_i].S_name, NAME_LENGTH);

		printf("\n\n");
		printf("Enter Employee's age (in years) : ");
		scanf("%d", &SUM_EmployeeRecord[SUM_i].S_age);

		printf("\n\n");
		printf("Enter Employee's sex (M/m for Male, F/f for Female) : ");
		SUM_EmployeeRecord[SUM_i].S_sex = getch();
		printf("%c", SUM_EmployeeRecord[SUM_i].S_sex);
		SUM_EmployeeRecord[SUM_i].S_sex = toupper(SUM_EmployeeRecord[SUM_i].S_sex);

		printf("\n\n");
		printf("Enter Employee's age Salary (in Indian Rupees) : ");
		scanf("%f", SUM_EmployeeRecord[SUM_i].S_salary);


		printf("\n\n");
		printf("Enter Employee's marital status (Y/y for Yes, N/n for No) : ");
		SUM_EmployeeRecord[SUM_i].S_marital_status = getch();
		printf("%c", SUM_EmployeeRecord[SUM_i].S_marital_status);
		SUM_EmployeeRecord[SUM_i].S_marital_status = toupper(SUM_EmployeeRecord[SUM_i].S_marital_status);
	}
	// To Display the Employee Details i.e. the values of 'struct SUM_EmployeeRecord[]'

	printf("\n\n");
	printf("********** Displaying Employee Recorsd **********\n\n");
	for (SUM_i = 0; SUM_i < NUM_EMPLOYEES; SUM_i++)
	{
		printf("***** Employee Number %d *****\n\n", (SUM_i + 1));
		printf("Name                : %s\n", SUM_EmployeeRecord[SUM_i].S_name);
		printf("Age                 : %d years\n", SUM_EmployeeRecord[SUM_i].S_age);
		
		if (SUM_EmployeeRecord[SUM_i].S_sex == 'F')
		{
			printf("Sex                 : Female\n");
		}
		else if (SUM_EmployeeRecord[SUM_i].S_sex == 'M')
		{
			printf("Sex                 : Male\n");
		}
		else
		{
			printf("Sex                 : Invalid Data Entered\n");
		}

		printf("Salary              : Rs. %lf\n", SUM_EmployeeRecord[SUM_i].S_salary);
		if (SUM_EmployeeRecord[SUM_i].S_marital_status == 'Y')
		{
			printf("Marital Status      : Married\n");
		}
		else if (SUM_EmployeeRecord[SUM_i].S_marital_status == 'N')
		{
			printf("Marital Status      : Unmarried\n");
		}
		else
		{
			printf("Marital Status      : Invalid Data Entered\n");
		}
		printf("\n\n");

	}
	return(0);
}
// Simple rudimentry implementation of gets_s()
// Implemented due to different behaviour of gets_s() / fgetf() / fscanf() on different platforms
//Backspace/Character Deletion and Arrowkey cursor movement not implemented

void MyGetString(char SUM_str[], int SUM_str_size)
{
	// Variable Declarations
	int SUM_i;
	char SUM_ch = '\0';
	// Code
	SUM_i = 0;
	do 
	{
		SUM_ch = getch();
		SUM_str[SUM_i] = SUM_ch;
		printf("%c", SUM_str[SUM_i]);
		SUM_i++;
	} while ((SUM_ch != '\r') && (SUM_i < SUM_str_size));
	if (SUM_i == SUM_str_size)
	{
		SUM_str[SUM_i - 1] = '\0';
	}
	else
	{
		SUM_str[SUM_i] = '\0';
	}
}

