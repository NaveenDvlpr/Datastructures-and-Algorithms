#include<bits/stdc++.h>
using namespace std;


int minSum(int s, int e, vector<int> &nums) {
	if(s < 0 || e >= nums.size()) return 0;
	if(s == e) return nums[s];
	int ans = INT_MAX;
	for(int i = s; i < e; i++) {
		int temp = nums[i]+nums[i+1], temp2 = INT_MAX;
		if(i-1>=s) temp2 = minSum(s,i-1,nums);
		if(i+2<=e) temp2 = min(temp2, minSum(i+1,e,nums));
		if(temp2 != INT_MAX) temp += (temp+temp2);
		cout << s << " " << e << " " << temp << endl;
		ans = min(ans, temp);
	}
	return ans;
}


int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) cin >> nums[i];
	cout << minSum(0,n-1,nums) << endl;
}
