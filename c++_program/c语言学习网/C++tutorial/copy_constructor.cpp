#include<iostream>
using namespace std;
#define PI 3.1415

class Circle
{
	private:
		double R;
	public:
		Circle(double R);
		Circle(Circle &A);//拷贝构造，没有就默认
		double area();
		double girth();
};
Circle::Circle(double R)
{
	cout<<"Constructor"<<endl;
	this->R = R;
}
Circle::Circle(Circle &A)
{
	cout<<"Copy Constructor"<<endl;
	this->R = A.R;
}
double Circle::area()
{
	return PI*R*R;
}
double Circle::girth()
{
	return 2*PI*R;
}
int main()
{
	Circle A(5);
	Circle B(A);
	cout<<B.girth()<<endl;

	cout<<A.girth()<<endl;
	return 0;
}
