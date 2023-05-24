#include <stdio.h>
int main(void)
{
	//code
	printf("\n\n");
	printf("Going On to Next Line.....Using \\n Esacpe Sequence\n\n");
	printf("Demonstrating \t Horizontal \t Tab \t Using \t \\t Escape Sequence !!!\n\n");
	printf("\"This Is A Double Quoted Output \" Done Using \\\' \\\' Escape Sequence\n\n");
	printf("\'This Is A Single Quoted Output \" Done Using \\\' \\\' Escape Sequence\n\n");
	printf("BACKSPACE Turned To Backspace\b Using Escape Sequence \\b\n\n");

	printf("\r Demonstrating Carriage Return Using \\r Esacpe Sequence\n");
	printf("Demonstrating \r Carriage Return Using \\r Esacpe Sequence\n");
	printf("Demonstrating Carriage \r Return Using \\r Esacpe Sequence\n\n");

	printf("Demonstrating \x41 Using \\xhh Escape Sequence\n\n"); //0x41 Is The hexadecimal Code for Letter 'A'. 'xxh' Is the Place Holder for 'x' Followed by 2 digits (hh), altogether forming a hexadecimal number.
	printf("Demonstrating \102 Using \\oo Escape Sequence\n\n"); //102 Is the Octal Code for letter 'B'. 'ooo' Is the place holder for 3 digits forming an Octal Number.
	return(0);
}



