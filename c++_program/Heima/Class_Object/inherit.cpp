/*
 * @Author: XingwenCui cxw1997n@gmail.com
 * @Date: 2022-11-28 14:17:42
 * @LastEditors: XingwenCui cxw1997n@gmail.com
 * @LastEditTime: 2022-11-28 17:27:04
 * @FilePath: \Program_learning\c++_program\Heima\Class_Object\inherit.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%A
 */
#include<iostream>
#include<string>

using namespace std;
//1.
//普通实现页面
//Java
// class Java
// {
// public:
//     void header()
//     {
//         cout<<"head"<<endl;
//     }
//     void footer()
//     {
//         cout<<"foot"<<endl;
//     }
// };

//Python ,与java重复，这样很麻烦
class Python
{
public:
    void header()
    {
        cout<<"head"<<endl;
    }
    void footer()
    {
        cout<<"foot"<<endl;
    }
};

//继承实现
class Base
{
public:
    void header()
    {
        cout<<"head"<<endl;
    }
    void footer()
    {
        cout<<"foot"<<endl;
    }
};

//Java
class Java : public Base
{
    public:
        //自己的东西，其他东西也都被继承了
        void content()
        {
            cout<<"Java video"<<endl;
        }
};

//2. 继承方式
class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};
//public inherit
class Son1: public Base1
{
public:
    void func()
    {
        m_A = 10; //base 类中public权限成员依然是公共的
        m_B = 20; // protect权限成员依然是保护的
        // m_C = 10; // private 访问不到
    }
};

void test02()
{
    Son1 s1;
    s1.m_A = 20;
    //s1.m_B = 100; //protect,外部访问不到
}

//保护继承
class Son2 : protected Base1
{
public:
    void func()
    {
        m_A = 10; //base 类中public权限成员是protect的
        m_B = 20; // protect权限成员依然是保护的
        // m_C = 10; // private 访问不到
    }    
};

void test022()
{
    Son2 s1;
    // s1.m_A = 10000; //保护权限访问不到
}

//私有继承
class Son3 : private Base1
{
public:
    void func()
    {
        m_A = 100;
        m_B = 100;
        // m_C = 100;
    }
};

void test023()
{
    Son3 s1;
    // s1.m_A = 1000; //访问不到
}


int main(){
    Java ja;
    ja.header();
    ja.content();
    ja.footer();

    system("pause");
    return 0;
}