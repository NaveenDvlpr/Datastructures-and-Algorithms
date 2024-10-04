#include<bits/stdc++.h>
using namespace std;

vector<int> countElements(vector<int> &a, vector<int> &b, vector<int> &q) {
        int mx = INT_MIN;
        for(auto i : a) mx = max(i, mx);
        for(auto i : b) mx = max(i , mx);
        cout << mx << endl;
		mx+=1;
        vector<int> ct(mx, 0);
        for(auto i : b) ct[i] = 1;
        for(auto i : ct) cout << i << " ";
        cout << endl;
        for(int i = 1; i < mx; i++) ct[i] += ct[i-1];
        for(auto i : ct) cout << i << " ";
        cout << endl;
        vector<int> ans;
        for(auto i : q) {
            ans.push_back(ct[a[i]]);
        }
        return ans;
}


/*
	9
4 10 2 9 3 4 1 9 8
7 3 9 2 10 10 3 4 4
3
5
7
2


5 7 1
*/ 


int main() {
	vector<int> a = {4, 10, 2, 9, 3, 4, 1, 9, 8};
	vector<int> b = {7, 3, 9, 2, 10, 10, 3, 4, 4};
	vector<int> q = {5, 7, 2};
	vector<int> ans = countElements(a,b,q);
	for(auto i : ans) cout << i << endl;
	return 0;
}
