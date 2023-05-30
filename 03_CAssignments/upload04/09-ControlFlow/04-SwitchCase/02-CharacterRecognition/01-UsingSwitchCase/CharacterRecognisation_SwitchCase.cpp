#include <stdio.h> //for printf()
#include <conio.h> //for getch()

//ASCII values for 'A' to 'Z' => 65 to 90
#define CHAR_ALPHABET_UPPER_CASE_BEGINNING 65
#define CHAR_ALPHABET_UPPER_CASE_ENDING 90

//ASCII values for 'A' to 'Z' => 65 to 90
#define CHAR_ALPHABET_LOWER_CASE_BEGINNING 97
#define CHAR_ALPHABET_LOWER_CASE_ENDING 122

//ASCII values for '0' to '9' => 65 to 90
#define CHAR_DIGIT_BEGINNING 48
#define CHAR_DIGIT_ENDING 57

int main(void)
{
	//variable declarations 
	char SUM_ch;
	int ch_value;
	
	//code
	printf("\n\n");

	printf("Enter Character : ");
	SUM_ch = getch();

	printf("\n\n");

	switch (SUM_ch)
	{
		//Fall Through Condition
	case 'A' :
	case 'a' :

	case 'E':
	case 'e':

	case 'I':
	case 'i':

	case 'O':
	case 'o':

	case 'U':
	case 'u':
		printf("Character \'%c\" Entered is a VOWEL CHARACTER from the English Alphabet !!!\n\n", SUM_ch);
		break;
	default:
		ch_value = (int)SUM_ch;
		// If the character has ASCII value b/w 65 - 90 OR b/w 97 - 122 It is still an alphabet, but an CONSONANT
		if ((ch_value >= CHAR_ALPHABET_UPPER_CASE_BEGINNING && ch_value <= CHAR_ALPHABET_UPPER_CASE_ENDING) || (ch_value >= CHAR_ALPHABET_LOWER_CASE_BEGINNING && ch_value <= CHAR_ALPHABET_LOWER_CASE_ENDING))
		{
			printf("Character \'%c\" Entered is a CONSONANT CHARACTER from the Engligh Alphabet !!!\n\n", SUM_ch);
		}
		else if (ch_value >= CHAR_DIGIT_BEGINNING && ch_value <= CHAR_DIGIT_ENDING)
		{
			printf("Character \'%c\" Entered is a DIGIT CHARACTER from the Engligh Alphabet !!!\n\n", SUM_ch);
		}
		else
		{
			printf("Character \'%c\" Entered is a SPECIAL CHARACTER from the Engligh Alphabet !!!\n\n", SUM_ch);
		}
		break;
	}
	printf("Switch Case Block Complete !!!\n\n");
	
	return(0);
}













