/* 5.32
 * this program will play the
 * game of "guess the number" by
 * selecting a random integer between
 * 1 and 1000 then prompting the user
 * to guess the number.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getNumber();  //function prototype

int main() {  //main header

    //initialize local variables
    char keepPlaying = 'y';
    int guess = 1;
    int number;

    //srand() to get different results each time number is generated
    srand(time(0));

    while (keepPlaying == 'y' || keepPlaying == 'Y') {  //when keepGoing is yes

        //prompt user to enter a number and type guess
        printf("\nI have a number between 1 and 1000\n");
        printf("Can you guess my number?\n");
        printf("Please type your first guess.\n");

        number = getNumber();  //call function to generate random number

        while (guess >= 1 && guess <= 1000) {  //while guess is within range

            scanf_s("%d", &guess);  //read user's guess from kb

            if (guess < number)  //if guess is too low, prompt user to try again
                printf("Too low. Try again.\n");

            else if (guess > number) //if guess is too high, prompt user to try again
                printf("Too high. Try again.\n");

            else if (guess == number) {  //if guess is correct, ask if user wants to continue
                printf("\nExcellent! You guessed the number!");
                printf("\nWould you like to try again?");
                scanf_s(" %c", &keepPlaying);
                break;
            }  //end else
        }  //end inner while
    }  //end outer while
}  //end main

/* function getNumber() generates
 * a random number between 1 and
 * 1000 then returns the value.
 */
int getNumber() {
    return 1 + rand() % 1000;
}  //end function
