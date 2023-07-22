#include <stdio.h>

int main(void)
{
	int AddIntegers(int, int);
	int SubtractIntegers(int, int);
	float AddFloats(float, float);

	// Variable Declarations
	typedef int (*AddIntsFnPtr)(int, int);
	AddIntsFnPtr ptrAddTwoIntegers = NULL;
	AddIntsFnPtr ptrFunc = NULL;

	typedef float (*AddFloatsFnPtr)(float, float);
	AddFloatsFnPtr ptrAddTwoFloats = NULL;

	int iAnswer = 0;
	float fAnswer = 0.0f;

	// Code
	ptrAddTwoIntegers = AddIntegers;
	iAnswer = ptrAddTwoIntegers(9, 30);
	printf("\n\n");
	printf("Sum of Integers = %d\n\n", iAnswer);

	ptrFunc = SubtractIntegers;
	iAnswer = ptrFunc(9, 30);
	printf("\n\n");
	printf("Subtraction of Integers = %d\n\n", iAnswer);

	ptrAddTwoFloats = AddFloats;
	fAnswer = ptrAddTwoFloats(13.2345f, 67.30f);
	printf("\n\n");
	printf("Sum of Floating-Point Numbers = %f\n\n", fAnswer);

	return(0);
}

// Function Definitions

int AddIntegers(int a, int b)
{
	// Variable declarations 
	int c;
	// Code
	c = a + b;
	return(c);
}

int SubtractIntegers(int a, int b)
{
	// Variable declarations 
	int c;
	// Code
	if (a > b)
	{
		c = a - b;
	}
	else
	{
		c = b - a;
	}
	return(c);
}

float AddFloats(float f1, float f2)
{
	// Variable declarations 
	int f3;
	// Code
	f3 = f1 + f2;
	return(f3);
}


