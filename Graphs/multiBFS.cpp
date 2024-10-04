#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
const int INF = 1e9+10;

int val[N][N];
int vis[N][N];
int lev[N][N];

int n, m;
vector<pair<int,int>> movements = {
	{1,0},{0,1},{-1,0},{0,-1},
	{1,1},{1,-1},{-1,1},{-1,-1}
};

void reset() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			vis[i][j] = 0;
			lev[i][j] = INF;
		}
	}
}

bool isValid(int i, int j) {
	if(i < 0 || j < 0 || i >= n || j >= m) return false;
	return true;
}

int bfs() {
	reset();
	int maxVal = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) maxVal = max(maxVal, val[i][j]);
	}
	queue<pair<int,int>> q;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(val[i][j] == maxVal) {
				q.push({i,j});
				vis[i][j] = 1;
				lev[i][j] = 0;	
			}
		}
	}
	while(!q.empty()) {
		pair<int,int> curr_v = q.front();
		q.pop();
		for(auto mt : movements) {
			int i = curr_v.first+mt.first;
			int j = curr_v.second+mt.second;
			if(isValid(i,j) && !vis[i][j]) {
				q.push({i,j});
				vis[i][j] = 1;
				lev[i][j] = lev[curr_v.first][curr_v.second]+1;
			}
		}
	}
	int maxHours = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) maxHours = max(maxHours, lev[i][j]);
	}
	return maxHours;
}


int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> val[i][j];
			}
		}
		cout << bfs();
	}
	
	return 0;
}















