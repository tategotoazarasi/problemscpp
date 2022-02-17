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
			auto vec = vector(begin(input), end(input));
			ASSERT_EQ(3, Solution::distributeCandies(vec));
		}

		TEST(distribute_candies, case2) {
			int input[] = {1, 1, 2, 2, 3, 3, 4, 5, 6, 6, 7, 8};
			auto vec    = vector(begin(input), end(input));
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

	namespace convert {
		TEST(convert, case1) {
			ASSERT_EQ("1C", Solution::convert(3));
		}

		TEST(convert, case2) {
			ASSERT_EQ("1AB", Solution::convert(28));
		}

		TEST(convert, case3) {
			ASSERT_EQ("1424501424501425MN", Solution::convert(1000000000000000000));
		}

		TEST(convert, case4) {
			ASSERT_EQ("1ZZ", Solution::convert(702));
		}
	}// namespace convert

	namespace min_path_sum {
		TEST(min_path_sum, case1) {
			int input[3][3] = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
			auto vec        = vector<vector<int>>();
			vec.resize(3);
			for(int i = 0; i < 3; i++) {
				const auto to_add = vector(begin(input[i]), end(input[i]));
				vec[i]            = to_add;
			}
			auto sol = Solution();
			ASSERT_EQ(7, sol.minPathSum(vec));
		}

		TEST(min_path_sum, case2) {
			int input[1][3] = {{1, 3, 2}};
			auto vec        = vector<vector<int>>();
			vec.resize(1);
			for(int i = 0; i < 1; i++) {
				const auto to_add = vector(begin(input[i]), end(input[i]));
				vec[i]            = to_add;
			}
			auto sol = Solution();
			ASSERT_EQ(6, sol.minPathSum(vec));
		}

		TEST(min_path_sum, case3) {
			int input[8][8] = {{1, 4, 8, 6, 2, 2, 1, 7}, {4, 7, 3, 1, 4, 5, 5, 1}, {8, 8, 2, 1, 1, 8, 0, 1}, {8, 9, 2, 9, 8, 0, 8, 9}, {5, 7, 5, 7, 1, 8, 5, 5}, {7, 0, 9, 4, 5, 6, 5, 6}, {4, 9, 9, 7, 9, 1, 9, 0}};
			auto vec        = vector<vector<int>>();
			vec.resize(8);
			for(int i = 0; i < 8; i++) {
				const auto to_add = vector(begin(input[i]), end(input[i]));
				vec[i]            = to_add;
			}
			auto sol = Solution();
			ASSERT_EQ(37, sol.minPathSum(vec));
		}
	}// namespace min_path_sum

	namespace digit_counts {
		TEST(digit_counts, case1) {
			ASSERT_EQ(1, Solution::digitCounts(1, 1));
		}

		TEST(digit_counts, case2) {
			ASSERT_EQ(5, Solution::digitCounts(1, 12));
		}

		TEST(digit_counts, case3) {
			ASSERT_EQ(2, Solution::digitCounts(0, 10));
		}
	}// namespace digit_counts
}// namespace lintcode
