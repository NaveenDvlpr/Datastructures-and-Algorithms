#include<bits/stdc++.h>
using namespace std;

int findPathDP(int i, vector<vector<int>> &g, vector<int> &dp) {
	if(g[i].size() == 0) return 0;
	if(dp[i] != -1) return dp[i];
	int ans = 0;
	for(auto j : g[i]) {
		ans = max(ans, findPathDP(j, g, dp));
	} 
	return dp[i] = ans+1;
}

int longestPath(vector<vector<int>> &g) {
	int n = g.size();
	int ans = 0;
	vector<int> dp(n, -1);
	for(int i = 0; i < n; i++) ans = max(ans, findPathDP(i, g, dp));
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u-1].push_back(v-1);
	}
	cout << longestPath(g);
	return 0;
}
