#include<iostream>

using namespace std;

//1143
int p1143(){
	int n,i;
	cin>>n;
	for(i=2;i<n;i++)
	{
		//能被除尽就停
		if(n%i==0)
			break;
	}
	if(i>=n)
		cout<<"是质数"<<endl;
	else
		cout<<"不是素数"<<endl;

	return 0;

}

int p1085(){
	int a,b;
	while(cin>>a>>b){ //cin的return是一个istream对象，如果接受失败，则返回false，结束循环
		cout<<a+b<<endl;
	}

	return 0;

}

int dowhile(){
	int N,sum = 0,i=0;
	cin>>N;
	cout<<i<<endl;
	do
	{
		sum+=i;
		i++;
	}while(i<=N);
	cout<<sum<<endl;
	return 0;
}

int p1149(){
	int n,i;
	int sum=0;
	cin>>n;
	for(i=1; i<=n;i++)
	{
		if(i%2!=0)
			sum += i;
	}
	cout<<sum<<endl;
	return 0;
}


int main(){
	//p1143();
	p1149();
	dowhile();
	//p1085();
	return 0;
}
