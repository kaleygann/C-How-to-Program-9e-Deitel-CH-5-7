// ex06_17.c
// What does this program do?
// This program fills an array of size 10 with values
// then calculates the sum of all values, starting from
// the last position then moving downward in the array.

#include <stdio.h>
#define SIZE 10

int whatIsThis(const int b[], size_t p); // function prototype

int main(void) {
    // initialize array a
    int a[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int x = whatIsThis(a, SIZE);
    printf("Result is %d\n", x);
}

// what does this function do?
// This function uses recursion to calculate
// the sum of all elements of the array in
// from position 9 to position 0: 10 + 9 + 8 + 7...
int whatIsThis(const int b[], size_t p) {
    if (1 == p) { // base case
    return b[0];  //once p gets to first element, return value of first element
    }
    else { // recursion step
    return b[p - 1] + whatIsThis(b, p - 1);
    }
}
