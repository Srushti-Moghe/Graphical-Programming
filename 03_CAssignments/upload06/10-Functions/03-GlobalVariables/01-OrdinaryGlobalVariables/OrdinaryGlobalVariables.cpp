#include <stdio.h> 

//*** GLOBAL SCOPE ***

//If not initialised by us; the Global Variables are initialised to their Zero values (w.r.t. their datatypes i.e.: 0 (for int), 0.0 (for float and double), etc. by default
//We shall explicitly initialize our Global Variable with 0 (Good Programming Discipline)

int global_count = 0;

int main(void)
{
	// Function Prototypes 
	void change_count_one(void);
	void change_count_two(void);
	void change_count_three(void);

	//Code
	printf("\n");

	printf("main() : Value of global_count = %d\n", global_count);

	change_count_one();
	change_count_two();
	change_count_three();

	printf("\n");

	return(0);
}

//*** GLOBAL SCOPE ***

void change_count_one(void)
{
	//Code
	global_count = 100;
	printf("change_count_one() : Value of global_count = %d\n", global_count);
}

//*** GLOBAL SCOPE ***

void change_count_two(void)
{
	//Code
	global_count = global_count + 1;
	printf("change_count_two() : Value of global_count = %d\n", global_count);
}

//*** GLOBAL SCOPE ***

void change_count_three(void)
{
	//Code
	global_count = global_count + 10;
	printf("change_count_three() : Value of global_count = %d\n", global_count);
}

//*** GLOBAL SCOPE ***

