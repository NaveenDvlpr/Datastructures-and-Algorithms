#include<bits/stdc++.h>
using namespace std;

string subsequenceDP(int i, int j, string &s, string &t, vector<vector<string>> &dp) {
	if(i == s.length() || j == t.length()) return "";
	if(dp[i][j] != "0") return dp[i][j];
	string ans;
	if(s[i] == t[j]) ans = s[i]+subsequenceDP(i+1, j+1, s, t, dp);
	else {
		string str1 = subsequenceDP(i+1, j, s, t, dp);
		string str2 = subsequenceDP(i, j+1, s, t, dp);
		if(str1.length() > str2.length()) ans = str1;
		else ans = str2;
	}
	return dp[i][j] = ans;
}
int main() {
	string s, t;
	cin >> s >> t;
	vector<vector<string>> dp(s.length(), vector<string> (t.length(), "0"));
	cout << subsequenceDP(0, 0, s, t, dp) << endl; 
	return 0;
}
