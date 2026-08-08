#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	printf("输入一行字母");
	scanf("%s",str);
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]>='a'&&str[i]<='z')
		{
		str[i]-=32;
		}
	}
	printf("大写转化为：%s",str);
}
