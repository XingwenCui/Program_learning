#include<stdio.h>

int main()
{
	int i;
	char ch[5];
	for(i=0;i<5;i++)
	{
		scanf("%c", &ch[i]);
		ch[i] += 4;
	}
	printf("%s",ch);
	return 0;
}
