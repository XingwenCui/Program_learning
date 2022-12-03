/*
 * @Author: XingwenCui cxw1997n@gmail.com
 * @Date: 2022-12-03 01:06:42
 * @LastEditors: XingwenCui cxw1997n@gmail.com
 * @LastEditTime: 2022-12-03 01:14:48
 * @FilePath: \Program_learning\c++_program\c语言学习网\C++tutorial\exercise\1812.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%A
 */
#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    char c;
    cin >> c;
    for (int i=0; i<3; i++){
        for(int j=0; j<5; j++){
            if (j< 5/2-i || j> 5 /2 +i){
                cout<<' ';
            }
            else{
                cout<<c;
            }
        }
        cout<<endl;
    }
    return 0;
}