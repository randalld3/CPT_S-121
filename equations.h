

#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings
#define PI 3.141592 //constant macro for pi
#define G .0000000000667 //constant macro for gravitational constant

#include <stdio.h> //necessary to use printf () and scanf ()
#include <math.h> //necessary to use sqrt ()


double calculate_newtons_2nd_law(double mass, double acceleration);
double calculate_volume_cylinder(double radius, double height);
char perform_character_encoding(char plaintext_character, int offset);
double calculate_gravitational_force(double first_mass, double second_mass, double distance);
double calculate_resistive_divider(double r1, double r2, double vin);
double calculate_distance_between_points(double x1, double y1, double x2, double y2);
double calculate_general_equation(double z_variable, double x_variable, int a_variable);
