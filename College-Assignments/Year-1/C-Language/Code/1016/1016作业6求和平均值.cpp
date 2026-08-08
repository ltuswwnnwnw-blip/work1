#include<stdio.h>
main()
{
	int a,b,sum,ave;
	printf("请输入第一个数");
	scanf("%d",&a);
	printf("请输入第二个数");
	scanf("%d",&b); 
	sum=a+b;
	ave=sum/2;
	printf("sum=%d\nave=%d",sum,ave);
}
