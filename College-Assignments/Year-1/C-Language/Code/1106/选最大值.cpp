#include<stdio.h>
main()
{
	int a,b,c;
	printf("输入三个任意整数");
	scanf("%d %d %d",&a,&b,&c);
	if(a>b&&a>c)
    printf("MAX=%d",a);
	else
	if(b>a&&b>c)
	printf("MAX=%d",b); 
	else
	if(c>a&&c>b)
	printf("MAX=%d",c);
}
