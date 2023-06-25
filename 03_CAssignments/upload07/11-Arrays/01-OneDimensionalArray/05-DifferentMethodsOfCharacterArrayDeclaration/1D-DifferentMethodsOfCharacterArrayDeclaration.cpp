#include <stdio.h>

int main(void)
{
	//Variable declarations
	char S_chArray_01[] = { 'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P', '\0'}; //Must give \0 Explicitly for Proper initialization
	char S_chArray_02[9] = { 'W', 'E', 'L', 'C', 'O', 'M', 'E', 'S', '\0' }; //Must give \0 Explicitly for Proper initialization
	char S_chArray_03[] = { 'Y', 'O', 'U', '\0' }; //Must give \0 Explicitly for Proper initialization
	char S_chArray_04[] = "To"; // \0 is assumed, size is given as 3, although string has only 2 characters
	char S_chArray_05[] = "REAL TIME RENDERING BATCH OF 2023-24"; // \0 is assumed, size is given as 37, although string has only 36 characters

	char S_chArray_WithoutNullTerminator[] = { 'H', 'E', 'L', 'L', 'O' };

	//Code
	printf("\n\n");

	printf("Size of chArray_01 : %lu\n\n", sizeof(S_chArray_01));
	printf("Size of chArray_02 : %lu\n\n", sizeof(S_chArray_02));
	printf("Size of chArray_03 : %lu\n\n", sizeof(S_chArray_03));
	printf("Size of chArray_04 : %lu\n\n", sizeof(S_chArray_04));
	printf("Size of chArray_05 : %lu\n\n", sizeof(S_chArray_05));

	printf("\n\n");

	printf("The Strings Are : \n\n");
	printf("chArray_01 : %s\n\n", S_chArray_01);
	printf("chArray_02 : %s\n\n", S_chArray_02);
	printf("chArray_03 : %s\n\n", S_chArray_03);
	printf("chArray_04 : %s\n\n", S_chArray_04);
	printf("chArray_05 : %s\n\n", S_chArray_05);

	printf("\n\n");
	printf("Size of chArray_WithoutNullTerminator : %lu\n\n", sizeof(S_chArray_WithoutNullTerminator));
	printf("Size of chArray_WithoutNullTerminator : %c\n\n", sizeof(S_chArray_WithoutNullTerminator));
	
	return(0);
}














