#include <stdio.h>

struct SUM_MyNumber
{
	int SUM_num;
	int SUM_num_table[10];
};
struct SUM_NumTables
{
	struct SUM_MyNumber SUM_n;
};

int main(void)
{
	// Variable Declarations
	struct SUM_NumTables SUM_tables[10]; // Array of 10 'struct SUM_NumTables'
	int SUM_i, SUM_j;

	// Code

	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		SUM_tables[SUM_i].SUM_n.SUM_num = (SUM_i + 1);
	}
	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		printf("\n\n");
		printf("Table of %d = \n", SUM_tables[SUM_i].SUM_n.SUM_num);
		for (SUM_j = 0; SUM_j < 10; SUM_j++)
		{
			SUM_tables[SUM_i].SUM_n.SUM_num_table[SUM_j] = SUM_tables[SUM_i].SUM_n.SUM_num * (SUM_j + 1);
			printf("%d * %d = %d\n", SUM_tables[SUM_i].SUM_n.SUM_num, (SUM_j + 1), SUM_tables[SUM_i].SUM_n.SUM_num_table[SUM_j]);
		}

	}
	return(0);
}



