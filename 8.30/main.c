/* 8.30
 * (Write Your Own String-Length Function) Write two versions of function
 * strlen in Fig. 8.27. The first version should use array indexing, and the second
 * should use pointers and pointer arithmetic.
 */

#include <stdio.h>

// function prototypes
int getLength1(const char str[100]);
int getLength2(const char *str);
void printLengths(const char *str);

int main() {

    // array to store line of text
    char str[100] = {};

    // prompt user to enter line of text
    printf("Enter line of text: ");
    fgets(str, sizeof(str), stdin);

    // display length of string obtained
    // using two different methods
    printLengths(str);

    return 0;
}

// function to get length of
// string using array indexing
int getLength1(const char str[100]) {
    int count = 0;
    while (str[count] != '\0'){
            count++;
    }
    return count - 1;
}

// function to get length of
// string using pointer arithmetic
int getLength2(const char *str) {
    int count = 0;
    while (*(str + count) != '\0') {
        count++;
    }
    return count - 1;
}

// function to print length of
// string using both methods
void printLengths(const char *str) {
    printf("\nTEXT LENGTH: \n");
    printf("Array indexing: %d characters\n", getLength1(str));
    printf("Pointer arithmetic: %d characters", getLength2(str));
}

