#include <stdio.h>
int main(void)
{
	//variable declarations
	int SUMi_num, SUMnum, SUMi;

	//code
	printf("\n\n");

	printf("Enter an Integer value from which iteration must begin : ");
	scanf("%d", &SUMi_num);

	printf("How many digits do you want to print from %d onwards ? : ", SUMi_num);
	scanf("%d", &SUMnum);

	printf("Printing Digits %d to %d : \n\n", SUMi_num, (SUMi_num + SUMnum));

	do 
	{
		printf("\t %d \n", SUMi);
		SUMi++;
	} while (SUMi <= (SUMi_num + SUMnum));

	printf("\n\n");

	return(0);

}







