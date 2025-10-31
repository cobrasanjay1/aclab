#include <stdio.h>
#include <math.h>

// Function to calculate (base^exp) % mod efficiently
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result = (result * base) % mod;
    }
    return result;
}

int main() {
    long long P, G, a, b, A, B, keyA, keyB;

    printf("---- DIFFIE-HELLMAN KEY EXCHANGE ----\n");

    // Step 1: Input prime number (P) and primitive root (G)
    printf("Enter a prime number (P): ");
    scanf("%lld", &P);

    printf("Enter a primitive root of %lld (G): ", P);
    scanf("%lld", &G);

    // Step 2: Each user chooses their private key
    printf("Enter private key of User A: ");
    scanf("%lld", &a);

    printf("Enter private key of User B: ");
    scanf("%lld", &b);

    // Step 3: Compute public keys
    A = power(G, a, P);  // A = G^a mod P
    B = power(G, b, P);  // B = G^b mod P

    printf("\nUser A sends Public Key A = %lld to User B", A);
    printf("\nUser B sends Public Key B = %lld to User A", B);

    // Step 4: Each user computes the shared secret key
    keyA = power(B, a, P);  // keyA = B^a mod P
    keyB = power(A, b, P);  // keyB = A^b mod P

    printf("\n\nSecret key for User A = %lld", keyA);
    printf("\nSecret key for User B = %lld", keyB);

    // Step 5: Both keys should be identical
    if (keyA == keyB)
        printf("\n✅ Shared Secret Key Established Successfully: %lld\n", keyA);
    else
        printf("\n❌ Error: Keys do not match!\n");

    return 0;
}