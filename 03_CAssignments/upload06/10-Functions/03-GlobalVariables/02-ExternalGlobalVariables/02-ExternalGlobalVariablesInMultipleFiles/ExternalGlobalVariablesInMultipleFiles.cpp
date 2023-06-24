#include <stdio.h> 

//*** GLOBAL SCOPE ***

int global_count = 0;

int main(void)
{
	// Function Prototypes 
	void change_count_one(void); //Function Defines in File_01.c
	void change_count_two(void); //Function Defines in File_02.c
	
	//Code
	printf("\n");
	
	change_count_one();  //Function Defines in File_01.c
	change_count_two();  //Function Defines in File_02.c
	
	printf("\n");

	return(0);
}

//*** GLOBAL SCOPE ***

void change_count(void)
{
	//Code
	global_count = global_count + 1;
	printf("Global Count = %d\n", global_count);
}


