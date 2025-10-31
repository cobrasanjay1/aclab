#include <stdio.h>
#include <string.h>

// Internal (predefined) key
#define DEFAULT_KEY "MySecretKey"

// Simple XOR-based encryption/decryption using the internal key
void encrypt(char *plaintext, char *ciphertext) {
    int i;
    char key[] = DEFAULT_KEY;
    int key_len = strlen(key);

    for (i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }
    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *decryptedtext) {
    int i;
    char key[] = DEFAULT_KEY;
    int key_len = strlen(key);

    for (i = 0; i < strlen(ciphertext); i++) {
        decryptedtext[i] = ciphertext[i] ^ key[i % key_len];
    }
    decryptedtext[i] = '\0';
}

int main() {
    char plaintext[256], ciphertext[256], decryptedtext[256];

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  // remove newline

    // Encryption
    encrypt(plaintext, ciphertext);

    printf("\nEncrypted text (in hex): ");
    for (int i = 0; i < strlen(plaintext); i++)
        printf("%02X ", (unsigned char)ciphertext[i]);
    printf("\n");

    // Decryption
    decrypt(ciphertext, decryptedtext);
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}
