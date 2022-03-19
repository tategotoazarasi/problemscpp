#include "templates.h"

void TrieNode::insert(const string &str) {
	if(this->nexts[str[0] - 'a'] == nullptr) {
		this->nexts[str[0] - 'a'] = new TrieNode(str[0]);
	}
	if(str.length() == 1) {
		this->nexts[str[0] - 'a']->end_of_word = true;
	} else {
		this->nexts[str[0] - 'a']->insert(str.substr(1));
	}
}

TrieNode::~TrieNode() {
	for(const auto *next: this->nexts) {
		delete next;
	}
}
