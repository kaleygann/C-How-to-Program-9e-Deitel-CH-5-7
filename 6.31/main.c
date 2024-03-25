/* 6.31
 * This program will use a recursive function to determine
 * whether a string is a palindrome. Returns 1 if the
 * string is a palindrome; returns 0 if the string is not
 * a palindrome.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function prototype
void printAll(char s1[], char s2[], char s3[], char s4[]);

int main() {

    // initialize some character arrays to test for palindromes
    char str1[] = "Radar...";
    char str2[] = "A man, a plan, a canal, Panama!";
    char str3[] = "My dog, Chai, is very cute!";
    char str4[] = "able was i ere i saw elba";

    // function call to print whether strings are palindromes
    printAll(str1, str2, str3, str4);

}  // end main

/* function toLower() converts characters to lowercase */
char toLower(char c) {
    return tolower(c);
}

/* function isAlpha() checks if character is alphabetical */
int isAlpha(char c) {
    return isalpha(c);
}

/* function isPalindrome() uses recursion to check if string is palindrome */
int isPalindrome(char str[], int start, int end) {

    if (start >= end)  // base case: if length of string is 0 or if only 1 character
        return 1;

    // move through characters from start and from end and ignore non-alphabetic characters
    while (start < end && !isAlpha(str[start]))
        start++;
    while (end > start && !isAlpha(str[end]))
        end--;

    // convert characters to lowercase
    char first_char = toLower(str[start]);
    char last_char = toLower(str[end]);

    // if characters are the same, check for characters between them
    if (first_char == last_char)
        return isPalindrome(str, start + 1, end - 1);

    // if the characters are not equal, string is not a palindrome
    return 0;
}

/* function testPalindrome() tests whether sentence or string is palindrome */
int testPalindrome(char str[]) {

    int length = strlen(str);  // set length of string

    return isPalindrome(str, 0, length - 1);  // return recursive function
}

/* function printAll() displays outputs whether strings are palindromes */
void printAll(char s1[], char s2[], char s3[], char s4[]) {

    printf("\"%s\" is%s a palindrome.\n", s1, testPalindrome(s1) ? "" : " not");
    printf("\"%s\" is%s a palindrome.\n", s2, testPalindrome(s2) ? "" : " not");
    printf("\"%s\" is%s a palindrome.\n", s3, testPalindrome(s3) ? "" : " not");
    printf("\"%s\" is%s a palindrome.\n", s4, testPalindrome(s4) ? "" : " not");
}



