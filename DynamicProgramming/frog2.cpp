#include<bits/stdc++.h>
using namespace std;

int frogRec(int i, int k, vector<int> &h) {
	int n = h.size();
	if(i == n-1) return 0;
	int ans = frogRec(i+1, k,h)+abs(h[i]-h[i+1]);
	for(int j = 2; j <= k; j++) {
		if(i+j < n) ans = min(ans, frogRec(i+j, k, h)+abs(h[i]-h[i+j]));
	}
	return ans;
}

int frogDP(int i, int k, vector<int> &h, vector<int> &dp) {
	int n = h.size();
	if(i == n-1) return 0;
	if(dp[i] != -1) return dp[i];
	int ans = frogDP(i+1, k, h, dp) + abs(h[i]-h[i+1]);
	for(int j = 2; j <= k; j++) {
		if(i+j < n) ans = min(ans, frogDP(i+j, k, h, dp) + abs(h[i] - h[i+j]));
	}
	return dp[i] = ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> h(n, 0);
	for(int i = 0; i < n; i++) cin >> h[i];
//	cout << frogRec(0, k, h) << endl;
	vector<int> dp(n+1, -1);
	cout << frogDP(0, k, h, dp) << endl;

	return 0;
}
