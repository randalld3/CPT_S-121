
#include "battleship.h"

/*
* Name: welcome_screen ()
* Description: Prints the word "Battleship" as a large ASCII text banner, and shows the rules of the game.
* History: Created 03.25.22
* Inputs: None
* Outputs: A lot of text.
* Returns: None
* Precondition: None
* Postcondition: Function executed
*/
void welcome_screen(void)
{
	printf("'########:::::'###::::'########:'########:'##:::::::'########::'######::'##::::'##:'####:'########::\n"
		   " ##.... ##:::'## ##:::... ##..::... ##..:: ##::::::: ##.....::'##... ##: ##:::: ##:. ##:: ##.... ##:\n"
		   " ##:::: ##::'##:. ##::::: ##::::::: ##:::: ##::::::: ##::::::: ##:::..:: ##:::: ##:: ##:: ##:::: ##:\n"
		   " ########::'##:::. ##:::: ##::::::: ##:::: ##::::::: ######:::. ######:: #########:: ##:: ########::\n"
		   " ##.... ##: #########:::: ##::::::: ##:::: ##::::::: ##...:::::..... ##: ##.... ##:: ##:: ##.....:::\n"
		   " ##:::: ##: ##.... ##:::: ##::::::: ##:::: ##::::::: ##:::::::'##::: ##: ##:::: ##:: ##:: ##::::::::\n"
		   " ########:: ##:::: ##:::: ##::::::: ##:::: ########: ########:. ######:: ##:::: ##:'####: ##::::::::\n"
	       "........:::..:::::..:::::..::::::::..:::::........::........:::......:::..:::::..::....::..:::::::::\n");

	system("pause");
	system("cls");

	printf("Welcome to Battlship!\n\nThe rules of the game are as follows:\n\n"
		"Battleship is a two player Navy game. The objective of the game is to sink all ships in your enemy's fleet.\n"
		"The player to sink his / her enemy's fleet first wins. Both players' fleets consist of 5 ships that are hidden from the enemy.\n"
		"Each ship may be differentiated by its ""size"" (besides the Cruiser and Submarine) or number of cells it expands on the game board.\n"
		"The Carrier has 5 cells, Battleship has 4 cells, Cruiser has 3 cells, Submarine has 3 cells, and the Destroyer has 2 cells.\n\n");

	system("pause");
	system("cls");
}

/*
* Name: initialize_game_board ()
* Description: Sets the values of a player's game board to '-'
* History: Created 03.25.22
* Inputs: A 2D array game board.  
* Outputs: fills an array with '-'
* Returns: None
* Precondition: Input max_rows and max_cols must be correct.
* Postcondition: Input game board will be filled with '-'
*/
void initialize_game_board(char game_board[MAX_ROWS][MAX_COLS])
{
	int row_index = 0, col_index = 0;

	for (; row_index < MAX_ROWS; ++row_index)
	{
		for (col_index = 0; col_index < MAX_COLS; ++col_index)
		{ game_board[row_index][col_index] = '-'; } 
	} 
}

/*
* Name: select_who_starts_first ()
* Description: randomly picks 0 or 1 to determine player who starts the game
* History: Created 03.25.22
* Inputs: None
* Outputs: 0 or 1
* Returns: one integer
* Precondition: None
* Postcondition: Function executed
*/
int select_who_starts_first(void)
{
	int starter = -1;
	return rand() % 2;
}

/*
* Name: random_or_manual ()
* Description: Prompts user to ask if they would like to manually enter their ships.
* History: Created 03.26.22
* Inputs: None
* Outputs: character entered by user ('m' means manual)
* Returns: One character
* Precondition: None
* Postcondition: Function executed
*/
char random_or_manual(void)
{
	char choice = 'a';
	printf("Would you like to place your ships manually or randomly? Enter 'm' for manual\n");
	scanf("%c", &choice);
	if (choice == 'M')
	{ choice = 'm'; }

	return choice;
}

/*
* Name: manually_place_ships_on_board ()
* Description: Awful function created with way too much logic. I wanted to experiment and make a complicated
*              function without a flow chart. This is what resulted. It has different loops for each ship, and 
*              pairs with validate_boat_placement to allow for the user to enter ship coordinates. Ship 
*              coordinates are checked for valid placement and overlap.
* History: Created 03.26.22
* Inputs: None
* Outputs: A completed game board with ships marked by characters 'c' for carrier, 'b' for battleship, 
           'r' for cruiser, 's' for submarine, and 'd' for destroyer.
* Returns: None
* Precondition: None
* Postcondition: player 1 will have a completed game board.
*/
void manually_place_ships_on_board(char player1_gb[MAX_ROWS][MAX_COLS])
{
	int index = 0, row_index = 0, col_index = 0, row = 0, column = 0;

	char space[3] = "";

	printf("Your carrier (5 spaces) will be placed first\n");
	for (index = 0; index < 5; ++index)
	{
		printf("Enter coordinate #%d (the row # first and column number second) for your carrier\n", index + 1);
		gets(space);

		row = space[0] - ASCII;
		column = space[1] - ASCII;

		if (player1_gb[row][column] != '-')
		{
			for (row_index = 0; row_index < MAX_ROWS; ++row_index)
			{
				for (col_index = 0; col_index < MAX_COLS; ++col_index)
				{
					if (player1_gb[row_index][col_index] == 'c')
					{
						player1_gb[row_index][col_index] = '-';
						printf("Error: Restarting Carrier Placement\n");
						index = -1;
					}
				}
			}
		}
		else
		{
			player1_gb[row][column] = 'c';
			if (index == 4)
			{ index = 5 * validate_boat_placement(player1_gb, 'c') - 1; }
		}
	}

	printf("Your battleship (4 spaces) will be placed second\n");
	for (index = 0; index < 4; ++index)
	{
		printf("Enter coordinate #%d (the row # first and column number second) for your battleship\n", index + 1);
		gets(space);

		row = space[0] - ASCII;
		column = space[1] - ASCII;

		if (player1_gb[row][column] != '-')
		{ 
			printf("Error: Restarting Battleship Placement\n");
			index = -1;

			for (row_index = 0; row_index < MAX_ROWS; ++row_index)
			{
				for (col_index = 0; col_index < MAX_COLS; ++col_index)
				{
					if (player1_gb[row_index][col_index] == 'b')
					{ player1_gb[row_index][col_index] = '-'; } 
				} 
			} 
		}
		else
	    { 
			player1_gb[row][column] = 'b'; 
			if (index == 3)
			{ index = 4 * validate_boat_placement(player1_gb, 'b') - 1; }
		} 
	} 

	printf("Your cruiser (3 spaces) will be placed third\n");
	for (index = 0; index < 3; ++index)
	{
		printf("Enter coordinate #%d (the row # first and column number second) for your cruiser\n", index + 1);
		gets(space);

		row = space[0] - ASCII;
		column = space[1] - ASCII;

		if (player1_gb[row][column] != '-')
		{
			for (row_index = 0; row_index < MAX_ROWS; ++row_index)
			{
				for (col_index = 0; col_index < MAX_COLS; ++col_index)
				{
					if (player1_gb[row_index][col_index] == 'r')
					{
						player1_gb[row_index][col_index] = '-';
						printf("Error: Restarting Cruiser Placement\n");
						index = -1;
					}
				}
			}
		}
		else
		{
			player1_gb[row][column] = 'r';
			if (index == 2)
			{ index = 3 * validate_boat_placement(player1_gb, 'r') - 1; }
		}
	}

	printf("Your submarine (3 spaces) will be placed fourth\n");
	for (index = 0; index < 3; ++index)
	{
		printf("Enter coordinate #%d (the row # first and column number second) for your submarine\n", index + 1);
		gets(space);

		row = space[0] - ASCII;
		column = space[1] - ASCII;

		if (player1_gb[row][column] != '-')
		{
			for (row_index = 0; row_index < MAX_ROWS; ++row_index)
			{
				for (col_index = 0; col_index < MAX_COLS; ++col_index)
				{
					if (player1_gb[row_index][col_index] == 's')
					{
						player1_gb[row_index][col_index] = '-';
						printf("Error: Restarting Submarine Placement\n");
						index = -1;
					}
				}
			}
		}
		else
		{
			player1_gb[row][column] = 's';
			if (index == 2)
			{ index = 3 * validate_boat_placement(player1_gb, 's') - 1; }
		}
	}

	printf("Your destroyer (2 spaces) will be placed last\n");
	for (index = 0; index < 2; ++index)
	{
		printf("Enter coordinate #%d (the row # first and column number second) for your destroyer\n", index + 1);
		gets(space);

		row = space[0] - ASCII;
		column = space[1] - ASCII;

		if (player1_gb[row][column] != '-')
		{
			for (row_index = 0; row_index < MAX_ROWS; ++row_index)
			{
				for (col_index = 0; col_index < MAX_COLS; ++col_index)
				{
					if (player1_gb[row_index][col_index] == 'd')
					{
						player1_gb[row_index][col_index] = '-';
						printf("Error: Restarting Destroyer Placement\n");
						index = -1;
					}
				}
			}
		}
		else
		{
			player1_gb[row][column] = 'd';
			if (index == 1)
			{ index = 2 * validate_boat_placement(player1_gb, 'd') -1; }
		}
	}
}

/*
* Name: validate_boat_placement ()
* Description: Pairs with manually_place_ships_on_board. This function ensures coordinates entered for a ship 
*              are all in the same row/column and adjacent.
* History: Created 03.26.22
* Inputs: A player's game board, and the boat to be validated.
* Outputs: The number 1 if the boat placement is valid.
* Returns: One integer
* Precondition: None
* Postcondition: None
*/
int validate_boat_placement(char player_gb[MAX_ROWS][MAX_COLS], char boat)
{
	int target = 0, count = 0, row_index = 0, col_index = 0, validate = 0;

	switch (boat)
	{
	case 'c': target = 5;
		break;
	case 'b': target = 4;
		break;
	case 'r': target = 3;
		break;
	case 's': target = 3;
		break;
	case 'd': target = 2;
		break;
    }

	for (row_index = 0; row_index < MAX_ROWS && validate != 1; ++row_index)
	{
		for (col_index = 0; col_index < MAX_COLS; ++col_index)
		{
			if (player_gb[row_index][col_index] == boat)
			{
				++count;
				if (target == count)
				{ validate = 1; }
			} 
			else
			{ count = 0; }
		}
		count = 0;
	}

	for (col_index = 0; col_index < MAX_COLS && validate != 1; ++col_index)
	{
		for (row_index = 0; row_index < MAX_ROWS; ++row_index)
		{
			if (player_gb[row_index][col_index] == boat)
			{
				++count;
				if (target == count)
				{ validate = 1; }
			}
			else
			{ count = 0; }
		} 
		count = 0;
	} 

	if (validate == 0)
	{ 
		printf("You entered a ship's coordinates incorrectly and will need to re-start\n"); 

		for (row_index = 0; row_index < MAX_ROWS; ++row_index)
		{
			for (col_index = 0; col_index < MAX_COLS; ++col_index)
			{
				if (player_gb[row_index][col_index] == boat)
				{ player_gb[row_index][col_index] = '-'; }
			}
		}
	}
	return validate;
}

/*
* Name: randomly_place_ships_on_board ()
* Description: Spaces are assigned for all five ships to fill a game board. Logic is done to ensure the ships
*              do not go off the game board or overlap. 
* History: Created 03.26.22
* Inputs: None
* Outputs: A completed game board.
* Returns: None
* Precondition: Game board must be initialized.
* Postcondition: The input game board will be filled in with all five ships.
*/
void randomly_place_ships_on_board(char player_gb[MAX_ROWS][MAX_COLS])
{
	int place = 0, ship = 0, spaces = 0, index = 0, row_index = 0, col_index = 0, direction = 0, row = 0, column = 0;
	char boat = 'a';
	// 57, 48, 39, 30, 21

	for (ship = 57; ship > 20; ship = ship - 9) // sequence to determine what ship is being placed, and how many spaces it will occupy when divided by 10.
	{
		place = 0;
		spaces = ship / 10;
		switch (ship)
		{
		case 57: boat = 'c';
			break;
		case 48: boat = 'b';
			break;
		case 39: boat = 'r';
			break;
		case 30: boat = 's';
			break;
		case 21: boat = 'd';
			break;
		}

		while (place == 0) // loop for placing individual ships
		{
			direction = rand() % 4;
			row = rand() % MAX_ROWS;
			column = rand() % MAX_COLS;
			place = 1;

			switch (direction)
			{
			case 0: 
				for (row_index = row, index = 0; index < spaces; ++index, --row_index) //checking upward
			    {
				    if (player_gb[row_index][column] != '-')
				    { place = 0; }
			    } 
				if (place == 1) // placing upward
				{
					for (row_index = row, index = 0; index < spaces; ++index, --row_index)
					{ player_gb[row_index][column] = boat; }
				}
				break;
            case 1: for (row_index = row, index = 0; index < spaces; ++index, ++row_index) // checking downward
			{
				if (player_gb[row_index][column] != '-')
				{ place = 0; }
			} 
			    if (place == 1) // placing downward
				{
					for (row_index = row, index = 0; index < spaces; ++index, ++row_index)
					{ player_gb[row_index][column] = boat; }
				}
				break;
			case 2: 
				if (column < spaces - 1)
			    { place = 0; }
				for (col_index = column, index = 0; index < spaces; ++index, --col_index) // checking to left
			    {
					if (player_gb[row][col_index] != '-')
					{ place = 0; }
			    } 
				if (place == 1) // placing to left
				{
					for (col_index = column, index = 0; index < spaces; ++index, --col_index)
					{ player_gb[row][col_index] = boat; }
				}
				break;
			case 3: 
				if (column > MAX_COLS - spaces)
			    { place = 0; }
				for (col_index = column, index = 0; index < spaces; ++index, ++col_index) // checking to right
			    {
				    if (player_gb[row][col_index] != '-')
				    { place = 0; }
			    } 
				if (place == 1) // placing to right
				{
					for (col_index = column, index = 0; index < spaces; ++index, ++col_index)
					{ player_gb[row][col_index] = boat; }
				}
				break;
			}
		}
	}
}

/*
* Name: display_board ()
* Description: Prints the game board as a 2D table, showing all ships, hits, and misses for player 1, and 
*              showing just the hits and misses for player 2.
* History: Created 03.27.22
* Inputs: A players game board (char[]) and a player number (int).
* Outputs: A printed player board.
* Returns: None
* Precondition: Player board must be initialized.
* Postcondition: None
*/
void display_board(char player_gb[MAX_ROWS][MAX_COLS], int player)
{
	int row_index = 0, col_index = 0;

	printf("%3d%2d%2d%2d%2d%2d%2d%2d%2d%2d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	for (row_index = 0; row_index < MAX_ROWS; ++row_index)
	{
		printf("%-2d", row_index);
		for (col_index = 0; col_index < MAX_COLS; ++col_index)
		{
			if (player == 1) // loop for showing player gb
			{ printf("%-2c", player_gb[row_index][col_index]); }
			else //  loop for showing computer gb
			{
				if (player_gb[row_index][col_index] == 'm' || player_gb[row_index][col_index] == '*')
				{ printf("%-2c", player_gb[row_index][col_index]); }
				else
				{ printf("- "); }
			}
		}
		printf("\n");
	}
}

/*
* Name: get_shot ()
* Description: Prompts user for shot location, and verifies the shot is valid before indirectly returning shot[].
* History: Created 03.27.22
* Inputs: Shot[]
* Outputs: A new shot coordinate.
* Returns: None
* Precondition: None
* Postcondition: shot[] will contain the value of the next shot location.
*/
void get_shot(char player_gb[MAX_ROWS][MAX_COLS], char shot[])
{
	char target[3] = "";
	int row = 0, column = 0, shoot = 0;

	do
	{
		++shoot;
		/*
		printf("Enter the row and then the column you wish to fire upon.\n");
		gets(target);
		row = target[0] - ASCII;
		column = target[1] - ASCII;
		*/

		printf("Enter the row you wish to fire upon\n");
		scanf("%d", &row);
		printf("Enter the column you wish to fire upon\n");
		scanf("%d", &column);

		if (row < 0 || row > 9 || column < 0 || column > 9 || player_gb[row][column] == 'm' || player_gb[row][column] == '*')
		{ shoot = 0; }
	} while (shoot == 0);

	shot[0] = row + ASCII;
	shot[1] = column + ASCII;
}

/*
* Name: check_shot ()
* Description: Checks to see if shot was a hit or miss, returns 1 if hit.
* History: Created 04.01.22
* Inputs: A players game board (char[]) and shot[].
* Outputs: 1 if hit, 0 if miss.
* Returns: A single integer.
* Precondition: Player board must have ships placed.
* Postcondition: None
*/
int check_shot(char player_gb[MAX_ROWS][MAX_COLS], char shot[])
{
	int hit_or_miss = 0, row = 0, column = 0;

	row = shot[0] - ASCII;
	column = shot[1] - ASCII;

	if (player_gb[row][column] == 'c' || player_gb[row][column] == 'b' || player_gb[row][column] == 'r' || 
		player_gb[row][column] == 's' || player_gb[row][column] == 'd')
	{
		hit_or_miss = 1;
		printf("That's a hit!\n\n");
	}
	else
	{ printf("That's a miss!\n\n"); }



	return hit_or_miss;
}

/*
* Name: random_shot ()
* Description: Picks random row and column for a shot, verifies that it has not been shot yet, and 
*              returns shot[] indirectly.
* History: Created 04.01.22
* Inputs: A players game board (char[]) and shot[].
* Outputs: A shot coordinate.
* Returns: shot[] string indirectly
* Precondition: None
* Postcondition: None
*/
void random_shot(char player1_gb[MAX_ROWS][MAX_COLS], char shot[])
{
	int row = 0, column = 0, shoot = 0;

	while (shoot == 0)
	{
		row = rand() % MAX_ROWS;
		column = rand() % MAX_COLS;
		if (player1_gb[row][column] != 'm' && player1_gb[row][column] != '*')
		{ shoot = 1; }
	}
	shot[0] = row + ASCII;
	shot[1] = column + ASCII;
}

/*
* Name: update_board ()
* Description: Fills in the player game board shot location with the appropriate shot symbol (* for hit, m for miss).
* History: Created 04.01.22
* Inputs: A players game board (char[]) and shot[].
* Outputs: A character to a player's game board.
* Returns: One char on player_gb[][] indirectly.
* Precondition: None
* Postcondition: Player_gb will be updated with new shot.
*/
void update_board(char player_gb[MAX_ROWS][MAX_COLS], char shot[])
{
	int row = 0, column = 0;

	row = shot[0] - ASCII;
	column = shot[1] - ASCII;

	if (player_gb[row][column] == '-')
	{ player_gb[row][column] = 'm'; }
	/*else if (player_gb[row][column] == 'm' || player_gb[row][column] == '*')
	{
		printf("You already shot there! That's a miss!\n");
	}*/
	else
	{ player_gb[row][column] = '*'; }
}

int is_winner(char player_gb[MAX_ROWS][MAX_COLS])
{
	int winner = 0, count = 0, row_index = 0, col_index = 0;

	for (; row_index < MAX_ROWS; ++row_index)
	{
		for (col_index = 0; col_index < MAX_COLS; ++col_index)
		{
			if (player_gb[row_index][col_index] == 'c' || player_gb[row_index][col_index] == 'b' ||
				player_gb[row_index][col_index] == 'r' || player_gb[row_index][col_index] == 's' || player_gb[row_index][col_index] == 'd')
			{ ++count; }
		}
	}
	if (count == 0)
	{ winner = 1; }

	return winner;
}

/*
* Name: check_if_sunk_ship ()
* Description: checks to see if a shot will sink a ship. It checks to see if the shot was a hit, and runs 
*              a counter on the number of ship symbols left on the game board. Returns 1 if the shot is
*              a hit and there is only one of that ship type.
* History: Created 04.01.22
* Inputs: A players game board (char[]) and shot[].
* Outputs: 1 if a ship is sunk, 0 otherwise.
* Returns: A singer integer
* Precondition: None
* Postcondition: None
*/
int check_if_sunk_ship(char player_gb[MAX_ROWS][MAX_COLS], char shot[], char* ship_sunk)
{
	int sink_or_swim = 0, row_index = 0, col_index = 0, row = 0, col = 0;
	int car = 0, bat = 0, cru = 0, sub = 0, des = 0;

	row = shot[0] - ASCII;
	col = shot[1] - ASCII;

	for (; row_index < MAX_ROWS; ++row_index)
	{
		for (col_index = 0; col_index < MAX_COLS; ++col_index)
		{
			if (player_gb[row_index][col_index] == 'c')
			{ ++car; }
			else if(player_gb[row_index][col_index] == 'b')
			{ ++bat; }
			else if (player_gb[row_index][col_index] == 'r')
			{ ++cru; }
			else if (player_gb[row_index][col_index] == 's')
			{ ++sub; }
			else if (player_gb[row_index][col_index] == 'd')
			{ ++des; }
		}
	}
	if (player_gb[row][col] == 'c' && car == 1)
	{ sink_or_swim = 1; *ship_sunk = 'c'; }
	else if (player_gb[row][col] == 'b' && bat == 1)
	{ sink_or_swim = 1; *ship_sunk = 'b'; }
	else if (player_gb[row][col] == 'r' && cru == 1)
	{ sink_or_swim = 1; *ship_sunk = 'r'; }
	else if (player_gb[row][col] == 's' && sub == 1)
	{ sink_or_swim = 1; *ship_sunk = 's'; }
	else if (player_gb[row][col] == 'd' && des == 1)
	{ sink_or_swim = 1; *ship_sunk = 'd'; }
	return sink_or_swim;
}

/*
* Name: update_stats ()
* Description: Receives hit_or_miss and updates the player stats structure on hits, misses, and shots.
* History: Created 04.04.22
* Inputs: A players stats structure (Stats) and hit_or_miss (int).
* Outputs: Updated player stats
* Returns: Two integers (one for shots, the other for hits or misses).
* Precondition: None
* Postcondition: Player stats will be updated.
*/
void update_stats(Stats* player_stats_ptr, int hit_or_miss)
{
	if(hit_or_miss == 0) // miss
	{ (*player_stats_ptr).num_misses++; }
	else if (hit_or_miss == 1) // hit
	{ (*player_stats_ptr).num_hits++; }
	player_stats_ptr->num_shots++;
}

/*
* Name: print_round_stats ()
* Description: Writes the player, shot coordinate, hit or miss, and if a ship was sunk to the battleship.log file.
* History: Created 04.04.22
* Inputs: Shot coordinate[], hit_or_miss, sink_or_swim, and a pointer to the file pointer in main to battleship.log.
* Outputs: File printed round stats,
* Returns: None
* Precondition: None
* Postcondition: Battleship.log file will contain updated stats.
*/
void print_round_stats(char shot[], int hit_or_miss, int sink_or_swim, int player_turn, FILE **infile, char ship_sunk)
{
	int player = 0;

	if (player_turn % 2 == 1)
	{ player = 1; }
	else
	{ player = 2; }

	if (sink_or_swim == 1)
	{ 
		fprintf(*infile, "Player %d: %s 'hit' ", player, shot); 
		if (ship_sunk == 'c')
		{ fprintf(*infile, "Carrier Sunk!\n"); }
		else if (ship_sunk == 'b')
		{ fprintf(*infile, "Battleship Sunk!\n"); }
		else if (ship_sunk == 'r')
		{ fprintf(*infile, "Cruiser Sunk!\n"); }
		else if (ship_sunk == 's')
		{ fprintf(*infile, "Submarine Sunk!\n"); }
		else if (ship_sunk == 'd')
		{ fprintf(*infile, "Destroyer Sunk!\n"); }
	}
	else
	{
		if (hit_or_miss == 1)
		{ fprintf(*infile, "Player %d: %s 'hit'\n", player, shot); }
		else
		{ fprintf(*infile, "Player %d: %s 'miss'\n", player, shot); }
	}
}

/*
* Name: determine_winner ()
* Description: Receives player turn and determines the winner when called. Due to the method used in the while 
*              loop in main, player 1 wins when player_turn = 0;
* History: Created 04.08.22
* Inputs: player_turn (int)
* Outputs: The winner of the game.
* Returns: One integer
* Precondition: Game loop must exit on proper sequence.
* Postcondition: None
*/
int determine_winner(int player_turn)
{
	int winner = 0;

	if (player_turn % 2 == 0)
	{ winner = 1; }
	else
	{ winner = 2; }
	
	return winner;
}

/*
* Name: print_final_stats ()
* Description: Writes the player, shot coordinate, hit or miss, and if a ship was sunk to the battleship.log file.
* History: Created 04.08.22
* Inputs: Pointers to p1 and p2_stats structures, the winner (int), and a pointer to the file pointer in main.
* Outputs: File printed final stats.
* Returns: None
* Precondition: p1 and p2_stats structures must already be updated.
* Postcondition: Battleship.log file will contain final stats.
*/
void print_final_stats(FILE** infile, Stats* p1_stats, Stats* p2_stats, int winner)
{
	p1_stats->hits_to_misses_ratio = ((float)p1_stats->num_hits * 100 )/ p1_stats->num_misses;
	p2_stats->hits_to_misses_ratio = ((float)p2_stats->num_hits * 100) / p2_stats->num_misses;
	fprintf(*infile, "\n\nPlayer %d wins!!\n\n", winner);
	fprintf(*infile, "*** Player 1 Stats***\nNumber Hits:    %d\nNumber Misses:  %d\nTotal Shots:    %d\n"
		    "Hit/Miss Ratio: %.0lf%%\n\n", p1_stats->num_hits, p1_stats->num_misses, p1_stats->num_shots,
	         p1_stats->hits_to_misses_ratio);
	fprintf(*infile, "*** Player 2 Stats***\nNumber Hits:    %d\nNumber Misses:  %d\nTotal Shots:    %d\n"
		    "Hit/Miss Ratio: %.0lf%%\n\n", p2_stats->num_hits, p2_stats->num_misses, p2_stats->num_shots,
	    	 p2_stats->hits_to_misses_ratio);
}