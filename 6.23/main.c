/* 6.23
 * Turtle Graphics -- this program will simulate a mechanical turtle that
 * walks around the room, controlled by commands via the program. The turtle
 * holds a pen and, when the pen is down, the turtle traces shapes as it moves;
 * when the pen is up, the turtle moves around without writing anything.
 */
#include <stdio.h>

// set SIZE of the array to 50
#define SIZE 50

// function prototype
void command(int floor[SIZE][SIZE]);

int main() {

    // declare floor array, set all elements to 0
    int floor[SIZE][SIZE] = {0};

    // function call
    command(floor);

}  // end main

/* function printFloor() will print the array using asterisks and spaces */
void printFloor(int floor[SIZE][SIZE]) {
    for(int i=0; i<SIZE; ++i) {
        for(int j=0; j<SIZE; ++j) {
            if(floor[i][j] == 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}  // end printFloor()

/* function command() will allow user to enter the commands and utilize a
 * switch statement to determine what action will occur based on command
 * number */
void command(int floor[SIZE][SIZE]) {

    //initialize local variables
    int pen, direction, steps, command = 0;

    //divide board in half
    int x = SIZE / 2;
    int y = SIZE / 2;

    // loop to iterate commands - terminates when user enters 9
    while(command != 9) {

        //prompt user to enter command
        printf("Enter command: ");
        scanf("%d", &command);

        // switch statement to determine command actions
        switch(command) {
            case 1:
                pen = 0;  //pen is up
                break;
            case 2:
                pen = 1;  // pen is down
                break;
            case 3:
                direction = (direction + 1) % 4;  // turn right
                break;
            case 4:
                direction = (direction + 3) % 4;  // turn left
                break;
            case 5:
                // prompt user to enter numbers of steps to move
                printf("Enter number of steps: ");
                scanf("%d", &steps);

                // for loop to increment or decrement x or y by number of steps
                for(int i = 1; i < steps; ++i){
                    if (pen) {
                        floor[x][y] = 1;  // if pen is down, set all elements to 1
                    }
                    if (direction == 0) {
                        y++;  // increment column index
                    }
                    else if (direction == 1) {
                        x++;  // increment row index
                    }
                    else if (direction == 2) {
                        y--;  // decrement column index
                    }
                    else {
                        x--;  // decrement row index
                    }
                }  // end for
                break;
            case 6:
                printFloor(floor);  // print floor
                break;
        }  // end switch
    }  // end while
}  // end command()