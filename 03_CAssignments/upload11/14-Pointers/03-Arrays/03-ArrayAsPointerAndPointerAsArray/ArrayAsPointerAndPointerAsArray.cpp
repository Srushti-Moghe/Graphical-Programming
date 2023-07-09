#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int S_iArray[] = { 10, 20, 30, 40, 50, 60 ,70, 80, 90, 100 };  // Integer Array
	int *ptr_S_iArray = NULL;  // Integer Pointer
	
	// Code 

	// Using Array Name as an Pointer : value of xth element of iArray :
	// *(iArray + x) and address of xth element of iArray : (iArray + x)

	printf("\n\n");
	printf("Using Array Name as an Pointer : value of xth element of iArray : *(iArray + x) and address of xth element of iArray : (iArray + x)\n\n");
	printf("Integer Array Elements and the Addresses they occupy are as follows : \n\n");

	printf("iArraay + 0 = %d \t at address (iArray + 0) : %p\n", *(S_iArray + 0), (S_iArray + 0));
	printf("iArraay + 1 = %d \t at address (iArray + 1) : %p\n", *(S_iArray + 1), (S_iArray + 1));
	printf("iArraay + 2 = %d \t at address (iArray + 2) : %p\n", *(S_iArray + 2), (S_iArray + 2));
	printf("iArraay + 3 = %d \t at address (iArray + 3) : %p\n", *(S_iArray + 3), (S_iArray + 3));
	printf("iArraay + 4 = %d \t at address (iArray + 4) : %p\n", *(S_iArray + 4), (S_iArray + 4));
	printf("iArraay + 5 = %d \t at address (iArray + 5) : %p\n", *(S_iArray + 5), (S_iArray + 5));
	printf("iArraay + 6 = %d \t at address (iArray + 6) : %p\n", *(S_iArray + 6), (S_iArray + 6));
	printf("iArraay + 7 = %d \t at address (iArray + 7) : %p\n", *(S_iArray + 7), (S_iArray + 7));
	printf("iArraay + 8 = %d \t at address (iArray + 8) : %p\n", *(S_iArray + 8), (S_iArray + 8));
	printf("iArraay + 9 = %d \t at address (iArray + 9) : %p\n", *(S_iArray + 9), (S_iArray + 9));
	
	// Assigning the base address of integer array 'iArray[]' to integer Pointer
	// Name of an Array == its Base Address
	ptr_S_iArray = S_iArray; // Equivalent to >> ptr_S_iArray = &S_iArray[0]

	// Using Pointer Name as Array Name : value of xth element of iArray :
	// ptr_iArray[x] and address of xth element of iArray : &ptr_iArray[x]

	printf("\n\n");
	printf("Using Pointer Name as Array Name : value of xth element of iArray :  ptr_iArray[x] and address of xth element of iArray : &ptr_iArray[x]\n\n");
	printf("Integer Array Elements and the Addresses they occupy are as follows : \n\n");

	printf("ptr_iArray[0] = %d \t\t at address &ptr_iArray[0] : %p\n", ptr_S_iArray[0], &ptr_S_iArray[0]);
	printf("ptr_iArray[1] = %d \t\t at address &ptr_iArray[1] : %p\n", ptr_S_iArray[1], &ptr_S_iArray[1]);
	printf("ptr_iArray[2] = %d \t\t at address &ptr_iArray[2] : %p\n", ptr_S_iArray[2], &ptr_S_iArray[2]);
	printf("ptr_iArray[3] = %d \t\t at address &ptr_iArray[3] : %p\n", ptr_S_iArray[3], &ptr_S_iArray[3]);
	printf("ptr_iArray[4] = %d \t\t at address &ptr_iArray[4] : %p\n", ptr_S_iArray[4], &ptr_S_iArray[4]);
	printf("ptr_iArray[5] = %d \t\t at address &ptr_iArray[5] : %p\n", ptr_S_iArray[5], &ptr_S_iArray[5]);
	printf("ptr_iArray[6] = %d \t\t at address &ptr_iArray[6] : %p\n", ptr_S_iArray[6], &ptr_S_iArray[6]);
	printf("ptr_iArray[7] = %d \t\t at address &ptr_iArray[7] : %p\n", ptr_S_iArray[7], &ptr_S_iArray[7]);
	printf("ptr_iArray[8] = %d \t\t at address &ptr_iArray[8] : %p\n", ptr_S_iArray[8], &ptr_S_iArray[8]);
	printf("ptr_iArray[9] = %d \t\t at address &ptr_iArray[9] : %p\n", ptr_S_iArray[9], &ptr_S_iArray[9]);
	
	return(0);
}



