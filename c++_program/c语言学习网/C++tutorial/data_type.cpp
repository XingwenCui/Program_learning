#include<iostream>
using namespace std;

//same with C
int main(){
	int num;
	char sex;
	double score1;
	double score2;
	double score3;

	cout<<"Please input student's I"<<endl;

	cin>>num>>sex>>score1>>score2>>score3;

	cout<<"ID:"<<num<<" "<<sex<<"Total score is:"
		<<score1+score2+score3<<endl;
	return 0;
}
