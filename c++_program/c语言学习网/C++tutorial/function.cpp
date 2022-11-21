#include<iostream>
#include<cstring>

using namespace std;

//1031
int Reverse(char a[], char b[])
{
	int i=0, n;
	n = strlen(a);
	while(a[i]!='\0'){
		b[n-i-1] = a[i];
		i++;
	}
	b[n]='\0';
	return 0;
}

//形参
int add1(int a=3,int b=5){
	return a+b;
}

//overload:同一个功能，函数名相同，形参不同，根据传入的参数类型，个数来自动选择最适合的一个函数绑定调用。
int add(int a, int b)
{
	cout<<"(int, int)\t";
	return a+b;
}

double add(double a, double b)
{
	cout<<"(double, double)\t";
	return a+b;
}

double add(double a, int b)
{
	cout<<"(double, int)\t";
	return a+b;
}

double add(int a, double b)
{
	cout<<"(int, double)\t";
	return a+b;
}

//function template 简化版的template
//class是固定的，也可以用typename
template<class T1, typename T2>
T1 add2(T1 x, T2 y)
{
	cout<<sizeof(T1)<<","<<sizeof(T2)<<"\t";
	return x+y;
}

//inline:把函数插到函数调用处，免去函数调用的一系列过程，像执行普通代码一样。
//只需要在函数定义前加上关键字
//inline函数的定义要在调用之前出现，才可以让compiler在编译期间了解上下文，进行代码替换。
//inline与register变量类似，只是提给编译器的一个请求，实部实现由编译器自行决定

inline int Max(int a, int b)
{
	return a>b?a:b;
}


int main(){
	char str1[100];
	char str2[100];
	cin>>str1;
	Reverse(str1, str2);
	cout<<str2<<endl;
	
	cout<<add1(10,20)<<endl;//将10和20分别给a和b
	cout<<add1(30)<<endl;
	cout<<add1()<<endl;

	//overload
	cout<<add(2,3)<<endl;
	cout<<add(2.9, 15.3)<<endl;
	cout<<add(10,9.9)<<endl;
	cout<<add(11.5,5)<<endl;

	//template
	cout<<add2(10,20)<<endl;
	cout<<add2(3.14,5.98)<<endl;
	cout<<add2('A',2)<<endl;
	//inline
	cout<<Max(3,5)<<endl;
	cout<<Max(7,9)<<endl;
	return 0;
}
