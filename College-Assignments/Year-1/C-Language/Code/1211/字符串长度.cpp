#include<stdio.h>
int main()
{
	char str[100];
	int len=0,i=0;
	scanf("%s",str);
	while(str[i]!='\0')
	{
		len++;
		i++;
	}
	printf("×Ö·û´®³¤¶ÈÎª:%d\n",len);
//	printf("%s\n",str);
}
