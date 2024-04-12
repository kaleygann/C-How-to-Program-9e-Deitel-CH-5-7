/* 4.25
 * This program will print a table of the
 * binary, octal and hexadecimal equivalents
 * of numbers 1-256.
 */

#include <stdio.h>

int main() { //main header

    printf("%s", "NUMBER\t\tBINARY\t\tOCTAL\t\tHEXADECIMAL\n-----------------------------------------------------------\n"); //display table header

    for (int n = 1; n <= 256; ++n) { //for loop to iterate numbers 1 through 256

        printf("%d\t\t", n); //print numbers

        //initialize variables for finding binary numbers
        int x = n;
        int i = 1;
        int binary = 0;

        while (x != 0) { //while loop to generate binary numbers

            int remainder = x % 2; //get remainder of number divided by two
            x /= 2; //divide number by two and store value in x
            binary += remainder * i; //accumulate binary value
            i *= 10; //accumulate i value

        } //end while

        printf("%d\t\t", binary); //display binary values
        printf("%o\t\t", n); //display octal values
        printf("%X\n", n); //display hexadecimal values

    } //end for
} //end main
