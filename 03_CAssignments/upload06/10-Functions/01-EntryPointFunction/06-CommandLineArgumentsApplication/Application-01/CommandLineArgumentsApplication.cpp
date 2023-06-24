#include <stdio.h> //'<stdio.h>' contains declaration of 'printf()'
#include <ctype.h> //'<ctype.h>' contains declaration of 'atoi()'
#include <stdlib.h> // '<stdlib.h>' contains declaration of 'exit()'

int main(int argc, char *argv[], char *envp[])
{
	// Variable Declarations
	int SUMi;
	int SUMnum;
	int S_sum;
	
	//Code
	if (argc == 1)
	{
		printf("\n\n");
		printf("No numbers are given for addition !!! Exiting Now ...\n\n");
		printf("Usage : CommandLineArgumentsApplication <first number> <second number> ... \n\n");

		exit(0);
	}

	//This program adds all the COMMAND LINE ARGUMENTS given in the INTEGER FORM only and gives OUTPUT as their SUM

	//use of 'atoi()' : all COMMAND LINE ARGUMENTSS of types OTHER than 'int' are IGNORED

	printf("\n\n");
	printf("Sum of all the Integer Command Line Arguments is : \n\n");

	for (SUMi = 1; SUMi < argc; SUMi++)
		// Loop starts from i= 1 because, i=o will result in'argv[i]='argv[0]'
		// This 'argv[0]' is the name of the program itself i.e. 'CommandLineArgumentsApplication.exe'
	{
		SUMnum = atoi(argv[SUMi]);
		S_sum = S_sum + SUMnum;
	}
	printf("SUM = %d\n\n", S_sum);
	
	return(0);
}



