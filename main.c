/*******************************************************************************************

* Programmer: Randall Dickinson                                                            *

* Class: CptS 121, Spring 2022; Lab Section 08                                             *

* Programming Assignment: Lab1Task2                                                        *

* Date: January 26, 2022                                                                   *

* Description: This program will perform a series of calculations                          *

*******************************************************************************************/


#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings



#include <stdio.h> // necessary to use printf () and scanf ()



int main(void) // the starting point for all C programs

{

    // we need to request memory for

    int number1_int = 0, number2_int = 0, number_sum = 0, number_product = 0, number_int_quotient = 0;
    int number5_int = 0, number7_int = 0, number8_one = 0, number8_two = 0, voltage = 0, resistance = 0;
    int power = 0, a10 = 0, b10 = 0, c10 = 0, d10 = 0, x10 = 0;
    // 2 variable declarations - reserves two memory blocks for integers and sets them to 0's

    double number1_float = 0.0, number2_float = 0.0, number_difference = 0, number_float_quotient = 0.00;
    double number5_float = 0.0, number6_float = 0.0, number10_float = 0.0, x1 = 0.0, x2 = 0.0, y1 = 0.0;
    double y2 = 0.0, xmid = 0.0, ymid = 0.0, slope = 0.0, bisector = 0.0, yint = 0;
    double height = 0.0, weight = 0.0, bmi = 0.0;

    // reserves two memory blocks for numbers with high precision (floating-point)



    printf("Enter two integer values: "); // ask the user

    scanf("%d%d", &number1_int, &number2_int); // read the integers typed through the keyboard - %d is for "decimal", i.e. integers



    printf("Enter two floating-point values: "); // ask the user

    scanf("%lf%lf", &number1_float, &number2_float); // read the integers typed through the keyboard - %lf is for "long float", i.e. double precision numbers


    
    // place all code for the subtasks/operations below here

    //1. Add number1_int and number2_int together and print the result as an integer value
    number_sum = number1_int + number2_int;
    printf("\nThe sum of the integers is %d\n", number_sum);

    //2. Subtract number1_float from number2_float and print the result as a floating-point value
    number_difference = number1_float - number2_float; 
    printf("\nThe difference of your two float numbers is %lf\n", number_difference);

    //3. Multiply number1_int by number1_float and print the result as an integer value
    number_product = number1_int * number1_float;
    printf("\nThe integer product of integer 1 and float number 1 is %d\n", number_product);

    //4. Divide number1_int by number2_int and print the result as an integer and a floating-point value
    number_int_quotient = number1_int / number2_int;
    (double)number_float_quotient = (double)number1_int / (double)number2_int;
    printf("\nThe integer value of integer 1 divided by integer 2 is %d\n", number_int_quotient);
    printf("\nThe float value of integer 1 divided by integer 2 is %lf\n", number_float_quotient);

    //5. Divide number1_int by number2_float and print the result as an integer and a floating-point value (Ask yourself: How does this compare to the previous operations? We are now dealing with mixed data types.)
    number5_float = (double)number1_int / number2_float;
    number5_int = number1_int / (int)number2_float;
    printf("\nThe integer value of integer 1 divided by float number 2 is %d\n", number5_int);
    printf("\nThe floating point value of integer 1 divided by float number 2 is %lf\n", number5_float);

    //6. Explicitly cast number1_int as a floating-point value and divide by number2_int. Print the result as a floating-point value.
    number6_float = (double)number1_int / number2_int;
    printf("\nThe floating point value of integer 1 divided by integer 2 is %lf\n", number6_float);

    //7. Try to mod number1_float by number2_float
    number7_int = (int)number1_float % (int)number2_float;
    printf("\nThe modulus of floating point 1 divided by floating point 2 is %d\n", number7_int);

    //8. Determine if number1_int and number2_int are even or odd. Print 0 if even and 1 if odd
    number8_one = number1_int % 2;
    number8_two = number2_int % 2;
    printf("\n%d\n", number8_one);
    printf("\n%d\n", number8_two);

    //9. Prompt the user for inputs for Joule's Law, and compute power
    printf("\nJoule's Law: P = V^2/R. Please enter integer values for V and then R\n");
    scanf("%d %d", &voltage, &resistance);
    power = (voltage * voltage) / resistance;
    printf("\nThe power is %d\n", power);

    //10.Write a program that prompts the user for inputs into a third order equation and display the results
    printf("\n Enter inputs in the order a,b,c,d,x for the equation  y = 3 * ax^3 + (1/4) * bx^2 + 10 * cx + (-5) * d.\n");
    scanf("%d %d %d %d %d", &a10, &b10, &c10, &d10, &x10);
    number10_float = (3 * a10 * (x10 * x10 * x10)) + (((double)b10 * (double)x10 * (double)x10) / 4) + (10 * c10 * x10) + (-5 * d10);
    printf("\nThe float value of the result is %lf\n", number10_float);

    //11. Prompt the user for the coordinates of the two points. Calculate the equation of the perpendicular bisector of this line.

    printf("\nplease enter values for x1, y1, x2, and y2 in that order\n");
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    slope = (y2 - y1) / (x2 - x1);
    bisector = -1 / slope;
    xmid = (x1 + x2) / 2;
    ymid = (y1 + y2) / 2;
    yint = ymid - (bisector * xmid);
    printf("\nThe points you have entered are (%lf , %lf) and (%lf , %lf) \n and the equation of the perpendicular bisector of the line segment is y = %lfx + %lf\n", x1, y1, x2, y2, bisector, yint);

    //12. Write a program to calculate your body mass index (BMI). The BMI is a measurement that 
    // uses your height and weight to determine if you are underweight, a healthy weight, or overweight. 
    //Your program is required to prompt the user for weight in pounds and height in feet. The height 
    //must then be converted to inches (recall: 1 foot = 12 inches). Once the BMI has been calculated display 
    //the resultant BMI value. Use the equation below to calculate the BMI.
    //BMI = ((weight in pounds) / (height in inches) ^ 2) * 703
    printf("\nEnter your weight in lbs and your height in feet as floating point numbers\n");
    scanf("%lf %lf", &weight, &height);
    bmi = (703 * weight) / (144 * height * height);
    printf("\nYour bmi is %lf\n", bmi);



    return 0; // return a success status (value 0) indicating the program worked fine

} // end of the main () function