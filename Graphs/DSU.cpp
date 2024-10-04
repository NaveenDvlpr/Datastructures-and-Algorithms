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
		size[a] += size[b];
	}	
}

int main() {
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) make(i);
	while(k--) {
		int u, v;
		cin >> u >> v;
		Union(u,v);
	}
	int cc = 0;
	for(int i = 1; i <= n; i++) {
		if(find(i) == i) cc++;
	}
	cout << cc << endl;
	return 0;
}
























