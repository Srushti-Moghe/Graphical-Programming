#include <stdio.h> //'<stdio.h>' contains declaration of 'printf()'

//*** USER DEFINED FUNCTIONS : METHOD OF CALLING FUNCTIN 2 ***

//Calling only TWO Functions DIRECTLY in Main(), in main() DIRECTLY

//Rest of the Functions trace their call INDIRECTLY to Main()

int main(int argc, char* argv[], char* envp[])
{
	// Function Prototypes or Declarations 
	void display_information(void);
	void Function_Country(void);

	//Code

	display_information(); //Function CALL
	Function_Country(); //Function CALL

	return(0);
}

// UDFs DEFINITIONS - 

void display_information(void) //Function DEFINITION
{
	//Function Prototypes
	void Function_My(void);
	void Function_Name(void);
	void Function_Is(void);
	void Function_FirstName(void);
	void Function_MiddleName(void);
	void Function_Surname(void);
	void Function_OfAMC(void);

	//Code

	//Function CALLS
	Function_My();
	Function_Name();
	Function_Is();
    Function_FirstName();
	Function_MiddleName();
	Function_Surname();
	Function_OfAMC();
}
	
void Function_My(void) // Function DEFINITION
{
	//Code
	printf("\n\n");
	printf("My");
}

void Function_Name(void) // Function DEFINITION
{
	//Code
	printf("\n\n");
	printf("Name");
}

void Function_Is(void) // Function DEFINITION
{
	//Code
	printf("\n\n");
	printf("Is");
}

void Function_FirstName(void) // Function DEFINITION
{
	//Code
	printf("\n\n");
	printf("Srushti");
}

void Function_MiddleName(void) // Function DEFINITION
{
	//Code
	printf("\n\n");
	printf("Umesh");
}

void Function_Surname(void) // Function DEFINITION
{
	//Code
	printf("\n\n");
	printf("Moghe");
}

void Function_OfAMC(void) // Function DEFINITION
{
	//Code
	printf("\n\n");
	printf("Of ASTROMEDICOMP");
}

void Function_Country(void) // Function DEFINITION
{
	//Code
	printf("\n\n");
	printf("I live In India.");
	printf("\n\n");
}






