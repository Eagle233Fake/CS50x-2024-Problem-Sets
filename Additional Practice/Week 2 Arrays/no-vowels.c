// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    int length = strlen(argv[1]);
    for (int i = 0; i < length; i++)
    {
        switch (argv[1][i])
        {
            case 'a':
                argv[1][i] = '6';
                break;
            case 'e':
                argv[1][i] = '3';
                break;
            case 'i':
                argv[1][i] = '1';
                break;
            case 'o':
                argv[1][i] = '0';
                break;
        }
    }

    printf("%s\n", argv[1]);
}
