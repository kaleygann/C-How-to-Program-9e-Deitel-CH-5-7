/* 5.22
 * This program will use functions
 * to separate the digits in an integer
 * between 1 and 32767 then print the
 * series of digits.
 */

#include <stdio.h>

//function prototypes
int getQuotient(int, int);
int getRemainder(int, int);

int main() {  //main header

    //local variables
    int a = 0;
    int b = 10000;

    printf("Enter a number between 1 and 32767: ");  //prompt user to enter a number
    scanf_s("%d", &a);  //read number value from kb

    while (a >= 1 && a <= 32767) {  //loop iterates when number is in range

        if (getQuotient(a, b) != 0) {  //if loop to ensure initial 0s are not printed
            printf("%d  ", getQuotient(a, b));  //display number
            a = getRemainder(a, b);  //set number to remainder
        }  //end if
        b /= 10;  //change divisor value
    }  //end while

}  //end main

/* function getQuotient calculates
 * the number divided by the divisor
 * then returns value */

int getQuotient(int a, int b) {
    return a / b;
}  //end function

/* function getRemainder calculates
 * the remainder of the current value
 * of a divided by divisor then returns
 * the value */

int getRemainder(int a, int b) {
    return a % b;
}  //end function
