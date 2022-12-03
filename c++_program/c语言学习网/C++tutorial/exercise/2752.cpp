#include<iostream>
using namespace std;

int main(){
    int a; short b;
    cout<<sizeof(a)<<' '<<sizeof(b)<<endl;

    float c; double d;
    cout<<sizeof(c)<<' '<<sizeof(d)<<endl;

    bool e; char f;
    cout<<sizeof(e)<<' '<<sizeof(f)<<endl;

    return 0;
}
