#include <stdio.h>
#include <conio.h>

// Defining struct
struct SUM_MyData
{
	int SUM_i;
	float SUM_f;
	double SUM_d;
	char SUM_ch;
}; 

int main(void)
{
	// Variable Declarations for single struct variable
	struct SUM_MyData SUM_Data;

	// Code
	// User input values for data members of 'struct SUM_Data'
	printf("\n\n");

	printf("Enter Integer value for Data Member 'SUM_i' of 'struct SUM_Data' : \n ");
	scanf("%d", &SUM_Data.SUM_i);

	printf("Enter Floating-Point value for Data Member 'SUM_f' of 'struct SUM_Data' : \n ");
	scanf("%f", &SUM_Data.SUM_f);

	printf("Enter Double value for Data Member 'SUM_d' of 'struct SUM_Data' : \n ");
	scanf("%lf", &SUM_Data.SUM_d);

	printf("Enter Character value for Data Member 'SUM_ch' of 'struct SUM_Data' : \n ");
	SUM_Data.SUM_ch = getch();

	// Displaying the values of the members of 'struct SUM_MyData'
	printf("Data Members of 'struct SUM_MyData' are : \n\n");
	
	printf("The Integer member 'SUM_i' of 'struct SUM_MyData' is          = %d\n", SUM_Data.SUM_i);
	printf("The Floating-Point member 'SUM_f' of 'struct SUM_MyData' is   = %f\n", SUM_Data.SUM_f);
	printf("The Double member 'SUM_d' of 'struct SUM_MyData' is           = %lf\n", SUM_Data.SUM_d);
	printf("The Character member 'SUM_ch' of 'struct SUM_MyData' is       = %c\n", SUM_Data.SUM_ch);
		
	return(0);
}




