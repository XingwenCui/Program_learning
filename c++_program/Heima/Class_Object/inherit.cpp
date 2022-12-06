/*
 * @Author: XingwenCui cxw1997n@gmail.com
 * @Date: 2022-11-28 14:17:42
 * @LastEditors: XingwenCui cxw1997n@gmail.com
 * @LastEditTime: 2022-12-05 22:56:07
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
    //constructor
    Base(){
        m_A = 100;
        cout<<"Base constructor"<<endl;
    }
    ~Base(){
        cout<<"Base deconstructor"<<endl;
    }

    void func(){
        cout<<"Base func"<<endl;
    }

    void func(int a){
        cout<<a<<endl;
    }

    void header()
    {
        cout<<"head"<<endl;
    }
    void footer()
    {
        cout<<"foot"<<endl;
    }
    static int m_sa; //静态成员，类内声明，类外初始化
    
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};
int Base :: m_sa = 300;

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


//继承中对象模型
class Son: public Base{
public:
    int m_D;
    int m_A;
    static int m_sa;
    void func(){
        cout<<"Son func"<<endl;
    }

    Son(){
        m_A = 200; //同名成员
        cout<<"Son constructor"<<endl;
    }
    ~Son(){
        cout<<"Son deconstructor"<<endl;
    }
};
int Son:: m_sa = 200; //类外初始化
void test3(){
    cout<<"size of Son is "<<sizeof(Son)<<endl; //16
    //父类中所有非静态属性，都会被继承下去，只是有的访问不到
}

void testconstruct(){
    Son s;
    cout<<"Son m_A = "<<s.m_A<<endl; //直接访问，返回200
    //访问父类中的同名成员，需要加作用域
    cout<<"Base m_A = "<<s.Base::m_A<<endl;
    s.func(); //访问SOn中同名函数

    //如果子类中有同名成员函数，子类同名成员会隐藏掉父类中所有同名成员函数，包括重载
    // s.func(100);
    //如果想访问，只能加作用域
    s.Base::func(500);
    s.Base::func(); //访问Base中同名函数


    //静态同名成员
    cout<<"Son m_sa = "<<s.m_sa<<endl;
    cout<<"Base m_sa = "<<s.Base::m_sa <<endl;
    //通过类名访问
    cout<<"Son m_sa = "<<Son::m_sa<<endl;
    //通过类名的方式，访问父类静态成员
    cout<<"Base m_sa = "<<Son::Base::m_sa<<endl;
    //同名静态函数也一样
}
int main(){
    // Java ja;
    // ja.header();
    // ja.content();
    // ja.footer();

    // test3();
    testconstruct();

    system("pause");
    return 0;
}