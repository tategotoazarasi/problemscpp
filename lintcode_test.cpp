//
// Created by tategotoazarasi on 2022/1/7.
//
#include "lintcode.h"
#include "gtest/gtest.h"
#include <vector>

using namespace std;

namespace lintcode {
	namespace license_key_formatting {
		TEST(license_key_formatting, case1) {
			auto s = string("5F3Z-2e-9-w");
			ASSERT_EQ("5F3Z-2E9W", Solution::licenseKeyFormatting(s, 4));
		}

		TEST(license_key_formatting, case2) {
			auto s = string("2-5g-3-J");
			ASSERT_EQ("2-5G-3J", Solution::licenseKeyFormatting(s, 2));
		}
	}// namespace license_key_formatting

	namespace distribute_candies {
		TEST(distribute_candies, case1) {
			int input[] = {
			        1,
			        1,
			        2,
			        2,
			        3,
			        3,
			};
			auto vec = vector<int>(begin(input), end(input));
			ASSERT_EQ(3, Solution::distributeCandies(vec));
		}

		TEST(distribute_candies, case2) {
			int input[] = {1, 1, 2, 2, 3, 3, 4, 5, 6, 6, 7, 8};
			auto vec    = vector<int>(begin(input), end(input));
			ASSERT_EQ(6, Solution::distributeCandies(vec));
		}
	}// namespace distribute_candies

	namespace remove_extra {
		TEST(remove_extra, case1) {
			string input = "The  sky   is blue";
			ASSERT_EQ("The sky is blue", Solution::removeExtra(input));
		}

		TEST(remove_extra, case2) {
			string input = "  low               ercase  ";
			ASSERT_EQ("low ercase", Solution::removeExtra(input));
		}
	}// namespace remove_extra

	namespace fibonacci {
		TEST(fibonacci, case1) {
			ASSERT_EQ(0, Solution::fibonacci(1));
		}

		TEST(fibonacci, case2) {
			ASSERT_EQ(1, Solution::fibonacci(2));
		}
	}// namespace fibonacci

	namespace character_deletion {
		TEST(character_deletion, case1) {
			auto str = string("They are students");
			auto sub = string("aeiou");
			ASSERT_EQ("Thy r stdnts", Solution::CharacterDeletion(str, sub));
		}
	}// namespace character_deletion

	namespace judge_circle {
		TEST(judge_circle, case1) {
			auto str = string("UD");
			ASSERT_TRUE(Solution::judgeCircle(str));
		}

		TEST(judge_circle, case2) {
			auto str = string("LL");
			ASSERT_FALSE(Solution::judgeCircle(str));
		}
	}// namespace judge_circle
}// namespace lintcode
