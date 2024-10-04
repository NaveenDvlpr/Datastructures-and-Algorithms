#include<bits/stdc++.h>
using namespace std;


bool isPeak(int i, int n, vector<int> &arr) {
	int left = INT_MIN, right = INT_MIN;
	if(i > 0) left = arr[i-1];
	if(i < n-1) right = arr[i+1];
	if(arr[i] > left && arr[i] > right) return true;
	return false;
}

int findPeak(int n, vector<int> &arr) {
	int s = 0, e = n-1;
	while(1) {
		if(isPeak(s, n, arr)) return s;
		if(isPeak(e, n, arr)) return e;
		int m = s+(e-s)/2;
		if(isPeak(m, n, arr)) return m;
		if(arr[m-1] > arr[m]) {
			s = s+1;
			e = m-1;
		} else {
			e = e-1;
			s = m+1;
		}	
	}
}


int main() {
	vector<int> arr = {1,2,3,6,5,4,7,3,2};
	cout << findPeak(9, arr);
	return 0;
}
