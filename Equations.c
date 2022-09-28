/*                  *                    *                    *                     *                    *                   *
* Author: Randall Dickinson              Date Completed: 02.10.22                                                            *
* Instructor: AOFallen                   Class: Cpt_S 121                                                                    *
*                                                                                                                            *
* Analysis.c contains functions necessary for the calculations needed in main.c                                              *
*                                                                                                                            *
* The calculate_sum function is used to complement the calculate_mean and calculate_variance functions.                      *
* The calculate_mean function is used to complement the calculate_variance function.                                         *
* The calculate_deviation function is used to complement the calculate_variance function.                                    *
* The calculate_mean, caluclate_standard_deviation, calculate_max, and calculate_min functions output values to be written   *
* into the output.dat file.                                                                                                  *
*                   *                    *                    *                     *                    *                   *
*/

#include "Equations.h"

/*
* Name: read_double ()
* Description: To read a floating point number from a file
* History: Created 02.09.22
* Inputs: None
* Outputs: one number (double)
* Returns: next number in file (double)
* Precondition: Must be a real number
* Postcondition: Will contain the most recently read number
*/
double read_double(FILE* infile)
{
	double num = 0.0;

	fscanf(infile, "%lf", &num);

	return num;
}

/*
* Name: read_integer ()
* Description: To read an integer a file
* History: Created 02.09.22
* Inputs: None
* Outputs: one number (int)
* Returns: next integer in file (int)
* Precondition: Must be an integer
* Postcondition: Will contain the most recently read integer
*/
int read_integer(FILE* infile)
{
	int num = 0;

	fscanf(infile, "%d", &num);

	return num;
}

/*
* Name: calculate_sum ()
* Description: To determine the sum of five floating point numbers
* History: Created 02.07.22
* Inputs: Five numbers (double)
* Outputs: One number (double)
* Returns: sum of input numbers (double)
* Precondition: Must be floating point numbers or integers
* Postcondition: Will contain value of the sum of the numbers
*/
double calculate_sum(double number1, double number2, double number3, double number4, double number5)
{
	double sum = 0.0;

	sum = number1 + number2 + number3 + number4 + number5;

	return sum;
}

/*
* Name: calculate_mean ()
* Description: To determine the mean of a set of numbers
* History: Created 02.07.22
* Inputs: A number sum (double) and the number of values to be averaged (int)
* Outputs: One number (double)
* Returns: mean of input numbers (double)
* Precondition: Must be floating point numbers or integers, the number of values to be averaged must be positive
* Postcondition: Will contain value of the mean of the numbers
*/
double calculate_mean(double sum, int number)
{
	double mean = 0.0;

	mean = sum / number;

	return mean;
}

/*
* Name: calculate_deviation ()
* Description: To determine the deviation between a students GPA and the mean GPA
* History: Created 02.07.22
* Inputs: An individual students GPA and the mean GPA (double)
* Outputs: One number (double)
* Returns: deviation of the GPA (double)
* Precondition: Must be floating point numbers or integers
* Postcondition: Will contain value of the deviation
*/
double calculate_deviation(double number, double mean)
{
	double deviation = 0.0;

	deviation = number - mean;

	return deviation;
}

/*
* Name: calculate_variance ()
* Description: To determine variance from a set of numbers
* History: Created 02.09.22
* Inputs: Five deviations (double) and the number of deviations (int)
* Outputs: One number (double)
* Returns: Variance of input numbers (double)
* Precondition: Must be floating point numbers or integers, number of deviations must not be 0
* Postcondition: Will contain value of the variance
*/
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
	double sum = 0.0, variance = 0.0;

	sum = calculate_sum(pow(deviation1, 2), pow(deviation2, 2), pow(deviation3, 2), pow(deviation4, 2), pow(deviation5, 2)); // uses calculate_sum function to add the squares of each deviation

	variance = calculate_mean(sum, number); //uses calculate_mean function to find the variance from the sum of the deviations squares

	return variance;
}

/*
* Name: calculate_standard_deviation ()
* Description: To determine standard deviation from a variance
* History: Created 02.07.22
* Inputs: One variance (double)
* Outputs: One number (double)
* Returns: Standard Deviation of the input number (double)
* Precondition: Must be floating point numbers or integers, variance must be positive
* Postcondition: Will contain value of the standard deviation
*/
double calculate_standard_deviation(double variance)
{
	double std_dev = 0.0;

	std_dev = sqrt(variance);

	return std_dev;
}

/*
* Name: find_max ()
* Description: To determine the maximum from a set of input GPAs
* History: Created 02.08.22
* Inputs: Five GPAs (double)
* Outputs: One number (double)
* Returns: Maximum GPA (double)
* Precondition: Must be floating point numbers or integers
* Postcondition: Will contain value of the maximum GPA
*/
double find_max(double number1, double number2, double number3, double number4, double number5)
{
	double max = 0.0;

	if (number1 >= number2 && number1 >= number3 && number1 >= number4 && number1 >= number5)
	{
		max = number1;
	}
	else if (number2 >= number1 && number2 >= number3 && number2 >= number4 && number2 >= number5)
	{
		max = number2;
	}
	else if (number3 >= number1 && number3 >= number2 && number3 >= number4 && number3 >= number5)
	{
		max = number3;
	}
	else if (number4 >= number1 && number4 >= number2 && number4 >= number3 && number4 >= number5)
	{
		max = number4;
	}
	else if (number5 >= number1 && number5 >= number2 && number5 >= number3 && number5 >= number4)
	{
		max = number5;
	}
	return max;
}

/*
* Name: find_min ()
* Description: To determine the minimum from a set of input GPAs
* History: Created 02.08.22
* Inputs: Five GPAs (double)
* Outputs: One number (double)
* Returns: Minimum GPA (double)
* Precondition: Must be floating point numbers or integers
* Postcondition: Will contain value of the minimum GPA
*/
double find_min(double number1, double number2, double number3, double number4, double number5)
{
	double min = 0.0;

	if (number1 <= number2 && number1 <= number3 && number1 <= number4 && number1 <= number5)
	{
		min = number1;
	}
	else if (number2 <= number1 && number2 <= number3 && number2 <= number4 && number2 <= number5)
	{
		min = number2;
	}
	else if (number3 <= number1 && number3 <= number2 && number3 <= number4 && number3 <= number5)
	{
		min = number3;
	}
	else if (number4 <= number1 && number4 <= number2 && number4 <= number3 && number4 <= number5)
	{
		min = number4;
	}
	else if (number5 <= number1 && number5 <= number2 && number5 <= number3 && number5 <= number4)
	{
		min = number5;
	}
	return min;
}

/*
* Name: print_double ()
* Description: To write a floating point number to a file
* History: Created 02.09.22
* Inputs: one number (double)
* Outputs: number to file (double)
* Returns: None
* Precondition: Must be a real number
* Postcondition: None
*/
void print_double(FILE* outfile, double number)
{
	fprintf(outfile, "%.2lf\n", number);
}