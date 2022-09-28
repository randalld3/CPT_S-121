/* Author: Randall Dickinson
*  Class: Cpt_S 121
*  Instructor: AOFallen
*  Section: 01
*  Assignment: PA5
*  Date Completed: 03.22.22
*/

#include "yahtzee.h"

/*
* Name: print_yahtzee ()
* Description: Prints the word 'Yahtzee!' as an ASCII text banner
* History: Created 03.11.22
* Inputs: None
* Outputs: Big Yahtzee!
* Returns: None
* Precondition: None
* Postcondition: Function executed
*/
void print_yahtzee(void)
{
	printf(".sSSS SSSSS                                                                               SSSSS\n"
		   "SSSSS SSSSS.sSSSSs.     .sSSS SSSSS .sSSSSSSSSSSSSSs. SSSSSSSSSs. .sSSSSs.    .sSSSSs.    S SSS\n"
		   "S SSS SSSSS S SSSSSSSs. S SSS SSSSS SSSSS S SSS SSSSS SSSSSS SSS' S SSSSSSSs. S SSSSSSSs. S  SS\n"
		   "S  SS SSSSS S  SSSSSSS  S  SS SSSSS SSSSS S  SS SSSSS     S  SS   S  SS SSSS' S  SS SSSS' S;;;S\n"
		   "`..SSsSSSS' S..SSsSSSSS S..SSsSSSSS `:S:' S..SS `:S:'    S..SS    S..SS       S..SS       SSSSS\n"
		   "   S:::S    S:::S SSSSS S:::S SSSSS       S:::S         S:::S     S:::SSSS    S:::SSSS    SSSSS\n"
		   "   S;;;S    S;;;S SSSSS S;;;S SSSSS       S;;;S        S;;;S      S;;;S       S;;;S       .sSs.\n"
		   "   SSSSS    SSSSS SSSSS SSSSS SSSSS       SSSSS       SSSSSSSSSSS SSSSS SSSSS SSSSS SSSSS SSSSS\n"
		   "   SSSSS    SSSSS SSSSS SSSSS SSSSS       SSSSS       SSSSSSSSSSS SSSSSsSS;:' SSSSSsSS;:' `:;:'\n");
}

/*
* Name: display_menu ()
* Description: Displays a menu with a list of options
* History: Created 02.25.22
* Inputs: None
* Outputs: Menu options
* Returns: None
* Precondition: None
* Postcondition: Function executed
*/
void display_menu(void)
{
	printf("1. Display Rules\n");
	printf("2. Play Game\n");
	printf("3. Exit\n");
}

/*
* Name: get_int_option ()
* Description: Scanf to receive menu option
* History: Created 02.25.22
* Inputs: None
* Outputs: Menu option
* Returns: One integer
* Precondition: None
* Postcondition: Function executed
*/
int get_int_option(void)
{
	int option = 0;

	do
	{
		scanf("%d", &option);
	} while (option < DISPLAY_RULES || option > EXIT);

	return option;
}

/*
* Name: process_option ()
* Description: Processes menu option to determine next step.
* History: Created 02.25.22
* Inputs: Menu option
* Outputs: Game rules, start of game, or game exit.
* Returns: None
* Precondition: None
* Postcondition: Function executed
*/
void process_option(int option)
{
	switch (option)
	{
	case DISPLAY_RULES: print_game_rules();
		break;
	case PLAY_GAME:  printf("\nLet's play Yahtzee!\n");
		break;
	case EXIT: printf("See you later loser!\n\n");
		system("pause");
		break;
	}
}

/*
* Name: print_game_rules ()
* Description: Prints the rules of the game of Yahtzee
* History: Created 03.11.22
* Inputs: None
* Outputs: The rules of Yahtzee
* Returns: None
* Precondition: None
* Postcondition: Function executed
*/
void print_game_rules(void)
{
	printf("\nThe Rules of Yahtzee:\n\nThe scorecard used for Yahtzee is composed of two sections. An upper section and a lower section.\n"
		     "A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\n\n"
		     "The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\n"
		     "If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\n"
		     "Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\n"
		     "If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus.\n\n"
		     "The lower section contains a number of poker like combinations.The choices for the lower section are:\n"
	         "Three-of-a-kind: Three dice with the same face - Score: Sum of all face values on the 5 dice\n"
	         "Four-of-a-kind: Four dice with the same face - Sum of all face values on the 5 dice\n"
	         "Full House: One pair and three-of-a-kind - 25 points\n"
	         "Small Straight: A sequence of four dice - 30 points\n"
	         "Large Straight: A sequence of five dice - 40 points\n"
	         "Yahtzee: Five dice with the same face\n"
	         "Chance: May be used for any sequence of dice; this is the catch all combination - Sum of all face values on the 5 dice\n\n");

	system("pause");
}

/*
* Name: print_player_one ()
* Description: Prints the words 'Player One' as an ASCII text banner
* History: Created 03.11.22
* Inputs: None
* Outputs: Big Player One
* Returns: None
* Precondition: None
* Postcondition: Function executed
*/
void print_player_one(void)
{
	printf("888b. 8                           .d88b.             \n"             
		   "8  .8 8 .d88 Yb  dP .d88b 8d8b    8P  Y8 8d8b. .d88b \n"
		   "8wwP' 8 8  8  YbdP  8.dP' 8P      8b  d8 8P Y8 8.dP' \n"
		   "8     8 `Y88   dP   `Y88P 8       `Y88P' 8   8 `Y88P \n"
		   "              dP                                   \n\n");
}

/*
* Name: print_player_two ()
* Description: Prints the words 'Player Two' as an ASCII text banner
* History: Created 03.11.22
* Inputs: None
* Outputs: Big Player Two
* Returns: None
* Precondition: None
* Postcondition: Function executed
*/
void print_player_two(void)
{
	printf("888b. 8                           88888                  \n"
           "8  .8 8 .d88 Yb  dP .d88b 8d8b      8   Yb  db  dP .d8b. \n"
           "8wwP' 8 8  8  YbdP  8.dP' 8P        8    YbdPYbdP  8' .8 \n"
           "8     8 `Y88   dP   `Y88P 8         8     YP  YP   `Y8P' \n"
           "              dP                                       \n\n");
}

/*
* Name: initial_dice_roll ()
* Description: gives die values for each of the dice
* History: Created 03.13.22
* Inputs: arr_dice
* Outputs: die values to fill arr_dice[]
* Returns: None
* Precondition: None
* Postcondition: arr_dice will hold the values of the dice
*/
void initial_dice_roll(int arr_dice[])
{
	int index = 0;
	
	while (index < 6)
	{
		arr_dice[index] = rand() % 6 + 1;
		++index;
	}
}

/*
* Name: print_dice ()
* Description: Prints the round #, roll #, and the value of each die, along with the die #.
* History: Created 03.13.22
* Inputs: arr_dice[], roll #, round #
* Outputs: A printed message to keep the player informed
* Returns: None
* Precondition: None
* Postcondition: Function executed
*/
void print_dice(int arr_dice[], int rolls, int round)
{
	int index = 1;

	printf("Round %d\n", (round + 1) / 2);
	printf("Roll %d\n\n", rolls);

	while (index < 6)
	{
		printf("Die %d: %d \n", index, arr_dice[index]);
		++index;
	}
}

/*
* Name: choose_to_score ()
* Description: prompts the player for score option and receives keyboard input
* History: Created 03.13.22
* Inputs: None
* Outputs: The players choice to score
* Returns: one character
* Precondition: None
* Postcondition: Function executed
*/
char choose_to_score(void)
{
	char choice = 'n';

	printf("Would you like to use this roll for one of the combinations?\n");
	do
	{
		scanf(" %c", &choice);
	} while (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y');

	return choice;
}

/*
* Name: dice_to_re_roll ()
* Description: Prompts the player for dice to re-roll, and receives input on which dice to re-roll
* History: Created 03.13.22
* Inputs: arr_re_roll []
* Outputs: the die numbers to be re-rolled
* Returns: None
* Precondition: None
* Postcondition: arr_re_roll [] will contain the die numbers to be re-rolled
*/
void dice_to_re_roll(int arr_re_roll[])
{
	int num_dice = 0, index = 0;

	do
	{
		printf("\nEnter the number of dice you would like to re-roll> ");
		scanf("%d", &num_dice);
	} while (num_dice < 1 || num_dice > 5);

	for (index = 0; index < num_dice; ++index)
	{
		printf("Enter a die number you would like to re-roll> ");
		scanf("%d", &arr_re_roll[index]);
	}

}

void validate_re_roll_dice(int arr_re_roll)
{
	int index1, index2;


}

/*
* Name: sequential_roll ()
* Description: Randomizes the die values (1-6) for the die numbers labeled for re-roll
* History: Created 03.14.22
* Inputs: arr_dice[], arr_re_roll []
* Outputs: new die values for arr_dice for the die numbers labeled for re-roll
* Returns: None
* Precondition: None
* Postcondition: arr_dice will have updated values for the die numbers labeled for re-roll
*/
void sequential_roll(int arr_dice[], int arr_re_roll[])
{
	int index = 0, die_num = 0;

	for (index = 0; arr_re_roll[index] != 0; ++index)
	{
		die_num = arr_re_roll[index];
		arr_dice[die_num] = rand() % 6 + 1;
	}
}

/*
* Name: reset_arr_re_roll ()
* Description: sets all values for arr_re_roll to 0
* History: Created 03.14.22
* Inputs: arr_re_roll []
* Outputs: All zeros for arr_re_roll []
* Returns: None
* Precondition: None
* Postcondition: arr_re_roll will be reset to zeroes.
*/
void reset_arr_re_roll(int arr_re_roll[])
{
	int index = 0;

	while (index < 6)
	{
		arr_re_roll[index] = 0;
		++index;
	}
}

/*
* Name: sum_of_the_faces ()
* Description: fills arr_num_dice with the number of occurences of each possible die value (1-6)
* History: Created 03.14.22
* Inputs: arr_dice[], arr_num_dice []
* Outputs: the number of occurences of each possible die value (1-6)
* Returns: None
* Precondition: None
* Postcondition: arr_num_dice will have the number of occurences of each possible die value
*/
void sum_of_the_faces(int arr_dice[], int arr_num_dice[])
{
	int index = 0, temp = 0;

	for (index = 0; index < 7; ++index)
	{
		arr_num_dice[index] = 0;
	}
	for (index = 1; index < 6; ++index)
	{
		temp = arr_dice[index];
		++arr_num_dice[temp];
	}
}

/*
* Name: score_option ()
* Description: prompts the player for a scoring option, collects input, and verifies the scoring option has not been used
* History: Created 03.14.22
* Inputs: scorecard []
* Outputs: The option the player would like to score
* Returns: One integer
* Precondition: Scorecard must have possible options for scoring (not -1)
* Postcondition: Function executed
*/
int score_option(int scorecard[])
{
	int option = 0;

	printf("Which option would you like to score?\n\nOption 1: 1's\nOption 2: 2's\nOption 3: 3's\nOption 4: 4's\n"
		"Option 5: 5's\nOption 6: 6's\nOption 7: Three-of-a-kind\nOption 8: Four-of-a-kind\nOption 9: Full house\n"
		"Option 10: Small straight\nOption 11: Large straight\nOption 12: Yahtzee\nOption 13: Chance\n");
    scanf("%d", &option);

	while (scorecard[option - 1] != -1)
	{
		while (option < 1 || option > 13)
		{
			printf("Please enter a valid option\n");
			scanf("%d", &option);
		}

		printf("You've already scored that option!\n");
		printf("Please enter a valid option> ");
		scanf("%d", &option);
	}
	
	return option;
}

/*
* Name: process_score_option ()
* Description: Calls the function needed to score the score option
* History: Created 03.14.22
* Inputs: score option, arr_num_dice [], scorecard []
* Outputs: scorecard value for the score option
* Returns: None
* Precondition: None
* Postcondition: scorecard [] will contain an updated value based on the score option
*/
void process_score_option(int option, int arr_num_dice[], int scorecard[])
{
	switch (option)
	{
	case 1: score_1s(arr_num_dice, scorecard);
		break;
	case 2: score_2s(arr_num_dice, scorecard);
		break; 
	case 3: score_3s(arr_num_dice, scorecard);
		break;
	case 4: score_4s(arr_num_dice, scorecard);
		break;
	case 5: score_5s(arr_num_dice, scorecard);
		break;
	case 6: score_6s(arr_num_dice, scorecard);
		break;
	case 7: score_three_of_a_kind(arr_num_dice, scorecard);
		break;
	case 8: score_four_of_a_kind(arr_num_dice, scorecard);
		break;
	case 9: score_full_house(arr_num_dice, scorecard);
		break;
	case 10: score_small_straight(arr_num_dice, scorecard);
		break;
	case 11: score_large_straight(arr_num_dice, scorecard);
		break;
	case 12: score_yahtzee(arr_num_dice, scorecard);
		break;
	case 13: score_chance(arr_num_dice, scorecard);
		break;
	}
}

/*
* Name: score_ns () (where n is the die value (1-6) being scored)
* Description: Fills in the scorecard [] with the appropriate score
* History: Created 03.14.22
* Inputs: arr_num_dice [], scorecard []
* Outputs: A value to scorecard [] based on arr_num_dice []
* Returns: None
* Precondition: None
* Postcondition: scorecard [] will have an updated score value
*/
void score_1s(int arr_num_dice[], int scorecard[])
{
	scorecard[0] = arr_num_dice[1];
}
void score_2s(int arr_num_dice[], int scorecard[])
{
	scorecard[1] = arr_num_dice[2] * 2;
}
void score_3s(int arr_num_dice[], int scorecard[])
{
	scorecard[2] = arr_num_dice[3] * 3;
}
void score_4s(int arr_num_dice[], int scorecard[])
{
	scorecard[3] = arr_num_dice[4] * 4;
}
void score_5s(int arr_num_dice[], int scorecard[])
{
	scorecard[4] = arr_num_dice[5] * 5;
}
void score_6s(int arr_num_dice[], int scorecard[])
{
	scorecard[5] = arr_num_dice[6] * 6;
}

/*
* Name: score_three_of_a_kind ()
* Description: Scores a value for the three-of-a-kind option
* History: Created 03.14.22
* Inputs: arr__num_dice [], scorecard []
* Outputs: A value to scorecard [] based on arr_num_dice []
* Returns: None
* Precondition: None
* Postcondition: scorecard [6] will have a new score value 
*/
void score_three_of_a_kind(int arr_num_dice[], int scorecard[])
{
	int index = 0, score = 0;

	for (index = 1; index < 7; ++index)
	{
		if (arr_num_dice[index] > 2)
		{
			for (index = 1; index < 7; ++index)
			{ score += index * arr_num_dice[index]; }
		}
	}
	scorecard[6] = score;
}

/*
* Name: score_four_of_a_kind ()
* Description: Scores a value for the four-of-a-kind option
* History: Created 03.14.22
* Inputs: arr__num_dice [], scorecard []
* Outputs: A value to scorecard [] based on arr_num_dice []
* Returns: None
* Precondition: None
* Postcondition: scorecard [7] will have a new score value
*/
void score_four_of_a_kind(int arr_num_dice[], int scorecard[])
{
	int index = 0, score = 0;

	for (index = 1; index < 7; ++index)
	{
		if (arr_num_dice[index] > 3)
		{
			for (index = 1; index < 7; ++index)
			{ score += index * arr_num_dice[index]; }
		}
	}
	scorecard[7] = score;
}

/*
* Name: score_full_house ()
* Description: Scores a value for the full house option
* History: Created 03.14.22
* Inputs: arr__num_dice [], scorecard []
* Outputs: A value to scorecard [] based on arr_num_dice []
* Returns: None
* Precondition: None
* Postcondition: scorecard [8] will have a new score value
*/
void score_full_house(int arr_num_dice[], int scorecard[])
{
	int index = 0;

	scorecard[8] = 0;

	for (index = 1; index < 7; ++index)
	{
		if (arr_num_dice[index] == 3)
		{
			for (index = 1; index < 7; ++index)
			{
				if (arr_num_dice[index] == 2)
				{ scorecard[8] = 25; }
			}
		}
	}
}

/*
* Name: score_small_straight ()
* Description: Scores a value for the small straight option
* History: Created 03.14.22
* Inputs: arr__num_dice [], scorecard []
* Outputs: A value to scorecard [] based on arr_num_dice []
* Returns: None
* Precondition: None
* Postcondition: scorecard [9] will have a new score value
*/
void score_small_straight(int arr_num_dice[], int scorecard[])
{
	scorecard[9] = 0;

	if (arr_num_dice[1] > 0 && arr_num_dice[2] > 0 && arr_num_dice[3] > 0 && arr_num_dice[4] > 0)
	{ scorecard[9] = 30; }
	else if (arr_num_dice[2] > 0 && arr_num_dice[3] > 0 && arr_num_dice[4] > 0 && arr_num_dice[5] > 0)
	{ scorecard[9] = 30; }
	else if (arr_num_dice[3] > 0 && arr_num_dice[4] > 0 && arr_num_dice[5] > 0 && arr_num_dice[6] > 0)
	{ scorecard[9] = 30; }
}

/*
* Name: score_large_straight ()
* Description: Scores a value for the large straight option
* History: Created 03.14.22
* Inputs: arr__num_dice [], scorecard []
* Outputs: A value to scorecard [] based on arr_num_dice []
* Returns: None
* Precondition: None
* Postcondition: scorecard [10] will have a new score value
*/
void score_large_straight(int arr_num_dice[], int scorecard[])
{
	scorecard[10] = 0;

	if (arr_num_dice[1] > 0 && arr_num_dice[2] > 0 && arr_num_dice[3] > 0 && arr_num_dice[4] > 0 && arr_num_dice[5] > 0)
	{
		scorecard[10] = 40;
	}
	else if (arr_num_dice[2] > 0 && arr_num_dice[3] > 0 && arr_num_dice[4] > 0 && arr_num_dice[5] > 0 && arr_num_dice[6] > 0)
	{
		scorecard[10] = 40;
	}
}

/*
* Name: score_yahtzee ()
* Description: Scores a value for the yahtzee option
* History: Created 03.14.22
* Inputs: arr__num_dice [], scorecard []
* Outputs: A value to scorecard [] based on arr_num_dice []
* Returns: None
* Precondition: None
* Postcondition: scorecard [11] will have a new score value
*/
void score_yahtzee(int arr_num_dice[], int scorecard[])
{
	int index = 0;

	scorecard[11] = 0;
	
	for (index = 1; index < 7; ++index)
	{
		if (arr_num_dice[index] == 5)
		{
			scorecard[11] = 50;
			print_yahtzee();
		}
	}
}

/*
* Name: score_chance ()
* Description: Scores a value for the chance option
* History: Created 03.14.22
* Inputs: arr__num_dice [], scorecard []
* Outputs: A value to scorecard [] based on arr_num_dice []
* Returns: None
* Precondition: None
* Postcondition: scorecard [12] will have a new score value
*/
void score_chance(int arr_num_dice[], int scorecard[])
{
	int index = 0, score = 0;

	for (index = 1; index < 7; ++index)
	{ score += index * arr_num_dice[index]; }

	scorecard[12] = score;
}

/*
* Name: sum_scores ()
* Description: Sums of the values of scorecard []
* History: Created 03.14.22
* Inputs: scorecard [], *total_score
* Outputs: The sum of the scores to *total_score
* Returns: None
* Precondition: None
* Postcondition: *total_score will have a score
*/
void sum_scores(int scorecard[], int* total_score)
{
	int index = 0, score = 0;

	for (index = 0; index < 6; ++index)
	{ score += scorecard[index]; }
	if (score >= 63)
	{ score += 35; }
	for (index = 6; index < 13; ++index)
	{ score += scorecard[index]; }

	*total_score = score;
}

/*
* Name: print_wins ()
* Description: Prints 'Wins!' as a large ascii text banner
* History: Created 03.14.22
* Inputs: None
* Outputs: Big Wins!
* Returns: None
* Precondition: None
* Postcondition: None
*/
void print_wins(void)
{
	printf ("Yb        dP w            8 \n" 
            " Yb  db  dP  w 8d8b. d88b 8 \n" 
            "  YbdPYbdP   8 8P Y8 `Yb. ""\n"  
            "   YP  YP    8 8   8 Y88P w \n\n");
}