#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // 检查是否是正确的输入
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    char *end;
    long number = strtol(argv[1], &end, 10);
    if (*end != '\0')
    // ???
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    // 处理输入
    int k;
    if (atoi(argv[1]) > 26)
    {
        k = (atoi(argv[1]) % 26);
    }
    else
    {
        k = (atoi(argv[1]));
    }
    // 获取输入
    string pt = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int i = 0, length = strlen(pt); i < length; i++)
    {
        if (isalpha(pt[i]))
        {
            if (islower(pt[i]))
            {
                if (pt[i] + k > 'z')
                {
                    printf("%c", pt[i] - 26 + k);
                }
                else
                {
                    printf("%c", pt[i] + k);
                }
            }
            else
            {
                if (pt[i] + k > 'Z')
                {
                    printf("%c", pt[i] - 26 + k);
                }
                else
                {
                    printf("%c", pt[i] + k);
                }
            }
        }
        else
        {
            printf("%c", pt[i]);
        }
    }
    printf("\n");
    // 输出
    return 0;
}
