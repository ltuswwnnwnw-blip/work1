#include<stdio.h>
int main()
{
	char ch;
	int upper,lower,digit,other;
	printf("输入一串字符");
	for(;;)
	{
		ch=getchar();
		if(ch>='A'&&ch<='Z')
		{
			upper++;
		}
		else if(ch>='a'&&ch<='z')
		{
			lower++;
		}
		else if(ch>='0'&&ch<='9')
		{
			digit++;
		}
		else
		{
			other++;
		}
	} 
	printf("大写字母%d个，小写字母%d个，数字%d个，其他%d个",upper,lower,digit,other); 
} 
