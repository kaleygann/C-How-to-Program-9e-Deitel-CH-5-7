/* 6.24.2
 * Knight's Tour: this program will move a knight around an 8-by-8 chessboard,
 * where the knight can enter the space only once using an accessibility
 * heuristic -- prints starting accessibility values as well as solution.
 */

#include <stdio.h>
#include <math.h>

// function prototype
void solveKT();

// set size to 8 (8 x 8 board)
#define SIZE 8

// store horizontal and vertical moves in arrays
int horizontal[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int vertical[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main() {

    // call function to solve Knight's Tour
    solveKT();

}  // end main

/* function isSafe determines whether a space is safe for the knight to move
 * into and ensures the space is not outside the boundaries of the board */
int isSafe(int x, int y, int board[SIZE][SIZE]) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == 0);
}

/* function countAccessibility() will calculate the accessibility of space on the board
 * by checking all knight moves from current position and checks if move is safe; increments
 * count if space is safe to move into then returns count of squares */
int countAccessibility(int currentRow, int currentColumn, int board[SIZE][SIZE]) {

    // initialize count
    int count = 0;

    // loop to iterate through checking all vertical and horizontal moves
    for (int i = 0; i < 8; i++) {

        // set x and y moves to be tested to current position plus movement
        int move_x = currentRow + vertical[i];
        int move_y = currentColumn + horizontal[i];

        // increment count of accessible squares
        if (isSafe(move_x, move_y, board))
            count++;
    }
    return count;

}  // end countAccessibility()


/* function moveKnight() will use recursion to get a complete tour of the chessboard by
 * looking at all possible moves */
int moveKnight(int currentRow, int currentColumn, int move, int board[SIZE][SIZE]) {

    // base case: if move = 65 then all squares have been visited (return true)
    if (move == pow(SIZE, 2) + 1)
        return 1;

    // set minimum accessibility to 8
    int min_access = SIZE;

    // declare variables to store next moves
    int next_x, next_y;

    // for loop to iterate through all possible moves then calculate accessibility
    for (int moveNumber = 0; moveNumber < 8; ++moveNumber) {

        // calculate next moves from current position
        int move_x = currentRow + vertical[moveNumber];
        int move_y = currentColumn + horizontal[moveNumber];

        // is space is safe to move into, calculate accessibility from current position
        if (isSafe(move_x, move_y, board)) {
            int accessibility = countAccessibility(move_x, move_y, board);

            // if accessibility is less than 8, reset minimum accessibility to current count
            if (accessibility < min_access) {
                min_access = accessibility;
                next_x = move_x;
                next_y = move_y;
            }
        }
    }  // end for

    // return false if next moves are -1
    if (next_x == -1 && next_y == -1)
        return 0;

    // place move number in square
    board[next_x][next_y] = move;

    // recursive call
    if (moveKnight(next_x, next_y, move + 1, board))
        return 1;

    board[next_x][next_y] = -1;  // backtracking

    return 0;

}  // end moveKnight()

/* function printBoard() prints the completed board with move numbers labeled */
void printBoard(int board[SIZE][SIZE]) {

    printf("\nSolution:\n-------------------------------\n");  // output header

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%3d ", board[i][j]);
        printf("\n");
    }

}  // end printBoard()

/* function solveKT() will utilize moveKnight() to solve the Knight's Tour
 * problem the display both the accessibility values and solution */

void solveKT() {

    // declare and initialize board array
    int board[SIZE][SIZE] = {0};

    // declare current row and current column variables
    int currentRow, currentColumn = 0;

    // label starting position
    board[currentRow][currentColumn] = 1;

    // moveKnight() returns 1, board is full (print board)
    if (moveKnight(currentRow, currentColumn, 2, board)) {
        printBoard(board);
    }

}  // end solveKT()







