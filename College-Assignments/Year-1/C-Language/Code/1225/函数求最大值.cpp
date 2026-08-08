#include<stdio.h>
int g(int v[5],int len)
{
	int max=v[0];
	for(int i=1;i<len;i++)
	{
		if(v[i]>max)
		{
			max=v[i];
		}
	}
	return max;
}
int main()
{
	int num[5]; 
	for(int i=0;i<5;i++)
	{
		printf("输入第%d个整数:",i+1);
		scanf("%d",&num[i]);
	}
	int max2=g(num,5);
	printf("最大值为:%d\n",max2);
}
