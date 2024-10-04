#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int binExp(int a, int b) {
	if(b == 0) return 1;
	int temp = binExp(a, b/2);
	if(b&1) return (a*1LL*((temp*1LL*temp)%M))%M;
	else return (temp*1LL*temp)%M;
}


int binExpItr(int a, int b) {
	int ans = 1;
	while(b) {
		if(b&1) ans = (ans*1LL*a)%M;
		a = (a*1LL*a)%M;
		b >>= 1;
	}
	return ans;
}

int 

int main(f ) {
	cout << binExpItr(2,13);
	return 0;
}



























