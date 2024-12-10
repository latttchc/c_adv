#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	int i;
	puts("\n-----　練習　----");
	int a = 100;
	printf("a = %d\n", a);
	printf("アドレス:%p\n", &a);
	printf("int型のサイズ:%d\n", (int)sizeof(int));

	int *pa;
	pa = &a;
	printf("pa =%p\n", pa);

	printf("*pa : %d\n", *pa);

	*pa = 999;
	printf("*pa : %d\n", *pa);
	printf("a = %d\n", a);

	printf("ポインタのサイズ:%d\n", (int)sizeof(pa));
	//////////////////////////////

	char c;
	c = 'z';
	printf("c = %c\n", c);
	printf("アドレス :%p\n", &c);
	printf("int型のサイズ:%d\n", (int)sizeof(char));

	printf("ポインタのサイズ:%d\n", (int)sizeof(&c));

	char *pc;
	pc = &c;
	printf("pc = %p\n", pc);

	*pc = 'w';
	printf("c = %c\n", c);

	puts("\n-----　課題　----");
	// 1
	puts("int型変数x:宣言,100を代入");
	int x = 100;
	// 2
	puts("int型変数y:宣言,200を代入");
	int y = 200;
	// 3
	printf("x = %d, y = %d\n", x, y);
	// 4
	printf("x = %p, y = %p\n", &x, &y);
	// 5
	puts("int型変数のアドレスを保存用のポインタpt1,pt2を宣言");
	int *pt1, *pt2;
	// 6
	pt1 = &x;
	printf("x = %d\n", *pt1);
	x *= 10;
	printf("xの10倍 = %d\n", *pt1);
	// 7
	pt2 = &y;
	printf("y = %d\n", *pt2);
	// 8
	pt2 = &x;
	printf("x = %d", *pt2);

	puts("\n--------------------------　アドレス　----------------------");
	int xa;

	xa = 1234;

	printf("変数axの値は %d 、アドレスは %p です。\n", xa, &xa);

	puts("\n---------------------------　ポインタ　---------------------");
	int va;
	int *vb; // ポインタの宣言

	va = 1234;
	vb = &va; // ポインタbに変数aのアドレスを代入

	printf(" %p \n", vb);  // 変数aのアドレスが表示される
	printf(" %d \n", *vb); // 変数aの　中身　が表示される

	puts("\n---------------------------　配列のアドレス　---------------------");
	int ay[3] = {100, 200, 600};

	// 配列a[]の各要素をふつうに呼び出し
	for (i = 0; i < 3; i++)
	{
		printf("ay[ %d ]の値は %d、アドレスは %p \n", i, ay[i], &ay[i]);
	}

	// a(配列の先頭要素のアドレス)を表示
	printf("\n ayは %p \n\n", ay);

	// 配列a[]の各要素をポインタ呼び出し
	for (i = 0; i < 3; i++)
	{
		printf("ay[ %d ]の値は %d、アドレスは %p \n", i, *(ay + i), ay + i);
	}
}
