#include <stdio.h>

#define MY_PI 3.1415926535897932

#define AMC_STRING "AstroMediComp RTR"

//If First Constant is not assigned a value, It is assumed to be 0 i.e.: 'SUNDAY' will be 0
//And the rest Of the constants are assigned consecutive integer values from 0 onwards i.e. : 'MONDAY' will be 1, 'TUESDAY' will be 2, and so on..

//UN-NAMEd ENUMS
enum
{
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
};

enum
{
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

//NAMED ENUMS
enum Numbers
{
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN
};

enum boolean
{
	TRUE = 1,
	FALSE = 0
};

int main(void)
{
	//local constant declarations
	const double epsilon = 0.000001;

	//code
	printf("\n\n");
	printf("Local Constant Epsilon = %lf\n\n", epsilon);

	printf("Sunday is day number = %d\n", SUNDAY);
	printf("Monday is day number = %d\n", MONDAY);
	printf("Tuesday is day number = %d\n", TUESDAY);
	printf("Wednesday is day number = %d\n", WEDNESDAY);
	printf("Thursday is day number = %d\n", THURSDAY);
	printf("Friday is day number = %d\n", FRIDAY);
	printf("Saturday is day number = %d\n\n", SATURDAY);

	printf("One is Enum number = %d\n", ONE);
	printf("Two is Enum number = %d\n", TWO);
	printf("Three is Enum number = %d\n", THREE);
	printf("Four is Enum number = %d\n", FOUR);
	printf("Five is Enum number = %d\n", FIVE);
	printf("Six is Enum number = %d\n", SIX);
	printf("Seven is Enum number = %d\n", SEVEN);
	printf("Eight is Enum number = %d\n", EIGHT);
	printf("Nine is Enum number = %d\n", NINE);
	printf("Ten is Enum number = %d\n\n", TEN);

	printf("January is month number = %d\n", JANUARY);
	printf("February is month number = %d\n", FEBRUARY);
	printf("March is month number = %d\n", MARCH);
	printf("April is month number = %d\n", APRIL);
	printf("May is month number = %d\n", MAY);
	printf("June is month number = %d\n", JUNE);
	printf("July is month number = %d\n", JULY);
	printf("August is month number = %d\n", AUGUST);
	printf("September is month number = %d\n", SEPTEMBER);
	printf("October is month number = %d\n", OCTOBER);
	printf("November is month number = %d\n", NOVEMBER);
	printf("December is month number = %d\n\n", DECEMBER);

	printf("Value of TRUE is = %d\n", TRUE);
	printf("Value of FALSE is = %d\n", FALSE);

	printf("MY_PI Macro value = %.10lf\n\n", MY_PI);
	printf("Area of circle of radius 2 units = %f\n\n", (MY_PI * 2.0f * 2.0f)); //pi * r * r = areaa of the circle with radius'r'

	printf("\n\n");

	printf(AMC_STRING);
	printf("\n\n");

	printf("AMC_STRING is : %s\n", AMC_STRING);
	printf("\n\n");

	return(0);
}



