/* 8.42
 * (Pqyoaf X Nylfomigrob: Cuzqvbpcxo vlk Adzdujcjjl) No doubt, you noticed
 * the section title above and this exercise’s title both look like gibberish.
 * This is not a mistake! In this exercise, we continue our focus on security by
 * introducing cryptography. You’ll create functions that implement a Vigenère
 * secret-key cipher. After encrypting and decrypting your own text, you can use
 * your decrypt function with our secret key to decrypt the encrypted titles above.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "cipher.h"

// set row and column sizes
#define ROW 26
#define COL 26

int main() {

    /* arrays to store plain text, cipher text,
     decrypted text, and secret key */
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
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}

// function to check that key only contains letters
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

    static const char vigenereSquare[ROW][COL] = {
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ","BCDEFGHIJKLMNOPQRSTUVWXYZA",
            "CDEFGHIJKLMNOPQRSTUVWXYZAB","DEFGHIJKLMNOPQRSTUVWXYZABC",
            "EFGHIJKLMNOPQRSTUVWXYZABCD","FGHIJKLMNOPQRSTUVWXYZABCDE",
            "GHIJKLMNOPQRSTUVWXYZABCDEF","HIJKLMNOPQRSTUVWXYZABCDEFG",
            "IJKLMNOPQRSTUVWXYZABCDEFGH","JKLMNOPQRSTUVWXYZABCDEFGHI",
            "KLMNOPQRSTUVWXYZABCDEFGHIJ","LMNOPQRSTUVWXYZABCDEFGHIJK",
            "MNOPQRSTUVWXYZABCDEFGHIJKL","NOPQRSTUVWXYZABCDEFGHIJKLM",
            "OPQRSTUVWXYZABCDEFGHIJKLMN","PQRSTUVWXYZABCDEFGHIJKLMNO",
            "QRSTUVWXYZABCDEFGHIJKLMNOP","RSTUVWXYZABCDEFGHIJKLMNOPQ",
            "STUVWXYZABCDEFGHIJKLMNOPQR","TUVWXYZABCDEFGHIJKLMNOPQRS",
            "UVWXYZABCDEFGHIJKLMNOPQRST","VWXYZABCDEFGHIJKLMNOPQRSTU",
            "WXYZABCDEFGHIJKLMNOPQRSTUV","XYZABCDEFGHIJKLMNOPQRSTUVW",
            "YZABCDEFGHIJKLMNOPQRSTUVWX","ZABCDEFGHIJKLMNOPQRSTUVWXY"
    };

    // convert key and input characters to uppercase
    keyChar = toupper(keyChar);
    inputChar = toupper(inputChar);

    /* find row that matches key character and
     column that matches input character */
    int row = keyChar - 'A';
    int col = 0;

    while (vigenereSquare[0][col] != inputChar)
        col++;

    // perform encrypted if encrypt returns true
    if (encrypt) {
        return vigenereSquare[row][col]; }

    // find the plain text character in the row
    else {
        for (int i = 0; i < COL; i++) {
            if (vigenereSquare[row][i] == inputChar)
                return vigenereSquare[0][i];
        }
    }
    // leave the input character unchanged if not found in square
    return inputChar;
}

// function to encrypt plain text using Vigenere cipher
void encrypt(const char *plaintext, char *encrypted, const char *secretKey) {

    checkKey(secretKey);

    // set key length
    int keyLength = strlen(secretKey);
    int index = 0;

    // iterate through plain text characters
    for (int i = 0; plaintext[i] != '\0'; ++i) {
        if (isalpha(plaintext[i])) {
            encrypted[index++] = getSubstitution(secretKey[index % keyLength], plaintext[i], true);
        }
        else {
            encrypted[index++] = plaintext[i];
        }
    }
    // set to terminating null character
    encrypted[index] = '\0';
}

// function to decrypt cipher text using Vigenere cipher
void decrypt(const char *ciphertext, char *decrypted, const char *secretKey) {

    checkKey(secretKey);

    // set key length
    int keyLength = strlen(secretKey);

    // indices to track position in cipher text and key
    int index = 0;
    int keyIndex = 0;

    // iterate through length of cipher text
    for (int i = 0; ciphertext[i] != '\0'; ++i) {
        if ((ciphertext[i])) {
            decrypted[index++] = getSubstitution(secretKey[keyIndex % keyLength], ciphertext[i], false);
            keyIndex = (keyIndex + 1) % keyLength; // update key index
        }
        else {
            decrypted[index++] = ciphertext[i];
        }
    }
    // set to terminating null character
    decrypted[index] = '\0';
}






