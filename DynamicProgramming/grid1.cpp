#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int gridTraversalDP(int i, int j, vector<string> &grid, vector<vector<int>> &dp) {
	int h = grid.size(), w = grid[0].size();
	if(i == h-1 && j == w-1) return 1;
	if(dp[i][j] != -1) return dp[i][j];
	int ans = 0;
	if(j+1 < w && grid[i][j+1] == '.') ans = (ans+0L+gridTraversalDP(i, j+1, grid, dp))%mod;
	if(i+1 < h && grid[i+1][j] == '.') ans = (ans+0L+gridTraversalDP(i+1, j, grid, dp))%mod;
	return dp[i][j] = ans;   
}

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> grid;
	for(int i = 0; i < h; i++) {
		string tmp;
		cin >> tmp;
		grid.push_back(tmp);
	} 	
	vector<vector<int>> dp(h, vector<int>(w, -1));
	cout << gridTraversalDP(0, 0, grid, dp);
	return 0;
}















