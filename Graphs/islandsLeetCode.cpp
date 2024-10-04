#include<bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &graph) {
	int n = graph.size(), m = graph[0].size();
	if(i<0 || j < 0 || i >= n || j >= m) return;
	if(!graph[i][j]) return;
	graph[i][j] = 0;
	dfs(i+1, j, graph);
	dfs(i, j+1, graph);
	dfs(i-1, j, graph);
	dfs(i, j-1, graph);
}

int connectedComponents(vector<vector<int>> &graph) {
	int n = graph.size(), m = graph[0].size(), cc = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(graph[i][j]) {
				cc++;
				dfs(i, j, graph);
			}
		}
	}
	return cc;
}

int main() {
	vector<vector<int>> graph = {
		{1,1,0,0,0},
		{1,1,0,0,0},
		{0,0,1,1,0},
		{0,0,0,1,1}
	};
	cout << connectedComponents(graph);
	
}
