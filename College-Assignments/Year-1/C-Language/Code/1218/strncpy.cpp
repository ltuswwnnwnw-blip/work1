#include<stdio.h>
#include<string.h>
int main()
{
	char str1[10]="abcdefg",str2[]="ABCDEF";
	strncpy(str1,str2,2);
	puts(str1);
}
