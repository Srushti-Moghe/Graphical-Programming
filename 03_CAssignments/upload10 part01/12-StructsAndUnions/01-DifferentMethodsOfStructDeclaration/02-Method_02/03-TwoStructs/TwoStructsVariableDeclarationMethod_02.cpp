#include <stdio.h>
#include <string.h>

// Defining Struct 1
struct SUM_MyPoint
{
	int SUM_x;
	int SUM_y;
};

// Defining Struct 2
struct SUM_MyPointProperties
{
	int SUM_Quadrant;
	char SUM_Axis_Location[10];
};

// Struct Declarations
struct SUM_MyPoint SUM_Point;                         // Global Declaration of variable SUM_MyPoint (that includes 2 integer datatypes), with SUM_x and SUM_y as its members
struct SUM_MyPointProperties SUM_PointProperties;     // Global Declaration of variable SUM_MyPointProperties (that includes  integer and character (Array) datatypes), with SUM_Quadrant and SUM_Axis_Location as its members

int main(void)
{
	// Code
	// User Input for the data Assigning Data of the members of struct 'SUM_MyPoint' variable SUM_MyPoint
	printf("\n\n");
	printf("Enter 'X Co-ordinate' for 'A' point : ");
	scanf("%d", &SUM_Point.SUM_x);
	printf("Enter 'Y Co-ordinate' for 'A' point : ");
	scanf("%d", &SUM_Point.SUM_y);
	printf("\n\n");
	printf("The User Input Co-ordinates for point 'A(x, y)' are : (%d, %d)\n\n", SUM_Point.SUM_x, SUM_Point.SUM_y); // Prints the  USer Input values for the x and y co-ordinate


	if (SUM_Point.SUM_x == 0 && SUM_Point.SUM_y == 0)			// Point x == y == 0 indicates the origin      
	{
		printf("The point A(%d, %d) lies on the Origin!!!", SUM_Point.SUM_x, SUM_Point.SUM_y);
	}
	else
	{
		if (SUM_Point.SUM_x == 0)			// Point lies on Y-Axis
		{
			if (SUM_Point.SUM_y > 0)
			{
				strcpy(SUM_PointProperties.SUM_Axis_Location, "Positive Y-Axis");
			}
			if (SUM_Point.SUM_y < 0)
			{
				strcpy(SUM_PointProperties.SUM_Axis_Location, "Negative Y-Axis");
			}
			SUM_PointProperties.SUM_Quadrant = 0;		// Point lies on Y-Axis, hence doesnot lie in any Quadrants
			printf("The Point A lies on %s \n\n", SUM_PointProperties.SUM_Axis_Location);
		}
		else if (SUM_Point.SUM_y == 0)			// Point lies on X-Axis
		{
			if (SUM_Point.SUM_x > 0)
			{
				strcpy(SUM_PointProperties.SUM_Axis_Location, "Positive X-Axis");
			}
			if (SUM_Point.SUM_x < 0)
			{
				strcpy(SUM_PointProperties.SUM_Axis_Location, "Negative X-Axis");
			}
			SUM_PointProperties.SUM_Quadrant = 0;		// Point lies on X-Axis, hence doesnot lie in any Quadrants
			printf("The Point A lies on %s \n\n", SUM_PointProperties.SUM_Axis_Location);
		}
		else
		{
			SUM_PointProperties.SUM_Axis_Location[0] = '\0';

			if (SUM_Point.SUM_x > 0 && SUM_Point.SUM_y > 0) //For Quadrant - 1
			{
				SUM_PointProperties.SUM_Quadrant = 1;
			}
			else if (SUM_Point.SUM_x > 0 && SUM_Point.SUM_y < 0) //For Quadrant - 2
			{
				SUM_PointProperties.SUM_Quadrant = 2;
			}
			else if (SUM_Point.SUM_x < 0 && SUM_Point.SUM_y < 0) //For Quadrant - 3
			{
				SUM_PointProperties.SUM_Quadrant = 3;
			}
			else     //For Quadrant - 4
			{
				SUM_PointProperties.SUM_Quadrant = 4;
			}
			printf("The Point lies in the Quadrant number %d !!!\n\n", SUM_PointProperties.SUM_Quadrant);
		}
	
	}
	return (0);
}

