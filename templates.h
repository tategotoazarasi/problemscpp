#pragma once
#include <array>
#include <string>

using namespace std;

/// \brief 字典树节点
struct TrieNode {
	char ch;
	array<TrieNode *, 26> nexts = {};
	bool end_of_word            = false;
	TrieNode(char ch): ch(ch) {}
	void insert(const string &str);
	~TrieNode();
};