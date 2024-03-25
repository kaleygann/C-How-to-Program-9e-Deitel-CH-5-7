/* 6.27
 * Eight Queens: Random Brute Force Technique
 * This program will solve the Eight Queens problem by
 * using a random brute-force technique. Runtime may vary
 * quite a bit due to the randomization.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// set constant size 8
#define SIZE 8

// function prototype
void solveQNs();

// array to store eight queens
int queens[SIZE];

int main() {

    // function call to solve Eight Queens problem
    solveQNs();

}  // end main

/* function isSafe() checks if a queen can be placed in a position that's not
 * in the line of attack from another queen */
int isSafe(int x, int y) {

    // check if next move leads to a "safe" position (not attacking other queens)
    for (int i = 0; i < y; ++i) {
        // absolute value function used to get positive values when checking diagonal attacks
        if (queens[i] == x || abs(queens[i] - x) == abs(i - y)) {
            return 0;  // return 0 if attack is found
        }
    }
    return 1; // if no attack found, position is safe to move into
}  // end isSafe()

/* function printBoard() prints 1s to indicate the queens' final positions and
 * 0s to indicate empty spaces */
void printBoard() {

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (queens[j] == i) {
                printf("1 ");
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}  // end printBoard()

/* function solveQNs() will use a while loop that calls isSafe() to check that
 * the queens' current positions on the board is a valid solution to the problem;
 * accumulates attempts until solution is foudn then displays both the solution
 * and number of attemps */
void solveQNs() {

    // seed random generator
    srand(time(0));

    // initialize variable to store number of attempts
    int attempts = 0;

    while (1) {

        // solution starting value is 1 (true)
        int solution = 1;

        // randomize placement of queens on the board
        for (int i = 0; i < SIZE; i++) {
            queens[i] = rand() % SIZE;
        }

        // check if placement of queens leads to a valid solution
        for (int i = 0; i < SIZE; ++i) {
            if (!isSafe(queens[i], i)) {  // if solution is not yet valid, break for loop
                solution = 0;
                break;
            }
        }  // end for

        // if queen placement is a valid solution, print board of queens
        if (solution) {
            printf("\nSolution:\n---------------\n");
            printBoard();
            printf("Attempts: %d\n", attempts);  // print number of attempts needed
            return;
        }
        attempts++;  // increment attempts
    }  // end while
}  // end solve QNs()
