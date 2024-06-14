/* 8.14
* (Tokenizing Telephone Numbers) Write a program that inputs a telephone
* number as a string in the form (555) 555-5555. Use function strtok to extract as
* tokens the area code, the first three digits of the phone number and the last four digits
* of the phone number. Concatenate the phone number’s seven digits into one string.
* Convert the area-code string and phone-number string to integers, then display both.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
int getAreaCode(char phone[15], char *endPtr);
int getRemaining(char *endPtr);
void printAll(int area, int rem);

int main() {

    // declare array to store phone number
    // declare pointer for character address
    // declare area and remainder variables
    char phone[15];
    char *endPtr;
    int area, remainder;

    // prompt user to input phone number
    printf("Enter the telephone number in format (XXX) XXX-XXXX: ");
    fgets(phone, sizeof(phone), stdin);

    // store values in area and remainder variables
    area = getAreaCode(phone, endPtr);
    remainder = getRemaining(endPtr);

    // display results
    printAll(area, remainder);

    return 0;
}

// function to extract area code from phone number
int getAreaCode(char phone[15], char *endPtr) {

    // tokenize phone number to get area code
    char *area_code = strtok(phone, "()");

    // convert area code to integer then return value
    int area_int = strtol(area_code, &endPtr, 0);
    return area_int;
}

// function to extract remaining digits from phone number
int getRemaining(char *endPtr) {

    // store digits in array
    char digits[8] = "";

    // tokenize remainder of phone number after area code
    char *first_three = strtok(NULL, "- ");
    char *last_four = strtok(NULL, " ");

    // store remaining numbers in digits array
    strcpy(digits, first_three);
    strncat(digits, last_four, 4);

    // convert digits to integer then return value
    int phone_int = strtol(digits, &endPtr, 0);
    return phone_int;
}

// function to separately print area code and remaining digits
void printAll(int area, int rem) {
    printf("Area code: %d\n", area);
    printf("Phone number: %d\n", rem);
}
