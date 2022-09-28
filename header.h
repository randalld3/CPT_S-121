/*
* Author: RAD
* Instructor: AOFallen
* Class: Cpt_S 121
* Section: 08L
* Assignment: PA8
* Date Submitted: 4/27/22
*/

#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS

#define ASCII 97

#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct occurrences
{
    int num_occurrences;
    double frequency;
} Occurrences;

char* my_str_n_cat(char* destination, char* source, int n);
int binary_search(int list[], int n, int target, int* target_index);
void bubble_sort(char* array_of_strings[], int size);
int is_palindrome(char word[], int length);
int sum_primes(unsigned int n);
void maximum_occurences(char str_ptr[], Occurrences struct_arr[], int* ptr1, char* ptr2);
void max_consecutive_integers(int arr[][5], int rows, int columns, int** address, int* number);

#endif
