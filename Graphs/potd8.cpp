#include<bits/stdc++.h>
using namespace std;

bool getBit(int n, int i) {
	if((n&(1<<i)) == 0) return false;
	return true;
}

int solve(vector<int> &nums) {
	int ans = 0;
	for(int i = 0; i < 31; i++) {
		int ct = 0;
		for(auto j : nums) {
			if(getBit(j, i)) ct++;
		}
		ans += ((1<<i)*(ct*(ct-1)/2));
	} 
	return ans;
}

int main() {
	vector<int> nums = {10, 20, 30, 40};
	cout << solve(nums) << endl;
}
