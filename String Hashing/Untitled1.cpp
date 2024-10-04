#include<bits/stdc++.h>
using namespace std;

vector<string> solve(string &json1, string &json2) {
	int n1 = json1.length(), n2 = json2.length();
	unordered_map<string, string> mp;
	string key = "", value = "";
	bool isKey = true;
	for(int i = 2; i < n1; i++) {
		if(json1[i] == '"') {
			i += 2;
			if(isKey) isKey = false;
			else {
				mp[key] = value;
				key = value = "";
				isKey = true;
			} 
		}
		else {
			if(isKey) key += json1[i];
			else value += json1[i];
		}
	}
	for(auto i : mp) {
		cout << i.first << " " << i.second << endl;
	}
	vector<string> ans;
	for(int i = 2; i < n2; i++) {
		if(json2[i] == '"') {
			i += 2;
			if(isKey) isKey = false;
			else {
				if(mp[key] != "" && mp[key] != value) ans.push_back(key);
				isKey = true;
				key = value = "";
			} 
		}
		else {
			if(isKey) key += json2[i];
			else value += json2[i];
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

// {"hello":"world","hi":"hello","you":"me"}
// {"hello":"world","hi":"hello","you":"me"}

int main() {
	string json1, json2;
	cin >> json1 >> json2;
	cout << json1 << endl;
	cout << json2 << endl;
	vector<string> ans = solve(json1, json2);
	for(auto s : ans) cout << s << endl;
	
	return 0;
}
