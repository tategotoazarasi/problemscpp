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
            static std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string> &);
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

            void insert(const std::string &str);

            bool dfs(TrieNode *, const std::string &, int, bool);
        };
    }

    namespace excel_sheet_column_number {
        class Solution {
        public:
            static int titleToNumber(const std::string &columnTitle);
        };
    }

    namespace excel_sheet_column_title {
        class Solution {
        public:
            static std::string convertToTitle(int columnNumber);
        };
    }

    namespace majority_element {
        class Solution {
        private:
            std::map<int, int> map;
        public:
            Solution();

            int majorityElement(std::vector<int> &nums);
        };
    }
};


#endif //PROBLEMSCPP_LEETCODE_H
