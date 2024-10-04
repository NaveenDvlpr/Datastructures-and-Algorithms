#include<bits/stdc++.h>
using namespace std;

int solve(int i,vector<int> &v, vector<int> &dp) {
	if(dp[i] != -1) return dp[i];
	int ans = v[i], temp = 0;
	for(int j = i+2; j < v.size(); j++) {
		temp = max(temp, solve(j, v,dp));
	}
	return dp[i] = ans+temp;
}

int main() {
	vector<int> v = {1,2,3,1,1,4,100,3,15,13,1,4,1,2,3,1,1,4,100,3,15,13,1,4,1,2,3,1,1,4,100,3,15,13,1,4,1,2,3,1,1,4,100,3,15,13,1,4,1,2,3,1,1,4,100,3,15,13,1,4};
	vector<int> dp(v.size()+1, -1);
	cout << max(solve(0,v,dp), solve(1, v, dp));
	return 0;
}
