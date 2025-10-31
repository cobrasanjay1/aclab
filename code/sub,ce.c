#include <stdio.h>
#include <ctype.h>

int main() {
    char text[100], ch;
    int key, i;

    printf("Enter a message: ");
    scanf(" %[^\n]", text);
    printf("Enter key (shift amount): ");
    scanf("%d", &key);

    // Encrypt
    printf("\nEncrypted message: ");
    for (i = 0; text[i] != '\0'; i++) {
        ch = text[i];
        if (isupper(ch))
            ch = (ch - 'A' + key) % 26 + 'A';
        else if (islower(ch))
            ch = (ch - 'a' + key) % 26 + 'a';
        text[i] = ch;
        printf("%c", ch);
    }

    // Decrypt
    printf("\nDecrypted message: ");
    for (i = 0; text[i] != '\0'; i++) {
        ch = text[i];
        if (isupper(ch))
            ch = (ch - 'A' - key + 26) % 26 + 'A';
        else if (islower(ch))
            ch = (ch - 'a' - key + 26) % 26 + 'a';
        printf("%c", ch);
    }

    printf("\n");
    return 0;
}