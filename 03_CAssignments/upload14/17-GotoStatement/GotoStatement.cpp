#include <stdio.h>
#include <string.h>   
#include <conio.h>
#include <ctype.h>		// toupper()

int main(void)
{
	// Variable Declarations
	char SUM_ch;
	char SUM_ch_i;
	unsigned int SUM_ascii_ch = 0;

	// Code
	printf("\n\n");
	printf("Enter teh first character of first name : ");
	SUM_ch = getch();
	SUM_ch = toupper(SUM_ch);

	for (SUM_ch_i = 'A'; SUM_ch_i <= 'Z'; SUM_ch_i++)
	{
		if (SUM_ch == SUM_ch_i)
		{
			SUM_ascii_ch = (unsigned int)SUM_ch;
				goto result_output; // program flow directly jumps to label "result output"
		}
	}
	printf("\n\n Goto statement not executed, so printing \"Hello World !!!\"\n");    // will be ommitted if "goto" statement executed
result_output: // label itself does not alter flow of program. Following code is executed regardless of whether goto statement is executed or not

	printf("\n\n");
	if (SUM_ascii_ch == 0)
	{
		printf("You must have a strange name! Could not find the character '%c' in the entire english alphabet!\n", SUM_ch);
	}
	else
	{
		printf("Character '%c' found. It has ASCII value %u.\n", SUM_ch, SUM_ascii_ch);
	}
	printf("\n\n");

	return(0);
}




