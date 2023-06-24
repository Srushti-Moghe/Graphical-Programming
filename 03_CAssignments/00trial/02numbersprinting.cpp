#include <stdio.h>

int main(void)
{
	//variable declarations 
	char ch;

	printf("\n\n");

	while (1)
	{
		ch = getch(ch);
		if (ch == 'Q' || ch == 'q')
			break;
	}

	printf("\n\n");
	printf("INFINITE LOOP IS EXECUTED !!!");		
	printf("\n\n");
	return(0);
}

