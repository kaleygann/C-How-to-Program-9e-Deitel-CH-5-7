/* 3.35
 * This program will ask user to
 * input a binary integer of five
 * digits or fewer containing only 0s
 * then pick off the digits one at a
 * time from right to right.
 */

#include <stdio.h>
#include <math.h>

int main() { //main header
    //initialize variables
    int num = 0;
    int dec = 0;
    int rem = 0;
    int j = 0;

    printf("%s", "Please enter a 5-digit integer consisting of only 1s and 0s: "); //prompt use for integer
    scanf_s("%d", &num); //read num value from kb

    while (num != 0){ //while loop
        rem = num % 10; //remainder of number divided by 10

        num /= 10; //set number to number divided by 10

        dec += (long)(rem * pow(2, j)); //add remainder times 2 to the power of j to decimal value
        j++; //increment j

    } //end while

    printf("The number in decimal is %d", dec); //output

} //end main
