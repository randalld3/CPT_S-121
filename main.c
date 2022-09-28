/*                  *                    *                    *                     *                    *                   *
* Author: Randall Dickinson              Date Completed: 02.10.22                                                            *
* Instructor: AOFallen                   Class: Cpt_S 121                                                                    *
*                                                                                                                            *
* This main file will open the input and output files necessary for reading and writing data.                                *
* It will use this data and the functions listed in Analysis.c to perform computations and obtain                            *
* a mean GPA, mean class standing, mean age, GPA standard deviation, GPA minimum, and GPA maximum.                           *
* This data is written into the output.dat file following each calculation                                                   *
*                                                                                                                            *
* Functions necessary for the calculations can be found in Equations.c                                                        *
*                   *                    *                    *                     *                    *                   *
*/

#include "Equations.h"

int main(void)
{
	FILE* infile = fopen("input.dat", "r"), // Opens an input file "input.dat" for reading
		* outfile = fopen("output.dat", "w"); // Opens an output file "output.dat" for writing

	double gpa1 = 0.0, age1 = 0, deviation1 = 0.0, sum_gpa = 0.0, mean_gpa = 0.0;
	double gpa2 = 0.0, age2 = 0, deviation2 = 0.0, sum_class = 0, mean_class = 0;
	double gpa3 = 0.0, age3 = 0, deviation3 = 0.0, sum_age = 0.0, mean_age = 0.0;
	double gpa4 = 0.0, age4 = 0, deviation4 = 0.0, min_gpa = 0.0, std_dev = 0.0;
	double gpa5 = 0.0, age5 = 0, deviation5 = 0.0, max_gpa = 0.0, variance = 0.0;

	int sid = 0, class_standing1 = 0, class_standing2 = 0, class_standing3 = 0, class_standing4 = 0, class_standing5 = 0;

	
	sid = read_integer(infile);
	gpa1 = read_double(infile);
	class_standing1 = read_integer(infile);
	age1 = read_double(infile);
	sid = read_integer(infile);
	gpa2 = read_double(infile);
	class_standing2 = read_integer(infile);
	age2 = read_double(infile);
	sid = read_integer(infile);
	gpa3 = read_double(infile);
	class_standing3 = read_integer(infile);
	age3 = read_double(infile);
	sid = read_integer(infile);
	gpa4 = read_double(infile);
	class_standing4 = read_integer(infile);
	age4 = read_double(infile);
	sid = read_integer(infile);
	gpa5 = read_double(infile);
	class_standing5 = read_integer(infile);
	age5 = read_double(infile);
	// calls read_integer and read_double functions to read five sets of numbers from input.dat file, returning values for listed variables in main

	sum_gpa = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5); // Calculates the sum of the GPAs

	sum_class = calculate_sum(class_standing1, class_standing2, class_standing3, class_standing4, class_standing5); // Calculates the sum of the class standings

	sum_age = calculate_sum(age1, age2, age3, age4, age5); // Calculates the sum of the ages

	mean_gpa = calculate_mean(sum_gpa, 5); // Calculates the mean of the GPAs
	print_double(outfile, mean_gpa); // writes the result to the output file(output.dat)

	mean_class = calculate_mean(sum_class, 5); // Calculates the mean of the class standings
	print_double(outfile, mean_class); //writes the result to the output file(output.dat)

	mean_age = calculate_mean(sum_age, 5); // Calculates the mean of the ages
	print_double(outfile, mean_age); //writes the result to the output file(output.dat)

	deviation1 = calculate_deviation(gpa1, mean_gpa); // Calculates the deviation of each GPA from the mean
	deviation2 = calculate_deviation(gpa2, mean_gpa);
	deviation3 = calculate_deviation(gpa3, mean_gpa);
	deviation4 = calculate_deviation(gpa4, mean_gpa);
	deviation5 = calculate_deviation(gpa5, mean_gpa);

	variance = calculate_variance(deviation1, deviation2, deviation3, deviation4, deviation5, 5); // Calculates the variance of the GPAs

	std_dev = calculate_standard_deviation(variance); // Calculates the standard deviation of the GPAs
	print_double(outfile, std_dev); // writes the result to the output file(output.dat)

	min_gpa = find_min(gpa1, gpa2, gpa3, gpa4, gpa5); // Determines the min of the GPAs
	print_double(outfile, min_gpa); //writes the result to the output file(output.dat)

	max_gpa = find_max(gpa1, gpa2, gpa3, gpa4, gpa5); // Determines the max of the GPAs
	print_double(outfile, max_gpa); //writes the result to the output file(output.dat)

	fclose(infile); // closes the input file (input.dat)
	fclose(outfile); // closes the output file (output.dat)

	return 0;
}