#include <stdio.h> 

//***GLOBAL SCOPE***

int main(void)
{
	//*** LOCAL SCOPE of main() begins***

	//Variable Declarations
	// 'a' is a local variable. It is local to main() only.

	int SUMa = 35;

	//Function Prototypes
	void change_count(void);

	//Code
	printf("\n");
	printf("A = %d\n\n", SUMa);
	
	//local_count is initialized to 0
	//local_count = local_count + 1 = 0 + 1 = 1
	change_count();

	//Since 'local_count' is an ordinary local variable of change_count(), it WILL retain its value from previous call to change_count().
	//So local_count is 1
	// local_count = local_count + 1 = 1 + 1 = 2
	change_count();

	return(0);

	//*** LOCAL SCOPE of main() ends***
}

//***GLOBAL SCOPE

void change_count(void)
{
	//*** LOCAL SCOPE of main() begins***
	
	//Variable Declarations
	//'local_count' is a Local Static Variable. It is local to change_count() only
	//It will retain its value between calls to change_count()
	static int S_local_count = 0;

	//Code
	S_local_count = S_local_count + 1;
	printf("Local Count = %d\n", S_local_count);
	//*** LOCAL SCOPE of change_count() ends***
}

//***GLOBAL SCOPE***



