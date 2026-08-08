#include<stdio.h>
int main()
{
	int a[20];
	int b;
	a[0]=1;
	a[1]=1;
	for(b=2;b<20;b++)
	{
		a[b]=a[b-1]+a[b-2];
	}
	printf("斐波拉契数列前20项:\n");
    for(b=0;b<20;b++)
    {
    	printf("%5d",a[b]);
    	if((b+1)%5==0)
    	{
    		printf("\n");
    	}
    }
}
