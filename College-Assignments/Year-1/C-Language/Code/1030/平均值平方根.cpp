#include<stdio.h>
#include<math.h>
main()
{
	float a,b,ave,aroot,broot;
	printf("输入两个整数:");
	scanf("%d %d",&a,&b);
	ave=(a+b)/2;
	aroot=sqrt(a);
	broot=sqrt(b);
	printf("两数平均值为:%f",ave);
	printf("平方根各为:%f,%f",aroot,broot);
	
}
