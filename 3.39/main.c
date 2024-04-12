/* 3.39
 * This program will display a checkerboard
 * pattern of asterisks.
 */

#include <stdio.h>

int main() { //main header
    //initialize variable
    int x = 0;
    //for loop to iterate four times
    for (x=1; x<=8; x+=2){
        printf("%s", "* * * * * * * *"); //print 1st, 3rd, 5th, and 7th row
        puts("");
        printf("%s", " * * * * * * * *\n"); //print 2nd, 4th, 6th, and 8th row
    } //end for
} //end main
