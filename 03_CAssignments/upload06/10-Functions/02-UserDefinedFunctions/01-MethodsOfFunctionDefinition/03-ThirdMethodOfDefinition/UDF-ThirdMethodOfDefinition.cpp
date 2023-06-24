#include <stdio.h> //'<stdio.h>' contains declaration of 'printf()'

//Entry Point Function => main() => VALID RETURN TYPE (int) and 3 PARAMETERS (int, argc, char *argv[], char *envp[])

int main(int argc, char* argv[], char* envp[])
{
	// Function Prototype / Declaration / Signature
	void MyAddition(int, int);

	// Variable Declarations : LOCAL VARIABLES to main()
	int SUMa, SUMb;

	printf("\n\n");
	printf("Enter Integer VAlue for 'A' : ");
	scanf("%d", &SUMa);

	printf("\n\n");
	printf("Enter Integer VAlue for 'B' : ");
	scanf("%d", &SUMb);

	MyAddition(SUMa, SUMb); //FUNCTION CALL

	return(0);
}

// UDF : METHOD OF DEFINITION 3
// *** NO RETURN VALUE VALID PARAMETERS (int, int) ***

void MyAddition(int SUMa, int SUMb) //Function DEFINITION
{
	// Variable Declarations : LOCAL VARIABLES to MyAddition()
	int S_sum;

	//Code
	S_sum = SUMa + SUMb;
	printf("\n\n");
	printf("Sum of %d and %d = %d\n\n", SUMa, SUMb, S_sum);
}



