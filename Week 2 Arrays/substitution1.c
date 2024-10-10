#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // 检查是否符合
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // 遍历 char
    int length = strlen(argv[1]);
    if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < length; i++)
    {
        if (!isalpha((argv[1])[i]))
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    int array[26];
    for (int i = 0; i < 26; i++)
    {
        array[i] = 0;
    }
    for (int i = 0; i < 26; i++)
    {
        array[toupper((argv[1])[i]) - 'A'] += 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (array[i] == 0)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }

    /*
    int count = 0;
    for (int i = 0; i < length - 1; i++)
    {
        if (!isalpha((argv[1])[i]))
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        count += toupper((argv[1])[i]);
    }
    if (count != 1936)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    */

    // 接受输入
    string pt = get_string("plaintext:  ");
    printf("ciphertext: ");
    // 转化
    for (int k = 0, length_pt = strlen(pt); k < length_pt; k++)
    {
        // 大写
        if (isupper(pt[k]))
        {
            printf("%c", (toupper(argv[1][pt[k] - 'A'])));
        }
        // 小写
        else if (islower(pt[k]))
        {
            printf("%c", (toupper(argv[1][pt[k] - 'a'])) + 'a' - 'A');
        }
        else
        {
            printf("%c", pt[k]);
        }
    }
    printf("\n");
    return 0;
}
