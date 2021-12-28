//
// Created by tategotoazarasi on 2021/12/28.
//

#ifndef PROBLEMSCPP_CONCATENATED_WORDS_H
#define PROBLEMSCPP_CONCATENATED_WORDS_H

#include <string>
#include <vector>

namespace concatenated_words {
    class Solution {
    public:
        static std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string> &);
    };

    class TrieNode {
    public:
        bool is_end;
        char ch;
        TrieNode *nexts[26] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                               nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
                               nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

        explicit TrieNode(char);

        void insert(const std::string &str);

        bool dfs(TrieNode *, const std::string &, int, bool);
    };
}


#endif //PROBLEMSCPP_CONCATENATED_WORDS_H
