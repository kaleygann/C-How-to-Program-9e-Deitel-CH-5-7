/* 4.30
 * This program will rewrite Fig 4.5
 * by replacing switch with a nested
 * if...else statement then replace nested if
 * with series of if statements.
 */

// fig04_05.c
// Counting letter grades with switch.
#include <stdio.h>

int main(void) { //main header
    //initialize variables
    int aCount = 0;
    int bCount = 0;
    int cCount = 0;
    int dCount = 0;
    int fCount = 0;

    //prompt user to enter grades or EOF to end input
    puts("Enter the letter grades.");
    puts("Enter the EOF character to end input.");
    int grade = 0; // one grade

    // loop until user types end-of-file key sequence
    while ((grade = getchar()) != EOF) { //while loop

        // determine which grade was input
        if (grade == 'a' || grade == 'A') { //if grade is a or A
            ++aCount; //increment number of a's
            continue; //continue loop
        } //end if
        if (grade == 'b' || grade == 'B') { //else if grade is b or B
            ++bCount; //increment number of b's
            continue; //continue loop
        } //end if
       if (grade == 'c' || grade == 'C') { //if grade is c or C
            ++cCount; //increment number of c's
            continue; //continue loop
        } //end if
        if (grade == 'd' || grade == 'D') { //if grade is d or D
            ++dCount; //increment number of d's
            continue; //continue loop
        } //end if
        if (grade == 'f' || grade == 'F') { //if grade is f or F
            ++fCount; //increment number of f's
            continue; //continue loop
        } //end if
        if (grade == '\n' || grade == '\t' || grade == ' ') { //if grade is newline, tab, or space
            continue; //continue loop
        } //end if
        else { //catch all other characters
            printf("%s", "Incorrect letter grade entered."); //notify user of incorrect input
            puts(" Enter a new grade."); //prompt user to re-enter grade
            continue; //continue loop
        } //end else
    } // end while

    // output summary of results
    puts("\nTotals for each letter grade are:");
    printf("A: %d\n", aCount);
    printf("B: %d\n", bCount);
    printf("C: %d\n", cCount);
    printf("D: %d\n", dCount);
    printf("F: %d\n", fCount);
} //end main
