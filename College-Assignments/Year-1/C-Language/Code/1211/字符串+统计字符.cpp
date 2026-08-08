#include<stdio.h>
int main()
{
	char str[80];
	char ch,t;
	int count=0,i=0;
	printf("输入字符串");
	while((ch=getchar())!='\n'&&i<79)
	{
		str[i]=ch;
		i++;
	}
	str[i]='\0';
	printf("输入统计字符");
	scanf("%c",&t);
	for(int j=0;str[j]!='\0';j++)
	{
		if(str[j]==t)
		{
			count++;
		}
	}
	printf("字符%c出现了%d次\n",t,count);
	printf("%s\n",str);
}
