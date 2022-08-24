#include<stdio.h>
#include<string.h>
struct _INFO
        {
                int num;
                char str[256];
        };

int main()
{
	// struct + struct_name + variable_name
	struct _INFO A;
	A.num = 2014;
	strcpy(A.str,"Welcome to");
	printf("This year is %d %s\n",A.num,A.str);
	
	
	// 2.struct array: struct + struct_name(with struct) + variable
	struct address
	{
		char name[30]; //结构体成员
		char street[40];
		unsigned long tel; //无符号长整型
		unsigned long zip;
	}student[3] = {
		{"zhang","road NO.1",111111,4444},
		{"wang","ss",22222,5555},
		{"Li","road No3",33333,66666}
	};

	//3.struct pointer
	struct address *p;
	p = &student[0];
	int i;
	int length;
	length = sizeof(student)/sizeof(student[0]);
	for(i=0;i<length;i++)
	{
		printf("%s %s %u %u\n",p++->name,p->street,p->tel,p->zip);
	}
	printf("length of struct array is %d",length);
	
	//4.union
	union UNION
	{
		int a; int b; int c;
	};
	union UNION U;
	U.a = 1;
	U.b = 2;
	U.c = 3;
	printf("a:%d\n",U.a);
	printf("b:%d\n",U.b);	
	printf("c:%d\n",U.c);
	
	//5.typedef
	typedef struct _INFO AAAI;
	AAAI B;
	B=A;
	printf("THis year is %d %s\n",A.num,B.str);

	//6.enumerate
	enum Week{MON,TUE,WED,THU=10,FRI,SAT,SUN};
	enum Week W=WED;//the third value
	printf("%d\n",W);
	enum Week F=FRI;	
	printf("%d\n",F);
	return 0;
}
