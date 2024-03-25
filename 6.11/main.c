/* 6.11
 * This program will modify Fig 6_12 by
 * modifying the bubble sort to make fewer
 * comparisons on each pass; additionally, the sort
 * will be modified to check at the end of each pass whether
 * any swaps have been made (terminate if none have been made) */

// fig06_12.c
// Sorting an array's values into ascending order.

#include <stdio.h>
#define SIZE 10

// function main begins program execution
int main(void) {
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

    puts("Data items in original order");

    // output original array
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%4d", a[i]);
    }

    // bubble sort
    // loop to control number of passes
    for (int pass = 1; pass < SIZE; ++pass) {
        int swaps = 0;  //variable to count swaps
        // loop to control number of comparisons per pass
        // Edited to (SIZE - pass) to decrease number of comparisons each time
        for (size_t i = 0; i < SIZE - pass; ++i) {
            // compare adjacent elements and swap them if first
            // element is greater than second element
            if (a[i] > a[i + 1]) {
                int hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;
                swaps++;  //increment swaps
            }
        }
        if (swaps == 0) {  //if there are no swaps, break the loop
            break;
        }
    }

    puts("\nData items in ascending order");

    // output sorted array
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%4d", a[i]);
    }

    puts("");
}