/* 6.24
 * Knight's Tour: this program will move a knight around an 8-by-8 chessboard,
 * where the knight can enter the space only once. Program will solve this puzzle
 * by using backtracking method with recursion.
 */

#include <stdio.h>
#include <math.h>

// set sizes for rows and columns (8 x 8 board)
#define SIZE 8

// function prototype
int solveKT();


int main() {

    // call function to solve knight tour
    solveKT();

}  // end main


/* printBoard() prints board with move number of moves labeled */
void printBoard(int board[SIZE][SIZE])
{
    printf("\nSolution: \n --------------------------------------\n");
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf(" %3d ", board[i][j]);
        }
        printf("\n");
    }
}  // end printBoard()

// function isSafe() checks if the place on the board
// is available to move into (has not yet been visited)
int isSafe(int x, int y, int board[SIZE][SIZE])
{
    return (board[x][y] == -1 && x >= 0 && x < SIZE && y >= 0 && y < SIZE);
}  // end isSafe()


/* function moveKnight() uses recursion to check moves from the knight's current position then moves the knight
 * into the "safe" positions */
int moveKnight(int currentRow, int currentColumn, int move, int board[SIZE][SIZE], int horizontal[SIZE], int vertical[SIZE])
{
    if (move == pow(SIZE, 2) + 1) {  // if move is 65, board is full - return true
        return 1;
    }

    // loop to attempt all moves from current position, starting at x = 0 and y = 0
    for (int moveNumber = 0; moveNumber < SIZE; ++moveNumber) {

        // x moves will add vertical movement using moveNumber index
        int move_x = currentRow + vertical[moveNumber];

        // y moves will add horizontal movement using moveNumber index
        int move_y = currentColumn + horizontal[moveNumber];

        // if position on board has not been touched, move knight into position
        if (isSafe(move_x, move_y, board)) {
            board[move_x][move_y] = move;

            //recursive call
            if (moveKnight(move_x, move_y, move + 1, board,
                           horizontal, vertical)) {
                return 1;
            }
            else {
                board[move_x][move_y] = -1;  //backtracking
            }
        }
    }
    return 0;
} // end moveKnight()


/* function solveKT() uses backtracking to solve the Knight's Tour
 * by calling the moveKnight() function */
int solveKT() {

    // initialize current row and column variables
    int currentRow = 0;
    int currentColumn = 0;

    // declare board array
    int board[SIZE][SIZE];

    // store the 8 horizontal and 8 vertical moves in arrays
    int horizontal[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int vertical[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

    // set all elements to -1 (solution matrix)
    for (int x = 0; x < SIZE; ++x) {
        for (int y = 0; y < SIZE; ++y) {
            board[x][y] = -1;
        }
    }

    // set knight's current position to 1
    board[currentRow][currentColumn] = 1;

    // starting from currentRow and currentColumn, go through tours; when board is full, print board
    if (moveKnight(0, 0, 2, board, horizontal, vertical)) {
        printBoard(board);
    }
}  // end solveKT()









