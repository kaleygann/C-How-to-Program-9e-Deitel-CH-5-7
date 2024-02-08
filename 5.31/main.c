/* 5.31
 * This program will
 * simulate coin tossing by
 * using a function to "flip"
 * a coin then displaying the
 * results.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip ();  //function prototype

int main() {  //main header

    int heads, tails;  //local variables
    srand(time(0));  //srand() to get different series of numbers each time

    for (int i = 1; i <= 100; ++i) {  //for loop to iterate number of tosses

        flip();  //call function flip()

        if (flip() == 1) {  //accumulate heads when flip() returns 1
            heads++;
        }  //end if
        else  //accumulate tails when flip() returns 0
            tails++;

    }  //end for

    //display results
    printf("Heads: %d\n", heads);
    printf("Tails: %d", tails);

}  //end main

/* function flip()
 * generates a random
 * number between 1 and 2
 * then returns 1 for 1 and
 * 0 for 2
 */

int flip () {
        int num = rand() % 2;
        if (num == 1) {
            return 1;
        }
        else
            return 0;
    }  //end function



