/* 5.49
 * This program will produce two positive
 * integers then ask the user what the product
 * of the two integers is. The user may try the
 * problem continually until they answer correctly,
 * then they will be prompted to answer another
 * problem.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
int getFirstNumber(int);
int getSecondNumber(int);


int main() {  //main header

    //local variables
    int num1, num2;
    int a, b;
    int answer, product = 0;
    char keepGoing = 'y';

    //seed random generator
    srand(time(0));

    //while keepGoing is not no
    while (keepGoing == 'y' || keepGoing == 'Y') {

        //local variables
        a = getFirstNumber(num1);
        b = getSecondNumber(num2);

        printf("\nHow much is %d times %d?", a, b);  //ask user to answer question
        scanf_s("%d", &answer);  //read user's answer from kb

        product = a * b;  //calculate product of the two numbers

        if (answer == product) {  //if answer is correct
            printf("\nVery good!");
        }  //end if

        while (answer != product) {  //if answer is not correct, iterate loop until user answers correctly

            printf("\nNo, please try again.");  //prompt user to try again
            scanf_s("%d", &answer);  //read answer value from kb

            if (answer == product) {  //if answer is correct
                printf("\nVery good!");
            }  //end if

        }  //end inner while

        printf("\n\nWould you like to continue (y or n)?");  //ask if user would like to continue
        scanf_s(" %c", &keepGoing);  //read keepGoing character from kb

    }  //end outer while

}  //end main

//function to return first number between 0 and 9
int getFirstNumber(int num1) {
    num1 = rand() % 10;
    return num1;
}  //end function

//function to return second number between 0 and 9
int getSecondNumber(int num2) {
    num2 = rand() % 10;
    return num2;
}  //end function







