/* 6.27
 * Eight Queens: Exhaustive Brute Force Technique
 * This program will solve the Eight Queens problem by
 * using an exhaustive brute-force technique to check
 * all possible solutions then print the number of attempts
 * as well as the board containing all eight queens.
 */

#include <stdio.h>
#include <stdlib.h>

// set constant size 8
#define SIZE 8

// function prototype
void solveQNs();

// array to store eight queens
int queens[SIZE];

int main() {

    // function call to solve Eight Queens problem
    solveQNs();
}

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

/* function solveQNs() uses an exhaustive brute force technique to
 * solve the Eight Queens problem */
void solveQNs() {

    // initialize variable to store number of attempts
    int attempts = 0;

    // check all possible solutions
    for (int a = 0; a < SIZE; ++a) {
        for (int b = 0; b < SIZE; ++b) {
            for (int c = 0; c < SIZE; ++c) {
                for (int d = 0; d < SIZE; ++d) {
                    for (int e = 0; e < SIZE; ++e) {
                        for (int f = 0; f < SIZE; ++f) {
                            for (int g = 0; g < SIZE; ++g) {
                                for (int h = 0; h < SIZE; ++h) {
                                    queens[0] = a;
                                    queens[1] = b;
                                    queens[2] = c;
                                    queens[3] = d;
                                    queens[4] = e;
                                    queens[5] = f;
                                    queens[6] = g;
                                    queens[7] = h;

                                    // solution starting value is 1 (true)
                                    int solution = 1;

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
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}  // end solve QNs()