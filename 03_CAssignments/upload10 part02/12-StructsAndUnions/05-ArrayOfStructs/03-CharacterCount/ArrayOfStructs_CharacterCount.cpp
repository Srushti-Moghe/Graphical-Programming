#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

// Defining struct SUM_MyEmployee
struct SUM_CharacterCount
{
	char S_ch;
	int S_ch_Count;
} SUM_character_and_count[] = { {'A', 0}, //character_and_count[0].ch = 'A' & character_and_count[0].ch_count = 0
								{'B', 0}, //character_and_count[1].ch = 'B' & character_and_count[1].ch_count = 0
								{'C', 0}, //character_and_count[2].ch = 'C' & character_and_count[2].ch_count = 0
								{'D', 0}, //character_and_count[3].ch = 'D' & character_and_count[3].ch_count = 0
								{'E', 0}, //character_and_count[4].ch = 'E' & character_and_count[4].ch_count = 0
								{'F', 0}, //character_and_count[5].ch = 'F' & character_and_count[5].ch_count = 0
								{'G', 0}, //character_and_count[6].ch = 'G' & character_and_count[6].ch_count = 0
								{'H', 0},
								{'I', 0},
								{'J', 0},
								{'K', 0},
								{'L', 0},
								{'M', 0},
								{'N', 0},
								{'O', 0},
								{'P', 0},
								{'Q', 0},
								{'R', 0},
								{'S', 0},
								{'T', 0},
								{'U', 0},
								{'V', 0},
								{'W', 0},
								{'X', 0},
								{'Y', 0},
								{'Z', 0} }; //character_and_count[25].ch = 'Z' & character_and_count[25].ch_count = 0

#define SIZE_OF_ENTIRE_ARRAY_OF_STRUCTS sizeof(SUM_character_and_count)
#define SIZE_OF_ONE_STRUCT_FROM_THE_ARRAY_OF_STRUCTS sizeof(SUM_character_and_count[0])
#define NUM_ELEMENTS_IN_ARRAY (SIZE_OF_ENTIRE_ARRAY_OF_STRUCTS / SIZE_OF_ONE_STRUCT_FROM_THE_ARRAY_OF_STRUCTS)

// Entry Point Function
int main(void)
{
	// Variable declarations
	char SUM_str[MAX_STRING_LENGTH];
	int SUM_i, SUM_j, SUM_actual_string_length = 0;

	//Code
	printf("\n\n");
	printf("Enter a string : \n\n");
	gets_s(SUM_str, MAX_STRING_LENGTH);

	SUM_actual_string_length = strlen(SUM_str);

	printf("\n\n");
	printf("The string you have entered is : \n\n");
	printf("%s\n\n", SUM_str);

	for (SUM_i = 0; SUM_i < SUM_actual_string_length; SUM_i++)
	{
		for (SUM_j = 0; SUM_j < NUM_ELEMENTS_IN_ARRAY; SUM_j++) // To run every character of the input string through the entire alphabet (A toZ)
		{
			SUM_str[SUM_i] = toupper(SUM_str[SUM_i]); // If input character is in lower case, turn it to upper case from comparison
			if (SUM_str[SUM_i] == SUM_character_and_count[SUM_j].S_ch)
			{
				SUM_character_and_count[SUM_j].S_ch_Count++;  // Increment its count by 1
			}
		}
	}
	printf("\n\n");
	printf("The number of occurences of all characters from the alphabet are as follows : \n\n");
	for (SUM_i = 0; SUM_i < NUM_ELEMENTS_IN_ARRAY; SUM_i++)
	{
		printf("Character '%c' = %d\n", SUM_character_and_count[SUM_i].S_ch, SUM_character_and_count[SUM_i].S_ch_Count);
	}
	printf("\n\n");

	return(0);
}




