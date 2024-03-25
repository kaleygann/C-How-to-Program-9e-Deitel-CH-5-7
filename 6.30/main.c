/* 6.30
 * This program will use the Sieve of Eratosthenes to find all subscripts of an
 * array that are prime numbers less than 1000 then display them.
 */

#include <stdio.h>
#include <math.h>

// function prototypes
void fillArray(int a[]);
void isPrime(int a[]);
void printPrimes(const int a[]);

#define SIZE 1000  // set size to 1000

int main() {

    // declare array
    int arr[SIZE];

    // function calls
    fillArray(arr);
    isPrime(arr);

    // display prime numbers
    printf("Prime numbers between 2 and %d: \n", SIZE);
    printPrimes(arr);

} // end main

// function fillArray() will loop through the array
// and initialize all elements to 1 (true)
void fillArray(int a[]) {
    for (int i = 2; i < SIZE; ++i) {
        a[i] = 1;
    }
}  // end fillArray()

// void isPrime() will loop through the array and check the elements
// to see if their subscripts to find ones that aren't multiples of 2, 3, 4, etc.
// then set each to 0
void isPrime(int a[]) {
    for (int i = 2; i < sqrt(SIZE); ++i) {
        if (a[i] == 1) {
            for (int j = i * 2; j < SIZE; j += i) {
                a[j] = 0;
            }
        }
    }
} // end isPrime()

// printPrimes() will loop through the array and
// print each prime subscript of elements still
// set to 1
void printPrimes(const int a[]) {
    for (int i = 0; i < SIZE; ++i) {
        if (a[i] == 1) {
            printf("%d ", i);
        }
    }
}  // end printPrimes()



