#include <stdio.h>

//Defining the struct variable type
struct SUM_MyPoint
{
	int SUM_x;
	int SUM_y;
} SUM_Point_A, SUM_Point_B, SUM_Point_C, SUM_Point_D, SUM_Point_E; 
// Global Declaration of variable SUM_MyPoint (that includes 2 different variables of 'int' datatype), with SUM_Point_A, SUM_Point_B, SUM_Point_C, SUM_Point_D, SUM_Point_E as its "struct" variables
int main(void)
{
	//Code
	// Assigning Variables to the Data Membners of 'struct SUM_MyPoint' Members SUM_x and SUM_y for Variables - SUM_Point_A, SUM_Point_B, SUM_Point_C, SUM_Point_D, SUM_Point_E
	
	//'struct SUM_MyPoint >> variable 'SUM_Point_A'
	SUM_Point_A.SUM_x = 3;
	SUM_Point_A.SUM_y = 0;
	
	//'struct SUM_MyPoint >> variable 'SUM_Point_B'
	SUM_Point_B.SUM_x = 1;
	SUM_Point_B.SUM_y = 2;

	//'struct SUM_MyPoint >> variable 'SUM_Point_C'
	SUM_Point_C.SUM_x = 9;
	SUM_Point_C.SUM_y = 6;

	//'struct SUM_MyPoint >> variable 'SUM_Point_D'
	SUM_Point_D.SUM_x = 8;
	SUM_Point_D.SUM_y = 2;

	//'struct SUM_MyPoint >> variable 'SUM_Point_E'
	SUM_Point_E.SUM_x = 11;
	SUM_Point_E.SUM_y = 8;

	//To display the members of 'struct SUM_MyPoint'
	printf("\n\n");
	printf("Co-ordinates (x, y) of Point 'A' are : (%d, %d)\n\n", SUM_Point_A.SUM_x, SUM_Point_A.SUM_y);
	printf("Co-ordinates (x, y) of Point 'B' are : (%d, %d)\n\n", SUM_Point_B.SUM_x, SUM_Point_B.SUM_y);
	printf("Co-ordinates (x, y) of Point 'C' are : (%d, %d)\n\n", SUM_Point_C.SUM_x, SUM_Point_C.SUM_y);
	printf("Co-ordinates (x, y) of Point 'D' are : (%d, %d)\n\n", SUM_Point_D.SUM_x, SUM_Point_D.SUM_y);
	printf("Co-ordinates (x, y) of Point 'E' are : (%d, %d)\n\n", SUM_Point_E.SUM_x, SUM_Point_E.SUM_y);

	return(0);
}


