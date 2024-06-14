/* 8.07
* (Converting Strings to Integers for Calculations) Write a program that inputs
* four strings representing integers, converts the strings to integers, sums the values and
* prints the total of the four values.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// function prototypes
void printNums(long n1, long n2, long n3, long n4);
long getSum(long n1, long n2, long n3, long n4);
void getUserInput(char s1[SIZE], char s2[SIZE], char s3[SIZE], char s4[SIZE]);

int main() {
    char string1[SIZE];
    char string2[SIZE];
    char string3[SIZE];
    char string4[SIZE];

    // get user input
    getUserInput(string1, string2, string3, string4);

    // store values in num variables
    char *remainder;
    long num1 = strtol(string1, &remainder, 10);
    long num2 = strtol(string2, &remainder, 10);
    long num3 = strtol(string3, &remainder, 10);
    long num4 = strtol(string4, &remainder, 10);

    // print strings as integers then print sum of integers
    printNums(num1, num2, num3, num4);
    printf("Sum of integers: %ld\n", getSum(num1, num2, num3, num4));

    return 0;
}

// function to obtain four strings from user
// remove all newline characters
void getUserInput(char s1[SIZE], char s2[SIZE], char s3[SIZE], char s4[SIZE]) {
    puts("Enter first string: ");
    fgets(s1, SIZE, stdin);
    s1[strcspn(s1, "\n")] = 0;

    puts("Enter second string: ");
    fgets(s2, SIZE, stdin);
    s2[strcspn(s2, "\n")] = 0;

    puts("Enter third string: ");
    fgets(s3, SIZE, stdin);
    s3[strcspn(s3, "\n")] = 0;

    puts("Enter fourth string: ");
    fgets(s4, SIZE, stdin);
    s4[strcspn(s4, "\n")] = 0;
}

// function to add the converted (to integer) strings
long getSum(long n1, long n2, long n3, long n4) {
    return n1 + n2 + n3 + n4;
}

// function to print each integer
void printNums(long n1, long n2, long n3, long n4) {
    printf("\nInteger 1: %ld\nInteger 2: %ld\nInteger 3: %ld\nInteger 4: %ld\n", n1, n2, n3, n4);
}





