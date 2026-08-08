#include<stdio.h>
int main()
{
	int a=8;
	int *pa=&a;
	printf("a地址=%08X,pa地址 =%08X\n",&a,&pa);
	printf("a内容=%d,pa内容=%08X\n",a,pa);
	printf("a=%d,*pa=%d\n",a,*pa);
	a=16;
	printf("a=%d,*pa=%d\n",a,*pa);
	*pa=256;
	printf("a=%d,*pa=%d\n",a,*pa);
}

