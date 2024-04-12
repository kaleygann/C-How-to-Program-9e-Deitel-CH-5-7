/* 4.14
 * This program will evaluate the
 * factorials of the integers from
 * 1 to 5 then display results in
 * a tabular format.
 */

#include <stdio.h>

int main() { //main header

    int fact = 0; //initialize variable

    printf("INTEGER\t\tFACTORIAL\n-------------------------\n");
    for (int i = 1; i <= 5; ++i) { //outer for loop
        fact = 1; //set factorial to 1

        for (int j = 1; j <= i; ++j) { //inner for loop
        fact *= j; //accumulate factorials by multiplying

        } //end inner for
        printf("%d\t\t", i); //display integers
        printf("%d\n", fact); //display factorials of integers

    } //end outer for
} //end main


