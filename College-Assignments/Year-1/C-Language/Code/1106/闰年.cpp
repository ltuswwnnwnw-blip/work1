#include<stdio.h>
main()
{
	int num;
	printf("输入一个数");
	scanf("%d",&num);
	if((num%4==0&&num%100!=0)||(num%400==0))
	{printf("num为闰年",num);}
	else
	{printf("num不为闰年",num);}
}
