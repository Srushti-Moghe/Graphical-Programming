#include <stdio.h>
#include <conio.h>

int main(void)
{
	//Variable Declarations 
	int SUMi;
	char SUMch;

	//Code
	printf("\n\n");

	printf("Printing Even Numbers from 1 to 100 for every user input. Exiting the Loop when Users enter Character - 'Q' or 'q' :  \n\n");

	printf("Enter character 'Q' or 'q' to exit the Loop : \n\n");


	for (SUMi = 1; SUMi <= 100; SUMi++)
	{
		printf("\t%d\n", SUMi);
		SUMch = getch();
		if (SUMch == 'Q' || SUMch == 'q')
		{
			break;
		}
	}
	printf("\n\n");
	printf("EXITING LOOP");
	printf("\n\n");
		
	return(0);
}

