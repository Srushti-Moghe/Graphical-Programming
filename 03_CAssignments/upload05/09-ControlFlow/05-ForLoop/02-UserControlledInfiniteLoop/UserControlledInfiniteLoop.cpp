#include <stdio.h>
#include <conio.h>
int main(void)
{
	//variable declarations
	char option, SUMch = '\0';

	//code
	printf("\n\n");
	printf("Once the Infinite Loop begins, enter 'Q' or 'q' to quit the infinite loop : \n\n");
	printf("Enter 'Y' or 'y' to initiate the user controlled Infinite Loop : ");
	printf("\n\n");

	option = getch();

	if (option == 'Y' || option == 'y')
	{
		for (;;) //infinite loop
		{
			printf("In Loop \n");
			SUMch = getch();

			if (SUMch == 'Q' || SUMch == 'q')
				break; //User controlled exiting from infinite loop
		}
	}

	printf("\n\n");
	printf("ExisTing User controlled Infinite Loop......");
	printf("\n\n");

	return(0);

}


