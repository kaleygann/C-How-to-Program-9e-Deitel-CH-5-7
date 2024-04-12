/* 4.10
 * This program will calculate and print the
 * average of several integers input by the
 * user. The last value read with scanf
 * is the sentinel 9999.
 */

#include <stdio.h>

int main() {
    //initialize variables
    int number = 0;
    int count = 0;
    float sum = 0;
    float average = 0;

    printf("Enter a series of integers to average:\n"); //prompt user to enter integers

    while(number != 9999) //while loop iterates when number is not 9999
    {
        scanf_s ("%d",&number); //read numbers from kb

        if (number == 9999) //check if number equals 9999
            break; //break the loop if number equals 9999
        else
            sum = sum + (float)number; //accumulate sum of numbers

        count++; //increment count
    } //end while

    average = (sum / (float)count); //calculate average of numbers

    printf("Average: %.4f",average); //display average

} //end main

