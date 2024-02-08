/* 5.52
 * This program will modify 5.49 by
 * allowing the user to enter a difficulty
 * level for solving multiplication problems.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
int getFirstNumEasy(int);
int getSecondNumEasy(int);
int getFirstNumHard(int);
int getSecondNumHard(int);

int main() {  //main header

    //local variables
    int num1 = 0;
    int num2 = 0;
    int answer = 0;
    char keepGoing = 'y';
    int difficulty = 0;

    //seed random generator
    srand(time(0));

    //while keepGoing is not no
    while (keepGoing == 'y' || keepGoing == 'Y') {

        //prompt user to enter difficulty level for each problem
        printf("\nEnter difficulty level (1 for Easy, 2 for Hard): ");
        scanf_s("%d", &difficulty);  //read difficulty value from kb

        if (difficulty == 1) {  //if difficulty level is easy, multiply one-digit numbers

            int a = getFirstNumEasy(num1);  //set variable a to first number
            int b = getSecondNumEasy(num2);  //set variable b to second number
            int product = a * b;  //calculate product of the two numbers

            printf("\nHow much is %d times %d?", a, b);  //ask user to answer question
            scanf_s("%d", &answer);  //read answer from kb

            if (answer == product) {  //if answer is correct
                printf("\nVery good!\n");
            }  //end if

            while (answer != product) {  //if answer is not correct, iterate loop until user answers correctly

                printf("\nNo, please try again.");  //prompt user to try again
                scanf_s("%d", &answer);  //read answer value from kb

                if (answer == product) {  //if answer is correct
                    printf("\nVery good!\n");
                }  //end if

            }  //end while
        }  //end if


        if (difficulty == 2) {  //if difficulty level is hard, multiply two-digit numbers

            int a = getFirstNumHard(num1);  //set variable a to first number
            int b = getSecondNumHard(num2);  //set variable b to second number
            int product = a * b;  //calculate product of the two numbers

            printf("\nHow much is %d times %d?", a, b);  //ask user to answer question
            scanf_s("%d", &answer);  //read answer from kb

            if (answer == product) {  //if answer is correct
                printf("\nVery good!\n");
            }  //end if

            while (answer != product) {  //if answer is not correct, iterate loop until user answers correctly

                printf("\nNo, please try again.");  //prompt user to try again
                scanf_s("%d", &answer);  //read answer value from kb

                if (answer == product) {  //if answer is correct
                    printf("\nVery good!\n");
                }  //end if

            }  //end inner while
        }  //end if

        printf("\nWould you like to continue (y or n)?");  //ask if user would like to continue
        scanf_s(" %c", &keepGoing);  //read keepGoing character from kb

    }  //end outer while

}  //end main

//function to return first number between 0 and 9
int getFirstNumEasy(int num1) {
    num1 = rand() % 10;
    return num1;
}  //end function

//function to return second number between 0 and 9
int getSecondNumEasy(int num2) {
    num2 = rand() % 10;
    return num2;
}  //end function

//function to return first number between 10 and 99
int getFirstNumHard(int num1) {
    num1 = 10 + rand() % 90;
    return num1;
}  //end function

//function to return second number between 10 and 99
int getSecondNumHard(int num2) {
    num2 = 10 + rand() % 90;
    return num2;
}  //end function

