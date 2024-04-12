/* 3.18
 * This program will get a salesperson's goals
 * for a given week then calculate and display
 * their earnings.
 */

#include <stdio.h>

int main() { //main header

    //initialize variables and constants
    float sales = 0;
    float salary = 0;
    const double BASE_PAY = 200.0;
    const double BONUS_PERCENT = .09;


    printf("%s", "\nEnter sales in dollars (-1 to end): "); //prompt user to enter sales
    scanf_s("%f", &sales); //read sales value from kb

        while (sales != -1){ //while loop

            salary = BASE_PAY + (BONUS_PERCENT * sales); //calculate salary
            printf("Salary is: $%.2f\n\n", salary); //display salary

            printf("%s", "Enter sales in dollars (-1 to end): "); //prompt user to enter sales
            scanf_s("%f", &sales); //read sales value from kb

        } //end while
} //end main
