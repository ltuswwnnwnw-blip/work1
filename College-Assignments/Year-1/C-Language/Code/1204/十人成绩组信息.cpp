#include<stdio.h>
int main()
{
	int a[10],i; 
	int sum=0;
	float avg;
	int max,min;
	for(i=0;i<10;i++)
	{
		printf("输入第%d个成绩:",i+1);
		scanf("%d",&a[i]);
	}
	for(i=0;i<10;i++)
	{
		sum+=a[i];
	}
	max=a[0];
	min=a[0];
	for(i=1;i<10;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
		if(a[i]<min)
		{
			min=a[i];
		}
	}
	avg=sum/10;
	printf("sum=%d\n avg=%2.f\n max=%d\n min=%d\n",sum,avg,max,min );
}
