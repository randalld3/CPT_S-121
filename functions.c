/*
* Author: RAD
* Instructor: AOFallen
* Class: Cpt_S 121
* Section: 08L
* Assignment: PA8
* Date Submitted: 4/27/22
*/

#include "header.h"

/*
* Name: my_str_n_cat ()
* Description: peforms strcat() function without string library and using pointer arithmetic.
* History: Created 04.23.22
* Inputs: A pointer to a source string, a pointer to a destination string, and an integer number of characters to copy.
* Outputs: A concatonated resulting string.
* Returns: A pointer to the resulting string.
* Precondition: The number of characters to copy must not make the destination string write outside of memory.
* Postcondition: Destination string will be concatonated.
*/
char* my_str_n_cat(char* destination, char* source, int n)
{
	while(*destination != '\0')
	{ ++destination; }

	while (*source != '\0' && n > 0)
	{
		*destination = *source;
		++destination;
		++source;
		--n;
	}
	return destination;
}

/*
* Name: binary_search ()
* Description: Searches an ordered list of integers for an input target. Returns 1 if found, 0 otherwise.
* History: Created 04.23.22
* Inputs: list array[] to be searched (int), the number of integers in the array, an integer target, and a
*         pointer for the target index.
* Outputs: 1 if target is found, along with the target index (indirectly), 0 otherwise.
* Returns: One integer
* Precondition: List must be ordered.
* Postcondition: target_index may contain a new value.
*/
int binary_search(int list[], int n, int target, int* target_index)
{
	int lower_index = 0, upper_index = n - 1, mid_index = 0, found = 0;

	while (lower_index <= upper_index && found == 0)
	{
		mid_index = (lower_index + upper_index) / 2;

		if (list[mid_index] == target)
		{ 
			found = 1;
			*target_index = mid_index;
		}
		else if (list[mid_index] > target)
		{ upper_index = mid_index - 1; }
		else
		{ lower_index = mid_index + 1; }
	}
	return found;
}

/*
* Name: bubble_sort ()
* Description: Takes in an array of pointers to strings and the number of strings. Uses strcmp() to 
               order the strings alphabetically.
* History: Created 04.24.22, modified 4.26.22
* Inputs: array_of_strings[](pointers), size (int)
* Outputs: A sorted list of strings.
* Returns: None
* Precondition: None
* Postcondition: array_of_strings[] will be in alphabetical order.
*/
void bubble_sort(char* array_of_strings[], int size)
{
	int index = 0, passes = 0;
	char* tmp;

	for (passes = 1; passes < size; ++passes)
	{
		for (index = 0; index < size - passes; ++index)
		{
			if (strcmp(array_of_strings[index], array_of_strings[index + 1]) == 1)
			{
				tmp = array_of_strings[index];
				array_of_strings[index] = array_of_strings[index + 1];
				array_of_strings[index + 1] = tmp;
			}
		}
	}
}

/*
* Name: is_palindrome ()
* Description: Takes in a word or phrase (ignores whitespace) and its length, and recursively 
               determines if it is a palindrome. 
* History: Created 04.25.22
* Inputs: word[] "string", length (int)
* Outputs: 1 if palindrome, 0 otherwise
* Returns: One integer
* Precondition: None
* Postcondition: None
*/
int is_palindrome(char word[], int length)
{
	int index = 0, result = 0, spaces = 0;

	for (; index < length - spaces; ++index)
	{
		word[index] = tolower(word[index]);

		if (word[index] == ' ')
		{
			for (; index < length - spaces; ++index)
			{ word[index] = word[index + 1]; }
			++spaces;
			index = 0;
		}
	}

	if (length <= 0)
	{ result = 1; }
	else if (*word == *(word + length - spaces - 1))
	{ result = is_palindrome(word + 1, length - spaces - 2); }
	else
	{ result = 0; }

	return result;
}

/*
* Name: sum_primes ()
* Description: Takes in an unsigned integer n, and calculates the sum of all prime numbers from 2 to n.
* History: Created 04.25.22
* Inputs: One unsigned integer
* Outputs: Sum of primes from 2 to n.
* Returns: One integer
* Precondition: None
* Postcondition: None
*/
int sum_primes(unsigned int n)
{
	int result = 0, index = 2, prime = 1;

	for (; index < n; ++index)
	{
		if (n % index == 0)
		{ prime = 0; }
	}
	if (prime)
	{ result = n; }

	if (result == 1)
	{ result = 0; }

	if (n == 2)
	{ 
		// do nothing 
	}
	else if (n > 2)
	{ result += sum_primes(n - 1); }

	return result;
}

/*
* Name: maximum_occurences ()
* Description: Takes in a pointer to a string, an array of occurences structs, a pointer to an integer, and a 
*              pointer to a character, fills in the occurences array with number of character uses and 
*              frequency, and returns indirectly the most common character and the number of occurences.
* History: Created 04.25.22
* Inputs: a pointer to a string, struct_arr[] (occurences*), one int*, and one char*.
* Outputs: None
* Returns: max letter used (indirectly) and number of uses (indirectly).
* Precondition: None
* Postcondition: num_occurences and frequency in struct_arr[] (occurences) will be filled in.
*/
void maximum_occurences(char str_ptr[], Occurrences struct_arr[], int* ptr1, char* ptr2)
{
	int temp = 0, index = 0, total = 0, max = 0;

	for (int i = 0; i < 26; ++i)
	{
		struct_arr[i].num_occurrences = 0;
		struct_arr[i].frequency = 0.0;
	}

	while (str_ptr[index] != '\0')
	{
		if (str_ptr[index] == ' ')
		{
			// do nothing
		}
		else
		{

			temp = tolower(str_ptr[index]) - ASCII;
			++struct_arr[temp].num_occurrences;
		}
		++index;
	}

	for (index = 0; index < 26; ++index)
	{
		total += struct_arr[index].num_occurrences;

		if (struct_arr[index].num_occurrences > max)
		{ max = struct_arr[index].num_occurrences; }
	}

	for (index = 0; index < 26; ++index)
	{ struct_arr[index].frequency = struct_arr[index].num_occurrences / (double)total; }

	for (index = 0; index < 26; ++index)
	{
		if (struct_arr[index].num_occurrences == max)
		{
			*ptr1 = max;
			*ptr2 = index + ASCII;
		}
	}
}

/*
* Name: max_consecutive_integers ()
* Description: Determines the maximum consecutive integer of a 2D array, and returns indirectly the 
*              integer and the address of the integer.
* History: Created 04.26.22
* Inputs: A 2D array a signed integers, number of rows, number of columns, a pointer to a pointer to the 
*         address for the most consecutive integer, and a pointer for the most consecutive integer.
* Outputs: None
* Returns: Most consecutive integer (indirectly) and the address of the most consecutive integer (indirectly).
* Precondition: There must be at least two of an integer in a row in the 2D array somewhere.
* Postcondition: None
*/
void max_consecutive_integers(int arr[][5], int rows, int columns, int** address, int* number)
{
	int row_i = rows - 1, col_i = columns - 1, counter = 0, max = 0;

	for (; row_i >= 0; --row_i)
	{
		for (col_i = columns - 1; col_i >= 0; --col_i)
		{
			if (arr[row_i][col_i] == arr[row_i][col_i - 1])
			{ ++counter; }
			else
			{ counter = 0; }
			if (counter > max)
			{
				max = counter;
				*number = arr[row_i][col_i];
				*address = &arr[row_i][col_i];
			}
		}
	}
}