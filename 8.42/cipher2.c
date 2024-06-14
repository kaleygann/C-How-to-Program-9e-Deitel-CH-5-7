/* 8.42
 * (Vigenère Cipher Modification—Supporting All ASCII Characters) Your
 * Vigenère cipher implementation from Exercise 8.41 encrypts and decrypts
 * only the letters A–Z. All other characters simply pass through as is.
 * Modify your implementation to support the complete ASCII character set
 * shown in Appendix B.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "cipher.h"

// set ASCII range size
#define RANGE 128

int main() {

    // arrays to store plain text, cipher text,
    // decrypted text, and secret key
    char plaintext[100] = {};
    char ciphertext[100];
    char decryptedtext[100];
    const char secretKey[] = "XMWUJBVYHXZ";

    // prompt user to enter line of text
    printf("Enter line of text: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // encrypt plain text then print cipher text
    encrypt(plaintext, ciphertext, secretKey);
    printf("\nEncrypted text: %s", ciphertext);

    // decrypt cipher text then print original plain text
    decrypt(ciphertext, decryptedtext, secretKey);
    printf("\nDecrypted text: %s\n", decryptedtext);

    return 0;
}

// function to generate ASCII characters
void generateVigenereSquare(char vigenereSquare[RANGE][RANGE]) {
    for (int i = 0; i < RANGE; i++) {
        for (int j = 0; j < RANGE; j++) {
            vigenereSquare[i][j] = (char)((i + j) % RANGE);
        }
    }
}

// function to check that the key only contains letters
bool checkKey(const char *secretKey) {
    while (*secretKey) {
        if (!isalpha(*secretKey))
            return false;
        secretKey++;
    }
    return true;
}

// function to get substitution character for Vigenere cipher
char getSubstitution(char keyChar, char inputChar, bool encrypt) {

    char vigenereSquare[RANGE][RANGE];
    generateVigenereSquare(vigenereSquare);

    int key = keyChar % RANGE;
    int input = inputChar % RANGE;
    int result;

    // if encrypted
    if (encrypt) {
        result = vigenereSquare[key][input];
    }
    // if decrypting
    else {
        for (int i = 0; i < RANGE; i++) {
            if (vigenereSquare[key][i] == input) {
                result = i;
                break;
            }
        }
    }
    return (char)result;
}

// function encrypt plaintext
void encrypt(const char *plaintext, char *encrypted, const char *secretKey) {

    checkKey(secretKey);  // check that secret key is valid

    int keyLength = strlen(secretKey);
    int index = 0;

    // replace plaintext characters with encrypted characters
    for (int i = 0; plaintext[i] != '\0'; ++i) {
        encrypted[index] = getSubstitution(secretKey[index % keyLength], plaintext[i], true);
        index++;
    }
    encrypted[index] = '\0';  // null-terminate encrypted message
}

// function to decrypt encrypted message
void decrypt(const char *ciphertext, char *decrypted, const char *secretKey) {

    checkKey(secretKey);  // check that secret key is valid

    int keyLength = strlen(secretKey);
    int index = 0;

    // replace encrypted characters with original plaintext characters
    for (int i = 0; ciphertext[i] != '\0'; ++i) {
        decrypted[index] = getSubstitution(secretKey[index % keyLength], ciphertext[i], false);
        index++;
    }
    decrypted[index] = '\0';  // null-terminate decrypted message
}






