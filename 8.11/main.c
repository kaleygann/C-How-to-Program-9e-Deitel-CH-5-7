/* 8.11
 (Random Sentences) Use random-number generation to create sentences. Your
program should use four arrays of pointers to char called article, noun, verb and
preposition. Create a sentence by selecting a word at random from each array in the
following order: article, noun, verb, preposition, article and noun. The arrays
should be filled as follows: The article array should contain the articles "the", "a",
"one", "some" and "any"; the noun array should contain the nouns "boy", "girl",
"dog", "town" and "car"; the verb array should contain the verbs "drove", "jumped",
"ran", "walked" and "skipped"; the preposition array should contain the prepositions
 "to", "from", "over", "under" and "on". As each word is picked, concatenate it to the
 previous words in an array large enough to hold the entire sentence. Separate the words
 by spaces. The final sentence should start with a capital letter and end with a period.
 Generate 20 such sentences. Modify your program to produce a short story consisting of
 several of these sentences. (How about the possibility of a random term-paper writer?) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

// function prototypes
void createSentence(char *article[6], char *noun[6], char *preposition[6],
                    char *verb[6], char *sentence[100]);
void addConjunctions(char sentence[100]);
void printSentence(char *article[6], char *noun[6], char *preposition[6],
                   char *verb[6], char *sentence[100]);


int main() {

    // seed random-number generator
    srand(time(0));

    // initialize article, noun, preposition, and verb arrays
    char *article[6] = {"the", "a", "one", "some", "any", "\0"};
    const char *noun[6] = {"boy", "girl", "dog", "town", "car", "\0"};
    const char *preposition[6] = {"to", "from", "over", "under", "on", "\0"};
    const char *verb[6] = {"drove", "jumped", "ran", "walked", "skipped", "\0"};

    // initialize sentence array
    char sentence[100] = {};

    // display sentences
    printSentence(article, (char **) noun, (char **) preposition, (char **) verb, (char **) sentence);

    return 0;
}

// function to generate the standard sentence
void createSentence(char *article[6], char *noun[6], char *preposition[6],
                    char *verb[6], char *sentence[100]) {

    // array to store the first capitalized article
    char article1[6];

    // copy the article to the capitalized article array
    // capitalize the first letter of the article
    strcpy(article1, article[rand() % 5]);
    article1[0] = toupper(article1[0]);

    // concatenate each word and spaces in the sentence
    strcpy((char *) sentence, article1);
    strcat((char *) sentence, " ");
    strcat((char *) sentence, noun[rand() % 5]);
    strcat((char *) sentence, " ");
    strcat((char *) sentence, verb[rand() % 5]);
    strcat((char *) sentence, " ");
    strcat((char *) sentence, preposition[rand() % 5]);
    strcat((char *) sentence, " ");
    strcat((char *) sentence, article[rand() % 5]);
    strcat((char *) sentence, " ");
    strcat((char *) sentence, noun[rand() % 5]);
    strcat((char *) sentence, ".");
}

// function to add conjunctions to sentences
void addConjunctions(char sentence[100]) {

    char sentence2[100];
    strcpy(sentence2, sentence);
    sentence2[0] = tolower(sentence2[0]);

    // randomly choose a conjunction
    int choice = rand() % 4;

    // print conjunctions in sentences
    if (choice == 0) {
        printf("Then, %s ", sentence2);
    } else if (choice == 1) {
        printf("So, %s ", sentence2);
    } else if (choice == 2) {
        printf("Additionally, %s ", sentence2);
    } else if (choice == 3) {
        printf("Meanwhile, %s ", sentence2);
    }
}

// function to display all sentences
void printSentence(char *article[6], char *noun[6], char *preposition[6],
                   char *verb[6], char *sentence[100]) {
    for (int i = 0; i < 20; ++i) {

        // generate random sentence
        createSentence(article, noun, preposition, verb, sentence);

        // manipulate every few sentences by adding conjunctions
        if (i % 3 == 1) {
            addConjunctions((char *) sentence);
        }
        // print a normal sentence
        else {
            printf("%s ", sentence);
        }
    }
}

