#include<iostream>
using namespace std;
#include<string>

class MyPrint
{
public:
    void operator()(string test)
    {
        cout<<test<<endl;
    }
};

//加法类
class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1+num2;
    }
};

void test01()
{
    MyPrint myprint;
    myprint("hello world");

    cout<<MyAdd()(100,100)<<endl; //匿名函数对象MyAdd()
}

int main()
{
    test01();

    return 0;
}