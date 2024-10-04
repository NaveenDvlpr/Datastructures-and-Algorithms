#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &mat) {
	cout << endl;
	for(auto v : mat) {
		for(auto i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int solve(vector<vector<int>> &mat) {
	int r = mat.size(), c = mat[0].size();
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(mat[i][j] == 0) {
				if(i-1 >= 0) mat[i-1][j] = -1;
				if(i+1 < r) mat[i+1][j] = -1;
				if(j+1 < c) mat[i][j+1] = -1;
				if(j-1 >= 0) mat[i][j-1] = -1;
			}
		}
	}
	
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(mat[i][j] == -1) mat[i][j] = 0;
		}
	}
	
	for(int j = c-1; j > 0; j--) {
		for(int i = 0; i < r; i++) {
			if(j != c-1 && mat[i][j] == 1) continue;
			if(mat[i][j-1] != 0) mat[i][j-1] += mat[i][j];
		}
		for(int i = 1; i < r; i++) {
			if(mat[i][j-1] == 1 && mat[i-1][j-1] > 1) mat[i][j-1] += mat[i-1][j-1]; 
		}
		for(int i = r-2; i >= 0; i--) {
			if(mat[i][j-1] == 1 && mat[i+1][j-1] > 1) mat[i][j-1] += mat[i+1][j-1];
		} 
		print(mat);
	}
	
	int ans = INT_MAX;
	for(int i = 0; i < r; i++) {
		if(mat[i][0] > 1) ans = min(ans, mat[i][0]);
	}
	if(ans == INT_MAX) ans = -1;
	return ans;
}

int main() {
	vector<vector<int>> mat = {
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1	
	},
	{
		1, 0, 1, 1, 1, 1, 1, 1, 1, 1
	},
	{
		1, 1, 1, 0, 1, 1, 1, 1, 1, 1
	},
	{
		1, 1, 1, 1, 0, 1, 1, 1, 1, 1
	}, 
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	},
	{
		1, 1, 1, 1, 1, 0, 1, 1, 1, 1
	},
	{
		1, 0, 1, 1, 1, 1, 1, 1, 0, 1
	},
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	}, 
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	}, 
	{
		0, 1, 1, 1, 1, 0, 1, 1, 1, 1
	}, 
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	}, 
	{
		1, 1, 1, 0, 1, 1, 1, 1, 1, 1
	}
};
	print(mat);
	cout << solve(mat);
	return 0;
}



