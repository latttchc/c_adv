#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>

void func1(int x[], int size);
void func2(int *p, int size);
void func3(const int *p, int size);

int main()
{
	int i;
	puts("\n-----　練習　----");
	char str1[50] = {'a', 'p', 'p', 'l', 'e', '\0', 'a', 'p', 'p', 'l', 'e', '\0'};

	for (i = 0; i < 50; i++)
	{
		printf("%c,", str1[i]);
	}
	printf("\n");

	for (i = 0; i < 50; i++)
	{
		printf("%d,", str1[i]);
	}
	printf("\n");

	printf("%s", str1);

	puts("\n-----　ポインタ　----");

	printf("%c,", str1[0]);
	printf("%p,", &str1[0]);
	printf("%p,", str1);
	printf("\n");

	char *ptr1;
	ptr1 = str1;

	for (i = 0; i < 50; i++)
	{
		printf("%c,", ptr1[i]);
	}
	printf("\n");

	for (i = 0; i < 50; i++)
	{
		printf("%c,", *(ptr1 + i));
	}
	printf("\n");

	puts("\n-----　str2　----");

	char str2[50] = "banana";
	printf("\n");
	printf("%s", str2);

	puts("\n-----　関数　----");

	char str3[3];
	int r;
	r = scanf("%s", str3);
	printf("str3 = %s, r=%d\n", str3, r);

	r = (int)strlen(str1);
	printf("文字列 = %s, 長さ = %d\n", str1, r);

	r = (int)strlen(str2);
	printf("文字列 = %s, 長さ = %d\n", str2, r);

	str3[sizeof(str3) - 1] = '\0';
	r = (int)strlen(str3);
	printf("文字列 = %s, 長さ = %d\n", str3, r);

	strcpy(str2, "orange");
	printf("%s\n", str2);

	printf("\n");
	printf("\n");
	puts("\n-----　課題　----");
	int result, t;
	strcpy(str1, "xyz");
	strcpy(str2, "pineapple");
	for (i = 0; i < 9; i++)
	{
		t = strcmp(&str1[i], &str2[i]);
		result += t;
	}
	// printf("%d\n", result);
	printf("結果は: ");
	if (result == 0)
	{
		printf("%sと%sは等しい", str1, str2);
	}
	else if (result < 0)
	{
		printf("%sが大きい", str2);
	}
	else
	{
		printf("%sが大きい", str1);
	}

	puts("\n---------------------------　配列のアドレス　---------------------");
	int ay[3] = {100, 200, 600};

	printf("ay[0]：%d \n", ay[0]);
	printf("ay[0]のアドレス：%p \n\n", &ay[0]); // 配列の先頭要素のアドレス

	printf("ay[1]：%d \n", ay[1]);
	printf("ay[1]のアドレス：%p \n\n", &ay[1]); // 配列の２番目要素のアドレス

	// 配列a[]の各要素をふつうに呼び出し
	for (i = 0; i < 3; i++)
	{
		printf("ay[ %d ]の値は %d、アドレスは %p \n", i, ay[i], &ay[i]);
	}

	// 配列a[]の各要素をポインタで呼び出し
	for (i = 0; i < 3; i++)
	{
		printf("ay[ %d ]の値は %d、アドレスは %p \n", i, *(ay + i), ay + i);
	}

	// a(配列の先頭要素のアドレス)は配列のアドレスである
	printf("\nayは配列先頭のアドレス ay：\t%p \n", ay);
	printf("ayは配列先頭のアドレス &ay[0]：\t%p \n", &ay[0]);
	printf("\nアドレスayの位置のデータ ay[0]：%d \n", ay[0]);
	printf("アドレスayの位置のデータ *ay：\t%d \n", *ay);

	puts("\n---------------------------　配列とポインタ　---------------------");

	int *ptny; // 先週の内容
	ptny = &ay[0];
	printf("ptny：%p \n", ptny);
	printf("ポインタptnyの指す場所のデータptny[0]：%d \n", ptny[0]);
	printf("ポインタptnyの指す場所のデータ*ptny：%d \n", *ptny);

	printf("ptny[0]：%d \n", ptny[0]);
	printf("ptny[0]のアドレス：%p \n\n", &ptny[0]); // 配列の先頭要素のアドレス

	printf("\nptny[1]：%d \n", ptny[1]);
	printf("ptny[1]のアドレス：%p \n\n", &ptny[1]); // 配列の２番目要素のアドレス

	puts("\n---------------------------　ポインタで配列に別名　---------------------");
	puts("ptnyを設定し直す：");
	ptny = ay; // ptny = &ay[0];と同じ効果

	//(配列の先頭要素のアドレス)を表示
	printf("\nptnyは配列先頭のアドレス %p \n", ptny);
	printf("アドレスayの位置のデータ ptny[0]：%d \n", ptny[0]);
	printf("アドレスayの位置のデータ *ptny：%d \n", *ptny);

	// 配列の各要素をポインタで呼び出し
	for (i = 0; i < 3; i++)
	{
		printf("　ptny[ %d ]のアドレス&ptny[i]は %p、値ptny[i]は %d\n", i, &ptny[i], ptny[i]);
	}
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		printf("　ptny[ %d ]のアドレスptny+iは %p、値*(ptny+i)は %d \n", i, ptny + i, *(ptny + i));
	}

	puts("\n---------------------------　ポインタの演算　---------------------");

	puts("ptnyを設定し直す：ptny = ay;");
	ptny = ay; // ptny = &ay[0];と同じ効果
	printf("ptny：%p \n", ptny);
	printf("ポインタptnyの指す場所のデータ*ptny：%d \n", *ptny);
	printf("ポインタptnyの指す場所のデータptny[0]：%d \n\n", ptny[0]);

	ptny++; // ポインタが箱１個分移動
	puts("ptny++後：");
	printf("ptny：%p \n", ptny);
	printf("ポインタptnyの指す場所のデータ*ptny：%d \n", *ptny);
	printf("ポインタptnyの指す場所のデータptny[0]：%d \n\n", ptny[0]);

	puts("ptnyを設定し直す：ptny = ay;");
	ptny = ay;
	printf("ptny+1後： \n");
	printf("ptny：%p ==>ポンタptnyが動いていない。\n", ptny);
	printf("ポインタptnyの指す場所のデータ*ptny：%d \n", *ptny);
	printf("ポインタptnyから箱1個分をずらした場所(ptny+1)のアドレス：%p \n", ptny + 1);
	printf("ポインタptnyから箱1個分をずらした場所*(ptny+1)のデータ：%d \n", *(ptny + 1));
	printf("ay：%p \n", ay);

	puts("\n---------------------------　ポインタを関数の引数に　---------------------");
	//	ay[3] = { 100, 200, 600 }

	func1(ay, 3);

	func2(ay, 3);

	func3(ay, 3);

	//////////////////////////////////////////
}

void func1(int x[], int size)
{
	int i;
	puts("\n関数 func1 が受け取った配列： int x[]");
	for (i = 0; i < size; i++)
		printf("  %d", x[i]);
	printf("\n");
}

void func2(int *p, int size)
{
	int i;
	puts("\n関数 func2 が受け取った配列： int* p");
	for (i = 0; i < size; i++)
		printf("  %d", p[i]);
	printf("\n");
}

void func3(const int *p, int size)
{
	int i;
	puts("\n関数 func3 が受け取った配列： const int* p");
	for (i = 0; i < size; i++)
		printf("  %d", *(p + 1));
	printf("\n");
}
