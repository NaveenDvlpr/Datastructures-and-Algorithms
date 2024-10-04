#include<bits/stdc++.h>
using namespace std;

int solve(int i, vector<int> &h, vector<int> &a, vector<int> &dp) {
	int n = h.size();
	if(i == n) return 0;
	if(dp[i] != -1) return dp[i];
	int ans = 0;
	for(int j = i+1; j < n; j++) {
		if(h[i] < h[j]) {
			ans = max(ans, solve(j, h, a, dp));
		}
	}
	return dp[i] = ans + a[i];
}

int maxBeauty(int i, vector<int> &h, vector<int> &a) {
	int n = h.size();
	vector<int> dp(n, -1);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans = max(ans, solve(i, h, a, dp));
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> h(n), a(n);
	for(int i = 0; i < n; i++) cin >> h[i];
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << maxBeauty(0,h,a);	
	return 0;
}
