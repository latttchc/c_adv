#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TEAMNUM 6	  /* チーム数 */
#define MAX_LENGTH 10 /* チーム名の長さの上限 */

////////////////////////////////////////////
// 構造体のテンプレート（枠型）の宣言
typedef struct seiseki
{					// 成績
	int number;		// 番号
	char name[20];	// 名前
	double average; // 平均点
} Seiseki;

int structarraypointer();
int nest();
////////////////////////////////////////////
// 勝敗情報　の構造体の宣言
typedef struct record
{							   /* 勝敗情報 */
	char name[MAX_LENGTH + 1]; /* チーム名 */
	int wins;				   /* 勝ち数 */
	int losses;				   /* 負け数 */
	double average;			   /* 勝率 */
} RECORD;

// 構造体配列
RECORD team[TEAMNUM]; /* グローバル変数 */

// 過去問fe19s10に、利用する関数
void calcAverage();				   /* 完成した関数 */
void print();					   /* 練習の関数 */
void printRank();				   /* 課題の関数 */
void sort(RECORD *pTeam[TEAMNUM]); /* 完成した関数 */

// 便宜上、追加した関数
void insertTeams(RECORD *team);
////////////////////////////////////////////
void printRank()
{
	int i;
	int rank = 1;
	RECORD *pTeam[TEAMNUM];

	calcAverage();
	for (i = 0; i < TEAMNUM; i++)
	{
		pTeam[i] = &team[i];
	}
	sort(pTeam);
	printf("順位 チーム名 勝ち 負け	勝率\n");
	for (i = 0; i < TEAMNUM; i++)
	{
		if (i > 0)
		{
			if (pTeam[i]->average != pTeam[i - 1]->average)
			{
				rank++;
			}
		}
		printf("%1d	%-10s %4d %4d	%5.3f\n", rank,
			   pTeam[i]->name,
			   pTeam[i]->wins,
			   pTeam[i]->losses,
			   pTeam[i]->average);
	}
}

////////////////////////////////////////////
void print()
{
}

////////////////////////////////////////////
int main()
{
	int i;
	puts("\n-----　練習　----");
	insertTeams(team);
	calcAverage();

	// 構造体
	struct record A;
	A.wins = 30;
	printf("%d\n", A.wins);

	RECORD B;
	B.wins = 40;
	printf("%d\n", B.wins);

	RECORD C = {"C", 20, 30, 0};
	printf("%d\n", C.wins);

	// ポインタ
	int age = 31;
	printf("age = %d\n", age);
	printf("&age = %p\n", &age);

	int *pAge;
	pAge = &age;
	printf("pAge = %p\n", pAge);
	printf("*pAge = %d\n", *pAge);

	// 構造体をへのポインタ
	RECORD *pC;
	pC = &C;
	printf("pC = %p\n", pC);
	printf("(*pC).wins = %d\n", (*pC).wins);
	printf("pC->wins = %d\n", pC->wins);
	printf("C.wins = %d\n", C.wins);

	puts("----------　構造体の大きさ　----");
	for (i = 0; i < TEAMNUM; i++)
	{
		printf("%-10s %6d %6d %8.2f\t%p\n",
			   team[i].name,
			   team[i].wins,
			   team[i].losses,
			   team[i].average,
			   &team[i]);
	}

	puts("\n\n----------　ポインタ演算　----");

	printf("team = %p\n", team);

	RECORD *ptr;
	ptr = team;
	printf("ptr = %p \n", ptr);
	printf("ptr -> name = %s \n", ptr->name);

	ptr++;
	printf("ptr = %p \n", ptr);
	printf("ptr -> name = %s \n", ptr->name);

	printf("(int)sizeof(team[0]):%d バイト\n", (int)sizeof(team[0]));

	int a, b, c, d;
	a = (int)sizeof(team[0].name);
	b = (int)sizeof(team[0].wins);
	c = (int)sizeof(team[0].losses);
	d = (int)sizeof(team[0].average);

	printf("a: %d, b: %d, c: %d, d: %d, バイト", a, b, c, d);

	puts("\n\n-----　課題　----");
	printf("　　勝率の高いチームから順に表示\n");
	printRank();

	puts("\n\n\n\n----------　構造体とポインタ　----");
	puts("----------　ポインタの基本　----");
	struct seiseki student1;
	student1.number = 1000;
	printf("student1.number = \t%04d\n", student1.number);
	printf("&student1 \t\t%p\n", &student1);

	struct seiseki *pstd1;
	pstd1 = &student1;
	printf("pstd1  : \t\t%p\n", pstd1);
	printf("pstd1->number = \t%04d\n", pstd1->number);

	puts("\n----------　ポインタの基本、初期化で構造体----");
	struct seiseki student2 = {1, "Satou", 90.2};
	struct seiseki *pstd2;
	pstd2 = &student2;

	printf("student2.name = %s\n", student2.name);
	printf("pstd2 = &student2 : %p\n\n", pstd2);
	printf("pstd2->name = \t%s\n", pstd2->name);
	printf("(*pstd2).name = %s\n", (*pstd2).name);

	puts("\n----------　ポインタの基本、間接演算子でメンバーを参照----");
	printf("(*pstd2).number = \t%d\n", (*pstd2).number);
	printf("(*pstd2).name = \t%s\n", (*pstd2).name);
	printf("(*pstd2).average = \t%f\n", (*pstd2).average);

	puts("\n----------　ポインタの基本、構造体代入----");
	Seiseki student3;
	student3 = student2;

	printf("student3.name = %s\n", student3.name);
	printf("&student3 : \t%p\n", &student3);

	puts("\n----------　ポインタの基本、ポインタで構造体代入----");
	Seiseki student4;
	student4 = *pstd2;
	printf("student4.name = %s\n", student4.name);
	printf("&student4 : \t%p\n", &student4);

	puts("\n----------　ポインタの基本、構造体に別名、ポインタの代入----");
	struct seiseki *pstd5;
	pstd5 = pstd2; // 構造体に別名
	printf("pstd5->name = \t%s\n", pstd5->name);
	printf("(*pstd5).name = %s\n", (*pstd5).name);
	printf("pstd5 : \t%p\n", pstd5);

	puts("\n\n----------　構造体メンバーへの参照　----");
	/* 構造体変数そのまま */
	puts("****表示方法１：構造体変数そのまま　student2.number　");
	printf("%04d\t", student2.number);
	printf("%s\t", student2.name);
	printf("%.1f\n", student2.average);

	/* ポインタ＋アロー演算子 */
	puts("\n****表示方法２：ポインタ＋アロー演算子　pstd2->number　");
	printf("%04d\t", pstd2->number);
	printf("%s\t", pstd2->name);
	printf("%.1f\n", pstd2->average);

	/* ポインタ＋間接演算子＋ピリオド */
	puts("\n****表示方法３：ポインタ＋間接演算子＋ピリオド　(*pstd2).number　");
	printf("%04d\t", (*pstd2).number);
	printf("%s\t", (*pstd2).name);
	printf("%.1f\n", (*pstd2).average);

	puts("\n\n\n----------　構造体配列とポインタ　----");
	puts("****ご参考までに****");
	// structarraypointer();

	puts("\n----------　構造体のネストとポインタ 　----");
	// nest();

	printf("\n");
	return 0;
	//////////////////////////////////////////
}

/////////////////////////////////////////
void sort(RECORD *pTeam[TEAMNUM])
{
#define TRUE 1
#define FALSE 0
	RECORD *tmp;
	int idx1, idx2;
	int loop;
	for (idx1 = 1; idx1 < TEAMNUM; idx1++)
	{
		tmp = pTeam[idx1];
		idx2 = idx1 - 1;
		loop = TRUE;
		while (idx2 >= 0 && loop == TRUE)
		{
			if (pTeam[idx2]->average < tmp->average)
			{
				pTeam[idx2 + 1] = pTeam[idx2];
				idx2--;
			}
			else
			{
				loop = FALSE;
			}
		}
		pTeam[idx2 + 1] = tmp;
	}
}

/////////////////////////////////////////
void insertTeams(RECORD *team)
{
	strcpy(team[0].name, "Bishops");
	strcpy(team[1].name, "Kings");
	strcpy(team[2].name, "Jnights");
	strcpy(team[3].name, "Pawns");
	strcpy(team[4].name, "Queens");
	strcpy(team[5].name, "Rooks");
	team[0].wins = 27;
	team[1].wins = 33;
	team[2].wins = 27;
	team[3].wins = 12;
	team[4].wins = 32;
	team[5].wins = 19;
	team[0].losses = 23;
	team[1].losses = 17;
	team[2].losses = 23;
	team[3].losses = 38;
	team[4].losses = 18;
	team[5].losses = 31;
}

/////////////////////////////////////////
void calcAverage()
{
	int i, total;
	insertTeams(team);
	for (i = 0; i < TEAMNUM; i++)
	{
		total = team[i].wins + team[i].losses;
		if (total == 0)
		{
			team[i].average = 0.0;
		}
		else
		{
			team[i].average = (double)(team[i].wins) / total;
		}
	}
}

/////////////////////////////////////////
//****これ以降、ご参考までに****
//----------　構造体配列とポインタ　----
int structarraypointer()
{
	int i;
	insertTeams(team);
	calcAverage();

	RECORD *pt;
	pt = team;

	puts("\n----------　配列名でメンバーを表示　----");
	printf("チーム名   勝ち  負け     勝率\t\t各要素のアドレス\n");
	for (i = 0; i < TEAMNUM; i++)
	{
		printf("%-10s %4d  %4d    %5.3f\t\t%p\n",
			   team[i].name,
			   team[i].wins,
			   team[i].losses,
			   team[i].average,
			   &team[i]);
	}
	puts("\n----------　各メンバーのアドレス　----");
	printf("チーム名\t\t勝ち\t\t\t負け\t\t\t勝率\t\t\t各要素のアドレス\n");
	for (i = 0; i < TEAMNUM; i++)
	{
		printf("%p\t%p\t%p\t%p\t%p\n",
			   &team[i].name,
			   &team[i].wins,
			   &team[i].losses,
			   &team[i].average,
			   &team[i]);
	}

	puts("\n----------　ポインタを利用した構造体配列の表示　----");
	puts("----------　方法１：演算でポインタの位置をずらし、間接演算子を使用　----");
	printf("チーム名   勝ち  負け     勝率\t\tpt+i アドレス\t\tptの位置\n");
	for (i = 0; i < TEAMNUM; i++)
	{
		printf("%-10s %4d  %4d    %5.3f\t\t%p\t%p\n",
			   (*(pt + i)).name,
			   (*(pt + i)).wins,
			   (*(pt + i)).losses,
			   (*(pt + i)).average,
			   pt + i,
			   pt);
	}

	puts("\n----------　方法２：演算でポインタの位置をずらし、アロー演算子を使用　----");
	printf("チーム名   勝ち  負け     勝率\t\tpt+i アドレス\t\tptの位置\n");
	for (i = 0; i < TEAMNUM; i++)
	{
		printf("%-10s %4d  %4d    %5.3f\t\t%p\t%p\n",
			   (pt + i)->name,
			   (pt + i)->wins,
			   (pt + i)->losses,
			   (pt + i)->average,
			   pt + i,
			   pt);
	}

	puts("\n----------　方法３：ポインタの位置を移動しながら、間接演算子を使用　----");
	RECORD *q;
	printf("チーム名   勝ち  負け     勝率\t\tqアドレス\t\tptの位置\n");
	for (q = pt; q < pt + TEAMNUM; q++)
	{
		printf("%-10s %4d  %4d    %5.3f\t\t%p\t%p\n",
			   (*q).name,
			   (*q).wins,
			   (*q).losses,
			   (*q).average,
			   q,
			   pt);
	}

	puts("\n----------　方法４：ポインタの位置を移動しながら、アロー演算子を使用　----");
	printf("チーム名   勝ち  負け     勝率\t\tqアドレス\t\tptの位置\n");
	for (q = pt; q < pt + TEAMNUM; q++)
	{
		printf("%-10s %4d  %4d    %5.3f\t\t%p\t%p\n",
			   q->name,
			   q->wins,
			   q->losses,
			   q->average,
			   q,
			   pt);
	}

	return 0;
}

//----------　構造体のネストとポインタ 　----
int nest(void)
{

	// 構造体のテンプレート（枠型）の宣言
	typedef struct subject // 科目
	{
		int mathematics; // 数学
		int english;	 // 英語
	} SUBJECT;

	typedef struct // 成績
	{
		int number;		 // 番号
		char name[20];	 // 名前
		SUBJECT general; // 一般科目
	} GRADE;

	typedef struct // 成績
	{
		int number;	   // 番号
		char name[20]; // 名前
		SUBJECT *ps;   // 一般科目(ポインタに変更)
	} MARK;

	puts("----------　構造体のメンバーが構造体の場合 　----");
	GRADE student1, *p;

	// アドレスの設定
	p = &student1;

	// 構造体メンバの参照
	p->number = 1;
	strcpy(p->name, "Satou");
	p->general.mathematics = 90;
	p->general.english = 80;

	printf("番号：%d、 名前：%s、 数学：%d、 英語：%d\n",
		   p->number, p->name, p->general.mathematics, p->general.english);

	puts("----------　構造体のメンバーがポインタの場合 　----");
	// 構造体とポインタの宣言
	MARK student2, *p2;
	SUBJECT general; // RECORD型のメンバであるSUBJECTの本体を宣言する
	// アドレスの設定
	p2 = &student2;
	p2->ps = &general; // ネストされた構造体変数にアドレスを設定する
	// 構造体メンバの参照
	p2->number = 2;
	strcpy(p2->name, "Tanaka");
	p2->ps->mathematics = 100;
	p2->ps->english = 70;
	printf("番号：%d、 名前：%s、 数学：%d、 英語：%d\n",
		   p2->number, p2->name, p2->ps->mathematics, p2->ps->english);

	return 0;
}