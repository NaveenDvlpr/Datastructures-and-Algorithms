#include<bits/stdc++.h>
using namespace std;

vector<int> rabin_karp(string &s, string &t) {
	int p = 31;
	int m = 1e9+9;
	int S = s.size(), T = t.size();
	
	vector<long long> p_pow(max(S, T));
	p_pow[0] = 1;
	for(int i = 1; i < (int)p_pow.size(); i++) p_pow[i] = (p_pow[i-1]*p) % m;
	
	vector<long long> h(T+1, 0);
	for(int i = 0; i < T; i++) {
		h[i+1] = (h[i]+(t[i]-'a'+1)* p_pow[i]) % m;
	}
	
	long long h_s = 0;
	for(int i = 0; i < S; i++) {
		h_s = (h_s + (s[i]-'a'+1) * p_pow[i]) % m;
	}
	
	vector<int> occurences;
	for(int i = 0; i+S-1 < T; i++) {
		long long curr_h = (h[i+S]+m-h[i]) % m;
		if(curr_h == h_s * p_pow[i] % m) {
			occurences.push_back(i);
		}
	}
	return occurences;
}

int main() {
	string t = "abababab";
	string s = "ab";
	
	vector<int> ans = rabin_karp(s, t);
	
	for(auto i : ans) cout << i << " ";
	
	return 0;
}
