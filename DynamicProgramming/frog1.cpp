#include<bits/stdc++.h>
using namespace std;

int frogRec(int i, vector<int> &h) {
	int n = h.size();
	if(i == n-1) return 0;
	int ans = frogRec(i+1, h)+abs(h[i]-h[i+1]);
	if(i+2 < n) ans = min(ans, frogRec(i+2, h)+abs(h[i]-h[i+2]));
	return ans;
}

int frogDP(int i, vector<int> &h, vector<int> &dp) {
	int n = h.size();
	if(i == n-1) return 0;
	if(dp[i] != -1) return dp[i];
	int ans = frogDP(i+1, h, dp)+abs(h[i]-h[i+1]);
	if(i+2 < n) ans = min(ans, frogDP(i+2, h, dp)+abs(h[i]-h[i+2]));
	return dp[i] = ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> h(n, 0);
	for(int i = 0; i < n; i++) cin >> h[i];
//	cout << frogRec(0, h) << endl;
	vector<int> dp(n+1, -1);
	cout << frogDP(0, h, dp) << endl;
	return 0;
}
