#include<stdio.h>

int main(){
	int a;
	scanf("%d",&a);
	double Sn, n;
	n = 0, Sn = 0;
	// When Sn more than a, loop stop
	while (Sn <= a){
		Sn = Sn + 1/(++n);
		printf("%f\n",n);
	}
	printf("%d",(int)(n));
	
}