//
// Created by wangzhiheng on 10/11/2026.
//
#include "leetcode_hw.h"
#include <gtest/gtest.h>

using namespace std;

namespace leetcode::hw {
	namespace maximum_binary_string_after_change {
		TEST(maximum_binary_string_after_change, case1) {
			ASSERT_EQ(Solution::maximumBinaryString("000110"), "111011");
		}
		TEST(maximum_binary_string_after_change, case2) {
			ASSERT_EQ(Solution::maximumBinaryString("01"), "01");
		}
		TEST(maximum_binary_string_after_change, case3) {
			ASSERT_EQ(Solution::maximumBinaryString("1100"), "1110");
		}
		TEST(maximum_binary_string_after_change, case4) {
			ASSERT_EQ(Solution::maximumBinaryString("11"), "11");
		}
		TEST(maximum_binary_string_after_change, case5) {
			ASSERT_EQ(Solution::maximumBinaryString("101010111011001101000110010001100001111"), "111111111111111111101111111111111111111");
		}
	}// namespace maximum_binary_string_after_change

	namespace climbing_stairs_ii {
		TEST(climbing_stairs_ii, case1) {
			vector costs = {1, 2, 3, 4};
			ASSERT_EQ(13, Solution::climbStairs(4, costs));
		}

		TEST(climbing_stairs_ii, case2) {
			vector costs = {5, 1, 6, 2};
			ASSERT_EQ(11, Solution::climbStairs(4, costs));
		}

		TEST(climbing_stairs_ii, case3) {
			vector costs = {9, 8, 3};
			ASSERT_EQ(12, Solution::climbStairs(3, costs));
		}
	}// namespace climbing_stairs_ii

	namespace minimum_cost_to_acquire_required_items {
		TEST(minimum_cost_to_acquire_required_items, case1) {
			ASSERT_EQ(3, Solution::minimumCost(3, 2, 1, 3, 2));
		}

		TEST(minimum_cost_to_acquire_required_items, case2) {
			ASSERT_EQ(22, Solution::minimumCost(5, 4, 15, 2, 3));
		}

		TEST(minimum_cost_to_acquire_required_items, case3) {
			ASSERT_EQ(0, Solution::minimumCost(5, 4, 15, 0, 0));
		}
	}// namespace minimum_cost_to_acquire_required_items

	namespace longest_valid_parentheses {
		TEST(longest_valid_parentheses, case1) {
			ASSERT_EQ(2, Solution::longestValidParentheses("(()"));
		}

		TEST(longest_valid_parentheses, case2) {
			ASSERT_EQ(4, Solution::longestValidParentheses(")()())"));
		}

		TEST(longest_valid_parentheses, case3) {
			ASSERT_EQ(0, Solution::longestValidParentheses(""));
		}

		TEST(longest_valid_parentheses, case4) {
			ASSERT_EQ(6, Solution::longestValidParentheses("()(())"));
		}

		TEST(longest_valid_parentheses, case5) {
			ASSERT_EQ(6, Solution::longestValidParentheses("(()())"));
		}

		TEST(longest_valid_parentheses, case6) {
			ASSERT_EQ(8, Solution::longestValidParentheses("((()))())"));
		}
	}// namespace longest_valid_parentheses

	namespace longest_strictly_increasing_or_strictly_decreasing_subarray {
		TEST(longest_strictly_increasing_or_strictly_decreasing_subarray, case1) {
			vector nums = {1, 4, 3, 3, 2};
			ASSERT_EQ(2, Solution::longestMonotonicSubarray(nums));
		}

		TEST(longest_strictly_increasing_or_strictly_decreasing_subarray, case2) {
			vector nums = {3, 3, 3, 3};
			ASSERT_EQ(1, Solution::longestMonotonicSubarray(nums));
		}

		TEST(longest_strictly_increasing_or_strictly_decreasing_subarray, case3) {
			vector nums = {3, 2, 1};
			ASSERT_EQ(3, Solution::longestMonotonicSubarray(nums));
		}

		TEST(longest_strictly_increasing_or_strictly_decreasing_subarray, case4) {
			vector nums = {2, 1, 10};
			ASSERT_EQ(2, Solution::longestMonotonicSubarray(nums));
		}
	}// namespace longest_strictly_increasing_or_strictly_decreasing_subarray
}// namespace leetcode::hw