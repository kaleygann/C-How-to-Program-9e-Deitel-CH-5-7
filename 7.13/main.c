/* 7.13
 * This program will modify the program in 7.12 to deal
 * two hands then compare the hands. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HAND_SIZE 5
#define SUITS 4
#define FACES 13
#define CARDS 52

// function prototypes
void shuffle(int deck[][FACES]);
void deal(int deck[][FACES], const char *face[], const char *suit[], char *faces1[], char *suits1[], char *faces2[], char *suits2[]);
int compareHands(char *faces1[], char *faces2[], char *suits1[], char *suits2[], int (*evaluate)(char *faces[], char *suits[]));
int evaluateHand(char *faces[], char *suits[]);
int pair(char *faces[]);
int twoPairs(char *faces[]);
int threeKind(char *faces[]);
int fourKind(char *faces[]);
int flush(char *suits[]);
int straight(char *faces[]);


int main(void) {
    // initialize deck array
    int deck[SUITS][FACES] = {0};

    // pointer arrays to store each hand's faces and suits
    char *faces1[5] = {};
    char *suits1[5] = {};
    char *faces2[5] = {};
    char *suits2[5] = {};

    srand(time(NULL)); // seed random-number generator
    shuffle(deck); // shuffle the deck

    // initialize suit array
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    // initialize face array
    const char *face[FACES] = {"Ace", "Deuce", "Three", "Four", "Five",
                               "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    deal(deck, face, suit, faces1, suits1, faces2, suits2); // deal and compare the deck

    if (compareHands(faces1, faces2, suits1, suits2, evaluateHand) == 1) {
        printf("\nPlayer 1 wins!");
    }
    else if (compareHands(faces1, faces2, suits1, suits2, evaluateHand) == 2) {
        printf("\nPlayer 2 wins!");
    }
    else
        printf("\nIt's a draw!");

}  // end main

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

// deal function to deal each hand
void deal(int deck[][FACES], const char *face[], const char *suit[], char *faces1[], char *suits1[], char *faces2[],
          char *suits2[]) {

    // loop for two hands
    for (size_t hand = 0; hand < 2; ++hand) {
        printf("\nHand %zu:\n", hand + 1);  // header for each hand
        for (size_t card = 1; card <= 5; ++card) {
            // loop through rows of deck
            for (size_t row = 0; row < SUITS; ++row) {
                // loop through columns of deck
                for (size_t column = 0; column < FACES; ++column) {
                    // if slot contains current card, display card
                    if (deck[row][column] == card + 5 * hand) {  // adjust card number for hands
                        if (hand == 0) {  // first hand
                            faces1[card - 1] = face[column];
                            suits1[card - 1] = suit[row];
                            printf("%s of %s  ", faces1[card - 1], suits1[card - 1]);  // display hand
                        }
                        else  {  // second hand
                            faces2[card - 1] = face[column];
                            suits2[card - 1] = suit[row];
                            printf("%s of %s  ", faces2[card - 1], suits2[card - 1]);  // display hand
                        }
                    }
                }
            }
        }
        printf("\n");
    }
}

// function tha evaluates the hand
int evaluateHand(char *faces[], char *suits[]) {

    if (straight(faces) && flush(suits)) {  // return 6 points if straight flush (royal flush?)
        return 6;
    }
    else if (flush(suits)) {  // return 5 points if flush
        return 5;
    }
    else if (fourKind(faces)) {  // return 4 points if 4 of a kind
        return 4;
    }
    else if (threeKind(faces)) {  // return three points if three of a kind
        return 3;
    }
    else if (twoPairs(faces)) {  // return 2 points if 2 pairs
        return 2;
    }
    else if (pair(faces)) {  // return 1 point if 1 pair
        return 1;
    }
    return 0;  // return 0 points if none of the above is found in hand
}

// function to compare the two hands
// uses a pointer to the evaluateHand function
int compareHands(char *faces1[], char *faces2[], char *suits1[], char *suits2[], int (*evaluate)(char *faces[], char *suits[])) {

    // if Hand 1 has higher points than Hand 2
    if ((*evaluate)(faces1, suits1) > (*evaluate)(faces2, suits2))  {
        return 1;
    }
    // if Hand 2 has more points than Hand 1
    else if ((*evaluate)(faces1, suits1) < (*evaluate)(faces2, suits2)) {
        return 2;
    }
    else  // if there is a tie
        return 0;
}

// function to check if hand contains a pair
int pair(char *faces[]) {

    // for loop to iterate through hand and compare faces
    for (size_t i = 0; i < HAND_SIZE - 1; ++i) {
        for (size_t j = i + 1; j < HAND_SIZE; ++j) {
            // see if two cards are equal to each other
            if (faces[i] == faces[j]) {
                return 1;  // return true if pair is found
            }
        }
    }
    return 0;
}

// function to check if hand has two pairs
int twoPairs(char *faces[]) {

    // array to keep track of pairs
    char pairedValues[HAND_SIZE] = {0};

    // pairs counter to count instances of duplicates
    int count = 0;

    // for loop to iterate through hand and compare faces
    for (size_t i = 0; i < HAND_SIZE; ++i) {
        for (size_t j = i + 1; j < HAND_SIZE; ++j) {
            if (faces[i] == faces[j] && !pairedValues[i]) {

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
int threeKind(char *faces[]) {

    // variable to count duplicates
    int count = 0;

    // for loop to iterate through hand and compare faces
    for (size_t i = 0; i < HAND_SIZE - 1; ++i) {
        for (size_t j = i + 1; j < HAND_SIZE; ++j) {
            // compare the face values
            if (faces[i] == faces[j]) {
                count++;  // increment count if duplicate is found
            }
        }
        if (count >= 3) {  // if count at least 3, return true
            return 1;
        }
    }
    return 0;
}

// function to check if hand has four of a kind
int fourKind(char *faces[]) {

    // variable to count duplicates
    int count = 0;

    // for loop to iterate through hand and compare faces
    for (size_t i = 0; i < HAND_SIZE - 1; ++i) {
        for (size_t j = i + 1; j < HAND_SIZE; ++j) {
            // compare the face values
            if (faces[i] == faces[j]) {
                count++;  // increment count if duplicate is found
            }
        }
        if (count == 4) {  // if count is 4, return true
            return 1;
        }
    }
    return 0;
}

// function to check if hand has flush (all 5 the same suit)
int flush(char *suits[]) {

    // variable to count duplicates
    int count = 0;

    // iterate through hand and compare suits
    for (size_t i = 0; i < HAND_SIZE; ++i) {
        if (suits[i] == suits[0]) {
            count++;  // increment count when duplicate is found
        }
        if (count == 5) {  // when 5 of a kind is found, return true
            return 1;
        }
    }
    return 0;
}

// function to check if hand has 5 cards that are consecutive face values (straight)
int straight(char *faces[]) {

    // loop through hand to check for consecutive cards
    for (size_t i = 0; i < HAND_SIZE - 1; ++i) {
        for (size_t j = i + 1; j < HAND_SIZE; ++j) {
            if (faces[i][0] > faces[j][0]) {
                // store greater value in temp variable
                char *temp = faces[i];
                // swap values to sort cards
                faces[i] = faces[j];
                faces[j] = temp;
            }
        }
        for (size_t i = 0; i < HAND_SIZE - 1; ++i) {
            // if the difference between each sorted face is not 1, cards are consecutive (return false)
            if (faces[i + 1][0] - faces[i][0] != 1) {
                return 0;
            }
        }
    }
    return 1;  // return true if cards are consecutive
}

