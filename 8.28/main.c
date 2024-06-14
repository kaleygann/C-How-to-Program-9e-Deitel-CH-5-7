/* 8.28
 * (Write Your Own String-Copy and String-Concatenation Functions) Write
 * two versions of each string-copy and string-concatenation function in Section 8.6.
 * The first version should use array indexing, and the second should use pointers and
 * pointer arithmetic.
 */

#include <stdio.h>
#include <string.h>

#define SIZE 100

// function prototypes
void stringCopy(char str1[SIZE], char str2[SIZE]);
void stringCopy2(char *str1, char *str2);
void stringCat(char str1[SIZE], char str2[SIZE], char str3[SIZE * 2]);
void stringCat2(char *str1, char *str2, char *str3);
void getInput(char str1[SIZE], char str2[SIZE]);

int main() {

    // arrays to store lines of text
    char str1[SIZE] = {};
    char str2[SIZE] = {};
    char str3[SIZE * 2] = {};

    // get input for first string copy
    // print result
    getInput(str1, str2);
    stringCopy(str1, str2);
    printf("\nCopied string: %s\n", str1);

    // get input for second string copy
    // print result
    getInput(str1, str2);
    stringCopy2(str1, str2);
    printf("\nCopied string: %s\n", str1);

    // get input for first string concatenation
    // print result
    getInput(str1, str2);
    stringCat(str1, str2, str3);
    printf("\nConcatenated string: %s\n", str3);

    // get input for second string concatenation
    // print result
    getInput(str1, str2);
    stringCat2(str1, str2, str3);
    printf("\nConcatenated string: %s\n", str3);

    return 0;
}

// function to get user input
void getInput(char str1[SIZE], char str2[SIZE]) {

    printf("\nEnter a line of text: ");
    fgets(str1, SIZE, stdin);
    str1[strcspn(str1, "\n")] = '\0';  // remove newline

    printf("Enter another line of text: ");
    fgets(str2, SIZE, stdin);
    str2[strcspn(str2, "\n")] = '\0';  // remove newline
}

// function to copy strings using array indexing
void stringCopy(char str1[SIZE], char str2[SIZE]) {

    int i = 0;
    while (str2[i] != '\0') {
        str1[i] = str2[i];  // copy str2 into str1
        ++i;
    }
    str1[i] = '\0';  // null-terminate str1
}

// function to copy strings using pointer arithmetic
void stringCopy2(char *str1, char *str2) {

    while ((*str1 = *str2) != '\0') {  // copy str2 into str1
        str1++;
        str2++;
    }
}

// function to concatenate string using array indexing
void stringCat(char str1[SIZE], char str2[SIZE], char str3[SIZE * 2]) {

    int i = 0, j = 0;

    // copy str1 to str3
    while (str1[i] != '\0') {
        str3[i] = str1[i];
        i++;
    }
    // concatenate str2 to str3
    while (str2[j] != '\0') {
        str3[i] = str2[j];
        i++;
        j++;
    }
    str3[i] = '\0';  // null-terminate str3
}

// function to concatenate string using pointer arithmetic
void stringCat2(char *str1, char *str2, char *str3) {

    while (*str1 != '\0') {
        *str3 = *str1;  // concatenate str1 to str3
        str1++;
        str3++;
    }
    while (*str2 != '\0') {
        *str3 = *str2;  // concatenate str2 to str3
        str2++;
        str3++;
    }
    *str3 = '\0';  // null-terminate str3
}
