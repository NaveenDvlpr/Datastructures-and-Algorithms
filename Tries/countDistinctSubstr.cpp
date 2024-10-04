#include<bits/stdc++.h>
using namespace std;

struct Node {
	Node* links[26];
	
	bool containsKey(char ch) {
		return links[ch-'a'];
	}
	Node* get(char ch) {
		return links[ch-'a'];
	}
	void put(char ch, Node* node) {
		links[ch-'a'] = node;
	}
};


class Trie {
private:
	Node* root;
public:
	Trie() {
		root = new Node();
	}
	void insert(string word) {
		Node *node = root;
		for(int i = 0; i < word.length(); i++) {
			if(!node->containsKey(word[i])) {
				node->put(word[i], new Node());
			}
			node = node->get(word[i]);
		}
	}
	
	int solveCDS(Node* node) {
		int count = 0;
		for(int i = 0; i < 26; i++) {
			if(node->containsKey('a'+i)) {
				count++;
				count += solveCDS(node->get('a'+i));
			}
		}
		return count;
	}
	
	int getCDS() {
		return solveCDS(root);
	}
};

int countDistinctSubstrings(string str) {
	Trie trie;
	for(int i = 0; i < str.length(); i++) trie.insert(str.substr(i));
	return trie.getCDS();
}



int main() {
	cout << countDistinctSubstrings("abcd") << endl;
	return 0;
}









