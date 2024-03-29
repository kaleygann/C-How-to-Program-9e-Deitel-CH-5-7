
// fig07_16.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HAND_SIZE 5
#define SUITS 4
#define FACES 13
#define CARDS 52

// prototypes
void shuffle(int deck[][FACES]);
void deal(int deck[][FACES], const char *face[], const char *suit[], char hand_faces[], char hand_suits[]);
int pair(const char *hPtr);
int twoPairs(const char *hPtr);
int threeKind(const char *hPtr);
int fourKind(const char *hPtr);


int main(void) {
    // initialize deck array
    int deck[SUITS][FACES] = {0};

    char hand_faces[5];
    char hand_suits[5];

    srand(time(NULL)); // seed random-number generator
    shuffle(deck); // shuffle the deck

    // initialize suit array
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    // initialize face array
    const char *face[FACES] = {"Ace", "Deuce", "Three", "Four", "Five",
                               "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};


    deal(deck, face, suit, hand_faces, hand_suits); // deal the deck

    if (pair(hand_faces)) {
        puts("\nPair found.");
    }
    if (twoPairs(hand_faces)) {
        puts("Two pairs found.");
    }
    if (threeKind(hand_faces)) {
        puts("Three of a kind found.");
    }
    if (fourKind(hand_faces)) {
        puts("Four of a kind found.");
    }

}

// shuffle cards in deck
void shuffle(int deck[][FACES]) {
    // for each of the cards, choose slot of deck randomly
    for (size_t card = 1; card <= CARDS; ++card) {
        size_t row = 0; // row number
        size_t column = 0; // column number

        // choose new random location until unoccupied slot found
        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while(deck[row][column] != 0);

        deck[row][column] = card; // place card number in chosen slot
    }
}

// deal cards in deck
void deal(int deck[][FACES], const char *face[], const char *suit[], char hand_faces[], char hand_suits[]) {
    // deal each of the cards
    for (size_t card = 1; card <= 5; ++card) {
        // loop through rows of deck
        for (size_t row = 0; row < SUITS; ++row) {
            // loop through columns of deck for current row
            for (size_t column = 0; column < FACES; ++column) {
                // if slot contains current card, display card
                if (deck[row][column] == card) {
                    hand_faces[card - 1] = *face[column];
                    hand_suits[card - 1] = *suit[row];
                    printf("%c of %c  ", hand_faces[card - 1], hand_suits[card -1]);
                }
            }
        }
    }
}

// function to check if hand contains a pair
int pair(const char *hPtr) {

    // for loop to iterate through hand and compare faces
    for (size_t i = 0; i < HAND_SIZE; ++i) {
        for (size_t j = i + 1; j < HAND_SIZE; ++j) {

            if (*(hPtr + i) == *(hPtr + j)) {
                return 1;  // return true if pair is found
            }
        }
    }
    return 0;
}

int twoPairs(const char *hPtr) {

    // array to keep track of pairs
    char pairedValues[HAND_SIZE] = {0};

    // pairs counter to count instances of duplicates
    int count = 0;

    // for loop to iterate through hand and compare faces
    for (size_t i = 0; i < HAND_SIZE; ++i) {
        for (size_t j = i + 1; j < HAND_SIZE; ++j) {
            if (*(hPtr + i) == *(hPtr + j) && !pairedValues[i]) {

                pairedValues[i] = 1;  // store 1 if pair value is found
                count++;

                if (count == 2) {  // if count is 2, return true
                    return 1;
                }
            }
        }
    }
    return 0;
}


// function to check if hand has 3 of a kind
int threeKind(const char *hPtr) {

    // variable to count triples
    int count = 0;

    // for loop to iterate through hand and compare faces
    for (size_t i = 0; i < HAND_SIZE - 1; ++i) {
        for (size_t j = i + 1; j < HAND_SIZE; ++j) {
            // Compare the face values in column 0 of each row
            if (*(hPtr + i) == *(hPtr + j)) {
                count++;
            }
        }
        if (count >= 3) {  // if count is 4, return true
            return 1;
        }
    }
    return 0;
}


// function to check if hand has four of a kind
int fourKind(const char *hPtr) {

    // variable to count quads
    int count = 0;

    // for loop to iterate through hand and compare faces
    for (size_t i = 0; i < HAND_SIZE - 1; ++i) {
        for (size_t j = i + 1; j < HAND_SIZE; ++j) {
            // Compare the face values in column 0 of each row
            if (*(hPtr + i) == *(hPtr + j)) {
                count++;
            }
        }
        if (count == 4) {  // if count is 4, return true
            return 1;
        }
    }
    return 0;
}

/*
// function to check if hand has flush (all 5 the same suit)
int flush() {

}

// function to check if hand has 5 cards that are consecutive face values (straight)
int straight() {

} */
