#include<stdio.h>
//递归，时间复杂度为O(log n)
int gcd(int a, int b) {
	return (a%b == 0)? b : gcd(b,a%b); //辗转相除
}

int main() {
	int m,n;
	scanf("%d %d", &m, &n);
	int ans = gcd(m,n);
	printf("%d %d\n", ans, m*n / ans);
	return 0;
}
