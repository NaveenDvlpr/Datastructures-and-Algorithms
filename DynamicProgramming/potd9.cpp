#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k, vector<int> &arr) {
	vector<int> small(n), big(n);
	int s = INT_MAX, b = INT_MIN;
	for(int i = n-1; i >= 0; i--) {
		if(arr[i] < s) s = arr[i];
		if(arr[i] > b) b = arr[i];
		small[i] = s;
		big[i] = b;
	}
	s = INT_MAX;
	b = INT_MIN;
	int ans = big[k]-small[k];
	for(int i = 0; i < n-k; i++) {
		s = min(s, arr[i]);
		b = max(b, arr[i]);
		ans = min(ans, (max(b, big[k+i])-min(s,small[k+i])));
	}
	return ans;
}

int main() {
	vector<int> arr = {1, 2, 3, 4, 5};
	cout << solve(5, 3, arr);
}
