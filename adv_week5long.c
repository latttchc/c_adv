#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>
// 自定義関数のプロトタイプ
int add(int, int);

void myFirstFunc();
void showHello(int num);
void aisatu(char name[]);

void myFunction(void);
float divide(int, int);

int max(int x, int y);

int main(void) // メイン関数
{
    puts("\n---------- サンプル ---------- ");
    int a = 3, b = 4, c;
    c = add(a, b);
    printf("a+b=%d\n", c);

    puts("\n---------- 練習 ---------- ");
    // 　問題①
    // 　関数myFirstFuncの引数の有無、個数、型：＿ない＿＿＿、
    // 　戻り値の有無、型：＿＿＿ない＿＿＿＿＿。

    // 　問題②
    // 　myFirstFuncを呼び出してみてください
    myFirstFunc();

    // 　問題③
    // 　関数showHelloの引数の数は＿＿1＿＿個、int
    // 　戻り値の有無、型：＿＿＿＿ない_＿＿＿。

    // 　問題④
    // 　showHelloを呼び出してください
    showHello(3);
    showHello(b);

    // 　問題⑤
    // 　関数aisatuの引数の数は＿＿1＿個、文字列
    // 　戻り値の有無、型：＿＿＿＿ない＿＿＿＿。

    // 　問題⑥
    // 　aisatuを呼び出してください
    aisatu("佐藤");

    // 　問題⑦　標準ライブラリ関数を呼び出す
    // 　floor関数、pow関数、rand関数
    double r;
    r = floor(3.14);
    printf("r=%f\n", r);

    printf("結果:%f\n", floor(8.999));

    r = pow(2.0, 4.0);
    printf("r=%f\n", r);

    puts("\n---------- 課題 ---------- ");
    // 　問題⑧
    // 　関数myFunctionの引数の数は＿＿0＿＿個、
    // 　戻り値の有無、型：＿＿＿＿なし＿＿＿＿。

    // 　問題⑨
    // 　myFunctionを呼び出してください
    myFunction();
    // 　問題10
    // 　関数divideの引数の数は＿＿2＿個、int
    // 　戻り値の有無、型：＿＿＿有,float＿＿＿＿。

    // 　問題11
    // 　divideを呼び出してください
    int i, j;
    i = divide(5, 6);
    j = divide(70, 5);
    printf("一つ目:%d, 二つ目:%d", i, j);
    puts("");

    // 　問題12
    //  以下のメソッドmaxを呼び出すコマンド、正しいのは：＿＿ア,ウ,オ＿＿。
    //  ※ただし、アは結果を表示できない
    //
    //  正解が複数ある、すべて書いてください。
    // 　ア： max(10, 20);
    // 　イ： max();
    // 　ウ： int value = max(10, 20);
    // 　エ： int n = max();
    // 　オ： int x = 10; int y = 20; int m; m = max(x, y);

    // 　問題13
    // 　メソッド max を呼び出してください、計算の結果を表示してください。
    max(10, 20); // 結果は表示できない
    puts("");

    int value = max(10, 20);
    printf("結果は%d\n", value);

    int x = 10, y = 20, m;
    m = max(x, y);
    printf("結果は%d\n", m);
    ////////////////////////////////////////
    return 0;
}

int add(int x, int y) // 関数本体の定義
{
    int z;
    z = x + y;
    return z;
}

////////////////////////////////////////

void myFirstFunc()
{
    puts("myFirstFuncです。");
}

void showHello(int num)
{
    int i;

    for (i = 0; i < num; i++)
    {
        printf("Hello ");
    }
    printf("\n");
}

void aisatu(char name[])
{
    printf("%sさん、こんにちは。\n", name);
}

void myFunction(void)
{
    puts("myFunctionです。  ");
}

float divide(int x, int y)
{
    puts("divide の呼び出しに 成功！！！");
    return (float)x / y;
}

int max(int x, int y)
{
    puts("max の呼び出しに 成功！！！");
    int maxData;

    if (x >= y)
        maxData = x;
    else
        maxData = y;

    return maxData;
}
