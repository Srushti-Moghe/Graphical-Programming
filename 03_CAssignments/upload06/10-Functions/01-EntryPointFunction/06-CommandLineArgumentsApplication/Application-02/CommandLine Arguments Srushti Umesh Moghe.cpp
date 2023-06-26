#include <stdio.h> //'<stdio.h>' contains declaration of 'printf()'
#include <stdlib.h> // '<stdlib.h>' contains declaration of 'exit()'

int main(int argc, char *argv[], char *envp[])
{
	// Variable Declarations
	int SUMi;
	
	//Code
	if (argc != 4) //ProgramName + FirstName + MiddleName + Surname = 4 COmmand Line Arguments are Required
	{
		printf("\n\n");
		printf("Invalid Usage !!! Exiting Now ...\n\n");
		printf("Usage : CommandLineArgumentsApplication <first name> <middle name> <surname> \n\n");

		exit(0);
	}

	//This program prints your full name as entered in COMMAND LINE ARGUMENTS
	
	printf("\n\n");
	printf("Your Full Name is :");

	for (SUMi = 1; SUMi < argc; SUMi++)
		// Loop starts from i= 1 because, i=o will result in'argv[i]='argv[0]'
		// This 'argv[0]' is the name of the program itself i.e. 'CommandLineArgumentsApplication.exe'
	{
		printf("%s", argv[SUMi]);
	}
	printf("\n\n");
	
	return(0);
}





