/* 3.26
 * This program will find the two largest
 * values from 10 numbers input by the user
 * then display them.
 */


#include <stdio.h>

int main() { //main header

    //initialize variables
    int counter = 1;
    int number, largest1, largest2 = 0;

    while (counter <= 10){ //while loop

        printf("%s", "Enter a non-negative number: "); //prompt user to enter a number
        scanf_s("%d", &number); //read number value from kb

        if (number > largest1){ //if statement
            largest2 = largest1; //set the two values equal to one another
            largest1 = number;//set largest to the current number
        } //end if

        else if(number > largest2){ //else statement
            largest2 = number; //set largest2 to current number
        }
        counter++; //increment counter
    } //end while

    printf("\nThe largest number is: %d\n", largest1); //display largest number
    printf("The second largest number is: %d\n", largest2); //display second largest number

} //end main
