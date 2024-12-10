#pragma warning(disable : 4996)

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10 /* チーム名の長さの上限 */

typedef struct record
{							   /* 勝敗情報 */
	char name[MAX_LENGTH + 1]; /* チーム名 */
	int wins;				   /* 勝ち数 */
	int losses;				   /* 負け数 */
	double average;			   /* 勝率 */
} RECORD;

// 引数にポイントを指定
void swap1(int x, int y);
void swap2(int *x, int *y);

/////////////////////////////////////////
// 引数に配列の指定方法
void setArr1(int arr[5], int initValue, int count);
void setArr11(int[5], int, int);

void setArr2(int arr[], int initValue, int count);
void setArr22(int[], int, int);

void setArr3(int *arr, int initValue, int count);
void printArr(int *, int);
void printArr_address(int *, int);
/////////////////////////////////////////
// 戻り値がポイント時の指定方法
int *tripleArr(int *arr, int count);

/////////////////////////////////////////
// 引数に文字列（char配列）の指定方法
void printString1(char str[200]);
void printString2(char str[]);
void printString3(char *str);

/////////////////////////////////////////
// 関数と構造体
void struct_function(void);
//
void printRecord_1(RECORD data);
void printRecord_11(RECORD data);
void printRecord_111(struct record data);
void printRecord_2(RECORD *p);
void changeRecord(RECORD *, int, int);
// 戻り値に構造体
RECORD createTeam(const char *name, int w, int l);
struct record createTeam2(const char *name, int w, int l);

// 練習用　関数のプロトタイプ
void calc(int x, int y, int *pwa, int *psa)
{
	*pwa = x + y;
	*psa = x - y;
}

////////////////////////////////////////////
int main()
{
	int a = 3, b = 4;
	int koma[] = {8, 5, 9, 2, 3, 6, 7, 1};
	// 文字列の初期化
	char msg1[50] = {'a', 'p', 'p', 'l', 'e', '\0', 'a', 'p', 'p', 'l', 'e', '\0'};
	char msg2[50] = "banana";
	char msg3[] = "orange_orange";

	char msg4[6];
	msg4[0] = 'H';
	msg4[1] = 'e';
	msg4[5] = '\0';

	////////////////////////////////////////////
	puts("\n---------------　練習　--------------");
	int c;
	int wa, sa;
	calc(a, b, &wa, &sa);
	printf("計算の結果 wa = %d, sa = %d\n", wa, sa);
	puts("\n\n\n---------- サンプル ---------- ");
	puts("---------- 引数の 値渡し、ポインタ渡し ---------- ");
	int vx = 100, vy = 200;
	printf("vx = %d, vy = %d \n", vx, vy);
	swap1(vx, vy);
	printf("swap1(vx, vy)を呼び出した後：\tvx = %d, vy = %d \n", vx, vy);

	swap2(&vx, &vy);
	printf("swap2(&vx, &vy)を呼び出した後：\tvx = %d, vy = %d \n", vx, vy);

	////////////////////////////////////////////
	puts("\n---------- 配列を引数に指定 ---------- ");
	int arr[5] = {0};

	printf("mainに：定義した配列arrの大きさsizeof(arr) = %d\n", (int)sizeof(arr));
	printf("ポインタの大きさsizeof(*int) = %d\n", (int)sizeof(&a));

	printArr(arr, 5); // 配列へのポインタを引数に指定
					  // 配列名を書くだけで配列の先頭アドレスを渡せること
	setArr1(arr, 123, 5);
	printArr(arr, 5);

	setArr2(arr, 456, 5);
	printArr(arr, 5);

	setArr3(arr, 789, 5);
	printArr_address(arr, 5);

	////////////////////////////////////////////
	puts("\n---------- 配列のポインタを戻り値として返す ---------- ");
	printf("元の配列の内容：\t");
	printArr(koma, 8);

	int *x;
	x = tripleArr(koma, 8);
	printf("関数呼び出す後：\t");
	printArr(koma, 8);
	printf("関数戻り値のポインタ：\t");
	printArr(x, 8);

	////////////////////////////////////////////
	puts("\n---------- 文字列を引数に指定 ---------- ");
	printString1(msg3); // void printString1(char str[200]);
	printString2(msg3); // void printString2(char str[]);
	printString3(msg3); // void printString3(char* str);

	puts("文字列の初期化方法、定義方法によって、動きが異なる。");
	puts("定義後：");
	printf("msg1：%s\n", msg1);
	printf("msg2：%s\n", msg2);
	printf("msg3：%s\n", msg3);
	printf("msg4：%s\n", msg4);

	puts("変更後：");
	strcpy(msg1, "abc");
	strcpy(msg2, "abc");
	strcpy(msg3, "abc");
	strcpy(msg4, "abc");
	printf("msg1：%s\n", msg1);
	printf("msg2：%s\n", msg2);
	printf("msg3：%s\n", msg3);
	printf("msg4：%s\n", msg4);

	/////////////////////////////////////////
	puts("\n\n\n---------- 構造体が引数、戻り値として利用する場合 ---------- ");
	// struct_function();

	printf("\n");
	return 0;
} //////// mainの終り

/////////////////////////////////////////
void swap1(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}

void swap2(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/////////////////////////////////////////
// 配列と関数
void setArr1(int arr[5], int initValue, int count)
{
	printf("setArr関数内: 渡された%p\n", arr);
	printf("setArr関数内:引数で渡されたデータの大きさsizeof(arr) = %d\n", (int)sizeof(arr));

	for (int i = 0; i < count; i++)
	{
		arr[i] = initValue;
	}
}

void setArr11(int arr[5], int initValue, int count)
{
	setArr1(arr, initValue, count);
}

void setArr2(int arr[], int initValue, int count)
{
	setArr1(arr, initValue, count);
}

void setArr22(int arr[], int initValue, int count)
{
	setArr3(arr, initValue, count);
}

void setArr3(int *arr, int initValue, int count)
{
	int i;
	printf("setArr〇関数内: 渡された%p\n", arr);
	printf("setArr〇関数内:引数で渡されたデータの大きさsizeof(arr) = %d\n", (int)sizeof(arr));

	for (i = 0; i < count; i++)
	{
		arr[i] = initValue;
	}

	// もう一つの書き方
	for (i = 0; i < count; i++)
	{
		*(arr + i) = initValue;
	}
}

////////////////////////////////////////////
void printArr(int *arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d,  ", arr[i]);
	}
	printf("\n\n");
}

void printArr_address(int *arr, int count)
{

	for (int i = 0; i < count; i++)
	{
		printf("%d,\t%p \n", arr[i], &arr[i]);
	}
	printf("\n\n");
}

////////////////////////////////////////////
void printString1(char str[200])
{
	printf("void printString1(char str[200]);の結果：%s\n", str);
}

void printString2(char str[])
{
	printf("void printString2(char str[]);の結果：%s\n", str);
}

void printString3(char *str)
{
	printf("void printString3(char* str);の結果：%s\n", str);
}

////////////////////////////////////////////

int *tripleArr(int *arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		*(arr + i) = *(arr + i) * 3;
	}

	return arr;
}

// これ以降、構造体と関数////////////////////////////////
// 構造体と関数//////////////////////////////////////////
void struct_function(void)
{
	puts("---------- 構造体が引数、戻り値として利用する場合 ---------- ");
	RECORD teamA;
	strcpy(teamA.name, "Queens");
	teamA.wins = 32;
	teamA.losses = 18;

	printRecord_1(teamA);
	printRecord_11(teamA);
	printRecord_111(teamA);

	RECORD teamB = {"Rooks", 19, 31, 0};
	struct record teamBB = {"teamB", 20, 20, 0};
	printRecord_2(&teamB);
	printRecord_2(&teamBB);
	changeRecord(&teamBB, 1, 0);
	printRecord_2(&teamBB);

	RECORD teamC;
	teamC = createTeam("Kings", 33, 17);
	printRecord_1(teamC);

	teamC = createTeam2("teamC", 33, 17);
	printRecord_1(teamC);

	struct record teamCC;
	teamCC = createTeam2("teamCC", 30, 30);
	printRecord_1(teamCC);

	typedef struct record TTTT;
	TTTT teamD;
	teamD = createTeam2("teamD", 30, 30);
	printRecord_1(teamD);

	puts("\n---------- 構造体戻り値の標準ライブラリ関数 ---------- ");
	puts("---------- localtime関数 ---------- ");

	time_t tt;
	struct tm *today;

	tt = time(NULL);
	today = localtime(&tt);
	char *wday[] = {"日", "月", "火", "水", "木", "金", "土"};

	printf("%4d年%2d月%2d日 %s %2d時%2d分%2d秒 \n",
		   today->tm_year + 1900, today->tm_mon,
		   today->tm_mday, wday[today->tm_wday],
		   today->tm_hour, today->tm_min,
		   today->tm_sec);
}

////////////////////////////////////////////
void printRecord_1(RECORD data)
{
	printf("[チーム名]:\t%s\n", data.name);
	printf("[勝ち数]:\t%d\n", data.wins);
	printf("[負け数]:\t%d\n", data.losses);

	int total = data.wins + data.losses;
	if (total == 0)
	{
		data.average = 0.0;
	}
	else
	{
		data.average = (double)(data.wins) / total;
	}
	printf("[勝  率]:\t%3.2f\n\n", data.average);
}
////////////////////////////////////////////
void printRecord_11(RECORD data)
{
	printRecord_2(&data);
}

void printRecord_111(struct record data)
{
	printRecord_2(&data);
}

////////////////////////////////////////////
void printRecord_2(RECORD *p)
{
	printf("[チーム名]:\t%s\n", p->name);
	printf("[勝ち数]:\t%d\n", p->wins);
	printf("[負け数]:\t%d\n", p->losses);

	int total = p->wins + p->losses;
	if (total == 0)
	{
		p->average = 0.0;
	}
	else
	{
		p->average = (double)(p->wins) / total;
	}
	printf("[勝  率]:\t%3.2f\n\n", p->average);
}

void changeRecord(RECORD *p, int wNew, int lNew)
{
	p->wins += wNew;
	(*p).losses += lNew;
	printf("勝ち数: %d回、負け数: %d回 増えました。\n", wNew, lNew);
}

////////////////////////////////////////////
// 構造体が戻り値に指定
RECORD createTeam(const char *name, int w, int l)
{
	RECORD t;
	strcpy(t.name, name);
	t.wins = w;
	t.losses = l;

	return t;
}

struct record createTeam2(const char *name, int w, int l)
{
	RECORD t;
	strcpy(t.name, name);
	t.wins = w;
	t.losses = l;

	return t;
}