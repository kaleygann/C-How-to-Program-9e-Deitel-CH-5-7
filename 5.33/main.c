/* 5.33
 * this program will modify the 5.32
 * game of "guess the number" by
 * printings various statements depending
 * on the amount of guesses the user makes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getNumber();  //function prototype

int main() {  //main header

    //initialize local variables
    char keepGoing = 'y';
    int guess = 1;
    int number;
    int numGuesses = 0;

    //srand() to get different results each time number is generated
    srand(time(0));

    while (keepGoing == 'y' || keepGoing == 'Y') {  //when keepGoing is yes

        //prompt user to enter a number and type guess
        printf("\nI have a number between 1 and 1000\n");
        printf("Can you guess my number?\n");
        printf("Please type your first guess.\n");

        number = getNumber();  //call function to generate random number

        while (guess >= 1 && guess <= 1000) {  //while guess is within range

            scanf_s("%d", &guess);  //read user's guess from kb

            if (guess < number) { //if guess is too low, prompt user to try again

                printf("Too low. Try again.\n");  //prompt user to try again
                numGuesses++;  //accumulate guesses

            }  //end if

            else if (guess > number) { //if guess is too high, prompt user to try again

                printf("Too high. Try again.\n");  //prompt user to try again
                numGuesses++;  //accumulate guesses

            }  //end else if

            else if (guess == number) {  //if guess is correct, ask if user wants to continue

                printf("\nExcellent! You guessed the number!\n");  //output
                numGuesses++;  //accumulate number of guesses

                if (numGuesses < 10)  //if # of guesses are fewer than 10
                    printf("Either you know the secret or you got lucky!\n");

                if (numGuesses == 10)  //if # of guesses are 10
                    printf("Aha! You know the secret!\n");

                if (numGuesses > 10) //if # of guesses are more than 10
                    printf("You should be able to do better!\n");

                printf("Would you like to try again (y or n)?\n");  //prompt user if they wish to try again
                scanf_s(" %c", &keepGoing);  //read keepGoing value from kb
                break;  //terminate loop

            }  //end else if
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
