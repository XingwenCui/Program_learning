/*
 * @Author: XingwenCui cxw1997n@gmail.com
 * @Date: 2022-11-30 00:40:55
 * @LastEditors: XingwenCui cxw1997n@gmail.com
 * @LastEditTime: 2022-11-30 01:05:58
 * @FilePath: \Program_learning\c++_program\c语言学习网\Data_structure_Algorithm\Tree\permutation.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<cmath>

using namespace std;

int p[10] = {0}; //初始数组，注意，p[0]==0
bool vis[10] = {0}; //是否遍历到
int n; //对n个数全排列
void DFS(int x){
    if (x == n+1){
        for (int i=1; i<=n; i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
        return;
    }

    for (int i=1; i<=n; i++){
        //如果i位置是false，即没标记过
        if (vis[i]==false){
            p[x] = i; //对p[x]位置为i
            vis[i] = true; //给i位置设为标记，这样在下边的DFS就不会再更新他
            DFS(x+1); //迭代DFS，step+1
            vis[i] = false; //重置标记,恢复初始状态
        }
    }
}

int main(){
    while (cin>>n){
        if(n>10){
            cout<<"You can't enter number more than 10"<<endl;
            return 0;
        }
        DFS(1);
    }
    return 0;
}