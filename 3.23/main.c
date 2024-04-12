/* 3.23
 * this program will use a loop to
 * find the largest number in a group
 * of numbers input by the user then
 * display the largest number found.
 */

#include <stdio.h>

int main() { //main header

    //initialize variables
    int counter = 1;
    int number, largest = 0;

        while (counter <= 10){ //while loop

            printf("%s", "Enter a non-negative number: "); //prompt user to enter a number
            scanf_s("%d", &number); //read number value from kb

                if (number > largest){ //if current number is greater to current largest value
                    largest = number; //set largest to the current number
                } //end if
            counter++; //increment counter
        } //end while

    printf("\nThe largest number is: %d\n", largest); //display largest number

} //end main
