#include<bits/stdc++.h>
using namespace std;

int count_unique_substrings(string &s) {
	int n = s.size();
	int p = 31;
	int m = 1e9+9;
	vector<long long> p_pow(n);
	p_pow[0] = 1;
	for(int i = 1; i < n; i++) {
		p_pow[i] = (p_pow[i-1] * p) % m;
	}
	vector<long long> h(n+1, 0);
	for(int i = 0; i < n; i++) {
		h[i] = ((s[i]-'a'+1)*p_pow[i]) % m;
	}
	int cnt = 0;
	for(int l = 1; l <= n; l++) {
		unordered_set<long long> hs;
		for(int i = 0; i <= n-l; i++) {
			long long cur_h = (h[i+l]+m-h[i]) % m;
			cur_h = (cur_h * p_pow[n-i-1]) % m;
			hs.insert(cur_h);
		}
		cnt += hs.size();
	}
	return cnt;
}

// The function above executes in O(N^2) time
// Using Suffix Arrays we can do this task in O(NlogN)
// Using Suffix Trees or a Suffix Automation we can do this task in O(N)


int main() {
	string s = "abcde";
	cout << count_unique_substrings(s);
	return 0;
}
















