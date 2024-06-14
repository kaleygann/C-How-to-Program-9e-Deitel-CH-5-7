/* 8.09
* (Comparing Strings) Write a program that uses function strcmp to compare
* two strings input by the user. The program should state whether the first string is less
* than, equal to or greater than the second string.
*/

#include <stdio.h>
#include <string.h>

// store size value
#define SIZE 100

// function prototypes
void getUserInput(char s1[SIZE], char s2[SIZE]);
void printResult(char s1[SIZE], char s2[SIZE], int r);

int main() {

    // initialize string arrays
    char string1[SIZE] = "";
    char string2[SIZE] = "";

    // prompt user for strings
    getUserInput(string1, string2);

    //variable to store result
    int result = strcmp(string1, string2);

    // display results
    printResult(string1, string2, result);

    return 0;
}

// function to get strings from user
void getUserInput(char s1[SIZE], char s2[SIZE]) {
    puts("Enter first string: ");
    scanf_s("%s", s1, SIZE);

    puts("Enter second string: ");
    scanf_s("%s", s2, SIZE);
}

// function to display results
void printResult(char s1[SIZE], char s2[SIZE], int r) {
    if (r == 1) {
        printf("%s is greater than %s", s1, s2);
    }
    else if (r < 0) {
        printf("%s is less than %s", s1, s2);
    }
    else if (r == 0) {
        printf("%s is equal to %s", s1, s2);
    }
}
