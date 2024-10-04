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

void dfs(int i, int j, int nc, int oc, vector<vector<int>> &image) {
	int n = image.size(), m = image[0].size();
	if(i < 0 || i >= n || j < 0 || j >= m) return;
	if(image[i][j] != oc) return;
	image[i][j] = nc;
	dfs(i+1, j, nc, oc, image);
	dfs(i, j+1, nc, oc, image);
	dfs(i-1, j, nc, oc, image);
	dfs(i, j-1, nc, oc, image);
}

vector<vector<int>> floodfill(vector<vector<int>> &image, int srcx, int srcy, int newColor) {
	int n = image.size(), m = image[0].size();
	if(image[srcx][srcy] != newColor) dfs(srcx, srcy, newColor, image[srcx][srcy], image);
	return image;
}


int main() {
	vector<vector<int>> image = {{1,1,4},{1,2,1},{1,1,1}};
	print(image);
	image = floodfill(image,0,0,1);
	print(image);
	return 0;
}















