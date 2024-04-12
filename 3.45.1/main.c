/* 3.45 pt. 1
 * This program will read a non-negative
 * integer and compute and print its factorial.
 */

#include <stdio.h>

int main() { //main header
    //initialize variables
    int num = 0;
    int total = 1;

    printf("%s", "Please enter a non-negative integer: "); //prompt user for integer
    scanf_s("%d", &num); //read num value from kb

    for (int i = 1; i <= num; i++){ //for loop, increments i
        total *= i; //accumulate total by multiplying by i each iteration
    } //end for
    printf("The factorial of %d is: %d", num, total); //print factorial
} //end main
