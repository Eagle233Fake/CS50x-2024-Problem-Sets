#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char rotate(char c, int key);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Make sure every character in argv[1] is a digit
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);
    // Prompt user for plaintext
    string pt = get_string("plaintext:  ");
    printf("ciphertext: ");
    // For each character in the plaintext:
    for (int j = 0; pt[j] != '\0'; j++)
    {
        pt[j] = rotate(pt[j], key);
    }
    printf("%s\n", pt);
    return 0;
}
        // Rotate the character if it's a letter
char rotate(char c, int key)
{
    if (isupper(c))
    {
        return 'A' + (c - 'A' + key) % 26;
    }
    else if (islower(c))
    {
        return 'a' + (c - 'a' + key) % 26;
    }
    else
    {
        return c;
    }
}
