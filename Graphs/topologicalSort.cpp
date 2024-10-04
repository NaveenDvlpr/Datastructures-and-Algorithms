#include<bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>> &g, vector<bool> &visited, stack<int> &st) {
	visited[v] = true;
	for(auto c : g[v]) {
		if(visited[c]) continue;
		dfs(c,g,visited,st);
	}
	st.push(v);
}

vector<int> topSort(vector<vector<int>> &g) {
	int n = g.size();
	vector<bool> visited(n, false);
	stack<int> st;
	for(int i = 0; i < n; i++) {
		if(!visited[i]) dfs(i,g,visited,st);
	}
	vector<int> ans;
	while(!st.empty()) {
		int tp = st.top();
		st.pop();
		ans.push_back(tp+1);
		
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
	vector<int> topSortArr = topSort(g);
	for(auto i : topSortArr) cout << i << " ";
	return 0;
}
