/* 3.22
 * This program will use a loop to print
 * the number 1 to 10 side by side on the
 * same line with three spaces between
 * the number.
 */

#include <stdio.h>

int main() { //main header

    int x = 1; //initialize x to 0

        while (x <= 10){ //while loop
            printf("%3d", x); //display x value
            x++; //increment x by 1
        } //end while
} //end main
