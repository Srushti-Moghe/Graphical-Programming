#include <stdio.h>

//Defining Struct
struct SUM_MyPoint
{
	int SUM_x;
	int SUM_y;
};
struct SUM_MyPoint SUM_MyPoint_A, SUM_MyPoint_B, SUM_MyPoint_C, SUM_MyPoint_D, SUM_MyPoint_E; // Global Declaration of variable SUM_MyPoints (that includes 2 integer data types), with SUM_x and SUM_y as its members

int main(void)
{
	// Code
	// Assigning Data values to the members of struct 'SUM_MyPoint' variables

	//struct 'SUM_MyPoint' >> variable SUM_MyPoint_A
	SUM_MyPoint_A.SUM_x = 1;
	SUM_MyPoint_A.SUM_y = -2;

	//struct 'SUM_MyPoint' >> variable SUM_MyPoint_B
	SUM_MyPoint_B.SUM_x = -3;
	SUM_MyPoint_B.SUM_y = 4;

	//struct 'SUM_MyPoint' >> variable SUM_MyPoint_C
	SUM_MyPoint_C.SUM_x = 5;
	SUM_MyPoint_C.SUM_y = 6;

	//struct 'SUM_MyPoint' >> variable SUM_MyPoint_D
	SUM_MyPoint_D.SUM_x = -7;
	SUM_MyPoint_D.SUM_y = -8;

	//struct 'SUM_MyPoint' >> variable SUM_MyPoint_E
	SUM_MyPoint_E.SUM_x = 0;
	SUM_MyPoint_E.SUM_y = 0;
	
	// Printing the members of struct 'SUM_MyPoint' (and all its variables)
	printf("\n\n");
	printf("The Members of struct 'SUM_MyPoint' i.e. the Co-ordinates are : \n");
	printf("The (x, y) Co-ordinate of point A are = (%d, %d)\n", SUM_MyPoint_A.SUM_x, SUM_MyPoint_A.SUM_y);
	printf("The (x, y) Co-ordinate of point B are = (%d, %d)\n", SUM_MyPoint_B.SUM_x, SUM_MyPoint_B.SUM_y);
	printf("The (x, y) Co-ordinate of point C are = (%d, %d)\n", SUM_MyPoint_C.SUM_x, SUM_MyPoint_C.SUM_y);
	printf("The (x, y) Co-ordinate of point D are = (%d, %d)\n", SUM_MyPoint_D.SUM_x, SUM_MyPoint_D.SUM_y);
	printf("The (x, y) Co-ordinate of point E are = (%d, %d)\n", SUM_MyPoint_E.SUM_x, SUM_MyPoint_E.SUM_y);
	printf("\n\n");

	return (0);
}

