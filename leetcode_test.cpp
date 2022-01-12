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
			auto *input  = new TreeNode(4, new TreeNode(1, new TreeNode(0), new TreeNode(2, nullptr, new TreeNode(3))),
                                       new TreeNode(6, new TreeNode(5), new TreeNode(7, nullptr, new TreeNode(8))));
			auto *ans    = new TreeNode(30, new TreeNode(36, new TreeNode(36), new TreeNode(35, nullptr, new TreeNode(33))),
                                     new TreeNode(21, new TreeNode(26), new TreeNode(15, nullptr, new TreeNode(8))));
			auto *output = Solution::convertBST(input);
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
}// namespace leetcode
