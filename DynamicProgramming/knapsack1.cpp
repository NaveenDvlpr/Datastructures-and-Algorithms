#include<bits/stdc++.h>
using namespace std;

int knapsackRec(int i, int W, vector<pair<int,int>> &objects) {
	if(i == objects.size()) return 0;
	int w = objects[i].first, v = objects[i].second;
	int ans = knapsackRec(i+1, W, objects);	
	if(w <= W) ans = max(ans, knapsackRec(i+1, W-w, objects)+v);
	return ans;
}

long long knapsackDP(int i, int W, vector<pair<int, int>> &objects, vector<vector<long long>> &dp) {
	if(i == objects.size()) return 0;
	if(dp[i][W] != -1) return dp[i][W]; 
	int w = objects[i].first, v = objects[i].second;
	long long ans = knapsackDP(i+1, W, objects, dp);
	if(w <= W) ans = max(ans, knapsackDP(i+1, W-w, objects, dp)+v);
	return dp[i][W] = ans;
}

int main() {
	int n, W;
	cin >> n >> W;
	vector<pair<int, int>> objects;
	for(int i = 0; i < n; i++) {
		pair<int, int> temp;
		cin >> temp.first >>  temp.second;
		objects.push_back(temp);
	}
	//cout << knapsackRec(0, W, objects) << endl;
	
	vector<vector<long long>> dp(n, vector<long long> (W+1, -1));
	cout << knapsackDP(0, W, objects, dp) << endl;
	
	return 0;
}
