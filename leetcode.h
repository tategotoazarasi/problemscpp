//
// Created by tategotoazarasi on 2021/12/29.
//

#ifndef PROBLEMSCPP_LEETCODE_H
#define PROBLEMSCPP_LEETCODE_H

#include <map>
#include <string>
#include <vector>

using namespace std;

namespace leetcode {
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;

		TreeNode()
			: val(0), left(nullptr), right(nullptr) {}

		explicit TreeNode(int x)
			: val(x), left(nullptr), right(nullptr) {}

		TreeNode(int x, TreeNode *left, TreeNode *right)
			: val(x), left(left), right(right) {}

		bool operator==(const TreeNode &) const;

		bool operator!=(const TreeNode &) const;
	};

	namespace concatenated_words {
		class Solution {
		public:
			static vector<string> findAllConcatenatedWordsInADict(vector<string> &);
		};

		class TrieNode {
		public:
			bool is_end;
			char ch;
			TrieNode *nexts[26] = {
					nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
					nullptr,
					nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
					nullptr,
					nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

			explicit TrieNode(char);

			void insert(const string &str);

			bool dfs(TrieNode *, const string &, int, bool);
		};
	}// namespace concatenated_words

	namespace excel_sheet_column_number {
		class Solution {
		public:
			static int titleToNumber(const string &columnTitle);
		};
	}// namespace excel_sheet_column_number

	namespace excel_sheet_column_title {
		class Solution {
		public:
			static string convertToTitle(int columnNumber);
		};
	}// namespace excel_sheet_column_title

	namespace majority_element {
		class Solution {
		private:
			map<int, int> m;

		public:
			Solution();

			int majorityElement(vector<int> &nums);
		};
	}// namespace majority_element

	namespace count_special_quadruplets {
		class Solution {
		public:
			static int countQuadruplets(vector<int> &);
		};
	}// namespace count_special_quadruplets

	namespace hand_of_straights {
		class Solution {
		public:
			static bool isNStraightHand(vector<int> &hand, int groupSize);
		};
	}// namespace hand_of_straights

	namespace perfect_number {
		class Solution {
		public:
			static bool checkPerfectNumber(int num);
		};
	}// namespace perfect_number

	namespace convert_bst_to_greater_tree {
		struct FriendTreeNode {
			int sum;
			int val;
			FriendTreeNode *left;
			FriendTreeNode *right;
			TreeNode *friend_node;

			explicit FriendTreeNode(int x, TreeNode *friend_node)
				: sum(x), val(0), left(nullptr), right(nullptr),
				  friend_node(friend_node) {}
		};

		class Solution {
		public:
			static TreeNode *convertBST(TreeNode *root);

			static FriendTreeNode *copy(TreeNode *);

			static void get_sum(FriendTreeNode *);

			static void convert(FriendTreeNode *);
		};
	}// namespace convert_bst_to_greater_tree

	namespace convert_1d_array_into_2d_array {
		class Solution {
		public:
			static vector<vector<int>> construct2DArray(vector<int> &original, int m, int n);
		};
	}// namespace convert_1d_array_into_2d_array

	namespace elimination_game {
		class Solution {
		public:
			static int lastRemaining(int);
		};
	}// namespace elimination_game

	namespace check_if_all_as_appears_before_all_bs {
		class Solution {
		public:
			static bool checkString(string);
		};
	}// namespace check_if_all_as_appears_before_all_bs

	namespace number_of_laser_beams_in_a_bank {
		class Solution {
		public:
			static int numberOfBeams(vector<string> &);

			static int deviceCount(const string &);
		};
	}// namespace number_of_laser_beams_in_a_bank

	namespace destroying_asteroids {
		class Solution {
		public:
			static bool asteroidsDestroyed(int mass, vector<int> &asteroids);
		};
	}// namespace destroying_asteroids

	namespace maximum_employees_to_be_invited_to_a_meeting {
		class Solution {
		public:
			static int maximumInvitations(vector<int> &);
		};
	}// namespace maximum_employees_to_be_invited_to_a_meeting

	namespace day_of_the_week {
		class Solution {
		public:
			static string dayOfTheWeek(int day, int month, int year);
		};
	}// namespace day_of_the_week

	/**
	 * \brief LeetCode 913. 猫和老鼠
	 */
	namespace cat_and_mouse {
		const int MOUSE_WIN = 1;

		const int CAT_WIN = 2;

		const int DRAW = 0;

		const int MAXN = 51;

		class Solution {
		public:
			int n;
			int dp[MAXN][MAXN][MAXN * 2];
			vector<vector<int>> graph;

			int catMouseGame(vector<vector<int>> &graph);

			int getResult(int mouse, int cat, int turns);

			void getNextResult(int mouse, int cat, int turns);
		};
	}// namespace cat_and_mouse

	namespace replace_all_s_to_avoid_consecutive_repeating_characters {
		class Solution {
		public:
			static string modifyString(string s);
		};
	}// namespace replace_all_s_to_avoid_consecutive_repeating_characters

	/**
	 * \brief LeetCode 71. 简化路径
	 */
	namespace simplify_path {
		class Solution {
		public:
			static string simplifyPath(string path);
		};
	}// namespace simplify_path

	/**
	 * \brief LeetCode 1614. 括号的最大嵌套深度
	 */
	namespace maximum_nesting_depth_of_the_parentheses {
		class Solution {
		public:
			static int maxDepth(string s);
		};
	}// namespace maximum_nesting_depth_of_the_parentheses

	/// \brief LeetCode 89. 格雷编码
	namespace gray_code {
		class Solution {
		public:
			static vector<int> grayCode(int n);
		};
	}// namespace gray_code

	/// \brief LeetCode 5976. 检查是否每一行每一列都包含全部整数
	namespace check_if_every_row_and_column_contains_all_numbers {
		class Solution {
		public:
			static bool checkValid(vector<vector<int>> &matrix);
		};
	}// namespace check_if_every_row_and_column_contains_all_numbers

	/// \brief LeetCode 5977. 最少交换次数来组合所有的 1 II
	namespace minimum_swaps_to_group_all_1s_together_ii {
		class Solution {
		public:
			static int minSwaps(vector<int> &nums);
		};
	}// namespace minimum_swaps_to_group_all_1s_together_ii

	/// \brief LeetCode 5978. 统计追加字母可以获得的单词数
	namespace count_words_obtained_after_adding_a_letter {
		class Solution {
		public:
			static int wordCount(vector<string> &startWords, vector<string> &targetWords);

			static unsigned int str2bin(const string &);
		};
	}// namespace count_words_obtained_after_adding_a_letter

	/// \brief LeetCode 1629. 按键持续时间最长的键
	namespace slowest_key {
		class Solution {
		public:
			static char slowestKey(vector<int> &releaseTimes, string keysPressed);
		};
	}// namespace slowest_key

	/**
	 * \brief LeetCode 306. 累加数
	 */
	namespace additive_number {
		class Solution {
		public:
			static bool isAdditiveNumber(string num);
			/**
			 * \brief 
			 * \param n1 第一个数字
			 * \param n2 第二个数字
			 * \param length 总长度
			 * \param current 现在的位置
			 * \return 
			 */
			static bool dfs(unsigned long long n1, unsigned long long n2, const char *, unsigned short length, unsigned short current);
			/**
			 * \brief 将字符串的一个子串转换为整数
			 * \param start 起始位置
			 * \param length 转换长度
			 * \return 从字符串转换来的整数
			 */
			static unsigned long long str2ui(const char *, unsigned short start, unsigned short length);

			/**
			 * \brief 判断一个字符串与另一个字符串的子串是否相等
			 * \param start 另一个字符串的子串起始位置
			 * \param length 另一个字符串的总长度
			 * \return 一个字符串与另一个字符串的子串是否相等
			 */
			static bool equal(string, const char *, unsigned short start, unsigned short length);
		};
	}// namespace additive_number
};   // namespace leetcode

#endif//PROBLEMSCPP_LEETCODE_H
