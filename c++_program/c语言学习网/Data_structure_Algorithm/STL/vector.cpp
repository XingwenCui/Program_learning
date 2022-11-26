/*
 * @Author: XingwenCui cxw1997n@gmail.com
 * @Date: 2022-11-27 00:53:13
 * @LastEditors: XingwenCui cxw1997n@gmail.com
 * @LastEditTime: 2022-11-27 01:19:24
 * @FilePath: \Program_learning\c++_program\c语言学习网\Data_structure_Algorithm\STL\vector.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;



int main(){
    // vector<int> v1; //创建空vector
    // vector<int> v2(10); //开辟10个元素空间，相当于int v[10];
    // vector<int> v3(10,5); //10个元素，赋值为5
    // vector<int> v4(v3.begin(),v3.end()); //创建v4，内容为v3内容

    //迭代器
    //1.
    // vector<int>::iterator it; //C98标准，创建迭代器，本身是指针
    // for (it=v4.begin();it!=v4.end();it++){
    //     cout<<*it<<' ';
    // }
    // cout<<""<<endl;
    //也可以直接访问下标
    // for (int i = 0; i<v4.size();i++){
    //     cout<<v4[i]<<' ';
    // }
    // cout<<endl;
    cout<<"heelo"<<endl;
    system("pause");
    return 0;
}