#include<iostream>
using namespace std;
int c1007();

int increment(){
	int a = 10;
	cout<<a++<<endl; //a++,print first,then(next line) add itself
	cout<<a<<endl;
	cout<<++a<<endl;
	cout<<a<<endl;
	return 0;
}

int assign()
{
	int a=10;
	int b;
	b=a;//assign value of a to b
	return 0;
}

int relate()
{
	cout<<(10>5)<<endl;
	cout<<(2>=2)<<endl;
	cout<<(3!=1)<<endl;
	cout<<(5==5)<<endl;
	return 0;

}

int main()
{
	increment();
	relate();
	int a; //待判断的三位数
	int ge;
	int shi;
	int bai;
	cin>>a;

	ge = a%10;
	shi = a%100/10;
	bai = a/100;

	cout<<ge<<" "<<shi<<" "<<bai<<endl;
	c1007();
	return 0;
}

int c1007(){
	int x,y;
	cin>>x;
	if(x<1){
		y=x;
	}
	else if(1<=x && x<10){
		y=2*x-1;	
	}
	else
	{
		y=3*x-11;
	}
	cout<<y<<endl;
	return 0;
}
