#include<bits/stdc++.h>
using namespace std;

int jobScheduling(vector<int> profit, vector<int> deadline) {
	int max_deadline = 0;
	for(int i = 0; i < deadline.size(); i++) max_deadline = max(max_deadline, deadline[i]);
	vector<bool> slot_aval(true, max_deadline);
	int maxProfit = 0;
	vector<pair<int, int>> jobs;
	for(int i = 0; i < profit.size(); i++) jobs.push_back({profit[i],deadline[i]});
	sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());
	for(int i = 0; i < jobs.size(); i++) {
		int dl = jobs[i].second;
		for(int j = dl-1; j >= 0; j--) {
			if(slot_aval[j]) {
				slot_aval[j] = false;
				maxProfit += jobs[i].first;
				break;
			}
		}
	}
	return maxProfit;
}

int main() {
	vector<int> profit = {35, 30, 25, 20, 15, 12, 5};
	vector<int> weight = {3, 4, 4, 2, 3, 1, 2};0.0
	cout << jobScheduling(profit, weight);
	return 0;
}
