#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> &nums) {
	int n = nums.size();
	vector<int> count(n, 1);
	for(int i = n-2; i >= 0; i--) {
		for(int j = i+1; j < n; j++) {
			if(nums[j]-nums[i] >= j-i) {
				if(count[j] >= count[i]) count[i] = max(count[i], count[j])+1;
			}
		}
	}
	for(auto i : count) cout << i << " ";
	cout << endl;
	int ans = -1;
	for(int i = 0; i < n; i++) ans = max(ans, count[i]);
	ans = n-ans;
	return ans; 
}

int main() {
	vector<int> nums = {1,9,8,7,3,9,8,7,5};
	cout << solve(nums) << endl;
	return 0;
}

