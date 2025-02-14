#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int SUM_length, SUM_breadth, SUM_area;

	struct SUM_MyPoint
	{
		int SUM_x;
		int SUM_y;
	};
	struct SUM_MyRectangle
	{
		struct SUM_MyPoint SUM_point_01;
		struct SUM_MyPoint SUM_point_02;
	};
	struct SUM_MyRectangle SUM_rect = { {2, 4}, {6, 8} };

	// Code
	SUM_length = SUM_rect.SUM_point_02.SUM_y - SUM_rect.SUM_point_01.SUM_y;
	if (SUM_length < 0)
	{
		SUM_length = SUM_length * -1;
	}
	SUM_breadth = SUM_rect.SUM_point_02.SUM_x - SUM_rect.SUM_point_01.SUM_x;
	if (SUM_breadth < 0)
	{
		SUM_breadth = SUM_breadth * -1;
	}
	SUM_area = SUM_length * SUM_breadth;

	// To Display the Rectangle Length, Breadth, Area
	printf("\n\n");
	printf("Length of the Rectangle   : %d\n\n", SUM_length);
	printf("Breadth of the Rectangle  : %d\n\n", SUM_breadth);
	printf("Area of the Rectangle     : %d\n\n", SUM_area);

	return(0);

}


