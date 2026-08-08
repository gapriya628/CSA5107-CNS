#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100], key[100];
    int i, j = 0, shift;

    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key: ");
    scanf("%s", key);

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            shift = tolower(key[j % strlen(key)]) - 'a';

            if (isupper(text[i]))
                text[i] = (text[i] - 'A' + shift) % 26 + 'A';
            else
                text[i] = (text[i] - 'a' + shift) % 26 + 'a';

            j++;
        }
    }

    printf("\nEncrypted Text: %s", text);

    return 0;
}
