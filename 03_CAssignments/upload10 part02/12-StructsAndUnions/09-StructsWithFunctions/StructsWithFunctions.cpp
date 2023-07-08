#include <stdio.h>
#include <conio.h>

struct SUM_MyData
{
	int SUM_i;
	float SUM_f;
	double SUM_d;
	char SUM_c;
};

int main(void)
{
	// Function Prototype 
	struct SUM_MyData AddStructMembers(struct SUM_MyData, struct SUM_MyData, struct SUM_MyData);
	
	// Variable Declarations
	struct SUM_MyData SUM_data1, SUM_data2, SUM_data3, SUM_data_answer;

	// Code
	 
	// SUM_data1
	printf("\n\n\n\n");
	printf("***** DATA 1 *****\n\n");
	printf("Enter an integer value for 'i' of struct SUM_MyData SUM_data1 : ");
	scanf("%d", &SUM_data1.SUM_i);

	printf("\n\n");
	printf("Enter a floating value for 'f' of struct SUM_MyData SUM_data1 : ");
	scanf("%f", &SUM_data1.SUM_f);

	printf("\n\n");
	printf("Enter a double value for 'd' of struct SUM_MyData SUM_data1 : ");
	scanf("%lf", &SUM_data1.SUM_d);

	printf("\n\n");
	printf("Enter a character value for 'c' of struct SUM_MyData SUM_data1 : ");
	SUM_data1.SUM_c = getch();
	printf("%c", SUM_data1.SUM_c);



	// SUM_data2
	printf("\n\n\n\n");
	printf("***** DATA 2 *****\n\n");
	printf("Enter an integer value for 'i' of struct SUM_MyData SUM_data2 : ");
	scanf("%d", &SUM_data2.SUM_i);

	printf("\n\n");
	printf("Enter a floating value for 'f' of struct SUM_MyData SUM_data2 : ");
	scanf("%f", &SUM_data2.SUM_f);

	printf("\n\n");
	printf("Enter a double value for 'd' of struct SUM_MyData SUM_data2 : ");
	scanf("%lf", &SUM_data2.SUM_d);

	printf("\n\n");
	printf("Enter a character value for 'c' of struct SUM_MyData SUM_data2 : ");
	SUM_data2.SUM_c = getch();
	printf("%c", SUM_data2.SUM_c);


	// SUM_data3
	printf("\n\n\n\n");
	printf("***** DATA 3 *****\n\n");
	printf("Enter an integer value for 'i' of struct SUM_MyData SUM_data3 : ");
	scanf("%d", &SUM_data3.SUM_i);

	printf("\n\n");
	printf("Enter a floating value for 'f' of struct SUM_MyData SUM_data3 : ");
	scanf("%f", &SUM_data3.SUM_f);

	printf("\n\n");
	printf("Enter a double value for 'd' of struct SUM_MyData SUM_data3 : ");
	scanf("%lf", &SUM_data3.SUM_d);

	printf("\n\n");
	printf("Enter a character value for 'c' of struct SUM_MyData SUM_data3 : ");
	SUM_data3.SUM_c = getch();
	printf("%c", SUM_data3.SUM_c);

	// Calling Function AddStructMembers() which Accepts 3 variables of type 'struct SUM_MyData' as parameters and adds up the respective members and returns the answer in another struct of the same type

	SUM_data_answer = AddStructMembers(SUM_data1, SUM_data2, SUM_data3);

	printf("\n\n\n\n");
	printf("***** Answers *****");
	printf("SUM_data_answer.SUM_i = %d\n", SUM_data_answer.SUM_i);
	printf("SUM_data_answer.SUM_f = %f\n", SUM_data_answer.SUM_f);
	printf("SUM_data_answer.SUM_d = %lf\n", SUM_data_answer.SUM_d);

	printf("\n\n");
	SUM_data_answer.SUM_c = SUM_data1.SUM_c;
	printf("SUM_data_answer.SUM_c (from data1) = %c\n", SUM_data_answer.SUM_c);
	printf("\n\n");
	SUM_data_answer.SUM_c = SUM_data2.SUM_c;
	printf("SUM_data_answer.SUM_c (from data2) = %c\n", SUM_data_answer.SUM_c);
	printf("\n\n");
	SUM_data_answer.SUM_c = SUM_data3.SUM_c;
	printf("SUM_data_answer.SUM_c (from data3) = %c\n", SUM_data_answer.SUM_c);

	return(0);
}

// Defining AddStructMembers()
struct SUM_MyData AddStructMembers(struct SUM_MyData n_1, struct SUM_MyData n_2, struct SUM_MyData n_3)
{
	// Variable Declarations
	struct SUM_MyData SUM_answer;

	// Code
	SUM_answer.SUM_i = n_1.SUM_i + n_2.SUM_i + n_3.SUM_i;
	SUM_answer.SUM_f = n_1.SUM_f + n_2.SUM_f + n_3.SUM_f;
	SUM_answer.SUM_d = n_1.SUM_d + n_2.SUM_d + n_3.SUM_d;

	return(SUM_answer);
}





