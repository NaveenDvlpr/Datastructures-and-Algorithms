#include<bits/stdc++.h>
using namespace std;

long long computeHash(string &s) {
	int p = 31;
	int m = 1e9+9;
	long long hashValue = 0;
	long long p_pow = 1;
	for(char c : s) {
		hashValue = (hashValue + (c - 'a' + 1)*(p_pow)) % m;
		p_pow = (p_pow * p) % m;
	}
	return hashValue;
}


// Duplicate strings in list of strings
// Obvious approach compare and sort O(nmlogn)
// Hash Approach O(nm + nlogn)

vector<vector<int>> groupIdenticalStrings(vector<string> &s) {
	int n = s.size();
	vector<pair<long long, int>> hashes(n);
	for(int i = 0; i < n; i++) {
		hashes[i] = {computeHash(s[i]), i};
	}
	sort(hashes.begin(), hashes.end());
	
	vector<vector<int>> groups;
	for(int i = 0; i < n; i++) {
		if(i == 0 || hashes[i].first != hashes[i-1].first) 
			groups.emplace_back();
		groups.back().push_back(hashes[i].second);
	}
	return groups;
}


int main() {
	vector<string> s = {"bcde", "abcd", "abcd", "cdef", "bcde"};
	vector<vector<int>> ans = groupIdenticalStrings(s);
	for(auto v : ans) {
		for(auto i : v) cout << i << " ";
		cout << endl;
	}
	return 0;
}


























