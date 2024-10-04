#include<bits/stdc++.h>
using namespace std;

int solve(int n, string &str) {
	vector<int> max(26, 0);
	vector<int> steps(26, 0);
	vector<bool> exists(26, 0);
	int temp = 1, cd;
	exists[str[0]-'a'] = true;
	for(int i = 1; i < n; i++) {
		if(str[i] == str[i-1]) temp++; 
		else {
			exists[str[i]-'a'] = true;
			cd = str[i-1]-'a';
			if(max[cd] >= temp) steps[cd] += temp;
			else {
				steps[cd] += max[cd];
				max[cd] = temp;
			}
			temp = 1;
		}
	}
	cd = str[n-1]-'a';
	if(max[cd] >= temp) steps[cd] += temp;
	else {
		steps[cd] += max[cd];
		max[cd] = temp;
	}
	
	int ans = INT_MAX;
	for(int i = 0; i < 26; i++) {
		if(exists[i]) {
			ans = min(ans, steps[i]);
		}
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string str;
		cin >> str;
		cout << solve(n, str) << endl;
	}
	return 0;
}
