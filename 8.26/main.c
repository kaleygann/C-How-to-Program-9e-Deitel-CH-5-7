/* 8.26
 * (Write Your Own Character-Handling Functions) Using the ASCII character
 * chart in Appendix B as a guide, write your own versions of the character-handling
 * functions in Section 8.3.
 */

#include <stdio.h>

// function prototypes
int isDigit(char c);
int isAlpha(char c);
int isAlnum(char c);
int isLower(char c);
int isUpper(char c);
void printAll(char c);

int main() {

    // variable to store character
    char character;

    // prompt user to enter character
    printf("Enter a letter or number: ");
    scanf("%c", &character);

    // display results
    printAll(character);

    return 0;
}

// function to check if character is a letter
int isAlpha(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// function to check if character is a number
int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// function to check if character is alphanumeric
int isAlnum(char c) {
    return (isAlpha(c) || isDigit(c));
}
// function to check if character is lowercase
int isLower(char c) {
    return (c >= 'a' && c <= 'z');
}

// function to check if character is uppercase
int isUpper(char c) {
    return (c >= 'A' && c <= 'Z');
}

// function to print results
void printAll(char c) {
    printf("Character: %c\n", c);
    printf("Alphabetic? %s\n", isAlpha(c) ? "Yes" : "No");
    printf("Digit? %s\n", isDigit(c) ? "Yes" : "No");
    printf("Alphanumeric? %s\n", isAlnum(c) ? "Yes" : "No");
    printf("Lowercase? %s\n", isLower(c) ? "Yes" : "No");
    printf("Uppercase? %s\n", isUpper(c) ? "Yes" : "No");
}




