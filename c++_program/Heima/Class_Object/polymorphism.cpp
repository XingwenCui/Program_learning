/*
 * @Author: XingwenCui cxw1997n@gmail.com
 * @Date: 2022-12-06 10:31:05
 * @LastEditors: XingwenCui cxw1997n@gmail.com
 * @LastEditTime: 2022-12-06 11:49:52
 * @FilePath: \Program_learning\c++_program\Heima\Class_Object\polymorphism.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
using namespace std;

class Animal
{
    public:
        //加上虚函数，动态多态，函数地址晚绑定
        virtual void speak(){
            cout<<"Animal is speaking"<<endl;
        }
};

class Cat:public Animal
{
    public:
        void speak(){
            cout<<"Cat is speaking miao"<<endl;
        }
}; 

// class Dog : public Animal
// {
//     public:
//         void speak(){
//             cout<<"Dog is speaking wang"<<endl;
//         }
// };

//地址早绑定，在编译阶段就确定了函数地址
void doSpeak(Animal &animal){
    
    animal.speak();
}
//如果想让猫说话，就不能提前绑定，在Animal类前加上virtual
//所以动态多态，要满足1.继承关系 2. 子类重写父类的虚函数

//动态多态的使用，需要父类的指针或引用执行子类对象

int main(){
    Cat cat;
    doSpeak(cat); //直接使用时动物在说话，加virtual可以让cat说话
    // Dog dog;
    // doSpeak(dog);

    cout<<sizeof(cat)<<endl; //加virtual是8个字节（64位系统）,指针，不加1个字节

    return 0;
}