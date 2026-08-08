#include<stdio.h>
#include<math.h>
int main()
{
	int i,n;
	double sum,x,y;
	printf("输入一个数:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		double x=pow(-1,i+1);
		double y=3*i-2;
		sum+=x/y;
	}
	printf("前%d项之和为:%.6f",n,sum);
}
