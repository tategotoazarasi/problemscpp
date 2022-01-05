#include<vector>
#include "gtest/gtest.h"
#include "leetcode.h"
#include "acwing.h"
#include "lintcode.h"
#include "luogu.h"

using namespace std;

namespace leetcode
{
	namespace excel_sheet_column_title
	{
		TEST(excel_sheet_column_title, case1)
		{
			ASSERT_EQ(std::string("A"), Solution::convertToTitle(1));
		}

		TEST(excel_sheet_column_title, case2)
		{
			ASSERT_EQ(std::string("AB"), Solution::convertToTitle(28));
		}

		TEST(excel_sheet_column_title, case3)
		{
			ASSERT_EQ(std::string("ZY"), Solution::convertToTitle(701));
		}

		TEST(excel_sheet_column_title, case4)
		{
			ASSERT_EQ(std::string("FXSHRXW"), Solution::convertToTitle(2147483647));
		}

		TEST(excel_sheet_column_title, case5)
		{
			ASSERT_EQ(std::string("AZ"), Solution::convertToTitle(52));
		}
	}

	namespace majority_element
	{
		TEST(majority_element, case1)
		{
			auto sol = Solution();
			int arr[] = { 3, 2, 3 };
			auto vec = std::vector<int>(arr, arr + 3);
			ASSERT_EQ(3, sol.majorityElement(vec));
		}

		TEST(majority_element, case2)
		{
			auto sol = Solution();
			int arr[] = { 2, 2, 1, 1, 1, 2, 2 };
			auto vec = std::vector<int>(arr, arr + 7);
			ASSERT_EQ(2, sol.majorityElement(vec));
		}

		TEST(majority_element, case3)
		{
			auto sol = Solution();
			int arr[] = { 3, 2, 3 };
			auto vec = std::vector<int>(arr, arr + 3);
			ASSERT_EQ(3, sol.majorityElement(vec));
		}
	}

	namespace excel_sheet_column_number
	{
		TEST(excel_sheet_column_number, case1)
		{
			ASSERT_EQ(1, Solution::titleToNumber("A"));
		}

		TEST(excel_sheet_column_number, case2)
		{
			ASSERT_EQ(28, Solution::titleToNumber("AB"));
		}

		TEST(excel_sheet_column_number, case3)
		{
			ASSERT_EQ(701, Solution::titleToNumber("ZY"));
		}

		TEST(excel_sheet_column_number, case4)
		{
			ASSERT_EQ(2147483647, Solution::titleToNumber("FXSHRXW"));
		}
	}

	namespace concatenated_words
	{
		TEST(concatenated_words, case1)
		{
			basic_string<char> input[] = {
				"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat",
				"ratcatdogcat"
			};
			auto vec = vector<basic_string<char>>(begin(input), end(input));
			auto ans = Solution::findAllConcatenatedWordsInADict(vec);
			string outputstr[] = { "catsdogcats", "dogcatsdog", "ratcatdogcat" };
			auto output = vector<string>(begin(outputstr), end(outputstr));
			for (const string& str : ans)
			{
				ASSERT_TRUE(find(output.cbegin(), output.cend(), str) != output.cend());
			}
			for (const string& str : output)
			{
				ASSERT_TRUE(find(ans.cbegin(), ans.cend(), str) != ans.cend());
			}
			ASSERT_EQ(ans.size(), output.size());
		}

		TEST(concatenated_words, case2)
		{
			basic_string<char> input[] = { "cat", "dog", "catdog" };
			auto vec = vector<basic_string<char>>(begin(input), end(input));
			auto ans = Solution::findAllConcatenatedWordsInADict(vec);
			string outputstr[] = { "catdog" };
			auto output = vector<string>(begin(outputstr), end(outputstr));
			for (const string& str : ans)
			{
				ASSERT_TRUE(find(output.cbegin(), output.cend(), str) != output.cend());
			}
			for (const string& str : output)
			{
				ASSERT_TRUE(find(ans.cbegin(), ans.cend(), str) != ans.cend());
			}
			ASSERT_EQ(ans.size(), output.size());
		}

		TEST(concatenated_words, case4)
		{
			basic_string<char> input[] = { "nuqhmfj", "mf", "jf", "n", "u", "q", "h" };
			auto vec = vector<basic_string<char>>(begin(input), end(input));
			auto ans = Solution::findAllConcatenatedWordsInADict(vec);
			auto output = vector<string>();
			for (const string& str : ans)
			{
				ASSERT_TRUE(find(output.cbegin(), output.cend(), str) != output.cend());
			}
			for (const string& str : output)
			{
				ASSERT_TRUE(find(ans.cbegin(), ans.cend(), str) != ans.cend());
			}
			ASSERT_EQ(ans.size(), output.size());
		}
	}

	namespace count_special_quadruplets
	{
		TEST(count_special_quadruplets, case1)
		{
			int input[] = { 1, 2, 3, 6 };
			auto vec = vector<int>(begin(input), end(input));
			ASSERT_EQ(1, Solution::countQuadruplets(vec));
		}

		TEST(count_special_quadruplets, case2)
		{
			int input[] = { 3, 3, 6, 4, 5 };
			auto vec = vector<int>(begin(input), end(input));
			ASSERT_EQ(0, Solution::countQuadruplets(vec));
		}

		TEST(count_special_quadruplets, case3)
		{
			int input[] = { 1, 1, 1, 3, 5 };
			auto vec = vector<int>(begin(input), end(input));
			ASSERT_EQ(4, Solution::countQuadruplets(vec));
		}

		TEST(count_special_quadruplets, case4)
		{
			int input[] = { 28, 8, 49, 85, 37, 90, 20, 8 };
			auto vec = vector<int>(begin(input), end(input));
			ASSERT_EQ(1, Solution::countQuadruplets(vec));
		}
	}

	namespace hand_of_straights
	{
		TEST(hand_of_straights, case1)
		{
			int input[] = { 1, 2, 3, 6, 2, 3, 4, 7, 8 };
			auto vec = vector<int>(begin(input), end(input));
			ASSERT_TRUE(Solution::isNStraightHand(vec, 3));
		}

		TEST(hand_of_straights, case2)
		{
			int input[] = { 1, 2, 3, 4, 5 };
			auto vec = vector<int>(begin(input), end(input));
			ASSERT_FALSE(Solution::isNStraightHand(vec, 4));
		}

		TEST(hand_of_straights, case3)
		{
			int input[] = { 1, 2, 3, 4, 5, 6 };
			auto vec = vector<int>(begin(input), end(input));
			ASSERT_TRUE(Solution::isNStraightHand(vec, 2));
		}

		TEST(hand_of_straights, case4)
		{
			int input[] = {
				9, 13, 15, 23, 22, 25, 4, 4, 29, 15, 8, 23, 12, 19, 24, 17, 18, 11, 22, 24, 17, 17, 10, 23,
				21, 18, 14, 18, 7, 6, 3, 6, 19, 11, 16, 11, 12, 13, 8, 26, 17, 20, 13, 19, 22, 21, 27, 9, 20,
				15, 20, 27, 8, 13, 25, 23, 22, 15, 9, 14, 20, 10, 6, 5, 14, 12, 7, 16, 21, 18, 21, 24, 23,
				10, 21, 16, 18, 16, 18, 5, 20, 19, 20, 10, 14, 26, 2, 9, 19, 12, 28, 17, 5, 7, 25, 22, 16,
				17, 21, 11
			};
			auto vec = vector<int>(begin(input), end(input));
			ASSERT_FALSE(Solution::isNStraightHand(vec, 10));
		}
	}

	namespace perfect_number
	{
		TEST(perfect_number, case1)
		{
			ASSERT_TRUE(Solution::checkPerfectNumber(28));
		}

		TEST(perfect_number, case2)
		{
			ASSERT_TRUE(Solution::checkPerfectNumber(6));
		}

		TEST(perfect_number, case3)
		{
			ASSERT_TRUE(Solution::checkPerfectNumber(496));
		}

		TEST(perfect_number, case4)
		{
			ASSERT_TRUE(Solution::checkPerfectNumber(8128));
		}

		TEST(perfect_number, case5)
		{
			ASSERT_FALSE(Solution::checkPerfectNumber(2));
		}
	}

	namespace convert_bst_to_greater_tree
	{
		TEST(convert_bst_to_greater_tree, case1)
		{
			auto input = new TreeNode(4, new TreeNode(1, new TreeNode(0), new TreeNode(2, nullptr, new TreeNode(3))),
				new TreeNode(6, new TreeNode(5), new TreeNode(7, nullptr, new TreeNode(8))));
			auto ans = new TreeNode(30, new TreeNode(36, new TreeNode(36), new TreeNode(35, nullptr, new TreeNode(33))),
				new TreeNode(21, new TreeNode(26), new TreeNode(15, nullptr, new TreeNode(8))));
			auto output = Solution::convertBST(input);
			ASSERT_TRUE((*ans) == (*output));
		}
	}

	namespace convert_1d_array_into_2d_array
	{
		TEST(convert_1d_array_into_2d_array, case1)
		{
			int input[4] = { 1, 2, 3, 4 };
			auto vec = vector<int>(begin(input), end(input));
			auto ans = Solution::construct2DArray(vec, 2, 2);
			int output1[] = { 1, 2 };
			int output2[] = { 3, 4 };
			auto vec1 = vector<int>(begin(output1), end(output1));
			auto vec2 = vector<int>(begin(output2), end(output2));
			auto vec_output = vector<vector<int>>();
			vec_output.push_back(vec1);
			vec_output.push_back(vec2);
			ASSERT_EQ(vec_output, ans);
		}
	}

	namespace elimination_game
	{
		TEST(elimination_game, case1)
		{
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
	}

	namespace check_if_all_as_appears_before_all_bs
	{
		TEST(check_if_all_as_appears_before_all_bs, case1)
		{
			ASSERT_TRUE(Solution::checkString("aaabbb"));
		}

		TEST(check_if_all_as_appears_before_all_bs, case2)
		{
			ASSERT_FALSE(Solution::checkString("abab"));
		}

		TEST(check_if_all_as_appears_before_all_bs, case3)
		{
			ASSERT_TRUE(Solution::checkString("bbb"));
		}
	}

	namespace number_of_laser_beams_in_a_bank
	{
		TEST(number_of_laser_beams_in_a_bank, case1)
		{
			string input[] = { "011001", "000000", "010100", "001000" };
			auto vec = vector<string>(begin(input), end(input));
			ASSERT_EQ(8, Solution::numberOfBeams(vec));
		}

		TEST(number_of_laser_beams_in_a_bank, case2)
		{
			string input[] = { "000", "111", "000" };
			auto vec = vector<string>(begin(input), end(input));
			ASSERT_EQ(0, Solution::numberOfBeams(vec));
		}
	}

	namespace destroying_asteroids
	{
		TEST(destroying_asteroids, case1)
		{
			int input[] = { 3, 9, 19, 5, 21 };
			auto vec = vector<int>(begin(input), end(input));
			ASSERT_TRUE(Solution::asteroidsDestroyed(10, vec));
		}

		TEST(destroying_asteroids, case2)
		{
			int input[] = { 4, 9, 23, 4 };
			auto vec = vector<int>(begin(input), end(input));
			ASSERT_FALSE(Solution::asteroidsDestroyed(5, vec));
		}
	}

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

	namespace day_of_the_week
	{
		TEST(day_of_the_week, case1)
		{
			ASSERT_EQ("Saturday", Solution::dayOfTheWeek(31, 8, 2019));
		}

		TEST(day_of_the_week, case2)
		{
			ASSERT_EQ("Sunday", Solution::dayOfTheWeek(18, 7, 1999));
		}

		TEST(day_of_the_week, case3)
		{
			ASSERT_EQ("Sunday", Solution::dayOfTheWeek(15, 8, 1993));
		}

		TEST(day_of_the_week, case4)
		{
			ASSERT_EQ("Monday", Solution::dayOfTheWeek(29, 2, 2016));
		}

		TEST(day_of_the_week, case5)
		{
			ASSERT_EQ("Tuesday", Solution::dayOfTheWeek(31, 8, 2100));
		}
	}

	namespace replace_all_s_to_avoid_consecutive_repeating_characters
	{
		TEST(replace_all_s_to_avoid_consecutive_repeating_characters, case1)
		{
			ASSERT_EQ("azs", Solution::modifyString("?zs"));
		}

		TEST(replace_all_s_to_avoid_consecutive_repeating_characters, case2)
		{
			ASSERT_EQ("ubvaw", Solution::modifyString("ubv?w"));
		}

		TEST(replace_all_s_to_avoid_consecutive_repeating_characters, case3)
		{
			ASSERT_EQ("jaqgacb", Solution::modifyString("j?qg??b"));
		}

		TEST(replace_all_s_to_avoid_consecutive_repeating_characters, case4)
		{
			ASSERT_EQ("abywaipkja", Solution::modifyString("??yw?ipkj?"));
		}
	}
}

namespace acwing
{
	TEST(acwing1, case1)
	{
		istringstream in("3 4");
		auto out = ostringstream();
		acwing1::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("7", ans);
	}

	TEST(acwing4200, case1)
	{
		istringstream in("2 7 1 8 2 8");
		auto out = ostringstream();
		acwing4200::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("0", ans);
	}

	TEST(acwing4200, case2)
	{
		istringstream in("20 30 40 50 0 100");
		auto out = ostringstream();
		acwing4200::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("20", ans);
	}

	TEST(acwing4200, case3)
	{
		istringstream in("31 41 59 26 17 43");
		auto out = ostringstream();
		acwing4200::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("9", ans);
	}

	TEST(acwing4201, case1)
	{
		istringstream in("10");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(acwing4201, case2)
	{
		istringstream in("20");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("3", ans);
	}

	TEST(acwing4201, case3)
	{
		istringstream in("100");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing4201, case4)
	{
		istringstream in("1000");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("8", ans);
	}

	TEST(acwing4201, case5)
	{
		istringstream in("10000");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("16", ans);
	}

	TEST(acwing4201, case6)
	{
		istringstream in("200");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("7", ans);
	}

	TEST(acwing4201, case7)
	{
		istringstream in("101");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("5", ans);
	}

	TEST(acwing4201, case8)
	{
		istringstream in("1");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	TEST(acwing4201, case9)
	{
		istringstream in("102");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("5", ans);
	}

	TEST(acwing4201, case10)
	{
		istringstream in("111");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("7", ans);
	}

	TEST(acwing4201, case11)
	{
		istringstream in("110");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("6", ans);
	}

	TEST(acwing610, case1)
	{
		istringstream in("5\n6\n7\n8");
		auto out = ostringstream();
		acwing610::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("DIFERENCA = -26", ans);
	}

	TEST(acwing604, case1)
	{
		istringstream in("2.00");
		auto out = ostringstream();
		acwing604::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("A=12.5664", ans);
	}

	TEST(acwing606, case1)
	{
		istringstream in("5.0\n7.1");
		auto out = ostringstream();
		acwing606::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("MEDIA = 6.43182", ans);
	}

	TEST(acwing609, case1)
	{
		istringstream in("25\n100\n5.50");
		auto out = ostringstream();
		acwing609::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("NUMBER = 25\n"
			"SALARY = U$ 550.00", ans);
	}

	TEST(acwing615, case1)
	{
		istringstream in("500\n35.0");
		auto out = ostringstream();
		acwing615::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("14.286 km/l", ans);
	}

	TEST(acwing616, case1)
	{
		istringstream in("1.0 7.0\n5.0 9.0");
		auto out = ostringstream();
		acwing616::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("4.4721", ans);
	}

	TEST(acwing653, case1)
	{
		istringstream in("576");
		auto out = ostringstream();
		acwing653::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("576\n"
			"5 nota(s) de R$ 100,00\n"
			"1 nota(s) de R$ 50,00\n"
			"1 nota(s) de R$ 20,00\n"
			"0 nota(s) de R$ 10,00\n"
			"1 nota(s) de R$ 5,00\n"
			"0 nota(s) de R$ 2,00\n"
			"1 nota(s) de R$ 1,00", ans);
	}

	TEST(acwing4203, case1)
	{
		istringstream in("001001");
		auto out = ostringstream();
		acwing4203::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("NO", ans);
	}

	TEST(acwing4203, case2)
	{
		istringstream in("1000000001");
		auto out = ostringstream();
		acwing4203::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("YES", ans);
	}

	TEST(acwing4204, case1)
	{
		istringstream in("2");
		auto out = ostringstream();
		acwing4204::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("0 1\n"
			"1 0", ans);
	}

	TEST(acwing4204, case2)
	{
		istringstream in("4");
		auto out = ostringstream();
		acwing4204::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("0 1 2 3\n"
			"1 0 3 2\n"
			"2 3 0 1\n"
			"3 2 1 0", ans);
	}

	TEST(acwing4204, case3)
	{
		istringstream in("6");
		auto out = ostringstream();
		acwing4204::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("0 1 2 3 4 5\n"
			"1 0 3 4 5 2\n"
			"2 3 0 5 1 4\n"
			"3 4 5 0 2 1\n"
			"4 5 1 2 0 3\n"
			"5 2 4 1 3 0", ans);
	}

	TEST(acwing2058, case1)
	{
		istringstream in("1010\n"
			"212");
		auto out = ostringstream();
		acwing2058::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("14", ans);
	}

	TEST(acwing654, case1)
	{
		istringstream in("556");
		auto out = ostringstream();
		acwing654::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("0:9:16", ans);
	}

	TEST(acwing605, case1)
	{
		istringstream in("3\n"
			"9");
		auto out = ostringstream();
		acwing605::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("PROD = 27", ans);
	}

	TEST(acwing2041, case1)
	{
		istringstream in("7 4\n5 5\n2 4\n4 6\n3 5");
		auto out = ostringstream();
		acwing2041::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	TEST(acwing2041, case2)
	{
		istringstream in("9 10\n"
			"5 5\n"
			"3 6\n"
			"6 6\n"
			"3 9\n"
			"1 7\n"
			"5 6\n"
			"6 8\n"
			"7 9\n"
			"4 6\n"
			"5 9");
		auto out = ostringstream();
		acwing2041::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing2041, case3)
	{
		istringstream in(
			"23 100\n8 9\n2 14\n6 12\n13 18\n13 18\n5 17\n10 14\n1 13\n8 12\n17 19\n2 6\n4 19\n16 20\n4 15\n9 9\n13 19\n1 14\n4 17\n16 21\n7 15\n3 14\n7 19\n13 17\n3 8\n7 19\n6 8\n8 23\n5 19\n17 20\n10 20\n9 18\n20 23\n16 23\n7 7\n4 22\n4 23\n19 23\n10 18\n14 16\n2 7\n3 7\n4 18\n20 21\n13 17\n10 13\n5 17\n8 20\n21 22\n14 22\n4 21\n4 18\n4 10\n4 5\n19 20\n6 22\n3 15\n7 9\n3 22\n20 21\n3 12\n3 16\n8 18\n5 12\n9 23\n10 14\n5 10\n3 21\n18 22\n10 15\n2 17\n19 23\n9 12\n2 19\n3 15\n12 14\n3 3\n9 18\n9 22\n7 9\n1 21\n4 15\n2 6\n18 20\n3 17\n4 18\n8 15\n2 15\n9 19\n6 9\n5 21\n2 16\n1 20\n2 20\n13 20");
		auto out = ostringstream();
		acwing2041::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("46", ans);
	}

	namespace acwing2060
	{
		TEST(acwing2060, case1)
		{
			istringstream in("6 16\n"
				"................\n"
				"..XXXX....XXX...\n"
				"...XXXX....XX...\n"
				".XXXX......XXX..\n"
				"........XXXXX...\n"
				".........XXX....");
			auto out = ostringstream();
			acwing2060::main(in, out);
			auto ans = out.str();
			ASSERT_EQ("3", ans);
		}
	}

	namespace acwing2019
	{
		TEST(acwing2019, case1)
		{
			istringstream in("7 6 3\n"
				"6 2\n"
				"5 2\n"
				"4 3\n"
				"2 1\n"
				"7 3\n"
				"5 4\n"
				"6 4");
			auto out = ostringstream();
			acwing2019::main(in, out);
			auto ans = out.str();
			ASSERT_EQ("1", ans);
		}

		TEST(acwing2019, case2)
		{
			istringstream in("4 2 2\n"
				"2 1\n"
				"1 2\n"
				"2 3\n"
				"4 2");
			auto out = ostringstream();
			acwing2019::main(in, out);
			auto ans = out.str();
			ASSERT_EQ("0", ans);
		}
	}

	TEST(acwing611, case1)
	{
		istringstream in("12 1 5.30\n"
			"16 2 5.10");
		auto out = ostringstream();
		acwing611::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("VALOR A PAGAR: R$ 15.50", ans);
	}

	TEST(acwing612, case1)
	{
		istringstream in("3");
		auto out = ostringstream();
		acwing612::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("VOLUME = 113.097", ans);
	}
}

namespace lintcode
{
	namespace license_key_formatting
	{
		TEST(license_key_formatting, case1)
		{
			auto s = string("5F3Z-2e-9-w");
			ASSERT_EQ("5F3Z-2E9W", Solution::licenseKeyFormatting(s, 4));
		}

		TEST(license_key_formatting, case2)
		{
			auto s = string("2-5g-3-J");
			ASSERT_EQ("2-5G-3J", Solution::licenseKeyFormatting(s, 2));
		}
	}

	namespace distribute_candies
	{
		TEST(distribute_candies, case1)
		{
			int input[] = { 1, 1, 2, 2, 3, 3, };
			auto vec = vector<int>(begin(input), end(input));
			ASSERT_EQ(3, Solution::distributeCandies(vec));
		}

		TEST(distribute_candies, case2)
		{
			int input[] = { 1, 1, 2, 2, 3, 3, 4, 5, 6, 6, 7, 8 };
			auto vec = vector<int>(begin(input), end(input));
			ASSERT_EQ(6, Solution::distributeCandies(vec));
		}
	}

	namespace remove_extra
	{
		TEST(remove_extra, case1)
		{
			string input = "The  sky   is blue";
			ASSERT_EQ("The sky is blue", Solution::removeExtra(input));
		}

		TEST(remove_extra, case2)
		{
			string input = "  low               ercase  ";
			ASSERT_EQ("low ercase", Solution::removeExtra(input));
		}
	}

	namespace fibonacci
	{
		TEST(fibonacci, case1)
		{
			ASSERT_EQ(0, Solution::fibonacci(1));
		}

		TEST(fibonacci, case2)
		{
			ASSERT_EQ(1, Solution::fibonacci(2));
		}
	}

	namespace character_deletion
	{
		TEST(character_deletion, case1)
		{
			auto str = string("They are students");
			auto sub = string("aeiou");
			ASSERT_EQ("Thy r stdnts", Solution::CharacterDeletion(str, sub));
		}
	}
}

namespace luogu
{
	/*TEST(T210229, case1) {
		istringstream in("3\n"
						 "0011\n"
						 "0110\n"
						 "1100");
		ostringstream out = ostringstream();
		T210229::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("9", ans);
	}

	TEST(T210229, case2) {
		istringstream in("3\n"
						 "0011\n"
						 "0110\n"
						 "1101");
		ostringstream out = ostringstream();
		T210229::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("8", ans);
	}

	TEST(T210229, case3) {
		istringstream in("4\n"
						 "10101\n"
						 "11101\n"
						 "01010\n"
						 "10101");
		ostringstream out = ostringstream();
		T210229::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("14", ans);
	}

	TEST(T210229, case4) {
		istringstream in("3\n"
						 "0111\n"
						 "1000\n"
						 "1101");
		ostringstream out = ostringstream();
		T210229::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("9", ans);
	}*/
}
