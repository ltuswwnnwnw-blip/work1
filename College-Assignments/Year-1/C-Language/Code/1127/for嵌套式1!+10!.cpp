#include<stdio.h>
int main()
{
	int sum=0;
	for(int i=1;i<=10;i++)
	{
		int fact=1;
		for(int j=1;j<=i;j++)
		{
			fact*=j;
		}
		sum+=fact;
	}
	printf("1!+2!+3!....+10!=%d\n",sum);
}
