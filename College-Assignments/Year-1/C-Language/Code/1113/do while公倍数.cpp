#include<stdio.h>
int main()
{
	int n1,n2,a,b,r,gcd,lcm;
	printf("输入第一个自然数");
	scanf("%d",&n1);
	printf("输入第二个自然数");
	scanf("%d",&n2);
	a=n1;
	b=n2;
	do
	{
		r=a%b;
		a=b;
		b=r;
	}
	while(b!=0);
	gcd=a;
	lcm=n1*n2/gcd;
	printf("%d和%d的最大公约数为:%d\n",n1,n2,gcd);
	printf("%d和%d的最小公倍数为:%d\n",n1,n2,lcm);
	return 0;
}
