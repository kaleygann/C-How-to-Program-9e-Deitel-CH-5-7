/* 8.06
 * (Displaying Strings in Uppercase and Lowercase) Write a program
 * that inputs a line of text into char array s[100]. Display the
 * line in uppercase letters and in lowercase letters.
 */

#include <stdio.h>
#include <ctype.h>

// function prototypes
void toUpper(char s[]);
void toLower(char s[]);
void printLines(char s[]);

int main() {

    // initialize array s
    char str[100] = "";

    // prompt user for input
    puts("Enter a line of text:");
    scanf_s("%99[^\n]", str);

    // display converted line
    printLines(str);

    return 0;
}

// function to convert line to uppercase
void toUpper(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        s[i] = toupper(s[i]);
        ++i;
    }
}

// function to convert line to lowercase
void toLower(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        s[i] = tolower(s[i]);
        ++i;
    }
}

// function to print line converted to uppercase and lowercase
void printLines(char s[]) {

    puts("\nOriginal line converted to uppercase:");
    toUpper(s);
    puts(s);

    puts("\nOriginal line converted to lowercase:");
    toLower(s);
    puts(s);
}


