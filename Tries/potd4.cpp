#include<bits/stdc++.h>
using namespace std;

int right(Node* node) {
	if(node == NULL) return -1;
	while(node->right != NULL) node = node->right;
	return node->data;
}

int left(Node* node) {
	if(node == NULL) return -1;
	while(node->left != NULL) node = node->left;
	return node->data;
}

void solve(Node* node, int &ans) {
	int l = right(node->left), r = left(node->right);
	if(l != -1) ans = min(ans, node->data-l);
	if(r != -1) ans = min(ans, r-node->data);
	if(node->left) solve(node->left, ans);
	if(node->right) solve(node->right, ans);
}

int af(Node* root) {
	int ans = INT_MAX;
	solve(root, ans);
	return ans;
}
