/* 4.16
 * This program will print four separate
 * right triangles using loops.
 */

#include <stdio.h>

int main() {

    //initialize variables
    int rows = 10;
    int i, j, k = 0;

    //TRIANGLE A -------------------------------------------
    for (i = 1; i <= rows; ++i) { //for loop to iterate rows

         for (j = 1; j <= i; ++j) { //for loop to print stars

             printf("%s", "*"); //print one star

         } //end inner for

         printf("\n"); //new line

    } // end outer for

    printf("\n"); //new line

    //TRIANGLE B ------------------------------------------
    for(i = 1; i <= rows; ++i) { //for loop to iterate rows

        for (j = rows; j >= i; --j) { //for loop to print stars

            printf("%s", "*"); //print one star

        } //end inner for

        printf("\n"); //new line

    } //end outer for

    printf("\n"); //new line

    //TRIANGLE C -------------------------------------------

    for (i = 1; i <= rows; i++) { //for loop to iterate rows

        for (j = 1; j <= i; j++) { //for loop to print spaces

            printf(" "); //print one space

        } //end first inner for
        for (k = i; k <= rows; k++) { //for loop to print stars

            printf("%s", "*"); //print one star

        } //end second inner for

        printf ("\n"); //new line

    } //end outer for

    printf("\n"); //new line

    //TRIANGLE D -------------------------------------------
    for (i = 1; i <= rows; ++i) { //for loop to iterate rows

        for (j = rows; j >= i; --j) { //for loop to print spaces

            printf(" "); //print one space

        } //end first inner for

        for (k = 1; k <= i; ++k) { //for loop to print stars

            printf("%s", "*"); //print one star

        } //end second inner for

        printf("\n"); //new line

    } //end outer for

} //end main

