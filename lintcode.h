//
// Created by tategotoazarasi on 2021/12/29.
//

#ifndef PROBLEMSCPP_LINTCODE_H
#define PROBLEMSCPP_LINTCODE_H

#include<string>
#include<vector>

using namespace std;

namespace lintcode {
    namespace lintcode1214 {
        class Solution {
        public:
            /**
            * @param S: a string
            * @param K: a integer
            * @return: return a string
            */
            static string licenseKeyFormatting(string &, int);
        };
    }

    namespace lintcode1163 {
        class Solution {
        public:
            /**
             * @param candies: a list of integers
             * @return: return a integer
             */
            static int distributeCandies(vector<int> &candies);
        };
    }
}


#endif //PROBLEMSCPP_LINTCODE_H
