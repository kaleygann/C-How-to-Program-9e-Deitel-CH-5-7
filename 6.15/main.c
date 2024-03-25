/* 6.15
 * This program will use a one-dimensional array to read 20 numbers between 10 and 100 (inclusive)
 * then print the number only if it is not a duplicate of a number already read.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// function prototypes
int isDuplicate(const int arr[], int dupe, int c, int val);
void printValues(const int arr[], int c);

#define SIZE 20  // set array size to 20

int main() {

    // seed random generator
    srand(time(0));

    // initialize array
    int numbers[SIZE] = {0};

    // local variables
    int count = 0;
    int value;

    // loop through array and add random values that are not duplicates
    for (int i = 0; i < SIZE; ++i) {
        int duplicate = 0;
        value = 10 + rand() % 91;

        // if duplicate function does not return 1 (true), add value to array
        if (!isDuplicate(numbers, duplicate, count, value)) {
            numbers[count++] = value;
        }
    }  // end for

    // call function to display values
    printValues(numbers, count);

} // end main

// function isDuplicate() returns 1 if a duplicate
// is found in the array
int isDuplicate(const int arr[], int dupe, int c, int val) {

    // loop through array and check for duplicates
    for (int j = 0; j < c; ++j) {
        if (val == arr[j]) {
            dupe = 1;
            break;  // exit loop if duplicate occurs
        }
    }  //end for
    return dupe;  // return 1 (true) if duplicate is found
}  // end isDuplicate()

// function printValues() prints all values
// in the array that are not duplicates
void printValues(const int arr[], int c) {
    printf("\nValues with no duplicates: \n");
    // loop through array and print each value
    for (int i = 0; i < c; ++i) {
        printf("%d ", arr[i]);
    }
}  //end printValues()