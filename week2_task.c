#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age;
    printf("ageを入力:");
    scanf("%d", &age);
    /*年齢判定*/
    if (age >= 20)
    {
        printf("お酒OKですよ");
    }
    else
    {
        printf("ダメですよ");
    }
    printf("\n");

    /*奇数・偶数判定*/
    if (age % 2 == 0)
    {
        printf("ageの中身が偶数");
    }
    else
    {
        printf("ageの中身が奇数");
    }

    return 0;
}