#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int solve(int v, int k, vector<vector<int>> &g, vector<vector<int>> &dp) {
	int n = g.size();
	if(k == 0) return 1;
	if(dp[v][k] != -1) return dp[v][k];
	int ans = 0;
	for(int c = 0; c < n; c++) {
		if(g[v][c]) ans = (ans + 0LL + solve(c, k-1, g, dp))%mod;
	}
	return dp[v][k] = ans;
}


int findPaths(int n, int k, vector<vector<int>> &g) {
	int ans = 0;
	vector<vector<int>> dp(n, vector<int>(k, -1));
	for(int i = 0; i < n; i++) {
		ans = (ans + 0LL + solve(i, k, g, dp))%mod;
	}
	return ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> g(n, vector<int>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) cin >> g[i][j];
	}
	cout << findPaths(n, k, g);
	return 0;
}
