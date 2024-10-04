#include<bits/stdc++.h>
using namespace std;

int range(long long num) {
	if(num == 0) return 1;
	int ct = 0;
	while(num) {
		ct++;
		num/=10;
	}
	return ct;
}

long long convert(string s) {
	long long num = 0;
	for(int i = 0; i < s.length(); i++) {
		int d = s[i]-'0';
		num *= 10;
		num += d;
	}
	return num;
}

bool solve(long long num1, long long num2, int i, string &n) {
	cout << num1 << " " << num2 << " " << i << endl;
	int l = n.length();
	while(i < l) {
		num1 += num2;
		swap(num1, num2);
		int r = range(num2);
		long long anum = convert(n.substr(i, r));
		cout << anum << endl;
		if(anum != num2) return false;
		i += r;	
	}
	return true;
}

bool isAttentive(string n) {
	int l = n.length();
	for(int i = 0; i <= l/2; i++) {
		for(int j = 1; l-i-j-1 >= max(i+1, j); j++) {
			long long num1 = convert(n.substr(0, i+1));
			long long num2 = convert(n.substr(i+1, j));
			if(solve(num1, num2, i+j+1, n)) return true;
		}
	}
	return false;
}

int main() {
	cout << isAttentive("2951587152334216745547779911");
	return 0;
}
