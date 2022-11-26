#include<stdio.h>

int max(int n1, int n2); //declare method
int main()
{
	int x;
	extern int exter = 3;
	x = max(1,2); //use our method we defined.
	printf("%d, The max value is %d\n",exter, x);	

	return 0; //未完成任务
}

int exter; //declare a extern variable
int max(int n1, int n2)
{
	int result; // local variable
	if (n1>n2)
		result = n1;
	else
		result = n2;

	return result;
}

int fun(
