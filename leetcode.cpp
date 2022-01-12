#include "leetcode.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_set>

using namespace std;

namespace leetcode {
	bool TreeNode::operator==(const TreeNode &node) const {
		if(this->left != nullptr && node.left == nullptr) {
			return false;
		}
		if(this->left == nullptr && node.left != nullptr) {
			return false;
		}
		if(this->right != nullptr && node.right == nullptr) {
			return false;
		}
		if(this->right == nullptr && node.right != nullptr) {
			return false;
		}
		if(this->left != nullptr && node.left != nullptr && *this->left != *node.left) {
			return false;
		}
		if(this->right != nullptr && node.right != nullptr && *this->right != *node.right) {
			return false;
		}
		return this->val == node.val;
	}

	bool TreeNode::operator!=(const TreeNode &node) const { return !(*this == node); }

	namespace concatenated_words {
		vector<string> Solution::findAllConcatenatedWordsInADict(vector<string> &words) {
			sort(words.begin(), words.end(), [&](const string &a, const string &b) { return a.size() < b.size(); });
			auto ans  = vector<string>();
			auto node = TrieNode(0);
			for(const string &word: words) {
				if(word.length() == 0) {
					continue;
				}
				if(node.dfs(&node, word, 0, false)) {
					ans.push_back(word);
				} else {
					node.insert(word);
				}
			}
			return ans;
		}

		TrieNode::TrieNode(char ch) {
			this->ch     = ch;
			this->is_end = false;
		}

		void TrieNode::insert(const string &str) {
			auto *node = this->nexts[str[0] - 'a'];
			if(node == nullptr) {
				node                      = new TrieNode(str[0]);
				this->nexts[str[0] - 'a'] = node;
			}
			if(str.length() == 1) {
				node->is_end = true;
				return;
			}
			return node->insert(str.substr(1));
		}

		bool TrieNode::dfs(TrieNode *root, const string &str, int start, bool flag) const {
			if(this->ch == 0) {
				//根节点
				auto *const node = this->nexts[str[start] - 'a'];
				if(node == nullptr) {
					return false;
				}
				return node->dfs(root, str, start, flag);
			}
			//非根节点
			//到一个单词结束处
			if(this->is_end) {
				if(start == str.length() - 1) {
					return flag;
				}
				const auto res = root->dfs(root, str, start + 1, true);
				if(res) {
					return true;
				}
			}
			TrieNode *node = nullptr;
			if(str[start + 1] - 'a' >= 0) {
				node = this->nexts[str[start + 1] - 'a'];
			}
			return node != nullptr && node->dfs(root, str, start + 1, flag);
		}
	}// namespace concatenated_words

	namespace excel_sheet_column_number {
		int Solution::titleToNumber(const std::string &columnTitle) {
			int sum    = 0;
			int length = static_cast<int>(columnTitle.length());
			for(const char c: columnTitle) {
				sum += static_cast<int>(static_cast<double>(c - 'A' + 1) * pow(26, length-- - 1));
			}
			return sum;
		}
	}// namespace excel_sheet_column_number

	namespace excel_sheet_column_title {
		string Solution::convertToTitle(int columnNumber) {
			auto ans   = string();
			bool round = false;
			while(columnNumber != 0) {
				char ch = 0;
				if(round) {
					ch    = static_cast<char>(columnNumber % 26 + 63);
					round = false;
				} else {
					ch = static_cast<char>(columnNumber % 26 + 64);
				}
				if(ch == '@' && columnNumber >= 26) {
					ch    = 'Z';
					round = true;
				} else if(ch == '?' && columnNumber >= 26) {
					ch    = 'Y';
					round = true;
				}
				if('A' <= ch && ch <= 'Z') {
					ans.insert(0, 1, ch);
				}
				columnNumber /= 26;
			}
			return ans;
		}
	}// namespace excel_sheet_column_title

	namespace majority_element {
		Solution::Solution() { this->m = std::map<int, int>(); }

		int Solution::majorityElement(vector<int> &nums) {
			for(int i: nums) {
				if(m.contains(i)) {
					m[i] = m[i] + 1;
					if(m[i] > nums.size() / 2) {
						return i;
					}
				} else {
					m[i] = 1;
				}
			}
			return 0;
		}
	}// namespace majority_element

	namespace count_special_quadruplets {
		int Solution::countQuadruplets(vector<int> &nums) {
			int sum = 0;
			for(int i = 3; i < nums.size(); i++) {
				for(int j = 0; j < i - 2; j++) {
					if(j == i) {
						continue;
					}
					for(int k = j + 1; k < i - 1; k++) {
						if(k == i) {
							continue;
						}
						for(int l = k + 1; l < i; l++) {
							if(l == i) {
								continue;
							}
							if(nums[k] + nums[j] + nums[l] == nums[i]) {
								sum++;
							}
						}
					}
				}
			}
			return sum;
		}
	}// namespace count_special_quadruplets

	namespace hand_of_straights {
		bool Solution::isNStraightHand(vector<int> &hand, int groupSize) {
			if(hand.size() % groupSize != 0) {
				return false;
			}
			if(groupSize == 1) {
				return true;
			}
			sort(hand.begin(), hand.end());
			const auto len = hand.size() / groupSize;
			for(int i = 0; i < len; i++) {
				int current = *hand.begin();
				hand.erase(hand.begin());
				for(int j = 1; j < groupSize; j++) {
					auto next = find(hand.begin(), hand.end(), current + 1);
					if(next == hand.end()) {
						return false;
					}
					current = *next;
					hand.erase(next);
				}
			}
			return true;
		}
	}// namespace hand_of_straights

	namespace perfect_number {
		bool Solution::checkPerfectNumber(int num) {
			int sum = 0;
			int max = num;
			for(int i = 1; i < max; i++) {
				if(num % i == 0) {
					sum += i;
					if(i != 1) {
						sum += num / i;
					}
					max = num / i;
				}
			}
			return sum == num;
		}
	}// namespace perfect_number

	namespace convert_bst_to_greater_tree {
		TreeNode *Solution::convertBST(TreeNode *root) {
			if(root == nullptr) {
				return nullptr;
			}
			FriendTreeNode *sum = copy(root);
			get_sum(sum);
			sum->val = sum->sum - (sum->left == nullptr ? 0 : sum->left->sum);
			convert(sum);
			return root;
		}

		FriendTreeNode *Solution::copy(TreeNode *node) {
			auto *ret = new FriendTreeNode(node->val, node);
			if(node->left != nullptr) {
				ret->left = copy(node->left);
			}
			if(node->right != nullptr) {
				ret->right = copy(node->right);
			}
			return ret;
		}

		void Solution::get_sum(FriendTreeNode *node) {
			if(node->left != nullptr) {
				get_sum(node->left);
				node->sum += node->left->sum;
			}
			if(node->right != nullptr) {
				get_sum(node->right);
				node->sum += node->right->sum;
			}
		}

		void Solution::convert(FriendTreeNode *sum_node) {
			if(sum_node->right != nullptr) {
				sum_node->right->val = sum_node->val - sum_node->friend_node->val -
				                       (sum_node->right->left == nullptr ? 0 : sum_node->right->left->sum);
				convert(sum_node->right);
			}
			if(sum_node->left != nullptr) {
				sum_node->left->val = sum_node->val + sum_node->left->friend_node->val +
				                      (sum_node->left->right == nullptr ? 0 : sum_node->left->right->sum);
				convert(sum_node->left);
			}
			sum_node->friend_node->val = sum_node->val;
		}
	}// namespace convert_bst_to_greater_tree

	namespace convert_1d_array_into_2d_array {
		vector<vector<int>> Solution::construct2DArray(vector<int> &original, int m, int n) {
			if(original.size() != m * n) {
				return {};
			}
			auto ans  = vector<vector<int>>();
			int count = 0;
			for(int i = 0; i < m; i++) {
				auto row = vector<int>();
				for(int j = 0; j < n; j++) {
					row.push_back(original[count++]);
				}
				ans.push_back(row);
			}
			return ans;
		}
	}// namespace convert_1d_array_into_2d_array

	namespace elimination_game {
		int Solution::lastRemaining(int n) {
			int num_amount = n;
			int loop_cnt   = 0;
			int a0         = 1;//初项
			int d          = 1;//差
			while(num_amount != 1) {
				//剩下的数目不为1时
				if(num_amount % 2 == 1) {
					// 奇数个数字
					a0 = a0 + d;
				} else if(num_amount % 2 == 0) {
					// 偶数个数字
					const bool left_to_right = loop_cnt % 2 == 0;
					if(left_to_right) {
						a0 = a0 + d;
					} else {
						a0 = a0;
					}
				}
				loop_cnt++;
				d *= 2;
				num_amount /= 2;
			}
			return a0;
		}
	}// namespace elimination_game

	namespace check_if_all_as_appears_before_all_bs {
		bool Solution::checkString(const string &s) {
			bool flag = true;
			for(const char ch: s) {
				if(ch == 'a') {
					if(!flag) {
						return false;
					}
				} else if(ch == 'b') {
					flag = false;
				}
			}
			return true;
		}
	}// namespace check_if_all_as_appears_before_all_bs

	namespace number_of_laser_beams_in_a_bank {
		int Solution::numberOfBeams(vector<string> &bank) {
			if(bank.size() == 1) {
				return 0;
			}
			int count   = 0;
			int i       = 0;
			int count_i = deviceCount(bank[i]);
			int j       = 1;
			while(i < j && i < bank.size() && j < bank.size()) {
				if(deviceCount(bank[j]) == 0) {
					j++;
					continue;
				}
				const int count_j = deviceCount(bank[j]);
				count += count_i * count_j;
				count_i = count_j;
				i       = j;
				j++;
			}
			return count;
		}

		int Solution::deviceCount(const string &str) {
			int count = 0;
			for(const char c: str) {
				if(c == '1') {
					count++;
				}
			}
			return count;
		}
	}// namespace number_of_laser_beams_in_a_bank

	namespace destroying_asteroids {
		bool Solution::asteroidsDestroyed(int mass, vector<int> &asteroids) {
			long long m = mass;
			sort(asteroids.begin(), asteroids.end());
			for(const int i: asteroids) {
				if(m < i) {
					return false;
				}
				m += i;
			}
			return true;
		}
	}// namespace destroying_asteroids

	/*namespace maximum_employees_to_be_invited_to_a_meeting {
		int Solution::maximumInvitations(vector<int>& favorite) {
			int n = static_cast<int>(favorite.size());
			vector<vector<int >> g(n), rg(n); // rg 为图 g 的反图
			vector<int> deg(n); // 图 g 上每个节点的入度
			for (int v = 0; v < n; ++v) {
				int w = favorite[v];
				g[v].emplace_back(w);
				rg[w].emplace_back(v);
				++deg[w];
			}

			// 拓扑排序，剪掉图 g 上的所有树枝
			queue<int> q;
			for (int i = 0; i < n; ++i) {
				if (deg[i] == 0) {
					q.emplace(i);
				}
			}
			while (!q.empty()) {
				int v = q.front();
				q.pop();
				for (int w : g[v]) {
					if (--deg[w] == 0) {
						q.emplace(w);
					}
				}
			}

			// 寻找图 g 上的基环
			vector<int> ring;
			vector<int> vis(n);

			function<void(int)> dfs = [&](int v) {
				vis[v] = true;
				ring.emplace_back(v);
				for (int w : g[v]) {
					if (!vis[w]) {
						dfs(w);
					}
				}
			};

			// 通过反图 rg 寻找树枝上最深的链
			int max_depth = 0;

			function<void(int, int, int)> rdfs = [&](int v, int fa, int depth) {
				max_depth = max(max_depth, depth);
				for (int w : rg[v]) {
					if (w != fa) {
						rdfs(w, v, depth + 1);
					}
				}
			};

			int max_ring_size = 0, sum_chian_size = 0;
			for (int i = 0; i < n; ++i) {
				if (!vis[i] && deg[i]) { // 遍历基环上的点（拓扑排序后入度不为 0）
					ring.resize(0);
					dfs(i);
					int sz = static_cast<int>(ring.size());
					if (sz == 2) { // 基环大小为 2
						int v = ring[0], w = ring[1];
						max_depth = 0;
						rdfs(v, w, 1);
						sum_chian_size += max_depth; // 累加 v 这一侧的最长链的长度
						max_depth = 0;
						rdfs(w, v, 1);
						sum_chian_size += max_depth; // 累加 w 这一侧的最长链的长度
					}
					else {
						max_ring_size = max(max_ring_size, sz); // 取所有基环的最大值
					}
				}
			}
			return max(max_ring_size, sum_chian_size);
		}
	}*/
	/**
	 * \brief LeetCode 1185. 一周中的第几天
	 */
	namespace day_of_the_week {
		string Solution::dayOfTheWeek(int day, int month, int year) {
			const string output[]   = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
			const int dayofmonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			int count               = 5;
			count += (year - 1971) * 365;
			count += (year - 1) / 4 - 1970 / 4;
			for(int m = 0; m < month - 1; m++) {
				count += dayofmonths[m];
			}
			if(month > 2 && year % 4 == 0 && year % 100 != 0) {
				count++;
			}
			count += day - 1;
			count %= 7;
			return output[count];
		}
	}// namespace day_of_the_week

	namespace cat_and_mouse {
		int Solution::catMouseGame(vector<vector<int>> &graph) {
			this->n     = graph.size();
			this->graph = graph;
			memset(dp, -1, sizeof dp);
			return getResult(1, 2, 0);
		}

		int Solution::getResult(int mouse, int cat, int turns) {
			if(turns == n * 2) {
				return DRAW;
			}
			if(dp[mouse][cat][turns] < 0) {
				if(mouse == 0) {
					dp[mouse][cat][turns] = MOUSE_WIN;
				} else if(cat == mouse) {
					dp[mouse][cat][turns] = CAT_WIN;
				} else {
					getNextResult(mouse, cat, turns);
				}
			}
			return dp[mouse][cat][turns];
		}

		void Solution::getNextResult(int mouse, int cat, int turns) {
			const int curMove       = turns % 2 == 0 ? mouse : cat;
			const int defaultResult = curMove == mouse ? CAT_WIN : MOUSE_WIN;
			int result              = defaultResult;
			for(int next: graph[curMove]) {
				if(curMove == cat && next == 0) {
					continue;
				}
				const int nextMouse  = curMove == mouse ? next : mouse;
				const int nextCat    = curMove == cat ? next : cat;
				const int nextResult = getResult(nextMouse, nextCat, turns + 1);
				if(nextResult != defaultResult) {
					result = nextResult;
					if(result != DRAW) {
						break;
					}
				}
			}
			dp[mouse][cat][turns] = result;
		}
	}// namespace cat_and_mouse

	namespace replace_all_s_to_avoid_consecutive_repeating_characters {
		string Solution::modifyString(string s) {
			for(int i = 0; i < s.size(); i++) {
				if(s[i] == '?') {
					for(char ch = 'a'; ch < 'z' + 1; ch++) {
						if(0 <= i - 1 && s[i - 1] == ch) {
							continue;
						}
						if(i + 1 < s.size() && s[i + 1] == ch) {
							continue;
						}
						s[i] = ch;
						break;
					}
				}
			}
			return s;
		}
	}// namespace replace_all_s_to_avoid_consecutive_repeating_characters

	namespace simplify_path {
		string Solution::simplifyPath(const string &path) {
			auto *const str_cpy = new char[path.size() + 1];
			memcpy(str_cpy, path.c_str(), path.size() + 1);
			auto *next = strtok(str_cpy, "/");
			auto stck  = deque<string>();
			while(next != nullptr) {
				auto nextstr = string(next);
				if(nextstr == "..") {
					if(!stck.empty()) {
						stck.pop_back();
					}
					next = strtok(nullptr, "/");
					continue;
				}
				if(nextstr == ".") {
					next = strtok(nullptr, "/");
					continue;
				}
				stck.emplace_back(next);
				next = strtok(nullptr, "/");
			}
			auto oss = ostringstream();
			if(stck.empty()) {
				oss << '/';
			} else {
				while(!stck.empty()) {
					auto pname = stck.front();
					oss << '/' << pname;
					stck.pop_front();
				}
			}

			return oss.str();
		}
	}// namespace simplify_path

	namespace maximum_nesting_depth_of_the_parentheses {
		int Solution::maxDepth(const string &s) {
			int max     = 0;
			int current = 0;
			for(const char ch: s) {
				if(ch == '(') {
					current++;
				} else if(ch == ')') {
					current--;
				}
				if(max < current) {
					max = current;
				}
			}
			return max;
		}
	}// namespace maximum_nesting_depth_of_the_parentheses

	namespace gray_code {
		vector<int> Solution::grayCode(int n) {
			vector<int> ret(1 << n);
			for(int i = 0; i < ret.size(); i++) {
				ret[i] = i >> 1 ^ i;
			}
			return ret;
		}
	}// namespace gray_code

	namespace check_if_every_row_and_column_contains_all_numbers {
		bool Solution::checkValid(vector<vector<int>> &matrix) {
			const unsigned int n = matrix.size();
			for(int i = 0; i < n; i++) {
				auto *const row = new bool[n + 1];
				memset(row, 1, (n + 1) * sizeof(bool));
				for(int j = 0; j < n; j++) {
					if(!row[matrix[i][j]]) {
						return false;
					}
					row[matrix[i][j]] = false;
				}
				delete[] row;
			}

			for(int j = 0; j < n; j++) {
				auto *const column = new bool[n + 1];
				memset(column, 1, (n + 1) * sizeof(bool));
				for(int i = 0; i < n; i++) {
					if(!column[matrix[i][j]]) {
						return false;
					}
					column[matrix[i][j]] = false;
				}
				delete[] column;
			}
			return true;
		}
	}// namespace check_if_every_row_and_column_contains_all_numbers

	namespace minimum_swaps_to_group_all_1s_together_ii {
		int Solution::minSwaps(vector<int> &nums) {
			int onecount = 0;
			for(int i = 0; i < nums.size(); i++) {
				if(nums[i] == 1) {
					onecount++;
				}
			}
			if(onecount == 0) {
				return 0;
			}

			int zerocount = 0;
			for(int i = 0; i < onecount; i++) {
				if(nums[i] == 0) {
					zerocount++;
				}
			}
			int min = zerocount;

			for(int i = 0; i < nums.size(); i++) {
				if(nums[i] == 0) {
					zerocount--;
				}
				if(nums[(onecount + i) % nums.size()] == 0) {
					zerocount++;
				}
				if(zerocount < min) {
					min = zerocount;
				}
			}
			return min;
		}
	}// namespace minimum_swaps_to_group_all_1s_together_ii

	namespace count_words_obtained_after_adding_a_letter {
		int Solution::wordCount(vector<string> &startWords,
		                        vector<string> &targetWords) {
			int count  = 0;
			auto start = unordered_set<unsigned int>();
			for(const string &word: startWords) {
				auto bin = str2bin(word);
				start.insert(bin);
			}
			for(const string &word: targetWords) {
				auto bin = str2bin(word);
				for(int i = 0; i < 26; i++) {
					if((bin & 1 << i) != 0 && start.contains(bin - (1 << i))) {
						//bin有第i个字母且bin去掉第i个字母在start中仍然存在
						count++;
						break;
					}
				}
			}
			return count;
		}

		unsigned int Solution::str2bin(const string &str) {
			unsigned int ret = 0;
			for(const char ch: str) {
				ret |= 1 << ch - 'a';
			}
			return ret;
		}
	}// namespace count_words_obtained_after_adding_a_letter

	namespace slowest_key {
		char Solution::slowestKey(vector<int> &releaseTimes, string keysPressed) {
			int max  = releaseTimes[0];
			int maxi = 0;
			for(int i = 1; i < releaseTimes.size(); i++) {
				const int time = releaseTimes[i] - releaseTimes[i - 1];
				if(max < time) {
					max  = time;
					maxi = i;
				} else if(max == time) {
					if(keysPressed[i] > keysPressed[maxi]) {
						maxi = i;
					}
				}
			}
			return keysPressed[maxi];
		}
	}// namespace slowest_key

	namespace additive_number {
		bool Solution::isAdditiveNumber(string num) {
			if(num.length() < 3) {
				return false;
			}
			auto *const nums = new char[num.length()];
			for(int i = 0; i < num.length(); i++) {
				nums[i] = num[i];
			}
			for(int i = 1; i <= num.length() - i; i++) {
				const auto n1 = str2ui(nums, 0, i);
				for(int j = i + 1; j - i <= num.length() - j; j++) {
					const auto n2 = str2ui(nums, i, j - i);
					if(dfs(n1, n2, nums, num.length(), j)) {
						return true;
					}
					if(n2 == 0) {
						break;
					}
				}
				if(n1 == 0) {
					break;
				}
			}
			return false;
		}

		bool Solution::dfs(unsigned long long n1, unsigned long long n2, const char *nums, unsigned short length, unsigned short current) {
			const auto sum = to_string(n1 + n2);
			if(sum.length() > length - current) {
				//前两位和的位数超过剩余的位数
				return false;
			}
			if(!equal(sum, nums, current, length)) {
				//不包含下一个数字
				return false;
			}
			if(current + sum.length() == length) {
				//终止条件
				return true;
			}
			const auto n3 = str2ui(nums, current, sum.length());
			return dfs(n2, n3, nums, length, current + sum.length());
		}

		unsigned long long Solution::str2ui(const char *str, unsigned short start, unsigned short length) {
			unsigned long long ans = 0;
			for(int i = start; i < start + length; i++) {
				ans *= 10;
				ans += str[i] - '0';
			}
			return ans;
		}

		bool Solution::equal(string sum, const char *nums, unsigned short start, unsigned short length) {
			int j = 0;
			for(int i = start; j < sum.length() && i < length; i++, j++) {
				if(sum[j] != nums[i]) {
					return false;
				}
			}
			return j == sum.length();
		}
	}// namespace additive_number

	namespace decode_the_slanted_ciphertext {
		string Solution::decodeCiphertext(string encodedText, int rows) {
			if(encodedText.empty()) {
				return "";
			}
			const int columns = encodedText.length() / rows;
			auto *const table = new char *[rows];
			for(int i = 0; i < rows; i++) {
				table[i] = new char[columns - rows + 2];
				for(int j = i; j - i < columns - rows + 2; j++) {
					if(i * columns + j < encodedText.length()) {
						table[i][j - i] = encodedText[i * columns + j];
					} else {
						table[i][j - i] = ' ';
					}
				}
			}
			auto oss = ostringstream();
			for(int j = 0; j < columns - rows + 2; j++) {
				for(int i = 0; i < rows; i++) {
					oss << table[i][j];
				}
			}
			string ans = oss.str();
			return rtrim(ans);
		}

		string Solution::rtrim(string &s) {
			for(int i = s.length() - 1; i >= 0; i--) {
				if(s[i] != ' ') {
					string ans = s.substr(0, i + 1);
					return ans;
				}
			}
			return s;
		}
	}// namespace decode_the_slanted_ciphertext

	namespace escape_a_large_maze {
		bool Solution::isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target) {
			const int limit = blocked.size() * (blocked.size() - 1) / 2;
			if(blocked.empty()) {
				return true;
			}
			auto *p_source          = new point(source[0], source[1], 0, nullptr);
			auto *p_target          = new point(target[0], target[1], 0, nullptr);
			auto blocked_set_source = unordered_set<point, point_hash>();
			auto blocked_set_target = unordered_set<point, point_hash>();
			for(auto block: blocked) {
				blocked_set_source.insert(point(block[0], block[1], 0, nullptr));
				blocked_set_target.insert(point(block[0], block[1], 0, nullptr));
			}
			const unsigned int source_status = search(blocked_set_source, p_source, p_target, limit);
			if(source_status == 0) {
				return false;
			}
			if(source_status == 1) {
				return true;
			}
			const unsigned int target_status = search(blocked_set_target, p_target, p_source, limit);
			return target_status != 0;
		}

		unsigned int Solution::search(unordered_set<point, point_hash> &block_set, point *source, point *target, unsigned int limit) {
			auto pq = priority_queue<point>();
			pq.push(point(source->x, source->y, 0, target));
			int count = 0;
			while(!pq.empty()) {
				if(count > limit || pq.size() > limit) {
					return 2;//不包围
				}
				count++;
				const auto p = pq.top();
				pq.pop();
				point nexts[] = {point(p.x + 1, p.y, p.distance + 1, target), point(p.x - 1, p.y, p.distance + 1, target), point(p.x, p.y + 1, p.distance + 1, target), point(p.x, p.y - 1, p.distance + 1, target)};
				for(auto next: nexts) {
					if(0 <= next.x && next.x < 1000000 && 0 <= next.y && next.y < 1000000 && !block_set.contains(next)) {
						if(next.x == target->x && next.y == target->y) {
							return 1;//连通
						}
						pq.push(next);
						block_set.insert(next);
					}
				}
			}
			return 0;//不连通
		}

		bool point::operator<(const point &p) const { return this->distance + (abs(static_cast<int>(this->x - target->x)) + abs(static_cast<int>(this->y - target->y))) < p.distance + (abs(static_cast<int>(p.x - target->x)) + abs(static_cast<int>(p.y - target->y))); }
		bool point::operator==(const point &p) const { return this->x == p.x && this->y == p.y; }

		size_t point_hash::operator()(const point &p) const { return p.x * 1000000 + p.y; }
	}// namespace escape_a_large_maze
}// namespace leetcode
