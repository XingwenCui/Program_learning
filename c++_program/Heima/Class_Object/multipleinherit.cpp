/*
 * @Author: XingwenCui cxw1997n@gmail.com
 * @Date: 2022-12-05 23:01:17
 * @LastEditors: XingwenCui cxw1997n@gmail.com
 * @LastEditTime: 2022-12-05 23:08:12
 * @FilePath: \Program_learning\c++_program\Heima\Class_Object\multipleinherit.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
using namespace std;

class Base1{
public:
    Base1(){
        m_A = 100;
    }
    int m_A;
};

class Base2{
public:
    Base2(){
        m_A = 200;
    }
    int m_A;
};

class Son : public Base1, public Base2{
public:
    Son(){
        m_C = 300;
        m_D = 400;
    }
    int m_C;
    int m_D;
};

void test(){
    //1.占多少内存空间
    Son s;
    cout<<"size of son is "<<sizeof(s)<<endl; //16,他继承了2父类

    //2. 父类同名成员
    // cout<<"m_A = "<<s.m_A<<endl; //二义性
    cout<<"Base1::m_A "<<s.Base1::m_A<<endl;
    cout<<"Base2::m_A "<<s.Base2::m_A<<endl;


}

int main(){
    test();
    return 0;
}
