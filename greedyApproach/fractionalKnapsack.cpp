#include<bits/stdc++.h>
using namespace std;

double maxProfit(vector<int> weight, vector<int> profit, int W) {
	int n = weight.size();
	vector<pair<double,int>> ratio;
	for(int i = 0; i < n; i++) {
		ratio.push_back({(double)profit[i]/weight[i], i});
	}
	sort(ratio.begin(), ratio.end());
	reverse(ratio.begin(), ratio.end());
	
	double maxProfit = 0;
	
	for(int i = 0; i < n && W != 0; i++) {
		pair<double, int> temp = ratio[i];
		int ind = temp.second;
		if(weight[ind] <= W) {
			maxProfit += profit[ind];
			W -= weight[ind];
		} else {
			maxProfit += temp.first*W;
			W = 0;
		}
	}
	
	return maxProfit;
}


int main() {
	vector<int> weight = {2, 3, 5, 7, 1, 4, 1};
	vector<int> profit = {10, 5, 15, 7, 6, 18, 3};
	
	cout << maxProfit(weight, profit, 15);
	return 0;
}
