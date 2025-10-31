#include <stdio.h>

int main()
{
    char str[100];
    int hash = 0;
    printf("Enter a string : ");
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        hash += str[i];
    }
    printf("Hash value %d \n", hash);
    return 0;
}