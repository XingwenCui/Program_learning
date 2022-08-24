#include<stdio.h>

int main()
{
	// putchar is a function{int putchar(int ch)} which used to output a character.
	putchar('A');
	char x = 'c';
	putchar(x);
	putchar('\n');

	//getchar is a function{getchar()} which incept a char(a key)
	char c;
	c = getchar();
	putchar(c);
	putchar('\n');
	
	//format print: printf("",v)
	//format string is % + d(integer),f(float),5.2f is length of 5 and cotain 2 decimal
	int a = 12;
	float b = 123.42;
	c = 'A';
	printf("%d\n",a);
	printf("0%o\n",a);
	printf("0%o\n",a);
        printf("0x%x\n",a);
        printf("%2.2f\n",b);
        printf("%c\n",c);
        getchar();
	
	//scanf: format input, similar with printf
	float f = scanf("%10f");
	scanf("%10f",&f);
	printf("%f\n",f);	

	return 0;
}
