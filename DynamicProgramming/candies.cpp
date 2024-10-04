#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int candieDist(int i, int k, vector<int> &candies, vector<vector<int>> &dp) {
	int n = candies.size();
	if(i == n-1 && candies[i] >= k) return 1;
	if(i == n && k > 0) return 0;
	if(dp[i][k] != -1) return dp[i][k];
	int ans = 0;
	cout << i << " " << k << endl;
	for(int j = 0; j <= candies[i]; j++) {
		if(k-j >= 0) ans = (ans+0LL+candieDist(i+1, k-j, candies, dp))%mod;
		else break;
	}
	return dp[i][k] = ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> candies(n);
	for(int i = 0; i < n; i++) cin >> candies[i];
	vector<vector<int>> dp(n, vector<int> (k+1, -1));
	cout << candieDist(0,k,candies,dp);
	return 0;
}
