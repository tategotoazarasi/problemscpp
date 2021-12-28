//
// Created by tategotoazarasi on 2021/12/28.
//

#include "concatenated_words.h"

using namespace std;

namespace concatenated_words {
    vector<string> Solution::findAllConcatenatedWordsInADict(vector<string> &words) {
        sort(words.begin(), words.end(), [&](const string &a, const string &b) {
            return a.size() < b.size();
        });
        auto ans = vector<string>();
        TrieNode node = TrieNode(0);
        for (const string &word: words) {
            if (word.length() == 0) {
                continue;
            }
            if (node.dfs(&node, word, 0, false)) {
                ans.push_back(word);
            } else {
                node.insert(word);
            }
        }
        return ans;
    }

    TrieNode::TrieNode(char ch) {
        this->ch = ch;
        this->is_concatenated = false;
        this->is_end = false;
    }

    void TrieNode::insert(const string &str) {
        auto node = this->nexts[str[0] - 'a'];
        if ((node) == nullptr) {
            node = new TrieNode(str[0]);
            this->nexts[str[0] - 'a'] = node;
        }
        if (str.length() == 1) {
            node->is_end = true;
            return;
        } else return node->insert(str.substr(1));
    }

    bool TrieNode::dfs(TrieNode *root, const string &str, int start, bool flag) {
        if (this->ch == 0) {//根节点
            auto node = this->nexts[str[start] - 'a'];
            if (node == nullptr) {
                return false;
            }
            if (node->dfs(root, str, start, flag)) {
                return true;
            }
            return false;
        } else {//非根节点
            //到一个单词结束处
            if (this->is_end) {
                if (start == str.length() - 1) {
                    return flag;
                }
                auto res = root->dfs(root, str, start + 1, true);
                if (res) {
                    return true;
                }
            }
            TrieNode *node = nullptr;
            if (str[start + 1] - 'a' >= 0) {
                node = this->nexts[str[start + 1] - 'a'];
            }
            return node != nullptr && node->dfs(root, str, start + 1, flag);
        }
    }
}