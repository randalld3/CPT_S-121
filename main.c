
#include "header.h"

int main(void)
{
	double bank_balance = 0.0, wager = 0.0, initial_bank_balance;

	int menu_option = 0, verify = 0, die1 = 0, die2 = 0, point = 0, sum_dice = 0, win_or_lose = 0, decision = 0, number_rolls = 0;

	srand((unsigned int)time(NULL));

	print_craps(); // start of main menu
	display_menu();
	menu_option = get_option();
	menu_option = validate_menu_option(menu_option);
    process_option(menu_option);

	initial_bank_balance = get_bank_balance();
	bank_balance = initial_bank_balance;

	do // start of game loop; exits game once balance is zero
	{
		printf("\nYour current bank balance is $%.2lf\n", bank_balance);
		wager = get_wager_amount();
		verify = check_wager_amount(wager, bank_balance);
	
		while (verify == 0) // indicates if wager is too much
		{
			printf("\n\nYou're too poor!\n");
			wager = get_wager_amount();
			verify = check_wager_amount(wager, bank_balance);
		}
		++number_rolls; // adds 1 to number of rolls
		printf("\nRoll Number: %d\n", number_rolls);

		die1 = roll_die(); // start of initial dice roll
		printf("\nDie 1:\n");
		print_die(die1);
		die2 = roll_die();
		printf("\nDie 2:\n");
		print_die(die2);
		point = calculate_sum_dice(die1, die2);
		printf("\nYou rolled a %d!\n", point);

		win_or_lose = is_win_loss_or_point(point); // decides if the first roll is a win, loss, or push

		while (win_or_lose == PUSH) // beginning of inner game loop in event of a push; ends once game is won or lost
		{
			decision = double_down(bank_balance, wager);

			if (decision == 1) // doubles the wager before the next roll
			{
				wager = wager * 2;
			}

			++number_rolls; // increases roll count with each successive roll
			printf("\nRoll Number: %d\n", number_rolls);

			die1 = roll_die(); // dice roll in the inner loop in the event of a push
			printf("\nDie 1:\n");
			print_die(die1);
			die2 = roll_die();
			printf("\nDie 2:\n");
			print_die(die2);
			sum_dice = calculate_sum_dice(die1, die2);
			printf("\nYou rolled a %d!\n", sum_dice);

			win_or_lose = is_point_loss_or_neither(sum_dice, point); // decides if successive rolls are a win, loss, or push
			
		}

		bank_balance = adjust_bank_balance(bank_balance, wager, win_or_lose); // returns new bank balance after push loop is exited

		chatter_messages(number_rolls, win_or_lose, initial_bank_balance, bank_balance);

	} while (bank_balance > LOSE);

	return 0;
}