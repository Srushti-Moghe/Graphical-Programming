#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  
#include <conio.h>
#include <string.h>

#define NAME_LENGTH 100
#define MARITAL_STATUS 10

// Define struct
struct SUM_Employee
{
	char S_name[NAME_LENGTH];
	int S_age;
	char S_sex;
	float S_salary;
	char S_MaritalStatus;
};

int main(void)
{
	// Function Prototype
	void MyGetString(char[], int);

	// variable Declarations
	struct SUM_Employee *ptr_SUM_EmployeeRecord = NULL;
	int SUM_num_employees;
	int SUM_i;
	
	// Code
	printf("\n\n");
	printf("Enter number of employees whose detains you want to record : ");
	scanf("%d", &SUM_num_employees);

	printf("\n\n");
	ptr_SUM_EmployeeRecord = (struct SUM_Employee*)malloc(sizeof(struct SUM_Employee) * SUM_num_employees);

	if (ptr_SUM_EmployeeRecord == NULL)
	{
		printf("Failed to Allocate the memory for %d Employees !!! Exitting Now...\n\n", SUM_num_employees);
		exit(0);
	}
	else
	{
		printf("Memory allocation to %d Employees done Successfully !!!\n\n", SUM_num_employees);
	}

	// User Input Initialization of Array of 'struct Employee'
	for (SUM_i = 0; SUM_i < SUM_num_employees; SUM_i++)
	{
		printf("\n\n\n\n");
		printf("***Data Entry for Employee Number %d***\n", (SUM_i + 1));

		printf("\n\nEnter Employee Name : ");
		MyGetString(ptr_SUM_EmployeeRecord[SUM_i].S_name, NAME_LENGTH);

		printf("\n\nEnter Employee's Sex (M/m for Male, F/f for Female) : ");
		ptr_SUM_EmployeeRecord[SUM_i].S_sex = getch();
		printf("%c", ptr_SUM_EmployeeRecord[SUM_i].S_sex);
		ptr_SUM_EmployeeRecord[SUM_i].S_sex = toupper(ptr_SUM_EmployeeRecord[SUM_i].S_sex);

		printf("\n\nEnter Employee's Salary (in INR) : ");
		scanf("%f", &ptr_SUM_EmployeeRecord[SUM_i].S_salary);

		printf("\n\nEnter Employee's Marital Status (Y/y for Yes, N/n for No) : ");
		ptr_SUM_EmployeeRecord[SUM_i].S_MaritalStatus = getch();
		printf("%c", ptr_SUM_EmployeeRecord[SUM_i].S_MaritalStatus);
		ptr_SUM_EmployeeRecord[SUM_i].S_MaritalStatus = toupper(ptr_SUM_EmployeeRecord[SUM_i].S_MaritalStatus);
	}

	// Display
	printf("\n\n\n\n");
	printf("***** Displaying Employee Records *****");
	for (SUM_i = 0; SUM_i < SUM_num_employees; SUM_i++)
	{
		printf("*** Employee NUmber %d ***\n\n", (SUM_i + 1));
		printf("Name	: %s\n", ptr_SUM_EmployeeRecord[SUM_i].S_name);
		printf("Age		: %d Years\n", ptr_SUM_EmployeeRecord[SUM_i].S_age);

		if (ptr_SUM_EmployeeRecord[SUM_i].S_sex == 'M')
		{
			printf("Sex		: Male\n");
		}
		else if (ptr_SUM_EmployeeRecord[SUM_i].S_sex == 'F')
		{
			printf("Sex		: Female\n");
		}
		else
		{
			printf("Sex		: Invalid Data\n");
		}

		printf("Salary		: Rs. %f\n", ptr_SUM_EmployeeRecord[SUM_i].S_salary);

		if (ptr_SUM_EmployeeRecord[SUM_i].S_MaritalStatus == 'Y')
		{
			printf("Marital Status		: Married\n");
		}
		else if (ptr_SUM_EmployeeRecord[SUM_i].S_MaritalStatus == 'N')
		{
			printf("Marital Status		: Unmarried\n");
		}
		else
		{
			printf("Marital Status		: Invalid Data\n");
		}
		printf("\n\n");
	}

	if (ptr_SUM_EmployeeRecord)
	{
		free(ptr_SUM_EmployeeRecord);
		ptr_SUM_EmployeeRecord = NULL;
		printf("Memory allocated to %d Employees has been Successfully Freed !!!\n\n", SUM_num_employees);
	}

	return(0);
}
// Simple rudimentary implementation of gets_s()
// Implemented dur to the differentr behaviour of gets_s() / fgets_s() / fscanf() on various platforms
// Backspace / Character deletion and arrow key cursor movement not implemented

void MyGetString(char str[], int str_size)
{
	// Variable declarations
	int S_i;
	char S_ch = '\0';

	// COde
	S_i = 0;
	do
	{
		S_ch = getch();
		str[S_i] = S_ch;
		printf("%c", str[S_i]);
		S_i++;
	} while ((S_ch != '\r') && (S_i < str_size));

	if (S_i == str_size)
	{
		str[S_i - 1] = '\0';
	}
	else
	{
		str[S_i] = '\0';
	}
	return;
}







