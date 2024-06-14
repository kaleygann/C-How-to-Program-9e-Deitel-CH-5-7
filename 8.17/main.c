/*
 * 8.17
 * (Counting the Occurrences of a Substring) Write a program based on
 * Exercise 8.16 that inputs several lines of text and a search string and uses function
 * strstr to determine the total occurrences of the search string in the lines of text. Print
 * the result.
 */

#include <stdio.h>
#include <string.h>

// function prototypes
int searchString(char line[1000], char search[100]);
int addStrings(char l1[1000], char l2[1000], char l3[1000], char search[100]);

int main() {

    // initialize arrays to store lines of text and search string
    // initialize count variable
    char line1[1000], line2[1000], line3[1000] = {};
    char search[100] = {};
    int sum;

    // prompt user to enter three lines of text
    printf("Enter a line of text: ");
    fgets(line1, sizeof(line1), stdin);

    printf("Enter line of text: ");
    fgets(line2, sizeof(line2), stdin);

    printf("Enter line of text: ");
    fgets(line3, sizeof(line3), stdin);

    printf("Enter search string: ");
    scanf_s("%s", search);

    // add instances of search strings
    sum = addStrings(line1, line2, line3, search);

    // display results
    printf("The string '%s' appears %d %s%s", search, sum, (sum == 1) ? "time" : "times", (sum > 1) ? "s" : "");

    return 0;
}

// function to count each occurrence of search string in each line of text
int searchString(char line[1000], char search[100]) {

    char *searchPtr;

    int count = 0;
    searchPtr = strstr(line, search);

    while (searchPtr != NULL) {
        count++;
        searchPtr = strstr(searchPtr + 1, search);
    }
    return count;
}

// function to add number of occurrences of search string from all lines of text
int addStrings(char l1[1000], char l2[1000], char l3[1000], char search[100]) {

    int sum = searchString(l1, search) +
            searchString(l2, search) +
            searchString(l3, search);

    return sum;
}


