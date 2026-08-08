#include<stdio.h>
int main()
{
	char ch;
	int num=0,word=0,other=0;
	printf("输入一串字符");
	ch=getchar();
	while(ch!='\n')
	{
		if(ch>='0'&&ch<='9')
		{
			num++;
		}
		else if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		{
			word++;
		}
		else
		{
			other++;
		}
		ch=getchar();
	}
	printf("字母个数%d,数字个数%d,其他字符个数%d",num,word,other);
}
