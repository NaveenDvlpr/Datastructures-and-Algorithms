#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int solve(int v, int p, int c, vector<vector<int>> &g) {
	if(g[v].size() == 1) return 1;
	int ans = 0;
	for(auto ch : g[v]) {
		if(ch == p) continue;
		if(c == 0) {
			ans = (ans+0L+solve(ch, v, 1, g))%mod; 
		} 
		ans = (ans+0L+solve(ch, v, 0, g))%mod;
	}
	return ans;
}

int findSets(vector<vector<int>> &g) {
	return (solve(0, -1, 0, g) + 0L + solve(0, -1, 1, g))%mod;
}


int main() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for(int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		g[u-1].push_back(v-1);
		g[v-1].push_back(u-1);
	}
	cout << findSets(g);
	return 0;
}
