#include <stdio.h> //'<stdio.h>' contains declaration of 'printf()'

//*** USER DEFINED FUNCTIONS : METHOD OF CALLING FUNCTIN 1 ***

//Calling Function in main() DIRECTLY

//Entry Point Function => main() => VALID RETURN TYPE (int) and 3 PARAMETERS (int, argc, char *argv[], char *envp[])

int main(int argc, char* argv[], char* envp[])
{
	// Function Prototypes or Declarations 
	void MyAddition(void);
	int MySubtraction(void);
	void MyMultiplication(int, int);
	int MyDivision(int, int);

	// Variable Declarations : LOCAL VARIABLES to main()
	int SUMresult_subtraction;
	int SUMa_multiplication, SUMb_multiplication;
	int SUMa_division, SUMb_division, SUMresult_division;

	//Code

	//ADDITION
	MyAddition(); //Function CALL

	//SUBTRACTION
	SUMresult_subtraction = MySubtraction(); //Function CALL
	printf("\n\n");
	printf("Subtraction yeilds result = %d\n", SUMresult_subtraction);

	//MULTIPLICATION
	printf("\n\n");
	printf("ENter Integer value 'A' for MULTIPLICATION  : ");
	scanf("%d", &SUMa_multiplication);

	printf("\n\n");
	printf("Enter Integer Value 'B' for MULTIPLICATION : ");
	scanf("%d", &SUMb_multiplication);

	MyMultiplication(SUMa_multiplication, SUMb_multiplication); // Function CALL

	//DIVISION
	printf("\n\n");
	printf("ENter Integer value 'A' for DIVISION  : ");
	scanf("%d", &SUMa_division);

	printf("\n\n");
	printf("Enter Integer Value 'B' for DIVISION : ");
	scanf("%d", &SUMb_division);

	SUMresult_division = MyDivision(SUMa_division, SUMb_division); //Function CALL
	printf("\n\n");
	printf("Division of %d and %d gives = %d (QUOTIENT) \n", SUMa_division, SUMb_division, SUMresult_division);
	printf("\n\n");

	return(0);
}
	// Function Definition of MyAddition()
void MyAddition(void) // Function Definition
{
	// Variable Declarations : LOCAL VARIABLES to MyAddition()
	int SUMa, SUMb, S_sum;

	//Code
	printf("\n\n");
	printf("ENter Integer value 'A' for ADDITION  : ");
	scanf("%d", &SUMa);

	printf("\n\n");
	printf("Enter Integer Value 'B' for ADDITION : ");
	scanf("%d", &SUMb);

	S_sum = SUMa + SUMb;

	printf("\n\n");
	printf("SUM of %d and %d = %d\n\n", SUMa, SUMb, S_sum);
}

// Function Definition of MySubtraction()
int MySubtraction(void) // Function Definition
{
	// Variable Declarations : LOCAL VARIABLES to MySubtraction()
	int SUMa, SUMb, S_subtraction;

	//Code
	printf("\n\n");
	printf("ENter Integer value 'A' for SUBTRACTION  : ");
	scanf("%d", &SUMa);

	printf("\n\n");
	printf("Enter Integer Value 'B' for SUBTRACTION : ");
	scanf("%d", &SUMb);

	S_subtraction = SUMa - SUMb;

	return(S_subtraction);
}

// Function Definition of MyMultiplication()
void MyMultiplication(int SUMa_multiplication, int SUMb_multiplication) // Function Definition
{
	// Variable Declarations : LOCAL VARIABLES to MySubtraction()
	int S_multiplication;

	//Code
	S_multiplication = SUMa_multiplication * SUMb_multiplication;

	printf("\n\n");
	printf("Multiplication of %d and %d = %d\n\n", SUMa_multiplication, SUMb_multiplication, S_multiplication);
	
}

// Function Definition of MyDivision()
int MyDivision(int SUMa_division, int SUMb_division) // Function Definition
{
	// Variable Declarations : LOCAL VARIABLES to MyDivision()
	int S_DivQuotient;

	//Code
	if (SUMa_division > SUMb_division)
	{
		S_DivQuotient = SUMa_division / SUMb_division;
	}
	else
	{
		S_DivQuotient = SUMb_division / SUMa_division;
	}
	return(S_DivQuotient);
}




