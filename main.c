/*
* Author: RAD
* Instructor: AOFallen
* Class: Cpt_S 121
* Section: 08L
* Assignment: PA7 (poker)
* Date Submitted: 4/21/22
*/

#include "poker.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 }, re_deal[6] = { 0 }, quit = 0, winner = 0;
	int p1_num_faces[14] = { 0 }, p1_num_suits[4] = { 0 }, p2_num_faces[14] = { 0 }, p2_num_suits[4] = { 0 };

	Hand p1_hand, p2_hand;

	srand((unsigned)time(NULL)); /* seed random-number generator */
	main_menu();

	do
	{
		shuffle(deck);
		deal(deck, face, suit);
		system("pause");
		system("cls");
		reset_re_deal(re_deal);
		deal_hand(&p1_hand, deck, re_deal);
		reset_re_deal(re_deal);
		deal_hand(&p2_hand, deck, re_deal);
		display_hand(&p1_hand, face, suit, 1);
		display_hand(&p2_hand, face, suit, 2);
		which_cards(re_deal);
		system("pause");
		system("cls");
		deal_hand(&p1_hand, deck, re_deal);
		display_hand(&p1_hand, face, suit, 1);
		count_the_faces(&p1_hand, p1_num_faces);
		count_the_suits(&p1_hand, p1_num_suits);
		count_the_faces(&p2_hand, p2_num_faces);
		count_the_suits(&p2_hand, p2_num_suits);
		dealers_choice(&p2_hand, re_deal, p2_num_faces, p2_num_suits);
		deal_hand(&p2_hand, deck, re_deal);
		count_the_faces(&p2_hand, p2_num_faces);
		count_the_suits(&p2_hand, p2_num_suits);
		printf("The dealer turns over his cards\n\n");
		display_hand(&p2_hand, face, suit, 1);
		winner = compare_hands(p1_num_faces, p1_num_suits, p2_num_faces, p2_num_suits);
		printf("The winner is Player %d\n\n", winner);
		system("pause");
		system("cls");
		reset_deck(deck);
		quit = play_again();

	} while ( quit == 1);

	return 0;
}




