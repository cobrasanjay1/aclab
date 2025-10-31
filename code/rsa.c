

#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
    int t;
    while (1) {
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}

int modInverse(int e, int phi) {
    int d, k = 1;
    while (1) {
        d = (1 + k * phi) / e;
        if (((d * e) % phi) == 1)
            return d;
        k++;
    }
}

int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

int main() {
    int p, q, e;
    printf("Enter two prime numbers:\n");
    scanf("%d %d", &p, &q);

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    printf("Enter the exponent: ");
    scanf("%d", &e);

    int d = modInverse(e, phi);

    printf("Public key: (n = %d, e = %d)\n", n, e);
    printf("Private key: (n = %d, d = %d)\n", n, d);

    int msg;
    printf("Enter a Message to Encrypt: ");
    scanf("%d", &msg);

    int c = modExp(msg, e, n);
    printf("Encrypted Message: %d\n", c);

    int m = modExp(c, d, n);
    printf("Decrypted Message: %d\n", m);

    return 0;
}