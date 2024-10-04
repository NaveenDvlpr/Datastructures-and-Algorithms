#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int parent[N];
int size[N];

void make(int v) {
	parent[v] = v;
	size[v] = 1;
}

int find(int v) {
	if(v == parent[v]) return v;
	// path compression
	return parent[v] = find(parent[v]);
} 

void Union(int u, int v) {
	u = find(u);
	v = find(v);
	if(u!=v) {
		// union by size
		if(size[u] < size[v]) swap(u,v);
		parent[v] = u;
		size[u] += size[v];
	}	
}

int main() {
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) make(i);
	vector<pair<int, pair<int, int>>>l edges;
	for(int i = 0; i < k; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({w, {u, v}});
	}
	sort(edges.begin(), edges.end());
	int mst = 0;
	for(int i = 0; i < k; i++) {
		pair<int, pair<int,int>> edge = edges[i];
		int wt = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;
		u = find(u);
		v = find(v);
		if(u != v) {
			mst += wt;
			Union(u,v);
		}
	}
	cout << mst << endl;
	return 0;
}










