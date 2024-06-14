/* 8.32
 * (Printing Dates in Various Formats) Dates are commonly printed in several
 * different formats in business correspondence. Two of the more common formats are
 * 07/21/2003 and July 21, 2003. Write a program that reads a date in the first format
 * and prints it in the second format.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function prototypes
int monthToInt(char *month, char *endPtr);
void getMonthName(char *month, char *endPtr);
void dateString(char new_date[14], char month[20], char *day, char *year);
void tokenizeString(char *date, char month[20], char **day, char **year);


int main() {

    // character arrays to store date and month
    // pointers to store day, year, and end address
    char date[11] = {};
    char month[20] = {};
    char new_date[14] = {};
    char *day, *year, *endPtr = NULL;

    // prompt user to enter date
    printf("Enter date (MM/DD/YYYY): ");
    fgets(date, sizeof(date), stdin);

    // function calls
    tokenizeString(date, month, &day, &year);
    getMonthName(month,endPtr);
    dateString(new_date, month, day, year);

    // display date
    printf("Date: %s\n", new_date);

    return 0;
}

// tokenize the date input by user
void tokenizeString(char *date, char month[20], char **day, char **year) {
    char *token;
    token = strtok(date, "/");
    if (token != NULL) {
        strcpy(month, token);
        token = strtok(NULL, "/");
        if (token != NULL) {
            *day = token;
            token = strtok(NULL, "/");
            if (token != NULL) {
                *year = token;
            }
        }
    }
}

// function to convert month number to month name
void getMonthName(char *month, char *endPtr) {
    switch(monthToInt(month, endPtr)) {
        case 1:
            strcpy(month, "January");
            break;
        case 2:
            strcpy(month, "February");
            break;
        case 3:
            strcpy(month, "March");
            break;
        case 4:
            strcpy(month, "April");
            break;
        case 5:
            strcpy(month, "May");
            break;
        case 6:
            strcpy(month, "June");
            break;
        case 7:
            strcpy(month, "July");
            break;
        case 8:
            strcpy(month, "August");
            break;
        case 9:
            strcpy(month, "September");
            break;
        case 10:
            strcpy(month, "October");
            break;
        case 11:
            strcpy(month, "November");
            break;
        case 12:
            strcpy(month, "December");
            break;
    }
}

// function to concatenate the date components
void dateString(char new_date[14], char month[20], char *day, char *year) {
    strcpy(new_date, month);
    strcat(new_date, " ");
    strcat(new_date, day);
    strcat(new_date, ",");
    strcat(new_date, " ");
    strcat(new_date, year);
}

// function to convert the month string to an integer
int monthToInt(char *month, char *endPtr) {
    return strtol(month, &endPtr,10);
}


