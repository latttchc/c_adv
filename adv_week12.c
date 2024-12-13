#pragma warning(disable:4996) 

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////
#define TEAMNUM 6		/* �`�[���� */
#define MAX_LENGTH 10	/* �`�[�����̒����̏�� */
//���s���@�̍\���̂̐錾
typedef struct record {			/* ���s��� */
	char   name[MAX_LENGTH + 1];/* �`�[���� */
	int    wins;				/* ������ */
	int    losses;				/* ������ */
	double average;				/* ���� */
} RECORD;

//�\���̔z��A�\���̐���
RECORD team[TEAMNUM];
void insertTeams();
void printTeams();

////////////////////////////////////////////
//�t�@�C���ɏ�������
void makeTextFile(char fn[]);
void makeStructFile(char fn[]);

/////////////////////////////////////////
//�t�@�C������ǂݍ���
int readfile_fgetc(char* fn);
int readfile_fread(char* fn);
int readfile_fread_all(char* fn);

////////////////////////////////////////////

////////////////////////////////////////////

////////////////////////////////////////////
int main()
{
	//puts("\n------whereMyFile();--------");
	//whereMyFile();

	////////////////////////////////////////////
	puts("\n---------------�@���K�@--------------");






	puts("\n\n---------- �O�����F�t�@�C��������Ēu�� ---------- ");
	insertTeams(team);
	//printTeams();
	puts("�������team���e�L�X�g�t�@�C��teamText.txt�ɕۑ� ");
	makeTextFile("teamText.txt");

	puts("team���o�C�i���[�t�@�C��teamStructFile.data�ɕۑ� ");
	makeStructFile("teamStructFile.data");


	puts("\n\n--------------- �T���v�� --------------- ");
	puts("-----fgets�łP�s���ǂݍ���----- ");

	FILE* fp;
	char fn[101];
	strcpy(fn, "teamText.txt");

	/* �t�@�C���̃I�[�v�� */
	fp = fopen(fn, "r");

	if (fp == NULL) {
		printf("�t�@�C���J���G���[: %s \n", fn);
		return -1;
	}

	char str[512];
	char *ret;
	/* �P�s���̕������ǂݍ��� */
	while ((ret = fgets(str, 512-1, fp)) != NULL) {
		printf("[%s]\n", str);
	}
	puts("\n");

	fclose(fp);
	///////////////////////////////////////////////


	///////////////////////////////////////////////
	//puts("\n-----�e�L�X�g�t�@�C��----- ");
	//puts("-----�֐��Freadfile_fgetc----- ");
	//puts("-----fgetc�łP�s���ǂݍ���----- ");
	//readfile_fgetc("teamText.txt");


	///////////////////////////////////////////////
	//puts("\n-----�o�C�i���t�@�C��----- ");
	//puts("-----Teams�̏�����Ղœǂݍ���----- ");
	//puts("-----�֐��Freadfile_fread_all----- ");
	//readfile_fread("teamStructFile.data");
	
	//readfile_fread_all("teamStructFile.data");

	printf("\n");
	return 0;
}//////// main�̏I��


//�e�L�X�g�t�@�C�����쐬/////////////////////////////////////////
void makeTextFile(char fn[]) {
	int a = 100;

	FILE* fp;
	fp = fopen(fn, "w");	//�t�@�C�����������݃��[�h�i"w"�j�ŊJ��
	fprintf(fp, "a�� %d �ł��B\n", a);	//�ua��100�ł��v�Ə�������

	for (int i = 0; i < TEAMNUM; i++) {
		fprintf(fp,
			"%s,%d,%d,%f\n",
			team[i].name,
			team[i].wins,
			team[i].losses,
			team[i].average
		);
	}
	

	fclose(fp);		//�t�@�C�������
}

//�o�C�i���[�t�@�C�����쐬//////////////////////////////////////////
void makeStructFile(char fn[]) {
	FILE* fp;

	fp = fopen(fn, "wb");

	for (int i = 0; i < TEAMNUM; i++) {
		fwrite(&team[i], sizeof(RECORD), 1, fp);
	}
	fclose(fp);
}

/////////////////////////////////////////
int readfile_fgetc(char* fn) {
	FILE* fp;

	/* �t�@�C���̃I�[�v�� */
	if ((fp = fopen(fn, "r")) == NULL) {
		printf("�t�@�C���J���G���[: %s \n", fn);
		return -1;
	}

	char ret;
	while (1) {
		/* �P�����ǂݍ��� */
		ret = fgetc(fp);

		if (ret == EOF) {
			/* �߂�l��EOF�̏ꍇ�ǂݍ��ݏI�� */
			break;
		}
		printf("%c ", ret);
	}

	//�ȉ��̂悤�ɏ����Ă�OK
	// �P�������ǂݍ���ŕ\������
	while ((ret = fgetc(fp)) >= 0) {
		printf("%c ", ret);
	}
	puts("\n");
	fclose(fp);
	return 1;
}


/////////////////////////////////////////
int readfile_fread(char* fn) {
	FILE* fp;

	/* �t�@�C���̃I�[�v�� */
	if ((fp = fopen(fn, "rb")) == NULL) {
		printf("�t�@�C���J���G���[: %s \n", fn);
		return -1;
	}

	RECORD rTeam;
	size_t n;

	while (1) {
		/* sizeof(RECORD)�o�C�g���ǂݍ��� */
		n = fread(&rTeam, sizeof(RECORD), 1, fp);

		printf("�߂�ln : %d\n", (int)n);

		if (n < 1) {
			/* �߂�l����O��������������
			   �̂Ńt�@�C���̏I�[�ɍs�������� */
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
int readfile_fread_all(char* fn) {
	FILE* fp;

	/* �t�@�C���̃I�[�v�� */
	if ((fp = fopen(fn, "rb")) == NULL) {
		printf("�t�@�C���J���G���[: %s \n", fn);
		return -1;
	}

	RECORD allTeam[100];
	size_t ret_size;

	/* sizeof(RECORD)�~TEAMNUM�@�o�C�g���ǂݍ��� */
	ret_size = fread(allTeam, sizeof(RECORD), TEAMNUM, fp);

	printf("�߂�l ret_size : %d\n", (int)ret_size);
	if (ret_size < TEAMNUM) {
		return -1;
	}

	RECORD* pt;
	pt = allTeam;
	// ret_size �\���̂��t�@�C������ǂݍ���

	for (int i = 0; i < ret_size; i++) {
		printf("%s %d %f\n", 
			allTeam[i].name, allTeam[i].wins, allTeam[i].average);
	}
	puts("\n�����P��\���F");

	for (int i = 0; i < ret_size; i++) {
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
//�ȍ~�������ݗp�\���̂̐���
void insertTeams() {
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
	for (i = 0; i < TEAMNUM; i++) {
		total = team[i].wins + team[i].losses;
		if (total == 0) {
			team[i].average = 0.0;
		}
		else {
			team[i].average = (double)(team[i].wins) / total;
		}
	}
}

/////////////////////////////////////////
void printTeams() {
	for (int i = 0; i < TEAMNUM; i++) {
		printf("%-10s %6d %6d %8.2f \t%p\n",
			team[i].name,
			team[i].wins,
			team[i].losses,
			team[i].average,
			&team[i]
		);
	}
	puts("\n");
}