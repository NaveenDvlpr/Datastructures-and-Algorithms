#include<bits/stdc++.h>
using namespace std;

int solve(int k, vector<int> &stones, vector<int> &dp) {
	cout << k << endl;
	if(k == 0) return 1;
	if(k < 0 ) return 0;
	if(dp[k] != -1) return dp[k];
	int ans = 1;
	for(auto i : stones) {
		if(solve(k-i,stones,dp)) {
			ans = 0;
			break;
		}
	}
	return dp[k] = ans;
}

bool game(int k, vector<int> &stones) {
	vector<int> dp(k+1, -1);
	for(auto i : stones) {
		if(solve(k-i, stones, dp)) return true;
	}
	return false;
}


int main() {
	int n, k;
	cin >> n >> k;
	vector<int> stones(n);
	for(int i = 0; i < n; i++) cin >> stones[i];
	bool ans = game(k, stones);
	if(ans) cout << "first";
	else cout << "second";
}
