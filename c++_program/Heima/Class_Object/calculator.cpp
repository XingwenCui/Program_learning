/*
 * @Author: XingwenCui cxw1997n@gmail.com
 * @Date: 2022-12-06 13:43:39
 * @LastEditors: XingwenCui cxw1997n@gmail.com
 * @LastEditTime: 2022-12-06 14:07:12
 * @FilePath: \Program_learning\c++_program\Heima\Class_Object\calculator.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<string>
using namespace std;

//1. 普通写法
class Calculator
{
public:
    int getResult(string oper)
    {
        if (oper == "+"){
            return Num1 + Num2;
        }
        else if (oper == "-"){
            return Num1 - Num2;
        }
        else if (oper == "*"){
            return Num1 * Num2;
        }
        //如果后续加新的功能，需要修改代码。
        //但在真实开发中，提倡开闭原则，对扩展进行开发，对修改进行关闭
        return 0;
    }
    int Num1; int Num2;
};

void test(){
    Calculator c;
    c.Num1 = 10;
    c.Num2 = 20;

    cout<< c.getResult("+")<<endl;
}

//利用多态实现
//组织结构清晰，可读性强，对于前期后期拓展及维护性高

//首先实现抽象类
class AbCalculator
{
public:
    virtual int getResult(){
        return 0;
    }
    int Num1;
    int Num2;
};
//加法计算器
class AddCalculator : public AbCalculator
{
public:
    int getResult()
    {
        return Num1 + Num2;
    }
};
//减法计算器
class MinusCalculator : public AbCalculator
{
public:
    int getResult()
    {
        return Num1 - Num2;
    }
};
//乘法计算器
class MulCalculator : public AbCalculator
{
public:
    int getResult()
    {
        return Num1 * Num2;
    }
};

void test02(){
    //多态使用时，父类指针指向子类对象
    AbCalculator * abc = new AddCalculator; //堆区数据
    abc->Num1 = 100;
    abc->Num2 = 200;
    cout<<abc->getResult()<<endl;
    //用完记得销毁
    delete abc;

    abc = new MinusCalculator;
    abc->Num1 = 100;
    abc->Num2 = 200;
    cout<<abc->getResult()<<endl;
    delete abc;

    abc = new MulCalculator;
    abc->Num1 = 100;
    abc->Num2 = 200;
    cout<<abc->getResult()<<endl;
    delete abc;
}

int main(){
    test();
    test02();
    return 0;
}