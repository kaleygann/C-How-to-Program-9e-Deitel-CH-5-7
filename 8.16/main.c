/* 8.16
 * (Searching for Substrings) Write a program that inputs a line of text and a
 * search string from the keyboard. Using function strstr, locate the first occurrence of
 * the search string in the line of text. Assign the location to variable searchPtr of type
 * char *. If the search string is found, print the remainder of the line of text beginning
 * with the search string. Then, use strstr again to locate the next occurrence of the
 * search string in the line of text. If a second occurrence is found, print the remainder
 * of the line of text beginning with the second occurrence. [Hint: The second call to
 * strstr should contain searchPtr + 1 as its first argument.]
 */

#include <stdio.h>
#include <string.h>


int main() {

    char line[1000];
    char search[100];
    char *searchPtr;

    // prompt user for line of text
    printf("Enter a line of text: ");
    fgets(line, sizeof(line), stdin);

    // prompt user for string to be searched
    printf("Enter the search string: ");
    scanf("%s", search);

    // find first occurrence of search string
    searchPtr = strstr(line, search);

    // if search string is found
    if (searchPtr != NULL) {

        // print remainder of line with first occurrence
        printf("Remainder of text beginning with first occurrence: %s\n", searchPtr);
        searchPtr = strstr(searchPtr + 1, search);  // search text for second occurrence

        // if search string is found again, print
        // remainder of line with second occurrence
        if (searchPtr != NULL) {
            printf("Remainder of text beginning with second occurrence: %s\n", searchPtr);
        }
        else {
            printf("Second occurrence not found.\n");  // if second occurrence is not found
        }
    }
    else {
        printf("Search string not found.\n");  // if first occurrence is not found
    }

    return 0;

}
