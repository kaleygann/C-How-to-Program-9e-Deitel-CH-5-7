/* 6.32
 * This program will modify the program of Fig. 6.14 to use a recursive linear-Search
 * function to perform the lienar search of an array. The function will receive an integer array, the
 * size of the array, and the search key as arguments. If the search key is found, return the array
 * subscript; otherwise, return -1.
 */

// fig06_14.c
// Linear search of an array.
#include <stdio.h>
#define SIZE 100

// function prototype
int linearSearch(const int array[], int key, size_t size);

// function main begins program execution
int main(void) {
    int a[SIZE] = {0}; // create array a

    // create some data
    for (size_t x = 0; x < SIZE; ++x) {
        a[x] = 2 * x;
    }

    printf("Enter integer search key: ");
    int searchKey = 0; // value to locate in array a
    scanf("%d", &searchKey);

    // attempt to locate searchKey in array a
    int subscript = linearSearch(a, searchKey, SIZE);

    // display results
    if (subscript != -1) {
        printf("Found value at subscript %d\n", subscript);
    }
    else {
        puts("Value not found");
    }
}

// compare key to every element of array until the location is found
// or until the end of array is reached; return subscript of element
// if key is found or -1 if key is not found
int linearSearch(const int array[], int key, size_t size) {

    if (size == 0) {  // base case: if array size becomes 0, return -1
        return -1;
    }
    if (array[size - 1] == key) {  // if key is equal to value at index size - 1, return size - 1
        return size - 1;
    }
    // if key is still not found, functions calls itself (recursion)
    return linearSearch(array, key, size - 1);
}

