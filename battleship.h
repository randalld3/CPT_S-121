
#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#define _CRT_SECURE_NO_WARNINGS

#define ASCII 48
#define MAX_ROWS 10
#define MAX_COLS 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct stats
{
	int num_hits; 
	int num_misses; 
	int num_shots; 
	double hits_to_misses_ratio;
	char won_or_lost; 
} Stats;

void welcome_screen(void);
void initialize_game_board(char game_board[MAX_ROWS][MAX_COLS]);
char random_or_manual(void);
void manually_place_ships_on_board(char player1_gb[MAX_ROWS][MAX_COLS]);
int validate_boat_placement(char player_gb[MAX_ROWS][MAX_COLS], char boat);
void randomly_place_ships_on_board(char player_gb[MAX_ROWS][MAX_COLS]);
int select_who_starts_first(void);
void display_board(char player_gb[MAX_ROWS][MAX_COLS], int player);

void get_shot(char player_gb[MAX_ROWS][MAX_COLS], char shot[]);
int check_shot(char player_gb[MAX_ROWS][MAX_COLS], char shot[]);
void random_shot(char player1_gb[MAX_ROWS][MAX_COLS], char shot[]);
void update_board(char player_gb[MAX_ROWS][MAX_COLS], char shot[]);
int is_winner(char player_gb[MAX_ROWS][MAX_COLS]);
int check_if_sunk_ship(char player_gb[MAX_ROWS][MAX_COLS], char shot[], char* ship_sunk);
void update_stats(Stats* player_stats_ptr, int hit_or_miss);
void print_round_stats(char shot[], int hit_or_miss, int sink_or_swim, int player_turn, FILE **infile, char ship_sunk);

int determine_winner(int player_turn);
void print_final_stats(FILE** infile, Stats* p1_stats, Stats* p2_stats, int winner);


#endif

