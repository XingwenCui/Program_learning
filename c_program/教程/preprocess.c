// preprocess
#include<stdio.h>
#define M(y) (y*y+3*y) //define宏


int main()
{
	int y, max;
	max = M(y);

	printf("input two numbers: ");
	scanf("%d %d", &y, &max);
	printf("%d %d", y,M(y));
	return 0;
}
