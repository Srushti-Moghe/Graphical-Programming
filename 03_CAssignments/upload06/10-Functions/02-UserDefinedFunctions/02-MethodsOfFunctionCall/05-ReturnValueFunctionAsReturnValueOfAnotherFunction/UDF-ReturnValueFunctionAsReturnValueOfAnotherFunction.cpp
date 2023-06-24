#include <stdio.h> 

int main(int argc, char *argv[], char *envp[])
{
	// Function Prototypes or Declarations 
	int MyAddition(int, int);

	//Variable Declarations
	int SUMr;
	int SUMnum_01, SUMnum_02;
	

	//Code
	SUMnum_01 = 10;
	SUMnum_02 = 20;
	
	printf("\n\n");
	printf("%d + %d = %d\n", SUMnum_01, SUMnum_02, MyAddition(SUMnum_01, SUMnum_02));
	printf("\n\n");

	return(0);
}

//*** Function DEFINITION of MyAddition() ***

int MyAddition(int SUMa, int SUMb) // Function DECLARATION
{
	// Function PROTOTYPE
	int Add(int, int);
	
	//Code

	return(Add(SUMa, SUMb)); //Return value of function Add() as return value of function MyAddition()
}

int Add(int SUMx, int SUMy)
{
	//code

	return(SUMx + SUMy);	
}


