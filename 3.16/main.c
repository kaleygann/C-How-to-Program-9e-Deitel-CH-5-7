/* 3.16
 * This program will allow the user to input
 * the amount of miles driven and gallons
 * of gas used for each tankful then calculate
 * and display the average miles per gallon
 * obtained from each tankful.
 */

#include <stdio.h>

int main() //main header
{
    //initialize variables
    float gallons = 0;
    int miles = 0;
    float totGal = 0;
    int totMiles = 0;
    int count = 0;

        printf("\nEnter the gallons used (-1 to end): "); //prompt user to enter gallons used
        scanf_s("%f", &gallons); //read value from kb

        while (gallons != -1) { //while loop

            printf("Enter the miles driven: "); //prompt user to enter miles driven
            scanf_s("%d", &miles); //read value from kb

            float average = (float)miles/gallons; //set average to miles divided by gallons

            printf("The miles/gallon for this tank was: %f\n\n", average); //display average

            totGal += gallons; //add all gallons
            totMiles += miles; //add all miles

            printf("Enter the gallons used (-1 to end): "); //prompt user to enter gallons used
            scanf_s("%f", &gallons); //read gallons value from kb

            count++; //increment count

        } //end while

        float totAvg = (float)totMiles / totGal; //divide total miles by total gallons

        if (count != 0)  //if statement
            //display overall average
            printf("The overall average miles/gallon was %f\n", totAvg);

    } //end main

