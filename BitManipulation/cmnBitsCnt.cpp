#include<bits/stdc++.h>
using namespace std;

int commonBitsCount(int a, int b) {
	a = a&b;
	int ct = 0;
	for(int i = 30; i >= 0; i--) {
		if((a&(1<<i)) != 0) ct++;
	}
	return ct;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << commonBitsCount(a, b);
}
