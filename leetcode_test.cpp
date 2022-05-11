#include "leetcode.h"
#include "gtest/gtest.h"
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
			auto root                = new TreeNode(6);
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
}// namespace leetcode
