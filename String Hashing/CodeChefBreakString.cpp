#include<bits/stdc++.h>
using namespace std;

void generateZ(int n, string &str, vector<int> &z) {
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r-i, z[i-l]);
        }
        while(i+z[i] < n && str[i+z[i]] == str[z[i]]) {
            z[i]++;
        }
        if(i+z[i] > r) {
            l = i;
            r = i+z[i];
        } 
    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
    {
        string str;
        cin >> str;
        int n = str.length();
        if(n&1) {
        	cout << 0 << endl;
        	continue;
		}
        vector<int> z(n);
        generateZ(n, str, z);
        vector<int> z2(n);
        reverse(str.begin(), str.end());
        generateZ(n, str, z2);
        z[0] = z2[0] = n;
        int ans = 0;
        for(int i = 0; i <= n/2; i++) {
        	if(z[i] >= i && z2[n/2-i] >= (n/2-i)) ans++;
		}
		cout << ans << endl;
    }
	return 0;
}

