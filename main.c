
#include "battleship.h"

int main(void)
{
	FILE* infile = fopen("battleship.log", "w");
	char player1_gb[10][10], player2_gb[10][10], shot[3] = "";
	char choice = 'a', ship_sunk = 'a';
	int player_turn = 0, hit_or_miss = 0, win_or_lose = 0, sink_or_swim = 0, winner = 0, player = 0,
		player1_hits = 0, player1_shots = 0, player1_misses = 0, 
		player2_hits = 0, player2_shots = 0, player2_misses = 0;
	Stats p1_stats = { 0, 0, 0, 0.0 }, p2_stats = { 0, 0, 0, 0.0 };

	srand((unsigned int)time(NULL));
	welcome_screen();
	initialize_game_board(player1_gb);
	initialize_game_board(player2_gb);
	choice = random_or_manual();

	if (choice == 'm')
	{ manually_place_ships_on_board(player1_gb); }
	else
	{ randomly_place_ships_on_board(player1_gb); }

	randomly_place_ships_on_board(player2_gb);
	player_turn = select_who_starts_first();
	printf("Player 1, here is your game board:\n\n");
	display_board(player1_gb, 1);
	system("pause");
	system("cls");
	
	do
	{
		if (player_turn % 2 == 1)
		{
			display_board(player2_gb, 2);
			get_shot(player2_gb, shot, &player1_shots);
			system("cls");
			hit_or_miss = check_shot(player2_gb, shot, &player1_hits, &player1_misses);
			sink_or_swim = check_if_sunk_ship(player2_gb, shot, &ship_sunk);
			update_stats(&p1_stats, hit_or_miss);
			print_round_stats(shot, hit_or_miss, sink_or_swim, player_turn, &infile, ship_sunk);
			update_board(player2_gb, shot);
			display_board(player2_gb, 2);
			win_or_lose = is_winner(player2_gb);
			
		}
		else
		{
			random_shot(player1_gb, shot, &player2_shots);
			printf("Player 2 shoots %d %d!\n", shot[0] - ASCII, shot[1] - ASCII);
			hit_or_miss = check_shot(player1_gb, shot, &player2_hits, &player2_misses);
			sink_or_swim = check_if_sunk_ship(player1_gb, shot, &ship_sunk);
			update_stats(&p2_stats, hit_or_miss);
			print_round_stats(shot, hit_or_miss, sink_or_swim, player_turn, &infile, ship_sunk);
			update_board(player1_gb, shot);
			display_board(player1_gb, 1);
			win_or_lose = is_winner(player1_gb);
		}

		system("pause");
		system("cls");
		++player_turn;
	} while (win_or_lose == 0);

	winner = determine_winner(player_turn);
    printf("Player %d wins!", winner);
	print_final_stats(&infile, &p1_stats, &p2_stats, winner);
	fclose(infile);

	return 0;
}