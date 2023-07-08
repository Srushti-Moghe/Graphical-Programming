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
	
	// 'struct SUM_struct'
	printf("\n\n");
	printf("Members of SUM_struct are : \n\n");

	SUM_struct.SUM_i = 30;
	SUM_struct.SUM_f = 23.3f;
	SUM_struct.SUM_d = 44.556677;
	SUM_struct.SUM_c = 'R';

	printf("The integer 'i' member of SUM_struct.SUM_i      = %d\n", SUM_struct.SUM_i);
	printf("The float-point 'f' member of SUM_struct.SUM_f  = %f\n", SUM_struct.SUM_f);
	printf("The double 'd' member of SUM_struct.SUM_d       = %lf\n", SUM_struct.SUM_d);
	printf("The character 'c' member of SUM_struct.SUM_c    = %c\n", SUM_struct.SUM_c);

	printf("\n\n");
	printf("The Addresses of the Members of SUM_struct are : \n\n");
	printf("The Address of integer 'i' member of SUM_struct.SUM_i       = %p\n", &SUM_struct.SUM_i);
	printf("The Address of  float-point 'f' member of SUM_struct.SUM_f  = %p\n", &SUM_struct.SUM_f);
	printf("The Address of  double 'd' member of SUM_struct.SUM_d       = %p\n", &SUM_struct.SUM_d);
	printf("The Address of  character 'c' member of SUM_struct.SUM_c    = %p\n", &SUM_struct.SUM_c);

	printf("\n\n");
	printf("The Address of the struct SUM_struct : %p\n\n", &SUM_struct);

	// 'union SUM_union'
	printf("\n\n");
	printf("Members of SUM_union are : \n\n");

	SUM_union.SUM_i = 100;
	printf("The integer 'i' member of SUM_union.SUM_i      = %d\n", SUM_union.SUM_i);

	SUM_union.SUM_f = 13.3f;
	printf("The float-point 'f' member of SUM_union.SUM_f  = %f\n", SUM_union.SUM_f);

	SUM_union.SUM_d = 11.334455;
	printf("The double 'd' member of SUM_union.SUM_d       = %lf\n", SUM_union.SUM_d);

	SUM_union.SUM_c = 'S';
	printf("The character 'c' member of SUM_union.SUM_c    = %c\n", SUM_union.SUM_c);

	printf("\n\n");
	printf("The Addresses of the Members of SUM_union are : \n\n");

	printf("The Address of integer 'i' member of SUM_union.SUM_i       = %p\n", &SUM_union.SUM_i);
	printf("The Address of  float-point 'f' member of SUM_union.SUM_f  = %p\n", &SUM_union.SUM_f);
	printf("The Address of  double 'd' member of SUM_union.SUM_d       = %p\n", &SUM_union.SUM_d);
	printf("The Address of  character 'c' member of SUM_union.SUM_c    = %p\n", &SUM_union.SUM_c);

	printf("\n\n");
	printf("The Address of the union SUM_union : %p\n\n", &SUM_union);
	

	return(0);
}




