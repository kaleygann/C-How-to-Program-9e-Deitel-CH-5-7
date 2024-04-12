/* 3.20
 * This program will determine the gross
 * pay for several different employees then
 * display number of hours worked, hourly
 * rate, and their salary.
 */

#include <stdio.h>

int main() {  //main header

    //initialize variables
    float hours = 0;
    float rate = 0;
    const float FULL_TIME = 40;

    printf("%s", "\nEnter # of hours worked (-1 to end): "); //prompt user for first # of hours worked
    scanf_s("%f", &hours); //read hours value from kb

        while (hours != -1){ //while loop

            printf("%s", "Enter hourly rate of the worker ($00.00): "); //prompt user for hourly rate
            scanf_s("%f", &rate); //read hourly rate value from kb

                if (hours <= FULL_TIME){ //if statement
                    printf("Salary is: $%.2f\n", rate * hours); //display regular salary
                } //end if
                else //else statement
                    //calculate and display salary with overtime
                    printf("Salary is: $%.2f\n", (rate * FULL_TIME) + (rate * 1.5) * (hours - FULL_TIME));

            printf("%s", "\nEnter # of hours worked (-1 to end): "); //prompt user to enter hours again
            scanf_s("%f", &hours); //read hours value from kb

        } //end while
} //end main
