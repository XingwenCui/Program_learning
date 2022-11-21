#include<iostream>
using namespace std;

void boole()
{
	bool a = true;
	bool b=false;
	cout<<a<<endl<<b<<endl;
}


int main()
{
	boole();
	int a=9;
	int b=10;
	bool r; //定义bool类型变量r，C语言没bool
	r = a>b;
	cout<<r<<endl;
	cout<<"bool size is "<<sizeof(r)<<endl;
	return 0;
}
