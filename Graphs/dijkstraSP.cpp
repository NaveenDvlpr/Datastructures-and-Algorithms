#include<bits/stdc++.h>
using namespace std;


void dijkstra(vector<vector<pair<int,int>>> &g, vector<bool> &visited, vector<int> &spv) {
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push({0,0});
	while(!q.empty()) {
		pair<int,int> curr_p = q.top();
		q.pop();
		int curr_wt = curr_p.first;
		int curr_v = curr_p.second;
		if(visited[curr_v] == true) continue;
		for(auto child_p : g[curr_v]) {
			int child_v = child_p.first;
			int child_wt = child_p.second;
			if(visited[child_v]) continue;
			if(child_wt+curr_wt < spv[child_v]) {
				spv[child_v] = child_wt+curr_wt;
				q.push({spv[child_v], child_v});
			}
		}
		visited[curr_v] = true;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n);
	for(int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >>  wt;
		g[u-1].push_back({v-1, wt});
	}
	vector<bool> visited(n, false);
	vector<int> spv(n, INT_MAX);
	spv[0] = 0;nb
	dijkstra(g, visited, spv);
	for(auto i : spv) cout << i << " ";
	cout << endl;
	return 0;
}
