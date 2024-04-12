/* 3.41
 * This program will read the radius of
 * a circle then compute and display the
 * diameter, area, and circumference of
 * the circle.
 */

#include <stdio.h>
#include <math.h>

int main() { //main header
    //initialize variables
    double radius, diameter, circumference, area = 0.0;

    printf("%s", "Please enter the radius of the circle: "); //prompt user for radius
    scanf_s("%lf", &radius); //read radius value from kb

    diameter = radius * 2; //set diameter to radius times 2
    circumference = 2 * 3.14159 * radius; //circumference equal to 2 times pi times radius
    area = 3.14159 * pow(radius, 2); //area equal to pi times radius squared

    //display diameter, circumference, and area
    printf("Diameter: %.2lf\n", diameter);
    printf("Circumference: %.2lf\n", circumference);
    printf("Area: %.2lf", area);

} //end main
