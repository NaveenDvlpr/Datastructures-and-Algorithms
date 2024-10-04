#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int i) {
	if((n&(1<<i)) != 0) return 1;
	return 0;
}

void setBit(int &n, int i) {
	n |= (1<<i);
}

int division(int A, int B) {
	if(B == 0) return INT_MAX;
	int i;
	for(i = 30; i >= 0 && !getBit(A, i); i--);
	int tmp = 0, qou = 0;
	while(i>=0) {
		tmp <<= 1;
		qou <<= 1;
		if(getBit(A, i)) {
			setBit(tmp, 0);
		}
		if(tmp >= B) {
			setBit(qou, 0);
			tmp -= B;
		}
		i--;
	}
	return qou;
}

int main() {
	cout << division(7, 0) << endl;
	return 0;
}
