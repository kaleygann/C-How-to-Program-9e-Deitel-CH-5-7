/* 6.35
 * This program will use a recursive function that takes an array
 * and the size of the array as arguments then print the array once
 * it receives an array of size 0.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// function prototypes
void fillArray(int a[]);
void printArray(int a[], int);

#define SIZE 10

int main() {
    srand(time(0));  // seed random generator

    // initialize array
    int array[SIZE] = {};

    // output header
    printf("Array elements: \n");

    // function calls
    fillArray(array);
    printArray(array, SIZE);
}

/* fillArray() will fill the array with
   random numbers between 1 and 100, inclusive */
void fillArray(int a[]) {
    for (size_t i = 0; i < SIZE; ++i) {
        a[i] = 1 + rand() % 100;
    }
}  // end fillArray()

/* printArray() will recursively call itself
   to print the elements of the array until
   base case size 0 is reached */
void printArray(int a[], int s) {
    if (s == 0) {
        return;
    }
    printf("%d ", a[0]);
    printArray(a + 1, s - 1); // recursive call

} // end printArray()
