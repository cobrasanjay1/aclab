#include <stdio.h>
#include <string.h>

#define SBOX_LEN 256

// Key Scheduling Algorithm (KSA)
void KSA(unsigned char *key, int key_len, unsigned char *S) {
    int i, j = 0;
    unsigned char temp;

    for (i = 0; i < SBOX_LEN; i++)
        S[i] = i;

    for (i = 0; i < SBOX_LEN; i++) {
        j = (j + S[i] + key[i % key_len]) % SBOX_LEN;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }
}

// Pseudo-Random Generation Algorithm (PRGA)
void PRGA(unsigned char *S, unsigned char *input, unsigned char *output, int text_len) {
    int i = 0, j = 0, k, t;
    unsigned char temp;

    for (k = 0; k < text_len; k++) {
        i = (i + 1) % SBOX_LEN;
        j = (j + S[i]) % SBOX_LEN;

        temp = S[i];
        S[i] = S[j];
        S[j] = temp;

        t = (S[i] + S[j]) % SBOX_LEN;
        output[k] = input[k] ^ S[t];
    }
}

int main() {
    unsigned char key[256], plaintext[256], ciphertext[256], decrypted[256];
    unsigned char S[SBOX_LEN];
    int text_len, key_len, i;

    printf("Enter the key: ");
    fgets((char *)key, sizeof(key), stdin);
    key[strcspn((char *)key, "\n")] = '\0'; // remove newline

    printf("Enter the plaintext: ");
    fgets((char *)plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn((char *)plaintext, "\n")] = '\0'; // remove newline

    key_len = strlen((char *)key);
    text_len = strlen((char *)plaintext);

    // Encryption
    KSA(key, key_len, S);
    PRGA(S, plaintext, ciphertext, text_len);

    printf("\nCiphertext (in hex): ");
    for (i = 0; i < text_len; i++)
        printf("%02X ", ciphertext[i]);
    printf("\n");

    // Decryption
    KSA(key, key_len, S);
    PRGA(S, ciphertext, decrypted, text_len);
    decrypted[text_len] = '\0';

    printf("Decrypted text: %s\n", decrypted);

    return 0;
}
