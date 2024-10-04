#include<bits/stdc++.h>
using namespace std;

double maxHeadsDP(int i, int count, vector<double> &coins, vector<vector<double>> &dp) {
	int n = coins.size();
	if(count > n/2) return 0;
	if(i == n) return 1;
	if(dp[i][count] != -1) return dp[i][count];
	double ans;
	ans = maxHeadsDP(i+1,count,coins,dp)*coins[i]+maxHeadsDP(i+1,count+1,coins,dp)*(1-coins[i]);
	return dp[i][count]=ans;
}


double maxHeads(int n, vector<double> &coins) {
	double ans;
	vector<vector<double>> dp(n, vector<double>(n, -1));
	ans = maxHeadsDP(1,0,coins,dp)*coins[0]+maxHeadsDP(1,1,coins,dp)*(1-coins[0]);
	return ans;
}

 
int main() {
	int n;
	cin >> n;          
	vector<double> coins(n);
	for(int i = 0; i < n; i++) cin >> coins[i];
	cout << maxHeads(n, coins);
	
}
















