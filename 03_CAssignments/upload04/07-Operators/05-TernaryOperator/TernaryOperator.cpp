#include <stdio.h>

int main(void)
{
	//variable declarations 
	int SUMa, SUMb;
	int SUMp, SUMq;
	char ch_result_01, ch_result_02;
	int i_result_01, i_result_02;

	//code
	printf("\n\n");

	SUMa = 8;
	SUMb = 5;
	ch_result_01 = (SUMa > SUMb) ? 'A' : 'B';
	i_result_01 = (SUMa > SUMb) ? SUMa : SUMb;
	printf("Ternary Operator Answer 1 ------ %c and %d.\n\n", ch_result_01, i_result_01);

	SUMp = 20;
	SUMq = 20;
	ch_result_02 = (SUMp != SUMq) ? 'P' : 'Q';
	i_result_02 = (SUMp != SUMq) ? SUMp : SUMq;
	printf("Ternary Operator Answer 2 ------ %c and %d.\n\n", ch_result_02, i_result_02);

	printf("\n\n");
	return(0);
	
}


