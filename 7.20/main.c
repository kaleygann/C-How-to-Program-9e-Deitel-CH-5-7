/* 7.20
 * Maze Traversal
 * This program will use recursion to walk through a maze,
 * using the "right hand on the wall" algorithm. If the maze
 * turns to the right, the wall to the right must be followed, never
 * taking the right hand off the wall. X will indicate each spot visited. */

#include <stdio.h>

#define HEIGHT 12
#define WIDTH 12

// function prototype
void traverseMaze(char (*mPtr)[WIDTH], int x, int y, int direction);

int main() {
    char maze[HEIGHT][WIDTH] = {
            {'#','#','#','#','#','#','#','#','#','#','#','#'},
            {'#','.','.','.','#','.','.','.','.','.','.','#'},
            {'.','.','#','.','#','.','#','#','#','#','.','#'},
            {'#','#','#','.','#','.','.','.','.','#','.','#'},
            {'#','.','.','.','.','#','#','#','.','#','.','.'},
            {'#','#','#','#','.','#','.','#','.','#','.','#'},
            {'#','.','.','#','.','#','.','#','.','#','.','#'},
            {'#','#','.','#','.','#','.','#','.','#','.','#'},
            {'#','.','.','.','.','.','.','.','.','#','.','#'},
            {'#','#','#','#','#','#','.','#','#','#','.','#'},
            {'#','.','.','.','.','.','.','#','.','.','.','#'},
            {'#','#','#','#','#','#','#','#','#','#','#','#'}
    };

    // start from maze[2][0], facing right
    traverseMaze(maze, 2, 0, 1);

    // print completed maze
    printf("--------Solution--------\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void traverseMaze(char(*mPtr)[WIDTH], int x, int y, int direction) {

    // arrays to store x and y directions
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    // mark current spot as "x" (visited)
    *(*(mPtr + x) + y) = 'x';

    // check if end of maze is reached
    if (x == HEIGHT - 1 && y == WIDTH - 1) {
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


