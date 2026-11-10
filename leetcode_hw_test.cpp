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
}// namespace leetcode::hw