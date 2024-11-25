// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and "
               "symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int length = strlen(password);

    int lower = 0, upper = 0, num = 0, punct = 0;
    for (int i = 0; i < length; i++)
    {
        if (isupper(password[i]))
        {
            upper++;
        }
        if (islower(password[i]))
        {
            lower++;
        }
        if (isdigit(password[i]))
        {
            num++;
        }
        if (ispunct(password[i]))
        {
            punct++;
        }
    }

    if (upper > 0 && lower > 0 && num > 0 && punct > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
