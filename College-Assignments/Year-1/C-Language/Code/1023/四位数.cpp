#include<stdio.h>
int main()
{
	int a,b,c;
	int a10,a0,b10,b0;
	printf("请输入第一个十位数:");
	scanf("%d",&a);
	printf("请输入第二个十位数:");
	scanf("%d",&b);
	a10=a/10;
	a0=a%10;
	b10=b/10;
	b0=b%10;
	c=a10*1000+b10*100+a0*10+b0;
	printf("组合后四位数为c=%d",c);
	return 0; 
}
