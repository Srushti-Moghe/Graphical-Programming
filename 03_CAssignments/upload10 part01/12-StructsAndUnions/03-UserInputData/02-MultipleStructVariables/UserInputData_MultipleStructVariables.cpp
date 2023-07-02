#include <stdio.h>

// Defining struct
struct SUM_MyPoint
{
	int SUM_x;
	int SUM_y;
}; 

int main(void)
{
	// Variable Declarations for single struct variable
	struct SUM_MyPoint SUM_Point_A, SUM_Point_B, SUM_Point_C, SUM_Point_D, SUM_Point_E; // Declaring 5 struct variables
	
	// Code
	// User input values for data members of 'struct SUM_Point'

	// User input values for data members of SUM_Point_A
	printf("\n\n");
	printf("Enter X-Coordinate for Point 'A' : ");
	scanf("%d", &SUM_Point_A.SUM_x);
	printf("Enter Y-Coordinate for Point 'A' : ");
	scanf("%d", &SUM_Point_A.SUM_y);

	// User input values for data members of SUM_Point_B
	printf("\n\n");
	printf("Enter X-Coordinate for Point 'B' : ");
	scanf("%d", &SUM_Point_B.SUM_x);
	printf("Enter Y-Coordinate for Point 'B' : ");
	scanf("%d", &SUM_Point_B.SUM_y);

	// User input values for data members of SUM_Point_C
	printf("\n\n");
	printf("Enter X-Coordinate for Point 'C' : ");
	scanf("%d", &SUM_Point_C.SUM_x);
	printf("Enter Y-Coordinate for Point 'C' : ");
	scanf("%d", &SUM_Point_C.SUM_y);

	// User input values for data members of SUM_Point_D
	printf("\n\n");
	printf("Enter X-Coordinate for Point 'D' : ");
	scanf("%d", &SUM_Point_D.SUM_x);
	printf("Enter Y-Coordinate for Point 'D' : ");
	scanf("%d", &SUM_Point_D.SUM_y);

	// User input values for data members of SUM_Point_E
	printf("\n\n");
	printf("Enter X-Coordinate for Point 'E' : ");
	scanf("%d", &SUM_Point_E.SUM_x);
	printf("Enter Y-Coordinate for Point 'E' : ");
	scanf("%d", &SUM_Point_E.SUM_y);

	// Displaying the values of the members of 'struct SUM_MyPoint'
	printf("\n\n");
	printf("Data Members of 'struct SUM_MyPoint' are : \n\n");
	
	printf("The Co-ordinates (x, y) of Point 'A' are : (%d, %d)\n", SUM_Point_A.SUM_x, SUM_Point_A.SUM_y);
	printf("The Co-ordinates (x, y) of Point 'B' are : (%d, %d)\n", SUM_Point_B.SUM_x, SUM_Point_B.SUM_y);
	printf("The Co-ordinates (x, y) of Point 'C' are : (%d, %d)\n", SUM_Point_C.SUM_x, SUM_Point_C.SUM_y);
	printf("The Co-ordinates (x, y) of Point 'D' are : (%d, %d)\n", SUM_Point_D.SUM_x, SUM_Point_D.SUM_y);
	printf("The Co-ordinates (x, y) of Point 'E' are : (%d, %d)\n", SUM_Point_E.SUM_x, SUM_Point_E.SUM_y);
			
	return(0);
}




