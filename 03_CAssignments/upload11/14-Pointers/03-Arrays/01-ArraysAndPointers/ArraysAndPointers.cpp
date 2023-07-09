#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int S_iArray[] = { 10, 20, 30, 40, 50, 60 ,70, 80, 90, 100 };
	float S_fArray[] = { 1.2f, 2.3f, 3.4f, 4.5f, 5.6f };
	double S_dArray[] = {1.012345, 2.012345, 3.012345};
	char S_cArray[] = {'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P', '\0'};

	// Code 

	// Integer Array
	printf("\n\n");
	printf("Integer Array Elements and the Addresses they occupy are as follows : \n\n");
	printf("iArraay[0] = %d \t at address : %p\n", *(S_iArray + 0), (S_iArray + 0));
	printf("iArraay[1] = %d \t at address : %p\n", *(S_iArray + 1), (S_iArray + 1));
	printf("iArraay[2] = %d \t at address : %p\n", *(S_iArray + 2), (S_iArray + 2));
	printf("iArraay[3] = %d \t at address : %p\n", *(S_iArray + 3), (S_iArray + 3));
	printf("iArraay[4] = %d \t at address : %p\n", *(S_iArray + 4), (S_iArray + 4));
	printf("iArraay[5] = %d \t at address : %p\n", *(S_iArray + 5), (S_iArray + 5));
	printf("iArraay[6] = %d \t at address : %p\n", *(S_iArray + 6), (S_iArray + 6));
	printf("iArraay[7] = %d \t at address : %p\n", *(S_iArray + 7), (S_iArray + 7));
	printf("iArraay[8] = %d \t at address : %p\n", *(S_iArray + 8), (S_iArray + 8));
	printf("iArraay[9] = %d \t at address : %p\n", *(S_iArray + 9), (S_iArray + 9));
	
	// Floating-Point Array
	printf("\n\n");
	printf("Floating-Point Array Elements and the Addresses they occupy are as follows : \n\n");
	printf("fArraay[0] = %f \t at address : %p\n", *(S_fArray + 0), (S_fArray + 0));
	printf("fArraay[1] = %f \t at address : %p\n", *(S_fArray + 1), (S_fArray + 1));
	printf("fArraay[2] = %f \t at address : %p\n", *(S_fArray + 2), (S_fArray + 2));
	printf("fArraay[3] = %f \t at address : %p\n", *(S_fArray + 3), (S_fArray + 3));
	printf("fArraay[4] = %f \t at address : %p\n", *(S_fArray + 4), (S_fArray + 4));

	// Double Array
	printf("\n\n");
	printf("Double Array Elements and the Addresses they occupy are as follows : \n\n");
	printf("dArraay[0] = %lf \t at address : %p\n", *(S_dArray + 0), (S_dArray + 0));
	printf("dArraay[1] = %lf \t at address : %p\n", *(S_dArray + 1), (S_dArray + 1));
	printf("dArraay[2] = %lf \t at address : %p\n", *(S_dArray + 2), (S_dArray + 2));
	
	// Character Array
	printf("\n\n");
	printf("Characterer Array Elements and the Addresses they occupy are as follows : \n\n");
	printf("cArraay[0]  = %c \t at address : %p\n", *(S_cArray + 0), (S_cArray + 0));
	printf("cArraay[1]  = %c \t at address : %p\n", *(S_cArray + 1), (S_cArray + 1));
	printf("cArraay[2]  = %c \t at address : %p\n", *(S_cArray + 2), (S_cArray + 2));
	printf("cArraay[3]  = %c \t at address : %p\n", *(S_cArray + 3), (S_cArray + 3));
	printf("cArraay[4]  = %c \t at address : %p\n", *(S_cArray + 4), (S_cArray + 4));
	printf("cArraay[5]  = %c \t at address : %p\n", *(S_cArray + 5), (S_cArray + 5));
	printf("cArraay[6]  = %c \t at address : %p\n", *(S_cArray + 6), (S_cArray + 6));
	printf("cArraay[7]  = %c \t at address : %p\n", *(S_cArray + 7), (S_cArray + 7));
	printf("cArraay[8]  = %c \t at address : %p\n", *(S_cArray + 8), (S_cArray + 8));
	printf("cArraay[9]  = %c \t at address : %p\n", *(S_cArray + 9), (S_cArray + 9));
	printf("cArraay[10] = %c \t at address : %p\n", *(S_cArray + 10), (S_cArray + 10));
	printf("cArraay[11] = %c \t at address : %p\n", *(S_cArray + 11), (S_cArray + 11));
	printf("cArraay[12] = %c \t at address : %p\n", *(S_cArray + 12), (S_cArray + 12));

	return(0);
}



