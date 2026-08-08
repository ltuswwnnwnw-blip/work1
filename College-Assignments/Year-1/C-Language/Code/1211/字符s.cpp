#include<stdio.h>
int main()
{
	char str[100];
	int i=0;
	printf("ÊäÈë×Ö·û´®:");
	gets(str);
	while(str[i]!='\0')
	{
		if(str[i]>='a'&&str[i]<='z')
		{
			str[i]-=32;
		}
		i++;
	}
	printf("%s\n",str);
}
