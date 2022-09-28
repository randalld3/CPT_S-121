/* Author: Randall Dickinson
*  Class: Cpt_S 121
*  Instructor: AOFallen
*  Section: 01
*  Assignment: PA5
*  Date Completed: 03.22.22
*/

#include "yahtzee.h"

int main(void)
{
	int arr_dice[6] = { 0 }, arr_re_roll[6] = { 0 }, arr_num_dice[7] = { 0 }; // arr_dice stores the values of the five dice, arr_re_roll stores which dice will be re-rolled, and arr_num_dice stores the values of how many times each dice number (1-6) occurs.
	int scorecard_p1[13] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; // all values initialized to -1 to indicate they are empty until they are scored.
	int scorecard_p2[13] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	
	char score_choice = 'n';

	int menu_option = 0, round = 0, rolls = 0, scorecard_option = 0, score_p1 = 0, score_p2 = 0;

	srand((unsigned int)time(NULL));

	print_yahtzee();
	system("pause");
	system("cls");

	for (menu_option = 0; menu_option != 3;) 
	{
		display_menu();
		menu_option = get_int_option();
		process_option(menu_option);
		system("cls");
		
		if (menu_option == 2) // beginning of game loop
		{
			while (round < 26)
			{
				++round;
				if (round % 2 == 1)
				{
					print_player_one();
				}
				else
				{
					print_player_two();
				}
				system("pause");
				system("cls");

				for (rolls = 1; rolls <= 3; ++rolls) 
				{
					if (rolls == 1)
					{
						initial_dice_roll(arr_dice);
					}
					else // 2nd and 3rd rolls for a player
					{
						dice_to_re_roll(arr_re_roll);
						system("pause");
						system("cls");
						sequential_roll(arr_dice, arr_re_roll);
					}

					reset_arr_re_roll(arr_re_roll); // array must be reset between rolls
					print_dice(arr_dice, rolls, round);
					score_choice = choose_to_score();

					if (score_choice == 'y' || score_choice == 'Y' || rolls == 3) // beginning of scoring loop
					{
						sum_of_the_faces(arr_dice, arr_num_dice); // fills in arr_num_dice

						if (round % 2 == 1) // decides which player and option to score and applies scoring functions
						{
							scorecard_option = score_option(scorecard_p1);
							process_score_option(scorecard_option, arr_num_dice, scorecard_p1);
							rolls = 3;
						}
						else
						{
							scorecard_option = score_option(scorecard_p2);
							process_score_option(scorecard_option, arr_num_dice, scorecard_p2);
							rolls = 3;
						}
					}
				}
			}

			system("cls"); // beginning of endgame
			printf("Let's tally up those scores!\n");
			sum_scores(scorecard_p1, &score_p1);
			sum_scores(scorecard_p2, &score_p2);
			system("pause");
			system("cls");

			printf("Player 1: %d\n\nPlayer2: %d\n\n", score_p1, score_p2);
			if (score_p1 > score_p2)
			{
				print_player_one();
			}
			else
			{
				print_player_two();
			}
			print_wins();
			system("pause");
			system("cls");
		}
	}
	return 0;
}