/* 5.36
 * This program will solve the Tower
 * of Hanoi problem using a recursive
 * function with four parameters.
 */

#include <stdio.h>

void towerHanoi(int, int, int, int);  //function prototype

int main() { //main header

    //local variable
    int diskNum;

    printf("Enter number of disks: ");  //prompt user to enter number of disks
    scanf_s("%d", &diskNum);  //read number value from kb

    towerHanoi(diskNum, 1, 3, 2);  //call function

}  //end main

// recursive function towerHanoi() to print instructions
// for moving each peg using num - 1 disks

void towerHanoi (int diskNum, int firstPeg, int lastPeg, int tempPeg) {

    //base case
    if (diskNum == 1) {
        printf("%d ---> %d\n", firstPeg, lastPeg);
    }
    else {  //recursively call function twice
        towerHanoi(diskNum - 1, firstPeg, tempPeg, lastPeg);
        printf("%d ---> %d\n", firstPeg, lastPeg);
        towerHanoi(diskNum - 1, tempPeg, lastPeg, firstPeg);
    }
}  //end function