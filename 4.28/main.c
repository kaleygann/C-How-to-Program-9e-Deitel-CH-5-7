/* 4.28
 * This program will prompt the user to
 * enter an employee code then calculate
 * that employee's pay based on employee code,
 * hours worked, and base pay.
 */

#include <stdio.h>

int main() { //main header

    //initialize variables
    int code, items;
    double salary, sales,
            hours, rate, price;


    while (code != EOF) { //while code does not equal to EOF (-1)

        printf("\nEnter employee code (-1 to end): "); //prompt user to enter employee code
        scanf_s("%d", &code); //read code value from kb

        switch(code) { //switch statement for code values

            case 1: //code is 1
            printf("\nMANAGER\nEnter weekly salary: "); //prompt user to enter manager salary
            scanf_s("%lf", &salary); //read salary value from kb
            printf("Pay: $%.2lf\n", salary); //print salary
            break; //break to reiterate loop

            case 2: //code is 2
            printf("\nHOURLY EMPLOYEE\nEnter hours worked: "); // prompt user to enter hourly employee hours
            scanf_s("%lf", &hours); //read hours value from kb
            printf("Enter hourly rate: "); //prompt user to enter hourly rate
            scanf_s("%lf", &rate); //read rate value from kb
            printf("Pay: $%.2lf\n", rate * hours); //calculate and print pay
            break; //break to reiterate loop

            case 3: //code is 3
            printf("\nCOMMISSIONED EMPLOYEE\nEnter gross sales: "); //prompt user to enter commissioned employee gross sales
            scanf_s("%lf", &sales); //read sales value from kb
            printf("Pay: $%.2lf\n", 250 + sales * 0.057); //calculate and print pay
            break; //break to reiterate loop

            case 4: //code is 4
            printf("\nPIECEWORKER\nEnter items sold: "); //prompt user to enter pieceworker items sold
            scanf_s("%d", &items); //read items value from kb
            printf("Enter price per item: "); //prompt user to enter price per item
            scanf_s("%lf", &price); //read item price value from kb
            printf("Pay: $%.2lf\n", price * items); //calculate and print pay

        } //end switch
    } //end while
} //end main
