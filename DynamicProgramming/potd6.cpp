#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &mat) {
	for(auto i : mat) {
		for(auto j : i) cout << j << " ";
		cout << endl;
	}
	cout << endl << endl;
}

int solve(int n, int m, vector<vector<int>> points) 
	{ 
		print(points);
        vector<vector<int>> dist(n, vector<int>(m)), cost(n, vector<int>(m));
    	if(points[0][0] > 0) {
    		dist[0][0] = points[0][0];
    		cost[0][0] = 0;
    	} else {
    		dist[0][0] = 0;
    		cost[0][0] = -points[0][0];
    	}
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < m; j++) {
    			if(i==0&&j==0) continue;
    			int temp;
    			if(i-1>=0) {
    				temp = dist[i-1][j]+points[i][j];
    				if(temp > 0) {
    					cost[i][j] = cost[i-1][j];
    					dist[i][j] = temp;
    				} else {
    					cost[i][j] = cost[i-1][j]-temp;
    					dist[i][j] = 0;
    				}
    			} else {
    				cost[i][j] = INT_MAX;
    				dist[i][j] = INT_MIN;
    			}
    			if(j-1>=0) {
    				temp = dist[i][j-1]+points[i][j];
    				if(temp > 0) {
    					if(cost[i][j-1] < cost[i][j]) {
    						cost[i][j] = cost[i][j-1];
    						dist[i][j] = temp;
    					} else if(cost[i][j-1] == cost[i][j]) {
    						dist[i][j] = max(dist[i][j], temp);
    					}
    				} else {
    					int temp2 = cost[i][j-1]-temp;
    					if(cost[i][j] > temp2) {
    						cost[i][j] = temp2;
    						dist[i][j] = 0;
    					}
    				}
    			}
    		}
    	}
    	print(cost);
    	print(dist);
    	return cost[n-1][m-1]+1;
}


int main() {
	vector<vector<int>> points = {
		{-1, -2, 1, 1},
		{-5, -10, 2, 1},
		{6, 10, -2,-15}
	};
	cout << solve(points.size(), points[0].size(), points) << endl;
}
