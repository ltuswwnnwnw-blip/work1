#include<stdio.h>
int main()
{
	int sum,num,a,b,c;
	printf("输入一个三位数");
	scanf("%d",&num);
	a=num/100;
	b=(num/10)%10;
	c=num%10;
	if(a*a*a+b*b*b+c*c*c==num)
		printf("%d为水仙花",num);
    else
	    printf("%d为非水仙花",num);
	
} 
