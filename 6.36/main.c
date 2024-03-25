/* 6.36
 * This program will use a recursive function which takes a character array
 * as an argument then prints it back-to-front and returns nothing.
 */

#include <stdio.h>
#include <string.h>

// function prototype
void stringReverse(char s[], int index);

// set size to 50
#define SIZE 50

int main() {

    // declare char array with size 50 characters
    char str1[SIZE];

    // prompt user to enter string to reverse
    printf("Enter string to reverse: ");
    scanf("%s", str1);

    // call function
    stringReverse(str1, strlen(str1) - 1);

}  // end main

// function stringReverse() prints the array in
// reverse then stops processing when the index
// reaches below 0
void stringReverse(char s[], int index) {

    if (index < 0) {
        return;  // stops when index becomes less than 0
    }
    printf("%c", s[index]);
    stringReverse(s, index - 1);  // recursive call

}  // end stringReverse()
