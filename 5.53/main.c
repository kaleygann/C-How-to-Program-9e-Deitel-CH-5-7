/* 5.53
 * This program will modify 5.53 by
 * allowing the user to choose which
 * type of problem they would like to solve
 * then answer each questions within that
 * category.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
int getFirstNumber(int);
int getSecondNumber(int);

int main() {  //main header

    //local variables
    int num1, num2 = 0;
    int a, b = 0;
    int answer, result, type = 0;
    char keepGoing = 'y';

    //seed random generator
    srand(time(0));

    //while keepGoing is not no
    while (keepGoing == 'y' || keepGoing == 'Y') {

        //prompt user to type of problem
        printf("\nENTER TYPE OF PROBLEM\n");
        printf("(1: Addition, 2: Subtraction, 3: Multiplication, 4: Random): ");
        scanf_s("%d", &type);  //read difficulty value from kb

        if (type == 1) {  //if type is one, problems will be addition

            a = getFirstNumber(num1);  //set variable a to first number
            b = getSecondNumber(num2);  //set variable b to second number
            result = a + b;  //calculate sum of the two numbers

            printf("\nHow much is %d plus %d?", a, b);  //ask user to answer question
            scanf_s("%d", &answer);  //read answer from kb

            if (answer == result) {  //if answer is correct
                printf("\nVery good!\n");
            }  //end if

            while (answer != result) {  //if answer is not correct, iterate loop until user answers correctly

                printf("\nNo, please try again.");  //prompt user to try again
                scanf_s("%d", &answer);  //read answer value from kb

                if (answer == result) {  //if answer is correct
                    printf("\nVery good!\n");
                }  //end if

            }  //end while
        }  //end if


        if (type == 2) {  //if type is 2, problems will be subtraction

            a = getFirstNumber(num1);  //set variable a to first number
            b = getSecondNumber(num2);  //set variable b to second number
            result = a - b;  //calculate difference of the two numbers

            printf("\nHow much is %d minus %d?", a, b);  //ask user to answer question
            scanf_s("%d", &answer);  //read answer from kb

            if (answer == result) {  //if answer is correct
                printf("\nVery good!\n");
            }  //end if

            while (answer != result) {  //if answer is not correct, iterate loop until user answers correctly

                printf("\nNo, please try again.");  //prompt user to try again
                scanf_s("%d", &answer);  //read answer value from kb

                if (answer == result) {  //if answer is correct
                    printf("\nVery good!\n");
                }  //end if

            }  //end inner while
        }  //end if

        if (type == 3) {  //if type is 3, problem will be multiplication

            a = getFirstNumber(num1);  //set variable a to first number
            b = getSecondNumber(num2);  //set variable b to second number
            result = a * b;  //calculate product of the two numbers

            printf("\nHow much is %d times %d?", a, b);  //ask user to answer question
            scanf_s("%d", &answer);  //read answer from kb

            if (answer == result) {  //if answer is correct
                printf("\nVery good!\n");
            }  //end if

            while (answer != result) {  //if answer is not correct, iterate loop until user answers correctly

                printf("\nNo, please try again.");  //prompt user to try again
                scanf_s("%d", &answer);  //read answer value from kb

                if (answer == result) {  //if answer is correct
                    printf("\nVery good!\n");
                }  //end if

            }  //end inner while
        }  //end if

        if (type == 4) {  //if difficulty level is hard, multiply two-digit numbers

            a = getFirstNumber(num1);  //set variable a to first number
            b = getSecondNumber(num2);  //set variable b to second number

            int problem = 1 + rand() % 3;

                if (problem == 1) {  //if problem is 1: addition
                    result = a + b;  //calculate product of the two numbers
                    printf("\nHow much is %d plus %d?", a, b);  //ask user to answer question
                }  //end if

                else if (problem == 2) {  //if problem is 2: subtraction
                    result = a - b;  //calculate difference of the two numbers
                    printf("\nHow much is %d minus %d?", a, b);  //ask user to answer question
                }  //end else if

                else {  //if problem is 3: multiplication
                    result = a * b;  //calculate product of the two numbers
                    printf("\nHow much is %d times %d?", a, b);  //ask user to answer question
                }  //end else

            scanf_s("%d", &answer);  //read answer from kb

            if (answer == result) {  //if answer is correct
                printf("\nVery good!\n");
            }  //end if

            while (answer != result) {  //if answer is not correct, iterate loop until user answers correctly

                printf("\nNo, please try again.");  //prompt user to try again
                scanf_s("%d", &answer);  //read answer value from kb

                if (answer == result) {  //if answer is correct
                    printf("\nVery good!\n");
                }  //end if

            }  //end inner while
        }  //end if

        printf("\nWould you like to continue (y or n)?");  //ask if user would like to continue
        scanf_s(" %c", &keepGoing);  //read keepGoing character from kb

    }  //end outer while

}  //end main

//function to return first number between 0 and 100
int getFirstNumber(int num1) {
    num1 = rand() % 100;
    return num1;
}  //end function

//function to return second number between 0 and 100
int getSecondNumber(int num2) {
    num2 = rand() % 100;
    return num2;
}  //end function

