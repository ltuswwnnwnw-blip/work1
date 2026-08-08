#include<stdio.h>
int main()
{
	int num,a,b,c;
	printf("输入一个三位数");
	scanf("%d",&num);
	if(num<100||num>999)
	printf("输入错误");
    a=num/100;
	b=(num/10)%10;
	c=num%10;
	if(a<b&&b<c)
	printf("%d升序数",num);
	else
	printf("%d不为升序数",num);
}
