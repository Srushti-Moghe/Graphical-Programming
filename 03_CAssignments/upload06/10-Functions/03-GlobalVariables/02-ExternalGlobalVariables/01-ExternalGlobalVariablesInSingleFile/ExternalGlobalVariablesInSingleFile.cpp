#include <stdio.h> 

//***GLOBAL SCOPE***

int main(void)
{
	//Function Prototypes
	void change_count(void);

	//Variable Declarations
	extern int global_count;

	//Code
	printf("\n");
	printf("Value of global_count before change_count() = %d\n", global_count);
	change_count();
	printf("Value of global_count after change_count() = %d\n", global_count);
	printf("\n");

	return(0);
}
//***Global Scope***

//global_count is a global variable

//Since, it is declared after main(), it must be firest re-declarefd in main() as an external global variable by means of the 'extern' keyword and the type of the variable

//Once this is done, it can be used as an ordinary global variable in main as well

int global_count = 0;

void change_count(void)
{
	//Code
	global_count = 5;
	printf("Value of global_count() = %d\n", global_count);
}


