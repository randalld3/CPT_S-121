/*
* Author: RAD
* Instructor: AOFallen
* Class: Cpt_S 121
* Section: 08L
* Assignment: PA7 (poker)
* Date Submitted: 4/21/22
*/

#ifndef POKER_H
#define POKER_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define HEARTS 0
#define DIAMONDS 1
#define CLUBS 2
#define SPADES 3

typedef struct card
{
	int face;
    int suit;
}Card;

typedef struct hand
{
	Card cards[6];
}Hand;

void main_menu(void);
void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[]);
void deal_hand(Hand* player_hand, int deck[][13], int re_deal[]);
void display_hand(Hand* player_hand, const char* face[], const char* suit[], int show);
void which_cards(int re_deal[]);
void reset_re_deal(int re_deal[]);
void dealers_choice(Hand* p2_hand, int re_deal[], int num_faces[], int num_suits[]);
void reset_deck(int deck[][13]);
int play_again(void);

void count_the_faces(Hand* player_hand, int num_faces[]);
void count_the_suits(Hand* player_hand, int num_suits[]);
int is_full_house(int num_faces[]);
int is_straight(int num_faces[]);
int is_flush(int num_suits[]);
int is_four_of_a_kind(int num_faces[]);
int is_three_of_a_kind(int num_faces[]);
int is_two_pair(int num_faces[]);
int is_pair(int num_faces[]);
int compare_hands(int p1_num_faces[], int p1_num_suits[], int p2_num_faces[], int p2_num_suits[]);
int tie_breaker(int p1_num_faces[], int p2_num_faces[]);

#endif