#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char upper(string s, int i);
int cvt(char c);

int main(void)
{
    // 写出数组

    int array[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                     1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // 获取玩家的输入

    string player_1 = get_string("Player 1: "), player_2 = get_string("Player 2: ");

    // 分别计算总和

    int sum_1 = 0, sum_2 = 0;

    for (int p1 = 0, length_1 = strlen(player_1); p1 < length_1; p1++)
    {
        sum_1 += array[cvt(upper(player_1, p1))];
    }

    for (int p2 = 0, length_2 = strlen(player_2); p2 < length_2; p2++)
    {
        sum_2 += array[cvt(upper(player_2, p2))];
    }

    // 进行比较，输出谁赢

    if (sum_1 == sum_2)
    {
        printf("Tie!\n");
    }
    else if (sum_1 <= sum_2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Player 1 wins!\n");
    }
}

// 转为大写，并去除无用的符号

char upper(string s, int i)
{
    if (s[i] >= 'A' && s[i] <= 'z')
    {
        return toupper(s[i]);
    }
    return '\0';
}

// 定义一个对应的函数

int cvt(char c)
{
    int n = c - 'A';
    return n;
}
