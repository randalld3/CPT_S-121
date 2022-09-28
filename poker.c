/*
* Author: RAD
* Instructor: AOFallen
* Class: Cpt_S 121
* Section: 08L
* Assignment: PA7 (poker)
* Date Submitted: 4/21/22
*/

#include "poker.h"

/*
* Name: main_menu ()
* Description: Prints main menu for poker. Allows for user to view rules, play game, or exit based on input. 
               Guards against menu input outside of 1-3.
* History: Created 04.17.22
* Inputs: None
* Outputs: Menu options and text
* Returns: None
* Precondition: None
* Postcondition: Program will enter game loop, or will exit.
*/
void main_menu(void)
{
	int option = 0;

	do
	{
		printf("Main Menu\n\n1. Game Rules\n2. Play Game\n3. Exit\n");
		do
		{
			scanf("%d", &option);
		} while (option < 0 || option > 3);

		if (option == 3)
		{ exit(0); }
		else if (option == 1)
		{
			printf("The rules of poker: You will play as player 1. The computer will act as the dealer and Player 2.\n"
				"The dealer will shuffle the cards and show the deck has been shuffled. Five cards will be drawn\n"
			    "for both the player and the dealer. Both you and the dealer may select three cards to be discarded,\n"
			    "and those cards will be replaced with remaining cards from the deck. Your hand is then compared\n"
			    "against the dealer's, and the winner is announced. Hands are ranked as follows:\n\n"
			    "Straight Flush > Four of a Kind > Full House > Flush > Straight > Three of a kind > \n"
			    "Two Pair > One Pair > High Card\n\n");
			system("pause");
		}
		system("cls");
	} while (option != 2);
}



/*
* Name: shuffle ()
* Description: Randomizes the deck array so that a random card may be drawn as the deck is indexed.
* History: Created 04.17.22. Code taken from book J.R. Hanly & E.B. Koffman, Problem Solving & Program 
           Design in C (8th ed.), Pearson Education, Inc., 2016. ISBN: 9780134014890
* Inputs: 2D deck array
* Outputs: A randomized deck
* Returns: None
* Precondition: Deck must be initialized to all 0s
* Postcondition: Deck[][] will contain random numbers 1-52 throughout.
*/
void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/*
* Name: deal ()
* Description: Prints the randomized deck, demonstrating a dealer  fanning out cards
* History: Created 04.17.22. Code taken from book J.R. Hanly & E.B. Koffman, Problem Solving & Program
		   Design in C (8th ed.), Pearson Education, Inc., 2016. ISBN: 9780134014890
* Inputs: deck[][], face[] (a constant array of strings with face values to associate with integers from deck array),
          suit[] (the same as face but for suits[].
* Outputs: All cards of the deck printed
* Returns: None
* Precondition: None
* Postcondition: None
*/
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	printf("\tThe dealer shuffles the deck\n");
	/* deal each of the 52 cards */
	for (card = 1; card <= 52; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{ printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t'); }
			}
		}
	}
}

/*
* Name: deal_hand ()
* Description: Picks random undealt cards in the deck and enters the face and suit into a players hand. 
*              Cards needing re-deal are controlled by re_deal array input.
* History: Created 04.17.22
* Inputs: player_hand (Hand), deck[][], re_deal[]
* Outputs: A poker hand
* Returns: None
* Precondition: Deck must have remaining cards for re-deal.
* Postcondition: New cards will be in player_hand if any cards were listed for re-deal.
*/
void deal_hand(Hand* player_hand, int deck[][13], int re_deal[])
{
	int row = 0, column = 0, index = 0;

	for (index = 1; index < 6; ++index) // searches re_deal for 1s, these indicate a card needing re-deal
	{
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (deck[row][column] == 0); // loops through deck[][] until an unused card is found

		if (re_deal[index] == 1) //uses row/column to save face and suit to player struct
		{
			player_hand->cards[index].suit = row;
			player_hand->cards[index].face = column;
			deck[row][column] = 0; // prevents re-use of the same card
			re_deal[index] = 0; // reset re_deal
		}
	}
}

/*
* Name: display_hand ()
* Description: Code modified from deal (). Will display cards of a players hand, or "face-down" cards if int show = 2.
* History: Created 04.17.22
* Inputs: player_hand (Hand), face[], suit[], show (determines how card will look when dealt.
* Outputs: printed hand of cards
* Returns: None
* Precondition: None
* Postcondition: None
*/
void display_hand(Hand* player_hand, const char* face[], const char* suit[], int show)
{
	int card_suit = 0, card_face = 0;
	
	card_suit = player_hand->cards[1].suit;
	card_face = player_hand->cards[1].face;

	if (show == 1) // shows all cards of the hand
	{
		printf("Hand:\n     Card 1:\t\t    Card 2:\n%5s of %-8s\t%5s of %-8s\n     Card 3:\t\t    Card 4: \n%5s of %-8s\t%5s of %-8s\n     Card 5:\n%5s of %-8s\n\n",
			face[player_hand->cards[1].face], suit[player_hand->cards[1].suit],
			face[player_hand->cards[2].face], suit[player_hand->cards[2].suit], 
			face[player_hand->cards[3].face], suit[player_hand->cards[3].suit], 
			face[player_hand->cards[4].face], suit[player_hand->cards[4].suit], 
			face[player_hand->cards[5].face], suit[player_hand->cards[5].suit]);
	}
	else
	{
		printf("The dealer deals his cards face-down on the table:\n");
		printf("     Card 1:\t\t    Card 2:\n   *** of ***\t\t  *** of ***\n     Card 3:\t\t    Card 4: \n   "
			"*** of ***\t\t  *** of ***\n     Card 5: \n   *** of ***\n\n");
	}
}

/*
* Name: which_cards ()
* Description: prompts user and collects card #s the user would like re-dealt
* History: Created 04.17.22
* Inputs: int re_deal[] (each index corresponds to a card number 1-5)
* Outputs: 1s for cards needing re-deal in re_deal[]
* Returns: None
* Precondition: re_ceal must be set to 0s
* Postcondition: re_deal will contain cards to be re-dealt.
*/
void which_cards(int re_deal[])
{
	int num_cards = 0, card_number = 0;

	do
	{
		printf("Enter the number of cards you would like to exchange\n");
		scanf("%d", &num_cards);
	} while (num_cards < 0 || num_cards > 3);

	while (num_cards > 0)
	{
		printf("Enter a card # that you would like to exchange\n");
		scanf("%d", &card_number);
		if (card_number < 1 || card_number > 5)
		{
			printf("Invalid card number!\n");
			++num_cards; // adds extra iteration of do-while loop
		}
		if (re_deal[card_number] == 1)
		{
			printf("You've already entered that card number!\n");
			++num_cards;
		}
		else 
		{ ++re_deal[card_number]; }
		--num_cards;
	}
}

/*
* Name: reset_re_deal ()
* Description: Sets all indices of re_deal to 1, necessary for a new hand of cards
* History: Created 04.17.22
* Inputs: re_deal[]
* Outputs: a few 1s
* Returns: None
* Precondition: None
* Postcondition: re_deal will contain only 1s.
*/
void reset_re_deal(int re_deal[])
{
	int index = 1;

	for (; index < 6; ++index)
	{ re_deal[index] = 1; }
}

/*
* Name: dealers_choice ()
* Description: Uses logic to determine what the "smartest" move for the dealer is. Pairs with functions for 
*              determining if the dealer has a specific hand (like full house).
* History: Created 04.17.22
* Inputs: p2_hand, re_deal[], num_faces, num_suits[]
* Outputs: cards for re_deal
* Returns: None
* Precondition: count_the_faces() and count_the_suits() must have been completed prior to running function.
* Postcondition: re_deal will contain cards for re-deal.
*/
void dealers_choice(Hand* p2_hand, int re_deal[], int num_faces[], int num_suits[])
{
	int smart_dealer = 0, index = 0, try_flush = 0, card1 = -1, card2 = -1, card3 = -1;

	smart_dealer = is_full_house(num_faces) + is_straight(num_faces) + is_flush(num_suits) + is_four_of_a_kind(num_faces);

	if (!smart_dealer) // cards will need to be exchanged
	{
		for (index = 0; index < 4; ++index) // loop to check if dealer should try for flush
		{
			if (num_suits[index] == 4)
			{ try_flush = 1; }
		}
		// smart_dealer = is_three_of_a_kind(num_faces);
		if (is_three_of_a_kind(num_faces)) // dealing with 3 of a kind
		{
			for (index = 0; index < 14; ++index) // index looking for cards to be replaced
			{
				if (num_faces[index] == 1 && card1 == -1)
				{ card1 = index; }
				else if (num_faces[index] == 1 && card1 != -1)
				{ card2 = index; }
			}
			for (index = 1; index < 6; ++index) // index searching dealers hand for card # to be replaced.
			{
				if (p2_hand->cards[index].face == card1 || p2_hand->cards[index].face == card2)
				{ ++re_deal[index]; }
			}
		}
		else if (is_two_pair(num_faces)) // dealing with two pair
		{
			for (index = 0; index < 14; ++index) // index looking for card to be replaced
			{
				if (num_faces[index] == 1)
				{ card1 = index; }
			}
			for (index = 1; index < 6; ++index) // index searching dealers hand for card # to be replaced.
			{
				if (p2_hand->cards[index].face == card1)
				{ ++re_deal[index]; }
			}
		}
		else if (is_pair(num_faces))
		{
			for (index = 0; index < 14; ++index) // index looking for cards to be replaced
			{
				if (num_faces[index] == 1 && card1 == -1)
				{ card1 = index; }
				else if (num_faces[index] == 1 && card2 == -1)
				{ card2 = index; }
				else if (num_faces[index] == 1 && card3 == -1)
				{ card3 = index; }
			}
			for (index = 1; index < 6; ++index) // index searching dealers hand for card # to be replaced.
			{
				if (p2_hand->cards[index].face == card1 || p2_hand->cards[index].face == card2 || p2_hand->cards[index].face == card3)
				{ ++re_deal[index]; }
			}
		}
		else if (try_flush) // try for flush
		{
			for (index = 0; index < 4; ++index)
			{
				if (num_suits[index] == 1) // indicating card to be replaced
				{ card1 = index; }
				for (index = 1; index < 6; ++index)
				{
					if (p2_hand->cards[index].suit == card1)
					{ ++re_deal[index]; }
				}
			}
		}
		else // exchange the lowest 3 cards
		{
			for (index = 13; index >= 0; --index) // identifies highest two cards
			{
				if (card1 == -1)
				{
					if (num_faces[index] == 1)
					{ card1 = index; }
				}
				else if (card2 == -1)
				{
					if (num_faces[index] == 1)
					{ card2 = index; }
				}
			}
			for (index = 1; index < 6; ++index)
			{
				if (p2_hand->cards[index].face != card1 && p2_hand->cards[index].face != card2)
				{ ++re_deal[index]; }
			}
		}
	}
}

/*
* Name: reset_deck ()
* Description: Sets all values of deck to 0 so that shuffle() can be ran.
* History: Created 04.17.22
* Inputs: deck[]
* Outputs: a whole lof of 0s
* Returns: None
* Precondition: None
* Postcondition: Deck will be reset.
*/
void reset_deck(int deck[][13])
{
	int row_index = 0, col_index = 0;

	for (; row_index < 4; ++row_index)
	{
		for (col_index = 0; col_index < 13; ++col_index)
		{ deck[row_index][col_index] = 0; }
	}
}

/*
* Name: play_again ()
* Description: Prompts user to see if they would like to play again.
* History: Created 04.17.22
* Inputs: None
* Outputs: 1 if the user wants to play again.
* Returns: One integer
* Precondition: None
* Postcondition: Game will either re-enter game loop or exit.
*/
int play_again(void)
{
	char choice = 'a';
	int option = 0;

	printf("Would you like to play again? Enter 'y' for yes\n");
	scanf(" %c", &choice);

	if (choice == 'y' || choice == 'Y')
	{ option = 1; }
	system("cls");
	return option;
}



/*
* Name: count_the_faces ()
* Description: Resets num_faces, and fills it in with values from player_hand. num_faces[] is a counting
*              array that is primarily used for is_hand functions.
* History: Created 04.17.22
* Inputs: player_hand, num_faces[]
* Outputs: num_faces[] filled in with player card faces.
* Returns: None
* Precondition: None
* Postcondition: num_faces[] will be usable for is_hand functions.
*/
void count_the_faces(Hand* player_hand, int num_faces[])
{
	int index = 0, card = 0;

	for (; index < 14; ++ index) // resets num_faces[]
	{ num_faces[index] = 0; }

	for (index = 1; index < 6; ++index)
	{ ++num_faces[player_hand->cards[index].face]; }

	num_faces[13] = num_faces[0]; // makes ace low & high
	if (num_faces[0] > 1) // prevents two pair of low and high aces
	{ num_faces[0] = 1; }
}

/*
* Name: count_the_suits ()
* Description: Resets num_suits[], and fills it in with values from player_hand. num_suits[] is a counting
*              array that is primarily used for is_hand functions.
* History: Created 04.17.22
* Inputs: player_hand, num_suits[]
* Outputs: num_suits[] filled in with player card faces.
* Returns: None
* Precondition: None
* Postcondition: num_suits[] will be usable for is_hand functions.
*/
void count_the_suits(Hand* player_hand, int num_suits[])
{
	int index = 0, card = 0;

	for (; index < 4; ++ index) // resets num_suits[]
	{ num_suits[index] = 0; }

	for (index = 1; index < 6; ++index)
	{ ++num_suits[player_hand->cards[index].suit]; }
}

/* ***All is_"hand" functions have a similar description***
* Name: is_"hand" ()
* Description: Determines if a specific hand, such as full house, is present in a players hand.
* History: Created 04.17.22
* Inputs: num_faces[], num_suits (for is_flush)
* Outputs: 1 if a full house is present, 0 otherwise.
* Returns: One integer
* Precondition: None
* Postcondition: None
*/
int is_full_house(int num_faces[])
{
	int index = 0, full_house = 0;

	for (; index < 14; ++index)
	{
		if (num_faces[index] == 3)
		{
			for (index = 0; index < 14; ++index)
			{
				if (num_faces[index] == 2)
				{ full_house = 1; }
			}
		}
	}
	return full_house;
}
int is_straight(int num_faces[])
{
	int index = 0, counter = 0, straight = 0;

	for (; index < 14; ++index)
	{
		if (num_faces[index] == 1)
		{ ++counter; }
		else
		{ counter = 0; }
		if (counter == 5)
		{ straight = 1; }
	}
	return straight;
}
int is_flush(int num_suits[])
{
	int index = 0, flush = 0;

	for (; index < 4; ++index)
	{
		if (num_suits[index] == 5)
		{ flush = 1; }
	}
	return flush;
}
int is_four_of_a_kind(int num_faces[])
{
	int index = 0, foak = 0;

	for (; index < 14; ++index)
	{
		if (num_faces[index] == 4)
		{ foak = 1; }
	}
	return foak;
}
int is_three_of_a_kind(int num_faces[])
{
	int index = 0, toak = 0;

	for (; index < 14; ++index)
	{
		if (num_faces[index] == 3)
		{ toak = 1; }
	}
	return toak;
}
int is_two_pair(int num_faces[])
{
	int index = 0, pair1 = 0, pair2 = 0, two_pair = 0;

	for (; index < 14; ++index)
	{
		if (num_faces[index] == 2 && pair1 == 0)
		{ pair1 = 1; }
		else if (num_faces[index] == 2 && pair1 == 1)
		{ pair2 = 1; }
	}
	if (pair1 == 1 && pair2 == 1)
	{ two_pair = 1; }

	return two_pair;
}
int is_pair(int num_faces[])
{
	int index = 0, pair = 0;

	for (; index < 14; ++index)
	{
		if (num_faces[index] == 2)
		{ pair = 1; }
	}
	return pair;
}

/*
* Name: compare_hands ()
* Description: Reads in counting arrays num_faces[] and num_suits[] for both players, and determines the better 
*              poker hand. Initiates tie-breaker function if two players have the same type of hand (pair,
*              high card, etc).
* History: Created 04.18.22
* Inputs: p1_num_faces[], p1_num_suits[], p2_num_faces[], p2_num_suits[]
* Outputs: 1 if player 1 wins, 2 for player 2, 0 otherwise.
* Returns: One integer
* Precondition: None
* Postcondition: None
*/
int compare_hands(int p1_num_faces[], int p1_num_suits[], int p2_num_faces[], int p2_num_suits[])
{
	int index = 0, p1_score = 0, p2_score = 0, winner = 0;
	
    if (is_flush(p1_num_suits))
	{ p1_score += 5; }
	if (is_straight(p1_num_faces))
	{ p1_score += 4; }
	if (is_four_of_a_kind(p1_num_faces))
	{ p1_score = 7; }
	else if (is_full_house(p1_num_faces))
	{ p1_score = 6; }
	else if (is_three_of_a_kind(p1_num_faces))
	{ p1_score = 3; }
	else if (is_two_pair(p1_num_faces))
	{ p1_score = 2; }
	else if (is_pair(p1_num_faces))
	{ p1_score = 1; }

    if (is_flush(p2_num_suits))
	{ p2_score += 5; }
	if (is_straight(p2_num_faces))
	{ p2_score += 4; }
	if (is_four_of_a_kind(p2_num_faces))
	{ p2_score = 7; }
	else if (is_full_house(p2_num_faces))
	{ p2_score = 6; }
	else if (is_three_of_a_kind(p2_num_faces))
	{ p2_score = 3; }
	else if (is_two_pair(p2_num_faces))
	{ p2_score = 2; }
	else if (is_pair(p2_num_faces))
	{ p2_score = 1; }

	if (p1_score == p2_score)
	{ winner = tie_breaker(p1_num_faces, p2_num_faces); }
	else if (p1_score > p2_score)
	{ winner = 1; }
	else if (p2_score > p1_score)
	{ winner = 2; }
	return winner;
}

/*
* Name: tie_breaker ()
* Description: Determines a winner in the event player 1 and player 2 have the same type of hand. Not very smart
*              though, as it was stated that extensive logic was not needed, so it determines the winner in
*              the normal fashion of two high-card hands.
* History: Created 04.18.22
* Inputs: p1_num_faces[], p2_num_faces[]
* Outputs: 1 if p1 wins, 2 if p2 wins, 0 otherwise.
* Returns: One integer
* Precondition: None
* Postcondition: None
*/
int tie_breaker(int p1_num_faces[], int p2_num_faces[])
{
	int winner = 0, index = 0;

	for (index = 13; index >= 0; --index)
	{
		if (winner == 0)
		{
			if (p1_num_faces[index] > p2_num_faces[index])
			{ winner = 1; }
			else if (p2_num_faces[index] > p1_num_faces[index])
			{ winner = 2; }
		}
	}
	return winner;
}