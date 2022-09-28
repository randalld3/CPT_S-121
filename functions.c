
#include "header.h"

/*
* Name: print_craps ()
* Description: Prints the word 'craps' as an ASCII text banner
* History: Created 02.28.22
* Inputs: None
* Outputs: Big craps
* Returns: None
* Precondition: None
* Postcondition: Function executed
*/
void print_craps(void)
{
	printf("  #####  ######     #    ######   #####  ### \n"
	       " #     # #     #   # #   #     # #     # ### \n"
		   " #       #     #  #   #  #     # #       ### \n"
		   " #       ######  #     # ######   #####   #  \n"
		   " #       #   #   ####### #             #     \n"
		   " #     # #    #  #     # #       #     # ### \n"
		   "  #####  #     # #     # #        #####  ### \n\n");
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
* Name: get_option ()
* Description: Scanf to receive menu option
* History: Created 02.25.22
* Inputs: None
* Outputs: Menu option
* Returns: One integer
* Precondition: None
* Postcondition: Function executed
*/
int get_option(void)
{
	int option = 0;

	scanf("%d", &option);

	return option;
}

/*
* Name: validate_menu_option ()
* Description: Ensures the entered menu option is valid
* History: Created 02.25.22
* Inputs: Menu option
* Outputs: Validated option
* Returns: One integer
* Precondition: None
* Postcondition: Function executed
*/
int validate_menu_option(int option)
{
	while (option < DISPLAY_RULES || option > EXIT)
	{
		display_menu();
		option = get_option();

	}

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
	int exit = 0, death = 0;
	switch (option)
	{
	case DISPLAY_RULES: print_game_rules();
		break;
	case PLAY_GAME:  printf("\nLet's play craps!\n\n");
		break;
	case EXIT: printf("Goodbye"); death = 1 / exit;
		break;
	}
}

/*
* Name: print_game_rules ()
* Description: Prints the rules of craps
* History: Created 02.25.22
* Inputs: None
* Outputs: Rules of craps
* Returns: None
* Precondition: None
* Postcondition: Function executed
*/
void print_game_rules(void)
{
	char dummy = 0.0;

	printf("\nThe rules of craps are as follows:\nA player rolls two dice. Each die has six faces. \n"
		"These faces contain 1, 2, 3, 4, 5, and 6 spots. After the dice have come to rest, \n"
		"the sum of the spots on the two upward faces is calculated. If the sum is 7 or 11 on the first throw, \n"
		"the player wins. If the sum is 2, 3, or 12 on the first throw (called ""craps""), the player loses(i.e.the ""house"" wins).\n"
		"If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's ""point."" \n"
		"To win, you must continue rolling the dice until you ""make your point."" The player loses by rolling a 7 before making the point.\n\n" 
		"You will enter an initial bank balance at the beginning of the game. You must place a wager before the first roll of the dice.\n"
		"If neither the player or the house wins at the end of a turn, the player may choose to double their wager prior to the following turn.\n\n");

	printf("Press any key and enter to start the game\n");
	scanf(" %c", &dummy);
}

/*
* Name: get_bank_balance ()
* Description: prompts and receives initial bank balance
* History: Created 02.25.22
* Inputs: None
* Outputs: bank balance
* Returns: one number (double)
* Precondition: None
* Postcondition: Function executed
*/
double get_bank_balance(void)
{
	double bank_balance = 0;
	while (bank_balance <= 0) // ensures a valid bank balance is entered
	{
		printf("\nEnter your initial bank balance >$");
		scanf("%lf", &bank_balance);
	}

	return bank_balance;
}

/*
* Name: get_wager_amount ()
* Description: prompts the user for a wager
* History: Created 02.25.22
* Inputs: None
* Outputs: wager amount
* Returns: one number (double)
* Precondition: None
* Postcondition: Function executed
*/
double get_wager_amount(void)
{
	double wager = 0.0;

	
	printf("\nPlease enter the amount you would like to wager >$");
	scanf("%lf", &wager);

	while (wager <= 0)
	{
		printf("\nPlease enter a valid amount to wager >$");
		scanf("%lf", &wager);
	}

	return wager;
}

/*
* Name: check_wager_amount ()
* Description: Indicates if wager is too large
* History: Created 02.25.22
* Inputs: wager and bank balance
* Outputs: 1 if wager is less than balance
* Returns: one number (int)
* Precondition: wager and balance must be real numbers
* Postcondition: Function executed
*/
int check_wager_amount(double wager, double balance)
{
	int verify = 0;

	if (wager <= balance)
	{
		verify = 1;
	}
	
	return verify;
}

/*
* Name: roll_die ()
* Description: Rolls a single six-sided die and returns the value
* History: Created 02.25.22
* Inputs: None
* Outputs: Single die value
* Returns: One integer
* Precondition: None
* Postcondition: Function executed
*/
int roll_die(void)
{
	int roll = 0;

	
	roll = rand() % 6 + 1;

	return roll;
}

/*
* Name: print_die ()
* Description: Prints a die using asterisks to match the rolled die value
* History: Created 02.27.22
* Inputs: Die Value
* Outputs: A cool looking die
* Returns: None
* Precondition: Die value must be between 1 and 6
* Postcondition: Function executed
*/
void print_die(int die_value)
{
	switch (die_value)
	{
	case 1: printf("\n\n *\n");
		break;
	case 2: printf("\n  *\n\n*");
		break;
	case 3: printf("\n*\n *\n  *");
		break;
	case 4: printf("\n*  *\n\n*  *");
		break;
	case 5: printf("\n* *\n *\n* *");
		break;
	case 6: printf("\n*  *\n*  *\n*  *");
		break;
	}
}

/*
* Name: calculate_sum_dice ()
* Description: Adds the sum of two dice
* History: Created 02.25.22
* Inputs: Die1 and die2 values
* Outputs: Sum of the dice
* Returns: One integer
* Precondition: None
* Postcondition: Function executed
*/
int calculate_sum_dice(int die1_value, int die2_value)
{
	int sum_dice = 0;

	sum_dice = die1_value + die2_value;

	return sum_dice;
}

/*
* Name: is_win_loss_or_point ()
* Description: determines if the result of the first roll is a win, loss, or push
* History: Created 02.27.22
* Inputs: The sum of the dice
* Outputs: the result of the first roll
* Returns: one number (int)
* Precondition: the sum of the dice must be between 2 and 12
* Postcondition: Function executed
*/
int is_win_loss_or_point(int sum_dice)
{
	int decision = LOSE;

	if (sum_dice == 7 || sum_dice == 11) // win on first roll
	{
		printf("\nYou win!\n");
		decision = WIN;
	}
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12) // loss on first roll
	{
		print_craps();
		decision = LOSE;
	}
	else // push on first roll
	{
		decision = PUSH;
	}

	return decision;
}

/*
* Name: is_point_loss_or_neither ()
* Description: determines if successive rolls are a win, loss, or push
* History: Created 02.27.22
* Inputs: The sum of the dice, the point value from the first roll
* Outputs: the result of a successive roll
* Returns: one number (int)
* Precondition: the sum of the dice and the point value must be between 2 and 12
* Postcondition: Function executed
*/
int is_point_loss_or_neither(int sum_dice, int point_value)
{
	int result = LOSE;

	if (sum_dice == point_value)
	{
		printf("You win!\n");
		result = WIN;
	}
	else if (sum_dice == 7)
	{
		printf("\nYou lose\n");
		result = LOSE;
	}
	else
	{
		result = PUSH;
	}

	return result;
}

/*
* Name: adjust_bank_balance ()
* Description: adjusts the bank balance based off the original balance, wager, and win or loss.
* History: Created 02.27.22
* Inputs: bank balance, wager, int for win or loss
* Outputs: the new bank balance
* Returns: one number (double)
* Precondition: the sum of the dice must be between 2 and 12
* Postcondition: Function executed
*/
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
	double new_balance = 0.0;

	if (add_or_subtract == WIN)
	{
		new_balance = bank_balance + wager_amount;
	}
	else if (add_or_subtract == LOSE)
	{
		new_balance = bank_balance - wager_amount;
	}

	return new_balance;
}

/*
* Name: double_down ()
* Description: Prompts the user for doubling their bet
* History: Created 02.27.22
* Inputs: Bank balance and wager
* Outputs: 1 if the user doubles their bet, 0 otherwise
* Returns: One number (int)
* Precondition: None
* Postcondition: Function executed
*/
int double_down(double bank_balance, double wager)
{
	char choice = 'a';
	int new_wager = 0;

	new_wager = 0;

	printf("\nWould you like to double your wager?\nEnter 'y' for yes, or 'n' for no.\n");
	scanf(" %c", &choice);

	while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') // loop ensures only valid options
	{
		printf("\nPlease enter a valid option >");
		scanf(" %c", &choice);
	}
	if (choice == 'y' || choice == 'Y') // doubles wager if choice was yes
	{
		if (2 * wager > bank_balance) // ensures double down does not exceed bank balance
		{
			printf("\nYou're too broke to double down!\n"); // you cant trick this dealer
		}
		else
		{
			new_wager = 1;
		}
	}

	return new_wager;
}

/*
* Name: chatter_messages ()
* Description: Prints a message based off the number of rolls, current and initial bank balance, and if the player won the last roll
* History: Created 02.28.22
* Inputs: Number of rolls, win loss or push (int), initial bank balance, current bank balance
* Outputs: Messages to make the game more interesting!
* Returns: None
* Precondition: None
* Postcondition: Function executed
*/
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{
	if (current_bank_balance > LOSE)
	{
		if (number_rolls > 0 && number_rolls < 10)
		{
			if (win_loss_neither == PUSH)
			{
				printf("\nKeep it pushing, on to the next roll!\n");
			}
			else if (win_loss_neither == LOSE)
			{
				if (current_bank_balance > initial_bank_balance)
				{
					printf("\nIt's an early loss, but you're still ahead...\n");
				}
				else
				{
					printf("\nIt looks like you're off to a rough start!\n");
				}
			}
			else if (win_loss_neither == WIN)
			{
				if (current_bank_balance > initial_bank_balance)
				{
					printf("\nI see you're building your wealth fast!\n");
				}
				else
				{
					printf("\nThere you go! You're still in it!\n");
				}
			}
		}
		else if (number_rolls > 9 && number_rolls < 20)
		{
			if (win_loss_neither == LOSE)
			{
				if (current_bank_balance > initial_bank_balance)
				{
					printf("\nThat's ok! You're still doing great!\n");
				}
				else
				{
					printf("\nYou're going for broke, huh?\n");
				}
			}
			else if (win_loss_neither == WIN)
			{
				if (current_bank_balance > initial_bank_balance)
				{
					printf("\nAnother big win for the big winner!\n");
				}
				else
				{
					printf("\nOne win won't recover your losses. It's time to go big or go home.\n");
				}
			}
		}
		else if (number_rolls > 19)
		{
			if (win_loss_neither == WIN)
			{
				if (current_bank_balance > initial_bank_balance)
				{
					printf( "WWWWWWWW                           WWWWWWWWIIIIIIIIIINNNNNNNN        NNNNNNNNNNNNNNNN        NNNNNNNNEEEEEEEEEEEEEEEEEEEEEERRRRRRRRRRRRRRRRR\n"   
                            "W::::::W                           W::::::WI::::::::IN:::::::N       N::::::NN:::::::N       N::::::NE::::::::::::::::::::ER::::::::::::::::R\n"
                            "W::::::W                           W::::::WI::::::::IN::::::::N      N::::::NN::::::::N      N::::::NE::::::::::::::::::::ER::::::RRRRRR:::::R\n"
                            "W::::::W                           W::::::WII::::::IIN:::::::::N     N::::::NN:::::::::N     N::::::NEE::::::EEEEEEEEE::::ERR:::::R     R:::::R\n"
                            " W:::::W           WWWWW           W:::::W   I::::I  N::::::::::N    N::::::NN::::::::::N    N::::::N  E:::::E       EEEEEE  R::::R     R:::::R\n"
                            "  W:::::W         W:::::W         W:::::W    I::::I  N:::::::::::N   N::::::NN:::::::::::N   N::::::N  E:::::E               R::::R     R:::::R\n"
                            "   W:::::W       W:::::::W       W:::::W     I::::I  N:::::::N::::N  N::::::NN:::::::N::::N  N::::::N  E::::::EEEEEEEEEE     R::::RRRRRR:::::R\n"
                            "    W:::::W     W:::::::::W     W:::::W      I::::I  N::::::N N::::N N::::::NN::::::N N::::N N::::::N  E:::::::::::::::E     R:::::::::::::RR\n"
                            "     W:::::W   W:::::W:::::W   W:::::W       I::::I  N::::::N  N::::N:::::::NN::::::N  N::::N:::::::N  E:::::::::::::::E     R::::RRRRRR:::::R\n"
                            "      W:::::W W:::::W W:::::W W:::::W        I::::I  N::::::N   N:::::::::::NN::::::N   N:::::::::::N  E::::::EEEEEEEEEE     R::::R     R:::::R\n"
                            "       W:::::W:::::W   W:::::W:::::W         I::::I  N::::::N    N::::::::::NN::::::N    N::::::::::N  E:::::E               R::::R     R:::::R\n"
                            "        W:::::::::W     W:::::::::W          I::::I  N::::::N     N:::::::::NN::::::N     N:::::::::N  E:::::E       EEEEEE  R::::R     R:::::R\n"
                            "         W:::::::W       W:::::::W         II::::::IIN::::::N      N::::::::NN::::::N      N::::::::NEE::::::EEEEEEEE:::::ERR:::::R     R:::::R\n"
                            "          W:::::W         W:::::W          I::::::::IN::::::N       N:::::::NN::::::N       N:::::::NE::::::::::::::::::::ER::::::R     R:::::R\n"
                            "           W:::W           W:::W           I::::::::IN::::::N        N::::::NN::::::N        N::::::NE::::::::::::::::::::ER::::::R     R:::::R\n"
                            "            WWW             WWW            IIIIIIIIIINNNNNNNN         NNNNNNNNNNNNNNN         NNNNNNNEEEEEEEEEEEEEEEEEEEEEERRRRRRRR     RRRRRRR\n");
				}
				else
				{
					printf("\nCongrats on your win. You're still broke.\n");
				}
			}
			else if (win_loss_neither == LOSE)
			{
				if (current_bank_balance > initial_bank_balance)
				{
					printf("\nYou had to lose one eventually, right?\n");
				}
				else
				{
					printf("\nWhat's next, your car or your house?\n");
				}
			}
		}
	}
}
