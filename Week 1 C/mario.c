#include <cs50.h>
#include <stdio.h>
int main(void)
{
    // 要求用户输入高度
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    // 搭建 Blocks
    if (height > 0 && height <= 8)
        for (int i = 0; i < height; i++)
        {
            // 输入左边的Blocks
            // 输入空格
            for (int j = 0; j < height - i - 1; j++)
            {
                printf(" ");
            }
            // 输入#
            for (int k = 0; k < i + 1; k++)
            {
                printf("#");
            }
            printf("  ");
            // 输入右边的Blocks
            for (int l = 0; l < i + 1; l++)
            {
                printf("#");
            }
            printf("\n");
        }
}
