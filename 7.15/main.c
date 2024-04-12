/* 7.15
 * This program will modify program developed in Exercise 7.14 so that it can handle the dealer’s
hand automatically, but the player is allowed to decide which cards of the player’s
hand to replace. The program should then evaluate both hands and determine who
wins.  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// global variables
#define HAND_SIZE 5
#define SUITS 4
#define FACES 13
#define CARDS 52
#define MAX_DRAW 3

// function prototypes
void shuffle(int deck[][FACES]);
void deal(int deck[][FACES], const char *face[], const char *suit[], char *faces1[], char *suits1[], char *faces2[], char *suits2[]);
int compareHands(char *faces1[], char *faces2[], char *suits1[], char *suits2[]);
int evaluateHand(char *faces[], char *suits[]);
int pair(char *faces[], char *suits[]);
int twoPairs(char *faces[]);
int threeKind(char *faces[], char *suits[]);
int fourKind(char *faces[]);
int flush(char *suits[]);
void replaceFirstLast(char *face[], char *suit[], char *side1[], char *side2[]);
int straight(char *faces[]);
void printHand(char *faces[], char *suits[]);
void displayWinner(char *faces1[], char *faces2[], char *suits1[], char *suits2[]);
void drawCards(char *face[], char *suit[], char *faces[], char *suits[]);
void drawPlayerCards(char *face[], char *suit[], char *faces[], char *suits[], int cards);
void sortHand(char *faces[], char *suits[]);
void playPoker(int deck[][FACES], char *face[], char *suit[], char *faces1[], char *faces2[],
               char *suits1[], char *suits2[]);

int main(void) {

    // initialize deck array
    int deck[SUITS][FACES] = {0};

    // initialize suit array
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    // initialize face array
    const char *face[FACES] = {"Ace", "Deuce", "Three", "Four", "Five",
                               "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    // pointers to store each hand's faces and suits
    char *faces1[HAND_SIZE] = {};
    char *suits1[HAND_SIZE] = {};
    char *faces2[HAND_SIZE] = {};
    char *suits2[HAND_SIZE] = {};


    srand(time(NULL)); // seed random-number generator

    shuffle(deck);  // shuffle deck

    playPoker(deck, face, suit, faces1, faces2, suits1, suits2);  // play game

    displayWinner(faces1, faces2, suits1, suits2);  // display winners

    return 0;

}  // end main

// function that calls all the functions needed to play poker
void playPoker(int deck[][FACES], char *face[], char *suit[], char *faces1[], char *faces2[],
               char *suits1[], char *suits2[]) {

    // store number of cards to draw
    int cards = 0;

    // display dealer's hand face down
    printf("\nDealer's hand: ");
    deal(deck, face, suit, faces1, suits1, faces2, suits2);

    // sort both hands in ascending order
    sortHand(faces1, suits1);
    sortHand(faces2, suits2);

    // allow dealer to draw cards
    drawCards(face, suit, faces2, suits2);

    // show player's hand
    printf("\nPlayer's hand: \n");
    printHand(faces1, suits1);

    // ask player how many cards they want to draw
    printf("\nNumber of cards to draw (between 0 and 3): \n");
    scanf_s("%d", &cards);

    // allow player to draw cards
    drawPlayerCards(face, suit, faces1, suits1, cards);

    // display final hands
    printf("\nPlayer's hand: \n");
    printHand(faces1, suits1);

    printf("\nDealer's hand: \n");
    printHand(faces2, suits2);
}

void drawPlayerCards(char *face[], char *suit[], char *faces[], char *suits[], int cards) {

    // loop through number of cards player wants to replace
    for (int i = 1; i <= cards; ++i) {
        int replace = 0;
        printf("\nEnter number of card to replace (1 - 5): ");
        scanf_s("%d", &replace);

        // replace cards
        switch(replace) {
            case 1:
                faces[0] = face[rand() % FACES];
                suits[0] = suit[rand() % SUITS];
                break;
            case 2:
                faces[1] = face[rand() % FACES];
                suits[1] = suit[rand() % SUITS];
                break;
            case 3:
                faces[2] = face[rand() % FACES];
                suits[2] = suit[rand() % SUITS];
                break;
            case 4:
                faces[3] = face[rand() % FACES];
                suits[3] = suit[rand() % SUITS];
                break;
            case 5:
                faces[4] = face[rand() % FACES];
                suits[4] = suit[rand() % SUITS];
                break;
        }
    }
    sortHand(faces, suits);  // sort hand again
}

// function to shuffle cards in deck
void shuffle(int deck[][FACES]) {

    // for each card, choose slot of deck randomly
    for (size_t card = 1; card <= CARDS; ++card) {
        size_t row = 0; // row number
        size_t column = 0; // column number

        // choose new random location until unoccupied slot found
        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while(deck[row][column] != 0);

        deck[row][column] = card; // place card in chosen slot
    }
}

// function to deal each hand
void deal(int deck[][FACES], const char *face[], const char *suit[], char *faces1[], char *suits1[], char *faces2[], char *suits2[]) {

    // loop for two hands
    for (size_t hand = 0; hand < 2; ++hand) {
        // loop to deal cards
        for (size_t card = 1; card <= HAND_SIZE; ++card) {
            // loop through rows of deck
            for (size_t row = 0; row < SUITS; ++row) {
                // loop through columns of deck
                for (size_t column = 0; column < FACES; ++column) {
                    // if slot contains current card, display card
                    if (deck[row][column] == card + HAND_SIZE * hand) {
                        if (hand == 0) {  // first hand
                            faces1[card - 1] = face[column];
                            suits1[card - 1] = suit[row];
                        }
                        else {  // second hand face down
                            faces2[card - 1] = face[column];
                            suits2[card - 1] = suit[row];
                            printf("Face Down  ");
                        }
                    }
                }
            }
        }
        printf("\n");
    }
}

// function to swap values
void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// function to sort hand in ascending order
void sortHand(char *faces[], char *suits[]) {

    // loop through hand and swap cards
    for (size_t i = 0; i < HAND_SIZE - 1; ++i) {
        for (size_t j = i + 1; j < HAND_SIZE; ++j) {
            if (faces[i] > faces[j]) {
                swap(&faces[i], &faces[j]);
                swap(&suits[i], &suits[j]);

            }
        }
    }
}

// function to evaluate the hand
int evaluateHand(char *faces[], char *suits[]) {

    // variable to store hand quality
    int quality = 0;

    if (straight(faces) == 1 && flush(suits) == 1) {  // quality = 7 if straight flush
        quality = 7;
    }
    else if (flush(suits) == 1) {  // quality = 6 if flush
        quality = 6;
    }
    else if (straight(faces) == 1) { // quality = 5 if straight
        quality = 5;
    }
    else if (fourKind(faces)) {  // quality = 4 if four of a kind
        quality = 4;
    }
    else if (threeKind(faces, suits)) {  // quality = 3 if three of a kind
        quality = 3;
    }
    else if (twoPairs(faces)) {  // quality = 2 if two pairs
        quality = 2;
    }
    else if (pair(faces, suits)) {  // quality = 1 if one pair
        quality = 1;
    }

    return quality;  // return value
}

// function replace either first or last card in hand
void replaceFirstLast(char *face[], char *suit[], char *side1[], char *side2[]) {

    // replace first card
    if (side1[1] != side1[0]) {
        side1[0] = face[rand() & FACES];
        side2[0] = suit[rand() % SUITS];
    }
    // replace last card
    else if (side1[HAND_SIZE - 1] != side1[HAND_SIZE - 2]) {
        side1[HAND_SIZE - 1] = face[rand() % FACES];
        side2[HAND_SIZE - 1] = suit[rand() % SUITS];
    }
}

// function to draw cards
void drawCards(char *face[], char *suit[], char *faces[], char *suits[]) {
    // variable to store number of cards to draw
    // set to 0 (when 4 of a kind, draw 0)
    int cards = 0;

    // if almost flush or almost straight replace either first or last card
    if (flush(suits) == 2 || straight(faces) == 2) {
        replaceFirstLast(face, suit, suits, faces);

    }
    else {
        if (twoPairs(faces)) {  // draw one card if two pairs
            cards = 1;
        }
        else if (threeKind(faces, suits)) {  // draw 2 cards if three of a kind
            cards = 2;
        }
        else if (pair(faces, suits) || !pair(faces, suits)) {  // draw three cards if pair or no pair
            cards = 3;
        }
        // replace card(s) with random card(s) from deck
        for (size_t i = 0; i < cards; ++i) {
            faces[i] = face[rand() % FACES];
            suits[i] = suit[rand() % SUITS];
        }
    }

    sortHand(faces, suits);  // sort hand again
}


// function to compare the two hands
int compareHands(char *faces1[], char *faces2[], char *suits1[], char *suits2[]) {

    // store values from evaluateHand in variables result1 and result 2
    int result1 = evaluateHand(faces1, suits1);
    int result2 = evaluateHand(faces2, suits2);

    // if player hand ranks higher, return 1
    if (result1 > result2) {
        return 1;
    }
        // if dealer hand ranks higher, return 2
    else if (result1 < result2) {
        return 2;
    }
    // if there is a draw, return 0
    return 0;
}

// function to print final hands
void printHand(char *faces[], char *suits[]) {
    for (int i = 0; i < HAND_SIZE; ++i) {
        printf("%s of %s  ", faces[i], suits[i]);
    }
    printf("\n");
}

// function to determine and display winner
void displayWinner(char *faces1[], char *faces2[], char *suits1[], char *suits2[]) {

    // compare hands - store result in winner variable
    int winner = compareHands(faces1, faces2, suits1, suits2);

    // display who won
    if (winner == 1) {
        printf("\nPlayer 1 wins!");
    }
    else if (winner == 2) {
        printf("\nDealer wins!");
    }
    else {
        printf("\nIt's a draw!");
    }
}
// function to check if hand contains a pair
int pair(char *faces[], char *suits[]) {
    int count = 0;
    // iterate through hand and compare faces
    for (size_t i = 0; i < HAND_SIZE - 1; ++i) {
        for (size_t j = i + 1; j < HAND_SIZE; ++j) {
            // if two cards are equal to each other, return true
            if (faces[i] == faces[j]) {
                // place duplicates at end of hand
                swap(&faces[i], &faces[HAND_SIZE - 1]);
                swap(&faces[j], &faces[HAND_SIZE - 2]);
                swap(&suits[i], &suits[HAND_SIZE - 1]);
                swap(&suits[j], &suits[HAND_SIZE - 2]);

                count++;  // increment count
            }
            if (count == 1) {
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
            }
            if (count == 2) {
                return 1;  // return true if two pairs have been found
            }
        }
    }
    return 0;
}


// function to check if hand has 3 of a kind
int threeKind(char *faces[],char *suits[]) {

    // variable to count duplicates
    int count = 0;

    // for loop to iterate through hand and compare faces
    for (size_t i = 0; i < HAND_SIZE - 1; ++i) {
        for (size_t j = i + 1; j < HAND_SIZE; ++j) {
            // compare the face values
            if (faces[i] == faces[j]) {
                // place duplicates at end of hand
                swap(&faces[i], &faces[HAND_SIZE - 1]);
                swap(&faces[j], &faces[HAND_SIZE - 2]);
                swap(&suits[i], &suits[HAND_SIZE - 1]);
                swap(&suits[j], &suits[HAND_SIZE - 2]);
                count++;  // increment count if duplicate is found
            }
            if (count == 3) {  // if count at least 3, return true
                return 1;
            }
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
            if (count == 4) {  // if count is 4, return true
                return 1;
            }
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
        if (count == 5) {  // when 5 of the same suit is found, return 1
            return 1;
        }
        else if (count == 4) {  // if 4 of the same suit are found, return 2
            return 2;
        }
    }
    return 0;
}

// function to check if cards are consecutive
int straight(char *faces[]) {

    int count = 1;

    for (size_t i = 0; i < HAND_SIZE - 1; ++i) {
        // check if the current card is one less than the next card
        if (faces[i + 1] - faces[i] == 1) {
            count++;
            if (count == 5) {
                return 1;  // return 1 if straight is found
            }
            if (count == 4) {
                return 2;  // almost straight found (4 consecutive)
            }
        }
    }
    return 0;
}









