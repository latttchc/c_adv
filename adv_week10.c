#pragma warning(disable : 4996)

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// 自定義関数のプロトタイプ
void myFirstFunc();
void showHello(int num);
int add(int, int);

void swap1(int x, int y);
void swap2(int *x, int *y);

// 練習用　関数のプロトタイプ
void aisatu();
int getData();
int tripleData(int);
// 課題用　関数のプロトタイプ
void printHello();
int wa(int, int);
void checkAge(int);

////////////////////////////////////////////
int main()
{
	int i;
	int a = 3, b = 4, c;
	puts("\n-----　練習　----");

	aisatu();

	int y;
	y = getData();
	printf("y = %d\n", y);

	y = tripleData(100);
	printf("y = %d\n", y);

	printf("tripleData(a) = %d\n", tripleData(a));

	puts("\n\n---------------　課題　--------------");
	// ーーーーーーーーーーーーーーーーーーーーーー
	// 1人目
	int age1 = 30;
	if (age1 >= 20)
	{
		puts("大人です");
	}
	else
	{
		puts("子供です");
	}
	// ーーーーーーーーーーーーーーーーーーーーーー
	// 2人目
	int age2 = 10;
	if (age2 >= 20)
	{
		puts("大人です");
	}
	else
	{
		puts("子供です");
	}

	puts("----------　課題で作成した関数の呼び出し　----------");
	puts("＊＊＊＊関数　printHello　の呼び出し");
	printHello();

	puts("\n＊＊＊＊関数　checkAge　の呼び出し");
	checkAge(19);
	checkAge(29);

	puts("\n＊＊＊＊関数　wa　の呼び出し");
	printf("11 + 29 = %d", wa(11, 29));

	puts("\n\n\n---------- サンプル ---------- ");
	// void myFirstFunc();
	myFirstFunc();

	// void showHello(int num);
	showHello(3);
	puts("---------");
	showHello(b);

	// int add(int x, int y);
	c = add(a, b);
	printf("戻り値：%d\n", c);

	puts("\n---------- 値渡し、ポインタ渡し ---------- ");
	int vx = 100, vy = 200;
	printf("vx = %d, vy = %d \n", vx, vy);
	swap1(vx, vy);
	printf("swap1(vx, vy)を呼び出した後：\tvx = %d, vy = %d \n", vx, vy);

	swap2(&vx, &vy);
	printf("swap2(&vx, &vy)を呼び出した後：\tvx = %d, vy = %d \n", vx, vy);

	printf("\n");
	return 0;
} //////// mainの終り

//////////////////////////////////////////
// 　練習①
// 　関数　aisatu　を作ってください
// 　関数名：aisatu
// 　引数：ない
// 　戻り値：ない
void aisatu(void)
{
	puts("こんにちは。");

	return;
}

// 　練習②
//   getData 関数作ってみる
// 　関数名：getData
// 　引数：なし
// 　戻り値：あり
// 　機能：１～１００の数字を作る
int getData()
{
	srand(time(NULL));
	int x;
	x = rand();
	x = x % 100 + 1;
	return x;
}

/*
srand(time(NULL));
rand();
*/

// 　練習③
//   tripleData 関数作ってみる
// 　関数名：tripleData
// 　引数：１つ、整数
// 　戻り値：あり、整数
// 　機能：渡された数字の3倍にし、その結果を戻り値として返す
int tripleData(int x)
{
	return x * 3;
}

//////////////////課題の関数をここに作成してください。//////////////////////////
// 　問題①
// 　関数　printHello　を作ってください
// 　関数名：printHello
// 　引数：ない
// 　戻り値：ない
// 　機能：メッセージ hello を表示する
void printHello()
{
	printf("hello\n");
}

// 　問題②
// 　関数　wa　を作ってください
// 　関数名：wa　二つの整数の和を計算し、結果を戻す
// 　引数：二つ、整数
// 　戻り値：整数
int wa(int a, int b)
{
	return a + b;
}

// 　問題③
//   checkAge 関数作ってみる
// 　関数名：checkAge
// 　引数：？？？（自分で決めてください）
// 　戻り値：ない
void checkAge(int Age)
{
	if (Age >= 20)
	{
		puts("大人");
	}
	else
	{
		puts("子供");
	}
}

////////////////////////////////////////
void myFirstFunc()
{
	puts("myFirstFuncです。");
}

/////////////////////////////////////////
void showHello(int num)
{
	int i;

	for (i = 0; i < num; i++)
	{
		printf("Hello ");
	}
	printf("\n");
}

/////////////////////////////////////////
int add(int x, int y) // 関数本体の定義
{
	int z;
	z = x + y;
	return z;
}

/////////////////////////////////////////
void swap1(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}

/////////////////////////////////////////
void swap2(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/////////////////////////////////////////
