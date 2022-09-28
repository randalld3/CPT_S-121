
#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DISPLAY_RULES 1
#define PLAY_GAME 2
#define EXIT 3
#define PUSH -1
#define LOSE 0
#define WIN 1

void print_craps(void);
void display_menu(void);
int get_option(void);
int validate_menu_option(int option);
void process_option(int option);
void print_game_rules(void);

double get_bank_balance(void);
double get_wager_amount(void);
int check_wager_amount(double wager, double balance);

int roll_die(void);
void print_die(int die_value);
int calculate_sum_dice(int die1_value, int die2_value);

int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);
int double_down(double bank_balance, double wager);
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);

#endif
