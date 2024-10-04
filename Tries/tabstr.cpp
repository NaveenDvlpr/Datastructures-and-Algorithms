#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> wt(n, 0);
		for(int i = 0; i < n; i++) cin >> wt[i];
		sort(wt.begin(), wt.end());
		int ans = 0;
		for(int i = 0; i < n; i++) {
			ans = max(ans, (n-i)*wt[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
