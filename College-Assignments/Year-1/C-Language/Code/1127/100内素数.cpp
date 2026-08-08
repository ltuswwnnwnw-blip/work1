#include<stdio.h>
int main()
{
	int count=0;
	printf("100ÒÔÄÚËØÊı:");
	for(int num=2;num<100;num++)
	{
		int flat=1;
		for(int i=2;i*i<=num;i++)
		{
			if(num%i==0)
			{
			flat=0;break;
			}
		}
		if(flat)
		{
			printf("%-3d",num);
			count++;
			if(count%10==0)
			{printf("\n");
			}
		}
	}
}
