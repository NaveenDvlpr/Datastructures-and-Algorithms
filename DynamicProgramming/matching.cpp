
#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int matching(int i, int p, vector<vector<int>> &mat, vector<int> &mapping, vector<vector<int>> &dp) {
	int n = mat.size();
	if(i == n) {
		return 1;	
	}
	int ans = 0;
	if(dp[i][p] != -1) return dp[i][p]; 
	for(int j = 0; j < n; j++) {
		if(mat[i][j] && mapping[j] == -1) {
			mapping[j] = i;
			ans = (ans+0LL+matching(i+1, i, mat, mapping, dp))%mod;
			mapping[j] = -1;
		}
	}
	return dp[i][p] = ans;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> mat(n, vector<int>(n));
	vector<int> temp(n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) cin >> mat[i][j];
	}
	vector<int> mapping(n, -1);
	vector<vector<int>> dp(n, vector<int> (n, -1));
	cout << matching(0, 0, mat,mapping, dp);
	return 0;
}
