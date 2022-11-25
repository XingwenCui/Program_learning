#include<iostream>
using namespace std;

class MyInteger
{
    friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
    MyInteger()
    {
        m_Num = 0;
    }

    //overload 前置++, 注意返回的数据类型，这里要返回引用，是为了一直对一个数据递增
    MyInteger& operator++()
    {
        m_Num++; //先运算，后返回
        return *this; //返回自身
    }
    //overload 后置++
    //这里注意，return的是temp，函数运行完会释放掉，所以不能返回地址
    MyInteger operator++(int) //占位参数int，区分前置后置
    {
        //先返回，后递增
        MyInteger temp = *this; 
        m_Num++;
        return temp; //返回临时变量
    }

private:
    int m_Num;
};

//重载左移运算符
ostream& operator<<(ostream& cout, MyInteger myint){
    cout<<myint.m_Num;
    return cout;
}

void test01()
{
    MyInteger myint;
    cout<<++myint<<endl; //注意重载左移运算符
    cout<<++(++myint)<<endl; //如果是return值，则不会对myint再递增
    cout<<myint<<endl;
}

void test02()
{
    MyInteger myint;
    cout<<myint++<<endl;
    cout<<myint<<endl;
}

int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
