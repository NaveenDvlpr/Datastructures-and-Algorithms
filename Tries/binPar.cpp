#include<bits/stdc++.h>
using namespace std;

bool bin_par(int n) {
	int ct = 0;
	for(int i = 0; (n>>i) != 0; i++) {
		if(n & (1<<i)) ct++;
	}
	cout << ct << endl;
	if(ct&1) return true;
	else return false;
}


int main() {
	cout << bin_par(13) << endl;
	return 0;
}
