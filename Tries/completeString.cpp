#include<bits/stdc++.h>
using namespace std;

struct Node {
public:
	Node* list[26];
	bool isEnd = false;
	bool containsKey(char ch) {
		return (list[ch-'a'] != NULL);
	}
	Node* get(char ch) {
		return list[ch-'a'];
	}
	void put(char ch, Node *node) {
		list[ch-'a'] = node;
	}
	bool getEnd() {
		return isEnd;
	}
	void setEnd() {
		isEnd = true;
	}
};

class Trie {
private:
	Node *root = new Node();
public:
	void insert(string word) {
		Node *node = root;
		for(int i = 0; i < word.length(); i++) {
			if(!node->containsKey(word[i])) {
				node->put(word[i], new Node());
			}
			node = node->get(word[i]);
		}
		node->setEnd();
	}
	string solveCS(Node *node) {
		string cs = "";
		for(int i = 0; i < 26; i++) {
			string temp = "";
			if(node->containsKey('a'+i)) {
				Node *node2 = node->get('a'+i);
				if(node2->getEnd()) {
					cout << "x" << endl;
					temp = char('a'+i);
					temp += solveCS(node2);
				}
			}
			if(temp.length() > cs.length()) cs = temp;
		}
		return cs;
	}
	
	string getCS() {
		return solveCS(root);
	}
};

string completeString(int n, vector<string> arr) {
	Trie tr;
	for(int i = 0; i < n; i++) tr.insert(arr[i]);
	string ans = tr.getCS();
	if(ans == "") ans = "none";
	return ans;
}

int main() {
	int n = 2;
	vector<string> arr = {"ab", "abc"};	
	cout << completeString(2, arr);
	
	return 0;
}
















