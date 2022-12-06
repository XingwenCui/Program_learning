#include<iostream>
using namespace std;

class Animal{
    public:
        int age;
};
//继承之前加上virtual，解决菱形继承问题
class Sheep :virtual public Animal{};

class Tuo :virtual public Animal{};

class SheepTuo : public Sheep, public Tuo{};

void test(){
    SheepTuo st;

    // st.age = 18; //不明确
    st.Sheep::age = 18;
    st.Tuo::age = 28; //虚继承后，直接剩一个age

    cout<< st.Sheep::age <<endl;
    cout<< st.Tuo::age <<endl;

    //但是，我们实际上有一个age就可以了，但现在是两份，造成资源浪费
    //利用虚继承，可以解决多继承问题 virtual

}

int main(){
    test();

    return 0;
}