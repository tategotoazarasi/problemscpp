//
// Created by tategotoazarasi on 2021/12/29.
//

#ifndef PROBLEMSCPP_LEETCODE_H
#define PROBLEMSCPP_LEETCODE_H

#include<string>
#include<vector>
#include<map>

using namespace std;

namespace leetcode {
    namespace concatenated_words {
        class Solution {
        public:
            static vector<string> findAllConcatenatedWordsInADict(vector<string> &);
        };

        class TrieNode {
        public:
            bool is_end;
            char ch;
            TrieNode *nexts[26] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                                   nullptr,
                                   nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                                   nullptr,
                                   nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

            explicit TrieNode(char);

            void insert(const string &str);

            bool dfs(TrieNode *, const string &, int, bool);
        };
    }

    namespace excel_sheet_column_number {
        class Solution {
        public:
            static int titleToNumber(const string &columnTitle);
        };
    }

    namespace excel_sheet_column_title {
        class Solution {
        public:
            static string convertToTitle(int columnNumber);
        };
    }

    namespace majority_element {
        class Solution {
        private:
            map<int, int> m;
        public:
            Solution();

            int majorityElement(vector<int> &nums);
        };
    }

    namespace count_special_quadruplets {
        class Solution {
        public:
            static int countQuadruplets(vector<int> &);
        };
    }

    namespace hand_of_straights {
        class Solution {
        public:
            static bool isNStraightHand(vector<int> &hand, int groupSize);
        };
    }

    namespace perfect_number {
        class Solution {
        public:
            static bool checkPerfectNumber(int num);
        };
    }
};


#endif //PROBLEMSCPP_LEETCODE_H
