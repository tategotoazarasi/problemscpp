#include "leetcode.h"
#include "gtest/gtest.h"
#include <algorithm>
#include <vector>

using namespace std;

namespace leetcode {
	namespace excel_sheet_column_title {
		TEST(excel_sheet_column_title, case1) {
			ASSERT_EQ(std::string("A"), Solution::convertToTitle(1));
		}

		TEST(excel_sheet_column_title, case2) {
			ASSERT_EQ(std::string("AB"), Solution::convertToTitle(28));
		}

		TEST(excel_sheet_column_title, case3) {
			ASSERT_EQ(std::string("ZY"), Solution::convertToTitle(701));
		}

		TEST(excel_sheet_column_title, case4) {
			ASSERT_EQ(std::string("FXSHRXW"), Solution::convertToTitle(2147483647));
		}

		TEST(excel_sheet_column_title, case5) {
			ASSERT_EQ(std::string("AZ"), Solution::convertToTitle(52));
		}
	}// namespace excel_sheet_column_title

	namespace majority_element {
		TEST(majority_element, case1) {
			auto sol  = Solution();
			int arr[] = {3, 2, 3};
			auto vec  = std::vector(arr, arr + 3);
			ASSERT_EQ(3, sol.majorityElement(vec));
		}

		TEST(majority_element, case2) {
			auto sol  = Solution();
			int arr[] = {2, 2, 1, 1, 1, 2, 2};
			auto vec  = std::vector(arr, arr + 7);
			ASSERT_EQ(2, sol.majorityElement(vec));
		}

		TEST(majority_element, case3) {
			auto sol  = Solution();
			int arr[] = {3, 2, 3};
			auto vec  = std::vector(arr, arr + 3);
			ASSERT_EQ(3, sol.majorityElement(vec));
		}
	}// namespace majority_element

	namespace excel_sheet_column_number {
		TEST(excel_sheet_column_number, case1) {
			ASSERT_EQ(1, Solution::titleToNumber("A"));
		}

		TEST(excel_sheet_column_number, case2) {
			ASSERT_EQ(28, Solution::titleToNumber("AB"));
		}

		TEST(excel_sheet_column_number, case3) {
			ASSERT_EQ(701, Solution::titleToNumber("ZY"));
		}

		TEST(excel_sheet_column_number, case4) {
			ASSERT_EQ(2147483647, Solution::titleToNumber("FXSHRXW"));
		}
	}// namespace excel_sheet_column_number

	namespace concatenated_words {
		TEST(concatenated_words, case1) {
			basic_string<char> input[] = {
			        "cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat",
			        "ratcatdogcat"};
			auto vec           = vector(begin(input), end(input));
			const auto ans     = Solution::findAllConcatenatedWordsInADict(vec);
			string outputstr[] = {"catsdogcats", "dogcatsdog", "ratcatdogcat"};
			const auto output  = vector(begin(outputstr), end(outputstr));
			for(const string &str: ans) {
				ASSERT_TRUE(find(output.cbegin(), output.cend(), str) != output.cend());
			}
			for(const string &str: output) {
				ASSERT_TRUE(find(ans.cbegin(), ans.cend(), str) != ans.cend());
			}
			ASSERT_EQ(ans.size(), output.size());
		}

		TEST(concatenated_words, case2) {
			basic_string<char> input[] = {"cat", "dog", "catdog"};
			auto vec                   = vector(begin(input), end(input));
			const auto ans             = Solution::findAllConcatenatedWordsInADict(vec);
			string outputstr[]         = {"catdog"};
			const auto output          = vector(begin(outputstr), end(outputstr));
			for(const string &str: ans) {
				ASSERT_TRUE(find(output.cbegin(), output.cend(), str) != output.cend());
			}
			for(const string &str: output) {
				ASSERT_TRUE(find(ans.cbegin(), ans.cend(), str) != ans.cend());
			}
			ASSERT_EQ(ans.size(), output.size());
		}

		TEST(concatenated_words, case4) {
			basic_string<char> input[] = {"nuqhmfj", "mf", "jf", "n", "u", "q", "h"};
			auto vec                   = vector(begin(input), end(input));
			const auto ans             = Solution::findAllConcatenatedWordsInADict(vec);
			const auto output          = vector<string>();
			for(const string &str: ans) {
				ASSERT_TRUE(find(output.cbegin(), output.cend(), str) != output.cend());
			}
			for(const string &str: output) {
				ASSERT_TRUE(find(ans.cbegin(), ans.cend(), str) != ans.cend());
			}
			ASSERT_EQ(ans.size(), output.size());
		}
	}// namespace concatenated_words

	namespace count_special_quadruplets {
		TEST(count_special_quadruplets, case1) {
			int input[] = {1, 2, 3, 6};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(1, Solution::countQuadruplets(vec));
		}

		TEST(count_special_quadruplets, case2) {
			int input[] = {3, 3, 6, 4, 5};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(0, Solution::countQuadruplets(vec));
		}

		TEST(count_special_quadruplets, case3) {
			int input[] = {1, 1, 1, 3, 5};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(4, Solution::countQuadruplets(vec));
		}

		TEST(count_special_quadruplets, case4) {
			int input[] = {28, 8, 49, 85, 37, 90, 20, 8};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(1, Solution::countQuadruplets(vec));
		}
	}// namespace count_special_quadruplets

	namespace hand_of_straights {
		TEST(hand_of_straights, case1) {
			int input[] = {1, 2, 3, 6, 2, 3, 4, 7, 8};
			auto vec    = vector(begin(input), end(input));
			ASSERT_TRUE(Solution::isNStraightHand(vec, 3));
		}

		TEST(hand_of_straights, case2) {
			int input[] = {1, 2, 3, 4, 5};
			auto vec    = vector(begin(input), end(input));
			ASSERT_FALSE(Solution::isNStraightHand(vec, 4));
		}

		TEST(hand_of_straights, case3) {
			int input[] = {1, 2, 3, 4, 5, 6};
			auto vec    = vector(begin(input), end(input));
			ASSERT_TRUE(Solution::isNStraightHand(vec, 2));
		}

		TEST(hand_of_straights, case4) {
			int input[] = {
			        9, 13, 15, 23, 22, 25, 4, 4, 29, 15, 8, 23, 12, 19, 24, 17, 18, 11, 22, 24, 17, 17, 10, 23,
			        21, 18, 14, 18, 7, 6, 3, 6, 19, 11, 16, 11, 12, 13, 8, 26, 17, 20, 13, 19, 22, 21, 27, 9, 20,
			        15, 20, 27, 8, 13, 25, 23, 22, 15, 9, 14, 20, 10, 6, 5, 14, 12, 7, 16, 21, 18, 21, 24, 23,
			        10, 21, 16, 18, 16, 18, 5, 20, 19, 20, 10, 14, 26, 2, 9, 19, 12, 28, 17, 5, 7, 25, 22, 16,
			        17, 21, 11};
			auto vec = vector(begin(input), end(input));
			ASSERT_FALSE(Solution::isNStraightHand(vec, 10));
		}
	}// namespace hand_of_straights

	namespace perfect_number {
		TEST(perfect_number, case1) {
			ASSERT_TRUE(Solution::checkPerfectNumber(28));
		}

		TEST(perfect_number, case2) {
			ASSERT_TRUE(Solution::checkPerfectNumber(6));
		}

		TEST(perfect_number, case3) {
			ASSERT_TRUE(Solution::checkPerfectNumber(496));
		}

		TEST(perfect_number, case4) {
			ASSERT_TRUE(Solution::checkPerfectNumber(8128));
		}

		TEST(perfect_number, case5) {
			ASSERT_FALSE(Solution::checkPerfectNumber(2));
		}
	}// namespace perfect_number

	namespace convert_bst_to_greater_tree {
		TEST(convert_bst_to_greater_tree, case1) {
			auto *input        = new TreeNode(4, new TreeNode(1, new TreeNode(0), new TreeNode(2, nullptr, new TreeNode(3))),
			                                  new TreeNode(6, new TreeNode(5), new TreeNode(7, nullptr, new TreeNode(8))));
			const auto *ans    = new TreeNode(30, new TreeNode(36, new TreeNode(36), new TreeNode(35, nullptr, new TreeNode(33))),
			                                  new TreeNode(21, new TreeNode(26), new TreeNode(15, nullptr, new TreeNode(8))));
			const auto *output = Solution::convertBST(input);
			ASSERT_TRUE(*ans == *output);
		}
	}// namespace convert_bst_to_greater_tree

	namespace convert_1d_array_into_2d_array {
		TEST(convert_1d_array_into_2d_array, case1) {
			int input[4]    = {1, 2, 3, 4};
			auto vec        = vector(begin(input), end(input));
			const auto ans  = Solution::construct2DArray(vec, 2, 2);
			int output1[]   = {1, 2};
			int output2[]   = {3, 4};
			const auto vec1 = vector(begin(output1), end(output1));
			const auto vec2 = vector(begin(output2), end(output2));
			auto vec_output = vector<vector<int>>();
			vec_output.push_back(vec1);
			vec_output.push_back(vec2);
			ASSERT_EQ(vec_output, ans);
		}
	}// namespace convert_1d_array_into_2d_array

	namespace elimination_game {
		TEST(elimination_game, case1) {
			ASSERT_EQ(1, Solution::lastRemaining(1));
			ASSERT_EQ(2, Solution::lastRemaining(2));
			ASSERT_EQ(2, Solution::lastRemaining(3));
			ASSERT_EQ(2, Solution::lastRemaining(4));
			ASSERT_EQ(2, Solution::lastRemaining(5));
			ASSERT_EQ(4, Solution::lastRemaining(6));
			ASSERT_EQ(4, Solution::lastRemaining(7));
			ASSERT_EQ(6, Solution::lastRemaining(8));
			ASSERT_EQ(6, Solution::lastRemaining(9));
		}
	}// namespace elimination_game

	namespace check_if_all_as_appears_before_all_bs {
		TEST(check_if_all_as_appears_before_all_bs, case1) {
			ASSERT_TRUE(Solution::checkString("aaabbb"));
		}

		TEST(check_if_all_as_appears_before_all_bs, case2) {
			ASSERT_FALSE(Solution::checkString("abab"));
		}

		TEST(check_if_all_as_appears_before_all_bs, case3) {
			ASSERT_TRUE(Solution::checkString("bbb"));
		}
	}// namespace check_if_all_as_appears_before_all_bs

	namespace number_of_laser_beams_in_a_bank {
		TEST(number_of_laser_beams_in_a_bank, case1) {
			string input[] = {"011001", "000000", "010100", "001000"};
			auto vec       = vector(begin(input), end(input));
			ASSERT_EQ(8, Solution::numberOfBeams(vec));
		}

		TEST(number_of_laser_beams_in_a_bank, case2) {
			string input[] = {"000", "111", "000"};
			auto vec       = vector(begin(input), end(input));
			ASSERT_EQ(0, Solution::numberOfBeams(vec));
		}
	}// namespace number_of_laser_beams_in_a_bank

	namespace destroying_asteroids {
		TEST(destroying_asteroids, case1) {
			int input[] = {3, 9, 19, 5, 21};
			auto vec    = vector(begin(input), end(input));
			ASSERT_TRUE(Solution::asteroidsDestroyed(10, vec));
		}

		TEST(destroying_asteroids, case2) {
			int input[] = {4, 9, 23, 4};
			auto vec    = vector(begin(input), end(input));
			ASSERT_FALSE(Solution::asteroidsDestroyed(5, vec));
		}
	}// namespace destroying_asteroids

	namespace day_of_the_week {
		TEST(day_of_the_week, case1) {
			ASSERT_EQ("Saturday", Solution::dayOfTheWeek(31, 8, 2019));
		}

		TEST(day_of_the_week, case2) {
			ASSERT_EQ("Sunday", Solution::dayOfTheWeek(18, 7, 1999));
		}

		TEST(day_of_the_week, case3) {
			ASSERT_EQ("Sunday", Solution::dayOfTheWeek(15, 8, 1993));
		}

		TEST(day_of_the_week, case4) {
			ASSERT_EQ("Monday", Solution::dayOfTheWeek(29, 2, 2016));
		}

		TEST(day_of_the_week, case5) {
			ASSERT_EQ("Tuesday", Solution::dayOfTheWeek(31, 8, 2100));
		}
	}// namespace day_of_the_week

	namespace replace_all_s_to_avoid_consecutive_repeating_characters {
		TEST(replace_all_s_to_avoid_consecutive_repeating_characters, case1) {
			ASSERT_EQ("azs", Solution::modifyString("?zs"));
		}

		TEST(replace_all_s_to_avoid_consecutive_repeating_characters, case2) {
			ASSERT_EQ("ubvaw", Solution::modifyString("ubv?w"));
		}

		TEST(replace_all_s_to_avoid_consecutive_repeating_characters, case3) {
			ASSERT_EQ("jaqgacb", Solution::modifyString("j?qg??b"));
		}

		TEST(replace_all_s_to_avoid_consecutive_repeating_characters, case4) {
			ASSERT_EQ("abywaipkja", Solution::modifyString("??yw?ipkj?"));
		}
	}// namespace replace_all_s_to_avoid_consecutive_repeating_characters

	namespace simplify_path {
		TEST(simplify_path, case1) {
			ASSERT_EQ("/home", Solution::simplifyPath("/home/"));
		}

		TEST(simplify_path, case2) {
			ASSERT_EQ("/", Solution::simplifyPath("/../"));
		}

		TEST(simplify_path, case3) {
			ASSERT_EQ("/home/foo", Solution::simplifyPath("/home//foo/"));
		}

		TEST(simplify_path, case4) {
			ASSERT_EQ("/c", Solution::simplifyPath("/a/./b/../../c/"));
		}

		TEST(simplify_path, case5) {
			ASSERT_EQ("/a/b/c", Solution::simplifyPath("/a//b////c/d//././/.."));
		}
	}// namespace simplify_path

	namespace maximum_nesting_depth_of_the_parentheses {
		TEST(maximum_nesting_depth_of_the_parentheses, case1) {
			ASSERT_EQ(3, Solution::maxDepth("(1+(2*3)+((8)/4))+1"));
		}

		TEST(maximum_nesting_depth_of_the_parentheses, case2) {
			ASSERT_EQ(3, Solution::maxDepth("(1)+((2))+(((3)))"));
		}

		TEST(maximum_nesting_depth_of_the_parentheses, case3) {
			ASSERT_EQ(1, Solution::maxDepth("1+(2*3)/(2-1)"));
		}

		TEST(maximum_nesting_depth_of_the_parentheses, case4) {
			ASSERT_EQ(0, Solution::maxDepth("1"));
		}
	}// namespace maximum_nesting_depth_of_the_parentheses

	namespace gray_code {
		TEST(gray_code, case1) {
			int output[]   = {0, 1, 3, 2};
			const auto vec = vector(begin(output), end(output));
			ASSERT_EQ(vec, Solution::grayCode(2));
		}
	}// namespace gray_code

	namespace minimum_swaps_to_group_all_1s_together_ii {
		TEST(minimum_swaps_to_group_all_1s_together_ii, case1) {
			int input[] = {0, 1, 0, 1, 1, 0, 0};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(1, Solution::minSwaps(vec));
		}

		TEST(minimum_swaps_to_group_all_1s_together_ii, case2) {
			int input[] = {0, 1, 1, 1, 0, 0, 1, 1, 0};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(2, Solution::minSwaps(vec));
		}

		TEST(minimum_swaps_to_group_all_1s_together_ii, case3) {
			int input[] = {1, 1, 0, 0, 1};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(0, Solution::minSwaps(vec));
		}

		TEST(minimum_swaps_to_group_all_1s_together_ii, case4) {
			int input[] = {1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0,
			               1, 0, 0};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(7, Solution::minSwaps(vec));
		}
	}// namespace minimum_swaps_to_group_all_1s_together_ii

	namespace count_words_obtained_after_adding_a_letter {
		TEST(count_words_obtained_after_adding_a_letter, case1) {
			string input1[] = {"ant", "act", "tack"};
			auto vec1       = vector(begin(input1), end(input1));
			string input2[] = {"tack", "act", "acti"};
			auto vec2       = vector(begin(input2), end(input2));
			ASSERT_EQ(2, Solution::wordCount(vec1, vec2));
		}

		TEST(count_words_obtained_after_adding_a_letter, case2) {
			string input1[] = {"ab", "a"};
			auto vec1       = vector(begin(input1), end(input1));
			string input2[] = {"abc", "abcd"};
			auto vec2       = vector(begin(input2), end(input2));
			ASSERT_EQ(1, Solution::wordCount(vec1, vec2));
		}

		TEST(count_words_obtained_after_adding_a_letter, case3) {
			string input1[] = {"g", "vf", "ylpuk", "nyf", "gdj", "j", "fyqzg", "sizec"};
			auto vec1       = vector(begin(input1), end(input1));
			string input2[] = {"r", "am", "jg", "umhjo", "fov", "lujy", "b", "uz", "y"};
			auto vec2       = vector(begin(input2), end(input2));
			ASSERT_EQ(2, Solution::wordCount(vec1, vec2));
		}
	}// namespace count_words_obtained_after_adding_a_letter

	namespace slowest_key {
		TEST(slowest_key, case1) {
			int input[] = {9, 29, 49, 50};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ('c', Solution::slowestKey(vec, "cbcd"));
		}

		TEST(slowest_key, case2) {
			int input[] = {12, 23, 36, 46, 62};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ('a', Solution::slowestKey(vec, "spuda"));
		}
	}// namespace slowest_key

	namespace additive_number {
		TEST(additive_number, case1) {
			ASSERT_TRUE(Solution::isAdditiveNumber("112358"));
		}

		TEST(additive_number, case2) {
			ASSERT_TRUE(Solution::isAdditiveNumber("199100199"));
		}

		TEST(additive_number, case3) {
			ASSERT_FALSE(Solution::isAdditiveNumber("0235813"));
		}

		TEST(additive_number, case4) {
			ASSERT_TRUE(Solution::isAdditiveNumber("000000"));
		}

		TEST(additive_number, case5) {
			ASSERT_TRUE(Solution::isAdditiveNumber("11011"));
		}

		TEST(str2ui, case1) {
			const char input[] = {'2'};
			ASSERT_EQ(2, Solution::str2ui(input, 0, 1));
		}

		TEST(str2ui, case2) {
			const char input[] = {'2', '3', '4'};
			ASSERT_EQ(234, Solution::str2ui(input, 0, 3));
		}

		TEST(str2ui, case3) {
			const char input[] = {'2', '3', '4'};
			ASSERT_EQ(23, Solution::str2ui(input, 0, 2));
		}

		TEST(str2ui, case4) {
			const char input[] = {'2', '3', '4'};
			ASSERT_EQ(34, Solution::str2ui(input, 1, 2));
		}

		TEST(equal, case1) {
			const char input[] = {'1', '2'};
			ASSERT_TRUE(Solution::equal(string("12"), input, 0, 2));
		}

		TEST(equal, case2) {
			const char input[] = {'1', '2', '4'};
			ASSERT_TRUE(Solution::equal(string("12"), input, 0, 3));
		}

		TEST(equal, case3) {
			const char input[] = {'3', '2', '4'};
			ASSERT_FALSE(Solution::equal(string("12"), input, 0, 3));
		}

		TEST(equal, case4) {
			const char input[] = {'3', '2', '4', '5'};
			ASSERT_TRUE(Solution::equal(string("24"), input, 1, 4));
		}

		TEST(equal, case5) {
			const char input[] = {'3', '2', '4', '5'};
			ASSERT_FALSE(Solution::equal(string("2456"), input, 1, 4));
		}

		TEST(dfs, case1) {
			const char input[] = {'1', '1', '2'};
			ASSERT_TRUE(Solution::dfs(1, 1, input, 3, 2));
		}

		TEST(dfs, case2) {
			const char input[] = {'1', '1', '2', '3'};
			ASSERT_TRUE(Solution::dfs(1, 1, input, 4, 2));
		}

		TEST(dfs, case3) {
			const char input[] = {'1', '1', '2', '4'};
			ASSERT_FALSE(Solution::dfs(1, 1, input, 4, 2));
		}

		TEST(dfs, case4) {
			const char input[] = {'1', '1', '2', '3', '3', '4'};
			ASSERT_TRUE(Solution::dfs(11, 23, input, 6, 4));
		}
	}// namespace additive_number

	namespace decode_the_slanted_ciphertext {
		TEST(decode_the_slanted_ciphertext, case1) {
			ASSERT_EQ("cipher", Solution::decodeCiphertext("ch   ie   pr", 3));
		}

		TEST(decode_the_slanted_ciphertext, case2) {
			ASSERT_EQ("i love leetcode", Solution::decodeCiphertext("iveo    eed   l te   olc", 4));
		}

		TEST(decode_the_slanted_ciphertext, case3) {
			ASSERT_EQ("coding", Solution::decodeCiphertext("coding", 1));
		}

		TEST(decode_the_slanted_ciphertext, case4) {
			ASSERT_EQ(" abc", Solution::decodeCiphertext(" b  ac", 2));
		}
	}// namespace decode_the_slanted_ciphertext

	namespace increasing_triplet_subsequence {
		TEST(increasing_triplet_subsequence, case1) {
			int input[] = {1, 2, 3, 4, 5};
			auto vec    = vector(begin(input), end(input));
			ASSERT_TRUE(Solution::increasingTriplet(vec));
		}

		TEST(increasing_triplet_subsequence, case2) {
			int input[] = {5, 4, 3, 2, 1};
			auto vec    = vector(begin(input), end(input));
			ASSERT_FALSE(Solution::increasingTriplet(vec));
		}

		TEST(increasing_triplet_subsequence, case3) {
			int input[] = {2, 1, 5, 0, 4, 6};
			auto vec    = vector(begin(input), end(input));
			ASSERT_TRUE(Solution::increasingTriplet(vec));
		}

		TEST(increasing_triplet_subsequence, case4) {
			int input[] = {20, 100, 10, 12, 5, 13};
			auto vec    = vector(begin(input), end(input));
			ASSERT_TRUE(Solution::increasingTriplet(vec));
		}
	}// namespace increasing_triplet_subsequence

	namespace largest_number_at_least_twice_of_others {
		TEST(largest_number_at_least_twice_of_others, case1) {
			int input[] = {3, 6, 1, 0};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(1, Solution::dominantIndex(vec));
		}

		TEST(largest_number_at_least_twice_of_others, case2) {
			int input[] = {1, 2, 3, 4};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(-1, Solution::dominantIndex(vec));
		}

		TEST(largest_number_at_least_twice_of_others, case3) {
			int input[] = {1};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(0, Solution::dominantIndex(vec));
		}

		TEST(largest_number_at_least_twice_of_others, case4) {
			int input[] = {0, 0, 0, 1};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(3, Solution::dominantIndex(vec));
		}

		TEST(largest_number_at_least_twice_of_others, case5) {
			int input[] = {0, 0, 3, 2};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(-1, Solution::dominantIndex(vec));
		}
	}// namespace largest_number_at_least_twice_of_others

	namespace permutations {
		TEST(permutations, case1) {
			int input[] = {1};
			auto vec    = vector(begin(input), end(input));
			auto ans    = vector<vector<int>>();
			auto ans1   = vector<int>();
			ans1.push_back(1);
			ans.push_back(ans1);
			ASSERT_EQ(ans, Solution::permute(vec));
		}

		TEST(permutations, case2) {
			int input[] = {0, 1};
			auto vec    = vector(begin(input), end(input));
			auto ans    = vector<vector<int>>();
			auto ans1   = vector<int>();
			ans1.push_back(0);
			ans1.push_back(1);
			ans.push_back(ans1);
			auto ans2 = vector<int>();
			ans2.push_back(1);
			ans2.push_back(0);
			ans.push_back(ans2);
			ASSERT_EQ(ans, Solution::permute(vec));
		}

		TEST(permutations, case3) {
			int input[]       = {1, 2, 3};
			auto vec          = vector(begin(input), end(input));
			auto ans          = vector<vector<int>>();
			int outputs[6][3] = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
			for(auto &output: outputs) {
				ans.emplace_back(begin(output), end(output));
			}
			ASSERT_EQ(ans, Solution::permute(vec));
		}
	}// namespace permutations

	namespace calculate_money_in_leetcode_bank {
		TEST(calculate_money_in_leetcode_bank, case1) {
			ASSERT_EQ(10, Solution::totalMoney(4));
		}

		TEST(calculate_money_in_leetcode_bank, case2) {
			ASSERT_EQ(37, Solution::totalMoney(10));
		}

		TEST(calculate_money_in_leetcode_bank, case3) {
			ASSERT_EQ(96, Solution::totalMoney(20));
		}
	}// namespace calculate_money_in_leetcode_bank

	namespace divide_a_string_into_groups_of_size_k {
		TEST(divide_a_string_into_groups_of_size_k, case1) {
			string output[] = {"abc", "def", "ghi"};
			const auto vec  = vector(begin(output), end(output));
			ASSERT_EQ(vec, Solution::divideString("abcdefghi", 3, 'x'));
		}

		TEST(divide_a_string_into_groups_of_size_k, case2) {
			string output[] = {"abc", "def", "ghi", "jxx"};
			const auto vec  = vector(begin(output), end(output));
			ASSERT_EQ(vec, Solution::divideString("abcdefghij", 3, 'x'));
		}

		TEST(divide_a_string_into_groups_of_size_k, case3) {
			string output[] = {"ctoyjrwt", "ngqwtnnn"};
			const auto vec  = vector(begin(output), end(output));
			ASSERT_EQ(vec, Solution::divideString("ctoyjrwtngqwt", 8, 'n'));
		}
	}// namespace divide_a_string_into_groups_of_size_k

	namespace minimum_moves_to_reach_target_score {
		TEST(minimum_moves_to_reach_target_score, case1) {
			ASSERT_EQ(4, Solution::minMoves(5, 0));
		}

		TEST(minimum_moves_to_reach_target_score, case2) {
			ASSERT_EQ(7, Solution::minMoves(19, 2));
		}

		TEST(minimum_moves_to_reach_target_score, case3) {
			ASSERT_EQ(4, Solution::minMoves(10, 4));
		}
	}// namespace minimum_moves_to_reach_target_score

	namespace maximum_running_time_of_n_computers {
		TEST(maximum_running_time_of_n_computers, case1) {
			int input[] = {3, 3, 3};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(4, Solution::maxRunTime(2, vec));
		}

		TEST(maximum_running_time_of_n_computers, case2) {
			int input[] = {1, 1, 1, 1};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(2, Solution::maxRunTime(2, vec));
		}
	}// namespace maximum_running_time_of_n_computers

	namespace coun_vowels_permutation {
		TEST(coun_vowels_permutation, case1) {
			ASSERT_EQ(5, Solution::countVowelPermutation(1));
		}

		TEST(coun_vowels_permutation, case2) {
			ASSERT_EQ(10, Solution::countVowelPermutation(2));
		}

		TEST(coun_vowels_permutation, case3) {
			ASSERT_EQ(68, Solution::countVowelPermutation(5));
		}
	}// namespace coun_vowels_permutation

	namespace minimum_time_difference {
		TEST(minimum_time_difference, case1) {
			string input[] = {"23:59", "00:00"};
			auto vec       = vector(begin(input), end(input));
			ASSERT_EQ(1, Solution::findMinDifference(vec));
		}

		TEST(minimum_time_difference, case2) {
			string input[] = {"00:00", "23:59", "00:00"};
			auto vec       = vector(begin(input), end(input));
			ASSERT_EQ(0, Solution::findMinDifference(vec));
		}

		TEST(minimum_time_difference, case3) {
			string input[] = {"00:00", "04:00", "22:00"};
			auto vec       = vector(begin(input), end(input));
			ASSERT_EQ(120, Solution::findMinDifference(vec));
		}
	}// namespace minimum_time_difference

	namespace contains_duplicate_ii {
		TEST(contains_duplicate_ii, case1) {
			int input[] = {1, 2, 3, 1};
			auto vec    = vector(begin(input), end(input));
			ASSERT_TRUE(Solution::containsNearbyDuplicate(vec, 3));
		}

		TEST(contains_duplicate_ii, case2) {
			int input[] = {1, 0, 1, 1};
			auto vec    = vector(begin(input), end(input));
			ASSERT_TRUE(Solution::containsNearbyDuplicate(vec, 3));
		}

		TEST(contains_duplicate_ii, case3) {
			int input[] = {1, 2, 3, 1, 2, 3};
			auto vec    = vector(begin(input), end(input));
			ASSERT_FALSE(Solution::containsNearbyDuplicate(vec, 2));
		}
	}// namespace contains_duplicate_ii

	namespace stone_game_ix {
		TEST(stone_game_ix, case1) {
			int input[] = {2, 1};
			auto vec    = vector(begin(input), end(input));
			ASSERT_TRUE(Solution::stoneGameIX(vec));
		}

		TEST(stone_game_ix, case2) {
			int input[] = {2};
			auto vec    = vector(begin(input), end(input));
			ASSERT_FALSE(Solution::stoneGameIX(vec));
		}

		TEST(stone_game_ix, case3) {
			int input[] = {5, 1, 2, 4, 3};
			auto vec    = vector(begin(input), end(input));
			ASSERT_FALSE(Solution::stoneGameIX(vec));
		}

		TEST(stone_game_ix, case4) {
			int input[] = {3, 4, 6, 6, 8, 9, 2, 4, 5};
			auto vec    = vector(begin(input), end(input));
			ASSERT_TRUE(Solution::stoneGameIX(vec));
		}

		TEST(stone_game_ix, case5) {
			int input[] = {2, 3, 7, 9, 4, 32, 2, 5, 8, 2, 6, 8, 3, 2, 6, 8, 3, 2, 5, 7, 8, 3, 5, 67, 8};
			auto vec    = vector(begin(input), end(input));
			ASSERT_TRUE(Solution::stoneGameIX(vec));
		}

		TEST(stone_game_ix, case6) {
			int input[] = {15, 20, 10, 13, 14, 15, 5, 2, 3};
			auto vec    = vector(begin(input), end(input));
			ASSERT_FALSE(Solution::stoneGameIX(vec));
		}
	}// namespace stone_game_ix

	namespace jump_game_iv {
		TEST(jump_game_iv, case1) {
			int input[] = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(3, Solution::minJumps(vec));
		}

		TEST(jump_game_iv, case2) {
			int input[] = {7};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(0, Solution::minJumps(vec));
		}

		TEST(jump_game_iv, case3) {
			int input[] = {7, 6, 9, 6, 9, 6, 9, 7};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(1, Solution::minJumps(vec));
		}

		TEST(jump_game_iv, case4) {
			int input[] = {6, 1, 9};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(2, Solution::minJumps(vec));
		}

		TEST(jump_game_iv, case5) {
			int input[] = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(3, Solution::minJumps(vec));
		}

		TEST(jump_game_iv, case6) {
			int input[] = {-76, 3, 66, -32, 64, 2, -19, -8, -5, -93, 80, -5, -76, -78, 64, 2, 16};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(5, Solution::minJumps(vec));
		}

		TEST(jump_game_iv, case7) {
			int input[] = {-10, -25, 58, -67, 28, 86, 58, -29, -10, -10, 45, -80, 86, 35, -10, 58, -10, -98, -9, -98, -10, -67, -29, -6, 74, 46, -29, -5, 58, 58, -17, 28, -4, -67, 28, -98, -4, 86, -29, -92, -67, 58, -76, -27, -9, 58, -92, -42, -27, -41, 58, -25, 74, -98, -92, -10, -67, -6, -17, -5, -29, -17, -4, 28, -17, -80, 35, -9, 32, -29, -76, 46, -29, -5, -27, 35, 74, -92, -4, -98, -9, -10, -4, -27, -92, 74, -98, -29, -42, -9, 45, -10, -98, 28};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(3, Solution::minJumps(vec));
		}

		TEST(jump_game_iv, case8) {
			int input[] = {7};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(0, Solution::minJumps(vec));
		}
	}// namespace jump_game_iv

	namespace remove_palindromic_subsequences {
		TEST(remove_palindromic_subsequences, case1) {
			ASSERT_EQ(1, Solution::removePalindromeSub("ababa"));
		}

		TEST(remove_palindromic_subsequences, case2) {
			ASSERT_EQ(2, Solution::removePalindromeSub("abb"));
		}

		TEST(remove_palindromic_subsequences, case3) {
			ASSERT_EQ(2, Solution::removePalindromeSub("baabb"));
		}
	}// namespace remove_palindromic_subsequences

	namespace UhWRSj {
		TEST(UhWRSj, case1) {
			string input[] = {"cat", "bat", "rat"};
			auto vec       = vector(begin(input), end(input));
			ASSERT_EQ("the cat was rat by the bat", Solution::replaceWords(vec, "the cattle was rattled by the battery"));
		}

		TEST(UhWRSj, case2) {
			string input[] = {"a", "b", "c"};
			auto vec       = vector(begin(input), end(input));
			ASSERT_EQ("a a b c", Solution::replaceWords(vec, "aadsfasf absbs bbab cadsfafs"));
		}

		TEST(UhWRSj, case3) {
			string input[] = {"a", "aa", "aaa", "aaaa"};
			auto vec       = vector(begin(input), end(input));
			ASSERT_EQ("a a a a a a a a bbb baba a", Solution::replaceWords(vec, "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"));
		}

		TEST(UhWRSj, case4) {
			string input[] = {"catt", "cat", "bat", "rat"};
			auto vec       = vector(begin(input), end(input));
			ASSERT_EQ("the cat was rat by the bat", Solution::replaceWords(vec, "the cattle was rattled by the battery"));
		}

		TEST(UhWRSj, case5) {
			string input[] = {"ac", "ab"};
			auto vec       = vector(begin(input), end(input));
			ASSERT_EQ("it is ab that this solution is ac", Solution::replaceWords(vec, "it is abnormal that this solution is accepted"));
		}
	}// namespace UhWRSj

	namespace minimum_cost_of_buying_candies_with_discount {
		TEST(minimum_cost_of_buying_candies_with_discount, case1) {
			int input[] = {1, 2, 3};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(5, Solution::minimumCost(vec));
		}

		TEST(minimum_cost_of_buying_candies_with_discount, case2) {
			int input[] = {6, 5, 7, 9, 2, 2};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(23, Solution::minimumCost(vec));
		}

		TEST(minimum_cost_of_buying_candies_with_discount, case3) {
			int input[] = {5, 5};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(10, Solution::minimumCost(vec));
		}
	}// namespace minimum_cost_of_buying_candies_with_discount

	namespace count_the_hidden_sequences {
		TEST(count_the_hidden_sequences, case1) {
			int input[] = {1, -3, 4};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(2, Solution::numberOfArrays(vec, 1, 6));
		}

		TEST(count_the_hidden_sequences, case2) {
			int input[] = {3, -4, 5, 1, -2};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(4, Solution::numberOfArrays(vec, -4, 5));
		}

		TEST(count_the_hidden_sequences, case3) {
			int input[] = {4, -7, 2};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(0, Solution::numberOfArrays(vec, 3, 6));
		}
	}// namespace count_the_hidden_sequences

	namespace number_of_ways_to_divide_a_long_corridor {
		TEST(number_of_ways_to_divide_a_long_corridor, case1) {
			ASSERT_EQ(3, Solution::numberOfWays("SSPPSPS"));
		}

		TEST(number_of_ways_to_divide_a_long_corridor, case2) {
			ASSERT_EQ(1, Solution::numberOfWays("PPSPSP"));
		}

		TEST(number_of_ways_to_divide_a_long_corridor, case3) {
			ASSERT_EQ(0, Solution::numberOfWays("S"));
		}

		TEST(number_of_ways_to_divide_a_long_corridor, case4) {
			ASSERT_EQ(0, Solution::numberOfWays("P"));
		}

		TEST(number_of_ways_to_divide_a_long_corridor, case6) {
			ASSERT_EQ(1, Solution::numberOfWays("PSSSSP"));
		}
	}// namespace number_of_ways_to_divide_a_long_corridor

	namespace count_elements_with_strictly_smaller_and_greater_elements {
		TEST(count_elements_with_strictly_smaller_and_greater_elements, case1) {
			int input[] = {11, 7, 2, 15};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(2, Solution::countElements(vec));
		}

		TEST(count_elements_with_strictly_smaller_and_greater_elements, case2) {
			int input[] = {-3, 3, 3, 90};
			auto vec    = vector(begin(input), end(input));
			ASSERT_EQ(2, Solution::countElements(vec));
		}
	}// namespace count_elements_with_strictly_smaller_and_greater_elements

	namespace rearrange_array_elements_by_sign {
		TEST(rearrange_array_elements_by_sign, case1) {
			int input[]           = {3, 1, -2, -5, 2, -4};
			auto vec_input        = vector(begin(input), end(input));
			int output[]          = {3, -2, 1, -5, 2, -4};
			const auto vec_output = vector(begin(output), end(output));
			ASSERT_EQ(vec_output, Solution::rearrangeArray(vec_input));
		}

		TEST(rearrange_array_elements_by_sign, case2) {
			int input[]           = {-1, 1};
			auto vec_input        = vector(begin(input), end(input));
			int output[]          = {1, -1};
			const auto vec_output = vector(begin(output), end(output));
			ASSERT_EQ(vec_output, Solution::rearrangeArray(vec_input));
		}
	}// namespace rearrange_array_elements_by_sign

	namespace find_all_lonely_numbers_in_the_array {
		TEST(find_all_lonely_numbers_in_the_array, case1) {
			int input[]           = {10, 6, 5, 8};
			auto vec_input        = vector(begin(input), end(input));
			int output[]          = {10, 8};
			const auto vec_output = vector(begin(output), end(output));
			ASSERT_EQ(vec_output, Solution::findLonely(vec_input));
		}

		TEST(find_all_lonely_numbers_in_the_array, case2) {
			int input[]           = {1, 3, 5, 3};
			auto vec_input        = vector(begin(input), end(input));
			int output[]          = {1, 5};
			const auto vec_output = vector(begin(output), end(output));
			ASSERT_EQ(vec_output, Solution::findLonely(vec_input));
		}
	}// namespace find_all_lonely_numbers_in_the_array

	namespace maximum_good_people_based_on_statements {
		TEST(maximum_good_people_based_on_statements, case1) {
			int input1[]        = {2, 1, 2};
			int input2[]        = {1, 2, 2};
			int input3[]        = {2, 0, 2};
			vector<int> input[] = {vector(begin(input1), end(input1)), vector(begin(input2), end(input2)), vector(begin(input3), end(input3))};
			auto vec_input      = vector(begin(input), end(input));
			ASSERT_EQ(2, Solution::maximumGood(vec_input));
		}

		TEST(maximum_good_people_based_on_statements, case2) {
			int input1[]        = {2, 0};
			int input2[]        = {0, 2};
			vector<int> input[] = {vector(begin(input1), end(input1)), vector(begin(input2), end(input2))};
			auto vec_input      = vector(begin(input), end(input));
			ASSERT_EQ(1, Solution::maximumGood(vec_input));
		}
	}// namespace maximum_good_people_based_on_statements

	namespace second_minimum_time_to_reach_destination {
		TEST(second_minimum_time_to_reach_destination, case1) {
			int inputs[][2] = {{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}};
			auto vec        = vector<vector<int>>();
			for(const auto *input: inputs) {
				auto n_vec = vector<int>();
				n_vec.resize(2);
				n_vec[0] = input[0];
				n_vec[1] = input[1];
				vec.push_back(n_vec);
			}
			ASSERT_EQ(13, Solution::secondMinimum(5, vec, 3, 5));
		}

		TEST(second_minimum_time_to_reach_destination, case2) {
			int inputs[][2] = {{1, 2}};
			auto vec        = vector<vector<int>>();
			for(const auto *input: inputs) {
				auto n_vec = vector<int>();
				n_vec.resize(2);
				n_vec[0] = input[0];
				n_vec[1] = input[1];
				vec.push_back(n_vec);
			}
			ASSERT_EQ(11, Solution::secondMinimum(2, vec, 3, 2));
		}
	}// namespace second_minimum_time_to_reach_destination

	namespace count_of_matches_in_tournament {
		TEST(count_of_matches_in_tournament, case1) {
			ASSERT_EQ(6, Solution::numberOfMatches(7));
		}

		TEST(count_of_matches_in_tournament, case2) {
			ASSERT_EQ(13, Solution::numberOfMatches(14));
		}
	}// namespace count_of_matches_in_tournament

	namespace number_of_valid_words_in_a_sentence {
		TEST(number_of_valid_words_in_a_sentence, case1) {
			ASSERT_EQ(3, Solution::countValidWords("cat and  dog"));
		}

		TEST(number_of_valid_words_in_a_sentence, case2) {
			ASSERT_EQ(0, Solution::countValidWords("!this  1-s b8d!"));
		}

		TEST(number_of_valid_words_in_a_sentence, case3) {
			ASSERT_EQ(5, Solution::countValidWords("alice and  bob are playing stone-game10"));
		}

		TEST(number_of_valid_words_in_a_sentence, case4) {
			ASSERT_EQ(6, Solution::countValidWords("he bought 2 pencils, 3 erasers, and 1  pencil-sharpener."));
		}
	}// namespace number_of_valid_words_in_a_sentence

	namespace pattern_matching_lcci {
		TEST(pattern_matching_lcci, case1) {
			ASSERT_TRUE(Solution::patternMatching("abba", "dogcatcatdog"));
		}

		TEST(pattern_matching_lcci, case2) {
			ASSERT_FALSE(Solution::patternMatching("abba", "dogcatcatfish"));
		}

		TEST(pattern_matching_lcci, case3) {
			ASSERT_FALSE(Solution::patternMatching("aaaa", "dogcatcatdog"));
		}

		TEST(pattern_matching_lcci, case4) {
			ASSERT_TRUE(Solution::patternMatching("abba", "dogdogdogdog"));
		}

		TEST(pattern_matching_lcci, case5) {
			ASSERT_TRUE(Solution::patternMatching("bb", "tttt"));
		}

		TEST(pattern_matching_lcci, case6) {
			ASSERT_TRUE(Solution::patternMatching("aaaaab", "xahnxdxyaahnxdxyaahnxdxyaahnxdxyaauxuhuo"));
		}
	}// namespace pattern_matching_lcci

	namespace map_of_highest_peak {
		TEST(map_of_highest_peak, case1) {
			int input[2][2] = {{0, 1}, {0, 0}};
			auto vec_in     = vector<vector<int>>();
			vec_in.resize(2);
			for(int i = 0; i < 2; i++) {
				vec_in[i] = vector(begin(input[i]), end(input[i]));
			}
			int output[2][2] = {{1, 0}, {2, 1}};
			auto vec_out     = vector<vector<int>>();
			vec_out.resize(2);
			for(int i = 0; i < 2; i++) {
				vec_out[i] = vector(begin(output[i]), end(output[i]));
			}
			ASSERT_EQ(vec_out, Solution::highestPeak(vec_in));
		}

		TEST(map_of_highest_peak, case2) {
			int input[3][3] = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
			auto vec_in     = vector<vector<int>>();
			vec_in.resize(3);
			for(int i = 0; i < 3; i++) {
				vec_in[i] = vector(begin(input[i]), end(input[i]));
			}
			int output[3][3] = {{1, 1, 0}, {0, 1, 1}, {1, 2, 2}};
			auto vec_out     = vector<vector<int>>();
			vec_out.resize(3);
			for(int i = 0; i < 3; i++) {
				vec_out[i] = vector(begin(output[i]), end(output[i]));
			}
			ASSERT_EQ(vec_out, Solution::highestPeak(vec_in));
		}
	}// namespace map_of_highest_peak

	namespace find_substring_with_given_hash_value {
		TEST(find_substring_with_given_hash_value, case1) {
			ASSERT_EQ("ee", Solution::subStrHash("leetcode", 7, 20, 2, 0));
		}

		TEST(find_substring_with_given_hash_value, case2) {
			ASSERT_EQ("fbx", Solution::subStrHash("fbxzaad", 31, 100, 3, 32));
		}
	}// namespace find_substring_with_given_hash_value

	namespace groups_of_strings {
		TEST(groups_of_strings, case1) {
			string input[]        = {"a", "b", "ab", "cde"};
			auto input_vec        = vector(begin(input), end(input));
			int output[]          = {2, 3};
			const auto output_vec = vector(begin(output), end(output));
			auto sol              = Solution();
			ASSERT_EQ(output_vec, sol.groupStrings(input_vec));
		}

		TEST(groups_of_strings, case2) {
			string input[]        = {"a", "ab", "abc"};
			auto input_vec        = vector(begin(input), end(input));
			int output[]          = {1, 3};
			const auto output_vec = vector(begin(output), end(output));
			auto sol              = Solution();
			ASSERT_EQ(output_vec, sol.groupStrings(input_vec));
		}

		TEST(groups_of_strings, case3) {
			string input[]        = {"qamp", "am", "khdrn"};
			auto input_vec        = vector(begin(input), end(input));
			int output[]          = {3, 1};
			const auto output_vec = vector(begin(output), end(output));
			auto sol              = Solution();
			ASSERT_EQ(output_vec, sol.groupStrings(input_vec));
		}

		TEST(groups_of_strings, case4) {
			string input[]        = {"ghnv", "uip", "tenv", "hvepx", "e", "ktc", "byjdt", "ulm", "cae", "ea"};
			auto input_vec        = vector(begin(input), end(input));
			int output[]          = {8, 3};
			const auto output_vec = vector(begin(output), end(output));
			auto sol              = Solution();
			ASSERT_EQ(output_vec, sol.groupStrings(input_vec));
		}

		TEST(groups_of_strings, case5) {
			string input[]        = {"web", "a", "te", "hsx", "v", "k", "a", "roh"};
			auto input_vec        = vector(begin(input), end(input));
			int output[]          = {5, 4};
			const auto output_vec = vector(begin(output), end(output));
			auto sol              = Solution();
			ASSERT_EQ(output_vec, sol.groupStrings(input_vec));
		}
	}// namespace groups_of_strings

	namespace number_of_steps_to_reduce_a_number_to_zero {
		TEST(number_of_steps_to_reduce_a_number_to_zero, case1) {
			ASSERT_EQ(6, Solution::numberOfSteps(14));
		}

		TEST(number_of_steps_to_reduce_a_number_to_zero, case2) {
			ASSERT_EQ(4, Solution::numberOfSteps(8));
		}

		TEST(number_of_steps_to_reduce_a_number_to_zero, case3) {
			ASSERT_EQ(12, Solution::numberOfSteps(123));
		}
	}// namespace number_of_steps_to_reduce_a_number_to_zero

	namespace longest_nice_substring {
		TEST(longest_nice_substring, case1) {
			ASSERT_EQ("aAa", Solution::longestNiceSubstring("YazaAay"));
		}

		TEST(longest_nice_substring, case2) {
			ASSERT_EQ("Bb", Solution::longestNiceSubstring("Bb"));
		}

		TEST(longest_nice_substring, case3) {
			ASSERT_EQ("", Solution::longestNiceSubstring("c"));
		}

		TEST(longest_nice_substring, case4) {
			ASSERT_EQ("dD", Solution::longestNiceSubstring("dDzeE"));
		}
	}// namespace longest_nice_substring

	namespace reverse_prefix_of_word {
		TEST(reverse_prefix_of_word, case1) {
			ASSERT_EQ("dcbaefd", Solution::reversePrefix("abcdefd", 'd'));
		}

		TEST(reverse_prefix_of_word, case2) {
			ASSERT_EQ("zxyxxe", Solution::reversePrefix("xyxzxe", 'z'));
		}

		TEST(reverse_prefix_of_word, case3) {
			ASSERT_EQ("abcd", Solution::reversePrefix("abcd", 'z'));
		}
	}// namespace reverse_prefix_of_word

	namespace find_the_minimum_number_of_fibonacci_numbers_whose_sum_is_k {
		TEST(find_the_minimum_number_of_fibonacci_numbers_whose_sum_is_k, case1) {
			ASSERT_EQ(2, Solution::findMinFibonacciNumbers(7));
		}

		TEST(find_the_minimum_number_of_fibonacci_numbers_whose_sum_is_k, case2) {
			ASSERT_EQ(2, Solution::findMinFibonacciNumbers(10));
		}

		TEST(find_the_minimum_number_of_fibonacci_numbers_whose_sum_is_k, case3) {
			ASSERT_EQ(3, Solution::findMinFibonacciNumbers(19));
		}
	}// namespace find_the_minimum_number_of_fibonacci_numbers_whose_sum_is_k

	namespace number_of_rectangles_that_can_form_the_largest_square {
		TEST(number_of_rectangles_that_can_form_the_largest_square, case1) {
			vector<vector<int>> input = {{5, 8}, {3, 9}, {5, 12}, {16, 5}};
			ASSERT_EQ(3, Solution::countGoodRectangles(input));
		}

		TEST(number_of_rectangles_that_can_form_the_largest_square, case2) {
			vector<vector<int>> input = {{2, 3}, {3, 7}, {4, 3}, {3, 7}};
			ASSERT_EQ(3, Solution::countGoodRectangles(input));
		}
	}// namespace number_of_rectangles_that_can_form_the_largest_square

	namespace path_with_maximum_gold {
		TEST(path_with_maximum_gold, case1) {
			vector<vector<int>> input = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
			ASSERT_EQ(24, Solution::getMaximumGold(input));
		}

		TEST(path_with_maximum_gold, case2) {
			vector<vector<int>> input = {{1, 0, 7}, {2, 0, 6}, {3, 4, 5}, {0, 3, 0}, {9, 0, 20}};
			ASSERT_EQ(28, Solution::getMaximumGold(input));
		}
	}// namespace path_with_maximum_gold

	namespace minimum_difference_in_sums_after_removal_of_elements {
		TEST(minimum_difference_in_sums_after_removal_of_elements, case1) {
			vector input = {3, 1, 2};
			ASSERT_EQ(-1, Solution::minimumDifference(input));
		}

		TEST(minimum_difference_in_sums_after_removal_of_elements, case2) {
			vector input = {7, 9, 5, 8, 1, 3};
			ASSERT_EQ(1, Solution::minimumDifference(input));
		}
	}// namespace minimum_difference_in_sums_after_removal_of_elements

	namespace sum_of_unique_elements {
		TEST(sum_of_unique_elements, case1) {
			vector input = {1, 2, 3, 2};
			ASSERT_EQ(4, Solution::sumOfUnique(input));
		}

		TEST(sum_of_unique_elements, case2) {
			vector input = {1, 1, 1, 1, 1};
			ASSERT_EQ(0, Solution::sumOfUnique(input));
		}

		TEST(sum_of_unique_elements, case3) {
			vector input = {1, 2, 3, 4, 5};
			ASSERT_EQ(15, Solution::sumOfUnique(input));
		}
	}// namespace sum_of_unique_elements

	namespace smallest_value_of_the_rearranged_number {
		TEST(smallest_value_of_the_rearranged_number, case1) {
			ASSERT_EQ(103, Solution::smallestNumber(310));
		}

		TEST(smallest_value_of_the_rearranged_number, case2) {
			ASSERT_EQ(-7650, Solution::smallestNumber(-7605));
		}

		TEST(smallest_value_of_the_rearranged_number, case3) {
			ASSERT_EQ(-6333221000, Solution::smallestNumber(-2230363001));
		}
	}// namespace smallest_value_of_the_rearranged_number

	namespace design_bitset {
		TEST(design_bitset, case1) {
			auto bt = Bitset(5);
			bt.fix(3);
			bt.fix(1);
			bt.flip();
			ASSERT_FALSE(bt.all());
			bt.unfix(0);
			bt.flip();
			ASSERT_TRUE(bt.one());
			bt.unfix(0);
			ASSERT_EQ(2, bt.count());
			ASSERT_EQ("01010", bt.toString());
		}
	}// namespace design_bitset

	namespace longest_happy_string {
		TEST(longest_happy_string, case1) {
			ASSERT_EQ("ccbccacc", Solution::longestDiverseString(1, 1, 7));
		}

		TEST(longest_happy_string, case2) {
			ASSERT_EQ("aabaa", Solution::longestDiverseString(7, 1, 0));
		}
	}// namespace longest_happy_string

	namespace grid_illumination {
		TEST(grid_illumination, case1) {
			vector<vector<int>> lamps   = {{0, 0}, {4, 4}};
			vector<vector<int>> queries = {{1, 1}, {1, 0}};
			const vector output         = {1, 0};
			ASSERT_EQ(output, Solution::gridIllumination(5, lamps, queries));
		}

		TEST(grid_illumination, case2) {
			vector<vector<int>> lamps   = {{0, 0}, {4, 4}};
			vector<vector<int>> queries = {{1, 1}, {1, 1}};
			const vector output         = {1, 1};
			ASSERT_EQ(output, Solution::gridIllumination(5, lamps, queries));
		}

		TEST(grid_illumination, case3) {
			vector<vector<int>> lamps   = {{0, 0}, {0, 4}};
			vector<vector<int>> queries = {{0, 4}, {0, 1}, {1, 4}};
			const vector output         = {1, 1, 0};
			ASSERT_EQ(output, Solution::gridIllumination(5, lamps, queries));
		}

		TEST(grid_illumination, case4) {
			vector<vector<int>> lamps   = {{1, 1}};
			vector<vector<int>> queries = {{2, 0}, {1, 0}};
			const vector output         = {1, 0};
			ASSERT_EQ(output, Solution::gridIllumination(6, lamps, queries));
		}

		TEST(grid_illumination, case5) {
			vector<vector<int>> lamps   = {{2, 5}, {4, 2}, {0, 3}, {0, 5}, {1, 4}, {4, 2}, {3, 3}, {1, 0}};
			vector<vector<int>> queries = {{4, 3}, {3, 1}, {5, 3}, {0, 5}, {4, 4}, {3, 3}};
			const vector output         = {1, 0, 1, 1, 0, 1};
			ASSERT_EQ(output, Solution::gridIllumination(6, lamps, queries));
		}
	}// namespace grid_illumination

	namespace count_number_of_pairs_with_absolute_difference_k {
		TEST(count_number_of_pairs_with_absolute_difference_k, case1) {
			vector input = {1, 2, 2, 1};
			ASSERT_EQ(4, Solution::countKDifference(input, 1));
		}

		TEST(count_number_of_pairs_with_absolute_difference_k, case2) {
			vector input = {1, 3};
			ASSERT_EQ(0, Solution::countKDifference(input, 3));
		}

		TEST(count_number_of_pairs_with_absolute_difference_k, case3) {
			vector input = {3, 2, 1, 5, 4};
			ASSERT_EQ(3, Solution::countKDifference(input, 2));
		}
	}// namespace count_number_of_pairs_with_absolute_difference_k

	namespace simplified_fractions {
		TEST(simplified_fractions, case1) {
			const vector<string> output = {"1/2"};
			ASSERT_EQ(output, Solution::simplifiedFractions(2));
		}

		TEST(simplified_fractions, case2) {
			const vector<string> output = {"1/2", "1/3", "2/3"};
			ASSERT_EQ(output, Solution::simplifiedFractions(3));
		}

		TEST(simplified_fractions, case3) {
			const vector<string> output = {"1/2", "1/3", "2/3", "1/4", "3/4"};
			ASSERT_EQ(output, Solution::simplifiedFractions(4));
		}
	}// namespace simplified_fractions

	namespace minimum_difference_between_highest_and_lowest_of_k_scores {
		TEST(minimum_difference_between_highest_and_lowest_of_k_scores, case1) {
			vector input = {90};
			ASSERT_EQ(0, Solution::minimumDifference(input, 1));
		}

		TEST(minimum_difference_between_highest_and_lowest_of_k_scores, case2) {
			vector input = {9, 4, 1, 7};
			ASSERT_EQ(2, Solution::minimumDifference(input, 2));
		}
	}// namespace minimum_difference_between_highest_and_lowest_of_k_scores

	namespace number_of_enclaves {
		TEST(number_of_enclaves, case1) {
			vector<vector<int>> input = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
			ASSERT_EQ(3, Solution::numEnclaves(input));
		}

		TEST(number_of_enclaves, case2) {
			vector<vector<int>> input = {{0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
			ASSERT_EQ(0, Solution::numEnclaves(input));
		}
	}// namespace number_of_enclaves

	namespace maximum_number_of_balloons {
		TEST(maximum_number_of_balloons, case1) {
			ASSERT_EQ(1, Solution::maxNumberOfBalloons("nlaebolko"));
		}

		TEST(maximum_number_of_balloons, case2) {
			ASSERT_EQ(2, Solution::maxNumberOfBalloons("loonbalxballpoon"));
		}

		TEST(maximum_number_of_balloons, case3) {
			ASSERT_EQ(0, Solution::maxNumberOfBalloons("leetcode"));
		}
	}// namespace maximum_number_of_balloons

	namespace swap_adjacent_in_lr_string {
		TEST(swap_adjacent_in_lr_string, case1) {
			ASSERT_TRUE(Solution::canTransform("RXXLRXRXL", "XRLXXRRLX"));
		}

		TEST(swap_adjacent_in_lr_string, case2) {
			ASSERT_FALSE(Solution::canTransform("X", "L"));
		}

		TEST(swap_adjacent_in_lr_string, case3) {
			ASSERT_FALSE(Solution::canTransform("LXXLXRLXXL", "XLLXRXLXLX"));
		}
	}// namespace swap_adjacent_in_lr_string

	namespace count_operations_to_obtain_zero {
		TEST(count_operations_to_obtain_zero, case1) {
			ASSERT_EQ(3, Solution::countOperations(2, 3));
		}

		TEST(count_operations_to_obtain_zero, case2) {
			ASSERT_EQ(1, Solution::countOperations(10, 10));
		}
	}// namespace count_operations_to_obtain_zero

	namespace minimum_operations_to_make_the_array_alternating {
		TEST(minimum_operations_to_make_the_array_alternating, case1) {
			vector input = {3, 1, 3, 2, 4, 3};
			ASSERT_EQ(3, Solution::minimumOperations(input));
		}

		TEST(minimum_operations_to_make_the_array_alternating, case2) {
			vector input = {1, 2, 2, 2, 2};
			ASSERT_EQ(2, Solution::minimumOperations(input));
		}

		TEST(minimum_operations_to_make_the_array_alternating, case3) {
			vector input = {69, 91, 47, 74, 75, 94, 22, 100, 43, 50, 82, 47, 40, 51, 90, 27, 98, 85, 47, 14, 55, 82, 52, 9, 65, 90, 86, 45, 52, 52, 95, 40, 85, 3, 46, 77, 16, 59, 32, 22, 41, 87, 89, 78, 59, 78, 34, 26, 71, 9, 82, 68, 80, 74, 100, 6, 10, 53, 84, 80, 7, 87, 3, 82, 26, 26, 14, 37, 26, 58, 96, 73, 41, 2, 79, 43, 56, 74, 30, 71, 6, 100, 72, 93, 83, 40, 28, 79, 24};
			ASSERT_EQ(84, Solution::minimumOperations(input));
		}
	}// namespace minimum_operations_to_make_the_array_alternating

	namespace removing_minimum_number_of_magic_beans {
		TEST(removing_minimum_number_of_magic_beans, case1) {
			vector input = {4, 1, 6, 5};
			ASSERT_EQ(4, Solution::minimumRemoval(input));
		}

		TEST(removing_minimum_number_of_magic_beans, case2) {
			vector input = {2, 10, 3, 2};
			ASSERT_EQ(7, Solution::minimumRemoval(input));
		}
	}// namespace removing_minimum_number_of_magic_beans

	namespace maximum_and_sum_of_array {
		TEST(maximum_and_sum_of_array, case1) {
			vector input = {1, 2, 3, 4, 5, 6};
			ASSERT_EQ(9, Solution::maximumANDSum(input, 3));
		}

		TEST(maximum_and_sum_of_array, case2) {
			vector input = {1, 3, 10, 4, 7, 1};
			ASSERT_EQ(24, Solution::maximumANDSum(input, 9));
		}
	}// namespace maximum_and_sum_of_array

	namespace single_element_in_a_sorted_array {
		TEST(single_element_in_a_sorted_array, case1) {
			vector input = {1, 1, 2, 3, 3, 4, 4, 8, 8};
			ASSERT_EQ(2, Solution::singleNonDuplicate(input));
		}

		TEST(single_element_in_a_sorted_array, case2) {
			vector input = {3, 3, 7, 7, 10, 11, 11};
			ASSERT_EQ(10, Solution::singleNonDuplicate(input));
		}
	}// namespace single_element_in_a_sorted_array

	namespace lucky_numbers_in_a_matrix {
		TEST(lucky_numbers_in_a_matrix, case1) {
			vector<vector<int>> input = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
			const vector output       = {15};
			ASSERT_EQ(output, Solution::luckyNumbers(input));
		}

		TEST(lucky_numbers_in_a_matrix, case2) {
			vector<vector<int>> input = {{1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}};
			const vector output       = {12};
			ASSERT_EQ(output, Solution::luckyNumbers(input));
		}

		TEST(lucky_numbers_in_a_matrix, case3) {
			vector<vector<int>> input = {{7, 8}, {1, 2}};
			const vector output       = {7};
			ASSERT_EQ(output, Solution::luckyNumbers(input));
		}
	}// namespace lucky_numbers_in_a_matrix

	namespace number_of_ways_to_reconstruct_a_tree {
		TEST(number_of_ways_to_reconstruct_a_tree, case1) {
			vector<vector<int>> input = {{1, 2}, {2, 3}};
			ASSERT_EQ(1, Solution::checkWays(input));
		}

		TEST(number_of_ways_to_reconstruct_a_tree, case2) {
			vector<vector<int>> input = {{1, 2}, {2, 3}, {1, 3}};
			ASSERT_EQ(2, Solution::checkWays(input));
		}

		TEST(number_of_ways_to_reconstruct_a_tree, case3) {
			vector<vector<int>> input = {{1, 2}, {2, 3}, {2, 4}, {1, 5}};
			ASSERT_EQ(0, Solution::checkWays(input));
		}
	}// namespace number_of_ways_to_reconstruct_a_tree

	namespace find_center_of_star_graph {
		TEST(find_center_of_star_graph, case1) {
			vector<vector<int>> input = {{1, 2}, {2, 3}, {4, 2}};
			ASSERT_EQ(2, Solution::findCenter(input));
		}

		TEST(find_center_of_star_graph, case2) {
			vector<vector<int>> input = {{1, 2}, {5, 1}, {1, 3}, {1, 4}};
			ASSERT_EQ(1, Solution::findCenter(input));
		}
	}// namespace find_center_of_star_graph

	namespace knight_probability_in_chessboard {
		TEST(knight_probability_in_chessboard, case1) {
			auto sol = Solution();
			ASSERT_EQ(0.06250, sol.knightProbability(3, 2, 0, 0));
		}

		TEST(knight_probability_in_chessboard, case2) {
			auto sol = Solution();
			ASSERT_EQ(1.00000, sol.knightProbability(1, 0, 0, 0));
		}
	}// namespace knight_probability_in_chessboard

	namespace count_equal_and_divisible_pairs_in_an_array {
		TEST(count_equal_and_divisible_pairs_in_an_array, case1) {
			vector input = {3, 1, 2, 2, 2, 1, 3};
			ASSERT_EQ(4, Solution::countPairs(input, 2));
		}

		TEST(count_equal_and_divisible_pairs_in_an_array, case2) {
			vector input = {1, 2, 3, 4};
			ASSERT_EQ(0, Solution::countPairs(input, 1));
		}
	}// namespace count_equal_and_divisible_pairs_in_an_array

	namespace find_three_consecutive_integers_that_sum_to_a_given_number {
		TEST(find_three_consecutive_integers_that_sum_to_a_given_number, case1) {
			const vector<long long> output = {10, 11, 12};
			ASSERT_EQ(output, Solution::sumOfThree(33));
		}

		TEST(find_three_consecutive_integers_that_sum_to_a_given_number, case2) {
			const vector<long long> output = {};
			ASSERT_EQ(output, Solution::sumOfThree(4));
		}
	}// namespace find_three_consecutive_integers_that_sum_to_a_given_number

	namespace maximum_split_of_positive_even_integers {
		TEST(maximum_split_of_positive_even_integers, case1) {
			const vector<long long> output = {2, 4, 6};
			ASSERT_EQ(output, Solution::maximumEvenSplit(12));
		}

		TEST(maximum_split_of_positive_even_integers, case2) {
			const vector<long long> output = {};
			ASSERT_EQ(output, Solution::maximumEvenSplit(7));
		}

		TEST(maximum_split_of_positive_even_integers, case3) {
			const vector<long long> output = {2, 4, 6, 16};
			ASSERT_EQ(output, Solution::maximumEvenSplit(28));
		}
	}// namespace maximum_split_of_positive_even_integers

	namespace count_good_triplets_in_an_array {
		TEST(count_good_triplets_in_an_array, case1) {
			vector input1 = {2, 0, 1, 3};
			vector input2 = {0, 1, 2, 3};
			ASSERT_EQ(1, Solution::goodTriplets(input1, input2));
		}

		TEST(count_good_triplets_in_an_array, case2) {
			vector input1 = {4, 0, 1, 3, 2};
			vector input2 = {4, 1, 0, 2, 3};
			ASSERT_EQ(4, Solution::goodTriplets(input1, input2));
		}
	}// namespace count_good_triplets_in_an_array

	namespace count_integers_with_even_digit_sum {
		TEST(count_integers_with_even_digit_sum, case1) {
			ASSERT_EQ(2, Solution::countEven(4));
		}

		TEST(count_integers_with_even_digit_sum, case2) {
			ASSERT_EQ(14, Solution::countEven(30));
		}
	}// namespace count_integers_with_even_digit_sum

	namespace construct_string_with_repeat_limit {
		TEST(construct_string_with_repeat_limit, case1) {
			ASSERT_EQ("zzcccac", Solution::repeatLimitedString("cczazcc", 3));
		}

		TEST(construct_string_with_repeat_limit, case2) {
			ASSERT_EQ("bbabaa", Solution::repeatLimitedString("aababab", 2));
		}

		TEST(construct_string_with_repeat_limit, case3) {
			ASSERT_EQ("yxxvvuvusrrqqppopponliihgfeeddcbba", Solution::repeatLimitedString("robnsdvpuxbapuqgopqvxdrchivlifeepy", 2));
		}
	}// namespace construct_string_with_repeat_limit

	namespace count_array_pairs_divisible_by_k {
		TEST(count_array_pairs_divisible_by_k, case1) {
			vector input = {1, 2, 3, 4, 5};
			ASSERT_EQ(7, Solution::coutPairs(input, 2));
		}

		TEST(count_array_pairs_divisible_by_k, case2) {
			vector input = {1, 2, 3, 4};
			ASSERT_EQ(0, Solution::coutPairs(input, 5));
		}

		TEST(count_array_pairs_divisible_by_k, case3) {
			vector input = {8, 10, 2, 5, 9, 6, 3, 8, 2};
			ASSERT_EQ(18, Solution::coutPairs(input, 6));
		}
	}// namespace count_array_pairs_divisible_by_k

	namespace leetcode717_1_bit_and_2_bit_characters {
		TEST(leetcode717_1_bit_and_2_bit_characters, case1) {
			vector input = {1, 0, 0};
			ASSERT_TRUE(Solution::isOneBitCharacter(input));
		}

		TEST(leetcode717_1_bit_and_2_bit_characters, case2) {
			vector input = {1, 1, 1, 0};
			ASSERT_FALSE(Solution::isOneBitCharacter(input));
		}
	}// namespace leetcode717_1_bit_and_2_bit_characters

	namespace longest_mountain_in_array {
		TEST(longest_mountain_in_array, case1) {
			vector input = {2, 1, 4, 7, 3, 2, 5};
			ASSERT_EQ(5, Solution::longestMountain(input));
		}

		TEST(longest_mountain_in_array, case2) {
			vector input = {2, 2, 2};
			ASSERT_EQ(0, Solution::longestMountain(input));
		}
	}// namespace longest_mountain_in_array

	namespace push_dominoes {
		TEST(push_dominoes, case1) {
			ASSERT_EQ("RR.L", Solution::pushDominoes("RR.L"));
		}

		TEST(push_dominoes, case2) {
			ASSERT_EQ("LL.RR.LLRRLL..", Solution::pushDominoes(".L.R...LR..L.."));
		}
	}// namespace push_dominoes

	namespace the_number_of_good_subsets {
		TEST(the_number_of_good_subsets, case1) {
			vector input = {1, 2, 3, 4};
			ASSERT_EQ(6, Solution::numberOfGoodSubsets(input));
		}

		TEST(the_number_of_good_subsets, case2) {
			vector input = {4, 2, 3, 15};
			ASSERT_EQ(5, Solution::numberOfGoodSubsets(input));
		}
	}// namespace the_number_of_good_subsets

	namespace reverse_only_letters {
		TEST(reverse_only_letters, case1) {
			ASSERT_EQ("dc-ba", Solution::reverseOnlyLetters("ab-cd"));
		}

		TEST(reverse_only_letters, case2) {
			ASSERT_EQ("j-Ih-gfE-dCba", Solution::reverseOnlyLetters("a-bC-dEf-ghIj"));
		}

		TEST(reverse_only_letters, case3) {
			ASSERT_EQ("Qedo1ct-eeLg=ntse-T!", Solution::reverseOnlyLetters("Test1ng-Leet=code-Q!"));
		}
	}// namespace reverse_only_letters

	namespace where_will_the_ball_fall {
		TEST(where_will_the_ball_fall, case1) {
			vector<vector<int>> input = {{1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1}};
			const vector output       = {1, -1, -1, -1, -1};
			ASSERT_EQ(output, Solution::findBall(input));
		}

		TEST(where_will_the_ball_fall, case2) {
			vector<vector<int>> input = {{-1}};
			const vector output       = {-1};
			ASSERT_EQ(output, Solution::findBall(input));
		}

		TEST(where_will_the_ball_fall, case3) {
			vector<vector<int>> input = {{1, 1, 1, 1, 1, 1}, {-1, -1, -1, -1, -1, -1}, {1, 1, 1, 1, 1, 1}, {-1, -1, -1, -1, -1, -1}};
			const vector output       = {0, 1, 2, 3, 4, -1};
			ASSERT_EQ(output, Solution::findBall(input));
		}
	}// namespace where_will_the_ball_fall

	namespace complex_number_multiplication {
		TEST(complex_number_multiplication, case1) {
			ASSERT_EQ("0+2i", Solution::complexNumberMultiply("1+1i", "1+1i"));
		}

		TEST(complex_number_multiplication, case2) {
			ASSERT_EQ("0+-2i", Solution::complexNumberMultiply("1+-1i", "1+-1i"));
		}
	}// namespace complex_number_multiplication

	namespace counting_words_with_a_given_prefix {
		TEST(counting_words_with_a_given_prefix, case1) {
			vector<string> input = {"pay", "attention", "practice", "attend"};
			ASSERT_EQ(2, Solution::prefixCount(input, "at"));
		}

		TEST(counting_words_with_a_given_prefix, case2) {
			vector<string> input = {"leetcode", "win", "loops", "success"};
			ASSERT_EQ(0, Solution::prefixCount(input, "code"));
		}
	}// namespace counting_words_with_a_given_prefix

	namespace minimum_number_of_steps_to_make_two_strings_anagram_ii {
		TEST(minimum_number_of_steps_to_make_two_strings_anagram_ii, case1) {
			ASSERT_EQ(7, Solution::minSteps("leetcode", "coats"));
		}

		TEST(minimum_number_of_steps_to_make_two_strings_anagram_ii, case2) {
			ASSERT_EQ(0, Solution::minSteps("night", "thing"));
		}
	}// namespace minimum_number_of_steps_to_make_two_strings_anagram_ii

	namespace maximum_difference_between_increasing_elements {
		TEST(maximum_difference_between_increasing_elements, case1) {
			vector input = {7, 1, 5, 4};
			ASSERT_EQ(4, Solution::maximumDifference(input));
		}

		TEST(maximum_difference_between_increasing_elements, case2) {
			vector input = {9, 4, 3, 2};
			ASSERT_EQ(-1, Solution::maximumDifference(input));
		}

		TEST(maximum_difference_between_increasing_elements, case3) {
			vector input = {1, 5, 2, 10};
			ASSERT_EQ(9, Solution::maximumDifference(input));
		}
	}// namespace maximum_difference_between_increasing_elements

	namespace optimal_division {
		TEST(optimal_division, case1) {
			vector input = {1000, 100, 10, 2};
			ASSERT_EQ("1000/(100/10/2)", Solution::optimalDivision(input));
		}

		TEST(optimal_division, case2) {
			vector input = {2, 3, 4};
			ASSERT_EQ("2/(3/4)", Solution::optimalDivision(input));
		}

		TEST(optimal_division, case3) {
			vector input = {2};
			ASSERT_EQ("2", Solution::optimalDivision(input));
		}
	}// namespace optimal_division

	namespace minimum_time_to_complete_trips {
		TEST(minimum_time_to_complete_trips, case1) {
			vector input = {1, 2, 3};
			ASSERT_EQ(3, Solution::minimumTime(input, 5));
		}

		TEST(minimum_time_to_complete_trips, case2) {
			vector input = {2};
			ASSERT_EQ(2, Solution::minimumTime(input, 1));
		}

		TEST(minimum_time_to_complete_trips, case3) {
			vector input = {5, 10, 10};
			ASSERT_EQ(25, Solution::minimumTime(input, 9));
		}
	}// namespace minimum_time_to_complete_trips

	namespace minimum_time_to_finish_the_race {
		TEST(minimum_time_to_finish_the_race, case1) {
			vector<vector<int>> input = {{2, 3}, {3, 4}};
			ASSERT_EQ(21, Solution::minimumFinishTime(input, 5, 4));
		}

		TEST(minimum_time_to_finish_the_race, case2) {
			vector<vector<int>> input = {{1, 10}, {2, 2}, {3, 4}};
			ASSERT_EQ(25, Solution::minimumFinishTime(input, 6, 5));
		}
	}// namespace minimum_time_to_finish_the_race

	namespace maximum_number_of_achievable_transfer_requests {
		TEST(maximum_number_of_achievable_transfer_requests, case1) {
			vector<vector<int>> input = {{0, 1}, {1, 0}, {0, 1}, {1, 2}, {2, 0}, {3, 4}};
			ASSERT_EQ(5, Solution::maximumRequests(5, input));
		}

		TEST(maximum_number_of_achievable_transfer_requests, case2) {
			vector<vector<int>> input = {{0, 0}, {1, 2}, {2, 1}};
			ASSERT_EQ(3, Solution::maximumRequests(3, input));
		}

		TEST(maximum_number_of_achievable_transfer_requests, case3) {
			vector<vector<int>> input = {{0, 3}, {3, 1}, {1, 2}, {2, 0}};
			ASSERT_EQ(4, Solution::maximumRequests(4, input));
		}
	}// namespace maximum_number_of_achievable_transfer_requests

	namespace zigzag_conversion {
		TEST(zigzag_conversion, case1) {
			ASSERT_EQ("PAHNAPLSIIGYIR", Solution::convert("PAYPALISHIRING", 3));
		}

		TEST(zigzag_conversion, case2) {
			ASSERT_EQ("PINALSIGYAHRPI", Solution::convert("PAYPALISHIRING", 4));
		}

		TEST(zigzag_conversion, case3) {
			ASSERT_EQ("A", Solution::convert("A", 1));
		}
	}// namespace zigzag_conversion

	namespace find_the_closest_palindrome {
		TEST(find_the_closest_palindrome, case1) {
			ASSERT_EQ("121", Solution::nearestPalindromic("123"));
		}

		TEST(find_the_closest_palindrome, case2) {
			ASSERT_EQ("0", Solution::nearestPalindromic("1"));
		}

		TEST(find_the_closest_palindrome, case3) {
			ASSERT_EQ("1221", Solution::nearestPalindromic("1234"));
		}

		TEST(find_the_closest_palindrome, case4) {
			ASSERT_EQ("1001", Solution::nearestPalindromic("999"));
		}

		TEST(find_the_closest_palindrome, case5) {
			ASSERT_EQ("999", Solution::nearestPalindromic("1000"));
		}

		TEST(find_the_closest_palindrome, case6) {
			ASSERT_EQ("12921", Solution::nearestPalindromic("12932"));
		}

		TEST(find_the_closest_palindrome, case7) {
			ASSERT_EQ("99799", Solution::nearestPalindromic("99800"));
		}

		TEST(find_the_closest_palindrome, case8) {
			ASSERT_EQ("12121", Solution::nearestPalindromic("12120"));
		}

		TEST(find_the_closest_palindrome, case9) {
			ASSERT_EQ("1805115081", Solution::nearestPalindromic("1805170081"));
		}
	}// namespace find_the_closest_palindrome

	namespace add_digits {
		TEST(add_digits, case1) {
			ASSERT_EQ(2, Solution::addDigits(38));
		}

		TEST(add_digits, case2) {
			ASSERT_EQ(0, Solution::addDigits(0));
		}
	}// namespace add_digits

	namespace sum_of_subarray_ranges {
		TEST(sum_of_subarray_ranges, case1) {
			vector input = {1, 2, 3};
			ASSERT_EQ(4, Solution::subArrayRanges(input));
		}

		TEST(sum_of_subarray_ranges, case2) {
			vector input = {1, 3, 3};
			ASSERT_EQ(4, Solution::subArrayRanges(input));
		}

		TEST(sum_of_subarray_ranges, case3) {
			vector input = {4, -2, -3, 4, 1};
			ASSERT_EQ(59, Solution::subArrayRanges(input));
		}
	}// namespace sum_of_subarray_ranges

	namespace longest_uncommon_subsequence_i {
		TEST(longest_uncommon_subsequence_i, case1) {
			ASSERT_EQ(3, Solution::findLUSlength("aba", "cdc"));
		}

		TEST(longest_uncommon_subsequence_i, case2) {
			ASSERT_EQ(3, Solution::findLUSlength("aaa", "bbb"));
		}

		TEST(longest_uncommon_subsequence_i, case3) {
			ASSERT_EQ(-1, Solution::findLUSlength("aaa", "aaa"));
		}
	}// namespace longest_uncommon_subsequence_i

	namespace most_frequent_number_following_key_in_an_array {
		TEST(most_frequent_number_following_key_in_an_array, case1) {
			vector input = {1, 100, 200, 1, 100};
			ASSERT_EQ(100, Solution::mostFrequent(input, 1));
		}

		TEST(most_frequent_number_following_key_in_an_array, case2) {
			vector input = {2, 2, 2, 2, 3};
			ASSERT_EQ(2, Solution::mostFrequent(input, 2));
		}
	}// namespace most_frequent_number_following_key_in_an_array

	namespace sort_the_jumbled_numbers {
		TEST(sort_the_jumbled_numbers, case1) {
			vector mapping      = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
			vector nums         = {991, 338, 38};
			const vector output = {338, 38, 991};
			ASSERT_EQ(output, Solution::sortJumbled(mapping, nums));
		}

		TEST(sort_the_jumbled_numbers, case2) {
			vector mapping      = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			vector nums         = {789, 456, 123};
			const vector output = {123, 456, 789};
			ASSERT_EQ(output, Solution::sortJumbled(mapping, nums));
		}
	}// namespace sort_the_jumbled_numbers

	namespace all_ancestors_of_a_node_in_a_directed_acyclic_graph {
		TEST(all_ancestors_of_a_node_in_a_directed_acyclic_graph, case1) {
			vector<vector<int>> input        = {{0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7}, {4, 6}};
			const vector<vector<int>> output = {{}, {}, {}, {0, 1}, {0, 2}, {0, 1, 3}, {0, 1, 2, 3, 4}, {0, 1, 2, 3}};
			auto sol                         = Solution();
			ASSERT_EQ(output, sol.getAncestors(8, input));
		}

		TEST(all_ancestors_of_a_node_in_a_directed_acyclic_graph, case2) {
			vector<vector<int>> input        = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
			const vector<vector<int>> output = {{}, {0}, {0, 1}, {0, 1, 2}, {0, 1, 2, 3}};
			auto sol                         = Solution();
			ASSERT_EQ(output, sol.getAncestors(5, input));
		}
	}// namespace all_ancestors_of_a_node_in_a_directed_acyclic_graph

	namespace minimum_number_of_moves_to_make_palindrome {
		TEST(minimum_number_of_moves_to_make_palindrome, case1) {
			ASSERT_EQ(2, Solution::minMovesToMakePalindrome("aabb"));
		}

		TEST(minimum_number_of_moves_to_make_palindrome, case2) {
			ASSERT_EQ(2, Solution::minMovesToMakePalindrome("letelt"));
		}

		TEST(minimum_number_of_moves_to_make_palindrome, case3) {
			ASSERT_EQ(163, Solution::minMovesToMakePalindrome("skwhhaaunskegmdtutlgtteunmuuludii"));
		}
	}// namespace minimum_number_of_moves_to_make_palindrome

	namespace cells_in_a_range_on_an_excel_sheet {
		TEST(cells_in_a_range_on_an_excel_sheet, case1) {
			const vector<string> output = {"K1", "K2", "L1", "L2"};
			ASSERT_EQ(output, Solution::cellsInRange("K1:L2"));
		}

		TEST(cells_in_a_range_on_an_excel_sheet, case2) {
			const vector<string> output = {"A1", "B1", "C1", "D1", "E1", "F1"};
			ASSERT_EQ(output, Solution::cellsInRange("A1:F1"));
		}
	}// namespace cells_in_a_range_on_an_excel_sheet

	namespace append_k_integers_with_minimal_sum {
		TEST(append_k_integers_with_minimal_sum, case1) {
			vector input = {96, 44, 99, 25, 61, 84, 88, 18, 19, 33, 60, 86, 52, 19, 32, 47, 35, 50, 94, 17, 29, 98, 22, 21, 72, 100, 40, 84};
			ASSERT_EQ(794, Solution::minimalKSum(input, 35));
		}

		TEST(append_k_integers_with_minimal_sum, case2) {
			vector input = {5, 6};
			ASSERT_EQ(25, Solution::minimalKSum(input, 6));
		}

		TEST(append_k_integers_with_minimal_sum, case3) {
			vector input = {1, 4, 25, 10, 25};
			ASSERT_EQ(5, Solution::minimalKSum(input, 2));
		}

		TEST(append_k_integers_with_minimal_sum, case4) {
			vector input = {1, 2};
			ASSERT_EQ(3, Solution::minimalKSum(input, 1));
		}

		TEST(append_k_integers_with_minimal_sum, case5) {
			vector input = {2, 2, 2, 2};
			ASSERT_EQ(8, Solution::minimalKSum(input, 3));
		}
	}// namespace append_k_integers_with_minimal_sum

	namespace replace_non_coprime_numbers_in_array {
		TEST(replace_non_coprime_numbers_in_array, case1) {
			vector input        = {6, 4, 3, 2, 7, 6, 2};
			const vector output = {12, 7, 6};
			ASSERT_EQ(output, Solution::replaceNonCoprimes(input));
		}

		TEST(replace_non_coprime_numbers_in_array, case2) {
			vector input        = {2, 2, 1, 1, 3, 3, 3};
			const vector output = {2, 1, 1, 3};
			ASSERT_EQ(output, Solution::replaceNonCoprimes(input));
		}
	}// namespace replace_non_coprime_numbers_in_array

	namespace find_good_days_to_rob_the_bank {
		TEST(find_good_days_to_rob_the_bank, case1) {
			vector input        = {5, 3, 3, 3, 5, 6, 2};
			const vector output = {2, 3};
			ASSERT_EQ(output, Solution::goodDaysToRobBank(input, 2));
		}

		TEST(find_good_days_to_rob_the_bank, case2) {
			vector input        = {1, 1, 1, 1, 1};
			const vector output = {0, 1, 2, 3, 4};
			ASSERT_EQ(output, Solution::goodDaysToRobBank(input, 0));
		}

		TEST(find_good_days_to_rob_the_bank, case3) {
			vector input             = {1, 2, 3, 4, 5, 6};
			const vector<int> output = {};
			ASSERT_EQ(output, Solution::goodDaysToRobBank(input, 2));
		}

		TEST(find_good_days_to_rob_the_bank, case4) {
			vector input             = {4, 3, 2, 1};
			const vector<int> output = {};
			ASSERT_EQ(output, Solution::goodDaysToRobBank(input, 1));
		}
	}// namespace find_good_days_to_rob_the_bank

	namespace base_7 {
		TEST(base_7, case1) {
			ASSERT_EQ("202", Solution::convertToBase7(100));
		}

		TEST(base_7, case2) {
			ASSERT_EQ("-10", Solution::convertToBase7(-7));
		}
	}// namespace base_7

	namespace plates_between_candles {
		TEST(plates_between_candles, case1) {
			vector<vector<int>> input = {{2, 5}, {5, 9}};
			const vector output       = {2, 3};
			ASSERT_EQ(output, Solution::platesBetweenCandles("**|**|***|", input));
		}

		TEST(plates_between_candles, case2) {
			vector<vector<int>> input = {{1, 17}, {4, 5}, {14, 17}, {5, 11}, {15, 16}};
			const vector output       = {9, 0, 0, 0, 0};
			ASSERT_EQ(output, Solution::platesBetweenCandles("***|**|*****|**||**|*", input));
		}
	}// namespace plates_between_candles

	namespace smallest_rotation_with_highest_score {
		TEST(smallest_rotation_with_highest_score, case1) {
			vector input = {2, 3, 1, 4, 0};
			ASSERT_EQ(3, Solution::bestRotation(input));
		}

		TEST(smallest_rotation_with_highest_score, case2) {
			vector input = {1, 3, 0, 2, 4};
			ASSERT_EQ(0, Solution::bestRotation(input));
		}
	}// namespace smallest_rotation_with_highest_score

	namespace count_nodes_with_the_highest_score {
		TEST(count_nodes_with_the_highest_score, case1) {
			vector input = {-1, 2, 0, 2, 0};
			ASSERT_EQ(3, Solution::countHighestScoreNodes(input));
		}

		TEST(count_nodes_with_the_highest_score, case2) {
			vector input = {-1, 2, 0};
			ASSERT_EQ(2, Solution::countHighestScoreNodes(input));
		}
	}// namespace count_nodes_with_the_highest_score

	namespace max_area_of_island {
		TEST(max_area_of_island, case1) {
			vector<vector<int>> input = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
			                             {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
			                             {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
			                             {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
			                             {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
			                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
			                             {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
			                             {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
			ASSERT_EQ(6, Solution::maxAreaOfIsland(input));
		}

		TEST(max_area_of_island, case2) {
			vector<vector<int>> input = {{0, 0, 0, 0, 0, 0, 0, 0}};
			ASSERT_EQ(0, Solution::maxAreaOfIsland(input));
		}
	}// namespace max_area_of_island

	namespace find_all_k_distant_indices_in_an_array {
		TEST(find_all_k_distant_indices_in_an_array, case1) {
			vector nums         = {3, 4, 9, 1, 3, 9, 5};
			const vector output = {1, 2, 3, 4, 5, 6};
			ASSERT_EQ(output, Solution::findKDistantIndices(nums, 9, 1));
		}

		TEST(find_all_k_distant_indices_in_an_array, case2) {
			vector nums         = {2, 2, 2, 2, 2};
			const vector output = {0, 1, 2, 3, 4};
			ASSERT_EQ(output, Solution::findKDistantIndices(nums, 2, 2));
		}
	}// namespace find_all_k_distant_indices_in_an_array

	namespace count_artifacts_that_can_be_extracted {
		TEST(count_artifacts_that_can_be_extracted, case1) {
			vector<vector<int>> artifacts = {{0, 0, 0, 0}, {0, 1, 1, 1}};
			vector<vector<int>> dig       = {{0, 0}, {0, 1}};
			ASSERT_EQ(1, Solution::digArtifacts(2, artifacts, dig));
		}

		TEST(count_artifacts_that_can_be_extracted, case2) {
			vector<vector<int>> artifacts = {{0, 0, 0, 0}, {0, 1, 1, 1}};
			vector<vector<int>> dig       = {{0, 0}, {0, 1}, {1, 1}};
			ASSERT_EQ(2, Solution::digArtifacts(2, artifacts, dig));
		}
	}// namespace count_artifacts_that_can_be_extracted

	namespace maximize_the_topmost_element_after_k_moves {
		TEST(maximize_the_topmost_element_after_k_moves, case1) {
			vector nums = {5, 2, 2, 4, 0, 6};
			ASSERT_EQ(5, Solution::maximumTop(nums, 4));
		}

		TEST(maximize_the_topmost_element_after_k_moves, case2) {
			vector nums = {2};
			ASSERT_EQ(-1, Solution::maximumTop(nums, 1));
		}
	}// namespace maximize_the_topmost_element_after_k_moves

	namespace minimum_weighted_subgraph_with_the_required_paths {
		TEST(minimum_weighted_subgraph_with_the_required_paths, case1) {
			vector<vector<int>> edges = {{0, 2, 2}, {0, 5, 6}, {1, 0, 3}, {1, 4, 5}, {2, 1, 1}, {2, 3, 3}, {2, 3, 4}, {3, 4, 2}, {4, 5, 1}};
			ASSERT_EQ(9, Solution::minimumWeight(6, edges, 0, 1, 5));
		}

		TEST(minimum_weighted_subgraph_with_the_required_paths, case2) {
			vector<vector<int>> edges = {{0, 1, 1}, {2, 1, 1}};
			ASSERT_EQ(-1, Solution::minimumWeight(3, edges, 0, 1, 2));
		}

		TEST(minimum_weighted_subgraph_with_the_required_paths, case3) {
			vector<vector<int>> edges = {{4, 2, 20}, {4, 3, 46}, {0, 1, 15}, {0, 1, 43}, {0, 1, 32}, {3, 1, 13}};
			ASSERT_EQ(74, Solution::minimumWeight(5, edges, 0, 4, 1));
		}

		TEST(minimum_weighted_subgraph_with_the_required_paths, case4) {
			vector<vector<int>> edges = {{31, 64, 44}, {31, 6, 14}, {46, 21, 45}, {46, 65, 27}, {46, 30, 46}, {31, 0, 14}, {31, 29, 40}, {46, 95, 6}, {46, 73, 62}, {31, 74, 16}, {31, 55, 35}, {46, 40, 89}, {46, 57, 93}, {31, 90, 27}, {46, 58, 59}, {46, 12, 80}, {31, 44, 26}, {46, 67, 82}, {31, 8, 64}, {31, 23, 15}, {31, 7, 27}, {31, 94, 33}, {31, 86, 36}, {31, 33, 61}, {46, 88, 46}, {46, 69, 76}, {46, 39, 89}, {46, 53, 17}, {31, 75, 69}, {31, 72, 30}, {46, 83, 87}, {31, 35, 86}, {31, 62, 84}, {46, 51, 47}, {46, 66, 16}, {46, 50, 85}, {46, 81, 65}, {46, 36, 89}, {46, 60, 21}, {46, 10, 76}, {31, 18, 70}, {46, 3, 93}, {31, 47, 52}, {46, 16, 61}, {31, 15, 77}, {46, 28, 3}, {31, 93, 53}, {46, 43, 94}, {31, 38, 25}, {46, 1, 42}, {31, 22, 49}, {46, 45, 55}, {46, 99, 43}, {46, 24, 90}, {31, 9, 28}, {46, 13, 15}, {46, 27, 93}, {46, 49, 83}, {31, 71, 51}, {31, 59, 93}, {31, 91, 98}, {31, 54, 67}, {31, 25, 75}, {31, 68, 24}, {31, 76, 13}, {31, 41, 31}, {31, 19, 36}, {31, 87, 37}, {46, 17, 70}, {46, 97, 46}, {46, 61, 82}, {46, 79, 74}, {46, 85, 18}, {46, 14, 74}, {31, 32, 60}, {46, 84, 69}, {31, 34, 69}, {31, 4, 13}, {46, 70, 27}, {31, 48, 27}, {31, 11, 63}, {46, 5, 14}, {46, 37, 88}, {31, 96, 70}, {46, 52, 17}, {46, 42, 9}, {46, 20, 68}, {31, 77, 79}, {31, 80, 68}, {46, 78, 13}, {46, 26, 48}, {46, 2, 10}, {46, 63, 6}, {31, 89, 66}, {31, 56, 96}, {46, 92, 36}, {46, 98, 12}, {46, 82, 94}, {8, 82, 84}, {92, 82, 23}, {40, 82, 98}, {39, 82, 67}, {86, 82, 37}, {75, 82, 21}};
			ASSERT_EQ(132, Solution::minimumWeight(100, edges, 46, 31, 82));
		}
	}// namespace minimum_weighted_subgraph_with_the_required_paths

	namespace utf_8_validation {
		TEST(utf_8_validation, case1) {
			vector data = {193, 130, 1};
			ASSERT_TRUE(Solution::validUtf8(data));
		}

		TEST(utf_8_validation, case2) {
			vector data = {235, 140, 4};
			ASSERT_FALSE(Solution::validUtf8(data));
		}

		TEST(utf_8_validation, case3) {
			vector data = {250, 145, 145, 145, 145};
			ASSERT_FALSE(Solution::validUtf8(data));
		}
	}// namespace utf_8_validation

	namespace minimum_index_sum_of_two_lists {
		TEST(minimum_index_sum_of_two_lists, case1) {
			vector<string> list1        = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
			vector<string> list2        = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
			const vector<string> output = {"Shogun"};
			ASSERT_EQ(output, Solution::findRestaurant(list1, list2));
		}

		TEST(minimum_index_sum_of_two_lists, case2) {
			vector<string> list1        = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
			vector<string> list2        = {"KFC", "Shogun", "Burger King"};
			const vector<string> output = {"Shogun"};
			ASSERT_EQ(output, Solution::findRestaurant(list1, list2));
		}
	}// namespace minimum_index_sum_of_two_lists

	namespace count_number_of_maximum_bitwise_or_subsets {
		TEST(count_number_of_maximum_bitwise_or_subsets, case1) {
			vector nums = {3, 1};
			ASSERT_EQ(2, Solution::countMaxOrSubsets(nums));
		}

		TEST(count_number_of_maximum_bitwise_or_subsets, case2) {
			vector nums = {2, 2, 2};
			ASSERT_EQ(7, Solution::countMaxOrSubsets(nums));
		}

		TEST(count_number_of_maximum_bitwise_or_subsets, case3) {
			vector nums = {3, 2, 1, 5};
			ASSERT_EQ(6, Solution::countMaxOrSubsets(nums));
		}
	}// namespace count_number_of_maximum_bitwise_or_subsets

	namespace all_oone_data_structure {
		TEST(all_oone_data_structure, case1) {
			AllOne ao;
			ao.inc("a");
			ao.inc("b");
			ao.inc("b");
			ao.inc("c");
			ao.inc("c");
			ao.inc("c");
			ao.dec("b");
			ao.dec("b");
			ao.getMinKey();
			ao.dec("a");
			ao.getMaxKey();
			ao.getMinKey();
		}
	}// namespace all_oone_data_structure

	namespace longest_word_in_dictionary {
		TEST(longest_word_in_dictionary, case1) {
			vector<string> words = {"w", "wo", "wor", "worl", "world"};
			const string output  = "world";
			ASSERT_EQ(output, Solution::longestWord(words));
		}

		TEST(longest_word_in_dictionary, case2) {
			vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
			const string output  = "apple";
			ASSERT_EQ(output, Solution::longestWord(words));
		}
	}// namespace longest_word_in_dictionary

	namespace maximize_number_of_subsequences_in_a_string {
		TEST(maximize_number_of_subsequences_in_a_string, case1) {
			ASSERT_EQ(4, Solution::maximumSubsequenceCount("abdcdbc", "ac"));
		}

		TEST(maximize_number_of_subsequences_in_a_string, case2) {
			ASSERT_EQ(6, Solution::maximumSubsequenceCount("aabb", "ab"));
		}
	}// namespace maximize_number_of_subsequences_in_a_string

	namespace minimum_operations_to_halve_array_sum {
		TEST(minimum_operations_to_halve_array_sum, case1) {
			vector nums = {5, 19, 8, 1};
			ASSERT_EQ(3, Solution::halveArray(nums));
		}

		TEST(minimum_operations_to_halve_array_sum, case2) {
			vector nums = {3, 8, 20};
			ASSERT_EQ(3, Solution::halveArray(nums));
		}
	}// namespace minimum_operations_to_halve_array_sum

	namespace minimum_white_tiles_after_covering_with_carpets {
		TEST(minimum_white_tiles_after_covering_with_carpets, case1) {
			ASSERT_EQ(2, Solution::minimumWhiteTiles("10110101", 2, 2));
		}

		TEST(minimum_white_tiles_after_covering_with_carpets, case2) {
			ASSERT_EQ(0, Solution::minimumWhiteTiles("11111", 2, 3));
		}

		TEST(minimum_white_tiles_after_covering_with_carpets, case3) {
			ASSERT_EQ(0, Solution::minimumWhiteTiles("10111101", 2, 4));
		}
	}// namespace minimum_white_tiles_after_covering_with_carpets

	namespace count_hills_and_valleys_in_an_array {
		TEST(count_hills_and_valleys_in_an_array, case1) {
			vector num = {2, 4, 1, 1, 6, 5};
			ASSERT_EQ(3, Solution::countHillValley(num));
		}

		TEST(count_hills_and_valleys_in_an_array, case2) {
			vector num = {6, 6, 5, 5, 4, 1};
			ASSERT_EQ(0, Solution::countHillValley(num));
		}
	}// namespace count_hills_and_valleys_in_an_array

	namespace count_collisions_on_a_road {
		TEST(count_collisions_on_a_road, case1) {
			ASSERT_EQ(5, Solution::countCollisions("RLRSLL"));
		}

		TEST(count_collisions_on_a_road, case2) {
			ASSERT_EQ(0, Solution::countCollisions("LLRR"));
		}
	}// namespace count_collisions_on_a_road

	namespace maximum_points_in_an_archery_competition {
		TEST(maximum_points_in_an_archery_competition, case1) {
			vector aliceArrows  = {1, 1, 0, 1, 0, 0, 2, 1, 0, 1, 2, 0};
			const vector output = {0, 0, 0, 0, 1, 1, 0, 0, 1, 2, 3, 1};
			ASSERT_EQ(output, Solution::maximumBobPoints(9, aliceArrows));
		}

		TEST(maximum_points_in_an_archery_competition, case2) {
			vector aliceArrows  = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2};
			const vector output = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0};
			ASSERT_EQ(output, Solution::maximumBobPoints(3, aliceArrows));
		}
	}// namespace maximum_points_in_an_archery_competition

	namespace the_time_when_the_network_becomes_idle {
		TEST(the_time_when_the_network_becomes_idle, case1) {
			vector<vector<int>> edges = {{0, 1}, {1, 2}};
			vector patience           = {0, 2, 1};
			ASSERT_EQ(8, Solution::networkBecomesIdle(edges, patience));
		}

		TEST(the_time_when_the_network_becomes_idle, case2) {
			vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};
			vector patience           = {0, 10, 10};
			ASSERT_EQ(3, Solution::networkBecomesIdle(edges, patience));
		}
	}// namespace the_time_when_the_network_becomes_idle

	namespace remove_colored_pieces_if_both_neighbors_are_the_same_color {
		TEST(remove_colored_pieces_if_both_neighbors_are_the_same_color, case1) {
			ASSERT_TRUE(Solution::winnerOfGame("AAABABB"));
		}

		TEST(remove_colored_pieces_if_both_neighbors_are_the_same_color, case2) {
			ASSERT_FALSE(Solution::winnerOfGame("AA"));
		}

		TEST(remove_colored_pieces_if_both_neighbors_are_the_same_color, case3) {
			ASSERT_FALSE(Solution::winnerOfGame("ABBBBBBBAAA"));
		}
	}// namespace remove_colored_pieces_if_both_neighbors_are_the_same_color

	namespace k_th_smallest_in_lexicographical_order {
		TEST(k_th_smallest_in_lexicographical_order, case1) {
			ASSERT_EQ(10, Solution::findKthNumber(13, 2));
		}

		TEST(k_th_smallest_in_lexicographical_order, case2) {
			ASSERT_EQ(1, Solution::findKthNumber(1, 1));
		}
	}// namespace k_th_smallest_in_lexicographical_order

	namespace image_smoother {
		TEST(image_smoother, case1) {
			vector<vector<int>> img          = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
			const vector<vector<int>> output = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
			ASSERT_EQ(output, Solution::imageSmoother(img));
		}

		TEST(image_smoother, case2) {
			vector<vector<int>> img          = {{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};
			const vector<vector<int>> output = {{137, 141, 137}, {141, 138, 141}, {137, 141, 137}};
			ASSERT_EQ(output, Solution::imageSmoother(img));
		}
	}// namespace image_smoother

	namespace factorial_trailing_zeroes {
		TEST(factorial_trailing_zeroes, case1) {
			ASSERT_EQ(0, Solution::trailingZeroes(3));
		}

		TEST(factorial_trailing_zeroes, case2) {
			ASSERT_EQ(1, Solution::trailingZeroes(5));
		}

		TEST(factorial_trailing_zeroes, case3) {
			ASSERT_EQ(0, Solution::trailingZeroes(0));
		}
	}// namespace factorial_trailing_zeroes

	namespace baseball_game {
		TEST(baseball_game, case1) {
			vector<string> ops = {"5", "2", "C", "D", "+"};
			ASSERT_EQ(30, Solution::calPoints(ops));
		}

		TEST(baseball_game, case2) {
			vector<string> ops = {"5", "-2", "4", "C", "D", "9", "+", "+"};
			ASSERT_EQ(27, Solution::calPoints(ops));
		}

		TEST(baseball_game, case3) {
			vector<string> ops = {"1"};
			ASSERT_EQ(1, Solution::calPoints(ops));
		}
	}// namespace baseball_game

	namespace find_palindrome_with_fixed_length {
		TEST(find_palindrome_with_fixed_length, case1) {
			vector queries                 = {1, 2, 3, 4, 5, 90};
			const vector<long long> output = {101, 111, 121, 131, 141, 999};
			ASSERT_EQ(output, Solution::kthPalindrome(queries, 3));
		}

		TEST(find_palindrome_with_fixed_length, case2) {
			vector queries                 = {2, 4, 6};
			const vector<long long> output = {1111, 1331, 1551};
			ASSERT_EQ(output, Solution::kthPalindrome(queries, 4));
		}

		TEST(find_palindrome_with_fixed_length, case4) {
			vector queries                 = {10};
			const vector<long long> output = {191};
			ASSERT_EQ(output, Solution::kthPalindrome(queries, 3));
		}

		TEST(find_palindrome_with_fixed_length, case5) {
			vector queries                 = {9};
			const vector<long long> output = {10801};
			ASSERT_EQ(output, Solution::kthPalindrome(queries, 5));
		}

		TEST(find_palindrome_with_fixed_length, case7) {
			vector queries                 = {60};
			const vector<long long> output = {15951};
			ASSERT_EQ(output, Solution::kthPalindrome(queries, 5));
		}
	}// namespace find_palindrome_with_fixed_length

	namespace find_missing_observations {
		TEST(find_missing_observations, case1) {
			vector rolls        = {3, 2, 4, 3};
			const vector output = {6, 6};
			ASSERT_EQ(output, Solution::missingRolls(rolls, 4, 2));
		}

		TEST(find_missing_observations, case3) {
			vector rolls             = {1, 2, 3, 4};
			const vector<int> output = {};
			ASSERT_EQ(output, Solution::missingRolls(rolls, 6, 4));
		}
	}// namespace find_missing_observations

	namespace binary_number_with_alternating_bits {
		TEST(binary_number_with_alternating_bits, case1) {
			ASSERT_TRUE(Solution::hasAlternatingBits(5));
		}

		TEST(binary_number_with_alternating_bits, case2) {
			ASSERT_FALSE(Solution::hasAlternatingBits(7));
		}

		TEST(binary_number_with_alternating_bits, case3) {
			ASSERT_FALSE(Solution::hasAlternatingBits(11));
		}
	}// namespace binary_number_with_alternating_bits

	namespace maximize_the_confusion_of_an_exam {
		TEST(maximize_the_confusion_of_an_exam, case1) {
			ASSERT_EQ(4, Solution::maxConsecutiveAnswers("TTFF", 2));
		}

		TEST(maximize_the_confusion_of_an_exam, case2) {
			ASSERT_EQ(3, Solution::maxConsecutiveAnswers("TFFT", 1));
		}

		TEST(maximize_the_confusion_of_an_exam, case3) {
			ASSERT_EQ(5, Solution::maxConsecutiveAnswers("TTFTTFTT", 1));
		}

		TEST(maximize_the_confusion_of_an_exam, case4) {
			ASSERT_EQ(1, Solution::maxConsecutiveAnswers("F", 1));
		}
	}// namespace maximize_the_confusion_of_an_exam

	namespace find_servers_that_handled_most_number_of_requests {
		TEST(find_servers_that_handled_most_number_of_requests, case1) {
			vector arrival      = {1, 2, 3, 4, 5};
			vector load         = {5, 2, 3, 3, 3};
			const vector output = {1};
			ASSERT_EQ(output, Solution::busiestServers(3, arrival, load));
		}

		TEST(find_servers_that_handled_most_number_of_requests, case2) {
			vector arrival      = {1, 2, 3, 4};
			vector load         = {1, 2, 1, 2};
			const vector output = {0};
			ASSERT_EQ(output, Solution::busiestServers(3, arrival, load));
		}

		TEST(find_servers_that_handled_most_number_of_requests, case3) {
			vector arrival      = {1, 2, 3};
			vector load         = {10, 12, 11};
			const vector output = {0, 1, 2};
			ASSERT_EQ(output, Solution::busiestServers(3, arrival, load));
		}

		TEST(find_servers_that_handled_most_number_of_requests, case4) {
			vector arrival      = {1, 2, 3};
			vector load         = {1000000000, 1, 1000000000};
			const vector output = {1};
			ASSERT_EQ(output, Solution::busiestServers(2, arrival, load));
		}
	}// namespace find_servers_that_handled_most_number_of_requests

	namespace self_dividing_numbers {
		TEST(self_dividing_numbers, case1) {
			const vector output = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22};
			ASSERT_EQ(output, Solution::selfDividingNumbers(1, 22));
		}

		TEST(self_dividing_numbers, case2) {
			const vector output = {48, 55, 66, 77};
			ASSERT_EQ(output, Solution::selfDividingNumbers(47, 85));
		}
	}// namespace self_dividing_numbers

	namespace array_of_doubled_pairs {
		TEST(array_of_doubled_pairs, case1) {
			vector arr = {3, 1, 3, 6};
			ASSERT_FALSE(Solution::canReorderDoubled(arr));
		}

		TEST(array_of_doubled_pairs, case2) {
			vector arr = {2, 1, 2, 6};
			ASSERT_FALSE(Solution::canReorderDoubled(arr));
		}
	}// namespace array_of_doubled_pairs

	namespace strong_password_checker {
		TEST(strong_password_checker, case1) {
			ASSERT_EQ(5, Solution::strongPasswordChecker("a"));
		}

		TEST(strong_password_checker, case2) {
			ASSERT_EQ(3, Solution::strongPasswordChecker("aA1"));
		}

		TEST(strong_password_checker, case3) {
			ASSERT_EQ(0, Solution::strongPasswordChecker("1337C0d3"));
		}

		TEST(strong_password_checker, case4) {
			ASSERT_EQ(1, Solution::strongPasswordChecker("1111b"));
		}

		TEST(strong_password_checker, case5) {
			ASSERT_EQ(2, Solution::strongPasswordChecker("aaaa"));
		}
	}// namespace strong_password_checker

	namespace sum_of_scores_of_built_strings {
		TEST(sum_of_scores_of_built_strings, case1) {
			ASSERT_EQ(9, Solution::sumScores("babab"));
		}

		TEST(sum_of_scores_of_built_strings, case2) {
			ASSERT_EQ(14, Solution::sumScores("azbazbzaz"));
		}
	}// namespace sum_of_scores_of_built_strings

	namespace minimum_number_of_operations_to_convert_time {
		TEST(minimum_number_of_operations_to_convert_time, case1) {
			ASSERT_EQ(3, Solution::convertTime("02:30", "04:35"));
		}

		TEST(minimum_number_of_operations_to_convert_time, case2) {
			ASSERT_EQ(1, Solution::convertTime("11:00", "11:01"));
		}

		TEST(minimum_number_of_operations_to_convert_time, case3) {
			ASSERT_EQ(32, Solution::convertTime("00:00", "23:59"));
		}
	}// namespace minimum_number_of_operations_to_convert_time

	namespace find_players_with_zero_or_one_losses {
		TEST(find_players_with_zero_or_one_losses, case1) {
			vector<vector<int>> matches      = {{1, 3},
			                                    {2, 3},
			                                    {3, 6},
			                                    {5, 6},
			                                    {5, 7},
			                                    {4, 5},
			                                    {4, 8},
			                                    {4, 9},
			                                    {10, 4},
			                                    {10, 9}};
			const vector<vector<int>> output = {{1, 2, 10}, {4, 5, 7, 8}};
			ASSERT_EQ(output, Solution::findWinners(matches));
		}

		TEST(find_players_with_zero_or_one_losses, case2) {
			vector<vector<int>> matches      = {{2, 3}, {1, 3}, {5, 4}, {6, 4}};
			const vector<vector<int>> output = {{1, 2, 5, 6}, {}};
			ASSERT_EQ(output, Solution::findWinners(matches));
		}
	}// namespace find_players_with_zero_or_one_losses

	namespace maximum_candies_allocated_to_k_children {
		TEST(maximum_candies_allocated_to_k_children, case1) {
			vector candies = {5, 8, 6};
			ASSERT_EQ(5, Solution::maximumCandies(candies, 3));
		}

		TEST(maximum_candies_allocated_to_k_children, case2) {
			vector candies = {2, 5};
			ASSERT_EQ(0, Solution::maximumCandies(candies, 11));
		}

		TEST(maximum_candies_allocated_to_k_children, case3) {
			vector candies = {1, 2, 3, 4, 10};
			ASSERT_EQ(3, Solution::maximumCandies(candies, 5));
		}

		TEST(maximum_candies_allocated_to_k_children, case4) {
			vector candies = {123, 13300, 1000, 23, 11, 41, 311};
			ASSERT_EQ(15, Solution::maximumCandies(candies, 980));
		}
	}// namespace maximum_candies_allocated_to_k_children

	namespace encrypt_and_decrypt_strings {
		TEST(encrypt_and_decrypt_strings, case1) {
			vector keys               = {'a', 'b', 'c', 'd'};
			vector<string> values     = {"ei", "zf", "ei", "am"};
			vector<string> dictionary = {"abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"};
			auto enc                  = Encrypter(keys, values, dictionary);
			ASSERT_EQ("eizfeiam", enc.encrypt("abcd"));
			ASSERT_EQ(2, enc.decrypt("eizfeiam"));
		}
	}// namespace encrypt_and_decrypt_strings

	namespace process_restricted_friend_requests {
		TEST(process_restricted_friend_requests, case1) {
			vector<vector<int>> restrictions = {{0, 1}};
			vector<vector<int>> requests     = {{0, 2}, {2, 1}};
			const vector output              = {true, false};
			ASSERT_EQ(output, Solution::friendRequests(3, restrictions, requests));
		}

		TEST(process_restricted_friend_requests, case2) {
			vector<vector<int>> restrictions = {{0, 1}};
			vector<vector<int>> requests     = {{1, 2}, {0, 2}};
			const vector output              = {true, false};
			ASSERT_EQ(output, Solution::friendRequests(3, restrictions, requests));
		}
	}// namespace process_restricted_friend_requests

	namespace prime_number_of_set_bits_in_binary_representation {
		TEST(prime_number_of_set_bits_in_binary_representation, case1) {
			ASSERT_EQ(4, Solution::countPrimeSetBits(6, 10));
		}

		TEST(prime_number_of_set_bits_in_binary_representation, case2) {
			ASSERT_EQ(5, Solution::countPrimeSetBits(10, 15));
		}
	}// namespace prime_number_of_set_bits_in_binary_representation

	namespace minimum_height_trees {
		TEST(minimum_height_trees, case1) {
			vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
			const vector output       = {1};
			auto sol                  = Solution();
			ASSERT_EQ(output, sol.findMinHeightTrees(4, edges));
		}

		TEST(minimum_height_trees, case2) {
			vector<vector<int>> edges = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
			const vector output       = {3, 4};
			auto sol                  = Solution();
			ASSERT_EQ(output, sol.findMinHeightTrees(6, edges));
		}
	}// namespace minimum_height_trees

	namespace rotate_string {
		TEST(rotate_string, case1) {
			ASSERT_TRUE(Solution::rotateString("abcde", "cdeab"));
		}

		TEST(rotate_string, case2) {
			ASSERT_FALSE(Solution::rotateString("abcde", "abced"));
		}
	}// namespace rotate_string

	namespace reaching_points {
		TEST(reaching_points, case1) {
			ASSERT_TRUE(Solution::reachingPoints(1, 1, 3, 5));
		}

		TEST(reaching_points, case2) {
			ASSERT_FALSE(Solution::reachingPoints(1, 1, 2, 2));
		}

		TEST(reaching_points, case3) {
			ASSERT_TRUE(Solution::reachingPoints(1, 1, 1, 1));
		}
	}// namespace reaching_points

	namespace maximum_product_after_k_increments {
		TEST(maximum_product_after_k_increments, case1) {
			vector nums = {0, 4};
			ASSERT_EQ(20, Solution::maximumProduct(nums, 5));
		}

		TEST(maximum_product_after_k_increments, case2) {
			vector nums = {6, 3, 3, 2};
			ASSERT_EQ(216, Solution::maximumProduct(nums, 2));
		}
	}// namespace maximum_product_after_k_increments

	namespace maximum_total_beauty_of_the_gardens {
		TEST(maximum_total_beauty_of_the_gardens, case1) {
			vector flowers = {1, 3, 1, 1};
			ASSERT_EQ(14, Solution::maximumBeauty(flowers, 7, 6, 12, 1));
		}

		TEST(maximum_total_beauty_of_the_gardens, case2) {
			vector flowers = {2, 4, 5, 3};
			ASSERT_EQ(30, Solution::maximumBeauty(flowers, 10, 5, 2, 6));
		}

		TEST(maximum_total_beauty_of_the_gardens, case3) {
			vector flowers = {19, 17, 6, 9, 19};
			ASSERT_EQ(104, Solution::maximumBeauty(flowers, 24, 10, 17, 4));
		}
	}// namespace maximum_total_beauty_of_the_gardens

	namespace count_numbers_with_unique_digits {
		TEST(count_numbers_with_unique_digits, case1) {
			ASSERT_EQ(91, Solution::countNumbersWithUniqueDigits(2));
		}

		TEST(count_numbers_with_unique_digits, case2) {
			ASSERT_EQ(1, Solution::countNumbersWithUniqueDigits(0));
		}
	}// namespace count_numbers_with_unique_digits

	namespace number_of_lines_to_write_string {
		TEST(number_of_lines_to_write_string, case1) {
			vector width        = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
			const vector output = {3, 60};
			ASSERT_EQ(output, Solution::numberOfLines(width, "abcdefghijklmnopqrstuvwxyz"));
		}

		TEST(number_of_lines_to_write_string, case2) {
			vector width        = {4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
			const vector output = {2, 4};
			ASSERT_EQ(output, Solution::numberOfLines(width, "bbbcccdddaaa"));
		}
	}// namespace number_of_lines_to_write_string

	namespace permutation_in_string {
		TEST(permutation_in_string, case1) {
			ASSERT_TRUE(Solution::checkInclusion("ab", "eidbaooo"));
		}

		TEST(permutation_in_string, case2) {
			ASSERT_FALSE(Solution::checkInclusion("ab", "eidboaoo"));
		}

		TEST(permutation_in_string, case3) {
			ASSERT_FALSE(Solution::checkInclusion("dinitrophenylhydrazine", "dimethylhydrazine"));
		}
	}// namespace permutation_in_string

	namespace projection_area_of_3d_shapes {
		TEST(projection_area_of_3d_shapes, case1) {
			vector<vector<int>> grid = {{1, 2}, {3, 4}};
			ASSERT_EQ(17, Solution::projectionArea(grid));
		}

		TEST(projection_area_of_3d_shapes, case2) {
			vector<vector<int>> grid = {{2}};
			ASSERT_EQ(5, Solution::projectionArea(grid));
		}

		TEST(projection_area_of_3d_shapes, case3) {
			vector<vector<int>> grid = {{1, 0}, {0, 2}};
			ASSERT_EQ(8, Solution::projectionArea(grid));
		}
	}// namespace projection_area_of_3d_shapes

	namespace house_robber {
		TEST(house_robber, case1) {
			vector nums = {1, 2, 3, 1};
			ASSERT_EQ(4, Solution::rob(nums));
		}

		TEST(house_robber, case2) {
			vector nums = {2, 7, 9, 3, 1};
			ASSERT_EQ(12, Solution::rob(nums));
		}
	}// namespace house_robber

	namespace triangle {
		TEST(triangle, case1) {
			vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
			ASSERT_EQ(11, Solution::minimumTotal(triangle));
		}

		TEST(triangle, case2) {
			vector<vector<int>> triangle = {{-10}};
			ASSERT_EQ(-10, Solution::minimumTotal(triangle));
		}
	}// namespace triangle

	namespace lowest_common_ancestor_of_a_binary_search_tree {
		TEST(lowest_common_ancestor_of_a_binary_search_tree, case1) {
			auto *root               = new TreeNode(6);
			root->left               = new TreeNode(2);
			root->right              = new TreeNode(8);
			root->left->left         = new TreeNode(0);
			root->left->right        = new TreeNode(4);
			root->left->right->left  = new TreeNode(3);
			root->left->right->right = new TreeNode(5);
			root->right->left        = new TreeNode(7);
			root->right->right       = new TreeNode(9);
			Solution s;
			ASSERT_EQ(6, s.lowestCommonAncestor(root, root->left, root->right)->val);
		}
	}// namespace lowest_common_ancestor_of_a_binary_search_tree

	namespace find_all_anagrams_in_a_string {
		TEST(find_all_anagrams_in_a_string, case1) {
			const string s        = "cbaebabacd";
			const string p        = "abc";
			const vector expected = {0, 6};
			ASSERT_EQ(expected, Solution::findAnagrams(s, p));
		}

		TEST(find_all_anagrams_in_a_string, case2) {
			const string s        = "abab";
			const string p        = "ab";
			const vector expected = {0, 1, 2};
			ASSERT_EQ(expected, Solution::findAnagrams(s, p));
		}
	}// namespace find_all_anagrams_in_a_string

	namespace subarray_product_less_than_k {
		TEST(subarray_product_less_than_k, case1) {
			vector nums = {10, 5, 2, 6};
			const int k = 100;
			ASSERT_EQ(8, Solution::numSubarrayProductLessThanK(nums, k));
		}

		TEST(subarray_product_less_than_k, case2) {
			vector nums = {1, 2, 3};
			const int k = 0;
			ASSERT_EQ(0, Solution::numSubarrayProductLessThanK(nums, k));
		}
	}// namespace subarray_product_less_than_k

	namespace minimum_size_subarray_sum {
		TEST(minimum_size_subarray_sum, case1) {
			vector nums      = {2, 3, 1, 2, 4, 3};
			const int target = 7;
			ASSERT_EQ(2, Solution::minSubArrayLen(target, nums));
		}

		TEST(minimum_size_subarray_sum, case2) {
			vector nums      = {1, 4, 4};
			const int target = 4;
			ASSERT_EQ(1, Solution::minSubArrayLen(target, nums));
		}

		TEST(minimum_size_subarray_sum, case3) {
			vector nums      = {1, 1, 1, 1, 1, 1, 1, 1};
			const int target = 11;
			ASSERT_EQ(0, Solution::minSubArrayLen(target, nums));
		}

		TEST(minimum_size_subarray_sum, case4) {
			vector nums      = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
			const int target = 15;
			ASSERT_EQ(2, Solution::minSubArrayLen(target, nums));
		}

		TEST(minimum_size_subarray_sum, case5) {
			vector nums      = {10, 5, 13, 4, 8, 4, 5, 11, 14, 9, 16, 10, 20, 8};
			const int target = 80;
			ASSERT_EQ(6, Solution::minSubArrayLen(target, nums));
		}
	}// namespace minimum_size_subarray_sum

	namespace house_robber_ii {
		TEST(house_robber_ii, case1) {
			vector nums = {2, 3, 2};
			ASSERT_EQ(3, Solution::rob(nums));
		}

		TEST(house_robber_ii, case2) {
			vector nums = {1, 2, 3, 1};
			ASSERT_EQ(4, Solution::rob(nums));
		}

		TEST(house_robber_ii, case3) {
			vector nums = {1, 2, 3};
			ASSERT_EQ(3, Solution::rob(nums));
		}
	}// namespace house_robber_ii

	namespace jump_game {
		TEST(jump_game, case1) {
			vector nums = {2, 3, 1, 1, 4};
			ASSERT_TRUE(Solution::canJump(nums));
		}

		TEST(jump_game, case2) {
			vector nums = {3, 2, 1, 0, 4};
			ASSERT_FALSE(Solution::canJump(nums));
		}
	}// namespace jump_game

	namespace jump_game_ii {
		TEST(jump_game_ii, case1) {
			vector nums = {2, 3, 1, 1, 4};
			ASSERT_EQ(2, Solution::jump(nums));
		}

		TEST(jump_game_ii, case2) {
			vector nums = {2, 3, 0, 1, 4};
			ASSERT_EQ(2, Solution::jump(nums));
		}
	}// namespace jump_game_ii

	namespace unique_paths {
		TEST(unique_paths, case1) {
			ASSERT_EQ(28, Solution::uniquePaths(3, 7));
		}

		TEST(unique_paths, case2) {
			ASSERT_EQ(3, Solution::uniquePaths(3, 2));
		}
	}// namespace unique_paths

	namespace longest_palindromic_substring {
		TEST(longest_palindromic_substring, case1) {
			ASSERT_EQ("bab", Solution::longestPalindrome("babad"));
		}

		TEST(longest_palindromic_substring, case2) {
			ASSERT_EQ("bb", Solution::longestPalindrome("cbbd"));
		}

		TEST(longest_palindromic_substring, case3) {
			ASSERT_EQ("aaabbaaa", Solution::longestPalindrome("aaabbaaaa"));
		}

		TEST(longest_palindromic_substring, case4) {
			ASSERT_EQ("ccc", Solution::longestPalindrome("ccc"));
		}

		TEST(longest_palindromic_substring, case5) {
			ASSERT_EQ("bbbb", Solution::longestPalindrome("bbbb"));
		}

		TEST(longest_palindromic_substring, case6) {
			ASSERT_EQ("anana", Solution::longestPalindrome("bananas"));
		}
	}// namespace longest_palindromic_substring

	namespace arithmetic_slices {
		TEST(arithmetic_slices, case1) {
			vector nums = {1, 2, 3, 4};
			ASSERT_EQ(3, Solution::numberOfArithmeticSlices(nums));
		}

		TEST(arithmetic_slices, case2) {
			vector nums = {1};
			ASSERT_EQ(0, Solution::numberOfArithmeticSlices(nums));
		}
	}// namespace arithmetic_slices

	namespace decode_ways {
		TEST(decode_ways, case1) {
			ASSERT_EQ(2, Solution::numDecodings("12"));
		}

		TEST(decode_ways, case2) {
			ASSERT_EQ(3, Solution::numDecodings("226"));
		}

		TEST(decode_ways, case3) {
			ASSERT_EQ(0, Solution::numDecodings("06"));
		}

		TEST(decode_ways, case4) {
			ASSERT_EQ(1, Solution::numDecodings("27"));
		}
	}// namespace decode_ways

	namespace word_break {
		TEST(word_break, case1) {
			vector<string> wordDict = {"leet", "code"};
			const string s          = "leetcode";
			ASSERT_TRUE(Solution::wordBreak(s, wordDict));
		}

		TEST(word_break, case2) {
			vector<string> wordDict = {"apple", "pen"};
			const string s          = "applepenapple";
			ASSERT_TRUE(Solution::wordBreak(s, wordDict));
		}

		TEST(word_break, case3) {
			vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
			const string s          = "catsandog";
			ASSERT_FALSE(Solution::wordBreak(s, wordDict));
		}
	}// namespace word_break

	namespace longest_increasing_subsequence {
		TEST(longest_increasing_subsequence, case1) {
			vector nums = {10, 9, 2, 5, 3, 7, 101, 18};
			ASSERT_EQ(4, Solution::lengthOfLIS(nums));
		}

		TEST(longest_increasing_subsequence, case2) {
			vector nums = {0, 1, 0, 3, 2, 3};
			ASSERT_EQ(4, Solution::lengthOfLIS(nums));
		}

		TEST(longest_increasing_subsequence, case3) {
			vector nums = {7, 7, 7, 7, 7, 7, 7};
			ASSERT_EQ(1, Solution::lengthOfLIS(nums));
		}
	}// namespace longest_increasing_subsequence

	namespace number_of_longest_increasing_subsequence {
		TEST(number_of_longest_increasing_subsequence, case1) {
			vector nums = {1, 3, 5, 4, 7};
			ASSERT_EQ(2, Solution::findNumberOfLIS(nums));
		}

		TEST(number_of_longest_increasing_subsequence, case2) {
			vector nums = {2, 2, 2, 2, 2};
			ASSERT_EQ(5, Solution::findNumberOfLIS(nums));
		}
	}// namespace number_of_longest_increasing_subsequence

	namespace longest_common_subsequence {
		TEST(longest_common_subsequence, case1) {
			const string text1 = "abcde";
			const string text2 = "ace";
			ASSERT_EQ(3, Solution::longestCommonSubsequence(text1, text2));
		}

		TEST(longest_common_subsequence, case2) {
			const string text1 = "abc";
			const string text2 = "abc";
			ASSERT_EQ(3, Solution::longestCommonSubsequence(text1, text2));
		}

		TEST(longest_common_subsequence, case3) {
			const string text1 = "abc";
			const string text2 = "def";
			ASSERT_EQ(0, Solution::longestCommonSubsequence(text1, text2));
		}

		TEST(longest_common_subsequence, case4) {
			const string text1 = "abcde";
			const string text2 = "akccle";
			ASSERT_EQ(3, Solution::longestCommonSubsequence(text1, text2));
		}
	}// namespace longest_common_subsequence

	namespace delete_operation_for_two_strings {
		TEST(delete_operation_for_two_strings, case1) {
			const string s1 = "sea";
			const string s2 = "eat";
			ASSERT_EQ(2, Solution::minDistance(s1, s2));
		}

		TEST(delete_operation_for_two_strings, case2) {
			const string s1 = "leetcode";
			const string s2 = "etco";
			ASSERT_EQ(4, Solution::minDistance(s1, s2));
		}
	}// namespace delete_operation_for_two_strings

	namespace edit_distance {
		TEST(edit_distance, case1) {
			const string word1 = "horse";
			const string word2 = "ros";
			ASSERT_EQ(3, Solution::minDistance(word1, word2));
		}

		TEST(edit_distance, case2) {
			const string word1 = "intention";
			const string word2 = "execution";
			ASSERT_EQ(5, Solution::minDistance(word1, word2));
		}
	}// namespace edit_distance

	namespace coin_change {
		TEST(coin_change, case1) {
			vector coins     = {1, 2, 5};
			const int amount = 11;
			ASSERT_EQ(3, Solution::coinChange(coins, amount));
		}

		TEST(coin_change, case2) {
			vector coins     = {2};
			const int amount = 3;
			ASSERT_EQ(-1, Solution::coinChange(coins, amount));
		}

		TEST(coin_change, case3) {
			vector coins     = {1};
			const int amount = 0;
			ASSERT_EQ(0, Solution::coinChange(coins, amount));
		}

		TEST(coin_change, case4) {
			vector coins     = {186, 419, 83, 408};
			const int amount = 6249;
			ASSERT_EQ(20, Solution::coinChange(coins, amount));
		}

		TEST(coin_change, case5) {
			vector coins     = {2};
			const int amount = 3;
			ASSERT_EQ(-1, Solution::coinChange(coins, amount));
		}
	}// namespace coin_change

	namespace integer_break {
		TEST(integer_break, case1) {
			const int n = 2;
			ASSERT_EQ(1, Solution::integerBreak(n));
		}

		TEST(integer_break, case2) {
			const int n = 10;
			ASSERT_EQ(36, Solution::integerBreak(n));
		}
	}// namespace integer_break

	namespace max_points_on_a_line {
		TEST(max_points_on_a_line, case1) {
			vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
			ASSERT_EQ(3, Solution::maxPoints(points));
		}

		TEST(max_points_on_a_line, case2) {
			vector<vector<int>> points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
			ASSERT_EQ(4, Solution::maxPoints(points));
		}
	}// namespace max_points_on_a_line

	namespace sort_colors {
		TEST(sort_colors, case1) {
			vector nums = {2, 0, 2, 1, 1, 0};
			Solution::sortColors(nums);
			const vector expected = {0, 0, 1, 1, 2, 2};
			ASSERT_EQ(expected, nums);
		}

		TEST(sort_colors, case2) {
			vector nums = {2, 0, 1};
			Solution::sortColors(nums);
			const vector expected = {0, 1, 2};
			ASSERT_EQ(expected, nums);
		}
	}// namespace sort_colors

	namespace kth_largest_element_in_an_array {
		TEST(kth_largest_element_in_an_array, case1) {
			vector nums = {3, 2, 1, 5, 6, 4};
			ASSERT_EQ(5, Solution::findKthLargest(nums, 2));
		}

		TEST(kth_largest_element_in_an_array, case2) {
			vector nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
			ASSERT_EQ(4, Solution::findKthLargest(nums, 4));
		}
	}// namespace kth_largest_element_in_an_array

	namespace merge_intervals {
		TEST(merge_intervals, case1) {
			vector<vector<int>> intervals      = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
			const vector<vector<int>> expected = {{1, 6}, {8, 10}, {15, 18}};
			ASSERT_EQ(expected, Solution::merge(intervals));
		}

		TEST(merge_intervals, case2) {
			vector<vector<int>> intervals      = {{1, 4}, {4, 5}};
			const vector<vector<int>> expected = {{1, 5}};
			ASSERT_EQ(expected, Solution::merge(intervals));
		}

	}// namespace merge_intervals

	namespace search_a_2d_matrix_ii {
		TEST(search_a_2d_matrix_ii, case1) {
			vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
			ASSERT_TRUE(Solution::searchMatrix(matrix, 5));
		}

		TEST(search_a_2d_matrix_ii, case3) {
			vector<vector<int>> matrix = {{1, 1}};
			ASSERT_FALSE(Solution::searchMatrix(matrix, 0));
		}
	}// namespace search_a_2d_matrix_ii

	namespace serialize_and_deserialize_binary_tree {
		TEST(serialize_and_deserialize_binary_tree, case1) {
			const auto c            = Codec();
			const string serialized = "[1,2,3,null,null,4,5]";
			TreeNode *root          = Codec::deserialize(serialized);
			ASSERT_EQ(serialized, c.serialize(root));
		}

		TEST(serialize_and_deserialize_binary_tree, case2) {
			const auto c            = Codec();
			const string serialized = "[]";
			TreeNode *root          = Codec::deserialize(serialized);
			ASSERT_EQ(serialized, c.serialize(root));
		}

		TEST(serialize_and_deserialize_binary_tree, case3) {
			const auto c            = Codec();
			const string serialized = "[1,null,2,3]";
			TreeNode *root          = Codec::deserialize(serialized);
			ASSERT_EQ(serialized, c.serialize(root));
		}

		TEST(serialize_and_deserialize_binary_tree, case4) {
			const auto c            = Codec();
			const string serialized = "[1,2,3]";
			TreeNode *root          = Codec::deserialize(serialized);
			ASSERT_EQ(serialized, c.serialize(root));
		}

		TEST(serialize_and_deserialize_binary_tree, case5) {
			const auto c            = Codec();
			const string serialized = "[5,4,7,3,null,2,null,-1,null,9]";
			TreeNode *root          = Codec::deserialize(serialized);
			ASSERT_EQ(serialized, c.serialize(root));
		}
	}// namespace serialize_and_deserialize_binary_tree

	namespace task_scheduler {
		TEST(task_scheduler, case1) {
			vector tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
			ASSERT_EQ(8, Solution::leastInterval(tasks, 2));
		}

		TEST(task_scheduler, case2) {
			vector tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
			ASSERT_EQ(6, Solution::leastInterval(tasks, 0));
		}

		TEST(task_scheduler, case3) {
			vector tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
			ASSERT_EQ(16, Solution::leastInterval(tasks, 2));
		}

		TEST(task_scheduler, case4) {
			vector tasks = {'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
			ASSERT_EQ(31, Solution::leastInterval(tasks, 29));
		}

		TEST(task_scheduler, case5) {
			vector tasks = {'A', 'B', 'C', 'A'};
			ASSERT_EQ(8, Solution::leastInterval(tasks, 6));
		}
	}// namespace task_scheduler

	namespace spiral_matrix_ii {
		TEST(spiral_matrix_ii, case1) {
			const vector<vector<int>> ans = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
			ASSERT_EQ(ans, Solution::generateMatrix(3));
		}

		TEST(spiral_matrix_ii, case2) {
			const vector<vector<int>> ans = {{1}};
			ASSERT_EQ(ans, Solution::generateMatrix(1));
		}
	}// namespace spiral_matrix_ii

	namespace non_overlapping_intervals {
		TEST(non_overlapping_intervals, case1) {
			vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
			ASSERT_EQ(1, Solution::eraseOverlapIntervals(intervals));
		}

		TEST(non_overlapping_intervals, case2) {
			vector<vector<int>> intervals = {{1, 2}, {1, 2}, {1, 2}};
			ASSERT_EQ(2, Solution::eraseOverlapIntervals(intervals));
		}

		TEST(non_overlapping_intervals, case3) {
			vector<vector<int>> intervals = {{1, 2}, {2, 3}};
			ASSERT_EQ(0, Solution::eraseOverlapIntervals(intervals));
		}

		TEST(non_overlapping_intervals, case4) {
			vector<vector<int>> intervals = {{-52, 31}, {-73, -26}, {82, 97}, {-65, -11}, {-62, -49}, {95, 99}, {58, 95}, {-31, 49}, {66, 98}, {-63, 2}, {30, 47}, {-40, -26}};
			ASSERT_EQ(7, Solution::eraseOverlapIntervals(intervals));
		}

		TEST(non_overlapping_intervals, case5) {
			vector<vector<int>> intervals = {{-25322, -4602}, {-35630, -28832}, {-33802, 29009}, {13393, 24550}, {-10655, 16361}, {-2835, 10053}, {-2290, 17156}, {1236, 14847}, {-45022, -1296}, {-34574, -1993}, {-14129, 15626}, {3010, 14502}, {42403, 45946}, {-22117, 13380}, {7337, 33635}, {-38153, 27794}, {47640, 49108}, {40578, 46264}, {-38497, -13790}, {-7530, 4977}, {-29009, 43543}, {-49069, 32526}, {21409, 43622}, {-28569, 16493}, {-28301, 34058}};
			ASSERT_EQ(19, Solution::eraseOverlapIntervals(intervals));
		}
	}// namespace non_overlapping_intervals

	namespace product_of_array_except_self {
		TEST(product_of_array_except_self, case1) {
			vector nums         = {1, 2, 3, 4};
			const vector output = {24, 12, 8, 6};
			ASSERT_EQ(output, Solution::productExceptSelf(nums));
		}

		TEST(product_of_array_except_self, case2) {
			vector nums         = {-1, 1, 0, -3, 3};
			const vector output = {0, 0, 9, 0, 0};
			ASSERT_EQ(output, Solution::productExceptSelf(nums));
		}
	}// namespace product_of_array_except_self

	namespace subarray_sum_equals_k {
		TEST(subarray_sum_equals_k, case1) {
			vector nums = {1, 1, 1};
			ASSERT_EQ(2, Solution::subarraySum(nums, 2));
		}

		TEST(subarray_sum_equals_k, case2) {
			vector nums = {1, 2, 3};
			ASSERT_EQ(2, Solution::subarraySum(nums, 3));
		}

		TEST(subarray_sum_equals_k, case3) {
			vector nums = {1};
			ASSERT_EQ(0, Solution::subarraySum(nums, 0));
		}

		TEST(subarray_sum_equals_k, case4) {
			vector nums = {-1, -1, 1};
			ASSERT_EQ(1, Solution::subarraySum(nums, 0));
		}

		TEST(subarray_sum_equals_k, case5) {
			vector nums = {-1, -1, 1};
			ASSERT_EQ(1, Solution::subarraySum(nums, 1));
		}
	}// namespace subarray_sum_equals_k

	namespace partition_labels {
		TEST(partition_labels, case1) {
			const vector output = {9, 7, 8};
			ASSERT_EQ(output, Solution::partitionLabels("ababcbacadefegdehijhklij"));
		}

		TEST(partition_labels, case2) {
			const vector output = {10};
			ASSERT_EQ(output, Solution::partitionLabels("eccbbbbdec"));
		}
	}// namespace partition_labels

	namespace design_linked_list {
		TEST(design_linked_list, case1) {
			MyLinkedList mll;
			mll.addAtHead(1);
			mll.addAtTail(3);
			mll.addAtIndex(1, 2);
			ASSERT_EQ(2, mll.get(1));
			mll.deleteAtIndex(1);
			ASSERT_EQ(3, mll.get(1));
		}
	}// namespace design_linked_list

	namespace delete_node_in_a_bst {
		bool equal(TreeNode *tn1, TreeNode *tn2) {
			if(tn1 == nullptr != (tn2 == nullptr)) {
				return false;
			}
			if(tn1 != nullptr && tn2 != nullptr) {
				if(tn1->val != tn2->val) {
					return false;
				}
				if(!equal(tn1->left, tn2->left)) {
					return false;
				}
				if(!equal(tn1->right, tn2->right)) {
					return false;
				}
			}
			return true;
		}

		TEST(delete_node_in_a_bst, case1) {
			const auto c     = serialize_and_deserialize_binary_tree::Codec();
			TreeNode *root   = serialize_and_deserialize_binary_tree::Codec::deserialize("[5,3,6,2,4,null,7]");
			TreeNode *output = serialize_and_deserialize_binary_tree::Codec::deserialize("[5,4,6,2,null,null,7]");
			auto sol         = Solution();
			ASSERT_TRUE(equal(output, sol.deleteNode(root, 3)));
		}

		TEST(delete_node_in_a_bst, case2) {
			const auto c     = serialize_and_deserialize_binary_tree::Codec();
			TreeNode *root   = serialize_and_deserialize_binary_tree::Codec::deserialize("[5,3,6,2,4,null,7]");
			TreeNode *output = serialize_and_deserialize_binary_tree::Codec::deserialize("[5,3,6,2,4,null,7]");
			auto sol         = Solution();
			ASSERT_TRUE(equal(output, sol.deleteNode(root, 0)));
		}

		TEST(delete_node_in_a_bst, case3) {
			const auto c     = serialize_and_deserialize_binary_tree::Codec();
			TreeNode *root   = serialize_and_deserialize_binary_tree::Codec::deserialize("[]");
			TreeNode *output = serialize_and_deserialize_binary_tree::Codec::deserialize("[]");
			auto sol         = Solution();
			ASSERT_TRUE(equal(output, sol.deleteNode(root, 0)));
		}

		TEST(delete_node_in_a_bst, case4) {
			const auto c     = serialize_and_deserialize_binary_tree::Codec();
			TreeNode *root   = serialize_and_deserialize_binary_tree::Codec::deserialize("[3,2,5,null,null,4,10,null,null,8,15,7]");
			TreeNode *output = serialize_and_deserialize_binary_tree::Codec::deserialize("[3,2,7,null,null,4,10,null,null,8,15]");
			auto sol         = Solution();
			ASSERT_TRUE(equal(output, sol.deleteNode(root, 5)));
		}
	}// namespace delete_node_in_a_bst

	namespace missing_element_in_sorted_array {
		TEST(missing_element_in_sorted_array, case1) {
			vector nums = {4, 7, 9, 10};
			ASSERT_EQ(Solution::missingElement(nums, 1), 5);
		}

		TEST(missing_element_in_sorted_array, case2) {
			vector nums = {4, 7, 9, 10};
			ASSERT_EQ(Solution::missingElement(nums, 3), 8);
		}

		TEST(missing_element_in_sorted_array, case3) {
			vector nums = {1, 2, 4};
			ASSERT_EQ(Solution::missingElement(nums, 3), 6);
		}
	}// namespace missing_element_in_sorted_array

	namespace find_a_peak_element_ii {
		TEST(find_a_peak_element_ii, case1) {
			vector<vector<int>> mat = {{1, 4}, {3, 2}};
			const vector ans        = {0, 1};
			ASSERT_EQ(Solution::findPeakGrid(mat), ans);
		}

		TEST(find_a_peak_element_ii, case2) {
			vector<vector<int>> mat = {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}};
			const vector ans        = {2, 2};
			ASSERT_EQ(Solution::findPeakGrid(mat), ans);
		}
	}// namespace find_a_peak_element_ii

	namespace divide_chocolate {
		TEST(divide_chocolate, case1) {
			vector sweetness = {1, 2, 3, 4, 5, 6, 7, 8, 9};
			ASSERT_EQ(6, Solution::maximizeSweetness(sweetness, 5));
		}

		TEST(divide_chocolate, case2) {
			vector sweetness = {5, 6, 7, 8, 9, 1, 2, 3, 4};
			ASSERT_EQ(1, Solution::maximizeSweetness(sweetness, 8));
		}

		TEST(divide_chocolate, case3) {
			vector sweetness = {1, 2, 2, 1, 2, 2, 1, 2, 2};
			ASSERT_EQ(5, Solution::maximizeSweetness(sweetness, 2));
		}
	}// namespace divide_chocolate

	namespace shortest_distance_to_target_color {
		TEST(shortest_distance_to_target_color, case1) {
			vector colors               = {1, 1, 2, 1, 3, 2, 2, 3, 3};
			vector<vector<int>> queries = {{1, 3}, {2, 2}, {6, 1}};
			const vector ans            = {3, 0, 3};
			ASSERT_EQ(ans, Solution::shortestDistanceColor(colors, queries));
		}

		TEST(shortest_distance_to_target_color, case2) {
			vector colors               = {1, 2};
			vector<vector<int>> queries = {{0, 3}};
			const vector ans            = {-1};
			ASSERT_EQ(ans, Solution::shortestDistanceColor(colors, queries));
		}
	}// namespace shortest_distance_to_target_color

	namespace meeting_scheduler {
		TEST(meeting_scheduler, case1) {
			vector<vector<int>> slots1 = {{10, 50}, {60, 120}, {140, 210}};
			vector<vector<int>> slots2 = {{0, 15}, {60, 70}};
			const vector ans           = {60, 68};
			ASSERT_EQ(ans, Solution::minAvailableDuration(slots1, slots2, 8));
		}

		TEST(meeting_scheduler, case2) {
			vector<vector<int>> slots1 = {{10, 50}, {60, 120}, {140, 210}};
			vector<vector<int>> slots2 = {{0, 15}, {60, 70}};
			const vector<int> ans      = {};
			ASSERT_EQ(ans, Solution::minAvailableDuration(slots1, slots2, 12));
		}

		TEST(meeting_scheduler, case3) {
			vector<vector<int>> slots1 = {{10, 60}};
			vector<vector<int>> slots2 = {{12, 17}, {21, 50}};
			const vector ans           = {21, 29};
			ASSERT_EQ(ans, Solution::minAvailableDuration(slots1, slots2, 8));
		}
	}// namespace meeting_scheduler

	namespace find_the_duplicate_number {
		TEST(find_the_duplicate_number, case1) {
			vector nums = {1, 3, 4, 2, 2};
			ASSERT_EQ(2, Solution::findDuplicate(nums));
		}

		TEST(find_the_duplicate_number, case2) {
			vector nums = {3, 1, 3, 4, 2};
			ASSERT_EQ(3, Solution::findDuplicate(nums));
		}

		TEST(find_the_duplicate_number, case3) {
			vector nums = {1, 4, 4, 2, 4};
			ASSERT_EQ(4, Solution::findDuplicate(nums));
		}
	}// namespace find_the_duplicate_number

	namespace trapping_rain_water {
		TEST(trapping_rain_water, case1) {
			vector height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
			ASSERT_EQ(6, Solution::trap(height));
		}

		TEST(trapping_rain_water, case2) {
			vector height = {4, 2, 0, 3, 2, 5};
			ASSERT_EQ(9, Solution::trap(height));
		}
	}// namespace trapping_rain_water

	namespace product_of_two_run_length_encoded_arrays {
		TEST(product_of_two_run_length_encoded_arrays, case1) {
			vector<vector<int>> encoded1     = {{1, 3}, {2, 3}};
			vector<vector<int>> encoded2     = {{6, 3}, {3, 3}};
			const vector<vector<int>> output = {{6, 6}};
			ASSERT_EQ(output, Solution::findRLEArray(encoded1, encoded2));
		}

		TEST(product_of_two_run_length_encoded_arrays, case2) {
			vector<vector<int>> encoded1     = {{1, 3}, {2, 1}, {3, 2}};
			vector<vector<int>> encoded2     = {{2, 3}, {3, 3}};
			const vector<vector<int>> output = {{2, 3}, {6, 1}, {9, 2}};
			ASSERT_EQ(output, Solution::findRLEArray(encoded1, encoded2));
		}
	}// namespace product_of_two_run_length_encoded_arrays

	namespace longest_substring_with_at_most_two_distinct_characters {
		TEST(longest_substring_with_at_most_two_distinct_characters, case1) {
			ASSERT_EQ(3, Solution::lengthOfLongestSubstringTwoDistinct("eceba"));
		}

		TEST(longest_substring_with_at_most_two_distinct_characters, case2) {
			ASSERT_EQ(5, Solution::lengthOfLongestSubstringTwoDistinct("ccaabbb"));
		}
	}// namespace longest_substring_with_at_most_two_distinct_characters

	namespace longest_substring_with_at_most_k_distinct_characters {
		TEST(longest_substring_with_at_most_k_distinct_characters, case1) {
			ASSERT_EQ(3, Solution::lengthOfLongestSubstringKDistinct("eceba", 2));
		}

		TEST(longest_substring_with_at_most_k_distinct_characters, case2) {
			ASSERT_EQ(2, Solution::lengthOfLongestSubstringKDistinct("aa", 1));
		}
	}// namespace longest_substring_with_at_most_k_distinct_characters

	namespace max_consecutive_ones_iii {
		TEST(max_consecutive_ones_iii, case1) {
			vector nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
			ASSERT_EQ(6, Solution::longestOnes(nums, 2));
		}

		TEST(max_consecutive_ones_iii, case2) {
			vector nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
			ASSERT_EQ(10, Solution::longestOnes(nums, 3));
		}
	}// namespace max_consecutive_ones_iii

	namespace sliding_window_maximum {
		TEST(sliding_window_maximum, case1) {
			vector nums      = {1, 3, -1, -3, 5, 3, 6, 7};
			const vector ans = {3, 3, 5, 5, 6, 7};
			ASSERT_EQ(ans, Solution::maxSlidingWindow(nums, 3));
		}

		TEST(sliding_window_maximum, case2) {
			vector nums      = {1};
			const vector ans = {1};
			ASSERT_EQ(ans, Solution::maxSlidingWindow(nums, 1));
		}
	}// namespace sliding_window_maximum

	namespace minimum_window_substring {
		TEST(minimum_window_substring, case1) {
			ASSERT_EQ("BANC", Solution::minWindow("ADOBECODEBANC", "ABC"));
		}

		TEST(minimum_window_substring, case2) {
			ASSERT_EQ("a", Solution::minWindow("a", "a"));
		}

		TEST(minimum_window_substring, case3) {
			ASSERT_EQ("", Solution::minWindow("a", "aa"));
		}
	}// namespace minimum_window_substring

	namespace walls_and_gates {
		TEST(walls_and_gates, case1) {
			vector<vector<int>> rooms     = {{2147483647, -1, 0, 2147483647}, {2147483647, 2147483647, 2147483647, -1}, {2147483647, -1, 2147483647, -1}, {0, -1, 2147483647, 2147483647}};
			const vector<vector<int>> ans = {{3, -1, 0, 1}, {2, 2, 1, -1}, {1, -1, 2, -1}, {0, -1, 3, 4}};
			Solution::wallsAndGates(rooms);
			ASSERT_EQ(ans, rooms);
		}

		TEST(walls_and_gates, case2) {
			vector<vector<int>> rooms     = {{2147483647}};
			const vector<vector<int>> ans = {{2147483647}};
			Solution::wallsAndGates(rooms);
			ASSERT_EQ(ans, rooms);
		}

		TEST(walls_and_gates, case3) {
			vector<vector<int>> rooms     = {{0}};
			const vector<vector<int>> ans = {{0}};
			Solution::wallsAndGates(rooms);
			ASSERT_EQ(ans, rooms);
		}
	}// namespace walls_and_gates

	namespace pacific_atlantic_waterflow {
		TEST(pacific_atlantic_waterflow, case1) {
			vector<vector<int>> heights   = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
			const vector<vector<int>> ans = {{0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}};
			ASSERT_EQ(ans, Solution::pacificAtlantic(heights));
		}

		TEST(pacific_atlantic_waterflow, case2) {
			vector<vector<int>> heights   = {{2, 1}, {1, 2}};
			const vector<vector<int>> ans = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
			ASSERT_EQ(ans, Solution::pacificAtlantic(heights));
		}
	}// namespace pacific_atlantic_waterflow

	namespace kill_process {
		TEST(kill_process, case1) {
			vector pid       = {1, 3, 10, 5};
			vector ppid      = {3, 0, 5, 3};
			const vector ans = {5, 10};
			ASSERT_EQ(ans, Solution::killProcess(pid, ppid, 5));
		}

		TEST(kill_process, case2) {
			vector pid       = {1};
			vector ppid      = {0};
			const vector ans = {1};
			ASSERT_EQ(ans, Solution::killProcess(pid, ppid, 1));
		}
	}// namespace kill_process

	namespace open_the_lock {
		TEST(open_the_lock, case1) {
			vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
			ASSERT_EQ(6, Solution::openLock(deadends, "0202"));
		}

		TEST(open_the_lock, case2) {
			vector<string> deadends = {"8888"};
			ASSERT_EQ(1, Solution::openLock(deadends, "0009"));
		}

		TEST(open_the_lock, case3) {
			vector<string> deadends = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
			ASSERT_EQ(-1, Solution::openLock(deadends, "8888"));
		}
	}// namespace open_the_lock

	namespace number_of_operations_to_make_network_connected {
		TEST(number_of_operations_to_make_network_connected, case1) {
			vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
			ASSERT_EQ(1, Solution::makeConnected(4, connections));
		}

		TEST(number_of_operations_to_make_network_connected, case2) {
			vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
			ASSERT_EQ(2, Solution::makeConnected(6, connections));
		}

		TEST(number_of_operations_to_make_network_connected, case3) {
			vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
			ASSERT_EQ(-1, Solution::makeConnected(6, connections));
		}

		TEST(number_of_operations_to_make_network_connected, case4) {
			vector<vector<int>> connections = {{0, 1}, {0, 2}, {3, 4}, {2, 3}};
			ASSERT_EQ(0, Solution::makeConnected(5, connections));
		}
	}// namespace number_of_operations_to_make_network_connected

	namespace minimum_cost_to_make_at_least_one_valid_path_in_a_grid {
		TEST(minimum_cost_to_make_at_least_one_valid_path_in_a_grid, case1) {
			vector<vector<int>> grid = {{1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}};
			ASSERT_EQ(3, Solution::minCost(grid));
		}

		TEST(minimum_cost_to_make_at_least_one_valid_path_in_a_grid, case2) {
			vector<vector<int>> grid = {{1, 1, 3}, {3, 2, 2}, {1, 1, 4}};
			ASSERT_EQ(0, Solution::minCost(grid));
		}

		TEST(minimum_cost_to_make_at_least_one_valid_path_in_a_grid, case3) {
			vector<vector<int>> grid = {{1, 2}, {4, 3}};
			ASSERT_EQ(1, Solution::minCost(grid));
		}

		TEST(minimum_cost_to_make_at_least_one_valid_path_in_a_grid, case4) {
			vector<vector<int>> grid = {{2, 2, 2}, {2, 2, 2}};
			ASSERT_EQ(3, Solution::minCost(grid));
		}

		TEST(minimum_cost_to_make_at_least_one_valid_path_in_a_grid, case5) {
			vector<vector<int>> grid = {{4}};
			ASSERT_EQ(0, Solution::minCost(grid));
		}
	}// namespace minimum_cost_to_make_at_least_one_valid_path_in_a_grid

	namespace critical_connections_in_a_network {
		TEST(critical_connections_in_a_network, case1) {
			vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
			const vector<vector<int>> ans   = {{1, 3}};
			ASSERT_EQ(ans, Solution::criticalConnections(4, connections));
		}

		TEST(critical_connections_in_a_network, case2) {
			vector<vector<int>> connections = {{0, 1}};
			const vector<vector<int>> ans   = {{0, 1}};
			ASSERT_EQ(ans, Solution::criticalConnections(2, connections));
		}

		TEST(critical_connections_in_a_network, case3) {
			vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}, {4, 5}, {5, 3}};
			const vector<vector<int>> ans   = {{1, 3}};
			ASSERT_EQ(ans, Solution::criticalConnections(6, connections));
		}
	}// namespace critical_connections_in_a_network

	namespace factor_combinations {
		TEST(factor_combinations, case1) {
			const vector<vector<int>> ans = {};
			ASSERT_EQ(ans, Solution::getFactors(1));
		}

		TEST(factor_combinations, case2) {
			const vector<vector<int>> ans = {};
			ASSERT_EQ(ans, Solution::getFactors(37));
		}

		TEST(factor_combinations, case3) {
			const vector<vector<int>> ans = {{2, 6}, {2, 2, 3}, {3, 4}};
			ASSERT_EQ(ans, Solution::getFactors(12));
		}

		TEST(factor_combinations, case4) {
			const vector<vector<int>> ans = {{2, 16}, {2, 2, 8}, {2, 2, 2, 4}, {2, 2, 2, 2, 2}, {2, 4, 4}, {4, 8}};
			ASSERT_EQ(ans, Solution::getFactors(32));
		}
	}// namespace factor_combinations

	namespace decode_string {
		TEST(decode_string, case1) {
			ASSERT_EQ("aaabcbc", Solution::decodeString("3[a]2[bc]"));
		}

		TEST(decode_string, case2) {
			ASSERT_EQ("accaccacc", Solution::decodeString("3[a2[c]]"));
		}

		TEST(decode_string, case3) {
			ASSERT_EQ("abcabccdcdcdef", Solution::decodeString("2[abc]3[cd]ef"));
		}

		TEST(decode_string, case4) {
			ASSERT_EQ("abccdcdcdxyz", Solution::decodeString("abc3[cd]xyz"));
		}
	}// namespace decode_string

	namespace n_queens {
		TEST(n_queens, case1) {
			const vector<vector<string>> ans = {{".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}};
			ASSERT_EQ(ans, Solution::solveNQueens(4));
		}

		TEST(n_queens, case2) {
			const vector<vector<string>> ans = {{"Q"}};
			ASSERT_EQ(ans, Solution::solveNQueens(1));
		}
	}// namespace n_queens

	namespace sudoku_solver {
		TEST(sudoku_solver, case1) {
			vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
			Solution sol;
			Solution::solveSudoku(board);
			const vector<vector<char>> ans = {{'5', '3', '4', '6', '7', '8', '9', '1', '2'}, {'6', '7', '2', '1', '9', '5', '3', '4', '8'}, {'1', '9', '8', '3', '4', '2', '5', '6', '7'}, {'8', '5', '9', '7', '6', '1', '4', '2', '3'}, {'4', '2', '6', '8', '5', '3', '7', '9', '1'}, {'7', '1', '3', '9', '2', '4', '8', '5', '6'}, {'9', '6', '1', '5', '3', '7', '2', '8', '4'}, {'2', '8', '7', '4', '1', '9', '6', '3', '5'}, {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
			ASSERT_EQ(ans, board);
		}
	}// namespace sudoku_solver

	namespace regular_expression_matching {
		TEST(regular_expression_matching, case1) {
			ASSERT_FALSE(Solution::isMatch("aa", "a"));
		}

		TEST(regular_expression_matching, case2) {
			ASSERT_TRUE(Solution::isMatch("aa", "a*"));
		}

		TEST(regular_expression_matching, case3) {
			ASSERT_TRUE(Solution::isMatch("ab", ".*"));
		}

		TEST(regular_expression_matching, case4) {
			ASSERT_TRUE(Solution::isMatch("a", "ab*"));
		}
	}// namespace regular_expression_matching

	namespace different_ways_to_add_parentheses {
		TEST(different_ways_to_add_parentheses, case1) {
			const vector ans = {0, 2};
			ASSERT_EQ(ans, Solution::diffWaysToCompute("2-1-1"));
		}

		TEST(different_ways_to_add_parentheses, case2) {
			const vector ans = {-34, -14, -10, -10, 10};
			ASSERT_EQ(ans, Solution::diffWaysToCompute("2*3-4*5"));
		}
	}// namespace different_ways_to_add_parentheses

	namespace remove_invalid_parentheses {
		TEST(remove_invalid_parentheses, case1) {
			const vector<string> ans = {"(())()", "()()()"};
			ASSERT_EQ(ans, Solution::removeInvalidParentheses("()())()"));
		}

		TEST(remove_invalid_parentheses, case2) {
			const vector<string> ans = {"(a())()", "(a)()()"};
			ASSERT_EQ(ans, Solution::removeInvalidParentheses("(a)())()"));
		}

		TEST(remove_invalid_parentheses, case3) {
			const vector<string> ans = {""};
			ASSERT_EQ(ans, Solution::removeInvalidParentheses(")("));
		}

		TEST(remove_invalid_parentheses, case4) {
			const vector<string> ans = {"x"};
			ASSERT_EQ(ans, Solution::removeInvalidParentheses("x("));
		}

		TEST(remove_invalid_parentheses, case5) {
			const vector<string> ans = {"aaaaa"};
			ASSERT_EQ(ans, Solution::removeInvalidParentheses("((((((((((((((((((((aaaaa"));
		}
	}// namespace remove_invalid_parentheses

	namespace median_of_two_sorted_arrays {
		TEST(median_of_two_sorted_arrays, case1) {
			vector nums1 = {1, 3};
			vector nums2 = {2};
			ASSERT_EQ(2, Solution::findMedianSortedArrays(nums1, nums2));
		}

		TEST(median_of_two_sorted_arrays, case2) {
			vector nums1 = {1, 2};
			vector nums2 = {3, 4};
			ASSERT_EQ(2.5, Solution::findMedianSortedArrays(nums1, nums2));
		}

		TEST(median_of_two_sorted_arrays, case3) {
			vector nums1 = {1, 3};
			vector nums2 = {2, 7};
			ASSERT_EQ(2.5, Solution::findMedianSortedArrays(nums1, nums2));
		}
	}// namespace median_of_two_sorted_arrays

	namespace count_of_smaller_numbers_after_self {
		TEST(count_of_smaller_numbers_after_self, case1) {
			vector nums      = {5, 2, 6, 1};
			const vector ans = {2, 1, 1, 0};
			Solution sol;
			ASSERT_EQ(ans, sol.countSmaller(nums));
		}

		TEST(count_of_smaller_numbers_after_self, case2) {
			vector nums      = {-1};
			const vector ans = {0};
			Solution sol;
			ASSERT_EQ(ans, sol.countSmaller(nums));
		}

		TEST(count_of_smaller_numbers_after_self, case3) {
			vector nums      = {-1, -1};
			const vector ans = {0, 0};
			Solution sol;
			ASSERT_EQ(ans, sol.countSmaller(nums));
		}
	}// namespace count_of_smaller_numbers_after_self

	namespace best_time_to_buy_and_sell_stock_with_cooldown {
		TEST(best_time_to_buy_and_sell_stock_with_cooldown, case1) {
			vector prices = {1, 2, 3, 0, 2};
			ASSERT_EQ(3, Solution::maxProfit(prices));
		}

		TEST(best_time_to_buy_and_sell_stock_with_cooldown, case2) {
			vector prices = {1};
			ASSERT_EQ(0, Solution::maxProfit(prices));
		}

		TEST(best_time_to_buy_and_sell_stock_with_cooldown, case3) {
			vector prices = {1, 2};
			ASSERT_EQ(1, Solution::maxProfit(prices));
		}
	}// namespace best_time_to_buy_and_sell_stock_with_cooldown

	namespace best_time_to_buy_and_sell_stock_with_transaction_fee {
		TEST(best_time_to_buy_and_sell_stock_with_transaction_fee, case1) {
			vector prices = {1, 3, 2, 8, 4, 9};
			ASSERT_EQ(8, Solution::maxProfit(prices, 2));
		}

		TEST(best_time_to_buy_and_sell_stock_with_transaction_fee, case2) {
			vector prices = {1, 3, 7, 5, 10, 3};
			ASSERT_EQ(6, Solution::maxProfit(prices, 3));
		}
	}// namespace best_time_to_buy_and_sell_stock_with_transaction_fee

	namespace split_array_largest_sum {
		TEST(split_array_largest_sum, case1) {
			vector nums = {7, 2, 5, 10, 8};
			ASSERT_EQ(18, Solution::splitArray(nums, 2));
		}

		TEST(split_array_largest_sum, case2) {
			vector nums = {1, 2, 3, 4, 5};
			ASSERT_EQ(9, Solution::splitArray(nums, 2));
		}

		TEST(split_array_largest_sum, case3) {
			vector nums = {1, 4, 4};
			ASSERT_EQ(4, Solution::splitArray(nums, 3));
		}
	}// namespace split_array_largest_sum

	namespace maximal_square {
		TEST(maximal_square, case1) {
			vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
			ASSERT_EQ(4, Solution::maximalSquare(matrix));
		}

		TEST(maximal_square, case2) {
			vector<vector<char>> matrix = {{'0', '1'}, {'1', '0'}};
			ASSERT_EQ(1, Solution::maximalSquare(matrix));
		}

		TEST(maximal_square, case3) {
			vector<vector<char>> matrix = {{'0'}};
			ASSERT_EQ(0, Solution::maximalSquare(matrix));
		}
	}// namespace maximal_square

	namespace maximal_rectangle {
		TEST(maximal_rectangle, case1) {
			vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
			ASSERT_EQ(6, Solution::maximalRectangle(matrix));
		}

		TEST(maximal_rectangle, case2) {
			vector<vector<char>> matrix = {};
			ASSERT_EQ(0, Solution::maximalRectangle(matrix));
		}

		TEST(maximal_rectangle, case3) {
			vector<vector<char>> matrix = {{'0'}};
			ASSERT_EQ(0, Solution::maximalRectangle(matrix));
		}

		TEST(maximal_rectangle, case4) {
			vector<vector<char>> matrix = {{'1'}};
			ASSERT_EQ(1, Solution::maximalRectangle(matrix));
		}

		TEST(maximal_rectangle, case5) {
			vector<vector<char>> matrix = {{'0', '0'}};
			ASSERT_EQ(0, Solution::maximalRectangle(matrix));
		}
	}// namespace maximal_rectangle

	namespace predict_the_winner {
		TEST(predict_the_winner, case1) {
			vector nums = {1, 5, 2};
			ASSERT_FALSE(Solution::PredictTheWinner(nums));
		}

		TEST(predict_the_winner, case2) {
			vector nums = {1, 5, 233, 7};
			ASSERT_TRUE(Solution::PredictTheWinner(nums));
		}
	}// namespace predict_the_winner

	namespace palindrome_partitioning {
		TEST(palindrome_partitioning, case1) {
			const string s                   = "aab";
			const vector<vector<string>> ans = {{"a", "a", "b"}, {"aa", "b"}};
			ASSERT_EQ(ans, Solution::partition(s));
		}

		TEST(palindrome_partitioning, case2) {
			const string s                   = "a";
			const vector<vector<string>> ans = {{"a"}};
			ASSERT_EQ(ans, Solution::partition(s));
		}
	}// namespace palindrome_partitioning

	namespace palindrome_partitioning_ii {
		TEST(palindrome_partitioning_ii, case1) {
			const string s = "aab";
			ASSERT_EQ(1, Solution::minCut(s));
		}

		TEST(palindrome_partitioning_ii, case2) {
			const string s = "a";
			ASSERT_EQ(0, Solution::minCut(s));
		}

		TEST(palindrome_partitioning_ii, case3) {
			const string s = "ab";
			ASSERT_EQ(1, Solution::minCut(s));
		}
	}// namespace palindrome_partitioning_ii

	namespace partition_equal_subset_sum {
		TEST(partition_equal_subset_sum, case1) {
			vector nums = {1, 5, 11, 5};
			ASSERT_TRUE(Solution::canPartition(nums));
		}

		TEST(partition_equal_subset_sum, case2) {
			vector nums = {1, 2, 3, 5};
			ASSERT_FALSE(Solution::canPartition(nums));
		}
	}// namespace partition_equal_subset_sum

	namespace minimum_cost_for_tickets {
		TEST(minimum_cost_for_tickets, case1) {
			vector days  = {1, 4, 6, 7, 8, 20};
			vector costs = {2, 7, 15};
			ASSERT_EQ(11, Solution::mincostTickets(days, costs));
		}

		TEST(minimum_cost_for_tickets, case2) {
			vector days  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
			vector costs = {2, 7, 15};
			ASSERT_EQ(17, Solution::mincostTickets(days, costs));
		}
	}// namespace minimum_cost_for_tickets

	namespace best_time_to_buy_and_sell_stock_iii {
		TEST(best_time_to_buy_and_sell_stock_iii, case1) {
			vector prices = {3, 3, 5, 0, 0, 3, 1, 4};
			ASSERT_EQ(6, Solution::maxProfit(prices));
		}

		TEST(best_time_to_buy_and_sell_stock_iii, case2) {
			vector prices = {1, 2, 3, 4, 5};
			ASSERT_EQ(4, Solution::maxProfit(prices));
		}

		TEST(best_time_to_buy_and_sell_stock_iii, case3) {
			vector prices = {7, 6, 4, 3, 1};
			ASSERT_EQ(0, Solution::maxProfit(prices));
		}

		TEST(best_time_to_buy_and_sell_stock_iii, case4) {
			vector prices = {1};
			ASSERT_EQ(0, Solution::maxProfit(prices));
		}
	}// namespace best_time_to_buy_and_sell_stock_iii

	namespace dungeon_game {
		TEST(dungeon_game, case1) {
			vector<vector<int>> dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
			ASSERT_EQ(7, Solution::calculateMinimumHP(dungeon));
		}

		TEST(dungeon_game, case2) {
			vector<vector<int>> dungeon = {{0}};
			ASSERT_EQ(1, Solution::calculateMinimumHP(dungeon));
		}

		TEST(dungeon_game, case3) {
			vector<vector<int>> dungeon = {{29, -78, -52, -1, -38, 6, 24, -45, 35, -29}, {-48, -48, -52, 2, -96, -78, -96, 40, -78, -73}, {-31, -73, -19, 38, 14, -95, 28, -59, 29, -20}, {17, -86, 45, 15, -3, -53, 43, 42, -97, -1}, {20, -99, -4, -2, -87, -98, 7, -90, -33, -42}, {-77, -66, -54, -46, 38, -42, 3, -5, -45, -49}, {13, -13, -52, -63, 25, 9, -63, -6, -58, -86}, {-57, 38, -83, 41, -71, -18, 9, -57, 35, -33}, {-2, -2, -95, -85, -37, -9, -60, -95, -87, -99}, {46, -98, -77, -13, -76, 36, -38, -19, -63, 5}, {-66, -15, -45, -81, -51, 6, -29, -96, 6, 28}, {-22, 17, 34, -52, -14, -65, -17, -70, 10, -40}, {18, -37, 23, -76, -5, 4, -31, -59, -22, 30}, {-26, -12, -34, 9, -78, -53, -98, -37, -1, 29}, {-54, -94, 37, -8, 22, -16, -84, -100, -45, 13}, {25, -96, 28, -77, 5, -93, 4, 20, -41, -89}, {-90, -99, -47, 29, 14, -47, -78, -40, -56, 26}, {-82, -69, -56, -40, 6, 0, -20, 5, -39, -73}, {-100, 44, 11, 37, 43, 45, -23, 8, 16, 45}, {-33, 41, -89, -13, -63, 46, 17, 26, -65, 23}, {-48, 2, -32, -56, -55, -21, -63, -9, -23, -61}, {-56, 44, -34, 45, 45, -23, 41, 9, 7, -90}, {34, 49, -66, -41, 37, -56, -62, -71, 28, -87}, {-54, -36, -78, -37, -22, 27, -64, -58, -3, -70}, {-77, -23, -60, -99, 45, -47, -42, 9, -72, -3}, {30, 29, 2, -50, -46, 6, -72, 0, -39, -4}, {32, 29, -67, -38, -56, -43, 50, -65, -81, -3}, {31, -31, -93, 34, 40, 47, -28, -6, -60, 48}, {42, -68, -14, -94, -36, -26, 13, -96, -39, -71}, {-96, 1, 37, -42, 17, 1, 34, -30, -31, 48}, {-93, -24, 12, -15, -98, 49, 30, -73, -4, 16}, {-86, -35, -100, 4, 15, 14, -1, 47, -11, 46}, {-76, -67, 0, -95, 25, 5, -83, -54, 45, 30}, {-27, -84, 17, 9, -63, -39, 37, -69, -62, 24}, {-40, -37, -52, -39, 10, -69, -73, -51, 48, 27}, {5, -86, -92, -8, 37, -44, 33, 0, -83, -37}, {-82, 45, 23, -95, 15, 35, 27, -28, -80, -80}, {-57, 26, -52, -13, -65, -80, -18, 46, 11, -14}, {49, 23, 26, 9, 18, -57, -18, -82, -85, -10}, {38, -25, -11, -38, 44, -29, -14, -80, -16, 4}, {-46, 48, 39, -65, -59, -13, 47, -23, -58, -100}, {42, -69, -93, -18, 22, 5, -26, -77, -37, 20}, {30, 41, -34, -93, -74, -49, -89, -53, -18, -51}, {-3, 12, 28, 8, 28, -31, 4, -75, -57, -89}, {-70, 0, -6, -74, -14, 43, -53, -23, -76, -22}, {14, -82, -25, -14, 14, -78, -46, -16, 28, -72}, {5, 48, 45, -87, 20, -13, -63, -48, -7, -64}, {49, -3, -63, -43, -58, -23, -21, -60, 11, 15}, {-65, -58, -50, 47, 45, -93, -71, 20, -90, -58}, {-49, -62, -16, 11, 43, -31, -39, 13, -43, 30}, {8, -45, -98, -22, 10, -46, -51, -22, -81, -99}, {4, -87, -53, -53, -19, -38, 24, -42, -15, -21}, {-77, 30, -95, 39, 42, 10, 41, -40, -46, -51}, {-69, 45, -99, 14, -54, 35, 18, -46, 11, -80}, {-12, 50, -12, 50, 45, -58, 18, -19, 29, -24}, {-63, 12, -14, -28, -48, 42, -8, -67, -87, 43}, {9, -87, 26, -29, -53, -70, -11, -43, -88, 15}, {-1, -12, 15, -42, -44, 41, 22, -46, 7, -31}, {-13, 6, 11, 13, -98, -96, -54, -95, -84, -34}, {13, -47, -42, -94, -90, -86, 50, -91, 19, 48}, {-26, -66, -18, 45, -72, -60, -7, 40, 37, -45}, {-11, 15, 48, -70, -89, -92, 25, -82, -36, 23}, {27, -11, -4, 35, -32, -30, -33, 50, 29, -24}, {-32, 26, -10, -5, 25, -30, 18, -70, -98, -3}, {-80, -45, -65, 42, -84, -56, -50, -97, -13, -65}, {19, -41, 26, -11, -66, 18, -52, -16, 28, -22}, {45, -23, -79, -44, -38, -100, 8, 11, -99, -67}, {-8, -48, -20, -15, -11, -52, 20, 30, -43, 24}, {-49, 23, -58, -73, 18, 43, 26, 1, -33, 32}, {-15, 27, -49, -87, -72, -45, -56, -91, -30, -40}, {3, -55, -22, -44, -71, -100, -53, -99, -85, 14}, {-34, -67, 25, -93, -21, -4, -37, -92, 12, -97}, {-14, 17, -72, -3, -25, -44, -26, -98, 10, -68}, {-90, -97, -1, -31, -44, -27, 43, -77, -35, -77}, {28, -53, -27, -100, -51, -45, 45, -67, -70, -61}, {-24, -38, 40, 36, 39, 2, 43, -38, -64, 3}, {-77, -85, -54, -88, 41, -85, -57, -100, -93, -75}, {40, -98, -59, -60, -15, 39, -64, 32, -77, 13}, {-50, 9, -64, 28, -8, -61, -16, -79, -77, -69}, {10, 16, -54, 47, -11, -4, -54, -10, 3, -10}, {-76, -62, -78, -23, -34, -97, -17, -67, -23, 13}, {-67, -27, -74, -62, -56, -36, -9, -51, 6, 37}, {23, 32, -93, -3, 28, -35, -13, 11, 7, -99}, {-20, -54, -54, -82, -36, 8, 25, 38, 43, 32}, {-97, -71, 38, -73, 27, -71, 47, -69, -74, 19}, {-61, -10, 5, -84, 48, 49, 6, -86, -28, -48}, {20, -92, -54, -7, 2, -90, -68, 14, -32, -12}, {-27, -100, 18, -47, 5, -73, 10, -50, -91, -75}, {-30, -43, -31, -96, -34, -54, -72, -70, 32, -72}, {-51, -55, -17, 24, 39, 39, -35, 4, 19, -82}, {11, -14, -97, 10, 42, 28, -31, -61, -96, 38}, {-94, -78, -42, 10, -36, -72, 2, -26, 3, -68}, {-44, 23, 5, -82, -81, -38, 13, -76, 0, -20}, {-36, 1, -90, -65, -67, -14, -79, 46, 35, 30}, {-85, -79, -34, 46, -39, -79, 8, -61, -75, -100}, {-58, -54, -84, 5, -93, -55, 7, 19, -27, -24}, {1, -51, -30, -4, -39, -94, 32, 14, -46, -91}, {37, -4, -18, -16, 7, 4, -98, -63, -15, 44}, {-4, -55, -33, 30, -37, 43, 5, -13, -56, -17}, {-19, -74, -31, -64, -50, -72, -63, 50, 1, -10}};
			ASSERT_EQ(558, Solution::calculateMinimumHP(dungeon));
		}
	}// namespace dungeon_game

	namespace course_schedule {
		TEST(course_schedule, case1) {
			vector<vector<int>> prerequisites = {{1, 0}};
			ASSERT_TRUE(Solution::canFinish(2, prerequisites));
		}

		TEST(course_schedule, case2) {
			vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
			ASSERT_FALSE(Solution::canFinish(2, prerequisites));
		}
	}// namespace course_schedule

	namespace course_schedule_ii {
		TEST(course_schedule_ii, case1) {
			vector<vector<int>> prerequisites = {{1, 0}};
			const vector ans                  = {0, 1};
			ASSERT_EQ(ans, Solution::findOrder(2, prerequisites));
		}

		TEST(course_schedule_ii, case2) {
			vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
			const vector ans                  = {0, 1, 2, 3};
			ASSERT_EQ(ans, Solution::findOrder(4, prerequisites));
		}

		TEST(course_schedule_ii, case3) {
			vector<vector<int>> prerequisites = {};
			const vector ans                  = {0};
			ASSERT_EQ(ans, Solution::findOrder(1, prerequisites));
		}
	}// namespace course_schedule_ii

	namespace longest_increasing_path_in_a_matrix {
		TEST(longest_increasing_path_in_a_matrix, case1) {
			vector<vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
			Solution sol{};
			ASSERT_EQ(4, sol.longestIncreasingPath(matrix));
		}

		TEST(longest_increasing_path_in_a_matrix, case2) {
			vector<vector<int>> matrix = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};
			Solution sol{};
			ASSERT_EQ(4, sol.longestIncreasingPath(matrix));
		}

		TEST(longest_increasing_path_in_a_matrix, case3) {
			vector<vector<int>> matrix = {{1}};
			Solution sol{};
			ASSERT_EQ(1, sol.longestIncreasingPath(matrix));
		}

		TEST(longest_increasing_path_in_a_matrix, case4) {
			vector<vector<int>> matrix = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, {19, 18, 17, 16, 15, 14, 13, 12, 11, 10}, {20, 21, 22, 23, 24, 25, 26, 27, 28, 29}, {39, 38, 37, 36, 35, 34, 33, 32, 31, 30}, {40, 41, 42, 43, 44, 45, 46, 47, 48, 49}, {59, 58, 57, 56, 55, 54, 53, 52, 51, 50}, {60, 61, 62, 63, 64, 65, 66, 67, 68, 69}, {79, 78, 77, 76, 75, 74, 73, 72, 71, 70}, {80, 81, 82, 83, 84, 85, 86, 87, 88, 89}, {99, 98, 97, 96, 95, 94, 93, 92, 91, 90}, {100, 101, 102, 103, 104, 105, 106, 107, 108, 109}, {119, 118, 117, 116, 115, 114, 113, 112, 111, 110}, {120, 121, 122, 123, 124, 125, 126, 127, 128, 129}, {139, 138, 137, 136, 135, 134, 133, 132, 131, 130}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
			Solution sol{};
			ASSERT_EQ(140, sol.longestIncreasingPath(matrix));
		}
	}// namespace longest_increasing_path_in_a_matrix

	namespace parallel_courses {
		TEST(parallel_courses, case1) {
			vector<vector<int>> relations = {{1, 3}, {2, 3}};
			ASSERT_EQ(2, Solution::minimumSemesters(3, relations));
		}

		TEST(parallel_courses, case2) {
			vector<vector<int>> relations = {{1, 3}, {2, 3}, {3, 1}};
			ASSERT_EQ(-1, Solution::minimumSemesters(3, relations));
		}
	}// namespace parallel_courses

	namespace alien_dictionary {
		TEST(alien_dictionary, case1) {
			vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
			ASSERT_EQ("wertf", Solution::alienOrder(words));
		}

		TEST(alien_dictionary, case2) {
			vector<string> words = {"z", "x"};
			ASSERT_EQ("zx", Solution::alienOrder(words));
		}

		TEST(alien_dictionary, case3) {
			vector<string> words = {"z", "x", "z"};
			ASSERT_EQ("", Solution::alienOrder(words));
		}

		TEST(alien_dictionary, case4) {
			vector<string> words = {"z", "z"};
			ASSERT_EQ("z", Solution::alienOrder(words));
		}

		TEST(alien_dictionary, case5) {
			vector<string> words = {"abc", "ab"};
			ASSERT_EQ("", Solution::alienOrder(words));
		}
	}// namespace alien_dictionary

	namespace single_number_iii {
		TEST(single_number_iii, case1) {
			vector nums      = {1, 2, 1, 3, 2, 5};
			const vector ans = {3, 5};
			ASSERT_EQ(ans, Solution::singleNumber(nums));
		}

		TEST(single_number_iii, case2) {
			vector nums      = {-1, 0};
			const vector ans = {-1, 0};
			ASSERT_EQ(ans, Solution::singleNumber(nums));
		}

		TEST(single_number_iii, case3) {
			vector nums      = {0, 1};
			const vector ans = {1, 0};
			ASSERT_EQ(ans, Solution::singleNumber(nums));
		}
	}// namespace single_number_iii

	namespace shortest_path_to_get_all_keys {
		TEST(shortest_path_to_get_all_keys, case1) {
			vector<string> grid = {"@.a.#", "###.#", "b.A.B"};
			ASSERT_EQ(8, Solution::shortestPathAllKeys(grid));
		}

		TEST(shortest_path_to_get_all_keys, case2) {
			vector<string> grid = {"@..aA", "..B#.", "....b"};
			ASSERT_EQ(6, Solution::shortestPathAllKeys(grid));
		}

		TEST(shortest_path_to_get_all_keys, case3) {
			vector<string> grid = {"@Aa"};
			ASSERT_EQ(-1, Solution::shortestPathAllKeys(grid));
		}

		TEST(shortest_path_to_get_all_keys, case4) {
			vector<string> grid = {".@aA"};
			ASSERT_EQ(1, Solution::shortestPathAllKeys(grid));
		}

		TEST(shortest_path_to_get_all_keys, case5) {
			vector<string> grid = {"..#....##.", "....d.#.D#", "#...#.c...", "..##.#..a.", "...#....##", "#....b....", ".#..#.....", "..........", ".#..##..A.", ".B..C.#..@"};
			ASSERT_EQ(19, Solution::shortestPathAllKeys(grid));
		}
	}// namespace shortest_path_to_get_all_keys

	namespace minimum_number_of_k_consecutive_bit_flips {
		TEST(minimum_number_of_k_consecutive_bit_flips, case1) {
			vector nums = {0, 1, 0};
			ASSERT_EQ(2, Solution::minKBitFlips(nums, 1));
		}

		TEST(minimum_number_of_k_consecutive_bit_flips, case2) {
			vector nums = {1, 1, 0};
			ASSERT_EQ(-1, Solution::minKBitFlips(nums, 2));
		}

		TEST(minimum_number_of_k_consecutive_bit_flips, case3) {
			vector nums = {0, 0, 0, 1, 0, 1, 1, 0};
			ASSERT_EQ(3, Solution::minKBitFlips(nums, 3));
		}
	}// namespace minimum_number_of_k_consecutive_bit_flips

	namespace lfu_cache {
		TEST(lfu_cache, case1) {
			LFUCache c(2);
			c.put(1, 1);
			c.put(2, 2);
			ASSERT_EQ(1, c.get(1));
			c.put(3, 3);
			ASSERT_EQ(-1, c.get(2));
			ASSERT_EQ(3, c.get(3));
			c.put(4, 4);
			ASSERT_EQ(-1, c.get(1));
			ASSERT_EQ(3, c.get(3));
			ASSERT_EQ(4, c.get(4));
		}
	}// namespace lfu_cache

	namespace leetcode454_4sum_ii {
		TEST(leetcode454_4sum_ii, case1) {
			vector nums1 = {1, 2};
			vector nums2 = {-2, -1};
			vector nums3 = {-1, 2};
			vector nums4 = {0, 2};
			Solution sol;
			ASSERT_EQ(2, sol.fourSumCount(nums1, nums2, nums3, nums4));
		}

		TEST(leetcode454_4sum_ii, case2) {
			vector nums1 = {0};
			vector nums2 = {0};
			vector nums3 = {0};
			vector nums4 = {0};
			Solution sol;
			ASSERT_EQ(1, sol.fourSumCount(nums1, nums2, nums3, nums4));
		}
	}// namespace leetcode454_4sum_ii

	namespace maximum_size_subarray_sum_equals_k {
		TEST(maximum_size_subarray_sum_equals_k, case1) {
			vector nums = {1, -1, 5, -2, 3};
			ASSERT_EQ(4, Solution::maxSubArrayLen(nums, 3));
		}

		TEST(maximum_size_subarray_sum_equals_k, case2) {
			vector nums = {-2, -1, 2, 1};
			ASSERT_EQ(2, Solution::maxSubArrayLen(nums, 1));
		}
	}// namespace maximum_size_subarray_sum_equals_k

	namespace minimum_swaps_to_group_all_1s_together {
		TEST(minimum_swaps_to_group_all_1s_together, case1) {
			vector data = {1, 0, 1, 0, 1};
			ASSERT_EQ(1, Solution::minSwaps(data));
		}

		TEST(minimum_swaps_to_group_all_1s_together, case2) {
			vector data = {0, 0, 0, 1, 0};
			ASSERT_EQ(0, Solution::minSwaps(data));
		}

		TEST(minimum_swaps_to_group_all_1s_together, case3) {
			vector data = {1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1};
			ASSERT_EQ(3, Solution::minSwaps(data));
		}

		TEST(minimum_swaps_to_group_all_1s_together, case4) {
			vector data = {1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1};
			ASSERT_EQ(8, Solution::minSwaps(data));
		}
	}// namespace minimum_swaps_to_group_all_1s_together
}// namespace leetcode
