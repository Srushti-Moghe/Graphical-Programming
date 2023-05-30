#include <stdio.h>
int main(void)
{
	//variable declarations 
	int SUM_num;
	
	//code
	printf("\n\n");

	printf("Enter value for Num : ");
	scanf("%d", &SUM_num);
	
	if (SUM_num < 0) //IF - 01
	{
		printf("Num = %d is less than 0 (Negative) !!!\n\n", SUM_num);
	}
	else //ELSE - 01
	{
		if ((SUM_num > 0) && (SUM_num <= 100)) //IF - 02
		{
			printf("Num = %d is is between 0 and 100 !!!\n\n", SUM_num);
		}
		else //ELSE - 02
		{
			if ((SUM_num > 100) && (SUM_num <= 200)) //IF - 03
			{
				printf("Num = %d is is between 100 and 200 !!!\n\n", SUM_num);
			}
			else //ELSE - 03
			{
				if ((SUM_num > 200) && (SUM_num <= 300)) //IF - 04
				{
					printf("Num = %d is is between 200 and 300 !!!\n\n", SUM_num);
				}
				else //ELSE - 04
				{
					if ((SUM_num > 300) && (SUM_num <= 400)) //IF - 05
					{
						printf("Num = %d is is between 300 and 400 !!!\n\n", SUM_num);
					}
					else //ELSE - 05
					{
						if ((SUM_num > 400) && (SUM_num <= 500)) //IF - 06
						{
							printf("Num = %d is is between 400 and 500 !!!\n\n", SUM_num);
						}
						else //ELSE - 06
						{
							printf("Num %d is Greater than 500 !!! \n\n", SUM_num);
						} //closing brace for ELSE - 06
					}//closing brace for ELSE - 05
				}//closing brace for ELSE - 04
			}//closing brace for ELSE - 03
		}//closing brace for ELSE - 02
		
	}//closing brace for ELSE - 01

	return(0);
}




