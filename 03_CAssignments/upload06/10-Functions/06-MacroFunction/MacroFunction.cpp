#include <stdio.h>

#define MAX_NUMBER(Sa, Sb) ((Sa > Sb) ? Sa : Sb)

int main(int argc, char* argv[], char* envp[])
{
	//Variable declarations
	int SiNum_01;
	int SiNum_02;
	int SiResult;

	float SfNum_01;
	float SfNum_02;
	float SfResult;

	//Code
	//*** Comparing Integer Values***

	printf("\n\n");
	printf("Enter an Integer Number : \n\n");
	scanf("%d", &SiNum_01);

	printf("\n\n");
	printf("Enter another Integer Number : \n\n");
	scanf("%d", &SiNum_02);

	SiResult = MAX_NUMBER(SiNum_01, SiNum_02);
	printf("\n\n");
	printf("Result of Macro Function MAX_NUMBER() = %d\n\n", SiResult);

	printf("\n\n");

	//***Comparing Floating Point Values***

	printf("\n\n");
	printf("Enter a Floating Point Number : \n\n");
	scanf("%f", &SfNum_01);

	printf("\n\n");
	printf("Enter another FLoating Point Number : \n\n");
	scanf("%f", &SfNum_02);

	SfResult = MAX_NUMBER(SfNum_01, SfNum_02);
	printf("\n\n");
	printf("Result of Macro Function MAX_NUMBER() = %f\n\n", SfResult);

	printf("\n\n");

	return(0);

}








