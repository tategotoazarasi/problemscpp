//
// Created by tategotoazarasi on 2021/12/29.
//

#include "leetcode.h"

#include<cmath>

using namespace std;

namespace leetcode {
    namespace concatenated_words {
        vector<string> Solution::findAllConcatenatedWordsInADict(vector<string> &words) {
            sort(words.begin(), words.end(), [&](const string &a, const string &b) {
                return a.size() < b.size();
            });
            auto ans = vector<string>();
            auto node = TrieNode(0);
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

    namespace excel_sheet_column_number {
        int Solution::titleToNumber(const std::string &columnTitle) {
            int sum = 0;
            int length = static_cast<int>(columnTitle.length());
            for (char c: columnTitle) {
                sum += static_cast<int>(static_cast<double>(c - 'A' + 1) * pow(26, length-- - 1));
            }
            return sum;
        }
    }

    namespace excel_sheet_column_title {
        string Solution::convertToTitle(int columnNumber) {
            string ans = string();
            bool round = false;
            while (columnNumber != 0) {
                char ch;
                if (round) {
                    ch = static_cast<char>(columnNumber % 26 + 63);
                    round = false;
                } else ch = static_cast<char>(columnNumber % 26 + 64);
                if (ch == '@' && columnNumber >= 26) {
                    ch = 'Z';
                    round = true;
                } else if (ch == '?' && columnNumber >= 26) {
                    ch = 'Y';
                    round = true;
                }
                if ('A' <= ch && ch <= 'Z') {
                    ans.insert(0, 1, ch);
                }
                columnNumber /= 26;
            }
            return ans;
        }
    }

    namespace majority_element {
        Solution::Solution() {
            this->m = std::map<int, int>();
        }

        int Solution::majorityElement(vector<int> &nums) {
            for (int i: nums) {
                if (m.contains(i)) {
                    m[i] = m[i] + 1;
                    if (m[i] > nums.size() / 2) {
                        return i;
                    }
                } else {
                    m[i] = 1;
                }
            }
            return 0;
        }
    }

    namespace count_special_quadruplets {
        int Solution::countQuadruplets(vector<int> &nums) {
            int sum = 0;
            for (int i = 3; i < nums.size(); i++) {
                for (int j = 0; j < i - 2; j++) {
                    if (j == i) {
                        continue;
                    }
                    for (int k = j + 1; k < i - 1; k++) {
                        if (k == i) {
                            continue;
                        }
                        for (int l = k + 1; l < i; l++) {
                            if (l == i) {
                                continue;
                            }
                            if (nums[k] + nums[j] + nums[l] == nums[i]) {
                                sum++;
                            }
                        }
                    }
                }
            }
            return sum;
        }
    }
}