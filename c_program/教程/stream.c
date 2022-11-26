#include<stdio.h>

int main()
{
	int flag;
	printf("Input flag: ");
	scanf("%d" ,& flag);
	if(flag>=90)
	{
		printf("GOOD\n");
	}
	else if(flag>=60)
	{
		printf("pass\n");
	}
	else
	{
		printf("failed\n");
	}

	//swicth
	switch(flag)
	{	
		case 60:printf("haoxian");break;
		case 59:printf("what a pity!");break;
		default:printf("hahaha");	break;
	}

	//while
	int i = 0;
	while (i++<20)// i++ will increment after expression calculate
	{
		printf("count %d\n",i);
	}
	
	//do while
	int j = 0;
	do 
	{
		printf("count %d\n",j);
	} while(++j<20);

	//foor loop
	int e;
	for (e = 0; e<20;e++)
	{
		printf("count is %d\n",e);
	}
	//continue
	int n = 0;
	int sum = 0;
	for (n = 0; n < 100; n++)
	{
		if(n%2!=0)
		{
			continue;
		}
		sum=sum+n;
	}
	printf("%d\n",sum);

	return 0;
}


