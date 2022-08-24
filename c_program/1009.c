#include<stdio.h>
#include<string.h>

int main() 
{
	char str[6]; //Not more than 5 number, so char len is 6
	scanf("%s",str);

	int len = strlen(str);
	printf("%d\n",len);
	for(int i = 0; i < len; i++)
	{
		printf("%c ",str[i]);
	}
	printf("\n");
	for (int i = len-1; i>=0; i--)
	{
		printf("%c ",str[i]);
	}
	return 0;


}

