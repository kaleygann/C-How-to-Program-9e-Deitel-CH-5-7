/* 6.25
 * Knight's Tour: Brute Force Approach
 * This program will use random numbers to enable the knight to walk
 * at random around the chessboard in its legitimate L-shaped moves.
 * Program will run one tour and print the final board.
 * Program should produce a relatively short tour.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// set size to 8 for 8 x 8 chessboard
#define SIZE 8

// function prototype
void solveKT();

int main() {

    // call function to solve Knight's Tour
    solveKT();

} // end main

/* function isSafe determines whether a space is safe for the knight to move
 * into and ensures the space is not outside the boundaries of the board */
int isSafe(int x, int y, int board[SIZE][SIZE]) {
    return (board[x][y] == -1 && x >= 0 && x < SIZE && y >= 0 && y < SIZE);
}


/* function printBoard() prints the completed board with move numbers labeled */
void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%3d ", board[i][j]);
        }
        printf("\n");
    }
}  // end printBoard()


/* function solveKT() will move the knight using randomized move values to move
 * the knight into "safe" spaces checked by the isSafe() function; displays
 * values once tour ends */
void solveKT() {

    // seed random generator
    srand(time(0));

    // initialize 2D board array
    int board[SIZE][SIZE];

    // for loop to initialize all elements to -1, indicating spots not visited
    for (int x = 0; x < SIZE; ++x) {
        for (int y = 0; y < SIZE; ++y) {
            board[x][y] = -1;
        }
    }
    // set possible horizontal and vertical moves
    int horizontal[SIZE] = {2, 1, -1, -2, -2, -1, 1, 2};
    int vertical[SIZE] = {-1, -2, -2, -1, 1, 2, 2, 1};


        // set random starting x and y values
        int start_x = rand() % SIZE;
        int start_y = rand() % SIZE;

        // knight's starting position is at random index values and labeled as 0
        board[start_x][start_y] = 0;

        // declare move count and next x and y move variables
        int moveCount = 0;
        int next_x, next_y;

        // set current row and current column to starting positions
        int currentRow = start_x;
        int currentColumn = start_y;

        // while loop to iterate through moves and check available spaces
        while (1) {

            // randomize move number index
            int moveNumber = rand() % 8;

            // set next moves to current positions plus vertical and horizontal move values
            next_x = currentRow + vertical[moveNumber];
            next_y = currentColumn + horizontal[moveNumber];

            // terminate loop if space is not available to move into
            if (!isSafe(next_x, next_y, board)) {
                break;
            }

                /* if space for next move is available, increment move value and set it to
                current position to indicate it has been visited */
            else {
                moveCount++;
                board[next_x][next_y] = moveCount;
                currentRow = next_x;
                currentColumn = next_y;
            }
        }  // end while


    // output
    printf("\nSolution:\n--------------------------------\n");
    printBoard(board);
    printf("\nResult: the knight reached %d square(s).\n", moveCount);

}  // end solveKT()



