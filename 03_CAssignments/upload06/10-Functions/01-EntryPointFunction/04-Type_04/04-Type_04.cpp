#include <stdio.h> //'<stdio.h> contains declaration of 'printf()'

//Entry Point Function => main() => VALID RETURN TYPE (int) and 2 - PARAMETERS (int argc, char *argv[])

int main(int argc, char *argv[])
{
	// Variable Declarations
	int SUMi;
	
	//Code

	printf("\n\n");
	printf("HELLO WORLD !!!\n\n"); //LIBRARY FUNCTION
	printf("Number of Command Line Arguments = %d\n\n", argc);

	printf("Command Line Arguments passed to this program are = %d\n\n");
	for (SUMi = 0; SUMi < argc; SUMi++)
	{
		printf("Command Line Argument Number %d = %s\n", (SUMi + 1),argv[SUMi]);
	}
	printf("\n\n");
	
	return(0);
}



