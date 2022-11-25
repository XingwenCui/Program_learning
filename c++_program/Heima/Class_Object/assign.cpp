#include<iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        m_Age = new int(age); //堆区,手动开辟，手动释放
    }

    ~Person() //可能会造成堆区重复释放
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }

    Person& operator=(Person &p)
    {
        if (m_Age!=NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }

        //深拷贝
        m_Age = new int(*p.m_Age);

        return *this; //加上return为了能 p3=p2=p1,p2可以返回
    }

    int *m_Age;
};

void test01()
{
    Person p1(18);
    cout<<"p1 age: "<<*p1.m_Age<<endl;
    Person p2(20);
    Person p3(30);
    p3 = p2 = p1; //assign, 
    cout<<"p1 age: "<<*p1.m_Age<<endl;
    cout<<"p2 age: "<<*p2.m_Age<<endl;
    cout<<"p3 age: "<<*p3.m_Age<<endl;
}

int main()
{
    test01();
    int a = 10;
    int b = 20;
    int c = 30;
    c = b = a;
    cout<<a<<b<<c<<endl; //都是10

    system("pause");
    return 0;
}