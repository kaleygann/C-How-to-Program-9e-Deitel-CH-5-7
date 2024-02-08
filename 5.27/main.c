/* 5.27
 * This program will determine and
 * print all prime numbers between
 * 1 and 10,000 using two different
 * methods.
 * */

#include <stdio.h>
#include <math.h>

//function prototypes
int isPrime(int);
int isPrimeSqrt(int);

int main() {  //main header

    printf("\n1. All prime numbers between 1 and 10,000 are:\n");  //output header

    for (int num = 2; num <= 10000; ++num) {  //for loop to iterate between 2 and 10,000 (1 is not prime)
        if (isPrime(num))  //call function
            printf("%d ", num);  //print prime number
    }  //end for

    printf("\n\n2. All prime numbers between 1 and 10,000 are:\n");  //output header

    for (int num = 2; num <= 10000; ++num) { //for loop to iterate between 2 and 10,000 (1 is not prime)
        if (isPrimeSqrt(num))  //call function
            printf("%d ", num);  //print prime number
    }  //end for

}  //end main

// function isPrime() determines whether a number
// is prime using division then returns true or false
int isPrime(int num) {

    for (int i = 2; i <= num / 2; ++i) {  //for loop
        if (num % i == 0)  //return false if remainder of current number / i is 0
            return 0;
    }  //end for
    return 1;  //otherwise return true
}  //end function

// function isPrime() determines whether a number is prime
// using the square root function then returns true or false
int isPrimeSqrt(int num) {

    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0)  //return false if remainder of current number / i is 0
            return 0;
    }  //end for
    return 1;  //otherwise, return true
}  //end function