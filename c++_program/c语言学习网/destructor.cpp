#include<iostream>
#include<Cstring>

using namespace std;

class Student
{
	private:
		int num;
		char name[100];
		int score;
	public:
		Student(int n, char str, int s);
		~Student();//destructor，对象释放后的清理善后工作，~是为了区分constructor
		int print();
		int Set(int n, char str, int s);
};

Student::Student(int n, char str, int s)
{
	num=n;
	strcpy(name,str); //strcpy是把str的字符串复制到dest
	score=s;
	cout<<num<<" "<<name<<" "<<score<<" ";
	cout<<"Constructor"<<endl;
}
Student::~Student()
{
	cout<<num<<" "<<name<<" "<<score<<"";
	cout<<"Destructor"<<endl;
}
int Student::print()
{
	cout<<num<<" "<<name<<" "<<endl;
	return 0;
}
int Student::Set(int n, char str, int s)
{
	num=n;
	strcpy(name,str);
	score=s;
}

int main()
{
Student A(100,"doy",11);
	Student B(101,"cpp",12);
	return 0;
}


