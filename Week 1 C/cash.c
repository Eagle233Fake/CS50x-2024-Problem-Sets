#include <cs50.h>
#include <stdio.h>
int main(void)
{
    // Get input
    int change_owed;
    do
    {
        change_owed = get_int("Change owed: ");
    }
    while (change_owed < 0);

    // 25
    int sum_25 = change_owed / 25;
    int remain_25 = change_owed - 25 * sum_25;

    // 10
    int sum_10 = remain_25 / 10;
    int remain_10 = remain_25 - 10 * sum_10;

    // 5
    int sum_5 = remain_10 / 5;
    int remain_5 = remain_10 - 5 * sum_5;

    // Sum up
    int sum = sum_25 + sum_10 + sum_5 + remain_5;
    printf("%i\n", sum);
}
