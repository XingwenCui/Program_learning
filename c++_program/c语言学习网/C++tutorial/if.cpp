/*
 * @Author: XingwenCui cxw1997n@gmail.com
 * @Date: 2022-11-17 23:50:14
 * @LastEditors: XingwenCui cxw1997n@gmail.com
 * @LastEditTime: 2022-11-18 00:26:35
 * @FilePath: \Program_learning\c++_program\c语言学习网\if.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<iomanip>

using namespace std;
int switchcase(){
	int n;
	cin>>n;
	switch(n){
		case 0: cout<<"Sunday"; break;
		case 1: cout<<"Sunday"; break;
		case 2: cout<<"Sunday"; break;
		case 3: cout<<"Sunday"; break;
		case 4: cout<<"Sunday"; break;
		case 5: cout<<"Sunday"; break;
		case 6: cout<<"Sunday"; break;
		default: cout<<"input error!";
	}
	return 0;
}



int q1057q(){
	double x;
	double y;
	cin>>x;

	if(x<1){
		y=x;
	}
	else if(x>=1 && x<10)
	{
		y=2*x-1;
	}
	else
	{
		y=3*x-11;
	}
	//控制为两位小数
	cout<<fixed<<setprecision(2)<<y<<endl;
	return 0;
}


int main()
{
	switchcase();
	q1057q();
	
	//This is question 1119
	int a;
	int ge;
	int shi;
	int bai;
	cin>>a;
	ge = a%10;
	shi = a%100/10;
	bai = a/100;

	if(ge*ge*ge +shi*shi*shi+bai*bai*bai == a)
		cout<<"1"<<endl;
	else
		cout<<"0"<<endl;
	return 0;
}

