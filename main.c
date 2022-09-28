/*
Author: Randall Dickinson              Date Completed: 01.28.22
Instructor: AOFallen                   Class: Cpt_S 121

This program will notify the user of a specific equation, prompt the user for variable
data for the equation, calculate the result, and display the result to the user.

Equation 1 is covered in steps 1-3
Equation 2 is covered in steps 4-6
Equation 3 is covered in steps 7-9
Equation 4 is covered in steps 10-12
Equation 5 is covered in steps 13-15
Equation 6 is covered in steps 16-18
Equation 7 is covered in steps 19-21

*/

#include "equations.h"

int main(void) //the starting point of the program
{
    //we need to request memory for

    char encoded_character = 'a', plaintext_character = 'a'; //2 variable declarations for use in equation 3

    double mass1 = 0.0, acceleration = 0.0, force1 = 0.0, radius = 0.0, height = 0.0;
    double volume = 0.0, force4 = 0.0, mass4 = 0.0, mass4_second = 0.0, distance4 = 0.0;
    double r1 = 0.0, r2 = 0.0, vin = 0.0, vout = 0.0, x1 = 0.0, x2 = 0.0, y1 = 0.0;
    double y2 = 0.0, distance6 = 0.0, z_variable = 0.0, x_variable = 0.0, general_equation = 0.0;
    //22 variable declarations for precision calculations

    int offset = 0, a_variable = 0; //2 variable declarations for use in equations 3 and 7

    //1. Notify user of equation
    printf("This program will calculate force in Newtons from mass and acceleration values. \nNewtons Second Law: Force = mass * acceleration.\n");

    //2. Get the object mass and acceleration from the user
    printf("\nEnter the object mass in kg> ");
    scanf("%lf", &mass1);
    printf("\nEnter the object acceleration in m/s^2> ");
    scanf("%lf", &acceleration);

    //3. Calculate the force value and display it to the user
    force1 = calculate_newtons_2nd_law(mass1, acceleration);
    printf("\nThe force of the object is %lf * %lf = %.2lf Newtons\n", mass1, acceleration, force1);

    //4. Notify user of second equation
    printf("\nThis program will calculate the volume of a cylinder from its radius and height. \nCylinder Volume: PI * radius^2 * height\n");

    //5. Get the cylinder radius and height from the user
    printf("\nEnter the cylinder radius in meters> ");
    scanf("%lf", &radius);
    printf("\nEnter the cylinder height in meters> ");
    scanf("%lf", &height);

    //6. Calculate the cylinder volume and display to the user
    volume = calculate_volume_cylinder(radius, height);
    printf("\nThe volume of the cylinder is %lf * %lf^2 * %lf = %.2lf cubic meters\n", PI, radius, height, volume);

    //7. Notify user of third equation
    printf("\nThis program will perform character encoding given an integer number and a character. \nEncoded Character = Offset + Plaintext Character\n");

    //8. Get the plaintext character and offset from the user
    printf("\nEnter the plaintext character to be encoded> ");
    scanf(" %c", &plaintext_character);
    printf("\nEnter an integer value for character encoding offset> ");
    scanf("%d", &offset);


    //9. Calculate the encoded character and display to the user
    encoded_character = perform_character_encoding(plaintext_character, offset);
    printf("\nYour plaintext character was ""%c"" with an offset of %d, \nresulting in an encoded character of ""%c""\n", plaintext_character, offset, encoded_character);

    //10. Notify user of fourth equation
    printf("\nThis program will calculate gravitational force. \nForce = G (gravitational constant = 6.67 * 10^-11) * mass 1 * mass 2 / distance^2\n");

    //11. Get the first mass, second mass, and distance from the user
    printf("\nEnter the value for mass1> ");
    scanf("%lf", &mass4);
    printf("\nEnter the value for mass2> ");
    scanf("%lf", &mass4_second);
    printf("\nEnter the distance> ");
    scanf("%lf", &distance4);

    //12. Calculate the gravitational force and display to the user
    force4 = calculate_gravitational_force(mass4, mass4_second, distance4);
    printf("\nThe gravitational force is %.13lf * %lf * %lf / %lf^2 = %.2lf\n", G, mass4, mass4_second, distance4, force4);

    //13. Notify the user of the fifth equation
    printf("\nThis program will calculate resistive divider. \nVout = r2 / (r1 + r2) * vin\n");

    //14. Get the r1, r2, and vin values from the user
    printf("\nEnter the r1 value> ");
    scanf("%lf", &r1);
    printf("\nEnter the r2 value> ");
    scanf("%lf", &r2);
    printf("\nEnter the vin value> ");
    scanf("%lf", &vin);

    //15. Calculate vout and display to the user
    vout = calculate_resistive_divider(r1, r2, vin);
    printf("\nThe vout is %lf / (%lf + %lf) * %lf = %.2lf\n", r2, r1, r2, vin, vout);

    //16. Notify the user of the sixth equation
    printf("\nThis program will calculate distance between two points. \nDistance = square root ((x1-x2)^2 + (y1-y2)^2)\n");

    //17. Get the two pairs of coordinates from the user
    printf("\nEnter the value of x1> ");
    scanf("%lf", &x1);
    printf("\nEnter the value of y1> ");
    scanf("%lf", &y1);
    printf("\nEnter the value of x2> ");
    scanf("%lf", &x2);
    printf("\nEnter the value of y2> ");
    scanf("%lf", &y2);

    //18. Calculate the distance and display to the user
    distance6 = calculate_distance_between_points(x1, x2, y1, y2);
    printf("\nThe distance between (%lf,%lf) and (%lf,%lf) is %.2lf\n", x1, y1, x2, y2, distance6);

    //19. Notify the user of the seventh equation
    printf("\nThis program will calculate the result of an equation, given three variables. \nThe equation is y = (89/27) - z * x + a / (a %% 2)\n");

    //20. Get the z, x, and a values
    printf("\nEnter a floating point number for value z> ");
    scanf("%lf", &z_variable);
    printf("\nEnter a floating point number for value x> ");
    scanf("%lf", &x_variable);
    printf("\nEnter an integer value for a> ");
    scanf("%d", &a_variable);

    //21. Calculate the value of the equation and display to the user
    general_equation = calculate_general_equation(z_variable, x_variable, a_variable);
    printf("\nYour equation is (89/27) * - %lf * %lf + %d / %d %% 2 = %.2lf\n", z_variable, x_variable, a_variable, a_variable, general_equation);


    return 0; //return a success status (value 0) indicating the program worked fine

} //end of main function
