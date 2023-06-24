#include <stdio.h>
int main(void)
{
	//variable declarations
	float SUMf;
	float f_num = 5.6f; 

	//code
	printf("\n\n");

	printf("Printing numbers %f to %f : \n\n", f_num, (f_num * 10.0f));

	SUMf = f_num;
	do 
	{
		printf("\t %f \n", SUMf);
		SUMf = SUMf + f_num;
	} while (SUMf <= (f_num * 10.0f));

	printf("\n\n");

	return(0);

}






