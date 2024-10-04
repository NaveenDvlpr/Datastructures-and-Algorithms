#include<bits/stdc++.h>
using namespace std;

int vacationRec(int i, int a, vector<vector<int>> &activities) {
	if(i == activities.size()) return 0;
	int ans = 0;
	for(int j = 0; j < 3; j++) {
		if(j == a) continue;
		ans = max(ans, vacationRec(i+1, j, activities)+activities[i][a]);
	}
	return ans;
}

int vacationDP(int i, int a, vector<vector<int>> &activities, vector<vector<int>> &dp) {
	if(i == activities.size()) return 0;
	int ans = 0;
	if(dp[i][a] != -1) return dp[i][a];
	for(int j = 0; j < 3; j++) {
		if(j == a) continue;
		ans = max(ans, vacationRec(i+1, j, activities)+activities[i][a]);
	}
	return dp[i][a] = ans;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> activities(n, vector<int>(3, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) cin >> activities[i][j];
	}
	vector<vector<int>> dp(n, vector<int>(3, -1));
	int ans = 0;
	for(int i = 0; i < 3; i++) {
		ans = max(ans, vacationDP(0, i, activities, dp));
	}
	cout << ans << endl;
	return 0;
}
