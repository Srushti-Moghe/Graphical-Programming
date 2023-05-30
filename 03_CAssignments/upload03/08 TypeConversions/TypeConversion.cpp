#include <stdio.h>

int main(void)
{
	//Variable declarations //The variables i, j, ch_01, ch_02, a, result_int, f, result_float, i_explicit, i_implicit correspond to SUMi, SUMj, SUMch_01, SUMch_02, SUMa, SUMresult_int, SUMf, SUMresult_float, SUMi_explicit, SUMi_implicit
	int SUMi, SUMj;
	char SUMch_01, SUMch_02;

	int SUMa, SUMresult_int;
	float SUMf, SUMresult_float;

	int SUMi_explicit;
	float SUMf_explicit;

	//code
	printf("\n\n");

	//Interconversion and Implicit Type casting between CHAR and INT
	SUMi = 70;
	SUMch_01 = SUMi;
	printf("I = %d\n", SUMi);
	printf("Character 1 (after SUMch_01 = SUMi) = %c\n\n", SUMch_01);

	SUMch_02 = 'Q';
	SUMj = SUMch_02;
	printf("Character 2 = %c\n", SUMj);
	printf("J (after j = SUMch_02) = %d\n\n", SUMj);

	//IMPLICIT CONVERSION of INT to FLOAT
	SUMa = 5;
	SUMf = 7.8f;
	SUMresult_float = SUMa + SUMf;
	printf("Integer a = %d and floating-point number %f Added gives Floating-point Sum = %f\n\n", SUMa, SUMf, SUMresult_float);

	SUMresult_int = SUMa + SUMf;
	printf("Integer a = %d and floating-point number %f Added gives Integer Sum = %d\n\n", SUMa, SUMf, SUMresult_int);

	//EXPLICIT Type Casting Using CAST OPERATOR
	SUMf_explicit = 30.12434354674635f;
	SUMi_explicit = (int)SUMf_explicit;
	printf("Floating-point number which will be Type Casted Explicitly = %f\n", SUMf_explicit);
	printf("Resultant integer after Explicit Type Casting of %f = %d\n\n", SUMf_explicit, SUMi_explicit);

	return (0);
	}











 