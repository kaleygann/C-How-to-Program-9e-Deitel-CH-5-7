/* 8.15
 * (Displaying a Sentence with Its Words Reversed) Write a program that inputs
 * a line of text, tokenizes the line with function strtok and outputs the
 * tokens in reverse order.
 */

#include <stdio.h>
#include <string.h>

#define SIZE 100

// function prototypes
int tokenize(char *sentence[SIZE], char *tokens[SIZE]);
void printReverse(char *tokens[SIZE], int count);

int main() {

    // initialize sentence array, token pointer,
    // tokens pointer array, and count
    char sentence[SIZE];
    char *tokens[SIZE];

    // prompt user to enter a sentence
    printf("Enter a line of text to reverse: ");
    fgets(sentence, sizeof(sentence), stdin);

    // tokenize sentence
    int count = tokenize(sentence, tokens);

    // display sentence in reverse
    printReverse(tokens, count);

    return 0;
}

// function to tokenize the line of text then return the number of tokens
int tokenize(char *sentence[SIZE], char *tokens[SIZE]) {
    int count = 0;
    char *token = strtok(sentence, " ");

    while (token != NULL && count < 100) {
        tokens[count++] = token;
        token = strtok(NULL, " ");
    }
    return count;
}

// function to display the tokens reversed
void printReverse(char *tokens[SIZE], int count) {
    printf("Sentence in reverse order: \n");
    for (int i = count - 1; i >= 0; --i) {
        printf("%s  ", tokens[i]);
    }
}
