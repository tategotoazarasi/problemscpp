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

	namespace minimum_cost_to_acquire_required_items {
		class Solution {
		public:
			long long static minimumCost(int cost1, int cost2, int costBoth, int need1, int need2);
		};
	}// namespace minimum_cost_to_acquire_required_items

	namespace longest_valid_parentheses {
		struct Node {
			char c;
			Node *lend = nullptr;
			int pos;
		};
		class Solution {
		public:
			int static longestValidParentheses(string s);
		};
	}// namespace longest_valid_parentheses

	namespace longest_strictly_increasing_or_strictly_decreasing_subarray {
		class Solution {
		public:
			int static longestMonotonicSubarray(vector<int> &nums);
		};
	}// namespace longest_strictly_increasing_or_strictly_decreasing_subarray

	namespace restore_ip_addresses {
		class Solution {
		public:
			static vector<string> restoreIpAddresses(string s);
			static bool valid(const string &s, int a, int b);
			static void dfs(const string &s, int cur, int remain, vector<string> &res, array<int, 3> his);
		};
	}// namespace restore_ip_addresses

	namespace count_non_decreasing_subarrays_after_k_operations {
		class Solution {
		public:
			long long static countNonDecreasingSubarrays(vector<int> &nums, int k);
		};
	}// namespace count_non_decreasing_subarrays_after_k_operations

	namespace candy {
		class Solution {
		public:
			int static candy(vector<int> &ratings);
		};
	}// namespace candy
}// namespace leetcode::hw

#endif//PROBLEMSCPP_LEETCODE_HW_H
