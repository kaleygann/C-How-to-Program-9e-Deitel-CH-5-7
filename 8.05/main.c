/* 8.05
(Character Testing) Write a program that inputs a character from the keyboard
and tests it with each of the character-handling library functions. The program
should print the value returned by each function.
 */

#include <stdio.h>
#include <ctype.h>

int main() {

    // variable to store character
    char character = ' ';

    // prompt user for character input
    printf("Enter a character: ");
    scanf_s(" %c", &character);
    printf("\nTEST CHARACTER-HANDLING FUNCTIONS: \n");

    // test character-handling library functions
    // print values returned by each function
    printf("%s\n%s%s\n\n", "\nisdigit(): ",
           isdigit(character) ? "Character is a " : "Character is not a ", "digit");

    printf("%s\n%s%s\n\n", "isalpha(): ",
           isalpha(character) ? "Character is an " : "Character is not an ", "alphabetical character");

    printf("%s\n%s%s\n\n", "isalnum(): ",
           isalnum(character) ? "Character is a " : "Character is not a ", "digit or a letter");

    printf("%s\n%s%s\n\n", "isxdigit(): ",
           isxdigit(character) ? "Character is a " : "Character is not a ", "hexadecimal digit");

    if (isalpha(character)) {
        printf("%s\n%s%s\n\n", "islower(): ",
               islower(character) ? "Character is " : "Character is not ", "lowercase");

        printf("%s\n%s%s\n\n", "isupper(): ",
               isupper(character) ? "Character is " : "Character is not ", "uppercase");
    }

    if (isupper(character) && isalpha(character)) {
        printf("%s%s%c\n\n", "tolower(): \n",
               "Character converted to lowercase is ", tolower(character));
    }

    else if (islower(character) && isalpha(character)) {
        printf("%s%s%c\n\n", "toupper(): \n",
               "Character converted to uppercase is ", toupper(character));
    }

    printf("%s\n%s%s\n\n", "isspace(): ",
           isspace(character) ? "Character is a " : "Character is not a ", "space");

    printf("%s\n%s%s\n\n", "ispunct(): ",
           ispunct(character) ? "Character is a " : "Character is not a ", "punctuation character");


    printf("%s\n%s%s\n\n", "iscntrl(): ",
           iscntrl('\n') ? "Newline is a " : "Newline is not a ", "control character");

    printf("%s\n%s%s\n\n", "isgraph(): ",
           isgraph(character) ? "Character is a " : "Character is not a ", "printing character other than a space");

    printf("%s\n%s%s\n\n", "isprint(): ",
           isprint(character) ? "Character is a " : "Character is not a ", "printing character");

    return 0;

}
