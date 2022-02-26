#ifndef PROBLEMSCPP_LEETCODE_H
#define PROBLEMSCPP_LEETCODE_H

#include <array>
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
			[[nodiscard]] int count(vector<int> point) const;
		};
	}// namespace detect_squares

	/// \brief LeetCode 2047. 句子中的有效单词数
	namespace number_of_valid_words_in_a_sentence {
		class Solution {
		public:
			static int countValidWords(const string &sentence);
		};
	}// namespace number_of_valid_words_in_a_sentence

	/// \brief LeetCode 1996. 游戏中弱角色的数量
	namespace the_number_of_weak_characters_in_the_game {
		class Solution {
		public:
			static int numberOfWeakCharacters(vector<vector<int>> &properties);
		};
	}// namespace the_number_of_weak_characters_in_the_game

	/// \brief LeetCode 面试题 16.18. 模式匹配
	namespace pattern_matching_lcci {
		class Solution {
		public:
			static bool patternMatching(const string &pattern, const string &value);
		};
	}// namespace pattern_matching_lcci

	/**
	 * \brief LeetCode 1765. 地图中的最高点
	 */
	namespace map_of_highest_peak {
		class Solution {
		public:
			static vector<vector<int>> highestPeak(vector<vector<int>> &isWater);
		};
	}// namespace map_of_highest_peak

	/**
	 * \brief LeetCode 884. 两句话中的不常见单词
	 */
	namespace uncommon_words_from_two_sentences {
		class Solution {
		public:
			static vector<string> uncommonFromSentences(const string &s1, const string &s2);
		};
	}// namespace uncommon_words_from_two_sentences

	/**
	 * \brief LeetCode 5993. 将找到的值乘以 2
	 */
	namespace keep_multiplying_found_values_by_two {
		class Solution {
		public:
			static int findFinalValue(vector<int> &nums, int original);
		};
	}// namespace keep_multiplying_found_values_by_two

	/**
	 * \brief LeetCode 5981. 分组得分最高的所有下标
	 */
	namespace all_divisions_with_the_highest_score_of_a_binary_array {
		class Solution {
		public:
			static vector<int> maxScoreIndices(vector<int> &nums);
		};
	}// namespace all_divisions_with_the_highest_score_of_a_binary_array

	/**
	 * \brief LeetCode 5994. 查找给定哈希值的子串
	 */
	namespace find_substring_with_given_hash_value {
		class Solution {
		public:
			static string subStrHash(string s, int power, int modulo, int k, int hashValue);
		};
	}// namespace find_substring_with_given_hash_value

	/**
	 * \brief LeetCode 5995. 字符串分组
	 */
	namespace groups_of_strings {
		class Solution {
			int groups                                       = 0;
			unsigned int max_size                            = 1;
			unordered_map<unsigned int, unsigned int> parent = unordered_map<unsigned int, unsigned int>();
			unordered_map<unsigned int, unsigned int> rank   = unordered_map<unsigned int, unsigned int>();
			unordered_map<unsigned int, unsigned int> size   = unordered_map<unsigned int, unsigned int>();

		public:
			vector<int> groupStrings(vector<string> &words);
			static unsigned int compress(const string &word);
			void insert(unsigned int num);
			unsigned int find(unsigned int x);
			void to_union(unsigned int x1, unsigned int x2);
		};
	}// namespace groups_of_strings

	/// \brief LeetCode 1342. 将数字变成 0 的操作次数
	namespace number_of_steps_to_reduce_a_number_to_zero {
		class Solution {
		public:
			static int numberOfSteps(int num);
		};
	}// namespace number_of_steps_to_reduce_a_number_to_zero

	/// \brief LeetCode 1763. 最长的美好子字符串
	namespace longest_nice_substring {
		class Solution {
		public:
			static string longestNiceSubstring(const string &s);
			static pair<int, int> dfs(string s, int start, int end);
		};
	}// namespace longest_nice_substring

	/// \brief LeetCode 2000. 反转单词前缀
	namespace reverse_prefix_of_word {
		class Solution {
		public:
			static string reversePrefix(string word, char ch);
		};
	}// namespace reverse_prefix_of_word

	/**
	 * \brief LeetCode 1414. 和为 K 的最少斐波那契数字数目
	 */
	namespace find_the_minimum_number_of_fibonacci_numbers_whose_sum_is_k {
		class Solution {
		public:
			static int findMinFibonacciNumbers(int k);
			static int find_min(set<int, greater<>> &fibb, int k, set<int, greater<>>::iterator begin);
		};
	}// namespace find_the_minimum_number_of_fibonacci_numbers_whose_sum_is_k

	/// \brief LeetCode 1725. 可以形成最大正方形的矩形数目
	namespace number_of_rectangles_that_can_form_the_largest_square {
		class Solution {
		public:
			static int countGoodRectangles(vector<vector<int>> &rectangles);
		};
	}// namespace number_of_rectangles_that_can_form_the_largest_square

	/// \brief LeetCode 1219. Path with Maximum Gold
	namespace path_with_maximum_gold {
		class Solution {
		public:
			static int getMaximumGold(vector<vector<int>> &grid);
			static int get_sum(int current, int x, int y, int m, int n, vector<vector<int>> &grid, bool **occupied);
		};
	}// namespace path_with_maximum_gold

	/**
	 * \brief LeetCode 5984. 拆分数位后四位数字的最小和
	 */
	namespace minimum_sum_of_four_digit_number_after_splitting_digits {
		class Solution {
		public:
			static int minimumSum(int num);
		};
	}// namespace minimum_sum_of_four_digit_number_after_splitting_digits

	/**
	 * \brief LeetCode 5985. 根据给定数字划分数组
	 */
	namespace partition_array_according_to_given_pivot {
		class Solution {
		public:
			static vector<int> pivotArray(vector<int> &nums, int pivot);
		};
	}// namespace partition_array_according_to_given_pivot

	/**
	 * \brief LeetCode 5986. 设置时间的最少代价
	 */
	namespace minimum_cost_to_set_cooking_time {
		class Solution {
		public:
			static int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds);
			static int get_cost(int startAt, int moveCost, int pushCost, const int num[4]);
		};
	}// namespace minimum_cost_to_set_cooking_time

	/**
	 * \brief LeetCode 5987. 删除元素后和的最小差值
	 */
	namespace minimum_difference_in_sums_after_removal_of_elements {
		class Solution {
		public:
			static long long minimumDifference(vector<int> &nums);
		};
	}// namespace minimum_difference_in_sums_after_removal_of_elements

	/**
	 * \brief LeetCode 1748. 唯一元素的和
	 */
	namespace sum_of_unique_elements {
		class Solution {
		public:
			static int sumOfUnique(vector<int> &nums);
		};
	}// namespace sum_of_unique_elements

	/**
	 * \brief LeetCode 6000. 对奇偶下标分别排序
	 */
	namespace sort_even_and_odd_indices_independently {
		class Solution {
		public:
			static vector<int> sortEvenOdd(vector<int> &nums);
		};
	}// namespace sort_even_and_odd_indices_independently

	/**
	 * \brief LeetCode 6001. 重排数字的最小值
	 */
	namespace smallest_value_of_the_rearranged_number {
		class Solution {
		public:
			static long long smallestNumber(long long num);
		};
	}// namespace smallest_value_of_the_rearranged_number

	/**
	 * \brief LeetCode 6002. 设计位集
	 */
	namespace design_bitset {
		class Bitset {
			int size = 0;
			set<unsigned int> *one1;
			set<unsigned int> *zero0;

		public:
			/**
			 * \brief 用 size 个位初始化 Bitset ，所有位都是 0 。
			 */
			explicit Bitset(int size);
			/**
			 * \brief 将下标为 idx 的位上的值更新为 1 。如果值已经是 1 ，则不会发生任何改变。
			 */
			void fix(int idx) const;
			/**
			 * \brief 将下标为 idx 的位上的值更新为 0 。如果值已经是 0 ，则不会发生任何改变。
			 */
			void unfix(int idx) const;
			/**
			 * \brief 翻转 Bitset 中每一位上的值。换句话说，所有值为 0 的位将会变成 1 ，反之亦然。
			 */
			void flip();
			/**
			 * \brief 检查 Bitset 中 每一位 的值是否都是 1 。如果满足此条件，返回 true ；否则，返回 false 。
			 */
			[[nodiscard]] bool all() const;
			/**
			 * \brief 检查 Bitset 中 是否 至少一位 的值是 1 。如果满足此条件，返回 true ；否则，返回 false 。
			 */
			[[nodiscard]] bool one() const;
			/**
			 * \brief 返回 Bitset 中值为 1 的位的 总数 。
			 */
			[[nodiscard]] int count() const;
			/**
			 * \brief 返回 Bitset 的当前组成情况。注意，在结果字符串中，第 i 个下标处的字符应该与 Bitset 中的第 i 位一致。
			 */
			[[nodiscard]] string toString() const;
		};
	}// namespace design_bitset

	/// \brief LeetCode 1405. Longest Happy String
	namespace longest_happy_string {
		class Solution {
		public:
			static string longestDiverseString(int a, int b, int c);
			static void sort(char ch[3], int a, int b, int c);
			static int *get_p(char ch, int *a, int *b, int *c);
		};
	}// namespace longest_happy_string

	/// \brief LeetCode 1001. Grid Illumination
	namespace grid_illumination {
		struct pair_hash {
			unsigned long long operator()(const pair<int, int> & /*p*/) const;
		};

		class Solution {
		public:
			static vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries);
		};
	}// namespace grid_illumination

	/// \brief LeetCode 2006. Count Number of Pairs With Absolute Difference K
	namespace count_number_of_pairs_with_absolute_difference_k {
		class Solution {
		public:
			static int countKDifference(vector<int> &nums, int k);
		};
	}// namespace count_number_of_pairs_with_absolute_difference_k

	/// \brief LeetCode 1447. Simplified Fractions
	namespace simplified_fractions {
		class Solution {
		public:
			static vector<string> simplifiedFractions(int n);
			static int gcd(int m, int n);
		};
	}// namespace simplified_fractions

	/**
	 * \brief LeetCode 1984. Minimum Difference Between Highest and Lowest of K Scores
	 */
	namespace minimum_difference_between_highest_and_lowest_of_k_scores {
		class Solution {
		public:
			static int minimumDifference(vector<int> &nums, int k);
		};
	}// namespace minimum_difference_between_highest_and_lowest_of_k_scores

	/// \brief LeetCode 1020. Number of Enclaves
	namespace number_of_enclaves {
		class Solution {
		public:
			static int numEnclaves(vector<vector<int>> &grid);
		};
	}// namespace number_of_enclaves

	/**
	 * \brief LeetCode 1189. “气球” 的最大数量
	 */
	namespace maximum_number_of_balloons {
		class Solution {
		public:
			static int maxNumberOfBalloons(const string &text);
		};
	}// namespace maximum_number_of_balloons

	/**
	 * \brief LeetCode 777. 在LR字符串中交换相邻字符
	 */
	namespace swap_adjacent_in_lr_string {
		class Solution {
		public:
			static bool canTransform(const string &start, const string &end);
		};
	}// namespace swap_adjacent_in_lr_string

	/**
	 * \brief LeetCode 6004. 得到 0 的操作数
	 */
	namespace count_operations_to_obtain_zero {
		class Solution {
		public:
			static int countOperations(int num1, int num2);
		};
	}// namespace count_operations_to_obtain_zero

	/**
	 * \brief LeetCode 6005. 使数组变成交替数组的最少操作数
	 */
	namespace minimum_operations_to_make_the_array_alternating {
		class Solution {
		public:
			static int minimumOperations(vector<int> &nums);
		};
	}// namespace minimum_operations_to_make_the_array_alternating

	/**
	 * \brief LeetCode 6006. 拿出最少数目的魔法豆
	 */
	namespace removing_minimum_number_of_magic_beans {
		class Solution {
		public:
			static long long minimumRemoval(vector<int> &beans);
		};
	}// namespace removing_minimum_number_of_magic_beans

	/**
	 * \brief LeetCode 6007. 数组的最大与和
	 */
	namespace maximum_and_sum_of_array {
		class Solution {
		public:
			static int maximumANDSum(vector<int> &nums, int numSlots);
		};
	}// namespace maximum_and_sum_of_array

	/// \brief LeetCode 540. Single Element in a Sorted Array
	namespace single_element_in_a_sorted_array {
		class Solution {
		public:
			static int singleNonDuplicate(vector<int> &nums);
		};
	}// namespace single_element_in_a_sorted_array


	/// \brief LeetCode 1380. Lucky Numbers in a Matrix
	namespace lucky_numbers_in_a_matrix {
		class Solution {
		public:
			static vector<int> luckyNumbers(vector<vector<int>> &matrix);
		};
	}// namespace lucky_numbers_in_a_matrix

	/// \brief LeetCode 1719. Number Of Ways To Reconstruct A Tree
	namespace number_of_ways_to_reconstruct_a_tree {
		class Solution {
		public:
			static int checkWays(vector<vector<int>> &pairs);
		};
	}// namespace number_of_ways_to_reconstruct_a_tree

	/// \brief LeetCode 1791. Find Center of Star Graph
	namespace find_center_of_star_graph {
		class Solution {
		public:
			static int findCenter(vector<vector<int>> &edges);
		};
	}// namespace find_center_of_star_graph

	/// \brief LeetCode 688. Knight Probability in Chessboard
	namespace knight_probability_in_chessboard {
		struct status {
			int k;
			int row;
			int column;

			status(int k, int row, int column)
			    : k(k), row(row), column(column){};
		};

		struct status_hash {
			unsigned int operator()(const status & /*s*/) const;
		};

		struct status_equal {
			bool operator()(const status & /*s1*/, const status & /*s2*/) const;
		};

		class Solution {
			unordered_map<status, double, status_hash, status_equal> um = unordered_map<status, double, status_hash, status_equal>();

		public:
			double knightProbability(int n, int k, int row, int column);
		};
	}// namespace knight_probability_in_chessboard

	/// \brief LeetCode 969. Pancake Sorting
	namespace pancake_sorting {
		class Solution {
		public:
			static vector<int> pancakeSort(vector<int> &arr);
		};
	}// namespace pancake_sorting

	/// \brief LeetCode 5996. 统计数组中相等且可以被整除的数对
	namespace count_equal_and_divisible_pairs_in_an_array {
		class Solution {
		public:
			static int countPairs(vector<int> &nums, int k);
		};
	}// namespace count_equal_and_divisible_pairs_in_an_array

	/// \brief LeetCode 5997. 找到和为给定整数的三个连续整数
	namespace find_three_consecutive_integers_that_sum_to_a_given_number {
		class Solution {
		public:
			static vector<long long> sumOfThree(long long num);
		};
	}// namespace find_three_consecutive_integers_that_sum_to_a_given_number

	/// \brief LeetCode 5998. 拆分成最多数目的偶整数之和
	namespace maximum_split_of_positive_even_integers {
		class Solution {
		public:
			static vector<long long> maximumEvenSplit(long long finalSum);
		};
	}// namespace maximum_split_of_positive_even_integers

	/// \brief LeetCode 5999. 统计数组中好三元组数目
	namespace count_good_triplets_in_an_array {
		template<class T> class FenwickTree {
			int limit{};
			vector<T> arr;

			static int lowbit(int x) { return x & -x; }

		public:
			explicit FenwickTree(int limit) {
				this->limit = limit;
				arr         = vector<T>(limit + 1);
			}

			void update(int idx, T delta) {
				for(; idx <= limit; idx += lowbit(idx)) {
					arr[idx] += delta;
				}
			}

			T query(int idx) {
				T ans = 0;
				for(; idx > 0; idx -= lowbit(idx)) {
					ans += arr[idx];
				}
				return ans;
			}
		};

		class Solution {
		public:
			static long long goodTriplets(vector<int> &nums1, vector<int> &nums2);
		};
	}// namespace count_good_triplets_in_an_array

	/// \brief LeetCode 6012. 统计各位数字之和为偶数的整数个数
	namespace count_integers_with_even_digit_sum {
		class Solution {
		public:
			static int countEven(int num);
		};
	}// namespace count_integers_with_even_digit_sum

	/// \brief LeetCode 6013. 合并零之间的节点
	namespace merge_nodes_in_between_zeros {
		class Solution {
		public:
			static ListNode *mergeNodes(ListNode *head);
		};
	}// namespace merge_nodes_in_between_zeros

	/// \brief LeetCode 6014. 构造限制重复的字符串
	namespace construct_string_with_repeat_limit {
		class Solution {
		public:
			static string repeatLimitedString(const string &s, int repeatLimit);
		};
	}// namespace construct_string_with_repeat_limit

	/// \brief LeetCode 6015. 统计可以被 K 整除的下标对数目
	namespace count_array_pairs_divisible_by_k {
		class Solution {
		public:
			static long long coutPairs(vector<int> &nums, int k);
		};
	}// namespace count_array_pairs_divisible_by_k

	/**
	 * \brief LeetCode 717. 1比特与2比特字符
	 */
	namespace leetcode717_1_bit_and_2_bit_characters {
		class Solution {
		public:
			static bool isOneBitCharacter(vector<int> &bits);
		};
	}// namespace leetcode717_1_bit_and_2_bit_characters

	/**
	 * \brief LeetCode 845. 数组中的最长山脉
	 */
	namespace longest_mountain_in_array {
		class Solution {
		public:
			static int longestMountain(vector<int> &arr);
		};
	}// namespace longest_mountain_in_array

	/// \brief LeetCode 838. 推多米诺
	namespace push_dominoes {
		class Solution {
		public:
			static string pushDominoes(string dominoes);
		};
	}// namespace push_dominoes

	/// \brief LeetCode 1994. 好子集的数目
	namespace the_number_of_good_subsets {
		class Solution {
		private:
			static constexpr array<int, 10> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
			static constexpr int num_max           = 30;
			static constexpr int mod               = 1000000007;
			static constexpr int mask_max          = 1 << primes.size();

		public:
			static int numberOfGoodSubsets(vector<int> &nums);
		};
	}// namespace the_number_of_good_subsets

	/// \brief LeetCode 917. Reverse Only Letters
	namespace reverse_only_letters {
		class Solution {
		public:
			static string reverseOnlyLetters(string s);
		};
	}// namespace reverse_only_letters

	/// \brief LeetCode 1706. Where Will the Ball Fall
	namespace where_will_the_ball_fall {
		class Solution {
		public:
			static vector<int> findBall(vector<vector<int>> &grid);
		};
	}// namespace where_will_the_ball_fall

	/// \brief LeetCode 537. Complex Number Multiplication
	namespace complex_number_multiplication {
		class Solution {
		public:
			static string complexNumberMultiply(string num1, string num2);
		};
	}// namespace complex_number_multiplication

	/// \brief LeetCode 2016. Maximum Difference Between Increasing Elements
	namespace maximum_difference_between_increasing_elements {
		class Solution {
		public:
			static int maximumDifference(vector<int> &nums);
		};
	}// namespace maximum_difference_between_increasing_elements
};   // namespace leetcode

#endif//PROBLEMSCPP_LEETCODE_H
