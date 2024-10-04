#include<bits/stdc++.h>
using namespace std;

int dfs(int v, int p, vector<int> &w, vector<vector<int>> &g, vector<int> &ts) {
	ts[v] = w[v];
	for(auto c : g[v]) {
		if(c == p) continue;
		ts[v] += dfs(c, v, w, g, ts);
	}
	return ts[v];
}

int main() {
	int n;
	cin >> n;
	vector<int> w(n);
	for(int i = 0; i < n; i++) cin >> w[i];
	vector<vector<int>> g(n); 
	for(int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		g[u-1].push_back(v-1);
		g[v-1].push_back(u-1);
	}
	vector<int> treeSum(n, 0);
	dfs(0, -1, w, g, treeSum);
	int ans = INT_MIN;
	for(auto i : treeSum) cout << i << " ";
	cout << endl;
	for(int i = 1; i < n; i++) {
		ans = max(ans, treeSum[i]*(treeSum[0]-treeSum[i]));
	}
	cout << ans << endl;
	return 0;
}
