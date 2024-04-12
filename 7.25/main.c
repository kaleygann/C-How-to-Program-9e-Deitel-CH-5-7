/* 7.25
 * This program will create a menu-driven program to allow the user to
 * choose whether to calculate a circle's circumference, a circle's area,
 * or a sphere's volume. */

#include <stdio.h>
#include <math.h>

// function prototypes
void circleCircumference(double r1);
void circleArea(double r2);
void sphereVolume(double r3);

int main(void) {

    // initialize array of 3 pointers to functions that each take an
    // double argument and return void
    void (*f[3])(double) = {circleCircumference, circleArea, sphereVolume};

    // menu header
    printf("--------------MENU--------------\n");
    printf("0 Calculate circle circumference\n1 Calculate circle area\n"
                    "2 Calculate sphere volume\n3 Quit program\nEnter option: ");

    // variables to store choice and radius values
    int choice = 0;
    double radius = 0.0;

    scanf("%d", &choice);  // get first choice from user

    // process user's choice
    while (choice >= 0 && choice < 3) {

        // prompt user to enter radius
        printf("\nEnter radius: ");
        scanf("%lf", &radius);

        // call function at location choice in array f and pass
        // choice as an argument
        (*f[choice])(radius);

        // prompt user to enter another option
        printf("\n--------------MENU--------------\n");
        printf("0 Calculate circle circumference\n1 Calculate circle area\n"
               "2 Calculate sphere volume\n3 Quit program\nEnter option: ");
        scanf_s("%d", &choice);
    }

    puts("Program finished.");
    return 0;
}

// function to calculate the circumference of a circle
void circleCircumference(double r1) {

    printf("\nCIRCLE CIRCUMFERENCE\n---------------------\n");

    // calculate diameter and circumference
    double diameter = r1 * 2;
    double circumference = diameter * M_PI;

    // print results
    printf("Diameter: %.2lf units\n", diameter);
    printf("Radius: %.2lf units\n", r1);
    printf("Circumference: %.2lf units\n", circumference);

}

// function to calculate the area of the circle
void circleArea(double r2) {

    printf("\nCIRCLE AREA\n-------------\n");

    // calculate area
    double area =  2 *  M_PI * pow(r2, 2);

    // print results
    printf("Radius: %.2lf units\n", r2);
    printf("Area: %.2lf square units\n", area);
}

// function to calculate the volume of a sphere
void sphereVolume(double r3) {

    printf("\nSPHERE VOLUME\n--------------\n");

    // calculate volume
    double volume = (4/3) * M_PI * pow(r3, 3);

    // print results
    printf("Radius %.2lf units\n", r3);
    printf("Volume: %.2lf cubic units\n", volume);

}
