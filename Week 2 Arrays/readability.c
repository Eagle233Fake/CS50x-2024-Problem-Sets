#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int letter = 0;
    int word = 1;
    int sentence = 0;
    // 获取句子
    string text = get_string("Text: ");
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        // 获取 letter
        if (isalpha(text[i]))
        {
            letter++;
        }
        // 获取 word
        if (text[i] == ' ')
        {
            word++;
        }
        // 获取 sentence
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentence++;
        }
    }
    // 计算系数
    double L = (double) letter / (double) word * 100;
    double S = (double) sentence / (double) word * 100;
    double index = 0.0588 * L - 0.296 * S - 15.8;
    // 四舍五入
    int result = round(index);
    // 确定 readability
    if (result > 0 && result < 17)
    {
        printf("Grade %i\n", result);
    }
    else if (result <= 0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}
