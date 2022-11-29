#include<iostream>

using namespace std;

typedef long long ll;
ll ans,n;
//建立DFS算法遍历二叉树
void DFS(ll k){
    //边界条件
    if (k == n){
        ans++;
        return;
    }
    else if (k>n){
        //如果k超过了n，就返回DFS的搜索，按DFS，如果从k+1返回后会进行k+3
        return;
    }

    DFS(k+1);//走1个
    DFS(k+3);//走3个
}

int main(){
    cout<<"Please enter which is your goal?"<<endl;
    while (cin>>n){
        ans = 0; //有几个答案
        DFS(0); //从0开始,找到一个方法就ans+1
        cout<<ans<<endl;
    }
    return 0;
}
