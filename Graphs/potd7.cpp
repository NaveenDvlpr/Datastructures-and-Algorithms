#include<bits/stdc++.h>
using namespace std;

int setBit(int n, int i) {
	return (n | (1<<i));
}

int getBit(int n, int i) {
	if((n&(1<<i)) == 0) return 0;
	else return 1;
}

int bin_gray(int n) {
	int pos, ans = 0;
	for(pos = 31; pos >= 0 && !(n&(1<<pos)); pos--);
	ans = setBit(ans, pos);
	for(int i = pos-1; i >= 0; i--) {
		int first = getBit(n, i+1), second = getBit(n, i);
		if(first^second) ans = setBit(ans, i);
	}
	return ans;
}

int gray_bin(int n) {
	int pos, ans = 0;
	for(pos = 31; pos >= 0 && !(n&(1<<pos)); pos--);
	ans = setBit(ans, pos);
	int last = 1;
	for(int i = pos-1; i >= 0; i--) {
		last ^= getBit(n, i);
		if(last) ans = setBit(ans, i);
	}
	return ans;
}


int fun(int n) {
	n = gray_bin(n);
	return n;
}

int main() {
	cout << fun(4) << endl;
	cout << fun(15) << endl;
	return 0;
}
