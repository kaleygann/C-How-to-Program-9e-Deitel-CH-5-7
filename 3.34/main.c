/* 3.34
 * This program will read a five-digit
 * integer and determine whether it's
 * a palindrome.
 */

#include <stdio.h>

int main() { //main header
    //initialize variables
    int num, num2, temp, sum = 0;

    printf("%s", "\nPlease enter a five-digit integer: "); //prompt user for 5-digit integer
    scanf_s("%d", &num); //read integer value from kb
    temp = num; //

    while (num > 0){ //while loop
        num2 = num % 10; //store value num % 10 in num2
        sum = (sum * 10) + num2; //multiply sum by 10 then add number value
        num = num / 10; //set number value
    } //end while

    if (temp == sum){ //compare temp value and sum value
        printf("%s", "The number is a palindrome.\n"); //output
    } //end if
    else //else statement
        printf("%s", "The number is not a palindrome.\n"); //output

    return(0); //exit
} //end main
