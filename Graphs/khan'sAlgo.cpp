#include<bits/stdc++.h>
using namespace std;


vector<int> khanAlgo(vector<vector<int>> &g) {
	int n = g.size();
	vector<int> inDegree(n, 0);
	for(int i = 0; i < n; i++) {
		for(auto c : g[i]) inDegree[c]++;
	}
	queue<int> q;
	for(int i = 0; i < n; i++) {
		if(inDegree[i] == 0) q.push(i);
	}
	vector<int> ans;
	while(!q.empty()) {
		int fr = q.front();
		q.pop();
		ans.push_back(fr+1);
		for(int c : g[fr]) {
			if(--inDegree[c] == 0) q.push(c);
		}
	}
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
	vector<int> topSort = khanAlgo(g);
	for(auto i : topSort) cout << i << " ";
	cout << endl;
	return 0;
}
