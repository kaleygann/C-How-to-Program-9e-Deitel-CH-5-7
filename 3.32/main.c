/* 3.32
 * This program will read the side
 * of a square between numbers 1 and 20
 * then print the square out of asterisks.
 * */

#include <stdio.h>

int main(void) { //main header

    //initialize variables
    int size = 0;

    printf("%s", "Please enter a number between 1 and 20 for the size of the square: "); //prompt user to enter size
    scanf_s("%d", &size); //read size from kb

    if (size < 1 || size > 20){ //if statement
        printf("%s", "Invalid number. Please enter a size between 1 and 20: "); //prompt user to re-enter number
        scanf_s("%d", &size); //read size from kb
    } //end if

            for (int i = 0; i < size; i++) { //for loop
                for (int j = 0; j < size; j++) { //second for loop
                    printf("*"); //output
                } //end 2nd for
                puts(" "); //prints new line
            } //end 1st for
} //end main

