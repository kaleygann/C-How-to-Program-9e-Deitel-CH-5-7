/* 8.27
 * (Write Your String-Conversion Functions) Write your own versions of the
 * functions in Section 8.4 for converting strings to numbers.
 */

#include <stdio.h>
#include <ctype.h>


// function prototypes
long toLong(const char *str, char **endPtr, int base);
unsigned long toUnsignedLong(const char *str, char **endPtr, int base);
double toDouble(const char *str, char **endPtr);
void printAll(char str1[], char **endPtr);

int main() {

    // initialize array to hold line of text
    char str1[100] = {};

    // declare end pointer
    char *endPtr;

    // prompt user to enter string
    printf("Enter line of text: ");
    fgets(str1, sizeof(str1), stdin);

    // print string conversions
    printAll(str1, &endPtr);

    return 0;
}

// function to convert string to a long int
long toLong(const char *str, char **endPtr, int base) {

    long result = 0;
    int sign = 1;

    const char *ptr = str;  // pointer to traverse string

    // skip whitespace
    while (isspace(*ptr)) {
        ptr++;
    }

    // handle signs
    if (*ptr == '-') {  // if sign is '-', set sign to -1
        sign = -1;
        ptr++;  // move to next character
    }
    else if (*ptr == '+') {  // if sign is '+', just keep traversing string
        ptr++;
    }

    // check the base
    if (base == 0) {

        if (*ptr == '0') {
            ptr++;
            if (*ptr == 'x' || *ptr == 'X') {  // if '0x' or '0X', base is 16
                base = 16;
                ptr++;  // move past x or X
            }
            else {
                base = 8;  // otherwise, base is 8
            }
        }
        else {
            base = 10;  // if no prefix, default base is 10
        }
    }

    // if base is 16 and string starts with '0x' or '0X', skip both characters
    else if (base == 16 && *ptr == '0' && (*(ptr + 1) == 'x' || *(ptr + 1) == 'X')) {
        ptr += 2;
    }

    // convert digit to integer
    while (isalnum(*ptr)) {

        int digit;

        if (isdigit(*ptr)) {  // if numeric, convert to integer
            digit = *ptr - '0';
        }
        else if (isalpha(*ptr)) {  // if alphabetic, convert to integer
            digit = toupper(*ptr) - 'A' + 10;
        }
        else {  // break loop if character is neither letter nor number
            break;
        }
        if (digit >= base) {
            break;  // break loop if digit is not valid
        }

        // update result and move to next character
        result = result * base + digit;
        ptr++;
    }

    // set end point position
    if (endPtr != NULL) {
        *endPtr = (char *)ptr;
    }

    // return result
    return sign * result;
}

// function to convert a string to an unsigned long integer
// calls toLong() and casts the result to unsigned long
unsigned long toUnsignedLong(const char *str, char **endPtr, int base) {
    return (unsigned long)toLong(str, endPtr, base);
}

// function to convert a string to a double
double toDouble(const char *str, char **endPtr) {

    double result = 0.0;
    int sign = 1;
    const char *ptr = str;

    // skip whitespace
    while (isspace(*ptr)) {
        ptr++;
    }

    if (*ptr == '-') {  // if the sign is negative, make sign negative
        sign = -1;
        ptr++;
    }
    else if (*ptr == '+') {  // if sign is positive, move to next character
        ptr++;
    }

    // convert integer portion
    while (isdigit(*ptr)) {
        result = result * 10.0 + (*ptr - '0');  // Update the result
        ptr++;  // Move to the next character
    }

    // convert fraction part
    if (*ptr == '.') {

        // variables to store fractional part and its divisor
        double fraction = 0.0;
        double divisor = 10.0;
        ptr++;  // move to next character

        // update fractional part and update divisor
        while (isdigit(*ptr)) {
            fraction += (*ptr - '0') / divisor;
            divisor *= 10.0;
            ptr++;  // move to next character
        }
        result += fraction;  // accumulate fractional parts in result
    }

    // handle exponentiation string
    if (toupper(*ptr) == 'E') {

        int expSign = 1;
        int exponent = 0;
        ptr++;  // move to next character

        if (*ptr == '-' || *ptr == '+') {
            if (*ptr == '-') {
                expSign = -1;  // set exponent sign to negative
            }
            ptr++;  // move to next character
        }

        while (isdigit(*ptr)) {
            exponent = exponent * 10 + (*ptr - '0');  // Update the exponent
            ptr++;  // Move to the next character
        }

        while (exponent > 0) {
            if (expSign == 1) {  // if exponent is positive, multiple result by 10
                result *= 10.0;
            }
            else {  // if exponent negative, divide result by 10
                result /= 10.0;
            }
            exponent--;  // decrement exponent
        }
    }

    if (endPtr != NULL) {
        *endPtr = (char *)ptr;  // set the endPtr to the position where parsing stopped
    }

    return sign * result;  // return the result with the correct sign
}

// function to print all the values
void printAll(char str1[], char **endPtr) {

    // find the first numeric part in the string
    char *ptr = str1;
    while (*ptr && !isdigit(*ptr)) {
        ptr++;
    }

    // if no numbers are found, notify user
    if (*ptr == '\0') {
        printf("No number found in the line of text.\n");
        return;
    }

    // print results
    printf("Integer: %ld\n", toLong(ptr, endPtr, 10));
    printf("Unsigned integer: %lu\n", toUnsignedLong(ptr, endPtr, 10));
    printf("Double: %.2f\n", toDouble(ptr, endPtr));
}
