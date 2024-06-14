 /*
 * 8.44
 * RSA Public-Key Cryptography
 * Modify the RSA algorithm in 8.43 to replace totient with
 * lambda of n, which equals lcm((p - 1), (q - 1)), where
 * lcm = least common multiple.
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

// function prototypes
int isPrime(int n);
int gcd(int num1, int num2);
int modularPow(int m, int e, int n);
void get_dValues(int e, int t, int dValues[]);
void get_coPrimes(int t, int coPrimes[]);
int encrypt(int m, int e, int n);
int decrypt(int m, int d, int n);
void print_encrypted(const char *message, int encrypted_message[100], int e, int n);
void print_decrypted(const char *message, int encrypted_message[100], int d, int n);
int get_lcm(int num1, int num2);

int main() {

    // initialize variables
    int p, q, d, e = 0;
    int data, cipher, decrypted;

    // arrays to store message and encrypted message
    char message[100];
    int encrypted_message[100];

    // check if numbers entered are not prime
    while (1) {
        printf("Enter a prime number for p: ");
        scanf_s("%d", &p);

        printf("Enter a prime number for q: ");
        scanf_s("%d", &q);

        if (!(isPrime(p) && isPrime(q))) {
            printf("Both numbers are not prime. Please enter prime numbers only.\n");
        } else {
            break;
        }
    }

    // set n and totient values
    int n = p * q;
    int lcm = get_lcm((p - 1), (q - 1));

    // array to store co-primes and d-values
    int coPrimes[lcm];
    int dValues[lcm];

    // print results
    printf("\nn is: %d", n);
    printf("\nLowest common multiple is: %d", lcm);

    printf("\n\nCandidates for e: ");
    get_coPrimes(lcm, coPrimes);

    printf("\nSelect a value e from the preceding candidates: ");
    scanf_s("%d", &e);

    printf("\nCandidates for d: ");
    get_dValues(e, lcm, dValues);

    printf("\nSelect a value for d--either the d candidate above or d plus a multiple of the totient: ");
    scanf_s("%d", &d);

    printf("\nEnter a non-negative integer less than n to encrypt: ");
    scanf_s("%d", &data);

    // get cipher text and decrypted plain text
    cipher = encrypt(data, e, n);
    decrypted = decrypt(cipher, d, n);

    // print results
    printf("\nThe ciphertext is: %d", cipher);
    printf("\nThe decrypted plaintext is: %d", decrypted);

    printf("\n\nEnter a sentence to encrypt: ");
    scanf(" %[^\n]%*c", message);

    printf("Encrypted message: ");
    print_encrypted(message, encrypted_message, e, n);

    printf("\nThe decrypted plaintext is:\n");
    print_decrypted(message, encrypted_message, d, n);

    return 0;
}

// function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// function to get the greatest common denominator from two values
int gcd(int num1, int num2) {
    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

 int get_lcm(int num1, int num2) {
     return (num1 * num2) / gcd(num1, num2);
 }

// perform modular exponentiation
int modularPow(int m, int e, int n) {
    int c = 1;
    m = m % n;
    while (e > 0) {
        if (e % 2 == 1) {
            c = (c * m) % n;
        }
        e /= 2;
        m = (m * m) % n;
    }
    return c;
}

// function to get co-prime options for public-key exponent e (encryption)
void get_coPrimes(int t, int coPrimes[]) {
    int count = 0;
    for (int i = 2; i < t; ++i) {
        if (gcd(i, t) == 1) {
            coPrimes[count] = i;
            printf("%d ", coPrimes[count]);
            count++;
        }
    }
}

// function to get private key's exponent d (decryption))
void get_dValues(int e, int t, int dValues[]) {
    int count = 0;
    for (int i = 1; i < t; ++i) {
        if ((e * i) % t == 1) {
            dValues[count] = i;
            printf("%d ", dValues[count]);
            count++;
        }
    }
}

// function to encrypt message using public key (e, n)
int encrypt(int m, int e, int n) {
    return modularPow(m, e, n);
}

// function to decrypt message using public key (d, n)
int decrypt(int m, int d, int n) {
    return modularPow(m, d, n);
}

// function to print encrypted plaintext message
void print_encrypted(const char *message, int encrypted_message[100], int e, int n){
    for (int i = 0; i < strlen(message); ++i) {
        encrypted_message[i] = encrypt((int)message[i], e, n);
        printf("%c", (char)(encrypted_message[i] % 256));
    }
    printf("\n");
}

// function to print decrypted plaintext message
void print_decrypted(const char *message, int encrypted_message[100], int d, int n) {
    int decrypted;
    for (int i = 0; i < strlen(message); ++i) {
        decrypted = decrypt(encrypted_message[i], d, n);
        printf("%c", (char)decrypted);
    }
    printf("\n");
}

