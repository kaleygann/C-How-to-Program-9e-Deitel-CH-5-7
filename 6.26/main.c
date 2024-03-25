/* 6.26
 * Eight Queens: this program will solve the Eight Queens problem
 * by using backtracking, recursion, and an accessibility heuristic.
 * The goal is to place all eight queens on a chessboard where no
 * queen is "attacking" another. Complete solution will then be printed
 * (1 = queen, 0 = empty space)
 * */

#include <stdio.h>
#include <stdlib.h>

// set constant size 8
#define SIZE 8

// function prototypes
int solveQNs(int col);
void printBoard(int queens[SIZE]);

// array to store eight queens
int queens[SIZE];

// array to store elimination numbers
int elimination_numbers[SIZE][SIZE];

int main() {

    // function call to solve Eight Queens problem
    if (solveQNs(0)) {
        printf("\nSolution:\n---------------\n");
        printBoard(queens);  // display board
    }
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
void printBoard(int queens[SIZE]) {

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


/* function initializeElimination() will set the elimination numbers
 * to starting value of size - 1 (7) */
void initializeElimination() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            elimination_numbers[i][j] = SIZE - 1;
        }
    }
}  // end initialize Elimination()


/* function updateElimination() will update the elimination values
 * based on where a queen's position is on the board */
void updateElimination(int currentRow, int currentColumn, int eValue) {

    for (int i = 0; i < SIZE; ++i) {

        // update elimination numbers for entire row and column
        elimination_numbers[i][currentColumn] += eValue;
        elimination_numbers[currentRow][i] += eValue;

        // use arrays to store horizontal and vertical movements to create diagonal moves
        int vertical[] = {-1, -1, 1, 1};
        int horizontal[] = {-1, 1, -1, 1};

        // for loop to iterate through 4 directions
        for (int j = 0; j < SIZE / 2; ++j) {

            // set next move coordinates
            int next_x = currentRow + vertical[j];
            int next_y = currentColumn + horizontal[j];

            // while loop to update elimination numbers
            while (next_x >= 0 && next_x < SIZE && next_y >= 0 && next_y < SIZE) {

                elimination_numbers[next_x][next_y] += eValue;  //update elimination number

                // update moves to next square in direction
                next_x += vertical[j];
                next_y += horizontal[j];
            }
        }
    }

}  // end updateElimination()


/* function solveQNs() uses backtracking and recursion to solve Eight Queens problem */
int solveQNs(int column) {

    initializeElimination();

    // if all queens are placed, solution is found (return true)
    if (column >= SIZE) {
        return 1;
    }

    // Find a safe row to place a queen in the current column
    for (int row = 0; row < SIZE; ++row) {
        if (elimination_numbers[row][column] > 0 && isSafe(row, column)) {

            // place queen in the row
            queens[column] = row;
            updateElimination(row, column, -1); // update elimination numbers, decrement value

            // recursive call to place next queen
            if (solveQNs(column + 1)) {
                return 1;
            }

            // backtrack if queen placement does not create a solution
            else {
                updateElimination(row, column, 1);  // update elimination numbers, increment value (restore number)
            }
        }
    }  // end for

    return 0;
}  // end solveQNs()

