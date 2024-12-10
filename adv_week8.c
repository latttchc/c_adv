#pragma warning(disable : 4996)
#pragma warning(disable : 6001) //

#include <stdio.h>
#include <string.h>
// #include "baseball.h"

typedef struct record
{
	char name[11];
	int wins;
	int loses;
	double average;
} RECORD;

int main()
{
	int i;
	puts("\n----- 練習 -----");

	struct record teamx;
	teamx.wins = 10;

	RECORD teamA;
	RECORD teamB = {"Rooks", 19, 31, 0};
	RECORD teamC;

	strcpy(teamA.name, "Queens");
	teamA.wins = 32;
	teamA.loses = 18;
	teamA.average = (double)teamA.wins / (teamA.wins + teamA.loses);

	printf("%s:\t%.3f\n", teamA.name, teamA.average);

	teamB.average = (double)teamB.wins / (teamB.wins + teamB.loses);
	printf("%s:\t%.3f\n", teamB.name, teamB.average);

	teamC = teamA;
	printf("%s:\t%.3f\n", teamC.name, teamC.average);

	puts("\n\n----- 課題 -----");

	RECORD league[2];
	for (i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			league[i] = teamA;
		}
		else if (i == 1)
		{
			league[i] = teamB;
		}
		printf("チーム名:\"%s\", 勝ち数:%d, 負け数:%d\n", league[i].name, league[i].wins, league[i].loses);
	}

	puts("\n\n---------- 構造体の宣言・定義・参照 ----------");
	// 　構造体のテンプレート（枠型）の宣言
	struct seiseki // 成績
	{
		int number;		// 番号
		char name[20];	// 名前
		double average; // 平均点
	};

	// 構造体変数の定義
	struct seiseki student1;
	struct seiseki student2;

	// 構造体メンバの参照
	student1.number = 1000;
	strcpy(student1.name, "佐藤一郎");
	student1.average = 90.567;

	printf("%04d %s %.1f\n", student1.number, student1.name, student1.average);

	puts("\n\n---------- 構造体の配列 ----------");
	struct seiseki gakka[100];
	strcpy(gakka[0].name, "佐藤次郎");
	printf("配列先頭の学生: %s\n", gakka[0].name);

	puts("\n\n---------- 構造体の初期化 ----------");
	struct seiseki student5 = {1, "Satou", 90.2};

	struct seiseki student9[3] = {
		{200, "Suzuki", 77.3},
		{201, "Takahashi", 59.1},
		{202, "Tanaka", 64.9}};

	printf("%04d %s %.1f\n", student5.number, student5.name, student5.average);

	for (i = 0; i < 3; i++)
	{
		printf("%04d %s %.1f\n", student9[i].number, student9[i].name, student9[i].average);
	}

	puts("\n\n---------- 構造体同士の代入 ----------");
	student2 = student5;
	printf("構造体同士代入の結果:\t\t%04d %s %.1f\n", student2.number, student2.name, student2.average);

	student2.number = student5.number;
	strcpy(student2.name, student5.name);
	student2.average = student5.average;

	printf("構造体メンバーの代入の結果:\t%04d %s %.1f\n", student2.number, student2.name, student2.average);

	puts("\n\n---------- typedefで構造体を宣言 ----------");
	// 構造体データ型の宣言
	typedef struct
	{
		int number;		// 番号
		char name[20];	// 名前
		double average; // 平均点
	} Seiseki;

	typedef int MyData;
	MyData age;

	typedef struct seiseki MyStruct;
	typedef struct seiseki RECORDseiseki;

	MyStruct student6;
	MyStruct y;
	MyStruct *ptstudent6;
	MyStruct *pty;

	RECORDseiseki z;

	// 変数定義
	Seiseki student7;

	student7.number = 2000;
	strcpy(student7.name, "佐藤");
	student7.average = 80;

	printf("typedefを使用したデータ: %04d %s %.1f\n", student7.number, student7.name, student7.average);

	// student7 = student9[0];
	// printf("構造体代入後 : %04d %s %.1f\n", student7.number, student7.name, student7.average);

	Seiseki gakka2[100];
	gakka2[0].number = 9999;
	strcpy(gakka2[0].name, "鈴木三郎");
	printf("配列先頭の学生 : %s\n", gakka2[0].name);

	printf("\n");
	return 0;
}
