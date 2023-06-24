#include <stdio.h> 

int main(int argc, char *argv[], char *envp[])
{
	// Function Prototypes or Declarations 
	int MyAddition(int, int);

	//Variable Declarations
	int SUMr;
	int SUMnum_01, SUMnum_02;
	int SUMnum_03, SUMnum_04;

	//Code
	SUMnum_01 = 10;
	SUMnum_02 = 20;
	SUMnum_03 = 30;
	SUMnum_04 = 40;

	//RETURN VALUE of MyAddition() is sent as PARAMETER to another Call to MyAddition()
	SUMr = MyAddition(MyAddition(SUMnum_01, SUMnum_02), MyAddition(SUMnum_03, SUMnum_04));

	printf("\n\n");
	printf("%d + %d + %d + %d = %d\n", SUMnum_01, SUMnum_02, SUMnum_03, SUMnum_04, SUMr);
	printf("\n\n");

	return(0);
}

//*** Function DEFINITION of MyAddition() ***

int MyAddition(int SUMa, int SUMb) // Function DECLARATION
{
	//Variable Declaration
	int S_SUM;

	//Code

	S_SUM = SUMa + SUMb;
	return(S_SUM);
}


