/*
 * @Author: XingwenCui cxw1997n@gmail.com
 * @Date: 2022-12-03 00:40:49
 * @LastEditors: XingwenCui cxw1997n@gmail.com
 * @LastEditTime: 2022-12-03 00:49:45
 * @FilePath: \Program_learning\c++_program\c语言学习网\C++tutorial\exercise\1810.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * https://www.dotcpp.com/oj/problem1810.html
 */
#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

int main(){
    char a; int b; float c; double d;
    cin >> a >> b >> c >> d;
    cout<<right;
    cout<<a<<' ';
    cout<<setw(4)<<b<<' ';
    // cout<<setw(20);
    cout<<fixed<<setprecision(2)<<c<<' ';
    cout<<fixed<<setprecision(12)<<d<<endl;

    return 0;   
}