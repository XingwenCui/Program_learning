#include<iostream>
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
    for (int i=1; i>-1; i--){
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