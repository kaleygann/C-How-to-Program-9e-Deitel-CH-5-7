/* 8.10
* (Comparing Portions of Strings) Write a program that uses function strncmp
* to compare two strings input by the user. The program should input the number of
* characters to be compared, then display whether those characters from the first string
* are less than, equal to or greater than the second string.
 */

#include <stdio.h>
#include <string.h>

#define SIZE 100

// function prototype
void getStrings(char s1[SIZE], char s2[SIZE], int num);
void displayResult(char s1[SIZE], char s2[SIZE], int value);
int compareStrings(char s1[SIZE], char s2[SIZE], int result);


int main() {

    // initialize char arrays to store strings
    // and variable to store number of characters to compare
    char string1[SIZE] = "";
    char string2[SIZE] = "";
    int numChar = 0;
    int result = 0;

    // prompt user for strings
    getStrings(string1, string2, numChar);

    // store result from string comparison
    int value = compareStrings(string1, string2, result);

    // display results
    displayResult(string1, string2, value);
}

// function to get the two strings from user
void getStrings(char s1[SIZE], char s2[SIZE], int num) {

    puts("Enter the first string: ");
    scanf_s("%s", s1, SIZE);

    puts("Enter the second string: ");
    scanf_s("%s", s2, SIZE);

}

// function to get number of characters from user then compare strings
int compareStrings(char s1[SIZE], char s2[SIZE], int result) {

    int num = 0;
    puts("Enter the number of characters to compare: ");
    scanf_s("%d", &num);

    result = strncmp(s1, s2, num);

    return result;
}

// function to display the result of the string comparison
void displayResult(char s1[SIZE], char s2[SIZE], int value) {

    if (value == 1) {
        printf("%s characters are greater than %s character", s1, s2);
    }
    else if (value < 0) {
        printf("%s characters are less than %s characters", s1, s2);
    }
    else
        printf("%s characters are equal to %s characters", s1, s2);
}
