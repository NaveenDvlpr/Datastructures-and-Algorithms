#include<bits/stdc++.h>
using namespace std;

void insert(int a, int b, vector<int> &ans) {
	for(int i = a; i < b; i+=2) {
		ans.push_back(i+1);
		ans.push_back(i);
	}
}

bool isEven(int n) {
	return !(n&1);
}

vector<int> solve(int l, int r) {
	vector<int> ans;
	if((isEven(l) && isEven(r)) || (l == r)) return ans;
	if(l == 1 && !isEven(r)) {
		ans.push_back(1);
		l = 2;	
	} else if(!(isEven(l) || isEven(r))) {
		ans.push_back(l+1);
		ans.push_back(l+2);
		ans.push_back(l);
		l += 3;
	}
	insert(l, r, ans);
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int l, r;
		cin >> l >> r;
		vector<int> ans = solve(l, r);
		if(ans.size()) {
			for(auto i : ans) cout << i << " ";
			cout << endl;
		} else {
			cout << -1 << endl;
		}
	}
	
	return 0;
}












