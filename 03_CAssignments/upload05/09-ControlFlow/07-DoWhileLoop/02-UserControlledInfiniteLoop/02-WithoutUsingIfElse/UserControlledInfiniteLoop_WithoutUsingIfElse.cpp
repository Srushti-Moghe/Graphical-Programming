#include <stdio.h>
#include <conio.h>
int main(void)
{
	//variable declarations
	char option, SUMch = '\0';

	//code
	printf("\n\n");

	printf("Once the Infinite Loop begins, enter 'Q' or 'q' to quit the infinite loop : \n\n");

	do
	{
		do
		{
			printf("\n");
			printf("In Loop ...\n");
			SUMch = getch(); //conrol flow waits for character input
		} while (SUMch != 'Q' && SUMch != 'q');

		printf("\n\n");
		printf("ExisTing User controlled Infinite Loop......");

		printf("\n\n");
		printf("Do yu want too begin user controlled infinite loop again?...(Y/y - YES, any other key - NO) : ");
		option = getch();
	} while (option == 'Y' || option == 'y');

	return(0);

}





