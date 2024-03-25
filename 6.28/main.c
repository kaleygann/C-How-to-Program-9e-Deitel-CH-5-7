/* 6.28
 * This program will produce 20 random numbers between 1 and 20 then
 * store all non-duplicate values in an array, using the smallest possible
 * array.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// function prototypes
void fillArray(int a[]);
void printArrays(int a[], int n[], int count);

// use constant for array size of 20
#define SIZE 20

int main() {

    // seed random generator
    srand(time(0));

    //initialize local variable
    int count = 0;

    // declare an original array and an array to store new values
    int arr[SIZE], newArr[SIZE];

    // call function to fill array
    fillArray(arr);

    // loop through arrays and compare their elements
    for (int i = 0; i < SIZE; i++) {
        int j;
        for (j = 0; j < count; j++) {
            if (arr[i] == newArr[j])  // if elements are equal to each other, terminate loop
                break;
        }
        if (j == count) {  // if loop doesn't break and j is incremented, set new array value to original array value
            newArr[count] = arr[i];
            count++;  // increment count
        }
    }  // end for

    // display original array and array with no duplicate values
    printArrays(arr, newArr, count);

}  // end main

/* function fillArray() will fill original array with values
 * between 1 and 20, inclusive */
void fillArray(int a[]) {
    for (int i = 0; i < SIZE; i++) {
        a[i] = 1 + rand() % 20;
    }
}  // end fillArray()

/* function printArrays() will print the original array then
 * the new array containing no duplicate values */
void printArrays(int a[], int n[], int count) {
    printf("\nOriginal array: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", a[i]);

    printf("\nArray without duplicate values: ");
    for (int i = 0; i < count; i++)
        printf("%d ", n[i]);
}  // end printArrays()