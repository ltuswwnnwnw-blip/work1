#include<stdio.h>
int main()
{
	int a,b;
	int *p1=&a,*p2=&b;
	int temp;
	printf("输入数一");
	scanf("%d",p1);
	printf("输入数二");
	scanf("%d",p2);
	if(*p1<*p2)
	{
		temp=*p1;
		*p1=*p2;
		*p2=temp;
	} 
	printf("从大到小输出:%d,%d\n",*p1,*p2);
}
