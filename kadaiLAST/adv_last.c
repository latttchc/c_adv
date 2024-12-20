#pragma warning(disable : 4996)

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QNUM 6

typedef struct
{
	char q[256];
	char choises[3][128];
	int ansNo;
	int score;
} Quiz;

////////////////////////////////////////////

////////////////////////////////////////////
int main()
{
	Quiz quiz[MAX_QNUM];
	FILE *fp;
	int i, j, u_ansewer, u_score;
	fp = fopen("kadaiLAST_utf8.txt", "r");
	// utf-8のtxtファイルを読み込む
	if (fp == NULL)
	{
		printf("ファイル開けません");
		return 1;
	}

	while (i < MAX_QNUM && fgets(quiz[i].q, sizeof(quiz[i].q), fp) != NULL)
	{
		for (int j = 0; j < 3; j++)
		{
			fgets(quiz[i].choises[j], sizeof(quiz[i].choises[j]), fp);
		}
		fscanf(fp, "%d,%d\n", &quiz[i].ansNo, &quiz[i].score);
		i++;
	}
	fclose(fp);

	puts("--------クイズを答えてください。--------");
	for (i = 0; i < MAX_QNUM; i++)
	{
		printf("問題: %s\n", quiz[i].q);
		for (int j = 0; j < 3; j++)
		{
			printf("%s\n", quiz[i].choises[j]);
		}
		printf("1~3から正解を入力してください:");
		scanf("%d", &u_ansewer);
		if (quiz[i].ansNo == u_ansewer)
		{
			printf("正解!!\n\n");
			u_score += quiz[i].score;
		}
		else
		{
			printf("不正解😭 正解は %d でした...\n\n", quiz[i].ansNo);
		}
	}
	printf("あなたの得点は...%d/100でした!", u_score);
	return 0;
	////////////////////////////////////////////
} // main
