#include<bits/stdc++.h>
using namespace std;

// monotonic function
int requiredChances(vector<int> arr, int p) {
	int chances = 0;
	for(auto i : arr) {
		chances += (i/p);
		if(i%p == 0) chances--;
	}
	return chances;
}

int maxPenalty(vector<int> &arr, int q) {
	// binary search based on monotonic function
	int sp = 1, ep = arr[0];
	for(int i = 1; i < arr.size(); i++) ep = max(ep, arr[i]);
	while(sp <= ep) {
		int mp = (sp+ep)/2;
		int chances = requiredChances(arr, mp);
		if(chances == q || (mp == ep && chances <= q)) return mp;
		else if(chances < q) ep = mp;
		else sp = mp+1;
	}
}

int main() {
	vector<int> arr = {1,1,8};
	for(int i = 0; i <= 10; i++) {
		int mp = maxPenalty(arr, i);
		cout << i << " " << mp << endl;
	}
	
	return 0;
}
