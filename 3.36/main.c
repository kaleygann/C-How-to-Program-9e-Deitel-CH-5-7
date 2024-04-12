/* 3.36
 * This program will use a loop that
 * counts from 0 to 1,000,000,000
 * incrementing by 1 each iteration.
 * Every time the count reaches a multiple of
 * 100,000,000 the number will be displayed.
 */

#include <stdio.h>

int main() { //main header
    for (int num = 1; num <= 1000000000; num++) { //for loop
        if (num % 100000000 == 0) { //if remainder of number divided by 1 billion is equal to 0
            printf("%d\n", num); //display number
        } //end if
    } //end for
} //end main


