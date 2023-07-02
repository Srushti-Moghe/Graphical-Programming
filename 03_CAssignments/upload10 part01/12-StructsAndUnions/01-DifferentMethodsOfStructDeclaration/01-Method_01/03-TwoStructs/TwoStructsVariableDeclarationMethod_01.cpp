#include <stdio.h>
#include <string.h>

//Defining the struct variable type
struct SUM_MyPoint
{
	int SUM_x;
	int SUM_y;
} SUM_Point; 
// Global Declaration of variable SUM_MyPoint (that includes 2 different variables of 'int' datatype), with SUM_Point as its "struct" variables

struct SUM_MyPointProperties
{
	int SUM_Quadrant;
	char SUM_Axis_Location[10];
} SUM_PointProperties;
// Global Declaration of variable SUM_MyPointProperties (that includes 2 different variables of 'int' and 'char' datatypes), with SUM_PointProperties as its "struct" variables


int main(void)
{
	//Code
	// User Inputs for Assigning the data members 
	// struct SUM_MyPointProperties >> variable 'Point_A'
	printf("\n\n");
	printf("Enter 'X-Co-ordinate' for 'A' point : ");
	scanf("%d", &SUM_Point.SUM_x);
	printf("Enter 'Y-Co-ordinate' for 'A' point : ");
	scanf("%d", &SUM_Point.SUM_y);

	printf("\n\n");
	printf("Point Co-ordinates (x, y) are : (%d, %d) !!!\n\n", SUM_Point.SUM_x, SUM_Point.SUM_y);

	if (SUM_Point.SUM_x == 0 && SUM_Point.SUM_y == 0)
	{
		printf("The point is the origin (%d, %d)!!!\n", SUM_Point.SUM_x, SUM_Point.SUM_y);
	}
	else
	{
		if (SUM_Point.SUM_x == 0) // Point lies on Y-Axis
		{
			if (SUM_Point.SUM_y < 0) // Point on Negative Y-Axis
			{
				strcpy(SUM_PointProperties.SUM_Axis_Location, "Negative Y-Axis");
			}
			if (SUM_Point.SUM_y > 0) // Point lies on Positive Y-Axis
			{
				strcpy(SUM_PointProperties.SUM_Axis_Location, "Positive Y-Axis");
			}
			SUM_PointProperties.SUM_Quadrant = 0;
			printf("The Point lies on the %s Axis !!!\n\n", SUM_PointProperties.SUM_Axis_Location);
		}
		else if (SUM_Point.SUM_y == 0)  // Point lies on X-Axis
		{
			if (SUM_Point.SUM_x < 0) // Point lies on Negative X-Axis
			{
				strcpy(SUM_PointProperties.SUM_Axis_Location, "Negative X-Axis");
			}
			if (SUM_Point.SUM_y > 0) // Point lies on Positive X-Axis
			{
				strcpy(SUM_PointProperties.SUM_Axis_Location, "Positive X-Axis");
			}
			SUM_PointProperties.SUM_Quadrant = 0;
			printf("The Point lies on the %s Axis !!!\n\n", SUM_PointProperties.SUM_Axis_Location);

		}
		else
		{
			SUM_PointProperties.SUM_Axis_Location[0] = '\0'; // When the point lies on either of the Axes, It does not fall into any Quadrants

			if (SUM_Point.SUM_x > 0 && SUM_Point.SUM_y > 0) // Point-X lies on Positive X-Axis; Point-Y lies on Positive Y-Axis (+, +)
			{
				SUM_PointProperties.SUM_Quadrant = 1; 
			}
			else if (SUM_Point.SUM_x < 0 && SUM_Point.SUM_y > 0) // Point-X lies on Negative X-Axis; Point-Y lies on Positive Y-Axis (-, +)
			{
				SUM_PointProperties.SUM_Quadrant = 2;
			}
			else if (SUM_Point.SUM_x < 0 && SUM_Point.SUM_y < 0)  // Point-X lies on Negative X-Axis; Point-Y lies on Negative Y-Axis (-, -)
			{
				SUM_PointProperties.SUM_Quadrant = 3;
			}
			else if (SUM_Point.SUM_x > 0 && SUM_Point.SUM_y < 0) // Point-X lies on Positive X-Axis; Point-Y lies on Negative Y-Axis (+, -)
			{
				SUM_PointProperties.SUM_Quadrant = 4;
			}
			printf("The Point lies in Quadrant Number %d !!!\n\n", SUM_PointProperties.SUM_Quadrant);
		}
	}
	
	
	return(0);
}


