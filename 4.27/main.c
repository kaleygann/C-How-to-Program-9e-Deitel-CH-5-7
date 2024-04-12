/* 4.27
 * This program will find all Pythagorean
 * triples for each side of a triangle for
 * all values of 500 or less, using triple
 * nested for loop.
 */

#include <stdio.h>
#include <math.h>

int main() { //main header

    printf("SIDE1\tSIDE2\tSIDE3\n---------------------\n"); //table header

    for (int i = 1; i <= 500; ++i) { //for loop for side1

        for (int j = 1; j <= 500; ++j) { //for loop for side2

            for (int k = 1; k <= 500; ++k) { //for loop for hypotenuse

                //initialize variables to store side values
                int side1 = i;
                int side2 = j;
                int hyp = k;

                if (pow(side1, 2) + pow(side2, 2) == pow(hyp, 2)) { //check if pythagorean triple equation is true

                    printf("%d\t%d\t%d\n", side1, side2, hyp); //print side values (not squared)

                } //end if
            } //end second inner for
        } //end first inner for
    } //end outer for
} //end main
