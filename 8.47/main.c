/*
 * 8.47
 * RSA Public-Key Cryptography
 * Assume you have a public key (e, n) and ciphertext that was encrypted
 * using that key with your small-scale RSA implementation, but you do not
 * know the private key required to decrypt the ciphertext. Use brute-force
 * computing techniques to find n’s prime factors p and q. Then, do the
 * calculations necessary to recover d and decrypt the message.
 */

#include <stdio.h>
#include <math.h>

// function prototypes
long long int modularPow(long long int m, long long int e, long long int n);
long long int find_private_key(long long int e, long long int tot);
void decrypt(long long int ciphertext, long long int d, long long int n);

int main() {
    long long int n, e, ciphertext;

    // read public key (e, n) and ciphertext
    printf("Enter the value of n: ");
    scanf_s("%lld", &n);

    printf("Enter the value of e: ");
    scanf_s("%lld", &e);

    printf("Enter the ciphertext: ");
    scanf_s("%lld", &ciphertext);

    // factorize n to find p and q
    long long int p, q = 0;

    for (long long int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            p = i;
            q = n / i;
            break;
        }
    }
    // if n cannot be factorized
    if (p == 0 || q == 0) {
        printf("Failed to factorize n.\n");
        return -1;
    }

    // print factors if found
    printf("\nFactors found: p = %lld, q = %lld\n", p, q);

    // calculate totient function
    long long int tot = (p - 1) * (q - 1);
    printf("Totient: %lld\n", tot);

    // find the private key d
    long long int d = find_private_key(e, tot);
    printf("Private key d: %lld\n", d);

    // decrypt the message
    decrypt(ciphertext, d, n);

    return 0;
}

// function to perform modular exponentiation
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

// function to find the private key d
long long int find_private_key(long long int e, long long int tot) {
    long long int d = 1;
    while ((d * e) % tot != 1) {
        d++;
    }
    return d;
}

// function to decrypt the message
void decrypt(long long int ciphertext, long long int d, long long int n) {
    long long int decryptedMessage = modularPow(ciphertext, d, n);
    printf("Decrypted message: %lld\n", decryptedMessage);
}
