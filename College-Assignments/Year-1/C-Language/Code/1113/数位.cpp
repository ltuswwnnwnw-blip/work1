#include<stdio.h>
int main()
{
	int num,temp,count=0;
	printf("输入一个整数");
	scanf("%d",&num);
	if(num==0)
	{
		printf("该数位为1\n");
	}
	temp=(num<0)?-num:num;
	do
	{
		temp=temp/10;
		count++;
	}
	while(temp!=0);
	printf("该数数位为%d\n",count);
}
