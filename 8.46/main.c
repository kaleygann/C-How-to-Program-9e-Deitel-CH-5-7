/*
* 8.46
* RSA Public-Key Cryptography
* Modify your program to show the first five potential values for the
* decryption exponent d (i.e., the first value of d plus 1 * totient,
* the first value of d plus 2 * totient, etc.). Follow your list of
* possibilities with an ellipsis (…).
*
* Modify your code to do all RSA integer calculations using type long long int.
* Note that even that type will be inadequate for holding the enormous integers
* you’d use in industrial quality RSA. It would require special programming
* to use such larger integer values. Remember to change any printf and scanf
* statements’ %d conversion specifiers to %lld.
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

// function prototypes
int isPrime(long long int n);
long long int gcd(long long int num1, long long int num2);
long long int modularPow(long long int m, long long int e, long long int n);
void get_dValues(long long int e, long long int t, long long int dValues[]);
void get_coPrimes(long long int t, long long int coPrimes[]);
long long int encrypt(long long int m, long long int e, long long int n);
long long int decrypt(long long int m, long long int d, long long int n);
void print_encrypted(const char *message, long long int encrypted_message[100], long long int e, long long int n);
void print_decrypted(const char *message, long long int encrypted_message[100], long long int d, long long int n);
long long int get_lcm(long long int num1, long long int num2);

int main() {

    // initialize variables
    long long int p, q, d, e = 0;
    long long int data, cipher, decrypted;

    // arrays to store message and encrypted message
    char message[100];
    long long int encrypted_message[100];

    // check if numbers entered are not prime
    while (1) {
        printf("Enter a prime number for p: ");
        scanf_s("%lld", &p);

        printf("Enter a prime number for q: ");
        scanf_s("%lld", &q);

        if (!(isPrime(p) && isPrime(q))) {
            printf("Both numbers are not prime. Please enter prime numbers only.\n");
        } else {
            break;
        }
    }

    // set n and totient values
    long long int n = p * q;
    long long int lcm = get_lcm((p - 1), (q - 1));

    // array to store co-primes and d-values
    long long int coPrimes[lcm];
    long long int dValues[5]; // Store only the first five d-values

    // print results
    printf("\nn is: %lld", n);
    printf("\nLowest common multiple is: %lld", lcm);

    printf("\n\nCandidates for e: ");
    get_coPrimes(lcm, coPrimes);

    printf("\nSelect a value e from the preceding candidates: ");
    scanf_s("%lld", &e);

    printf("\nCandidates for d: ");
    get_dValues(e, lcm, dValues);

    printf("\nSelect a value for d--either the d candidate above or d plus a multiple of the totient: ");
    scanf_s("%lld", &d);

    printf("\nEnter a non-negative integer less than n to encrypt: ");
    scanf_s("%lld", &data);

    // get cipher text and decrypted plain text
    cipher = encrypt(data, e, n);
    decrypted = decrypt(cipher, d, n);

    // print results
    printf("\nThe ciphertext is: %lld", cipher);
    printf("\nThe decrypted plaintext is: %lld", decrypted);

    printf("\n\nEnter a sentence to encrypt: ");
    scanf(" %[^\n]%*c", message);

    printf("Encrypted message: ");
    print_encrypted(message, encrypted_message, e, n);

    printf("\nThe decrypted plaintext is:\n");
    print_decrypted(message, encrypted_message, d, n);

    return 0;
}

// function to check if a number is prime
int isPrime(long long int num) {
    if (num <= 1) {
        return 0;
    }
    for (long long int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// function to get the greatest common denominator from two values
long long int gcd(long long int num1, long long int num2) {
    while (num2 != 0) {
        long long int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

long long int get_lcm(long long int num1, long long int num2) {
    return (num1 * num2) / gcd(num1, num2);
}

// perform modular exponentiation
long long int modularPow(long long int m, long long int e, long long int n) {
    long long int c = 1;
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
void get_coPrimes(long long int t, long long int coPrimes[]) {
    long long int count = 0;
    for (long long int i = 2; i < t; ++i) {
        if (gcd(i, t) == 1) {
            coPrimes[count] = i;
            printf("%lld ", coPrimes[count]);
            count++;
        }
    }
}

// function to get private key's exponent d (decryption)
void get_dValues(long long int e, long long int t, long long int dValues[]) {
    long long int d = 0;
    for (long long int i = 1; ; ++i) {
        if ((e * i) % t == 1) {
            d = i;
            break;
        }
    }
    for (int i = 0; i < 5; ++i) {
        dValues[i] = d + i * t;
        printf("%lld ", dValues[i]);
    }
    printf("...\n");
}

// function to encrypt message using public key (e, n)
long long int encrypt(long long int m, long long int e, long long int n) {
    return modularPow(m, e, n);
}

// function to decrypt message using public key (d, n)
long long int decrypt(long long int m, long long int d, long long int n) {
    return modularPow(m, d, n);
}

// function to print encrypted plaintext message
void print_encrypted(const char *message, long long int encrypted_message[100], long long int e, long long int n) {
    for (int i = 0; i < strlen(message); ++i) {
        encrypted_message[i] = encrypt((int)message[i], e, n);
        printf("%c", (char)(encrypted_message[i] % 256));
    }
    printf("\n");
}

// function to print decrypted plaintext message
void print_decrypted(const char *message, long long int encrypted_message[100], long long int d, long long int n) {
    long long int decrypted;
    for (int i = 0; i < strlen(message); ++i) {
        decrypted = decrypt(encrypted_message[i], d, n);
        printf("%c", (char)decrypted);
    }
    printf("\n");
}
