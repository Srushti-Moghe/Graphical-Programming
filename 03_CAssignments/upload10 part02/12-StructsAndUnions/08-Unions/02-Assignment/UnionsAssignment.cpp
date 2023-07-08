#include <stdio.h>


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
	union SUM_MyUnion SUM_union_01, SUM_union_02;

	// Code
	
	// 'union SUM_union_01'
	printf("\n\n");
	printf("Members of SUM_union_01 are : \n\n");

	SUM_union_01.SUM_i = 30;
	printf("The integer 'i' member of SUM_union_01.SUM_i      = %d\n", SUM_union_01.SUM_i);

	SUM_union_01.SUM_f = 23.3f;
	printf("The float-point 'f' member of SUM_union_01.SUM_f  = %f\n", SUM_union_01.SUM_f);

	SUM_union_01.SUM_d = 44.556677;
	printf("The double 'd' member of SUM_union_01.SUM_d       = %lf\n", SUM_union_01.SUM_d);

	SUM_union_01.SUM_c = 'R';
	printf("The character 'c' member of SUM_union_01.SUM_c    = %c\n", SUM_union_01.SUM_c);

	printf("\n\n");
	printf("The Addresses of the Members of SUM_union_01 are : \n\n");
	printf("The Address of integer 'i' member of SUM_union_01.SUM_i       = %p\n", &SUM_union_01.SUM_i);
	printf("The Address of  float-point 'f' member of SUM_union_01.SUM_f  = %p\n", &SUM_union_01.SUM_f);
	printf("The Address of  double 'd' member of SUM_union_01.SUM_d       = %p\n", &SUM_union_01.SUM_d);
	printf("The Address of  character 'c' member of SUM_union_01.SUM_c    = %p\n", &SUM_union_01.SUM_c);

	printf("\n\n");
	printf("The Address of the union SUM_MyUnion SUM_union_01 : %p\n\n", &SUM_union_01);

	// 'union SUM_union_02'
	printf("\n\n");
	printf("Members of SUM_union_02 are : \n\n");

	SUM_union_02.SUM_i = 100;
	printf("The integer 'i' member of SUM_union_01.SUM_i      = %d\n", SUM_union_02.SUM_i);

	SUM_union_02.SUM_f = 13.3f;
	printf("The float-point 'f' member of SUM_union_01.SUM_f  = %f\n", SUM_union_02.SUM_f);

	SUM_union_02.SUM_d = 11.334455;
	printf("The double 'd' member of SUM_union_02.SUM_d       = %lf\n", SUM_union_02.SUM_d);

	SUM_union_02.SUM_c = 'S';
	printf("The character 'c' member of SUM_union_02.SUM_c    = %c\n", SUM_union_02.SUM_c);

	printf("\n\n");
	printf("The Addresses of the Members of SUM_union_02 are : \n\n");
	printf("The Address of integer 'i' member of SUM_union_02.SUM_i       = %p\n", &SUM_union_02.SUM_i);
	printf("The Address of  float-point 'f' member of SUM_union_02.SUM_f  = %p\n", &SUM_union_02.SUM_f);
	printf("The Address of  double 'd' member of SUM_union_02.SUM_d       = %p\n", &SUM_union_02.SUM_d);
	printf("The Address of  character 'c' member of SUM_union_02.SUM_c    = %p\n", &SUM_union_02.SUM_c);

	printf("\n\n");
	printf("The Address of the union SUM_MyUnion SUM_union_02 : %p\n\n", &SUM_union_02);
	

	return(0);
}




