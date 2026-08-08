#include<stdio.h>
main()
{
	int w;
	printf("输入第一个数:");
	scanf("%d",&w); 
	printf("%d",w>=10000?w/10000:w>=1000?w%1000:w>=100?w%100:w%10); 
}
