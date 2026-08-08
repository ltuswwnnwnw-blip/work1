#include<stdio.h>
main()
{
	char ch;
	printf("请输入一个小写字母:");
	scanf("%c",&ch);
	ch=ch-32; 
	printf("%c\n",ch);
}
