#include<stdio.h>
int main()
{
	float n,sum=0;
	int y=0,count=0;
	printf("输入分数");
	for(;;)
	{
	scanf("%f",&n);
	
	if(n<0)
	{break;}
	sum+=n;
	count++;
	if(n<60)
	{y++;}
    
	}
    float ave=sum/count;
    printf("平均成绩为%.2f\n,不及格人数为%d\n",ave,y);
}
