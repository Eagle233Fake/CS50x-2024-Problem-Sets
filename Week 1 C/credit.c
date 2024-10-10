#include <cs50.h>
#include <stdio.h>
int main(void)
{
    // 计算校验值
    int size = 0;
    int digit;
    int checksum = 0;
    int first;
    int second;
    long number = get_long("Number: ");
    for (int i = 0; number > 0; i++)
    {
        digit = number % 10;
        if (i % 2 == 0)
        {
            checksum += digit;
        }
        else
        {
            if (digit * 2 < 10)
            {
                checksum += digit * 2;
            }
            else
            {
                checksum += 1 + digit * 2 % 10;
            }
        }
        number /= 10;
        second = first;
        first = digit;
        size++;
    }
    // 检测校验值
    if (checksum % 10 == 0)
    {
        // AMEX
        if (size == 15 && first == 3 && (second == 4 || second == 7))
        {
            printf("AMEX\n");
        }
        // MasterCard
        else if (size == 16 && first == 5 && second < 6 && second > 0)
        {
            printf("MASTERCARD\n");
        }
        // VISA
        else if ((size == 13 || size == 16) && first == 4)
        {
            printf("VISA\n");
        }
        // Invalid
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
