#include<stdio.h>

int main()
{
	int num;
	//num is lvalue: and it's a modifiable lvalue.
	//num is a identifier of data object
	//1024 is rvalue
	num = 1024; 

	//mathematical operator 
	int a,b;
	a = b = 5;
	printf("%d      %d\n",a--,--b);
        printf("%d      %d\n",a--,--b);
        printf("%d      %d\n",a--,--b);
        printf("%d      %d\n",a--,--b);
        printf("%d      %d\n",a--,--b);
	
	//sizeof: not a function, its an operator, one of the keywords.
	//it will return the actual size of the object must be known.
	int intsize = sizeof(int);
	printf("Int sizeof is %d bytes\n", intsize);

	//logical operator
	printf("%d\n",3 && 5);
        printf("%d\n",10&&0);
        printf("%d\n",2>=3 || 10);
        printf("%d\n",5>=5 || !0);	

	//conditional operator
	int con = 2>1?10:20;
	printf("%d\n",con);

	return 0;
}
