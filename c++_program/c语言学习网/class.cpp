#include<iostream>
#include<cstring>

using namespace std;


//类是对象的抽象和概括，对象是类的具体和实例
class Student
{
	public:
		int num;
		char name[100];
		int score; //属性
		//方法
		int print()
		{
			cout<<num<<" "<<name<<" "<<score;
			return 0;
		}
}; //不要忘了;

//另一种写法
class Student2
{
	public:
		int num;
		int name[100];
		int score;
		int print(); //声明method
};
// define method out of class
int Student2::print(){
	cout<<num<<" "<<name<<" "<<score;
	return 0;
}

//3.constructor
//与class同名，没后return，如果不创建的话，系统默认生成一个空的constructor
class Studentc
{
	private:
		int num;
		char name[100];
		int score;
	public:
		Studentc(int n, char *str, int s);
		int print();
		int Set(int n, char *str, int s);
};
Studentc::Studentc(int n, char *str, int s)
{
	num = n;
	strcpy(name,str);
	score = s;
	cout<<"Constructor"<<endl;
}
int Studentc::print()
{
	cout<<num<<" "<<name<<" "<<score<<endl;
	return 0;
}
int Studentc::Set(int n, char *str, int s)
{
	num = n;
	strcpy(name,str);
	score = s;
	return 0;
}

//2. 对象建立与使用
int main()
{
	Student A;
	A.num = 101;
	strcpy(A.name, "dotcpp");
	A.score = 100;
	A.print();

	//对象指针
	//对象也是一片连续的内存空间
	Student *p; //现在并没有建立对象，也不会调用构造函数
	p = &A; //将同类型对象的地址，赋给pointer
	p -> print(); //通过->访问对象中的方法

	//引用,把这个对象的地址赋给这个引用类型，两者指向同一个内存空间
	//这是定义A对象的引用类型，想当与给A起了一个别名
	Student &Aq = A;
	Aq.print();
	
	//3.constructor
	char s[] = "das";
	Studentc S(10,s,122);
	A.print();
	return 0;
}









