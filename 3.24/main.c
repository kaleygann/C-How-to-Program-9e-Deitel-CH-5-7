/* 3.24
 * This program will use looping to print
 * a table of values and use the tab escape
 * sequence to format the output.
 */

#include <stdio.h>

int main() { //main header

    int n = 1; //initialize n to 1

    printf("%s", "\nN\t10*N\t100*N\t1000*N\n\n"); //display header

        while (n <= 10){ //while loop

            printf("%d\t", n); //display number
            printf("%d\t", n * 10); //display number times 10
            printf("%d\t", n * 100); //display number times 100
            printf("%d\t\n", n * 1000); //display number times 1000
            n++; //increment n

        } //end while
} //end main
