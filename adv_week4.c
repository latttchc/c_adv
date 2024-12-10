#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    srand(time(NULL));
    char src[8][6] = {{'x', '#', '#', '#', '#', 'y'},
                      {'#', ' ', ' ', ' ', ' ', ' '},
                      {'#', ' ', ' ', ' ', ' ', ' '},
                      {'#', ' ', ' ', ' ', ' ', ' '},
                      {'#', '#', '#', ' ', ' ', ' '},
                      {'#', ' ', ' ', ' ', ' ', ' '},
                      {'#', ' ', ' ', ' ', ' ', ' '},
                      {'z', ' ', ' ', ' ', ' ', ' '}};

    ////////////////////////////////////////
    puts("\n---------- 配列：練習 ---------- ");
    int age;
    age = 30;
    printf("age = %d\n", age);

    int m[10];
    m[0] = 800;
    m[9] = 1000;
    printf("m[0] = %d\n", m[0]);
    printf("m[9] = %d\n", m[9]);

    printf("m[1] = %d\n", m[1]);

    int j;
    for (j = 0; j < 10; j++)
    {
        printf("%d, ", j);
    }
    printf("\n");

    for (j = 0; j < 10; j++)
    {
        printf("%d: ", m[j]);
    }
    printf("\n");

    int s[5] = {100, 200};
    for (j = 0; j < 5; j++)
    {
        printf("%d: ", s[j]);
    }
    printf("\n");

    int s1[10] = {10, 20, 30, 40};
    // printf("%d\n", sizeof(s1) / sizeof(int));

    char t[6] = {'x', '#', '#', '#', '#', 'y'};
    // t[0] = 'a';
    printf("%c ", t[0]);

    for (j = 0; j < 6; j += 1)
    {
        printf("%c ", t[j]);
    }

    printf("\n");
    printf("元のパターン\n");

    int k;
    for (k = 0; k < 8; k++)
    {
        for (j = 0; j < 6; j += 1)
        {
            printf("%c", src[k][j]);
        }
        printf("\n");
    }
    printf("左右反転\n");
    for (k = 0; k < 8; k++)
    {
        for (j = 6; j > 0; j--)
        {
            printf("%c", src[k][j - 1]); // 5,4,3,..0
        }
        printf("\n");
    }
    printf("\n");

    printf("左右反転\n");
    for (k = 0; k < 8; k++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("%c", src[k][6 - 1 - j]);
        }
        printf("\n");
    }
    printf("\n");

    /* 左右反転 */
    /* 上下反転 */
    /* 90度右回転 */
    /* 90度左回転 */

    puts("\n---------- 配列：課題 ---------- ");

    int koma[20];
    // 1
    printf("Step 1\n");
    for (j = 0; j < 20; j = j + 1)
    {
        printf("%d, ", j);
    }
    printf("\n");
    printf("\n");

    // 2
    printf("Step 2\n");
    for (j = 0; j < 20; j = j + 1)
    {
        printf("%d, ", koma[j]);
    }
    printf("\n");
    printf("\n");

    // 3
    printf("Step 3\n");
    for (j = 0; j < 20; j = j + 1)
    {
        koma[j] = 7;
    }

    // 4
    printf("\nStep 4\n");
    for (j = 0; j < 20; j = j + 1)
    {
        printf("%d ", koma[j]);
    }
    printf("\n");
    printf("\n");

    // 5
    printf("Step 5\n");
    int x;
    // printf("%d", x);
    for (j = 0; j < 20; j = j + 1)
    {
        x = rand() % 3;
        koma[j] = x;
    }
    printf("\n");

    // 6
    printf("Step 6\n");
    for (j = 0; j < 20; j = j + 1)
    {
        printf("%d ", koma[j]);
    }
    printf("\n");
    printf("\n");

    // 7
    printf("Step 7\n");
    for (j = 0; j < 20; j = j + 1)
    {
        if (koma[j] == 0) // 空白:0
        {
            printf(" ");
        }
        else if (koma[j] == 1) // 1:●
        {
            printf("● ");
        }
        else // 2;◯
        {
            printf("◯ ");
        }
    }

    printf("\n");

    puts("\n---------- 配列サンプル ---------- ");
    int i;

    int test[5];
    test[0] = 80;
    test[1] = 60;
    test[2] = 22;
    test[3] = 50;
    test[4] = 75;

    for (i = 0; i < 5; i++)
    {
        printf(" %d 番目の人の点数は %d です。\n", i + 1, test[i]);
    }

    puts("\n---------- 配列初期化 ---------- ");

    int vs[5] = {80, 60, 22, 50, 75};
    for (i = 0; i < 5; i++)
    {
        printf(" %d 番目： %d \n", i + 1, vs[i]);
    }

    ////////////////////////////////////////
    puts("\n---------- ２次元配列---------- ");
    int apt[2][3];

    apt[0][0] = 100;
    apt[0][1] = 90;
    apt[0][2] = 80;

    apt[1][0] = 85;
    apt[1][1] = 77;
    apt[1][2] = 99;

    int kai = 0;
    int ban = 1;
    printf(" %d 階、 %d 番の箱の中身： %d \n", kai, ban, apt[kai][ban]);
    printf("\n\n");

    for (kai = 0; kai < 2; kai++)
    {
        printf(" %d 階の各箱の中身：", kai);

        for (ban = 0; ban < 3; ban++)
        {
            printf("%3d, ", apt[kai][ban]);
        }
        printf("\n");
    }

    // 文字列：文字の配列
    // 文字列１：文字列は文字の配列で表す
    puts("\n--------文字列１：文字の配列--------");
    char mojiRetu[6];
    mojiRetu[0] = 'H';
    mojiRetu[1] = 'e';
    mojiRetu[2] = 'l';
    mojiRetu[3] = 'l';
    mojiRetu[4] = 'o';
    mojiRetu[5] = '\0'; // 文字列の終わりを示す特殊文字

    printf("①　　　文字で表示：\t");
    for (i = 0; i < 6; i++)
    {
        printf("%c,\t", mojiRetu[i]);
    }
    printf("\n");

    printf("②文字コードで表示：\t");
    for (i = 0; i <= strlen(mojiRetu); i++)
    {
        printf("%d;\t", mojiRetu[i]);
    }
    printf("\n");

    // 文字列が特有な表示方法
    printf("③文字列として表示：%s   \n", mojiRetu);

    // 文字列２：文字列の初期化
    puts("\n--------文字列２：文字列の初期化--------");

    printf("＊＊＊初期化方法１：\t");
    char values[] = {'a', 'b', 'c', '\0'};
    printf("%s  \n", values);

    printf("＊＊＊初期化方法２：\t");
    char str[100] = "Hello";
    printf("%s  \n\n", str);

    ////////////////////////////////////////
    return 0;
}
