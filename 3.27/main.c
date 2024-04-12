/* 3.27
 * This program will modify the program from
 * Fig 3.06 in the textbook to validate its
 * inputs. If the value is other than 1 or 2,
 * the loop will continue until the user enters
 * a correct value.
 */
// fig03_06.c
// Analysis of examination results.
#include <stdio.h>

// function main begins program execution
int main(void) {

    // initialize variables in definitions
    int passes = 0;
    int failures = 0;
    int student = 1;

            while (student <= 10) { //while loop
                printf("%s", "Enter result (1=pass,2=fail): "); // prompt user for input and obtain value from user
                int result = 0; //int result = 0; // one exam result
                scanf_s("%d", &result); //read result value from kb
                //if result 1, increment passes
                if (result == 1) { //if statement
                    passes++; //increment passes
                } //end if
                else if (result == 2) { //else if statement
                    failures++; //increment failures
                } //end else if
                else { //else statement
                    printf("%s", "Invalid number. Please try again.\n\n"); //prompt user to input valid number
                    student--; //decrement student counter so invalid input does not count
                } //end else
                student++; //increment student counter
            } //end while

            //display number of passes and failures
            printf("Passed %d\n", passes);
            printf("Failed %d\n", failures);

            //if more than eight students passed, print "Bonus to instructor!"
            if (passes > 8) {
                puts("Bonus to instructor!");
            } //end if

} //end main