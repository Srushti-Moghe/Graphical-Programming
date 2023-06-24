#include <stdio.h> //'<stdio.h>' contains declaration of 'printf()'

//*** USER DEFINED FUNCTIONS : METHOD OF CALLING FUNCTIN 2 ***

//Calling only TWO Functions DIRECTLY in Main(), in main() DIRECTLY

//Rest of the Functions trace their call INDIRECTLY to Main()

int main(int argc, char* argv[], char* envp[])
{
	// Function Prototypes or Declarations 
	void Function_Country(void);

	//Code

	Function_Country(); 

	return(0);
}

void Function_Country(void) //Function DEFINITION
{
	//Function Declarations
	void Function_OfAMC(void);

	//Code

	Function_OfAMC();
	printf("\n\n");
	printf("I Live in India");
	printf("\n\n");
}
	
void Function_OfAMC(void) // Function DEFINITION
{
	//Function Declarations
	void Function_Surname(void);

	//Code

	Function_Surname();
	printf("\n\n");
	printf("Of ASTROMEDICOMP");	
}

void Function_Surname(void) // Function DEFINITION
{
	//Function Declarations
	void Function_MiddleName(void);

	//Code

	Function_MiddleName();
	printf("\n\n");
	printf("Moghe");
}

void Function_MiddleName(void) // Function DEFINITION
{
	//Function Declarations
	void Function_FirstName(void);

	//Code

	Function_FirstName();
	printf("\n\n");
	printf("Umesh");
}

void Function_FirstName(void) // Function DEFINITION
{
	//Function Declarations
	void Function_Is(void);

	//Code

	Function_Is();
	printf("\n\n");
	printf("Srushti");
}

void Function_Is(void) // Function DEFINITION
{
	//Function Declarations
	void Function_Name(void);

	//Code

	Function_Name();
	printf("\n\n");
	printf("Is");
}

void Function_Name(void) // Function DEFINITION
{
	//Function Declarations
	void Function_My(void);

	//Code

	Function_My();
	printf("\n\n");
	printf("Name");
}

// *** UDF DEFINITIONS ***
void Function_My(void) // Function DEFINITION
{
	//Code

	printf("\n\n");
	printf("My");
}

