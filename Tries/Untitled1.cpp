#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int fib(int n, vector<int> &dp) {
	if(n <= 1) return 0;
	if(n == 2) return 1;
	if(dp[n] != -1) return dp[n];
	return dp[n] = (fib(n-1,dp)+0LL+fib(n-2,dp))%mod;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> dp(n+1, -1);
		cout << fib(n, dp) << endl;	
	}
}
