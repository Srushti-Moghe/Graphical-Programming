#include <stdio.h>

struct SUM_MyNumber
{
	int SUM_num;
	int SUM_num_table[10];
};
struct SUM_NumTables
{
	struct SUM_MyNumber SUM_a;
	struct SUM_MyNumber SUM_b;
	struct SUM_MyNumber SUM_c;
};

int main(void)
{
	// Variable Declarations
	struct SUM_NumTables SUM_tables;
	int SUM_i;

	// Code

	// Table of 2
	SUM_tables.SUM_a.SUM_num = 2;
	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		SUM_tables.SUM_a.SUM_num_table[SUM_i] = SUM_tables.SUM_a.SUM_num * (SUM_i + 1);
	}
	printf("\n\n");
	printf("Table of %d : \n\n", SUM_tables.SUM_a.SUM_num);
	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		printf("%d * %d = %d\n", SUM_tables.SUM_a.SUM_num, (SUM_i + 1), SUM_tables.SUM_a.SUM_num_table[SUM_i]);
	}

	// Table of 3
	SUM_tables.SUM_b.SUM_num = 3;
	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		SUM_tables.SUM_b.SUM_num_table[SUM_i] = SUM_tables.SUM_b.SUM_num * (SUM_i + 1);
	}
	printf("\n\n");
	printf("Table of %d : \n\n", SUM_tables.SUM_b.SUM_num);
	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		printf("%d * %d = %d\n", SUM_tables.SUM_b.SUM_num, (SUM_i + 1), SUM_tables.SUM_b.SUM_num_table[SUM_i]);
	}

	// Table of 4
	SUM_tables.SUM_c.SUM_num = 4;
	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		SUM_tables.SUM_c.SUM_num_table[SUM_i] = SUM_tables.SUM_c.SUM_num * (SUM_i + 1);
	}
	printf("\n\n");
	printf("Table of %d : \n\n", SUM_tables.SUM_c.SUM_num);
	for (SUM_i = 0; SUM_i < 10; SUM_i++)
	{
		printf("%d * %d = %d\n", SUM_tables.SUM_c.SUM_num, (SUM_i + 1), SUM_tables.SUM_c.SUM_num_table[SUM_i]);
	}

	return(0);
}



