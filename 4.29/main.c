/* 4.29
 * This program will demonstrate how
 * certain logical expressions are
 * equivalent to each other.
 */

#include <stdio.h>

int main() { //main header
    //initialize variables
    int x = 9;
    int y = 3;
    int a = 10;
    int b = 10;
    int g = 5;
    int i = 3;
    int j = 7;


    /* use if statements to test if the two
     * expressions are equal to each other
     * and print "True" if they are
     * equivalent.
     */

    // A--------------------
    if (!(x < 5) && !(y >= 7)) { //if statement
        printf("True\n"); //output
    } //end if
    if (!(x < 5 || y >= 7)) {
        printf("True\n\n");
    }
    // B---------------------
    if (!(a == b) || !(g != 5)) { //if statement
        printf("True\n"); //output
    } //end if
    if (!(a == b && g != 5)) {
        printf("True\n\n");
    }
    // C----------------------
    if (!(x <= 8 && y > 4)) { //if statement
        printf("True\n"); //output
    } //end if
    if (!(x <= 8) || !(y > 4)) {
        printf("True\n\n");
    }
    // D-----------------------
    if (!(i > 4 || j <= 6)) { //if statement
        printf("True\n"); //output
    } //end if
    if  (!(i > 4) && !(j <= 6)) {
        printf("True\n");
    }
} //end main

