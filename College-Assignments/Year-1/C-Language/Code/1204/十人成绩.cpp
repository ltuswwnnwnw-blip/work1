#include<stdio.h>
int main()
{
	int x[10];
	int i;
	for(i=0;i<10;i++)
	{
		printf("输入第%d个元素值",i+1);
		scanf("%d",&x[i]);
	}
	printf("十名同学成绩：");
	for(i=0;i<10;i++)
	{
		printf("%-5d",x[i]);
	}
	//printf("\n");
}
