//
// Created by wangzhiheng on 10/11/2026.
//

#ifndef PROBLEMSCPP_LEETCODE_HW_H
#define PROBLEMSCPP_LEETCODE_HW_H
#include <string>
#include <vector>

using namespace std;

namespace leetcode::hw {
	namespace maximum_binary_string_after_change {
		class Solution {
		public:
			static string maximumBinaryString(string binary);
		};
	}// namespace maximum_binary_string_after_change

	namespace climbing_stairs_ii {
		class Solution {
		public:
			static int climbStairs(int n, vector<int> &costs);
		};
	}// namespace climbing_stairs_ii
}// namespace leetcode::hw

#endif//PROBLEMSCPP_LEETCODE_HW_H
