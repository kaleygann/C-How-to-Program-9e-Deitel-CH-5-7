/* 6.10
 * This program will use a one-dimensional
 * array of counters to determine how many
 * salespeople (employees) earned salaries
 * in a set of ranges. */

#include <stdio.h>

// symbolic constants
#define BASE 200
#define PERCENT_GROSS .09
#define SIZE 9

// function prototypes
void set_pay(int e[], int gross);
void print_results(const int e[]);

int main() {

    int gross_sales;

    // declare array employee[]
    int employee[SIZE] = {};

    // loop to continue receiving input from user
    while (gross_sales != EOF) {

        // prompt user for input
        printf("Enter gross sales (-1 to quit): ");
        scanf_s("%d", &gross_sales);

        if (gross_sales != EOF) {  // call function when EOF value is not input
            set_pay(employee, gross_sales);
        }
    }  // end while

    // function calls
    print_results(employee);

}  // end main


 /* function set_pay(int e[]) accepts
 * calculates the pay based on user input
  * of gross sales */

void set_pay(int e[], int gross) {

    // local variable
    int pay;

    // calculate pay and increment employees in pay brackets

        pay = BASE + (gross * PERCENT_GROSS);

        if (pay >= 200 && pay <= 299)
            e[0]++;
        else if (pay <= 399)
            e[1]++;
        else if (pay <= 499)
            e[2]++;
        else if (pay <= 599)
            e[3]++;
        else if (pay <= 699)
            e[4]++;
        else if (pay <= 799)
            e[5]++;
        else if (pay <= 899)
            e[6]++;
        else if (pay <= 999)
            e[7]++;
        else
            e[8]++;

}  // end set_pay()

/* function print_results(const int e[])
 * prints total number of employees
 * in each pay bracket. */

void print_results(const int e[]) {

    printf("\na) $200-299: %d", e[0]);
    printf("\nb) $300-399: %d", e[1]);
    printf("\nc) $400-499: %d", e[2]);
    printf("\nd) $500-599: %d", e[3]);
    printf("\ne) $600-699: %d", e[4]);
    printf("\nf) $700-799: %d", e[5]);
    printf("\ng) $800-899: %d", e[6]);
    printf("\nh) $900-999: %d", e[7]);
    printf("\ni) $1000 and over: %d", e[8]);

}  // end print_results()


