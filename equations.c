
#include "equations.h"

double calculate_newtons_2nd_law(double mass, double acceleration) //beginning of newton's second law function
{
    double  resulting_force = 0.0; //local variable, can only be used inside calculate_newtons_second_law

    resulting_force = mass * acceleration;

    return resulting_force; //copies the contents of resulting_force

}



double calculate_volume_cylinder(double radius, double height) //beginning of cylinder volume function
{
    double  volume = 0.0; //local variable, can only be used inside calculate_volume_cylinder

    volume = PI * radius * radius * height;

    return volume; //copies the contents of volume

}



char perform_character_encoding(char plaintext_character, int offset) //beginning of character encoding function
{
    char encoded_character = 'a'; //local variable, can only be used inside perform_character_encoding

    encoded_character = offset + plaintext_character;

    return encoded_character; //copies the contents of encoded_character

}



double calculate_gravitational_force(double first_mass, double second_mass, double distance) //beginning of calculate_gravitational_force function
{
    double force = 0.00; // local variable, can only be used in calculate_gravitational_force

    force = G * (first_mass * second_mass) / pow(distance, 2);

    return force; //copies the contents of force

}



double calculate_resistive_divider(double r1, double r2, double vin) //beginnning of calculate_resistive_divider function
{
    double vout = 0.0; //local variable, can only be used in calculate_resistive_divider

    vout = r2 / (r1 + r2) * vin;

    return vout; //copies the contents of vout

}



double calculate_distance_between_points(double x1, double y1, double x2, double y2) //beginning of calculate_distance_between_points function
{
    double distance = 0.0; //local variable, can only be used in calculate_distance_between_points function

    distance = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

    return distance; //copies the contents of distance

}



double calculate_general_equation(double z_variable, double x_variable, int a_variable) //beginning of calculate_general_equation function
{
    double general_equation_solution = 0.0; //local variable, can only be used in calculate_general_equation

    general_equation_solution = ((double)89 / (double)27) - (z_variable * x_variable) + (a_variable / (a_variable % 2));

    return general_equation_solution; //copies the contents of general_equation_solution
}
