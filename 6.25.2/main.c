/* 6.25.2
 * Knight's Tour: Brute-Force Approach
 * This program will use random numbers to enable the knight to walk at random around the
 * chessboard in its legitimate L-shaped moves. The program will run 1000 tours. Once
 * it finishes attempting tours, the information will be printed in tabular format
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// set size to 8 for 8 x 8 chessboard
// set number of tours to 1000
#define SIZE 8
#define TOURS 1000

// function prototype
void solveKT();

int main() {

    // call function to solve Knight's Tour
    solveKT();

}  // end main


/* function isSafe determines whether a space is safe for the knight to move
 * into and ensures the space is not outside the boundaries of the board */
int isSafe(int x, int y, int board[SIZE][SIZE]) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == -1);
}

/* function solveKT() will attempt 1000 tours. Moves the knight into "safe" spaces using
 * randomized move values and calling the isSafe() function; displays values and results
 * once tours end */
void solveKT() {

    // seed random generator
    srand(time(0));

    // initialize 2D board array
    int board[SIZE][SIZE];

    // array to track number of tours of different lengths
    int tourLengths[SIZE * SIZE + 1] = {};

    // initialize variable to store best number of squares visited
    int best = 0;

    // for loop to complete 1000 tours
    for (int i = 0; i < TOURS; ++i) {
        // for loop to initialize all elements to -1, indicating spots not visited
        for (int x = 0; x < SIZE; ++x) {
            for (int y = 0; y < SIZE; ++y) {
            board[x][y] = -1;
        }
    }

    // set possible horizontal and vertical moves
    int horizontal[SIZE] = {2, 1, -1, -2, -2, -1, 1, 2};
    int vertical[SIZE] = {1, 2, 2, 1, -1, -2, -2, -1};

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

        // randomize moveNumber index
        int moveNumber = rand() % 8;

        // set next moves to current positions plus vertical and horizontal moves values
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
            currentColumn= next_y;
        }
    }  // end while

    // increment tour length count
    tourLengths[moveCount]++;

    }  // end for

    // print tour lengths and number of moves
    printf("# of Moves\t# of Tours\n");
    printf("-------------------------------\n");

    // for loop to iterate through results and print tour length and number of moves
    for (int i = 1; i <= SIZE * SIZE; ++i) {
        printf("%6d %15d\n", i, tourLengths[i]);
        if (tourLengths[i] > 0) {
            best = i;
        }
    }

// print best number of moves
printf("\nBest result: %d moves.\n", best);

}  // end solveKT()


