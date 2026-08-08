#include<stdio.h>
int main()
{
	int a,reverse=0;
	printf("请输入一个四位数:");
	scanf("%d",&a);
	int ge=a%10;
	int shi=(a/10)%10;
	int bai=(a/100)%10;
	int qian=a/1000;
	reverse=ge*1000+shi*100+bai*10+qian;
	printf("反序数为:%d\n",reverse);
	return 0;
}
