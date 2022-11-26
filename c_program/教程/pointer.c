#include<stdio.h>
#include<string.h>


int main(){

	// 1. Address
	int i;
	int a[10] = {1,2,3,4,5,6,7,8,9,0};
	char b[10] = {'c','l','a','n','g','u','a','g','e'};
	for(i=0;i<10;i++)
	{
	
		//int need 4Byte address
		printf("int Address:0x%x,Value:%d\n",&a[i],a[i]);
	}
	printf("\n");
	for(i=0;i<10;i++)
	{
		//char need 1 Byte address
		printf("char Address:0x%x,Value:%c\n",&b[i],b[i]);
	}
	
	//2.Pointer
	int num = 2014;
	int *pp=&num;
	printf("num Address = 0x%x, num=%d\n",&num,num);
	// *p in here is value of the address p;
	printf("p=0x%x,*p=%d\n",pp,*pp);
	printf("%d\n",*&num);
	//size
	int *p;
        char *p1;
        float *p2;
        double *p3;
        struct INFO *p4;   //struct INFO类型为结构体类型 我们将会在后面的章节中讲解
        void *p5;
        printf("int point size is :%d\n",sizeof(p));
        printf("char point size is :%d\n",sizeof(p1));
        printf("float point size is :%d\n",sizeof(p2));
        printf("double point size is :%d\n",sizeof(p3));
        printf("struct point size is :%d\n",sizeof(p4));
        printf("void point size is :%d\n",sizeof(p5));	
	
	//3. array pointer
	int *po=a; // point a[0];
	for(i=0;i<10;i++)
	{
		// po and a is address of a[i], so *po is value
		printf("P Value:%d  a Value :%d\n",*(po++),*(a+i));
}
	printf("\n");
	
	//4. string pointer
	char *str = "www.dot";
	char string[] = "Welcome";
	//str[0]='C';这一句不可，指针只能表示指那，不能改变value;
	string[0] = 'C';
	printf("%s",string);
	
	//5. strcpy()
	char string1[10];
	char *str1 = "www.dotcpp.com";
	strcpy(string1,str1);
	printf("%s\n",string1);
	

	
	
	return 0;
}

