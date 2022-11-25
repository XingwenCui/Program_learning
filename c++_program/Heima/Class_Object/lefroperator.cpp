
#include<iostream>
using namespace std;

class Person
{
//如果属性是private，用友元使全局函数访问
public:
    //利用成员函数重载左移运算符,p.operator<<(cout)->p<<cout.不符合要求
    // void operator<<(Person &p)
    // {
        //成员函数无法实现，因为cout在左侧
    // }
    int m_A;
    int m_B;
};
//只能用全局函数重载左移运算符，cout是一个ostream的对象，且需要引用传递
ostream & operator<<(ostream &cout, Person &p) //本质 cout<<p,只能用全局实现左移
{
    cout<<"m_A="<<p.m_A<<"p.m_B="<<p.m_B;
    return cout;
}
void test01()
{
    Person p;
    p.m_A = 10;
    p.m_B = 10;
    cout<<p<<"Hello"<<endl; //不重载会报错
}

int main(){

    test01();
    system("pause");
    return 0;
}