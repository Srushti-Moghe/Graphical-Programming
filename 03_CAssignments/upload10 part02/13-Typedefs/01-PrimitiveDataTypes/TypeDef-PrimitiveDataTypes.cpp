#include <stdio.h>

//Global typedef
typedef int SUM_MY_INT;     //"type" int has been re"def"ined as MY_INT, This means that 'MY_INT can be treated as 'int'

int main(void)
{
	//Function Prototype
	SUM_MY_INT Add(SUM_MY_INT, SUM_MY_INT);

	//typedef 's
	typedef int SUM_MY_INT;   //"type" int has been re"def"ined as MY_INT, This means that 'MY_INT can be treated as 'int'
	typedef float SUM_FLOAT;  //"type" float has been re"def"ined as SUM_FLOAT, This means that 'SUM_FLOAT' can be treated as 'float'
	typedef char SUM_CHAR;    //"type" char has been re"def"ined as SUM_CHAR, This means that 'SUM_CHAR' can be treated as 'char'
	typedef double SUM_DOUBLE;//"type" double has been re"def"ined as SUM_DOUBLE, This means that 'SUM_DOUBLE' can be treated as 'double'
	
	//*****Just like in Win32SDK !!!*****
	typedef unsigned int UINT;
	typedef UINT HANDLE;
	typedef HANDLE HWND;
	typedef HANDLE HINSTANCE;

	//Variable Declarations
	SUM_MY_INT S_a = 10, S_i;
	SUM_MY_INT SiArray[] = { 9, 18, 27, 36, 45 ,54, 63, 72, 81,90 };

	SUM_FLOAT f_sum = 30.90f;
	const SUM_FLOAT f_sum_pi = 3.14f;

	SUM_CHAR S_ch = '*';
	SUM_CHAR S_chArray_01[] = "Helloe";
	SUM_CHAR S_chArray_02[][10] = { "RTR", "Batch", "2020-2021" };

	SUM_DOUBLE S_d = 8.00394875;

	UINT S_uint = 34567;
	HANDLE S_handle = 987;
	HWND S_hwnd = 7654;
	HINSTANCE S_hinstance = 876432;

	//Code
	printf("\n\n");
	printf("Type SUM_MY_INT variable a = %d\n", S_a);

	printf("\n\n");
	for (S_i = 0; S_i < (sizeof(SiArray) / sizeof(int)); S_i++)
	{
		printf("Type MY_INT Array variable iArray[%d] = %d\n", S_i, SiArray[S_i]);
	}
	printf("\n\n");

	printf("\n\n");
	printf("Type SUM_FLOAT variable f = %f\n", f_sum);
	printf("Type SUM_FLOAT constant f_pi = %f\n", f_sum_pi);

	printf("\n\n");
	printf("Type SUM_DOUBLE variable d = %lf\n", S_d);

	printf("\n\n");
	printf("Type SUM_CHAR variable c = %c\n", S_ch);

	printf("\n\n");
	printf("Type Character Array variable chArray_01 = %s\n", S_chArray_01);

	printf("\n\n");

	for (S_i = 0; S_i < (sizeof(S_chArray_02) / sizeof(S_chArray_02[0])); S_i++)
	{
		printf("%s \t", S_chArray_02[S_i]);
	}
	printf("\n\n");

	printf("\n\n");
	printf("Type UINT variable S_uint = %u\n\n", S_uint);
	printf("Type HANDLE variable S_handle = %u\n\n", S_handle);
	printf("Type HWND variable S_hwnd = %u\n\n", S_hwnd);
	printf("Type HINSTANCE variable S_hinstance = %u\n\n", S_hinstance);

	SUM_MY_INT S_x = 90;
	SUM_MY_INT S_y = 30;
	SUM_MY_INT S_ret;

	S_ret = Add(S_x, S_y);
	printf("ret = %d\n\n", S_ret);

	return(0);
}
//Function
SUM_MY_INT Add(SUM_MY_INT S_a, SUM_MY_INT S_b)
{
	//Variable Declarations
	SUM_MY_INT S_c;

	//Code
	S_c = S_a + S_b;
	return(S_c);
}



























