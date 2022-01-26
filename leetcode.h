#ifndef PROBLEMSCPP_LEETCODE_H
#define PROBLEMSCPP_LEETCODE_H

#include <climits>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
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

		bool operator==(const TreeNode & /*node*/) const;

		bool operator!=(const TreeNode & /*node*/) const;
	};

	struct ListNode {
		int val;
		ListNode *next;

		ListNode()
		    : val(0), next(nullptr){};

		explicit ListNode(int x)
		    : val(x), next(nullptr){};

		ListNode(int x, ListNode *next)
		    : val(x), next(next){};
	};

	namespace concatenated_words {
		class Solution {
		public:
			static vector<string> findAllConcatenatedWordsInADict(vector<string> & /*words*/);
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

			explicit TrieNode(char /*ch*/);

			void insert(const string &str);

			bool dfs(TrieNode * /*root*/, const string & /*str*/, int /*start*/, bool /*flag*/) const;
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
			static int countQuadruplets(vector<int> & /*nums*/);
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

			static FriendTreeNode *copy(TreeNode * /*node*/);

			static void get_sum(FriendTreeNode * /*node*/);

			static void convert(FriendTreeNode * /*sum_node*/);
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
			static int lastRemaining(int /*n*/);
		};
	}// namespace elimination_game

	namespace check_if_all_as_appears_before_all_bs {
		class Solution {
		public:
			static bool checkString(const string & /*s*/);
		};
	}// namespace check_if_all_as_appears_before_all_bs

	namespace number_of_laser_beams_in_a_bank {
		class Solution {
		public:
			static int numberOfBeams(vector<string> & /*bank*/);

			static int deviceCount(const string & /*str*/);
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
			static string simplifyPath(const string &path);
		};
	}// namespace simplify_path

	/**
	 * \brief LeetCode 1614. 括号的最大嵌套深度
	 */
	namespace maximum_nesting_depth_of_the_parentheses {
		class Solution {
		public:
			static int maxDepth(const string &s);
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

			static unsigned int str2bin(const string & /*str*/);
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
			static bool dfs(unsigned long long n1, unsigned long long n2, const char * /*nums*/, unsigned short length, unsigned short current);
			/**
			 * \brief 将字符串的一个子串转换为整数
			 * \param start 起始位置
			 * \param length 转换长度
			 * \return 从字符串转换来的整数
			 */
			static unsigned long long str2ui(const char * /*str*/, unsigned short start, unsigned short length);

			/**
			 * \brief 判断一个字符串与另一个字符串的子串是否相等
			 * \param start 另一个字符串的子串起始位置
			 * \param length 另一个字符串的总长度
			 * \return 一个字符串与另一个字符串的子串是否相等
			 */
			static bool equal(string /*sum*/, const char * /*nums*/, unsigned short start, unsigned short length);
		};
	}// namespace additive_number

	/// \brief LeetCode 2075. 解码斜向换位密码
	namespace decode_the_slanted_ciphertext {
		class Solution {
		public:
			static string decodeCiphertext(string encodedText, int rows);
			/// \brief 去除字符串右边的空白符
			/// \cite https://blog.csdn.net/tiandyoin/article/details/81508445
			/// \author tiandyoin
			/// \param s 要去除右边空白符的字符串
			/// \return  去除了右边空白符的字符串
			static string rtrim(string &s);
		};
	}// namespace decode_the_slanted_ciphertext

	/// \brief LeetCode 1036. 逃离大迷宫
	namespace escape_a_large_maze {
		struct point {
			unsigned int x;
			unsigned int y;
			unsigned int distance;
			point *target;

			point()
			    : x(0), y(0), distance(0), target(nullptr){};

			point(unsigned int x, unsigned int y, int distance, point *target)
			    : x(x), y(y), distance(distance), target(target){};
			bool operator<(const point &p) const;
			bool operator==(const point &p) const;
		};

		struct point_hash {
			size_t operator()(const point &p) const;
		};

		class Solution {
		public:
			static bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target);

			/// \brief 在迷宫中以source为起点搜索
			/// \param block_set 阻塞点集
			/// \param source 起点
			/// \param target 终点
			/// \param limit 搜索步数上限
			/// \return 0表示无法抵达 1表示可以抵达 2表示达到搜索步数上限
			static unsigned int search(unordered_set<point, point_hash> &block_set, point *source, point *target, unsigned int limit);
		};
	}// namespace escape_a_large_maze

	/**
	 * \brief LeetCode 334. 递增的三元子序列
	 */
	namespace increasing_triplet_subsequence {
		class Solution {
		public:
			static bool increasingTriplet(vector<int> &nums);
		};
	}// namespace increasing_triplet_subsequence

	/**
	 * \brief LeetCode 747. 至少是其他数字两倍的最大数
	 */
	namespace largest_number_at_least_twice_of_others {
		class Solution {
		public:
			static int dominantIndex(vector<int> &nums);
		};
	}// namespace largest_number_at_least_twice_of_others

	/// \brief LeetCode 373. 查找和最小的K对数字
	namespace find_k_pairs_with_smallest_sums {
		struct pair {
			int u;
			int v;

			pair(int u, int v)
			    : u(u), v(v){};
			bool operator<(const pair & /*p*/) const;
		};

		class Solution {
		public:
			static vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k);
		};
	}// namespace find_k_pairs_with_smallest_sums

	/**
	 * \brief LeetCode 46. 全排列
	 */
	namespace permutations {
		class Solution {
		public:
			static vector<vector<int>> permute(vector<int> &nums);
		};
	}// namespace permutations

	/// \brief LeetCode 1716. 计算力扣银行的钱
	namespace calculate_money_in_leetcode_bank {
		class Solution {
		public:
			static int totalMoney(int n);
		};
	}// namespace calculate_money_in_leetcode_bank

	/**
	 * \brief LeetCode 382. 链表随机节点
	 */
	namespace linked_list_random_node {
		class Solution {
		private:
			ListNode *head;

		public:
			explicit Solution(ListNode *head)
			    : head(head){};
			[[nodiscard]] int getRandom() const;
		};

	}// namespace linked_list_random_node

	/**
	 * \brief LeetCode 5980. 将字符串拆分为若干长度为 k 的组
	 */
	namespace divide_a_string_into_groups_of_size_k {
		class Solution {
		public:
			static vector<string> divideString(const string &s, int k, char fill);
		};
	}// namespace divide_a_string_into_groups_of_size_k

	/**
	 * \brief LeetCode 5194. 得到目标值的最少行动次数
	 */
	namespace minimum_moves_to_reach_target_score {
		class Solution {
		public:
			static int minMoves(int target, int maxDoubles);
		};
	}// namespace minimum_moves_to_reach_target_score

	/**
	 * \brief LeetCode 5982. 解决智力问题
	 */
	namespace solving_questions_with_brainpower {
		class Solution {
		public:
			static long long mostPoints(vector<vector<int>> &questions);
		};
	}// namespace solving_questions_with_brainpower

	/**
	 * \brief LeetCode 5983. 同时运行 N 台电脑的最长时间
	 */
	namespace maximum_running_time_of_n_computers {
		class Solution {
		public:
			static long long maxRunTime(int n, vector<int> &batteries);
		};
	}// namespace maximum_running_time_of_n_computers

	/// \brief LeetCode 1220. 统计元音字母序列的数目
	namespace coun_vowels_permutation {
		class Solution {
		public:
			static int countVowelPermutation(int n);
		};
	}// namespace coun_vowels_permutation

	/**
	 * \brief LeetCode 539. 最小时间差
	 * \date 2022-1-18
	 */
	namespace minimum_time_difference {
		class Solution {
		public:
			static int findMinDifference(vector<string> &timePoints);
		};
	}// namespace minimum_time_difference

	/// \brief LeetCode 219. 存在重复元素 II
	namespace contains_duplicate_ii {
		class Solution {
		public:
			static bool containsNearbyDuplicate(vector<int> &nums, int k);
		};
	}// namespace contains_duplicate_ii

	/// \brief LeetCode 2029. 石子游戏 IX
	namespace stone_game_ix {
		class Solution {
		public:
			static bool stoneGameIX(vector<int> &stones);
		};
	}// namespace stone_game_ix

	/**
	 * \brief LeetCode 1345. 跳跃游戏 IV
	 */
	namespace jump_game_iv {
		class Solution {
		public:
			static int minJumps(vector<int> &arr);
		};
	}// namespace jump_game_iv

	/// \brief LeetCode 1332. 删除回文子序列
	namespace remove_palindromic_subsequences {
		class Solution {
		public:
			static int removePalindromeSub(string s);
		};
	}// namespace remove_palindromic_subsequences

	/// \brief 剑指 Offer II 063. 替换单词
	namespace UhWRSj {
		struct TrieNode {
			char ch;
			TrieNode *next[26] = {};
			bool endroot;

			TrieNode()
			    : ch(0), endroot(false){};

			explicit TrieNode(char ch)
			    : ch(ch), endroot(false){};
			void insert(const string &str);
			[[nodiscard]] string get_prefix(string root, const string &str) const;
		};

		class Solution {
		public:
			static string replaceWords(vector<string> &dictionary, const string &sentence);
		};
	}// namespace UhWRSj

	/**
	 * \brief LeetCode 5971. 打折购买糖果的最小开销
	 */
	namespace minimum_cost_of_buying_candies_with_discount {
		class Solution {
		public:
			static int minimumCost(vector<int> &cost);
		};
	}// namespace minimum_cost_of_buying_candies_with_discount

	/**
	 * \brief LeetCode 5972. 统计隐藏数组数目
	 */
	namespace count_the_hidden_sequences {
		class Solution {
		public:
			static int numberOfArrays(vector<int> &differences, int lower, int upper);
		};
	}// namespace count_the_hidden_sequences

	/**
	 * \brief LeetCode 5973. 价格范围内最高排名的 K 样物品
	 */
	namespace k_highest_ranked_items_within_a_price_range {
		struct item {
			int distance;
			int price;
			int row;
			int col;

			item(int distance, int price, int row, int col)
			    : distance(distance), price(price), row(row), col(col){};
			bool operator<(const item & /*i*/) const;
		};

		class Solution {
		public:
			static vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k);
		};
	}// namespace k_highest_ranked_items_within_a_price_range

	/**
	 * \brief LeetCode 5974. 分隔长廊的方案数
	 */
	namespace number_of_ways_to_divide_a_long_corridor {
		class Solution {
		public:
			static int numberOfWays(string corridor);
		};
	}// namespace number_of_ways_to_divide_a_long_corridor

	/**
	 * \brief LeetCode 5989. 元素计数
	 */
	namespace count_elements_with_strictly_smaller_and_greater_elements {
		class Solution {
		public:
			static int countElements(vector<int> &nums);
		};
	}// namespace count_elements_with_strictly_smaller_and_greater_elements

	/**
	 * \brief LeetCode 5991. 按符号重排数组
	 */
	namespace rearrange_array_elements_by_sign {
		class Solution {
		public:
			static vector<int> rearrangeArray(vector<int> &nums);
		};
	}// namespace rearrange_array_elements_by_sign

	/**
	 * \brief LeetCode 5990. 找出数组中的所有孤独数字
	 */
	namespace find_all_lonely_numbers_in_the_array {
		class Solution {
		public:
			static vector<int> findLonely(vector<int> &nums);
		};
	}// namespace find_all_lonely_numbers_in_the_array

	/**
	 * \brief LeetCode 5992. 基于陈述统计最多好人数
	 */
	namespace maximum_good_people_based_on_statements {
		struct msg {
			int person;
			bool good;

			msg(int person, bool good)
			    : person(person), good(good){};
		};

		class Solution {
		public:
			static int maximumGood(vector<vector<int>> &statements);
			static pair<int, unordered_map<int, bool>> dfs(vector<vector<int>> &statements, unordered_map<int, bool> um, queue<msg> que);
		};
	}// namespace maximum_good_people_based_on_statements

	/**
	 * \brief LeetCode 2034. 股票价格波动
	 */
	namespace stock_price_fluctuation {
		/// \details
		/// Your StockPrice object will be instantiated and called as such:
		/// StockPrice* obj = new StockPrice();
		/// int param_2 = obj->current();
		/// int param_3 = obj->maximum();
		/// int param_4 = obj->minimum();
		class StockPrice {
			multiset<int> ms;
			map<int, int> m;

		public:
			StockPrice();
			void update(int timestamp, int price);
			[[nodiscard]] int current() const;
			[[nodiscard]] int maximum() const;
			[[nodiscard]] int minimum() const;
		};
	}// namespace stock_price_fluctuation

	/**
	 * \brief LeetCode 2045. 到达目的地的第二短时间
	 */
	namespace second_minimum_time_to_reach_destination {
		struct status {
			int position;
			int time;

			status(int position, int time)
			    : position(position), time(time){};
			bool operator<(const status &s) const;
		};

		class Solution {
		public:
			static int secondMinimum(int n, vector<vector<int>> &edges, int time, int change);
		};
	}// namespace second_minimum_time_to_reach_destination

	/// \brief LeetCode 1688. 比赛中的配对次数
	namespace count_of_matches_in_tournament {
		class Solution {
		public:
			static int numberOfMatches(int n);
		};
	}// namespace count_of_matches_in_tournament

	/// \brief LeetCode 2013. 检测正方形
	/// \details
	/// Your DetectSquares object will be instantiated and called as such:
	/// DetectSquares* obj = new DetectSquares();
	/// obj->add(point);
	/// int param_2 = obj->count(point);
	namespace detect_squares {
		class DetectSquares {
			multiset<pair<int, int>> ms;

		public:
			DetectSquares();
			void add(vector<int> point);
			int count(vector<int> point);
		};
	}// namespace detect_squares
};   // namespace leetcode

#endif//PROBLEMSCPP_LEETCODE_H
