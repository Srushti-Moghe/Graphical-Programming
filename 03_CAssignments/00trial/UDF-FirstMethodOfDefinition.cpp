#include <stdio.h> //'<stdio.h>' contains declaration of 'printf()'

//Entry Point Function => main() => VALID RETURN TYPE (int) and 3 PARAMETERS (int, argc, char *argv[], char *envp[])

int main(int argc, char* argv[], char* envp[])
{
	// Function Prototype / Declaration / Signature
	void MyAddition(void);
	// Code 
	MyAddition(); //Function CALL
	return(0);
}
// UDF : METHOD OF DEFINITION 1
// *** NO RETURN VALUE NO PARAMETERS ***

void MyAddition(void) //Function DEFINITION
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

	printf("\n\n");
	printf("SUM of %d and %d = %d\n\n", SUMa, SUMb, S_sum);

}



