/* 3.25
 * This program will use a loop to
 * produce a table of values using
 * the tab escape sequence to format
 * the output
 */

#include <stdio.h>

int main() { //main header

    int a = 3; //initialize a to 3

        printf("%s", "\nA\tA+2\tA+4\tA+6\n\n"); //display header

            while (a <= 15){ //while loop

                printf("%d\t", a); //display a
                printf("%d\t", a + 2); //display a + 2
                printf("%d\t", a + 4); //display a + 4
                printf("%d\t\n", a + 6); //display a + 6

                a += 3; //increase a by 3 each iteration
        } //end while

} //end main
