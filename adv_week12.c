#pragma warning(disable : 4996)

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////
#define TEAMNUM 6	  /* チーム数 */
#define MAX_LENGTH 10 /* チーム名の長さの上限 */
// 勝敗情報　の構造体の宣言
typedef struct record
{							   /* 勝敗情報 */
	char name[MAX_LENGTH + 1]; /* チーム名 */
	int wins;				   /* 勝ち数 */
	int losses;				   /* 負け数 */
	double average;			   /* 勝率 */
} RECORD;

// 構造体配列、構造体生成
RECORD team[TEAMNUM];
void insertTeams();
void printTeams();

////////////////////////////////////////////
// ファイルに書き込み
void makeTextFile(char fn[]);
void makeStructFile(char fn[]);

/////////////////////////////////////////
// ファイルから読み込み
int readfile_fgetc(char *fn);
int readfile_fread(char *fn);
int readfile_fread_all(char *fn);

////////////////////////////////////////////

////////////////////////////////////////////

////////////////////////////////////////////
int main()
{
	// puts("\n------whereMyFile();--------");
	// whereMyFile();

	////////////////////////////////////////////
	puts("\n---------------　練習　--------------");

	FILE *fpt;
	fpt = fopen("kadai12.txt", "r");
	if (fpt == NULL)
	{
		puts("fopen失敗");
		return -1;
	}
	else
	{
		puts("fopen成功");
	}

	char q[201];
	char s[3][101];
	char *rstr;
	rstr = fgets(q, 200, fpt);
	if (rstr == NULL)
	{
		puts("fgets失敗");
	}
	else
	{
		printf("問題:%s", q);
	}

	for (int count = 0; count < 3; count++)
	{
		rstr = fgets(s[count], 100, fpt);
		if (rstr == NULL)
		{
			puts("fgets失敗");
		}
	}
	printf("%s%s%s", s[0], s[1], s[2]);
	int ansNo, score;
	int iRet;
	iRet = fscanf(fpt, "%d, %d", &ansNo, &score);
	printf("戻り値iRat:%d\n", iRet);
	printf("正解の番号:%d\n", ansNo);
	printf("配点:%d\n", score);

	fclose(fpt);

	puts("\n\n---------- 前準備：ファイルを作って置く ---------- ");
	insertTeams(team);
	// printTeams();
	puts("文字列とteamをテキストファイルteamText.txtに保存 ");
	makeTextFile("teamText.txt");

	puts("teamをバイナリーファイルteamStructFile.dataに保存 ");
	makeStructFile("teamStructFile.data");

	puts("\n\n--------------- サンプル --------------- ");
	puts("-----fgetsで1行ずつ読み込み----- ");

	FILE *fp;
	char fn[101];
	strcpy(fn, "teamText.txt");

	/* ファイルのオープン */
	fp = fopen(fn, "r");

	if (fp == NULL)
	{
		printf("ファイル開くエラー: %s \n", fn);
		return -1;
	}

	char str[512];
	char *ret;
	/* １行分の文字列を読み込み */
	while ((ret = fgets(str, 512 - 1, fp)) != NULL)
	{
		printf("[%s]\n", str);
	}
	puts("\n");

	fclose(fp);
	///////////////////////////////////////////////

	///////////////////////////////////////////////
	// puts("\n-----テキストファイル----- ");
	// puts("-----関数：readfile_fgetc----- ");
	// puts("-----fgetcで１行ずつ読み込み----- ");
	// readfile_fgetc("teamText.txt");

	///////////////////////////////////////////////
	// puts("\n-----バイナリファイル----- ");
	// puts("-----Teamsの情報を一遍で読み込み----- ");
	// puts("-----関数：readfile_fread_all----- ");
	// readfile_fread("teamStructFile.data");

	// readfile_fread_all("teamStructFile.data");

	printf("\n");
	return 0;
} //////// mainの終り

// テキストファイルを作成/////////////////////////////////////////
void makeTextFile(char fn[])
{
	int a = 100;

	FILE *fp;
	fp = fopen(fn, "w");			   // ファイルを書き込みモード（"w"）で開く
	fprintf(fp, "aは %d です。\n", a); // 「aは100です」と書き込む

	for (int i = 0; i < TEAMNUM; i++)
	{
		fprintf(fp,
				"%s,%d,%d,%f\n",
				team[i].name,
				team[i].wins,
				team[i].losses,
				team[i].average);
	}

	fclose(fp); // ファイルを閉じる
}

// バイナリーファイルを作成//////////////////////////////////////////
void makeStructFile(char fn[])
{
	FILE *fp;

	fp = fopen(fn, "wb");

	for (int i = 0; i < TEAMNUM; i++)
	{
		fwrite(&team[i], sizeof(RECORD), 1, fp);
	}
	fclose(fp);
}

/////////////////////////////////////////
int readfile_fgetc(char *fn)
{
	FILE *fp;

	/* ファイルのオープン */
	if ((fp = fopen(fn, "r")) == NULL)
	{
		printf("ファイル開くエラー: %s \n", fn);
		return -1;
	}

	char ret;
	while (1)
	{
		/* １文字読み込み */
		ret = fgetc(fp);

		if (ret == EOF)
		{
			/* 戻り値がEOFの場合読み込み終了 */
			break;
		}
		printf("%c ", ret);
	}

	// 以下のように書いてもOK
	//  １文字ずつ読み込んで表示する
	while ((ret = fgetc(fp)) >= 0)
	{
		printf("%c ", ret);
	}
	puts("\n");
	fclose(fp);
	return 1;
}

/////////////////////////////////////////
int readfile_fread(char *fn)
{
	FILE *fp;

	/* ファイルのオープン */
	if ((fp = fopen(fn, "rb")) == NULL)
	{
		printf("ファイル開くエラー: %s \n", fn);
		return -1;
	}

	RECORD rTeam;
	size_t n;

	while (1)
	{
		/* sizeof(RECORD)バイト分読み込み */
		n = fread(&rTeam, sizeof(RECORD), 1, fp);

		printf("戻り値n : %d\n", (int)n);

		if (n < 1)
		{
			/* 戻り値が第三引数よりも小さい
			   のでファイルの終端に行き着いた */
			break;
		}

		printf("name : %s\n", rTeam.name);
		printf("wins  :%d\n", rTeam.wins);
		printf("average:%f\n\n", rTeam.average);
	}

	puts("\n");
	fclose(fp);
	return 1;
}

/////////////////////////////////////////
int readfile_fread_all(char *fn)
{
	FILE *fp;

	/* ファイルのオープン */
	if ((fp = fopen(fn, "rb")) == NULL)
	{
		printf("ファイル開くエラー: %s \n", fn);
		return -1;
	}

	RECORD allTeam[100];
	size_t ret_size;

	/* sizeof(RECORD)×TEAMNUM　バイト分読み込み */
	ret_size = fread(allTeam, sizeof(RECORD), TEAMNUM, fp);

	printf("戻り値 ret_size : %d\n", (int)ret_size);
	if (ret_size < TEAMNUM)
	{
		return -1;
	}

	RECORD *pt;
	pt = allTeam;
	// ret_size 個構造体をファイルから読み込んだ

	for (int i = 0; i < ret_size; i++)
	{
		printf("%s %d %f\n",
			   allTeam[i].name, allTeam[i].wins, allTeam[i].average);
	}
	puts("\nもう１回表示：");

	for (int i = 0; i < ret_size; i++)
	{
		printf("name : %s\n", pt->name);
		printf("wins  :%d\n", pt->wins);
		printf("average:%f\n\n", pt->average);
		pt++;
	}
	puts("\n");

	fclose(fp);

	return 1;
}

////////////////////////////////////////////
// 以降書き込み用構造体の生成
void insertTeams()
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

	int i, total;
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
void printTeams()
{
	for (int i = 0; i < TEAMNUM; i++)
	{
		printf("%-10s %6d %6d %8.2f \t%p\n",
			   team[i].name,
			   team[i].wins,
			   team[i].losses,
			   team[i].average,
			   &team[i]);
	}
	puts("\n");
}