
#include <stdio.h>
#include <string.h>

// Function for modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

// Function to calculate modular inverse (for finding d)
long long modInverse(long long e, long long phi) {
    long long d, k = 1;
    while (1) {
        d = (1 + (k * phi)) / e;
        if (((d * e) % phi) == 1)
            return d;
        k++;
    }
}

int main() {
    long long p, q, n, phi, e, d;
    char msg[100];
    long long i, ascii_sum = 0;
    long long sign, verify;

    // Step 1: Input two primes
    printf("Enter two prime numbers (p and q): ");
    scanf("%lld %lld", &p, &q);

    n = p * q;
    phi = (p - 1) * (q - 1);

    // Step 2: Public key exponent
    printf("Enter public key exponent (e): ");
    scanf("%lld", &e);

    // Step 3: Compute private key
    d = modInverse(e, phi);

    printf("\nPublic Key (e, n): (%lld, %lld)", e, n);
    printf("\nPrivate Key (d, n): (%lld, %lld)\n", d, n);

    // Step 4: Input message string
    printf("\nEnter message to sign: ");
    scanf(" %[^\n]", msg); // read string with spaces

    // Step 5: Convert string to a number (simple hash = sum of ASCII values)
    for (i = 0; i < strlen(msg); i++) {
        ascii_sum += msg[i];
    }

    printf("Message converted to number (sum of ASCII): %lld\n", ascii_sum);

    // Step 6: Sign the message using private key
    sign = modExp(ascii_sum, d, n);
    printf("Generated Digital Signature: %lld\n", sign);

    // Step 7: Verify signature using public key
    verify = modExp(sign, e, n);
    printf("Verified Message Value: %lld\n", verify);

    if (verify == ascii_sum)
        printf("\n✅ Signature Verified Successfully!\n");
    else
        printf("\n❌ Signature Verification Failed!\n");

    return 0;
}