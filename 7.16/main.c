/* 7.16
 * This program will modify Fig 7.16 by creating a high-performance shuffling algorithm
 * that avoids indefinite postponement. The shuffle function will loop row-by-row and column-by-column
 * through the array, touching every element once. Each element will be swapped with a randomly selected
 * element of the array. Printing the resulting array will show a satisfactory shuffle. */

// fig07_16.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// global variables
#define SUITS 4
#define FACES 13
#define CARDS 52

// function prototypes
void initializeDeck(int deck[][FACES]);
void shuffle(int deck[][FACES]);
void deal(int deck[][FACES], const char *face[], const char *suit[]);
void swap(int *card1, int *card2);
void printDeck(int deck[][FACES]);

int main(void) {

    // initialize deck array
    int deck[SUITS][FACES] = {0};

    srand(time(NULL)); // seed random-number generator

    // initialize suit array
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    // initialize face array
    const char *face[FACES] = {"Ace", "Deuce", "Three", "Four", "Five",
                               "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    initializeDeck(deck);  // initialize the deck to be in order

    printf("\nUnshuffled array:\n\n  ");
    printDeck(deck);  // print unshuffled array

    shuffle(deck); // shuffle the deck

    printf("\n\nShuffled array:\n\n");
    printDeck(deck);  // print shuffled array

    deal(deck, face, suit); // deal the deck

    return 0;
}


// function to initialize deck for cards to be in order 1 - 52
void initializeDeck(int deck[][FACES]) {

    // variable to store card number
    int card = 1;
    // loop through each row and column, setting each element to the card number
    for (size_t row = 0; row < SUITS; ++row) {
        for (size_t column = 0; column < FACES; ++column) {
            deck[row][column] = card++;  // increment card number
        }
    }
}

// function to shuffle cards in deck
void shuffle(int deck[][FACES]) {

    // variable to store total number of cards
    size_t cards = SUITS * FACES;

    // use Fisher-Yates shuffling algorithm
    for (size_t i = cards - 1; i > 0; --i) {
        size_t j = rand() % (i + 1);  // generate random index between 0 and i

        // swap cards
        swap(&deck[i / FACES][i % FACES], &deck[j / FACES][j % FACES]);
    }
}

// swap values at memory locations to which
// card1 and card2 point
void swap(int *card1, int *card2) {
    int temp = *card1;
    *card1 = *card2;
    *card2 = temp;
}

// deal cards in deck
void deal(int deck[][FACES], const char *face[], const char *suit[]) {
    printf("\n");
    for (size_t card = 1; card <= CARDS; ++card) {
        // loop through rows of deck
        for (size_t row = 0; row < SUITS; ++row) {
            // loop through columns of deck for current row
            for (size_t column = 0; column < FACES; ++column) {
                // if slot contains current card, display card
                if (deck[row][column] == card) {
                printf("%5s of %-8s  %c", face[column], suit[row],
                       card % 4 == 0 ? '\n' : '\0'); // 2-column format}
                       break;
                }
            }
        }
    }
}

// function to display entire array
void printDeck(int deck[][FACES]) {

    for (size_t column = 0; column < FACES; ++column) {
        printf("%5zu", column);
    }
    for (size_t row = 0; row < SUITS; ++row) {
        printf("\n\n%-2zu", row);
        for (size_t column = 0; column < FACES; ++column) {
            printf("%5d", deck[row][column]);
        }
        printf("");
    }
    printf("\n\n");
}

