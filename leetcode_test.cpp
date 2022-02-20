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

	/*namespace maximum_employees_to_be_invited_to_a_meeting {
		TEST(maximum_employees_to_be_invited_to_a_meeting, case1) {
			int input[] = { 2, 2, 1, 2 };
			auto vec = vector<int>(begin(input), end(input));
			ASSERT_EQ(3, Solution::maximumInvitations(vec));
		}

		TEST(maximum_employees_to_be_invited_to_a_meeting, case2) {
			int input[] = { 1, 2, 0 };
			auto vec = vector<int>(begin(input), end(input));
			ASSERT_EQ(3, Solution::maximumInvitations(vec));
		}

		TEST(maximum_employees_to_be_invited_to_a_meeting, case3) {
			int input[] = { 1, 2, 0 };
			auto vec = vector<int>(begin(input), end(input));
			ASSERT_EQ(3, Solution::maximumInvitations(vec));
		}

		TEST(maximum_employees_to_be_invited_to_a_meeting, case4) {
			int input[] = { 1, 0, 0, 2, 1, 4, 7, 8, 9, 6, 7, 10, 8 };
			auto vec = vector<int>(begin(input), end(input));
			ASSERT_EQ(6, Solution::maximumInvitations(vec));
		}
	}*/

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
}// namespace leetcode
