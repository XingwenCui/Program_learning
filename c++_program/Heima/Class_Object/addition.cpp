/*
 * @Author: XingwenCui cxw1997n@gmail.com
 * @Date: 2022-11-25 15:11:38
 * @LastEditors: XingwenCui cxw1997n@gmail.com
 * @LastEditTime: 2022-11-25 15:17:30
 * @FilePath: \Program_learning\c++_program\Heima\Class_Object\addition.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
using namespace std;

class Person
{
public:
	//1.成员函数重载+号
	Person operator+(Person &p)
	{
		Person temp;
		temp.A=this->A+p.A;
		temp.B=this->B+p.B;
		return temp;
	}
	int A;
	int B;
};

//2.全局函数重载+
Person operator+(Person &p1,Person &p2)
{
	Person temp;
	temp.A=p1.A+p2.A;
	temp.B=p1.B+p2.B;
	return temp;
}

//重载
Person operator+(Person &p1,int num)
{
	Person temp;
	temp.A=p1.A+num;
	temp.B=p1.B+num;
	return temp;
}

void test01()
{
	Person p1;
	p1.A=10;p1.B=20;
	Person p2;
	p2.A=1;p2.B=2;

	// Person p3 = p1+p2;
	Person p4 = p1+20;
	//1.成员函数本质：
	Person p3=p1.operator+(p1);
	//2.全局函数本质
	// Person p3 = operator+(p1,p2);
	
	cout<<"P3.A="<<p3.A<<endl;
	cout<<"P3.B="<<p3.B<<endl;
    cout<<"P4.A="<<p4.A<<"P4.B="<<p4.B<<endl;
}

int main(){

    test01();
    system("pause");
    return 0;
}