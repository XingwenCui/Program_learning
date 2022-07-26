#include<stdio.h>

int main()
{
	int n[10]; // declare an array contain 10 int
	int i,j;
	int a[5] = {1,2,3,4,5};
	//initial array elements
	for (i=0; i<10; i++)
	{
		n[i] = i + 100; // pass value to element
	}

	// output value
	for (j=0; j<10; j++)
	{
		printf("Element[%d} = %d\n", j, n[j]);
	}

	int ar[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	for(i = 0;i<3;i++)
	{
		for (j = 0; j<4; j++)
		{
			printf("%d",ar[i][j]);
		}
		printf("\n");
	}
	// string
	char c[5] = {"china"}; // the end will add '\0',so it won't output 'a'.
	char c1[6] = {'c','h','i','n','a','\0'};
	
	printf("%s and %s\n",c,c1);

	return 0;
}
