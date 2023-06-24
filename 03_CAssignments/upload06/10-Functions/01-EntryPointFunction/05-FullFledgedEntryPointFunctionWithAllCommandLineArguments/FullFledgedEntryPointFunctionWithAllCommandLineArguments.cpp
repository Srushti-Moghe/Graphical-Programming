#include <stdio.h> //'<stdio.h> contains declaration of 'printf()'

//Entry Point Function => main() => VALID RETURN TYPE (int) and 3 - PARAMETERS (int argc, char *argv[], char *envp[])

int main(int argc, char *argv[], char *envp[])
{
	// Variable Declarations
	int SUMi;
	
	//Code

	printf("\n\n");
	printf("HELLO WORLD !!!\n\n"); //LIBRARY FUNCTION

	printf("Number of Command Line Arguments = %d\n\n", argc);

	printf("Command Line Arguments passed to this program are = \n\n");

	for (SUMi = 0; SUMi < argc; SUMi++)
	{
		printf("Command Line Argument Number %d = %s\n", (SUMi + 1),argv[SUMi]);
	}
	printf("\n\n");

	printf("First 20 Environmental Variables Passed to this program are : \n\n");
	for (SUMi = 0; SUMi < 20; SUMi++)
	{
		printf("Environmental Variable Number %d = %s\n", (SUMi + 1), envp[SUMi]);
	}
	printf("\n\n");
	
	return(0);
}



