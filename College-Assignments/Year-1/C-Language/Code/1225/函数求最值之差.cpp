#include<stdio.h>
int findmax(int a,int b,int c)
{
	int max=a;
	if(b>max)max=b;
	if(c>max)max=c;
	return max;	
}
int findmin(int a,int b,int c)
{
	int min=a;
	if(b<min)min=b;
	if(c<min)min=c;
	return min;
}
int getdiff(int max,int min)
{
	return max-min;
}
int main()
{
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	int max1=findmax(x,y,z);
	int min1=findmin(x,y,z);
	int diff=getdiff(max1,min1);
	printf("max1-min1=%d\n",diff);
}
