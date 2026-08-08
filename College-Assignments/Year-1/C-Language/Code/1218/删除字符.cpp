#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	char ch;
	int i=0,j=0;
	printf("ÊäÈë×Ö·û´®");
	gets(str);
	printf("ÊäÈë×Ö·û:");
	scanf("%c",&ch);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=ch)
		{
			str[j++]=str[i];
		}
	}
	str[j]='\0';
	printf("%s\n",str);
}
