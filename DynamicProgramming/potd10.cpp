#include<bits/stdc++.h>
using namespace std;

void print(int n, int arr[]) {
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

vector<int> solve(int n, int arr[]) {
	vector<pair<int,int>> ans;
	for(int i = 0; i < n && ans.size() != 2; i++) {
		if(i <= n-2 && arr[i] < i) continue;
		print(n , arr);
		int pos = i;
		int tar = arr[i]-1;
		while(1) {
			if(arr[tar] == pos) break;
			if(arr[tar] < pos) {
				if(ans.size() == 0) {
					cout << pos << " " << tar+1 << endl;
					ans.push_back({pos, tar+1});
					break;
				} else {
					if(ans[0].second != tar+1) {
						cout << pos << " " << tar+1 << endl;
						ans.push_back({pos, tar+1});
						break;	
					}
				}
			}
			int tmp = arr[tar]-1;
			arr[tar] = pos;
			pos = tar;
			tar = tmp;
		}
	}
	print(n, arr);
	if(ans[0].first > ans[1].first) swap(ans[0], ans[1]);
	vector<int> ans2(2);
	ans2[0] = ans[0].second;
	ans2[1] = ans[1].second;
	return ans2;
}


int main() {
	int arr[] = {1,5,5,1,4,2,3};
	vector<int> ans = solve(7, arr);
	cout << ans[0] << " " << ans[1] << endl;
}
