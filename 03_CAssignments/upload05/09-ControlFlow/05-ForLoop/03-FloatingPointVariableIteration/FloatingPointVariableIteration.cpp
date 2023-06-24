#include <stdio.h>
int main(void)
{
	//variable declarations
	float SUMf;
	float f_num = 1.9f; 

	//code
	printf("\n\n");
	printf("Printing numbers %f to %f : \n\n", f_num, (f_num * 100.0f));

	for (SUMf = f_num; SUMf <= (f_num * 10.0f); SUMf = SUMf + f_num)
	{
		printf("\t %f \n", SUMf);
	}

	printf("\n\n");

	return(0);

}


