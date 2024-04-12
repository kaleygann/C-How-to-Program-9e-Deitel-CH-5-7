/* 4.11
 * This program will find the smallest of
 * several integers, assuming that the first
 * value read specifies the number of
 * values remaining.
 */

#include <stdio.h>

int main() { //main header
    //initialize variables
    int number, smallest, amt = 0;

    printf("Enter total number entries: "); //prompt user to enter amount of numbers
    scanf_s("%d", &amt); //read amount value from kb

    printf("Please enter a series of integers: "); //prompt user to enter numbers
    scanf_s("%d", &number); //read number value from kb

    smallest = number; //set smallest to current number

    for (int i = 2; i <= amt; i++) { //for loop

        scanf_s("%d", &number); //read number value from kb

            if (number < smallest) { //check if current number is less than current smallest
                smallest = number; //set current number to smallest
            } //end if
    } //end for

    printf("The smallest number is: %d", smallest); //print smallest number
} //end main
