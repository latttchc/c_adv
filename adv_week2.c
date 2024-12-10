#pragma warning(disable : 4996)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	////////////////////////////////////////
	int x;
	x = 100;
	printf("結果");
	printf("\n");

	printf("結果:%d\n", x);

	int ages;
	ages = 20;

	scanf("%d", &ages);

	printf("age = %d\n", ages);

	int b = ages / 7;
	int rem = ages % 7;

	printf("b = %d, rem = %d\n", b, rem);

	if (rem == 0)
	{
		printf("倍数");
	}
	else
	{
		printf("倍数ではない");
	}

	puts("\n\n------課題------\n");
	int age;
	printf("ageを再度入力:");
	scanf("%d", &age);
	puts("---年齢判定---");
	if (age >= 20)
	{
		printf("お酒OKですよ");
	}
	else
	{
		printf("ダメですよ");
	}
	puts("");

	puts("---奇数・偶数判定---");
	if (age % 2 == 0)
	{
		printf("ageの中身が偶数");
	}
	else
	{
		printf("ageの中身が奇数");
	}
	puts("");

	int luck;
	srand(time(NULL));
	luck = rand() % 4; // 0～3の数字を作成する

	////////////////////////////////
	// 整数 int
	puts("\n--------整数--------");
	int yourage;
	yourage = 30;
	printf("age = [%d]  \n", yourage);
	printf("age = [%ld]  \n", yourage);

	printf("age = [%5d]  \n", yourage);
	printf("age = [%05d]  \n", yourage);
	printf("age = [%-5d]  \n", yourage);
	printf("age = [%-+5d]  \n", yourage);

	// 小数点数 float、double
	puts("\n--------小数点数--------");
	float pi;
	pi = 3.14159265359;
	printf("pi = [%f]  \n", pi);
	printf("pi = [%8.3f]  \n", pi);

	float pi_d;
	pi_d = 3.1;
	printf("pi_d = [%f]  \n", pi_d);
	printf("pi_d = [%8.3f]  \n", pi_d);

	// データ型　char
	puts("\n--------データ型　char--------");
	char myage;
	myage = 77;
	printf("myage = %d  : 文字コード10進数\n", myage);
	printf("myage = %c  : 文字\n", myage);
	printf("myage = %x  : 文字コード16進数\n", myage);

	// 文字 char
	puts("\n--------文字--------");
	char moji;
	moji = 'a';
	printf("文字を表示してみる：%c  \n", moji);
	printf("数字で表示してみる：%d  \n", moji);
	printf("数字で表示してみる：%x  \n", moji);

	// 文字列：文字の配列
	puts("\n--------文字列--------");
	char mojiRetu[6] = "Hello";
	printf("文字列は：%s   \n", mojiRetu);

	////////////////////////////////////////

	return 0;
}
