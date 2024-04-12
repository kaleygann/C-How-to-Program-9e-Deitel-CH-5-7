/* 3.37
 * This program will print 100
 * asterisks, one at a time. After
 * every tenth asterisk, a newline
 * character will be printed.
 */

#include <stdio.h>

int main() { //main header

    for (int i = 1; i <= 110; i++){ //for loop
        if (i % 11 == 1){ //if the remainder of i divided by 11 is equal to one
            printf("\n"); //print newline
        } //end if
        else //else statement
            printf("%s\n", "*"); //display asterisks if remainder is not equal to 1
    } //end else
} //end main
