#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int repeated_letter(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            for (int j = 0; j < i; j++)
            {
                if (str[i] == str[j])
                {
                    printf("Key must not contain repeated letters.\n");
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    // Get the key and validate it
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check the key contain 26 letters.
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check the key contain only alphabical letters.
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }
    }

    // Check fo repeated letters.
    if (repeated_letter(argv[1]))
    {
        return 1;
    }

    // Get the plaintext from the user
    string plaintext = get_string("Plaintext:  ");
    printf("ciphertext: ");

    // Ensipher the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isalpha(c))
        {
            if (islower(c))
            {
                int index = c - 'a';
                printf("%c", tolower(argv[1][index]));
            }
            else if (isupper(c))
            {
                int index = c - 'A';
                printf("%c", toupper(argv[1][index]));
            }
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");

    return 0;
}
