/* 3.17
 * This program will determine whether a
 * customer has exceeded the credit limit
 * then displays all account information.
 */

#include <stdio.h>

int main(void) { //main header
    //initialize variables
    int account = 0;
    double balance = 0;
    double charges = 0;
    double credits = 0;
    double limit = 0;

    printf("%s", "Enter account number (-1 to end): "); //prompt user to enter acccount number
    scanf_s("%d", &account); //read account number value from kb

    while (account != -1) { //while account number does not equal to -1

        printf("%s", "Enter beginning balance: "); //prompt user to enter balance
        scanf_s("%lf", &balance); //read balance from kb

        printf("%s", "Enter total charges: "); //prompt user to enter total charges
        scanf_s("%lf", &charges); //read charges value from kb

        printf("%s", "Enter total credits: "); //prompt user to enter total credits
        scanf_s("%lf", &credits); //read credits value from kb

        printf("%s", "Enter credit limit: "); //prompt user to enter credit limit
        scanf_s("%lf", &limit); //read limit value from kb

        double newBal = balance + charges - credits; //calculate new balance

        if (newBal > balance) { //if new balance is greater than beginning balance
            //display account, limit, and new balance
            printf("\nAccount:\t%d\n", account);
            printf("Credit limit:\t%.2lf\n", limit);
            printf("Balance:\t%.2lf\n", newBal);
            printf("%s", "Credit Limit Exceeded.\n"); //display credit limit exceeded
        } //end if

        printf("%s", "\nEnter account number (-1 to end): "); //re-prompt user for account number
        scanf_s("%d", &account); //read account value from kb
    } //end while

 } // end main