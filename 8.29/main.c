/* 8.29
 * (Write Your Own String-Comparison Functions) Write two versions of each
 * string-comparison function in Fig. 8.13. The first version should use array indexing,
 * and the second should use pointers and pointer arithmetic.
 */

#include <stdio.h>
#include <string.h>

// function prototypes
int strCmp1(const char str1[100], const char str2[100]);
int strCmp2(const char *str1, const char *str2);
int strnCmp1(const char str1[100], const char str2[100], int n);
int strnCmp2(const char *str1, const char *str2, int n);
void printAll(const char *str1, const char *str2, int n);

int main() {

    char str1[100] = {};
    char str2[100] = {};
    int num = 0;

    // prompt user to enter lines of text
    printf("\nEnter a line of text: ");
    fgets(str1, sizeof(str1), stdin);

    printf("\nEnter another line of text: ");
    fgets(str2, sizeof(str2), stdin);

    printf("\nEnter number of characters to compare: ");
    scanf_s("%d", &num);

    // print results
    printAll(str1, str2, num);

}

// function to compare strings using array indexing
int strCmp1(const char str1[100], const char str2[100]) {

    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; ++i) {
        // compare character by character
        if (str1[i] < str2[i])
            return -1;
        if (str1[i] > str2[i])
            return 1;
    }
    // check lengths when end of string is reached
    if (strlen(str1) < strlen(str2))
        return -1;
    if (strlen(str1) > strlen(str2))
        return 1;

    return 0;  // return 0 if equal
}

// function to compare strings using pointer arithmetic
int strCmp2(const char *str1, const char *str2) {
    for (int i = 0; *(str1 + i) != '\0' && *(str2 + i) != '\0'; ++i) {
        // compare character by character
        if (*(str1 + i) < *(str2 + i))
            return -1;
        if (*(str1 + i) > *(str2 + i))
            return 1;
    }
    // check lengths when end of string is reached
    if (strlen(str1) < strlen(str2))
        return -1;
    if (strlen(str1) > strlen(str2))
        return 1;

    return 0;  // return 0 if equal
}

int strnCmp1(const char str1[100], const char str2[100], int n) {

    for (int i = 0; i < n; ++i) {
        // compare character by character
        if (str1[i] < str2[i])
            return -1;
        if (str1[i] > str2[i])
            return 1;
    }
    // check lengths when end of string is reached
    if (strlen(str1) < strlen(str2))
        return -1;
    if (strlen(str1) > strlen(str2))
        return 1;

    return 0;  // return 0 if equal
}

int strnCmp2(const char *str1, const char *str2, int n) {
    for (int i = 0; i < n; ++i) {
        // compare character by character
        if (*(str1 + i) < *(str2 + i))
            return -1;
        if (*(str1 + i) > *(str2 + i))
            return 1;
    }
    // check lengths when end of string is reached
    if (strlen(str1) < strlen(str2))
        return -1;
    if (strlen(str1) > strlen(str2))
        return 1;

    return 0;  // return 0 if equal
}

// function to print results
void printAll(const char *str1, const char *str2, int n) {
    printf("\nstrcmp array indexing: %d", strCmp1(str1, str2));
    printf("\nstrcmp pointer arithmetic: %d", strCmp2(str1, str2));
    printf("\nstrncmp array indexing: %d", strnCmp1(str1, str2, n));
    printf("\nstrncmp pointer arithmetic: %d", strnCmp2(str1, str2, n));
}


