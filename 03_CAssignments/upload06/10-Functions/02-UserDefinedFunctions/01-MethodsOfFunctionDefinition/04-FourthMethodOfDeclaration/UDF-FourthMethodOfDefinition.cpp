#include <stdio.h> //'<stdio.h>' contains declaration of 'printf()'

//Entry Point Function => main() => VALID RETURN TYPE (int) and 3 PARAMETERS (int, argc, char *argv[], char *envp[])

int main(int argc, char *argv[], char *envp[])
{
	// Function Prototype / Declaration / Signature
	int MyAddition(int, int);

	// Variable Declarations : LOCAL VARIABLES to main()
	int SUMa, SUMb, SUMresult;

	printf("\n\n");
	printf("Enter Integer Value for 'A' : ");
	scanf("%d", &SUMa);

	printf("\n\n");
	printf("Enter Integer Value for 'B' : ");
	scanf("%d", &SUMb);

	SUMresult = MyAddition(SUMa, SUMb); //FUNCTION CALL
	printf("\n\n");
	printf("Sum of %d and %d = %d\n\n", SUMa, SUMb, SUMresult);

	return(0);
}

// UDF : METHOD OF DEFINITION 4
// *** VALID (int) VALUE VALID PARAMETERS (int, int) ***

int MyAddition(int SUMa, int SUMb) //Function DEFINITION
{
	// Variable Declarations : LOCAL VARIABLES to MyAddition()
	int S_sum;

	//Code
	S_sum = SUMa + SUMb;
	return(S_sum);
	
}



