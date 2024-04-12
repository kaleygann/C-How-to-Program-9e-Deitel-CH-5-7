/* 7.22
 * Maze Traversal (generating mazes randomly, solving maze of any size)
 * This program will use recursion to walk through a randomly generated maze of any size,
 * using the "right hand on the wall" algorithm. If the maze
 * turns to the right, the wall to the right must be followed, never
 * taking the right hand off the wall. X will indicate each spot visited. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h.>


void initializeMaze(int height, int width, char maze[][width]);
void traverseMaze(int height, int width, char (*mPtr)[width], int x, int y, int direction);
void generateMaze(int height, int width, char (*mPtr)[width], int x, int y);
void swap(int *move1, int *move2);
void printSolution(int height, int width, char(*mPtr)[width]);


int main() {

    // seed random number generator
    srand(time(0));

    // initialize variables to store height and width
    int height, width = 0;

    // prompt user for height and width values
    printf("\nEnter maze height: ");
    scanf_s("%d", &height);

    printf("\nEnter maze width: ");
    scanf_s("%d", &width);

    // maze array
    char maze[width][width];

    // call function initialize the array to all #
    initializeMaze(height, width, maze);

    // call function to generate random maze, start from maze[2][0]
    generateMaze(height, width, maze, 2, 0);

    //call function to traverse maze, start from maze[2][0], facing right
    traverseMaze(height, width, maze, 2, 0, 1);

    // print completed maze
    printf("--------Solution--------\n");
    printSolution(height, width, maze);

    return 0;

}  // end main

// function to initialize entire maze to # signs
void initializeMaze(int height, int width, char maze[][width]) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            maze[i][j] = '#';
        }
    }
}

// function to check if space is safe to move into
int isSafe(int height, int width, char maze[][width], int x, int y) {
    return (x > 0 && x < height - 1 && y > 0 && y < width - 1 && maze[x][y] != '.');
}

// function to print traversed maze
void printSolution(int height, int width, char maze[][width]) {

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to generate the maze using recursive backtracking
void generateMaze(int height, int width, char (*mPtr)[width], int x, int y) {


    // Arrays to store x and y directions
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    if (x == height - 1 && y == width - 1) {
        return;
    }
    *(*(mPtr + x) + y) = '.';
    *(*(mPtr + height - 3) + width - 1)= '.';

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
        if (isSafe(height, width, mPtr, nextX, nextY)) {

            *(*(mPtr + x + dx[direction]) + y + dy[direction]) = '.'; // break down wall between current and next space

            // recursive call, continue generating maze
            generateMaze(height, width, mPtr, nextX, nextY);
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
void traverseMaze(int height, int width, char(*mPtr)[width], int x, int y, int direction) {

    // arrays to store x and y directions
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    // mark current spot as "x" (visited)
    *(*(mPtr + x) + y) = 'x';

    // return if end of maze is reached
    if (x == height - 1 && y == width - 1) {
        return;
    }

    // check if space to the right is available to move into
    int right = (direction + 1) % 4;
    int nextX = x + dx[right];
    int nextY = y + dy[right];

    // if space is not a wall, move into space
    if (*(*(mPtr + nextX) + nextY) != '#') {
        traverseMaze(height, width, mPtr, nextX, nextY, right);
        return;
    }

    // if right is unavailable, go straight
    nextX = x + dx[direction];
    nextY = y + dy[direction];

    // if space is not a wall, move into it
    if (*(*(mPtr + nextX) + nextY) != '#') {
        traverseMaze(height, width, mPtr, nextX, nextY, direction);
        return;
    }

    // if right and straight are unavailable, move left
    int left = (direction + 3) % 4;
    nextX = x + dx[left];
    nextY = y + dy[left];

    // if space is not a wall, move into it
    if (*(*(mPtr + nextX) + nextY) != '#') {
        traverseMaze(height, width, mPtr, nextX, nextY, left);
        return;
    }

    // if right, straight, and left are blocked, reverse direction
    int reverse = (direction - 2) % 4;
    nextX = x + dx[reverse];
    nextY = y + dy[reverse];

    // if space is not a wall, move into it
    if (*(*(mPtr + nextX) + nextY) != '#') {
        traverseMaze(height, width, mPtr, nextX, nextY, reverse);
        return;
    }
}
