#include <stdio.h> //'<stdio.h>' contains declaration of 'printf()'

//Entry Point Function => main() => VALID RETURN TYPE (int) and 3 PARAMETERS (int, argc, char *argv[], char *envp[])

int main(int argc, char* argv[], char* envp[])
{
	// Function Prototype / Declaration / Signature
	int MyAddition(void);

	// Variable Declarations : LOCAL VARIABLES to main()
	int SUMresult;

	// Code 
	SUMresult = MyAddition(); //Function CALL

	printf("\n\n");
	printf("SUM = %d\n\n", SUMresult);
	return(0);
}

// UDF : METHOD OF DEFINITION 2
// *** VALID (int) RETURN VALUE NO PARAMETERS ***

int MyAddition(void) //Function DEFINITION
{
	// Variable Declarations : LOCAL VARIABLES to MyAddition()
	int SUMa, SUMb, S_sum;

	//Code
	printf("\n\n");
	printf("Enter Integer VAlue for 'A' : ");
	scanf("%d", &SUMa);

	printf("\n\n");
	printf("Enter Integer VAlue for 'B' : ");
	scanf("%d", &SUMb);

	S_sum = SUMa + SUMb;

	return(S_sum);
}



