#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &mat) {
	cout << endl;
	for(auto v : mat) {
		for(auto i : v) {
			if(i == INT_MAX) cout << "X" << " ";
			else cout << i << " ";	
		}
		cout << endl;
	}
	cout << endl;
}

int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold) {
	vector<vector<int>> mat(n, vector<int>(n, INT_MAX));
	for(int i = 0; i < m; i++) {
		int u = edges[i][0], v = edges[i][1], w = edges[i][2];
		mat[u][v] = w;
		mat[v][u] = w; 
	}
	for(int i = 0; i < n; i++) mat[i][i] = 0;
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(mat[i][k] != INT_MAX && mat[k][j] != INT_MAX) {
					mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);	
				}
			}
		}
	}
	print(mat);
	int min_ct = INT_MAX, ind = -1;
	for(int i = 0; i < n; i++) {
		int ct = 0;
		for(int j = 0; j < n; j++) {
			if(mat[i][j] > 0 && mat[i][j] <= distanceThreshold) ct++;
		}
		if(ct != 0 && ct <= min_ct) {
			min_ct = ct;
			ind = i;
		}
	}
	return ind;
}

int main() {
	vector<vector<int>> edges = {{3,2,29},{2,0,27}};
	cout << findCity(4, 2, edges, 27);
	return 0;
}


