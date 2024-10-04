#include<bits/stdc++.h>
using namespace std;

int main() {
	int n = 3;
	vector<vector<int>> mat(n,vector<int>(n,0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) cout << mat[i][j] << " ";
		cout << endl;
	}
	return 0;
}
