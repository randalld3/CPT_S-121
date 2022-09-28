/* Author: Randall Dickinson
*  Class: Cpt_S 121
*  Instructor: AOFallen
*  Section: 01
*  Assignment: PA5
*  Date Completed: 03.22.22
*/

#ifndef YAHTZEE_H
#define YAHTZEE_H
#define _CRT_SECURE_NO_WARNINGS

#define DISPLAY_RULES 1
#define PLAY_GAME 2
#define EXIT 3


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_yahtzee(void);
void display_menu(void);
int get_int_option(void);
void process_option(int option);
void print_game_rules(void);

void print_player_one(void);
void print_player_two(void);
void initial_dice_roll(int arr_dice[]);
void print_dice(int arr_dice[], int rolls, int round);

char choose_to_score(void);
void dice_to_re_roll(int arr_re_roll[]);
void sequential_roll(int arr_dice[], int arr_re_roll[]);
void reset_arr_re_roll(int arr_re_roll[]);
void sum_of_the_faces(int arr_dice[], int arr_num_dice[]);
int score_option(int scorecard[]);
void process_score_option(int option, int arr_num_dice[], int scorecard[]);

void score_1s(int arr_num_dice[], int scorecard[]);
void score_2s(int arr_num_dice[], int scorecard[]);
void score_3s(int arr_num_dice[], int scorecard[]);
void score_4s(int arr_num_dice[], int scorecard[]);
void score_5s(int arr_num_dice[], int scorecard[]);
void score_6s(int arr_num_dice[], int scorecard[]);
void score_three_of_a_kind(int arr_num_dice[], int scorecard[]);
void score_four_of_a_kind(int arr_num_dice[], int scorecard[]);
void score_full_house(int arr_num_dice[], int scorecard[]);
void score_small_straight(int arr_num_dice[], int scorecard[]);
void score_large_straight(int arr_num_dice[], int scorecard[]);
void score_yahtzee(int arr_num_dice[], int scorecard[]);
void score_chance(int arr_num_dice[], int scorecard[]);

void sum_scores(int scorecard[], int* total_score);
void print_wins(void);

#endif