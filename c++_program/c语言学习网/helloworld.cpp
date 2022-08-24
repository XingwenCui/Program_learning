#include<iostream> //standard library
using namespace std; //命名空间，防止不同module间重名问题

//或者用这种
using std::cout;
using std::endl;

int main()
{
	int a;
	cin>>a;
	cout<<"Get "<<a<<endl;

	cout<<"Hello World!"<<endl;
	cout<<"Hello"<<"12,3"<<endl<<"another line"<<endl;
	std::cout<<"Hello World again!"<<std::endl;
	return 0;
}
