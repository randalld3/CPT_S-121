/*
* Author: RAD
* Instructor: AOFallen
* Class: Cpt_S 121
* Section: 08L
* Assignment: PA8
* Date Submitted: 4/27/22
*/

#include "header.h"

int main(void)
{
	char max_letter = 'a', source1[20] = "testing", source2[20] = "testing", 
		destination1[30] = "Attach to end", destination2[30] = "Attach to end",
		test[50] = "test string", test2[50] = "both fickle dwarves jinx my pig quiz",
		palindrome1[50] = "A man a plan a canal Panama", palindrome2[50] = "not a palindrome";
	char* array_of_strings[9] = { "the", "quick", "brown", "fox", "jumped", "over", "the", "lazy", "dog" },
		*array_of_strings2[10] = {"grumpy", "wizards", "make", "a", "toxic", "brew", "for", "the", "jovial", "queen"};
	int list1[6] = { 12, 22, 39, 58, 81, 99 }, list2[6] = { 4, 8, 15, 16, 23, 42 }, list3[4] = { -5, -1, 0, 6},
		index = 0, target = 42, found = 0,
		target_index = -1, pal = 0, n = -5, result = 0, occurences = 0;
	unsigned int  x = 13, y = 1, z = 8;
	int arr_2D[4][5] = { {-5, 6, 0, 2, 2} , {2, 2, 2, 9, 3} , {3, 3, 2, 1, -8} , {7, -2, 6, 0, 4} };
	int* address;
	Occurrences arr[26] = { 0 , 0 };

	printf("Function 1 test cases:\n\n");
	printf("Test #1 my_str_n_cat()\nSource Test String: %s, Destination String Before: %s, n = 10\n", source1, destination1);
	system("pause");
	my_str_n_cat(destination1, source1, 10);
	printf("Result: %s\n\n", destination1);
	printf("Test #2 my_str_n_cat()\nSource Test String: %s, Destination String Before: %s, n = 4\n", source2, destination2);
	system("pause");
	my_str_n_cat(destination2, source2, 4);
	printf("Result: %s\n\n", destination2);
	system("pause");
	system("cls");

	printf("Function 2 test cases:\nFound = '1' indicates found, Found = '0' indicates not found, "
		"Index = '-1' indicates no index\n\n");
	printf("Test 1: binary_search() Search for:% d\nList 1:\n", target);
	for (index = 0; index < 6; ++index)
	{ printf("%d ", list1[index]); }
	printf("\n");
	system("pause");
	found = binary_search(list1, 6, target, &target_index);
	printf("Found: %d, Target index: %d\n\n", found, target_index);
	printf("Test 2: binary_search() Search for:% d\nList 2:\n", target);
	for (index = 0; index < 6; ++index)
	{ printf("%d ", list2[index]); }
	printf("\n");
	system("pause");
	found = binary_search(list2, 6, target, &target_index);
	printf("Found: %d, Target index: %d\n\n", found, target_index);
	printf("Test 3: binary_search() Search for:% d\nList 1:\n", n);
	for (index = 0; index < 4; ++index)
	{ printf("%d ", list3[index]); }
	printf("\n");
	system("pause");
	found = binary_search(list3, 4, n, &target_index);
	printf("Found: %d, Target index: %d\n\n", found, target_index);
	system("pause");
	system("cls");

	printf("Function 3 test cases:\n\n");
    printf("Test 1: bubble_sort() test case:\n\nBefore: ");
	for (int i = 0; i < 9; i++) 
	{ printf("%s ", array_of_strings[i]); }
	printf("\n");
	system("pause");
	printf("\nAfter: ");
	bubble_sort(array_of_strings, 9);
	for (int i = 0; i < 9; i++) 
	{ printf("%s ", array_of_strings[i]); }
	printf("\n");
	system("pause");
	printf("\nTest 2: bubble_sort() test case:\n\nBefore: ");
	for (int i = 0; i < 10; i++) 
	{ printf("%s ", array_of_strings2[i]); }
	printf("\n");
	system("pause");
	printf("\nAfter: ");
	bubble_sort(array_of_strings2, 10);
	for (int i = 0; i < 10; i++) 
	{ printf("%s ", array_of_strings2[i]); }
	printf("\n");
	system("pause");
	system("cls");
	
	printf("Function 4: is_palindrome() test cases:\n\n");
	printf("Test 1: Test Phrase: %s\n", palindrome2);
	system("pause");
	pal = is_palindrome(palindrome2, 16);
	printf("Result: %d\n\n", pal);
	printf("Test 2: Test Phrase: %s\n", palindrome1);
	system("pause");
	pal = is_palindrome(palindrome1, 27);
	printf("Result: %d\n\n", pal);
	system("pause");
	system("cls");

	printf("Function 5 test cases: \n\n");
	printf("Test 1: sum_primes() Test number: %d\n", z);
	system("pause");
	result = sum_primes(z);
	printf("Result: %d\n\n", result);
	printf("Test 2: sum_primes() Test number: %d\n", x);
	system("pause");
	result = sum_primes(x);
	printf("Result: %d\n\n", result);
	printf("Test 3: sum_primes() Test number: %d\n", y);
	system("pause");
	result = sum_primes(y);
	printf("Result: %d\n\n", result);
	system("pause");
	system("cls");

	printf("Function 6 test cases: \n\n");
	printf("Test 1: maximum_occurrences() test phrase : % s\n", test);
	system("pause");
	maximum_occurences(test, arr, &occurences, &max_letter);
	for (index = 0; index < 26; ++index)
	{ printf("Letter: %c, Number of occurences: %d, Frequency: %lf\n", index + ASCII, arr[index].num_occurrences, arr[index].frequency); }
	printf("Maximum used letter: %c, Number of occurences: %d\n", max_letter, occurences);
	system("pause");
	system("cls");
	printf("Test 2: maximum_occurrences() test phrase : % s\n", test2);
	system("pause");
	maximum_occurences(test2, arr, &occurences, &max_letter);
	for (index = 0; index < 26; ++index)
	{ printf("Letter: %c, Number of occurences: %d, Frequency: %lf\n", index + ASCII, arr[index].num_occurrences, arr[index].frequency); }
	printf("Maximum used letter: %c, Number of occurences: %d\n", max_letter, occurences);
	system("pause");
	system("cls");

	printf("Function 7: max_consecutive_integers() 2-D array:\n\n");
	for (int r_i = 0; r_i < 4; ++r_i)
	{
		for (int c_i = 0; c_i < 5; ++c_i)
		{ printf("%d\t", arr_2D[r_i][c_i]); }
		printf("\n\n");
	}
	system("pause");
	max_consecutive_integers(arr_2D, 4, 5, &address, &result);
	printf("\nNumber of longest chain: %d\n", result);
	printf("Address of row 0, column 0: %d\n", &arr_2D[0][0]);
	printf("Address of first occurence in longest chain: %d\n", address);


	return 0;
}