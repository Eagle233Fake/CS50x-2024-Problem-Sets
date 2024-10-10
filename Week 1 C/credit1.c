#include <cs50.h>
#include <stdio.h>
long power_of_10(int k);
int main(void)
{
    long num = get_long("Credit Card Number: ");
    long sum = 0;
    long j = 0;
    // Calculate
    for (long i = 1; i < 17; i++)
    {
        j = (num % power_of_10(i)) / power_of_10(i - 1);
        if (i % 2 == 1)
            sum = sum + j;
        else if (j * 2 >= 10)
            sum = sum + 1 + (j * 2 % 10);
        else
            sum = sum + (j * 2);
    }
    if (sum % 10 == 0)
    {
        // AMEX
        if (num / 10000000000000 == 34 || num / 10000000000000 == 37)
            printf("AMEX\n");
        // MASTERCARD
        else if (num / 100000000000000 == 51 || num / 100000000000000 == 52 ||
                 num / 100000000000000 == 53 || num / 100000000000000 == 54 ||
                 num / 100000000000000 == 55)
            printf("MASTERCARD\n");
        // VISA
        else if (num / 1000000000000 == 4 || num / 1000000000000000 == 4)
            printf("VISA\n");
        // INVALID
        else
            printf("INVALID\n");
    }
    // INVALID
    else
        printf("INVALID\n");
}
// Calculate power of  10
long power_of_10(int k)
{
    long result = 1;
    for (long l = 0; l < k; l++)
    {
        result *= 10;
    }
    return result;
}
