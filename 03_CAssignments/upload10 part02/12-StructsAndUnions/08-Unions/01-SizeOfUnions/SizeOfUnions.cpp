#include <stdio.h>
struct SUM_MyStruct
{
	int SUM_i;
	float SUM_f;
	double SUM_d;
	char SUM_c;
 };

union SUM_MyUnion
{
	int SUM_i;
	float SUM_f;
	double SUM_d;
	char SUM_c;
};

int main(void)
{
	// Variable Declarations 
	struct SUM_MyStruct SUM_struct;
	union SUM_MyUnion SUM_union;

	// Code
	
	// Displaying the Addresses of the union 'SUM_MyUnion'
	printf("\n\n");
	printf("The size of 'struct SUM_MyStruct'   = % zu\n", sizeof(SUM_struct));
	printf("The size of 'union SUM_MyUnion'     = % zu\n", sizeof(SUM_union));
	printf("\n\n");

	return(0);
}




