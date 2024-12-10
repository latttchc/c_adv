#pragma warning(disable : 4996)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    ////////////////////////////////////////
    puts("\n----------練習 ---------- \n");

    int age;
    age = 20;
    printf("%d\n", age);

    if (age >= 20)
    {
        puts("おめでとう");
    }
    else
    {
        puts("お酒ダメですよ");
    }

    int luck;
    srand(time(NULL));
    luck = rand() % 4; // 0～3の数字を作成する
    printf("luck = %d \n", luck);

    if (luck == 3)
    {
        puts("大吉");
    }
    else if (luck == 2)
    {
        puts("中吉");
    }
    else if (luck == 1)
    {
        puts("小吉");
    }
    else
    {
        puts("吉");
    }

    switch (luck)
    {
    case 3:
        puts("大吉");
        break;
    case 2:
        puts("中吉");
        break;
    case 1:
        puts("小吉");
        break;
    default:
        puts("吉");
        break;
    }

    puts(age >= 20 ? "おめでとう" : "お酒だめ");

    int k;
    puts("数字を指定してください :");
    scanf("%d", &k);
    printf("k = %d\n", k);

    puts("------while------");
    int a;
    a = 1;
    while (a <= k)
    {
        puts("hello");
        a++;
    }

    puts("------do....while------");
    a = 1;
    do
    {
        puts("hello");
        a++;
    } while (a <= k);

    puts("------for------");
    for (a = 1; a <= k; a++)
    {
        puts("hello");
    }

    int b;
    b = 100;
    while (b <= 500)
    {
        printf("%d  ", b);
        b += 100;
    }
    puts("");
    for (b = 1; b <= 5; b += 1)
    {
        printf("%d,", b * 100);
    }

    ////////////////////////////////
    puts("\n----------課題 ---------- \n");
    int p;
    printf("倍数にしたい値を入力: ");
    scanf("%d", &p);
    if (p == 0 || p > 200)
    {
        puts("1~200の中のkの倍数を表示できません");
    }
    else
    {
        for (int num = p; num <= 200; num += p)
        {
            printf("%d, ", num);
        }
    }

    ////////////////////////////////
    puts("\n----------サンプル ---------- \n");
    int data;
    data = 100;

    // puts("dataを入力：");
    // scanf("%d", &data);

    printf("data = %d  \n", data);

    int amari;
    amari = data % 2;
    if (amari == 1)
    {
        puts(" 奇数 ");
    }
    else
    {
        puts(" 偶数 ");
    }

    // 三項演算子
    puts("三項演算子");
    printf("　%s\n\n", amari == 1 ? "奇数" : "偶数");

    // 関係演算子による判定の結果について
    puts("関係演算子による判定の結果について");

    int z = 100;
    printf("\n判定式の結果： %d  \n\n", z == 100);

    if (1)
    {
        puts("  確認用：条件　１ ");
        printf("  z = %d  \n", z);
    }
    else if (2)
    {
        puts("  確認用：条件　２ ");
        printf("  z = %d  \n", z);
    }
    else
    {
        puts("  確認用：それ以外 ");
        printf("  z = %d  \n", z);
    }

    ////////////////////////////////////////
    int i;
    int count = 3;

    puts("\n----------■ while ---------- \n");
    i = 1;
    while (i <= count)
    {
        printf("hello, ");
        i++;
    }
    printf("\n");

    //////////////////////////////////////////////

    puts("\n----------■ do ... while ---------- \n");
    i = 1;
    do
    {
        printf("hello; ");
        i++;
    } while (i <= count);
    puts("");

    //////////////////////////////////////////////

    puts("\n----------■ for ---------- \n");
    for (i = 1; i <= count; i++)
    {
        printf("hello: ");
    }
    printf("\n");

    //////////////////////////////////////////////

    puts("\n----------★ while   break ---------- \n");
    i = 1;
    while (1)
    {
        if (i > count)
        {
            break;
        }

        printf("hello~ ");

        i++;
    }
    printf("\n");

    //////////////////////////////////////////////

    puts("\n----------★ for   break ---------- \n");
    i = 1;

    for (i = 1;; i++)
    {
        if (i > count)
        {
            break;
        }
        printf("hello_ ");
    }
    printf("\n");

    //////////////////////////////////////////////

    return 0;
}
