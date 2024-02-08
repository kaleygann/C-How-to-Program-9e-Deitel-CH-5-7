/* 5.37
 * This program will solve the Tower of
 * Hanoi problem iteratively using a
 * function.
 */

#include <stdio.h>
#include <math.h>

void towerHanoi(int);  //function prototype

int main() {  //main header

    int diskNum;  //local variable

    printf("Enter number of disks: ");  //prompt user to enter number of disks
    scanf_s("%d", &diskNum);  //read number of disks value from kb

    towerHanoi(diskNum);  //function call

}  //end main

//function using bitwise operators to move disks
void towerHanoi(int diskNum) {

    for (int i = 1; i < pow(2, diskNum); ++i) {  //iterate number of moves

        int a = ((i & i - 1) % 3) + 1;  //set variable a using bitwise AND
        int b = (((i | i - 1) + 1) % 3) + 1;  //set variable b using bitwise OR

        printf("%d ---> %d\n", a, b);  //print move
    }  //end for

}  //end function
