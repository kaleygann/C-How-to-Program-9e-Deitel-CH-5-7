/* 3.19
 * This program will calculate interest
 * charges for several loans then display
 * the interest principal, interest late,
 * loan term, and interest charges.
 */

#include <stdio.h>

int main() { //main header

    //initialize variables
    float principal = 0;
    float interestRate = 0;
    int term = 0;
    float interest = 0;

    printf("%s", "\nEnter loan principal (-1 to end): "); //prompt user to enter principal
    scanf_s("%f", &principal); //read principal value from kb

        while (principal != -1) { //while loop

            printf("%s", "Enter interest rate: "); //prompt user to enter interest rate
            scanf_s("%f", &interestRate); //read interest rate value from kb

            printf("%s", "Enter the term of the loan in days: "); //prompt user to enter loan term
            scanf_s("%d", &term); //read term value from kb

            interest = principal * interestRate * ((float)term / 365); //calculate total interest charges

            printf("The interest charge is: $%.2f\n", interest); //display interest charge

            printf("%s", "\nEnter loan principal (-1 to end): "); //prompt user to enter principal
            scanf_s("%f", &principal); //read principal value from kb

        } //end while
} //end main

