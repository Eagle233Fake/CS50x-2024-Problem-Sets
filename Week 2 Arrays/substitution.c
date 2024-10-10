#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // 检查输入是否正确
    // 1. 是2个输入
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // 2. 输入的是字母
    int length_key = strlen(argv[1]);
    for (int i = 0; i < length_key; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    // 3. 输入的是26个字母
    if ((length_key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // 4. 输入的是不重复的字母
    int array[26] = {0};
    for (int j = 0; j < length_key; j++)
    {
        argv[1][j] = toupper(argv[1][j]);
        if (array[argv[1][j] - 'A'] == 1)
        {
        printf("Key must contain 26 characters.\n");
        return 1;
        }
        array[argv[1][j] - 'A']++;
    }
    // 获取pt
    string pt = get_string("plaintext:  ");
    // 转化
    for (int k = 0; k < length_key; k++)
    {
        argv[1][k] = toupper(argv[1][k]);
    }
    for (int l = 0, length_pt = strlen(pt); l < length_pt; l++)
    {
        if (isupper(pt[l]))
        {
            pt[l] = argv[1][pt[l] - 'A'];
        }
        else if (islower(pt[l]))
        {
            pt[l] = tolower(argv[1][pt[l] - 'a']);
        }
    }
    printf("ciphertext: %s\n", pt);
    return 0;
}
