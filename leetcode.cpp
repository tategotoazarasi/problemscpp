//
// Created by tategotoazarasi on 2021/12/29.
//

#include"leetcode.h"
#include<cmath>
#include<algorithm>
#include<iostream>

using namespace std;

namespace leetcode {
    bool TreeNode::operator==(const TreeNode &node) const {
        if (this->left != nullptr && node.left == nullptr) {
            return false;
        }
        if (this->left == nullptr && node.left != nullptr) {
            return false;
        }
        if (this->right != nullptr && node.right == nullptr) {
            return false;
        }
        if (this->right == nullptr && node.right != nullptr) {
            return false;
        }
        if (this->left != nullptr && node.left != nullptr && (*this->left) != (*node.left)) {
            return false;
        }
        if (this->right != nullptr && node.right != nullptr && (*this->right) != (*node.right)) {
            return false;
        }
        return this->val == node.val;
    }

    bool TreeNode::operator!=(const TreeNode &node) const {
        return !((*this) == node);
    }

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

    namespace hand_of_straights {
        bool Solution::isNStraightHand(vector<int> &hand, int groupSize) {
            if (hand.size() % groupSize != 0) {
                return false;
            }
            if (groupSize == 1) {
                return true;
            }
            sort(hand.begin(), hand.end());
            auto len = hand.size() / groupSize;
            for (int i = 0; i < len; i++) {
                int current = *hand.begin();
                hand.erase(hand.begin());
                for (int j = 1; j < groupSize; j++) {
                    auto next = find(hand.begin(), hand.end(), current + 1);
                    if (next == hand.end()) {
                        return false;
                    } else {
                        current = *next;
                        hand.erase(next);
                    }
                }
            }
            return true;
        }
    }

    namespace perfect_number {
        bool Solution::checkPerfectNumber(int num) {
            int sum = 0;
            int max = num;
            for (int i = 1; i < max; i++) {
                if (num % i == 0) {
                    sum += i;
                    if (i != 1) {
                        sum += num / i;
                    }
                    max = num / i;
                }
            }
            return sum == num;
        }
    }

    namespace convert_bst_to_greater_tree {
        TreeNode *Solution::convertBST(TreeNode *root) {
            if (root == nullptr) {
                return nullptr;
            }
            FriendTreeNode *sum = Solution::copy(root);
            get_sum(sum);
            sum->val = sum->sum - (sum->left == nullptr ? 0 : sum->left->sum);
            Solution::convert(sum);
            return root;
        }

        FriendTreeNode *Solution::copy(TreeNode *node) {
            auto *ret = new FriendTreeNode(node->val, node);
            if (node->left != nullptr) {
                ret->left = Solution::copy(node->left);
            }
            if (node->right != nullptr) {
                ret->right = Solution::copy(node->right);
            }
            return ret;
        }

        void Solution::get_sum(FriendTreeNode *node) {
            if (node->left != nullptr) {
                get_sum(node->left);
                node->sum += node->left->sum;
            }
            if (node->right != nullptr) {
                get_sum(node->right);
                node->sum += node->right->sum;
            }
        }

        void Solution::convert(FriendTreeNode *sum_node) {
            if (sum_node->right != nullptr) {
                sum_node->right->val = sum_node->val - sum_node->friend_node->val -
                                       (sum_node->right->left == nullptr ? 0 : sum_node->right->left->sum);
                Solution::convert(sum_node->right);
            }
            if (sum_node->left != nullptr) {
                sum_node->left->val = sum_node->val + sum_node->left->friend_node->val +
                                      (sum_node->left->right == nullptr ? 0 : sum_node->left->right->sum);
                Solution::convert(sum_node->left);
            }
            sum_node->friend_node->val = sum_node->val;
        }
    }

    namespace convert_1d_array_into_2d_array {
        vector<vector<int>> Solution::construct2DArray(vector<int> &original, int m, int n) {
            if (original.size() != m * n) {
                return {
                };
            }
            auto ans = vector<vector<int >>();
            int count = 0;
            for (int i = 0; i < m; i++) {
                auto row = vector<int>();
                for (int j = 0; j < n; j++) {
                    row.push_back(original[count++]);
                }
                ans.push_back(row);
            }
            return ans;
        }
    }
}