/* 6.37
 * This program will use a recursive function to print the
 * smallest element of an array containing 10 random numbers
 * between 0 and 100 (inclusive). */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// function prototypes
void fillArray(int a[]);
void printArray(const int a[]);
int recursive_Minimum(const int a[], int size);

// symbolic constant size set to 10
#define SIZE 10

int main() {

    // seed random generator
    srand(time(0));

    // declare array of size 10
    int arr[SIZE] = {};

    // output header
    printf("Array elements: \n");

    // function calls
    fillArray(arr);
    printArray(arr);

    // prints smallest value and calls function
    printf("\nSmallest value: %d", recursive_Minimum(arr, SIZE));

}

/* fillArray() will fill the array with
   random numbers between 1 and 100, inclusive */
void fillArray(int a[]) {
    for (int i = 0; i < SIZE; ++i) {
        a[i] = 1 + rand() % 100;
    }
}  // end fillArray()

/* printArray() will print all values in
 * the array */
void printArray(const int a[]) {
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", a[i]);
    }
}  // end printArray()

/* recursive_Minimum() uses recursion to go through array
 * and find the smallest value then return it. Calls itself
 * 9 times before terminating */
int recursive_Minimum(const int a[], int size) {
    int smallest;
    if (size == 1) {
        return a[size - 1];  // base case reached when size = 1, returns a[0]
    }
    smallest = recursive_Minimum(a, size - 1);  // recursive call

    if (smallest < a[size - 1]) {
        return smallest;
    }
    else
        return a[size - 1];

}  // end recursive_Minimum()
