/* 5.9
 * This program will calculate parking
 * charges for three separate vehicles
 * then display the results in a tabular
 * format.
 */

#include <stdio.h>

float calculateCharges(float); //function prototype

int main() { //main header

    float hours1, hours2, hours3, hours; //main local variables

    for (int car = 1; car <= 3; ++car) { //for loop

        printf("Enter car #%d parking hours: ", car); //prompt user to enter parking hours
        scanf_s("%f", &hours); //read hours value from kb

        if (car == 1) //first car
            hours1 = hours; //store first car's hours

        else if (car == 2) //second car
            hours2 = hours; //store second car's hours

        else //third car
            hours3 = hours; //store third car's hours
    } //end for

    //output values in tabular format
    printf( "\nCar\t\tHours\t\tCost\n");
    printf( "%d\t\t%.1f\t\t%.2f\n", 1, hours1, calculateCharges(hours1));
    printf( "%d\t\t%.1f\t\t%.2f\n", 2, hours2, calculateCharges(hours2));
    printf( "%d\t\t%.1f\t\t%.2f\n", 3, hours3, calculateCharges(hours3));

    //calculate total hours and total charges
    float totalHours = hours1 + hours2 + hours3;
    float totalCharges = calculateCharges(hours1) + calculateCharges(hours2) + calculateCharges(hours3);

    printf( "%s\t\t%.1f\t\t%.2f\n", "TOTAL", totalHours, totalCharges); //display totals

} //end main

float calculateCharges(float hours) { //function header

    float charge = 2; //base charge value is 2.00

    if (hours > 0 && hours <= 3) { //if hours are between 0 and 3
        return charge; //return base value of charge
    } //end if

    while (hours > 3 && hours <= 24) { //while hours are between 3 and 24

        charge += .50; //accumulate charge value
        --hours; //decrement hours

        if (charge >= 10) //if charge reaches 10, it's maxed out
            charge = 10; //set charge to 10

    } //end while

    return charge; //return charge value

} //end function


