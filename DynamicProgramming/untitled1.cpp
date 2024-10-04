#include<bits/stdc++.h>
using namespace std;


void print(vector<vector<int>> &mat) {
	cout << endl;
	for(auto i : mat) {
		for(auto j : i) cout << j << " ";
		cout << endl;
	}
	cout << endl;
}

int solve(int n, int m, vector<vector<int>> &points) {
	for(int i = n-1; i >= 0; i--) {
		for(int j = m-1; j >= 0; j--) {
			int num = points[i][j], temp;
			if(j+1 <= m-1) {
				temp = num + points[i][j+1];
				if(temp > 0) points[i][j] = 0;
				else points[i][j] = temp;
			} 
			if(i+1 <= n-1) {
				temp = num + points[i+1][j];
				if(temp > 0) points[i][j] = 0;
				else {
					if(j+1 == m) points[i][j] = temp;
					else points[i][j] = max(points[i][j], temp);
				}
			}
		}
	}
	print(points);
	return 1-points[0][0];
}


int main() {
	vector<vector<int>> points = {
		{1},{-1},{1}
	};	
	cout << solve(points.size(), points[0].size(), points) << endl;
	return 0;
}
