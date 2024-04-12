/* 7.21
 * Maze Traversal (generating mazes randomly)
 * This program will use recursion to walk through a randomly generated maze,
 * using the "right hand on the wall" algorithm. If the maze
 * turns to the right, the wall to the right must be followed, never
 * taking the right hand off the wall. X will indicate each spot visited. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h.>

#define HEIGHT 12
#define WIDTH 12

void initializeMaze(char maze[][WIDTH]);
void traverseMaze(char (*mPtr)[WIDTH], int x, int y, int direction);
void generateMaze(char (*mPtr)[WIDTH], int x, int y);
void swap(int *move1, int *move2);
void printSolution(char(*mPtr)[WIDTH]);


int main() {

    // seed random number generator
    srand(time(0));

    // maze array
    char maze[HEIGHT][WIDTH];

    // call function initialize the array to all #
    initializeMaze(maze);

    // call function to generate random maze, start from maze[2][0], facing right
    generateMaze(maze, 2, 0);

    //call function to traverse maze, start from maze[2][0], facing right
    //traverseMaze(maze, 2, 0, 1);

    // print completed maze
    printf("--------Solution--------\n");
    printSolution(maze);

    return 0;

}  // end main

// function to initialize entire maze to # signs
void initializeMaze(char maze[][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            maze[i][j] = '#';
        }
    }
}

// function to check if space is safe to move into
int isSafe(char maze[][WIDTH], int x, int y) {
    return (x > 0 && x < HEIGHT - 1 && y > 0 && y < WIDTH - 1 && maze[x][y] != '.');
}

// function to print traversed maze
void printSolution(char maze[][WIDTH]) {

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to generate the maze using recursive backtracking
void generateMaze(char (*mPtr)[WIDTH], int x, int y) {


    // Arrays to store x and y directions
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    if (x == HEIGHT - 1 && y == WIDTH - 1) {
        return;
    }

    // set maze entrance and exit, then continue to mark each spot
    *(*(mPtr + x) + y) = '.';
    *(*(mPtr + HEIGHT - 2) + WIDTH - 1)= '.';

    // array to store 4 directions
    int directions[4] = {0, 1, 2, 3};

    // randomize directions in array
    for (int i = 0; i < 4; ++i) {
        swap(&directions[i], &directions[rand() % 4]);
    }
    // attempt each direction
    for (int i = 0; i < 4; i++) {

        int direction = directions[i];  // select random direction
        int nextX = x + dx[direction] * 2;  // move two steps in x direction
        int nextY = y + dy[direction] * 2;   // move two steps in y direction

        // if space is available to move into
        if (isSafe(mPtr, nextX, nextY)) {
            *(*(mPtr + x + dx[direction]) + y + dy[direction]) = '.'; // break down wall between current and next space

            // recursive call, continue generating maze
            generateMaze(mPtr, nextX, nextY);
        }
    }
}

// function to swap values at memory locations
// to which d1 and d2 point
void swap(int *d1, int *d2) {
    int hold = *d1;
    *d1 = *d2;
    *d2 = hold;
}

// function to traverse maze, placing an x in visited spaces
void traverseMaze(char(*mPtr)[WIDTH], int x, int y, int direction) {

    // arrays to store x and y directions
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    // mark current spot as "x" (visited)
    *(*(mPtr + x) + y) = 'x';

    // return if end of maze is reached
    if (x == HEIGHT - 2 && y == WIDTH - 1) {
        return;
    }

    // check if space to the right is available to move into
    int right = (direction + 1) % 4;
    int nextX = x + dx[right];
    int nextY = y + dy[right];

    // if space is not a wall, move into space
    if (*(*(mPtr + nextX) + nextY) != '#') {
        traverseMaze(mPtr, nextX, nextY, right);
        return;
    }

    // if right is unavailable, go straight
    nextX = x + dx[direction];
    nextY = y + dy[direction];

    // if space is not a wall, move into it
    if (*(*(mPtr + nextX) + nextY) != '#') {
        traverseMaze(mPtr, nextX, nextY, direction);
        return;
    }

    // if right and straight are unavailable, move left
    int left = (direction + 3) % 4;
    nextX = x + dx[left];
    nextY = y + dy[left];

    // if space is not a wall, move into it
    if (*(*(mPtr + nextX) + nextY) != '#') {
        traverseMaze(mPtr, nextX, nextY, left);
        return;
    }

    // if right, straight, and left are blocked, reverse direction
    int reverse = (direction - 2) % 4;
    nextX = x + dx[reverse];
    nextY = y + dy[reverse];

    // if space is not a wall, move into it
    if (*(*(mPtr + nextX) + nextY) != '#') {
        traverseMaze(mPtr, nextX, nextY, reverse);
        return;
    }
}
