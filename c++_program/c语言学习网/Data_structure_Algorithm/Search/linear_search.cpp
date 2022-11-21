#include<iostream>
using namespace std;

int main() {
	int goods[6] = { 10,10,9,10,10,10 };
	for (int i = 0; i < 6; i++) {
		if (goods[i] == 9)
		{
			printf("Find bad in: %d",i+1);
			cout<< endl;
		}
	}
	system("pause");
	return 0;
}