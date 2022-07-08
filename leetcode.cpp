#include "leetcode.h"
#include "templates.h"
#include <algorithm>
#include <bit>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstring>
#include <numeric>
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
				const auto *const node = this->nexts[str[start] - 'a'];
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
			const TrieNode *node = nullptr;
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
			if(original.size() != static_cast<unsigned long long>(m) * static_cast<unsigned long long>(n)) {
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
			delete[] str_cpy;
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
						delete[] row;
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
						delete[] column;
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
			for(const int num: nums) {
				if(num == 1) {
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
				const auto bin = str2bin(word);
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
			delete[] nums;
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
			for(int i = 0; i < rows; i++) {
				delete[] table[i];
			}
			delete[] table;
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
			delete p_source;
			delete p_target;
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

	namespace increasing_triplet_subsequence {
		bool Solution::increasingTriplet(vector<int> &nums) {
			if(nums.size() < 3) {
				return false;
			}
			auto *min            = new int[nums.size()];
			auto *max            = new int[nums.size()];
			min[0]               = nums[0];
			max[nums.size() - 1] = nums[nums.size() - 1];
			for(int i = 1, j = nums.size() - 2; i < nums.size() && j >= 0; i++, j--) {
				if(min[i - 1] > nums[i]) {
					min[i] = nums[i];
				} else {
					min[i] = min[i - 1];
				}

				if(max[j + 1] < nums[j]) {
					max[j] = nums[j];
				} else {
					max[j] = max[j + 1];
				}
			}
			for(int i = 0; i < nums.size(); i++) {
				if(nums[i] > min[i] && nums[i] < max[i]) {
					delete[] min;
					delete[] max;
					return true;
				}
			}
			delete[] min;
			delete[] max;
			return false;
		}
	}// namespace increasing_triplet_subsequence

	namespace largest_number_at_least_twice_of_others {
		int Solution::dominantIndex(vector<int> &nums) {
			if(nums.size() < 2) {
				return 0;
			}
			unsigned int max;
			unsigned int index;
			unsigned int second;
			if(nums[0] < nums[1]) {
				max    = nums[1];
				index  = 1;
				second = nums[0];
			} else {
				max    = nums[0];
				index  = 0;
				second = nums[1];
			}
			for(int i = 2; i < nums.size(); i++) {
				if(nums[i] > max) {
					second = max;
					index  = i;
					max    = nums[i];
				} else if(nums[i] > second) {
					second = nums[i];
				}
			}
			if(max >= 2 * second) {
				return index;
			}
			return -1;
		}
	}// namespace largest_number_at_least_twice_of_others

	namespace find_k_pairs_with_smallest_sums {
		vector<vector<int>> Solution::kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
			auto ans = vector<vector<int>>();
			auto pq  = priority_queue<pair>();
			for(int i = 0; i < k && i < nums1.size(); i++) {
				for(int j = 0; j < k && j < nums2.size(); j++) {
					pq.push(pair(nums1[i], nums2[j]));
				}
			}
			for(int i = 0; i < k && i < nums1.size() * nums2.size(); i++) {
				const pair p = pq.top();
				pq.pop();
				auto to_add = vector<int>();
				to_add.resize(2);
				to_add[0] = p.u;
				to_add[1] = p.v;
				ans.push_back(to_add);
			}
			return ans;
		}

		bool pair::operator<(const pair &p) const { return this->u + this->v > p.u + p.v; }
	}// namespace find_k_pairs_with_smallest_sums

	namespace permutations {
		vector<vector<int>> Solution::permute(vector<int> &nums) {
			auto ans = vector<vector<int>>();
			if(nums.size() == 1) {
				auto next_ans = vector<int>();
				next_ans.push_back(nums[0]);
				ans.push_back(next_ans);
				return ans;
			}
			for(auto num: nums) {
				auto next = vector(nums);
				next.erase(find(next.begin(), next.end(), num));
				auto next_permutations = permute(next);
				auto new_ans           = vector<int>();
				new_ans.push_back(num);
				for(auto next_permutation: next_permutations) {
					auto next_ans = vector(new_ans);
					next_ans.insert(next_ans.end(), next_permutation.begin(), next_permutation.end());
					ans.push_back(next_ans);
				}
			}
			return ans;
		}
	}// namespace permutations

	namespace calculate_money_in_leetcode_bank {
		int Solution::totalMoney(int n) {
			int sum = n / 7 * (28 + 7 * (n / 7 + 3)) / 2;
			for(int i = 0; i < n % 7; i++) {
				sum += n / 7 + 1 + i;
			}
			return sum;
		}
	}// namespace calculate_money_in_leetcode_bank

	namespace linked_list_random_node {
		int Solution::getRandom() const {
			int i   = 1;
			int ans = 0;
			for(const auto *node = head; node != nullptr; node = node->next, i++) {
				if(rand() % i == 0) {
					// 1/i 的概率选中（替换为答案）
					ans = node->val;
				}
			}
			return ans;
		}
	}// namespace linked_list_random_node

	namespace divide_a_string_into_groups_of_size_k {
		vector<string> Solution::divideString(const string &s, int k, char fill) {
			auto ans = vector<string>();
			int i    = 0;
			for(; i * k + k < s.length(); i++) {
				ans.push_back(s.substr(i * k, k));
			}
			if(i * k != s.length()) {
				string last = s.substr(i * k);
				for(int j = last.length(); j < k; j++) {
					last += fill;
				}
				ans.push_back(last);
			}
			return ans;
		}
	}// namespace divide_a_string_into_groups_of_size_k

	namespace minimum_moves_to_reach_target_score {
		int Solution::minMoves(int target, int maxDoubles) {
			int count = 0;
			while(target != 1) {
				if(maxDoubles == 0) {
					return count + target - 1;
				}
				if(target % 2 == 0 && maxDoubles != 0) {
					target /= 2;
					maxDoubles--;
				} else {
					target--;
				}
				count++;
			}
			return count;
		}
	}// namespace minimum_moves_to_reach_target_score

	namespace solving_questions_with_brainpower {
		long long Solution::mostPoints(vector<vector<int>> &questions) {
			vector<long long> f(questions.size() + 1);
			for(int i = questions.size() - 1; i >= 0; --i) {
				auto &q     = questions[i];
				const int j = i + q[1] + 1;
				f[i]        = max(f[i + 1], q[0] + (j < questions.size() ? f[j] : 0));
			}
			return f[0];
		}
	}// namespace solving_questions_with_brainpower

	namespace maximum_running_time_of_n_computers {
		long long Solution::maxRunTime(int n, vector<int> &batteries) {
			auto check = [&](long long t) {
				long long sum = 0;
				for(const int i: batteries) {
					sum += min(t, static_cast<long long>(i));
				}
				return sum / t >= n;
			};

			long long l = 1;
			long long r = 1e16;
			while(l < r) {
				const long long m = (l + r) / 2;
				if(check(m)) {
					l = m + 1;
				} else {
					r = m;
				}
			}
			return l - 1;
		}
	}// namespace maximum_running_time_of_n_computers

	namespace coun_vowels_permutation {
		int Solution::countVowelPermutation(int n) {
			/// \brief a-0 e-1 i-2 o-3 u-4
			unsigned long long end[5] = {1, 1, 1, 1, 1};
			for(int _i = 1; _i < n; _i++) {
				const unsigned long long a = (end[1] + end[2] + end[4]) % 1000000007;
				const unsigned long long e = (end[0] + end[2]) % 1000000007;
				const unsigned long long i = (end[1] + end[3]) % 1000000007;
				const unsigned long long o = end[2] % 1000000007;
				const unsigned long long u = (end[2] + end[3]) % 1000000007;
				end[0]                     = a;
				end[1]                     = e;
				end[2]                     = i;
				end[3]                     = o;
				end[4]                     = u;
			}
			return (end[0] + end[1] + end[2] + end[3] + end[4]) % 1000000007;
		}
	}// namespace coun_vowels_permutation

	namespace minimum_time_difference {
		int Solution::findMinDifference(vector<string> &timePoints) {
			auto vec = vector<int>();
			for(string timePoint: timePoints) {
				vec.push_back(((timePoint[0] - '0') * 10 + (timePoint[1] - '0')) * 60 + (timePoint[3] - '0') * 10 + (timePoint[4] - '0'));
			}
			sort(vec.begin(), vec.end());
			int minimum = INT_MAX;
			for(int i = 0; i + 1 < vec.size(); i++) {
				minimum = min(minimum, vec[i + 1] - vec[i]);
			}
			minimum = min(minimum, vec[0] + 24 * 60 - vec[vec.size() - 1]);
			return minimum;
		}
	}// namespace minimum_time_difference

	namespace contains_duplicate_ii {
		bool Solution::containsNearbyDuplicate(vector<int> &nums, int k) {
			auto um = unordered_map<int, vector<int>>();
			for(int i = 0; i < nums.size(); i++) {
				if(!um.contains(nums[i])) {
					um.insert(pair(nums[i], vector<int>()));
				}
				auto pos = lower_bound(um[nums[i]].begin(), um[nums[i]].end(), i);
				if(pos != um[nums[i]].end() && abs(*pos - i) <= k || pos != um[nums[i]].begin() && abs(*(pos - 1) - i) <= k) {
					return true;
				}
				um[nums[i]].insert(pos, i);
			}
			for(auto i: um) {
				sort(i.second.begin(), i.second.end());
			}
			return false;
		}
	}// namespace contains_duplicate_ii

	namespace stone_game_ix {
		bool Solution::stoneGameIX(vector<int> &stones) {
			unsigned int remove    = 0;
			unsigned int counts[3] = {0, 0, 0};
			for(auto stone: stones) {
				stone %= 3;
				counts[stone]++;
			}
			if(stones.size() == 1) {
				return false;
			}
			if(counts[1] + counts[2] == 2) {
				if(counts[1] == 2 || counts[2] == 2) {
					return false;
				}
			}
			if(counts[1] == 0 && counts[2] == 0) {
				return false;
			}
			if(abs(static_cast<int>(counts[1]) - static_cast<int>(counts[2])) <= 2) {
				return counts[0] % 2 == 0;
			}
			return true;
		}
	}// namespace stone_game_ix

	namespace jump_game_iv {
		int Solution::minJumps(vector<int> &arr) {
			if(arr.size() == 1) {
				return 0;
			}
			auto pq    = queue<pair<int, int>>();//<下标,step>
			auto *flag = new bool[arr.size()];
			memset(flag, 0, arr.size() * sizeof(bool));
			auto um = unordered_map<int, vector<int>>();//<值,下标>
			for(int i = 0; i < arr.size(); i++) {
				if(!um.contains(arr[i])) {
					auto vec = vector<int>();
					vec.push_back(i);
					um.insert(pair(arr[i], vec));
				} else {
					um[arr[i]].push_back(i);
				}
			}
			pq.push(pair(0, 0));
			flag[0] = true;
			while(!pq.empty()) {
				auto [current_i, current_count] = pq.front();
				pq.pop();
				if(current_i == arr.size() - 1) {
					return current_count;
				}
				if(um.contains(arr[current_i])) {
					for(auto i: um[arr[current_i]]) {
						if(i != current_i && !flag[i]) {
							pq.push(pair(i, current_count + 1));
							flag[i] = true;
						}
					}
				}
				um.erase(arr[current_i]);
				if(current_i - 1 >= 0 && !flag[current_i - 1]) {
					pq.push(pair(current_i - 1, current_count + 1));
					flag[current_i - 1] = true;
				}
				if(current_i + 1 < arr.size() && !flag[current_i + 1]) {
					pq.push(pair(current_i + 1, current_count + 1));
					flag[current_i + 1] = true;
				}
			}
			delete[] flag;
			return 0;
		}
	}// namespace jump_game_iv

	namespace remove_palindromic_subsequences {
		int Solution::removePalindromeSub(string s) {
			for(int i = 0, j = s.length() - 1; i < j; i++, j--) {
				if(s[i] != s[j]) {
					return 2;
				}
			}
			return 1;
		}
	}// namespace remove_palindromic_subsequences

	namespace UhWRSj {
		string Solution::replaceWords(vector<string> &dictionary, const string &sentence) {
			auto oss         = ostringstream();
			auto *const nstr = new char[sentence.length() + 1];
			auto tn          = TrieNode();
			for(const auto &root: dictionary) {
				tn.insert(root);
			}
			strcpy(nstr, sentence.c_str());
			char *word = strtok(nstr, " ");
			while(word != nullptr) {
				oss << tn.get_prefix("", string(word)) << " ";
				word = strtok(nullptr, " ");
			}
			const string ans = oss.str();
			delete[] nstr;
			return ans.substr(0, ans.length() - 1);
		}

		void TrieNode::insert(const string &str) {
			if(str.empty()) {
				this->endroot = true;
				return;
			}
			if(this->next[str[0] - 'a'] == nullptr) {
				this->next[str[0] - 'a'] = new TrieNode(str[0]);
			}
			this->next[str[0] - 'a']->insert(str.substr(1));
		}

		string TrieNode::get_prefix(string root, const string &str) const {
			if(this->endroot || str.empty()) {
				return root;
			}
			if(this->next[str[0] - 'a'] == nullptr) {
				return root + str;
			}
			return this->next[str[0] - 'a']->get_prefix(root + str[0], str.substr(1));
		}
	}// namespace UhWRSj

	namespace minimum_cost_of_buying_candies_with_discount {
		int Solution::minimumCost(vector<int> &cost) {
			if(cost.size() == 1) {
				return cost[0];
			}
			if(cost.size() == 2) {
				return cost[0] + cost[1];
			}
			int count = 0;
			sort(cost.rbegin(), cost.rend());
			for(int i = 0; i < cost.size(); i++) {
				if(i % 3 != 2) {
					count += cost[i];
				}
			}
			return count;
		}
	}// namespace minimum_cost_of_buying_candies_with_discount

	namespace count_the_hidden_sequences {
		int Solution::numberOfArrays(vector<int> &differences, int lower, int upper) {
			long long current = 0;
			long long maximum = 0;
			long long minimum = 0;
			for(const auto difference: differences) {
				current += difference;
				maximum = max(maximum, current);
				minimum = min(minimum, current);
			}
			return max(static_cast<long long>(0), upper - lower - (maximum - minimum) + 1);
		}
	}// namespace count_the_hidden_sequences

	namespace k_highest_ranked_items_within_a_price_range {
		vector<vector<int>> Solution::highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k) {
			const auto m    = grid.size();
			const auto n    = grid[0].size();
			auto ans        = vector<vector<int>>();
			const auto low  = pricing[0];
			const auto high = pricing[1];
			const auto row  = start[0];
			const auto col  = start[1];
			auto pq         = priority_queue<item>();
			pq.push(item(0, grid[row][col], row, col));
			grid[row][col] = 0;
			while(pq.empty() && k != 0) {
				auto current = pq.top();
				pq.pop();
				if(current.price != 1 && current.price >= low && current.price <= high) {
					k--;
					auto vec = vector<int>();
					vec.push_back(current.row);
					vec.push_back(current.col);
					ans.push_back(vec);
				}
				pair<int, int> nexts[4] = {pair(current.row + 1, current.col),
				                           pair(current.row - 1, current.col),
				                           pair(current.row, current.col + 1),
				                           pair(current.row, current.col - 1)};
				for(const pair<int, int> next: nexts) {
					if(0 <= next.first && next.first < m && 0 <= next.second && next.second < n && grid[next.first][next.second] != 0) {
						pq.push(item(current.distance + 1, grid[next.first][next.second], next.first, next.second));
						grid[next.first][next.second] = 0;
					}
				}
			}
			return ans;
		}

		bool item::operator<(const item &i) const {
			if(this->distance != i.distance) {
				return this->distance > i.distance;
			}
			if(this->price != i.price) {
				return this->price > i.price;
			}
			if(this->row != i.row) {
				return this->row > i.row;
			}
			return this->col > i.col;
		}
	}// namespace k_highest_ranked_items_within_a_price_range

	namespace number_of_ways_to_divide_a_long_corridor {
		int Solution::numberOfWays(string corridor) {
			unsigned int s_count = 0;
			auto p               = vector<unsigned int>();
			for(const char ch: corridor) {
				if(ch == 'S') {
					s_count++;
				}
			}
			if(s_count == 0 || s_count % 2 != 0) {
				return 0;
			}
			if(s_count == 2) {
				return 1;
			}
			unsigned int start = 0;
			unsigned int end   = corridor.length() - 1;
			for(; start < end; start++) {
				if(corridor[start] == 'S') {
					break;
				}
			}
			for(; end > start; end--) {
				if(corridor[end] == 'S') {
					break;
				}
			}
			s_count              = 1;
			unsigned int p_count = 0;
			bool flag            = false;//是否在边界
			for(unsigned int i = start + 1; i <= end; i++) {
				if(corridor[i] == 'S') {
					s_count++;
				} else {
					if(s_count == 0) {
						p_count++;
					}
				}
				s_count %= 2;
				if(s_count == 0) {
					flag = true;
				} else if(s_count == 1) {
					if(flag) {
						p.push_back(p_count + 1);
						p_count = 0;
					}
					flag = false;
				}
			}
			unsigned long long ans = 1;
			for(const auto i: p) {
				ans *= i;
				ans %= 1000000007;
			}
			return ans;
		}
	}// namespace number_of_ways_to_divide_a_long_corridor

	namespace count_elements_with_strictly_smaller_and_greater_elements {
		int Solution::countElements(vector<int> &nums) {
			int maximum = nums[0];
			int minimum = nums[0];
			for(auto num: nums) {
				maximum = max(maximum, num);
				minimum = min(minimum, num);
			}
			unsigned int count = 0;
			for(const auto num: nums) {
				if(maximum != num && minimum != num) {
					count++;
				}
			}
			return count;
		}
	}// namespace count_elements_with_strictly_smaller_and_greater_elements

	namespace rearrange_array_elements_by_sign {
		vector<int> Solution::rearrangeArray(vector<int> &nums) {
			const auto size = nums.size();
			auto ans        = vector<int>();
			auto positive   = vector<int>();
			auto negative   = vector<int>();
			for(auto num: nums) {
				if(num > 0) {
					positive.push_back(num);
				} else {
					negative.push_back(num);
				}
			}
			for(int i = 0; i < size / 2; i++) {
				ans.push_back(positive[i]);
				ans.push_back(negative[i]);
			}
			return ans;
		}
	}// namespace rearrange_array_elements_by_sign

	namespace find_all_lonely_numbers_in_the_array {
		vector<int> Solution::findLonely(vector<int> &nums) {
			if(nums.size() == 1) {
				return nums;
			}
			sort(nums.begin(), nums.end());
			auto ans = vector<int>();
			if(nums[1] - nums[0] > 1) {
				ans.push_back(nums[0]);
			}
			if(nums[nums.size() - 1] - nums[nums.size() - 2] > 1) {
				ans.push_back(nums[nums.size() - 1]);
			}
			for(int i = 1; i < nums.size() - 1; i++) {
				if(nums[i] - nums[i - 1] > 1 && nums[i + 1] - nums[i] > 1) {
					ans.push_back(nums[i]);
				}
			}
			return ans;
		}
	}// namespace find_all_lonely_numbers_in_the_array

	namespace maximum_good_people_based_on_statements {
		int Solution::maximumGood(vector<vector<int>> &statements) {
			int maximum = 0;
			auto dup    = unordered_map<int, bool>();
			for(int i = 0; i < statements.size(); i++) {
				if(dup[i]) {
					continue;
				}
				const auto um = unordered_map<int, bool>();
				auto que      = queue<msg>();
				que.push(msg(i, true));
				auto ans = dfs(statements, um, que);
				maximum  = max(maximum, ans.first);
				for(auto it: ans.second) {
					if(it.second) {
						dup.insert(it);
					}
				}
			}
			return maximum;
		}

		pair<int, unordered_map<int, bool>> Solution::dfs(vector<vector<int>> &statements, unordered_map<int, bool> um, queue<msg> que) {
			int maximum     = 0;
			bool contradict = false;
			while(!que.empty()) {
				auto current = que.front();
				que.pop();
				if(um.contains(current.person)) {
					//已经存在
					if(um[current.person] != current.good) {
						//矛盾
						return pair<int, unordered_map<int, bool>>(0, {});
					}
				} else {
					um.insert(pair(current.person, current.good));
				}
				if(current.good) {
					//是好人
					for(int j = 0; j < statements.size(); j++) {
						if(statements[current.person][j] != 2 && j != current.person) {
							auto nmsg = msg(j, statements[current.person][j] == 1);
							if(um.contains(nmsg.person)) {
								//已经有了
								if(um[nmsg.person] != nmsg.good) {
									//矛盾
									contradict = true;
									return pair<int, unordered_map<int, bool>>(0, {});
								}
							} else {
								//还没有
								que.push(nmsg);
							}
						}
					}
				}
			}
			if(!contradict) {
				//不矛盾
				auto dup = unordered_map<int, bool>();
				for(int i = 0; i < statements.size(); i++) {
					if(dup[i]) {
						continue;
					}
					if(!um.contains(i)) {
						bool all2 = true;
						for(auto v: statements[i]) {
							if(v != 2) {
								all2 = false;
							}
						}
						if(all2) {
							um.insert(pair(i, true));
							continue;
						}
						auto nque = queue<msg>();
						nque.push(msg(i, true));
						auto ans = dfs(statements, um, nque);
						maximum  = max(maximum, ans.first);
						for(auto it: ans.second) {
							if(it.second) {
								dup.insert(it);
							}
						}
					}
				}

				int good_count = 0;
				for(auto i: um) {
					if(i.second) {
						good_count++;
					}
				}
				maximum = max(maximum, good_count);
			}
			return pair(maximum, um);
		}
	}// namespace maximum_good_people_based_on_statements

	namespace stock_price_fluctuation {
		StockPrice::StockPrice() {
			ms = multiset<int>();
			m  = map<int, int>();
		}

		void StockPrice::update(int timestamp, int price) {
			if(!m.contains(timestamp)) {
				m.insert(pair(timestamp, price));
			} else {
				ms.erase(ms.find(m[timestamp]));
				m[timestamp] = price;
			}
			ms.insert(price);
		}

		int StockPrice::current() const { return (*m.rbegin()).second; }

		int StockPrice::maximum() const { return *ms.rbegin(); }

		int StockPrice::minimum() const { return *ms.begin(); }
	}// namespace stock_price_fluctuation

	namespace second_minimum_time_to_reach_destination {
		int Solution::secondMinimum(int n, vector<vector<int>> &edges, int time, int change) {
			auto record = unordered_map<int, vector<int>>();
			for(int i = 1; i <= n; i++) {
				record.insert(pair(i, vector<int>()));
			}
			auto um = unordered_map<int, unordered_set<int>>();
			for(auto edge: edges) {
				if(!um.contains(edge[0])) {
					auto us = unordered_set<int>();
					us.insert(edge[1]);
					um.insert(pair(edge[0], us));
				} else {
					um[edge[0]].insert(edge[1]);
				}
				if(!um.contains(edge[1])) {
					auto us = unordered_set<int>();
					us.insert(edge[0]);
					um.insert(pair(edge[1], us));
				} else {
					um[edge[1]].insert(edge[0]);
				}
			}
			auto pq = priority_queue<status>();
			pq.push(status(1, 0));
			bool flag = false;//已经到达一次终点
			int prev  = 0;
			while(!pq.empty()) {
				status current = pq.top();
				pq.pop();
				if(current.position == n) {
					if(!flag) {
						flag = true;
						prev = current.time;
					} else {
						if(current.time != prev) {
							return current.time;
						}
					}
				}

				if(record[current.position].empty() || record[current.position].size() == 1 && current.time != *record[current.position].rbegin()) {
					//可以继续
					record[current.position].push_back(current.time);
				} else {
					continue;
				}

				for(int next: um[current.position]) {
					int next_time;
					if(current.time / change % 2 == 1) {
						//当前为红灯
						next_time = (current.time / change + 1) * change + time;
					} else {
						next_time = current.time + time;
					}
					auto next_status = status(next, next_time);
					if(record[next_status.position].empty() || record[next_status.position].size() == 1 && next_status.time != *record[next_status.position].rbegin()) {
						//可以继续
						pq.push(next_status);
					}
				}
			}
			return 0;
		}

		bool status::operator<(const status &s) const { return this->time > s.time; }
	}// namespace second_minimum_time_to_reach_destination

	namespace count_of_matches_in_tournament {
		int Solution::numberOfMatches(int n) { return n - 1; }
	}// namespace count_of_matches_in_tournament

	namespace detect_squares {
		DetectSquares::DetectSquares() { ms = multiset<pair<int, int>>(); }

		void DetectSquares::add(vector<int> point) { ms.insert(pair(point[0], point[1])); }

		int DetectSquares::count(vector<int> point) const {
			int count = 0;
			for(auto p: ms) {
				if(p.first != point[0] && p.second != point[1] && abs(p.first - point[0]) == abs(p.second - point[1])) {
					count += ms.count(pair(p.first, point[1])) * ms.count(pair(point[0], p.second));
				}
			}
			return count;
		}
	}// namespace detect_squares

	namespace number_of_valid_words_in_a_sentence {
		int Solution::countValidWords(const string &sentence) {
			auto *str = new char[sentence.length() + 1];
			strcpy(str, sentence.c_str());
			int count = 0;///< 有效单词数
			for(const char *token = strtok(str, " "); token != nullptr; token = strtok(nullptr, " ")) {
				bool is_valid = true; ///< 是否是有效单词
				bool hyphen   = false;///< 是否已经存在连接符'-'
				for(int i = 0; token[i] != '\0'; i++) {
					const char ch = token[i];///当前字符
					if(ch == '-') {
						//当前字符是连接符'-'
						if(hyphen) {
							//已经存在过连接符'-'
							is_valid = false;
							break;
						}
						hyphen = true;
						if(i == 0 || token[i + 1] == '\0') {
							//是否在字符串的开头或结尾
							is_valid = false;
							break;
						}
						if(isalpha(token[i - 1]) == 0 || isalpha(token[i + 1]) == 0) {
							//前后是否是字母
							is_valid = false;
							break;
						}
					} else if(token[i + 1] != '\0' && isalpha(ch) == 0) {
						//不是最后一个字符是否不是字母
						is_valid = false;
						break;
					} else if(isdigit(ch) != 0) {
						//是否是数字
						is_valid = false;
						break;
					}
				}
				if(is_valid) {
					count++;
				}
			}
			delete[] str;
			return count;
		}
	}// namespace number_of_valid_words_in_a_sentence

	namespace the_number_of_weak_characters_in_the_game {
		int Solution::numberOfWeakCharacters(vector<vector<int>> &properties) {
			//按攻击值从大到小排序。攻击值相同时，按照其防御值从小到大排序
			sort(properties.begin(), properties.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; });

			int maxDef = 0;///< 最大防御值
			int count  = 0;
			for(const auto &p: properties) {
				if(p[1] < maxDef) {
					count++;
				} else {
					maxDef = p[1];
				}
			}
			return count;
		}
	}// namespace the_number_of_weak_characters_in_the_game

	namespace pattern_matching_lcci {
		bool Solution::patternMatching(const string &pattern, const string &value) {
			int a_count = 0;
			int b_count = 0;
			for(const char ch: pattern) {
				if(ch == 'a') {
					a_count++;
				} else {
					b_count++;
				}
			}
			if(a_count == 0 || b_count == 0) {
				int size  = 0;
				int count = 0;
				if(b_count == 0) {
					if(value.length() % a_count != 0) {
						return false;
					}
					size  = value.length() / a_count;
					count = a_count;
				} else {
					if(value.length() % b_count != 0) {
						return false;
					}
					size  = value.length() / b_count;
					count = b_count;
				}
				const string str = value.substr(0, size);
				for(int i = 0; i < count; i++) {
					auto s = value.substr(i * size, size);
					if(s != str) {
						return false;
					}
				}
				return true;
			}
			for(int a_size = 0; a_size <= value.length() / a_count; a_size++) {
				string a;
				string b;
				if((value.length() - a_size * a_count) % b_count == 0) {
					const int b_size   = (value.length() - a_size * a_count) / b_count;
					string value_local = value;
					for(const char ch: pattern) {
						if(ch == 'a') {
							string a_local = value_local.substr(0, a_size);
							if(a.empty()) {
								a = a_local;
							} else if(a_local != a) {
								goto next_loop;
							}
							value_local = value_local.substr(a_size);
						} else {
							string b_local = value_local.substr(0, b_size);
							if(b.empty()) {
								b = b_local;
							} else if(b_local != b) {
								goto next_loop;
							}
							value_local = value_local.substr(b_size);
						}
					}
					if(a == b) {
						goto next_loop;
					}
					return true;
				}
			next_loop:;
			}
			return false;
		}
	}// namespace pattern_matching_lcci

	namespace map_of_highest_peak {
		vector<vector<int>> Solution::highestPeak(vector<vector<int>> &isWater) {
			const int m    = isWater.size();
			const int n    = isWater[0].size();
			auto *occupied = new bool *[m];
			for(int i = 0; i < m; i++) {
				occupied[i] = new bool[n];
				memset(occupied[i], 0, n * sizeof(bool));
			}
			auto que = queue<pair<int, int>>();
			for(int i = 0; i < m; i++) {
				for(int j = 0; j < n; j++) {
					if(isWater[i][j] == 1) {
						que.push(pair(i, j));
						isWater[i][j]  = 0;
						occupied[i][j] = true;
					} else {
						isWater[i][j] = 1;
					}
				}
			}
			while(!que.empty()) {
				pair<int, int> current = que.front();
				que.pop();
				pair<int, int> nexts[4] = {pair(current.first + 1, current.second),
				                           pair(current.first - 1, current.second),
				                           pair(current.first, current.second + 1),
				                           pair(current.first, current.second - 1)};
				for(auto next: nexts) {
					if(0 <= next.first && next.first < m && 0 <= next.second && next.second < n && !occupied[next.first][next.second]) {
						isWater[next.first][next.second]  = isWater[current.first][current.second] + 1;
						occupied[next.first][next.second] = true;
						que.push(next);
					}
				}
			}
			delete[] occupied;
			return isWater;
		}
	}// namespace map_of_highest_peak

	namespace uncommon_words_from_two_sentences {
		vector<string> Solution::uncommonFromSentences(const string &s1, const string &s2) {
			auto ans           = vector<string>();
			auto um            = unordered_map<string, unsigned int>();
			auto *const s1_str = new char[s1.length() + 1];
			auto *const s2_str = new char[s2.length() + 1];
			strcpy(s1_str, s1.c_str());
			strcpy(s2_str, s2.c_str());
			for(char *word = strtok(s1_str, " "); word != nullptr; word = strtok(nullptr, " ")) {
				auto word_str = string(word);
				if(!um.contains(word_str)) {
					um.insert(pair(word_str, 1));
				} else {
					um[word_str]++;
				}
			}
			for(char *word = strtok(s2_str, " "); word != nullptr; word = strtok(nullptr, " ")) {
				auto word_str = string(word);
				if(!um.contains(word_str)) {
					um.insert(pair(word_str, 1));
				} else {
					um[word_str]++;
				}
			}
			for(const auto &p: um) {
				if(p.second == 1) {
					ans.push_back(p.first);
				}
			}
			delete[] s1_str;
			delete[] s2_str;
			return ans;
		}
	}// namespace uncommon_words_from_two_sentences

	namespace keep_multiplying_found_values_by_two {
		int Solution::findFinalValue(vector<int> &nums, int original) {
		restart:;
			for(const auto num: nums) {
				if(num == original) {
					original *= 2;
					goto restart;
				}
			}
			return original;
		}
	}// namespace keep_multiplying_found_values_by_two

	namespace all_divisions_with_the_highest_score_of_a_binary_array {
		vector<int> Solution::maxScoreIndices(vector<int> &nums) {
			const auto n       = nums.size();
			auto left_0_count  = vector<int>();
			auto right_1_count = vector<int>();
			left_0_count.push_back(0);
			right_1_count.push_back(0);
			int count = 0;
			for(int i = 0; i < n; i++) {
				if(nums[i] == 0) {
					count++;
				}
				left_0_count.push_back(count);
			}
			count = 0;
			for(int i = n - 1; i >= 0; i--) {
				if(nums[i] == 1) {
					count++;
				}
				right_1_count.push_back(count);
			}
			right_1_count = vector(right_1_count.rbegin(), right_1_count.rend());
			int maximum   = 0;
			for(int i = 0; i <= n; i++) {
				maximum = max(maximum, left_0_count[i] + right_1_count[i]);
			}
			auto ans = vector<int>();
			for(int i = 0; i <= n; i++) {
				if(maximum == left_0_count[i] + right_1_count[i]) {
					ans.push_back(i);
				}
			}
			return ans;
		}
	}// namespace all_divisions_with_the_highest_score_of_a_binary_array

	namespace find_substring_with_given_hash_value {
		string Solution::subStrHash(string s, int power, int modulo, int k, int hashValue) {
			power %= modulo;
			auto *const pn = new int[k];
			pn[0]          = 1;
			for(int i = 1; i < k; i++) {
				pn[i] = static_cast<unsigned long long>(pn[i - 1]) * static_cast<unsigned long long>(power) % modulo;
			}

			for(int i = 0; i < s.length(); i++) {
				unsigned long long hash = 0;
				for(int j = 0; j < k; j++) {
					hash += static_cast<unsigned long long>((s[i + j] - 'a' + 1) % modulo) * pn[j];
					hash %= modulo;
				}
				if(hash == hashValue) {
					return s.substr(i, k);
				}
			}
			delete[] pn;
			return "";
		}
	}// namespace find_substring_with_given_hash_value

	namespace groups_of_strings {
		vector<int> Solution::groupStrings(vector<string> &words) {
			auto ans  = vector<int>();
			auto nums = vector<unsigned int>();
			for(const auto &word: words) {
				auto num = compress(word);
				nums.push_back(num);
				insert(num);
			}
			for(const auto num: nums) {
				for(int i = 0; i < 26; i++) {
					auto next = num ^ 1 << i;//添加或删除字符 i
					if(parent.contains(next)) {
						to_union(num, next);
					}
					if((num >> i & 1) == 1) {
						//存在字符i
						for(int j = 0; j < 26; j++) {
							if((num >> j & 1) == 0) {
								//不存在字符j
								auto next = num ^ 1 << i | 1 << j;
								if(parent.contains(next)) {
									to_union(num, num ^ 1 << i | 1 << j);// 替换字符 i 为 j
								}
							}
						}
					}
				}
			}
			ans.push_back(groups);
			ans.push_back(max_size);
			return ans;
		}

		unsigned int Solution::compress(const string &word) {
			unsigned int ans = 0;
			for(const char ch: word) {
				ans |= 1 << ch - 'a';
			}
			return ans;
		}

		void Solution::insert(unsigned int num) {
			parent.insert(pair(num, num));
			rank.insert(pair(num, 0));
			if(!size.contains(num)) {
				size.insert(pair(num, 1));
				groups++;
			} else {
				size[num]++;
				max_size = size[num];
			}
		}

		unsigned int Solution::find(unsigned int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }

		void Solution::to_union(unsigned int x1, unsigned int x2) {
			const int f1 = find(x1);
			const int f2 = find(x2);
			if(f1 == f2) {
				return;
			}
			groups--;
			if(rank[f1] > rank[f2]) {
				parent[f2] = f1;
				size[f1] += size[f2];
				max_size = max(max_size, size[f1]);
			} else {
				parent[f1] = f2;
				size[f2] += size[f1];
				max_size = max(max_size, size[f2]);
				if(rank[f1] == rank[f2]) {
					++rank[f2];
				}
			}
		}
	}// namespace groups_of_strings

	namespace number_of_steps_to_reduce_a_number_to_zero {
		int Solution::numberOfSteps(int num) {
			if(num == 0) {
				return 0;
			}
			int count = 0;
			while(num != 0) {
				if((num & 1) == 0) {
					count += 1;
				} else {
					count += 2;
				}
				num >>= 1;
			}
			return count - 1;
		}
	}// namespace number_of_steps_to_reduce_a_number_to_zero

	namespace longest_nice_substring {
		string Solution::longestNiceSubstring(const string &s) {
			auto [max_start, max_len] = dfs(s, 0, s.length() - 1);
			if(max_len == 0) {
				return "";
			}
			return s.substr(max_start, max_len);
		}

		pair<int, int> Solution::dfs(string s, int start, int end) {
			if(start == end) {
				return {start, 0};
			}
			int lower     = 0;
			int upper     = 0;
			int max_start = 0;
			int max_len   = 0;
			for(int i = start; i <= end; i++) {
				const char ch = s[i];
				if(islower(ch) != 0) {
					lower |= 1 << ch - 'a';
				} else {
					//isupper
					upper |= 1 << ch - 'A';
				}
			}
			if(lower == upper) {
				//是美好字符串
				return {start, end - start + 1};
			}
			//不是美好字符串
			const int not_nice = lower ^ upper;//无法构成美好字符串的字符
			int i              = start;
			while(i <= end) {
				if((not_nice >> tolower(s[i]) - 'a' & 1) == 1) {
					//在not_nice中
					i++;
					continue;
				}
				int j = i + 1;
				while(j <= end && (not_nice >> tolower(s[j]) - 'a' & 1) != 1) {
					j++;
				}
				auto [next_start, next_len] = dfs(s, i, j - 1);
				if(max_len < next_len) {
					max_len   = next_len;
					max_start = next_start;
				}
				i = j;
			}
			return {max_start, max_len};
		}
	}// namespace longest_nice_substring

	namespace reverse_prefix_of_word {
		string Solution::reversePrefix(string word, char ch) {
			int i = 0;
			for(; i < word.length(); i++) {
				if(ch == word[i]) {
					break;
				}
			}
			if(i == word.length()) {
				return word;
			}
			string prefix       = word.substr(0, i + 1);
			const string suffix = word.substr(i + 1);
			const auto xiferp   = string(prefix.rbegin(), prefix.rend());
			return xiferp + suffix;
		}
	}// namespace reverse_prefix_of_word

	namespace find_the_minimum_number_of_fibonacci_numbers_whose_sum_is_k {
		int Solution::findMinFibonacciNumbers(int k) {
			auto fibb = set<int, greater<>>();
			fibb.insert(1);
			int prev_1 = 1;
			int next   = 2;
			while(next <= k) {
				fibb.insert(next);
				const int prev_2 = prev_1;
				prev_1           = next;
				next             = prev_1 + prev_2;
			}
			return find_min(fibb, k, fibb.begin());
		}

		int Solution::find_min(set<int, greater<>> &fibb, int k, set<int, greater<>>::iterator begin) {
			const auto i = lower_bound(begin, fibb.end(), k, greater<int>());
			if(k == *i) {
				return 1;
			}
			return 1 + find_min(fibb, k - *i, i);
		}
	}// namespace find_the_minimum_number_of_fibonacci_numbers_whose_sum_is_k

	namespace number_of_rectangles_that_can_form_the_largest_square {
		int Solution::countGoodRectangles(vector<vector<int>> &rectangles) {
			auto m = map<int, int>();
			for(auto rectangle: rectangles) {
				int k = min(rectangle[0], rectangle[1]);
				m[k]++;
			}
			return (*m.rbegin()).second;
		}
	}// namespace number_of_rectangles_that_can_form_the_largest_square

	namespace path_with_maximum_gold {
		int Solution::getMaximumGold(vector<vector<int>> &grid) {
			const int m = grid.size();
			const int n = grid[0].size();
			int ans     = 0;
			for(int i = 0; i < m; i++) {
				for(int j = 0; j < n; j++) {
					if(grid[i][j] != 0) {
						auto *occupied = new bool *[m];
						for(int k = 0; k < m; k++) {
							occupied[k] = new bool[n];
							memset(occupied[k], 0, n * sizeof(bool));
						}
						occupied[i][j] = true;
						ans            = max(ans, get_sum(grid[i][j], i, j, m, n, grid, occupied));
						for(int k = 0; k < m; k++) {
							delete[] occupied[k];
						}
						delete[] occupied;
					}
				}
			}
			return ans;
		}

		int Solution::get_sum(int current, int x, int y, int m, int n, vector<vector<int>> &grid, bool **occupied) {
			pair<int, int> nexts[] = {make_pair(x + 1, y), make_pair(x - 1, y), make_pair(x, y + 1), make_pair(x, y - 1)};
			int maximum            = current;
			for(auto [next_x, next_y]: nexts) {
				if(0 <= next_x && next_x < m && 0 <= next_y && next_y < n && grid[next_x][next_y] != 0 && !occupied[next_x][next_y]) {
					auto *occupied_cpy = new bool *[m];
					for(int i = 0; i < m; i++) {
						occupied_cpy[i] = new bool[n];
						memcpy(occupied_cpy[i], occupied[i], n * sizeof(bool));
					}
					occupied_cpy[next_x][next_y] = true;
					maximum                      = max(maximum, get_sum(current + grid[next_x][next_y], next_x, next_y, m, n, grid, occupied_cpy));
					for(int i = 0; i < m; i++) {
						delete[] occupied_cpy[i];
					}
					delete[] occupied_cpy;
				}
			}
			return maximum;
		}
	}// namespace path_with_maximum_gold

	namespace minimum_sum_of_four_digit_number_after_splitting_digits {
		int Solution::minimumSum(int num) {
			auto oss = ostringstream();
			oss << num;
			const string str = oss.str();
			int nums[4];
			for(int i = 0; i < 4; i++) {
				nums[i] = str[i] - '0';
			}
			sort(nums, nums + 4);
			return nums[0] * 10 + nums[1] * 10 + nums[2] + nums[3];
		}
	}// namespace minimum_sum_of_four_digit_number_after_splitting_digits

	namespace partition_array_according_to_given_pivot {
		vector<int> Solution::pivotArray(vector<int> &nums, int pivot) {
			auto less    = vector<int>();
			auto equal   = vector<int>();
			auto greater = vector<int>();
			for(auto num: nums) {
				if(num < pivot) {
					less.push_back(num);
				} else if(num == pivot) {
					equal.push_back(num);
				} else {
					greater.push_back(num);
				}
			}
			less.insert(less.end(), equal.begin(), equal.end());
			less.insert(less.end(), greater.begin(), greater.end());
			return less;
		}
	}// namespace partition_array_according_to_given_pivot

	namespace minimum_cost_to_set_cooking_time {
		int Solution::minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
			int ans    = (moveCost + pushCost) * 4;
			int minute = targetSeconds / 60;
			int second = targetSeconds % 60;
			while(minute > 99) {
				minute -= 1;
				second += 60;
			}
			const int num[4] = {minute / 10, minute % 10, second / 10, second % 10};
			ans              = min(ans, get_cost(startAt, moveCost, pushCost, num));
			if(second + 60 < 100 && minute - 1 >= 0) {
				second += 60;
				minute -= 1;
				const int num[4] = {minute / 10, minute % 10, second / 10, second % 10};
				ans              = min(ans, get_cost(startAt, moveCost, pushCost, num));
			}
			return ans;
		}

		int Solution::get_cost(int startAt, int moveCost, int pushCost, const int num[4]) {
			int cost    = 0;
			int current = startAt;
			bool flag   = true;
			for(int i = 0; i < 4; i++) {
				if(num[i] == 0 && flag) {
					continue;
				}
				flag = false;
				if(num[i] != current) {
					cost += moveCost;
					current = num[i];
				}
				cost += pushCost;
			}
			return cost;
		}
	}// namespace minimum_cost_to_set_cooking_time

	namespace minimum_difference_in_sums_after_removal_of_elements {
		long long Solution::minimumDifference(vector<int> &nums) {
			const int n         = nums.size() / 3;
			auto *left_sum      = new long long[n];
			auto *right_sum     = new long long[n];
			long long left_min  = 0;
			long long right_max = 0;
			auto left_n         = priority_queue<int>();
			auto right_n        = priority_queue<int, vector<int>, greater<>>();
			for(int i = 0; i < n; i++) {
				left_n.push(nums[i]);
				left_min += nums[i];
			}
			for(int i = 3 * n - 1; i >= 2 * n; i--) {
				right_n.push(nums[i]);
				right_max += nums[i];
			}
			const long long left_min_preserve  = left_min;
			const long long right_max_preserve = right_max;
			left_sum[0]                        = left_min;
			right_sum[n - 1]                   = right_max;
			for(int i = n; i < 2 * n; i++) {
				if(nums[i] < left_n.top()) {
					left_min += nums[i] - left_n.top();
					left_n.pop();
					left_n.push(nums[i]);
				}
				left_sum[i - n] = left_min;
			}
			for(int i = 2 * n - 1; i >= n; i--) {
				if(nums[i] > right_n.top()) {
					right_max += nums[i] - right_n.top();
					right_n.pop();
					right_n.push(nums[i]);
				}
				right_sum[i - n] = right_max;
			}
			long long ans = left_min_preserve - right_sum[0];
			for(int i = 0; i < n - 1; i++) {
				ans = min(ans, left_sum[i] - right_sum[i + 1]);
			}
			ans = min(ans, left_sum[n - 1] - right_max_preserve);
			delete[] left_sum;
			delete[] right_sum;
			return ans;
		}
	}// namespace minimum_difference_in_sums_after_removal_of_elements

	namespace sum_of_unique_elements {
		int Solution::sumOfUnique(vector<int> &nums) {
			auto um = unordered_map<int, int>();
			for(auto num: nums) {
				um[num]++;
			}
			int ans = 0;
			for(auto [k, v]: um) {
				if(v == 1) {
					ans += k;
				}
			}
			return ans;
		}
	}// namespace sum_of_unique_elements

	namespace sort_even_and_odd_indices_independently {
		vector<int> Solution::sortEvenOdd(vector<int> &nums) {
			vector<int> even;///< 偶数
			vector<int> odd; ///< 奇数
			vector<int> ans;
			for(int i = 0; i < nums.size(); i++) {
				if(i % 2 == 0) {
					even.push_back(nums[i]);
				} else {
					odd.push_back(nums[i]);
				}
			}
			sort(even.begin(), even.end());
			sort(odd.begin(), odd.end(), greater<int>());
			for(int i = 0; i < odd.size(); i++) {
				ans.push_back(even[i]);
				ans.push_back(odd[i]);
			}
			if(even.size() > odd.size()) {
				ans.push_back(even.back());
			}
			return ans;
		}
	}// namespace sort_even_and_odd_indices_independently

	namespace smallest_value_of_the_rearranged_number {
		long long Solution::smallestNumber(long long num) {
			bool positive = num > 0;
			auto oss      = ostringstream();
			num           = abs(num);
			oss << num;
			vector<int> n;
			for(char ch: oss.str()) {
				n.push_back(ch - '0');
			}
			sort(n.begin(), n.end());
			vector<int> ans;
			if(positive) {
				for(auto i: n) {
					if(i != 0) {
						ans.push_back(i);
					}
				}
				for(auto i: n) {
					if(i == 0) {
						ans.insert(ans.begin() + 1, i);
					}
				}
			} else {
				for(int i = n.size() - 1; i >= 0; i--) {
					ans.push_back(n[i]);
				}
			}
			oss = ostringstream();
			if(!positive) {
				oss << '-';
			}
			for(auto i: ans) {
				oss << i;
			}
			auto iss = istringstream(oss.str());
			long long a;
			iss >> a;
			return a;
		}
	}// namespace smallest_value_of_the_rearranged_number

	namespace design_bitset {
		Bitset::Bitset(int size) {
			this->size = size;
			one1       = new set<unsigned int>();
			zero0      = new set<unsigned int>();
			for(int i = 0; i < size; i++) {
				zero0->insert(i);
			}
		}

		void Bitset::fix(int idx) const {
			zero0->erase(idx);
			one1->insert(idx);
		}

		void Bitset::unfix(int idx) const {
			zero0->insert(idx);
			one1->erase(idx);
		}

		void Bitset::flip() {
			auto *const tmp = one1;
			one1            = zero0;
			zero0           = tmp;
		}

		bool Bitset::all() const { return zero0->empty(); }

		bool Bitset::one() const { return !one1->empty(); }

		int Bitset::count() const { return one1->size(); }

		string Bitset::toString() const {
			auto oss = ostringstream();
			auto c1  = one1->begin();
			auto c0  = zero0->begin();
			for(int i = 0; i < size; i++) {
				if(c1 != one1->end() && *c1 == i) {
					oss << 1;
					++c1;
				} else if(c0 != zero0->end() && *c0 == i) {
					oss << 0;
					++c0;
				}
			}
			return oss.str();
		}
	}// namespace design_bitset

	namespace longest_happy_string {
		string Solution::longestDiverseString(int a, int b, int c) {
			auto oss   = ostringstream();
			int count  = 0;
			char prev  = '0';
			char ch[3] = {};
			sort(ch, a, b, c);
			while(a != 0 || b != 0 || c != 0) {
				if(!(count == 2 && prev == ch[2] && *get_p(ch[2], &a, &b, &c) > 0)) {
					oss << ch[2];
					(*get_p(ch[2], &a, &b, &c))--;
					if(prev == ch[2]) {
						count++;
					} else {
						prev  = ch[2];
						count = 1;
					}
				} else if(!(count == 2 && prev == ch[1]) && *get_p(ch[1], &a, &b, &c) > 0) {
					oss << ch[1];
					(*get_p(ch[1], &a, &b, &c))--;
					if(prev == ch[1]) {
						count++;
					} else {
						prev  = ch[1];
						count = 1;
					}
				} else if(!(count == 2 && prev == ch[0]) && *get_p(ch[0], &a, &b, &c) > 0) {
					oss << ch[0];
					(*get_p(ch[0], &a, &b, &c))--;
					if(prev == ch[0]) {
						count++;
					} else {
						prev  = ch[0];
						count = 1;
					}
				} else {
					return oss.str();
				}
				sort(ch, a, b, c);
			}
			return oss.str();
		}

		void Solution::sort(char *ch, int a, int b, int c) {
			int minimum = a;
			ch[0]       = 'a';
			int maximum = b;
			ch[2]       = 'b';
			if(minimum > b) {
				minimum = b;
				ch[0]   = 'b';
			}
			if(minimum > c) {
				minimum = c;
				ch[0]   = 'c';
			}
			if(maximum < a) {
				maximum = a;
				ch[2]   = 'a';
			}
			if(maximum < c) {
				maximum = c;
				ch[2]   = 'c';
			}
			ch[1] = 'a' + 'b' + 'c' - ch[0] - ch[2];
		}

		int *Solution::get_p(char ch, int *a, int *b, int *c) {
			switch(ch) {
				case 'a': return a;
				case 'b': return b;
				case 'c': return c;
				default: return nullptr;
			}
		}
	}// namespace longest_happy_string

	namespace grid_illumination {
		vector<int> Solution::gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries) {
			auto ls        = unordered_set<pair<int, int>, pair_hash>();
			auto row       = unordered_map<int, int>();
			auto col       = unordered_map<int, int>();
			auto diag_down = unordered_map<int, int>();///< 从左上到右下的对角线
			auto diag_up   = unordered_map<int, int>();///< 从右上到左下的对角线
			for(auto lamp: lamps) {
				int x  = lamp[0];
				int y  = lamp[1];
				auto p = make_pair(x, y);
				if(!ls.contains(p)) {
					ls.insert(p);
					row[x]++;
					col[y]++;
					diag_down[n - x + y]++;
					diag_up[x + y]++;
				}
			}
			auto ans = vector<int>();
			for(auto query: queries) {
				int query_x = query[0];
				int query_y = query[1];
				if(row[query_x] > 0 || col[query_y] > 0 || diag_down[n - query_x + query_y] > 0 || diag_up[query_x + query_y] > 0) {
					ans.push_back(1);
				} else {
					ans.push_back(0);
				}
				pair<int, int> adjacents[9] = {make_pair(query_x + 1, query_y + 1), make_pair(query_x + 1, query_y), make_pair(query_x + 1, query_y - 1),
				                               make_pair(query_x, query_y + 1), make_pair(query_x, query_y), make_pair(query_x, query_y - 1),
				                               make_pair(query_x - 1, query_y + 1), make_pair(query_x - 1, query_y), make_pair(query_x - 1, query_y - 1)};
				for(auto adjacent: adjacents) {
					if(ls.contains(adjacent)) {
						ls.erase(adjacent);
						auto [x, y] = adjacent;
						row[x]--;
						col[y]--;
						diag_down[n - x + y]--;
						diag_up[x + y]--;
					}
				}
			}
			return ans;
		}

		unsigned long long pair_hash::operator()(const pair<int, int> &p) const { return static_cast<unsigned long long>(p.first) * 1000000000 + p.second; }
	}// namespace grid_illumination

	namespace count_number_of_pairs_with_absolute_difference_k {
		int Solution::countKDifference(vector<int> &nums, int k) {
			int ans = 0;
			for(int i = 0; i < nums.size(); i++) {
				for(int j = i + 1; j < nums.size(); j++) {
					if(abs(nums[i] - nums[j]) == k) {
						ans++;
					}
				}
			}
			return ans;
		}
	}// namespace count_number_of_pairs_with_absolute_difference_k

	namespace simplified_fractions {
		vector<string> Solution::simplifiedFractions(int n) {
			auto ans = vector<string>();
			for(int denominator = 2; denominator <= n; denominator++) {
				for(int numerator = 1; numerator < denominator; numerator++) {
					if(gcd(denominator, numerator) != 1) {
						continue;
					}
					auto oss = ostringstream();
					oss << numerator << "/" << denominator;
					ans.push_back(oss.str());
				}
			}
			return ans;
		}

		int Solution::gcd(int m, int n) { return n != 0 ? gcd(n, m % n) : m; }
	}// namespace simplified_fractions

	namespace minimum_difference_between_highest_and_lowest_of_k_scores {
		int Solution::minimumDifference(vector<int> &nums, int k) {
			int ans = 100000;
			sort(nums.begin(), nums.end());
			for(int i = 0; i + k - 1 < nums.size(); i++) {
				ans = min(ans, nums[i + k - 1] - nums[i]);
			}
			return ans;
		}
	}// namespace minimum_difference_between_highest_and_lowest_of_k_scores

	namespace number_of_enclaves {
		int Solution::numEnclaves(vector<vector<int>> &grid) {
			int sum     = 0;
			const int m = grid.size();
			const int n = grid[0].size();
			auto que    = queue<pair<int, int>>();
			for(int i = 0; i < m; i++) {
				for(int j = 0; j < n; j++) {
					if(grid[i][j] == 1) {
						sum++;
						if(i == 0 || i == m - 1 || j == 0 || j == n - 1) {
							que.push(make_pair(i, j));
							grid[i][j] = 0;
						}
					}
				}
			}
			while(!que.empty()) {
				auto [x, y] = que.front();
				sum--;
				que.pop();
				pair<int, int> nexts[4] = {make_pair(x + 1, y), make_pair(x - 1, y), make_pair(x, y + 1), make_pair(x, y - 1)};
				for(auto next: nexts) {
					auto [next_x, next_y] = next;
					if(0 <= next_x && next_x < m && 0 <= next_y && next_y < n && grid[next_x][next_y] != 0) {
						que.push(next);
						grid[next_x][next_y] = 0;
					}
				}
			}
			return sum;
		}
	}// namespace number_of_enclaves

	namespace maximum_number_of_balloons {
		int Solution::maxNumberOfBalloons(const string &text) {
			int b = 0;
			int a = 0;
			int l = 0;
			int o = 0;
			int n = 0;
			for(const char ch: text) {
				switch(ch) {
					case 'b':
						b++;
						break;
					case 'a':
						a++;
						break;
					case 'l':
						l++;
						break;
					case 'o':
						o++;
						break;
					case 'n':
						n++;
						break;
				}
			}
			l /= 2;
			o /= 2;
			int ans = b;
			ans     = min(ans, a);
			ans     = min(ans, l);
			ans     = min(ans, o);
			ans     = min(ans, n);
			return ans;
		}
	}// namespace maximum_number_of_balloons

	namespace swap_adjacent_in_lr_string {
		bool Solution::canTransform(const string &start, const string &end) {
			auto oss_start = ostringstream();
			auto oss_end   = ostringstream();
			auto i_start   = vector<int>();
			auto i_end     = vector<int>();
			for(int i = 0; i < start.size(); i++) {
				char ch = start[i];
				if(ch == 'R' || ch == 'L') {
					oss_start << ch;
					i_start.push_back(i);
				}
			}
			for(int i = 0; i < end.size(); i++) {
				char ch = end[i];
				if(ch == 'R' || ch == 'L') {
					oss_end << ch;
					i_end.push_back(i);
				}
			}
			string str_start = oss_start.str();
			string str_end   = oss_end.str();
			if(str_start != str_end) {
				return false;
			}
			for(int i = 0; i < i_start.size(); i++) {
				if(str_start[i] == 'R') {
					if(i_start[i] > i_end[i]) {
						return false;
					}
				} else {
					//L
					if(i_start[i] < i_end[i]) {
						return false;
					}
				}
			}
			return true;
		}
	}// namespace swap_adjacent_in_lr_string

	namespace count_operations_to_obtain_zero {
		int Solution::countOperations(int num1, int num2) {
			int count = 0;
			while(num1 != 0 && num2 != 0) {
				if(num1 > num2) {
					count += num1 / num2;
					num1 = num1 % num2;
				} else {
					count += num2 / num1;
					num2 = num2 % num1;
				}
			}
			return count;
		}
	}// namespace count_operations_to_obtain_zero

	namespace minimum_operations_to_make_the_array_alternating {
		int Solution::minimumOperations(vector<int> &nums) {
			int a_sum = 0;
			int b_sum = 0;
			auto a    = unordered_map<int, int>();
			auto b    = unordered_map<int, int>();
			for(int i = 0; i < nums.size(); i++) {
				if(i % 2 == 0) {
					a[nums[i]]++;
					a_sum++;
				} else {
					b[nums[i]]++;
					b_sum++;
				}
			}
			int max_num = 0;
			int maximum = 0;
			int ans1    = 0;
			for(const auto i: a) {
				if(maximum < i.second) {
					maximum = i.second;
					max_num = i.first;
				}
			}
			ans1 += a_sum - maximum;
			maximum = 0;
			for(const auto i: b) {
				if(i.first != max_num && maximum < i.second) {
					maximum = i.second;
				}
			}
			ans1 += b_sum - maximum;

			int ans2 = 0;
			max_num  = 0;
			maximum  = 0;
			for(const auto i: b) {
				if(maximum < i.second) {
					maximum = i.second;
					max_num = i.first;
				}
			}
			ans2 += b_sum - maximum;
			maximum = 0;
			for(const auto i: a) {
				if(i.first != max_num && maximum < i.second) {
					maximum = i.second;
				}
			}
			ans2 += a_sum - maximum;
			return min(ans1, ans2);
		}
	}// namespace minimum_operations_to_make_the_array_alternating

	namespace removing_minimum_number_of_magic_beans {
		long long Solution::minimumRemoval(vector<int> &beans) {
			sort(beans.begin(), beans.end());
			long long sum     = 0;
			long long maximum = 0;
			for(int i = 0; i < beans.size(); i++) {
				sum += beans[i];
				maximum = max(maximum, static_cast<long long>(beans[i] * (beans.size() - i)));
			}
			return sum - maximum;
		}
	}// namespace removing_minimum_number_of_magic_beans

	namespace maximum_and_sum_of_array {
		int Solution::maximumANDSum(vector<int> &nums, int numSlots) {
			int ans = 0;
			vector<int> max_and_sum_of_status(1 << numSlots * 2);
			for(unsigned int status = 0; status < max_and_sum_of_status.size(); ++status) {
				//status:已经放置数字的篮子的集合
				const int one_count = popcount(status);
				if(one_count >= nums.size()) {
					continue;
				}
				for(int next_slot = 0; next_slot < numSlots * 2; ++next_slot) {
					if((status & 1 << next_slot) == 0) {
						// next_slot是空的
						const int next_status              = status | 1 << next_slot;                                                                              ///< 加上next_slot之后的状态
						const auto slot_num                = next_slot / 2 + 1;                                                                                    ///< slot编号
						max_and_sum_of_status[next_status] = max(max_and_sum_of_status[next_status], max_and_sum_of_status[status] + (slot_num & nums[one_count]));//放置第onecount个数字
						ans                                = max(ans, max_and_sum_of_status[next_status]);
					}
				}
			}
			return ans;
		}
	}// namespace maximum_and_sum_of_array

	namespace single_element_in_a_sorted_array {
		int Solution::singleNonDuplicate(vector<int> &nums) {
			int l = 0;
			int r = nums.size() - 1;
			while(l < r) {
				if(l + 1 == r) {
					if(l == 0) {
						return nums[l];
					}
					if(r == nums.size() - 1) {
						return nums[r];
					}
					if(nums[l - 1] == nums[l]) {
						return nums[r];
					}
					return nums[l];
				}
				const int m = (l + r) / 2;
				int tmp     = m;
				if(nums[m + 1] == nums[m]) {
					tmp = m + 1;
				}
				if(tmp % 2 == 0) {
					//在左边
					r = m;
				} else {
					//在右边
					l = m;
				}
			}
			return nums[l];
		}
	}// namespace single_element_in_a_sorted_array

	namespace lucky_numbers_in_a_matrix {
		vector<int> Solution::luckyNumbers(vector<vector<int>> &matrix) {
			auto ans      = vector<int>();
			const auto m  = matrix.size();
			const auto n  = matrix[0].size();
			auto *minimum = new int[m];
			memset(minimum, 50, m * sizeof(int));
			auto *maximum = new int[n];
			memset(maximum, 0, n * sizeof(int));
			for(int i = 0; i < m; i++) {
				for(int j = 0; j < n; j++) {
					minimum[i] = min(minimum[i], matrix[i][j]);
					maximum[j] = max(maximum[j], matrix[i][j]);
				}
			}
			for(int i = 0; i < m; i++) {
				for(int j = 0; j < n; j++) {
					if(matrix[i][j] == minimum[i] && matrix[i][j] == maximum[j]) {
						ans.push_back(matrix[i][j]);
					}
				}
			}
			delete[] minimum;
			delete[] maximum;
			return ans;
		}
	}// namespace lucky_numbers_in_a_matrix

	namespace number_of_ways_to_reconstruct_a_tree {
		int Solution::checkWays(vector<vector<int>> &pairs) {
			unordered_map<int, unordered_set<int>> adj;
			for(auto &p: pairs) {
				adj[p[0]].emplace(p[1]);
				adj[p[1]].emplace(p[0]);
			}
			/* 检测是否存在根节点*/
			int root = -1;
			for(auto &[node, neighbours]: adj) {
				if(neighbours.size() == adj.size() - 1) {
					root = node;
					break;
				}
			}
			if(root == -1) {
				return 0;
			}

			int res = 1;
			for(auto &[node, neighbours]: adj) {
				if(node == root) {
					continue;
				}
				const int currDegree = neighbours.size();
				int parent           = -1;
				int parentDegree     = INT_MAX;

				/* 根据 degree 的大小找到 node 的父节点 parent */
				for(const auto &neighbour: neighbours) {
					if(adj[neighbour].size() < parentDegree && adj[neighbour].size() >= currDegree) {
						parent       = neighbour;
						parentDegree = adj[neighbour].size();
					}
				}
				if(parent == -1) {
					return 0;
				}

				/* 检测 neighbours 是否是 adj[parent] 的子集 */
				for(const auto &neighbour: neighbours) {
					if(neighbour == parent) {
						continue;
					}
					if(static_cast<unsigned int>(adj[parent].contains(neighbour)) == 0U) {
						return 0;
					}
				}
				if(parentDegree == currDegree) {
					res = 2;
				}
			}
			return res;
		}
	}// namespace number_of_ways_to_reconstruct_a_tree

	namespace find_center_of_star_graph {
		int Solution::findCenter(vector<vector<int>> &edges) {
			auto um = unordered_map<int, int>();
			for(auto edge: edges) {
				um[edge[0]]++;
				um[edge[1]]++;
				if(um[edge[0]] > 1) {
					return edge[0];
				}
				if(um[edge[1]] > 1) {
					return edge[1];
				}
			}
			return 0;
		}
	}// namespace find_center_of_star_graph

	namespace knight_probability_in_chessboard {
		double Solution::knightProbability(int n, int k, int row, int column) {
			if(k == 0) {
				return 1;
			}
			const auto s = status(k, row, column);
			if(um.count(s) == 1) {
				return um[s];
			}
			int off                 = 0;
			pair<int, int> nexts[8] = {make_pair(row - 2, column - 1),
			                           make_pair(row - 2, column + 1),
			                           make_pair(row + 2, column - 1),
			                           make_pair(row + 2, column + 1),
			                           make_pair(row - 1, column - 2),
			                           make_pair(row - 1, column + 2),
			                           make_pair(row + 1, column - 2),
			                           make_pair(row + 1, column + 2)};
			double sum              = 0;
			for(auto [next_x, next_y]: nexts) {
				if(0 <= next_x && next_x < n && 0 <= next_y && next_y < n) {
					sum += knightProbability(n, k - 1, next_x, next_y);
				}
			}
			const double ans = sum / 8;
			um[s]            = ans;
			return ans;
		}

		unsigned int status_hash::operator()(const status &s) const { return s.k * 25 * 25 + s.row * 25 + s.column; }

		bool status_equal::operator()(const status &s1, const status &s2) const { return s1.k == s2.k && s1.row == s2.row && s1.column == s2.column; }
	}// namespace knight_probability_in_chessboard

	namespace pancake_sorting {
		vector<int> Solution::pancakeSort(vector<int> &arr) {
			auto ans      = vector<int>();
			const int n   = arr.size();
			auto *current = new int[n];
			auto *sorted  = new int[n];
			for(int i = 0; i < n; i++) {
				current[i] = arr[i];
				sorted[i]  = arr[i];
			}
			sort(sorted, sorted + n);
		RESTART:
			for(int i = n - 1; i >= 0; i--) {
				if(current[i] != sorted[i]) {
					const int target = sorted[i];
					int target_i     = -1;
					for(int j = 0; j <= i; j++) {
						if(current[j] == target) {
							target_i = j + 1;
							break;
						}
					}
					if(target_i == 1) {
						target_i = i + 1;
					}
					ans.push_back(target_i);
					for(int j = 0; j < target_i / 2; j++) {
						swap(current[j], current[target_i - j - 1]);
					}
					goto RESTART;
				}
			}
			delete[] current;
			delete[] sorted;
			return ans;
		}
	}// namespace pancake_sorting

	namespace count_equal_and_divisible_pairs_in_an_array {
		int Solution::countPairs(vector<int> &nums, int k) {
			int ans = 0;
			for(int i = 0; i + 1 < nums.size(); i++) {
				for(int j = i + 1; j < nums.size(); j++) {
					if(nums[i] == nums[j] && i * j % k == 0) {
						ans++;
					}
				}
			}
			return ans;
		}
	}// namespace count_equal_and_divisible_pairs_in_an_array

	namespace find_three_consecutive_integers_that_sum_to_a_given_number {
		vector<long long> Solution::sumOfThree(long long int num) {
			if(num % 3 == 0) {
				const long long mid = num / 3;
				vector ans          = {mid - 1, mid, mid + 1};
				return ans;
			}
			return {};
		}
	}// namespace find_three_consecutive_integers_that_sum_to_a_given_number

	namespace maximum_split_of_positive_even_integers {
		vector<long long> Solution::maximumEvenSplit(long long int finalSum) {
			if(finalSum % 2 != 0) {
				return {};
			}
			if(finalSum == 4) {
				return {4};
			}
			auto ans = vector<long long int>();
			ans.push_back(2);
			finalSum -= 2;
			for(long long i = 4; i <= finalSum; i += 2) {
				const long long int next = finalSum - i;
				if(next > i) {
					ans.push_back(i);
					finalSum = next;
				} else {
					ans.push_back(finalSum);
					break;
				}
			}
			return ans;
		}
	}// namespace maximum_split_of_positive_even_integers

	namespace count_good_triplets_in_an_array {
		long long Solution::goodTriplets(vector<int> &nums1, vector<int> &nums2) {
			const int n = nums1.size();
			FenwickTree<int> occur(n);
			unordered_map<int, int> pos;
			for(int i = 0; i < n; ++i) {
				pos[nums2[i]] = i + 1;
			}
			long long ans = 0;
			for(int i = 0; i < n; ++i) {
				const int idx   = pos[nums1[i]];
				const int left  = occur.query(idx);
				const int right = n - idx - (occur.query(n) - occur.query(idx));
				ans += 1LL * left * right;
				occur.update(idx, 1);
			}

			return ans;
		}
	}// namespace count_good_triplets_in_an_array

	namespace count_integers_with_even_digit_sum {
		int Solution::countEven(int num) {
			int ans = 0;
			for(int i = 1; i <= num; i++) {
				stringstream ss;
				ss << i;
				char ch;
				int sum = 0;
				while(ss >> ch) {
					sum += ch - '0';
				}
				if(sum % 2 == 0) {
					ans++;
				}
			}
			return ans;
		}
	}// namespace count_integers_with_even_digit_sum

	namespace merge_nodes_in_between_zeros {
		ListNode *Solution::mergeNodes(ListNode *head) {
			while(head != nullptr && head->val == 0) {
				head = head->next;
			}
			auto *prev = head;
			while(head != nullptr && head->next != nullptr) {
				if(head->next->val != 0) {
					head->val += head->next->val;
					head->next = head->next->next;
				} else {
					head->next = head->next->next;
					head       = head->next;
				}
			}
			return prev;
		}
	}// namespace merge_nodes_in_between_zeros

	namespace construct_string_with_repeat_limit {
		string Solution::repeatLimitedString(const string &s, int repeatLimit) {
			int ch[26] = {};
			for(const char c: s) {
				ch[c - 'a']++;
			}
			auto oss = ostringstream();
			for(int i = 25; i >= 0; i--) {
				int repeat = 0;
				while(ch[i] != 0) {
					oss << static_cast<char>(i + 'a');
					repeat++;
					ch[i]--;
					if(repeat == repeatLimit && ch[i] != 0) {
						for(int j = i - 1; j >= 0; j--) {
							if(ch[j] > 0) {
								oss << static_cast<char>(j + 'a');
								ch[j]--;
								repeat = 0;
								break;
							}
						}
						if(repeat != 0) {
							return oss.str();
						}
					}
				}
			}
			return oss.str();
		}
	}// namespace construct_string_with_repeat_limit

	namespace count_array_pairs_divisible_by_k {
		long long Solution::coutPairs(vector<int> &nums, int k) {
			long long ans = 0;
			// 统计每个数的倍数出现的次数
			auto count = unordered_map<int, int>();
			for(const auto num: nums) {
				count[num]++;
			}
			const int maximum = *max_element(nums.begin(), nums.end());
			// 为什么这个算法是 O(nlnn) 的？因为这个算法的循环次数是 n(1 + 1/2 + 1/3 + ...)，由调和级数可知括号内趋向 lnn
			for(int i = 1; i <= maximum; i++) {
				for(int j = i * 2; j <= maximum; j += i) {
					count[i] += count[j];
				}
			}
			for(const auto num: nums) {
				// 对于每个数统计与它形成好二元组的数有几个
				ans += count[k / gcd(k, num)];
				if(static_cast<long long>(num) * num % k == 0) {
					// 排除自己和自己形成好二元组的情况
					ans--;
				}
			}
			return ans / 2;
		}
	}// namespace count_array_pairs_divisible_by_k

	namespace leetcode717_1_bit_and_2_bit_characters {
		bool Solution::isOneBitCharacter(vector<int> &bits) {
			for(int i = 0; i < bits.size();) {
				int next = i;
				if(bits[i] == 1) {
					next += 2;
				} else {
					next += 1;
				}
				if(next >= bits.size()) {
					return i == bits.size() - 1;
				}
				i = next;
			}
			return false;
		}
	}// namespace leetcode717_1_bit_and_2_bit_characters

	namespace longest_mountain_in_array {
		int Solution::longestMountain(vector<int> &arr) {
			if(arr.size() < 3) {
				return 0;
			}
			auto up_down = vector<int>(arr.size() - 1);
			for(int i = 0; i + 1 < arr.size(); i++) {
				if(arr[i] < arr[i + 1]) {
					up_down[i] = 1;
				} else if(arr[i] > arr[i + 1]) {
					up_down[i] = 0;
				} else {
					up_down[i] = 2;
				}
			}
			auto sector_size = vector<pair<int, int>>();
			int prev         = up_down[0];
			int count        = 1;
			for(int i = 1; i < up_down.size(); i++) {
				if(up_down[i] != prev) {
					sector_size.emplace_back(prev, count);
					count = 1;
				} else {
					count++;
				}
				prev = up_down[i];
			}
			sector_size.emplace_back(prev, count);
			if(sector_size.size() < 2) {
				return 0;
			}
			int maximum = 0;
			for(int i = 0; i + 1 < sector_size.size(); i++) {
				if(sector_size[i].first == 1 && sector_size[i + 1].first == 0) {
					maximum = max(maximum, sector_size[i].second + sector_size[i + 1].second + 1);
				}
			}
			return maximum;
		}
	}// namespace longest_mountain_in_array

	namespace push_dominoes {
		string Solution::pushDominoes(string dominoes) {
			const int n      = dominoes.length();
			auto *left_to_r  = new int[n];
			auto *right_to_l = new int[n];
			auto *left_is    = new char[n];
			auto *right_is   = new char[n];
			int l2r          = 0;
			int r2l          = 0;
			char ch          = '.';
			for(int i = 0; i < n; i++) {
				if(dominoes[i] != '.') {
					ch = dominoes[i];
				}
				left_is[i] = ch;
			}
			ch = '.';
			for(int i = n - 1; i >= 0; i--) {
				if(dominoes[i] != '.') {
					ch = dominoes[i];
				}
				right_is[i] = ch;
			}
			for(int i = 0; i < n; i++) {
				if(dominoes[i] == 'R') {
					l2r = 0;
				} else {
					l2r++;
				}
				left_to_r[i] = l2r;
			}
			for(int i = n - 1; i >= 0; i--) {
				if(dominoes[i] == 'L') {
					r2l = 0;
				} else {
					r2l++;
				}
				right_to_l[i] = r2l;
			}
			for(int i = 0; i < n; i++) {
				if(dominoes[i] == '.') {
					if(left_is[i] == 'R' && right_is[i] == 'L') {
						if(right_to_l[i] > left_to_r[i]) {
							dominoes[i] = 'R';
						} else if(left_to_r[i] > right_to_l[i]) {
							dominoes[i] = 'L';
						}
					} else if(right_is[i] == 'L') {
						dominoes[i] = 'L';
					} else if(left_is[i] == 'R') {
						dominoes[i] = 'R';
					}
				}
			}
			delete[] left_to_r;
			delete[] right_to_l;
			delete[] left_is;
			delete[] right_is;
			return dominoes;
		}
	}// namespace push_dominoes

	namespace the_number_of_good_subsets {
		int Solution::numberOfGoodSubsets(vector<int> &nums) {
			vector<int> freq(num_max + 1);
			for(const int num: nums) {
				freq[num]++;
			}

			vector<int> f(mask_max);
			f[0] = 1;
			for(int i = 0; i < freq[1]; ++i) {
				f[0] = f[0] * 2 % mod;
			}

			for(int i = 2; i <= num_max; ++i) {
				if(freq[i] == 0) {
					continue;
				}

				// 检查 i 的每个质因数是否均不超过 1 个
				int subset  = 0;
				const int x = i;
				bool check  = true;
				for(int j = 0; j < primes.size(); j++) {
					const int prime = primes[j];
					if(x % (prime * prime) == 0) {
						check = false;
						break;
					}
					if(x % prime == 0) {
						subset |= 1 << j;
					}
				}
				if(!check) {
					continue;
				}

				// 动态规划
				for(int mask = mask_max - 1; mask > 0; mask--) {
					if((mask & subset) == subset) {
						f[mask] = (f[mask] + static_cast<long long>(f[mask ^ subset]) * freq[i]) % mod;
					}
				}
			}
			int ans = 0;
			for(int mask = 1; mask < mask_max; mask++) {
				ans = (ans + f[mask]) % mod;
			}
			return ans;
		}
	}// namespace the_number_of_good_subsets

	namespace reverse_only_letters {
		string Solution::reverseOnlyLetters(string s) {
			for(int i = 0, j = s.length() - 1; i < j && i < s.length() && j >= 0;) {
				if(isalpha(s[i]) != 0 && isalpha(s[j]) != 0) {
					const char temp = s[i];
					s[i]            = s[j];
					s[j]            = temp;
					i++;
					j--;
				} else {
					while(i < s.length() && isalpha(s[i]) == 0) {
						i++;
					}
					while(j >= 0 && isalpha(s[j]) == 0) {
						j--;
					}
				}
			}
			return s;
		}
	}// namespace reverse_only_letters

	namespace where_will_the_ball_fall {
		vector<int> Solution::findBall(vector<vector<int>> &grid) {
			const int m = grid.size();
			const int n = grid[0].size();
			vector<int> ans(n);
			for(int i = 0; i < n; i++) {
				int current_x = 0;
				int current_y = i;
				int dir       = 1;// 0 - 左, 1 - 下, 2 - 右
				while(true) {
					if(current_x == m) {
						ans[i] = current_y;
						break;
					}
					if(current_x < 0 || current_y < 0 || current_y >= n) {
						ans[i] = -1;
						break;
					}
					if(dir == 0) {
						//左
						if(grid[current_x][current_y] == 1) {
							ans[i] = -1;
							break;
						}
						dir = 1;
					} else if(dir == 1) {
						//下
						if(grid[current_x][current_y] == 1) {
							dir = 2;
						} else {
							dir = 0;
						}
					} else {
						//右
						if(grid[current_x][current_y] == 1) {
							dir = 1;
						} else {
							ans[i] = -1;
							break;
						}
					}
					if(dir == 0) {
						//左
						current_y--;
					} else if(dir == 1) {
						//下
						current_x++;
					} else {
						//右
						current_y++;
					}
				}
			}
			return ans;
		}
	}// namespace where_will_the_ball_fall

	namespace complex_number_multiplication {
		string Solution::complexNumberMultiply(const string &num1, const string &num2) {
			auto ss = stringstream();
			ss << num1 << num2;
			int r1;
			int i1;
			int r2;
			int i2;
			ss >> r1;
			ss.get();
			ss >> i1;
			ss.get();
			ss >> r2;
			ss.get();
			ss >> i2;
			const int r = r1 * r2 - i1 * i2;
			const int i = r1 * i2 + r2 * i1;
			ss          = stringstream();
			ss << r << '+' << i << 'i';
			return ss.str();
		}
	}// namespace complex_number_multiplication

	namespace maximum_difference_between_increasing_elements {
		int Solution::maximumDifference(vector<int> &nums) {
			int minn     = nums[0];
			int max_diff = -1;
			for(int i = 1; i < nums.size(); i++) {
				if(nums[i] > minn) {
					max_diff = max(max_diff, nums[i] - minn);
				}
				minn = min(minn, nums[i]);
			}
			return max_diff;
		}
	}// namespace maximum_difference_between_increasing_elements

	namespace optimal_division {
		string Solution::optimalDivision(vector<int> &nums) {
			auto oss = ostringstream();
			if(nums.size() == 1) {
				oss << nums[0];
			} else if(nums.size() == 2) {
				oss << nums[0] << '/' << nums[1];
			} else {
				oss << nums[0] << "/(";
				for(int i = 1; i < nums.size() - 1; i++) {
					oss << nums[i] << '/';
				}
				oss << nums[nums.size() - 1] << ')';
			}
			return oss.str();
		}
	}// namespace optimal_division

	namespace counting_words_with_a_given_prefix {
		int Solution::prefixCount(vector<string> &words, string pref) {
			int ans = 0;
			for(auto word: words) {
				bool ok = true;
				for(int i = 0; i < pref.length(); i++) {
					if(pref[i] != word[i]) {
						ok = false;
						break;
					}
				}
				if(ok) {
					ans++;
				}
			}
			return ans;
		}
	}// namespace counting_words_with_a_given_prefix

	namespace minimum_number_of_steps_to_make_two_strings_anagram_ii {
		int Solution::minSteps(const string &s, const string &t) {
			int ans       = 0;
			int s_num[26] = {};
			int t_num[26] = {};
			for(const char ch: s) {
				s_num[ch - 'a']++;
			}
			for(const char ch: t) {
				t_num[ch - 'a']++;
			}
			for(int i = 0; i < 26; i++) {
				ans += abs(s_num[i] - t_num[i]);
			}
			return ans;
		}
	}// namespace minimum_number_of_steps_to_make_two_strings_anagram_ii

	namespace minimum_time_to_complete_trips {
		long long Solution::minimumTime(vector<int> &time, int totalTrips) {
			int max_t = 1;
			int min_t = 100000;
			for(auto t: time) {
				max_t = max(max_t, t);
				min_t = min(min_t, t);
			}
			long long l = static_cast<long long>(totalTrips) / max_t / time.size();
			long long r = static_cast<long long>(totalTrips) * max_t;
			while(l <= r) {
				const long long m = (l + r) / 2;
				long long sum     = 0;
				for(const auto t: time) {
					sum += m / t;
				}
				if(l == r || l + 1 == r) {
					return r;
				}
				if(sum >= totalTrips) {
					r = m;
				} else if(sum < totalTrips) {
					l = m;
				}
			}
			return 0;
		}
	}// namespace minimum_time_to_complete_trips

	namespace minimum_time_to_finish_the_race {
		int Solution::minimumFinishTime(vector<vector<int>> &tires, int changeTime, int numLaps) {
			/* min_times[i] = 用一个轮胎跑 i 圈的最小花费 */
			vector<long long> min_times(20, 1e9);
			for(auto &v: tires) {
				const long long f    = v[0];
				const long long r    = v[1];
				const long long cost = f + changeTime;///< 第一次用该轮胎的耗费
				long long current    = f;
				long long sum        = cost;
				for(int i = 1; i <= 19; i++) {
					min_times[i] = min(min_times[i], sum);
					current *= r;
					if(current > cost) {
						current = f;
						sum += cost;
					} else {
						sum += current;
					}
				}
			}
			/* dp[i] = 跑 i 圈的最小花费 */
			vector<long long> dp(numLaps + 1, 1e9);
			dp[0] = 0;
			for(int i = 1; i <= numLaps; i++) {
				for(int j = 1; j <= min(19, i); j++) {
					dp[i] = min(dp[i], dp[i - j] + min_times[j]);
				}
			}
			/* 最后需要减去一次换轮胎的时间 */
			return dp[numLaps] - changeTime;
		}
	}// namespace minimum_time_to_finish_the_race

	namespace maximum_number_of_achievable_transfer_requests {
		int Solution::maximumRequests(int n, vector<vector<int>> &requests) {
			int ans = 0;
			for(unsigned int i = 0; i < 1 << requests.size(); i++) {
				auto *in  = new int[n];
				auto *out = new int[n];
				memset(in, 0, n * sizeof(int));
				memset(out, 0, n * sizeof(int));
				for(unsigned int j = 0; j < requests.size(); j++) {
					if((i & 1 << j) != 0) {
						out[requests[j][0]]++;
						in[requests[j][1]]++;
					}
				}
				bool ok = true;
				for(int j = 0; j < n; j++) {
					if(out[j] != in[j]) {
						ok = false;
						break;
					}
				}
				if(ok) {
					ans = max(ans, popcount(i));
				}
				delete[] in;
				delete[] out;
			}
			return ans;
		}
	}// namespace maximum_number_of_achievable_transfer_requests

	namespace zigzag_conversion {
		string Solution::convert(string s, int numRows) {
			if(numRows == 1) {
				return s;
			}
			auto oss = ostringstream();
			auto *m  = new char *[numRows];
			for(int i = 0; i < numRows; i++) {
				m[i] = new char[s.length()];
				memset(m[i], ' ', s.length() * sizeof(char));
			}
			int current_x = 0;
			int current_y = 0;
			bool dir      = true;// true = 下, false = 斜
			for(const char ch: s) {
				m[current_x][current_y] = ch;
				if(dir && current_x == numRows - 1 || !dir && current_x == 0) {
					dir = !dir;
				}
				if(dir) {
					current_x++;
				} else {
					current_x--;
					current_y++;
				}
			}
			for(int i = 0; i < numRows; i++) {
				for(int j = 0; j <= min(current_y, static_cast<int>(s.length() - 1)); j++) {
					if(m[i][j] != ' ') {
						oss << m[i][j];
					}
				}
			}
			for(int i = 0; i < numRows; i++) {
				delete[] m[i];
			}
			delete[] m;
			return oss.str();
		}
	}// namespace zigzag_conversion

	namespace find_the_closest_palindrome {
		string Solution::nearestPalindromic(const string &n) {
			const long long num = stoll(n);
			if(num == 10 || num == 11) {
				return "9";
			}
			if(num < 10) {
				return to_string(num - 1);
			}
			int len         = n.length();
			const bool even = n.length() % 2 == 0;
			string prefix   = n.substr(0, n.length() / 2 + (even ? 0 : 1));
			string option_str[3];
			auto rev                      = string(prefix.rbegin() + (even ? 0 : 1), prefix.rend());
			option_str[2]                 = prefix + rev;
			const long long prefix_int[2] = {stoll(prefix) - 1, stoll(prefix) + 1};
			string prefix_str[2]          = {to_string(prefix_int[0]), to_string(prefix_int[1])};
			for(int i = 0; i < 2; i++) {
				if(prefix_str[i].length() == prefix.length()) {
					rev           = string(prefix_str[i].rbegin() + (even ? 0 : 1), prefix_str[i].rend());
					option_str[i] = prefix_str[i] + rev;
				} else if(prefix_str[i].length() > prefix.length()) {
					rev           = string(prefix_str[i].rbegin() + (even ? 1 : 2), prefix_str[i].rend());
					option_str[i] = prefix_str[i] + rev;
				} else if(prefix_str[i].length() < prefix.length()) {
					rev           = string(prefix_str[i].rbegin(), prefix_str[i].rend());
					option_str[i] = prefix_str[i] + (even ? "9" : "") + rev;
				}
			}
			long long option_int[3] = {stoll(option_str[0]), stoll(option_str[1]), stoll(option_str[2])};
			sort(option_int, option_int + 3);
			long long minimum = option_int[0];
			for(int i = 1; i < 3; i++) {
				if(abs(option_int[i] - num) < abs(minimum - num) && option_int[i] != num) {
					minimum = option_int[i];
				}
			}
			return to_string(minimum);
		}
	}// namespace find_the_closest_palindrome

	namespace add_digits {
		int Solution::addDigits(int num) { return (num - 1) % 9 + 1; }
	}// namespace add_digits

	namespace sum_of_subarray_ranges {
		long long Solution::subArrayRanges(vector<int> &nums) {
			long long ans = 0;
			for(int i = 0; i + 1 < nums.size(); i++) {
				int minimum = nums[i];
				int maximum = nums[i];
				for(int j = i + 1; j < nums.size(); j++) {
					minimum = min(minimum, nums[j]);
					maximum = max(maximum, nums[j]);
					ans += maximum - minimum;
				}
			}
			return ans;
		}
	}// namespace sum_of_subarray_ranges

	namespace longest_uncommon_subsequence_i {
		int Solution::findLUSlength(const string &a, const string &b) {
			if(a.length() != b.length() || b.find(a) == string::npos && a.find(b) == string::npos) {
				return max(a.length(), b.length());
			}
			return -1;
		}
	}// namespace longest_uncommon_subsequence_i

	namespace most_frequent_number_following_key_in_an_array {
		int Solution::mostFrequent(vector<int> &nums, int key) {
			unordered_map<int, int> um;
			for(int i = 0; i + 1 < nums.size(); i++) {
				if(nums[i] == key) {
					um[nums[i + 1]]++;
				}
			}
			int max_v = 0;
			int max_k = 0;
			for(auto [k, v]: um) {
				if(v > max_v) {
					max_v = v;
					max_k = k;
				}
			}
			return max_k;
		}
	}// namespace most_frequent_number_following_key_in_an_array

	namespace sort_the_jumbled_numbers {
		vector<int> Solution::sortJumbled(vector<int> &mapping, vector<int> &nums) {
			vector<tuple<int, int, int>> vec;
			for(int i = 0; i < nums.size(); i++) {
				string str = to_string(nums[i]);
				ostringstream oss;
				for(const char ch: str) {
					oss << mapping[ch - '0'];
				}
				vec.emplace_back(i, nums[i], stoi(oss.str()));
			}
			sort(vec.begin(), vec.end(), cmp());
			vector<int> ans;
			ans.reserve(vec.size());
			for(auto [i, num, rev]: vec) {
				ans.push_back(num);
			}
			return ans;
		}
	}// namespace sort_the_jumbled_numbers

	namespace all_ancestors_of_a_node_in_a_directed_acyclic_graph {
		vector<vector<int>> Solution::getAncestors(int n, vector<vector<int>> &edges) {
			for(int i = 0; i < n; i++) {
				nexts[i]     = unordered_set<int>();
				ancestors[i] = set<int>();
			}
			for(auto edge: edges) {
				nexts[edge[0]].insert(edge[1]);
			}
			for(int i = 0; i < n; i++) {
				for(const auto next: nexts[i]) {
					auto *dfsd = new bool[n];
					memset(dfsd, 0, n * sizeof(bool));
					dfs(dfsd, i, next);
					delete[] dfsd;
				}
			}
			vector<vector<int>> ans;
			for(int i = 0; i < n; i++) {
				vector<int> vec;
				for(auto i: ancestors[i]) {
					vec.push_back(i);
				}
				ans.push_back(vec);
			}
			return ans;
		}

		void Solution::dfs(bool *dfsd, int v, int i) {
			ancestors[i].insert(v);
			dfsd[i] = true;
			for(const auto next: nexts[i]) {
				if(!dfsd[next]) {
					dfs(dfsd, v, next);
				}
			}
		}
	}// namespace all_ancestors_of_a_node_in_a_directed_acyclic_graph

	namespace minimum_number_of_moves_to_make_palindrome {
		int Solution::minMovesToMakePalindrome(string s) {
			int ans = 0;
			for(int left = 0, right = s.size() - 1; left < right; left++) {
				bool even = false;
				for(int i = right; left != i; i--) {
					if(s[left] == s[i]) {
						even = true;
						// 字母出现偶数次的情况，模拟交换
						for(; i < right; i++) {
							swap(s[i], s[i + 1]);
							ans++;
						}
						right--;
						break;
					}
				}
				if(!even) {
					// 字母出现奇数次的情况，计算它距离中间还有多少距离
					ans += s.size() / 2 - left;
				}
			}
			return ans;
		}
	}// namespace minimum_number_of_moves_to_make_palindrome

	namespace cells_in_a_range_on_an_excel_sheet {
		vector<string> Solution::cellsInRange(const string &s) {
			vector<string> ans;
			istringstream ss(s);
			char col1;
			char col2;
			int row1;
			int row2;
			ss >> col1 >> row1;
			ss.get();
			ss >> col2 >> row2;
			for(char col = col1; col <= col2; col++) {
				for(int row = row1; row <= row2; row++) {
					ostringstream oss;
					oss << col << row;
					ans.push_back(oss.str());
				}
			}
			return ans;
		}
	}// namespace cells_in_a_range_on_an_excel_sheet

	namespace append_k_integers_with_minimal_sum {
		long long Solution::minimalKSum(vector<int> &nums, int k) {
			long long ans = 0;
			set<int> s;
			for(auto num: nums) {
				s.insert(num);
			}
			long long limit = k;
			for(auto i = s.begin(); i != s.end() && *i <= limit; ++i) {
				limit++;
			}
			ans += limit + limit * (limit - 1) / 2;
			for(auto i = s.begin(); i != s.end() && *i < limit; ++i) {
				ans -= *i;
			}
			return ans;
		}
	}// namespace append_k_integers_with_minimal_sum

	namespace create_binary_tree_from_descriptions {
		TreeNode *Solution::createBinaryTree(vector<vector<int>> &descriptions) {
			unordered_map<int, TreeNode *> um;
			unordered_set<int> nodes;
			unordered_set<int> childs;
			for(auto description: descriptions) {
				nodes.insert(description[0]);
				nodes.insert(description[1]);
				childs.insert(description[1]);
			}
			for(auto node: nodes) {
				um[node] = new TreeNode();
			}
			for(auto description: descriptions) {
				if(description[2] == 1) {
					//childi 是 parenti 的左子节点
					um[description[0]]->left = um[description[1]];
				} else {
					//childi 是 parenti 的右子节点。
					um[description[0]]->right = um[description[1]];
				}
			}
			for(auto node: nodes) {
				if(!childs.contains(node)) {
					return um[node];
				}
			}
			return nullptr;
		}
	}// namespace create_binary_tree_from_descriptions

	namespace replace_non_coprime_numbers_in_array {
		vector<int> Solution::replaceNonCoprimes(vector<int> &nums) {
			vector<int> ans;
			for(int i = 0; i < nums.size(); i++) {
				int num = nums[i];
				while(!ans.empty() && gcd(num, ans.back()) > 1) {
					num = num / gcd(num, ans.back()) * ans.back();
					ans.pop_back();
				}
				ans.push_back(num);
			}
			return ans;
		}
	}// namespace replace_non_coprime_numbers_in_array

	namespace find_good_days_to_rob_the_bank {
		vector<int> Solution::goodDaysToRobBank(vector<int> &security, int time) {
			if(security.size() < 2 * time + 1) {
				return {};
			}
			vector<int> ans;
			if(time == 0) {
				for(int i = 0; i < security.size(); i++) {
					ans.push_back(i);
				}
				return ans;
			}
			vector non_increasing(security.size(), 0);
			vector non_decreasing(security.size(), 0);
			for(int i = 1; i < security.size(); i++) {
				if(security[i] >= security[i - 1]) {
					non_decreasing[i] = non_decreasing[i - 1] + 1;
				} else {
					non_decreasing[i] = 0;
				}
				if(security[i] <= security[i - 1]) {
					non_increasing[i] = non_increasing[i - 1] + 1;
				} else {
					non_increasing[i] = 0;
				}
			}
			for(int i = time; i + time < security.size(); i++) {
				if(non_decreasing[i + time] >= time && non_increasing[i] >= time) {
					ans.push_back(i);
				}
			}
			return ans;
		}
	}// namespace find_good_days_to_rob_the_bank

	namespace base_7 {
		string Solution::convertToBase7(int num) {
			bool pos = true;
			if(num < 0) {
				pos = false;
				num = -num;
			}
			if(num == 0) {
				return "0";
			}
			deque<int> deq;
			while(num != 0) {
				deq.push_front(num % 7);
				num /= 7;
			}
			ostringstream oss;
			if(!pos) {
				oss << '-';
			}
			for(const int n: deq) {
				oss << n;
			}
			return oss.str();
		}
	}// namespace base_7

	namespace plates_between_candles {
		vector<int> Solution::platesBetweenCandles(string s, vector<vector<int>> &queries) {
			vector<int> ans;
			vector<int> plate_count(s.length());
			vector<int> candle_pos;
			if(s[0] == '*') {
				plate_count[0] = 1;
			} else {
				plate_count[0] = 0;
				candle_pos.push_back(0);
			}
			for(int i = 1; i < s.length(); i++) {
				plate_count[i] = plate_count[i - 1];
				if(s[i] == '*') {
					plate_count[i]++;
				} else {
					candle_pos.push_back(i);
				}
			}
			for(auto query: queries) {
				int left  = query[0];
				int right = query[1];
				auto li   = lower_bound(candle_pos.begin(), candle_pos.end(), left);
				if(li == candle_pos.end() || *li > right) {
					ans.push_back(0);
					continue;
				}
				auto ri = lower_bound(candle_pos.rbegin(), candle_pos.rend(), right, greater<int>());
				if(ri == candle_pos.rend() || *ri < left) {
					ans.push_back(0);
					continue;
				}
				ans.push_back(plate_count[*ri] - plate_count[*li]);
			}
			return ans;
		}
	}// namespace plates_between_candles

	namespace smallest_rotation_with_highest_score {
		int Solution::bestRotation(vector<int> &nums) {
			const int n = nums.size();
			vector k_score_diff(n + 1, 0);
			for(int i = 0; i < n; i++) {
				const int low  = (i + 1) % n;
				const int high = (i - nums[i] + n) % n;
				k_score_diff[low]++;
				k_score_diff[high + 1]--;
				if(low > high) {
					k_score_diff[0]++;
					k_score_diff[n]--;
				}
			}
			int ans       = 0;
			int max_score = 0;
			int score     = 0;
			for(int i = 0; i < n; i++) {
				score += k_score_diff[i];
				if(score > max_score) {
					ans       = i;
					max_score = score;
				}
			}
			return ans;
		}
	}// namespace smallest_rotation_with_highest_score

	namespace n_ary_tree_preorder_traversal {
		vector<int> Solution::preorder(Node *root) {
			if(root == nullptr) {
				return {};
			}
			vector<int> ans;
			ans.push_back(root->val);
			for(auto *child: root->children) {
				auto preorder_child = preorder(child);
				ans.insert(ans.end(), preorder_child.begin(), preorder_child.end());
			}
			return ans;
		}
	}// namespace n_ary_tree_preorder_traversal

	namespace count_nodes_with_the_highest_score {
		int Solution::countHighestScoreNodes(vector<int> &parents) {
			int ans     = 0;
			auto nodes  = vector<TreeNode *>(parents.size(), nullptr);
			auto edges  = vector(parents.size(), vector<int>());
			auto scores = vector<unsigned long long>(parents.size(), 0);
			for(int i = 0; i < parents.size(); i++) {
				nodes[i] = new TreeNode(i);
				if(parents[i] != -1) {
					edges[i].push_back(parents[i]);
					edges[parents[i]].push_back(i);
				}
			}
			TreeNode *root = nullptr;
			for(int i = 0; i < parents.size(); i++) {
				if(parents[i] != -1) {
					nodes[parents[i]]->add_child(nodes[i]);
				} else {
					root = nodes[i];
				}
			}
			root->dfs();
			unsigned long long max_score = 0;
			for(int i = 0; i < parents.size(); i++) {
				unsigned long long score = 1;
				const auto *node         = nodes[i];
				for(const auto *child: node->get_children()) {
					score *= child->get_count();
				}
				if(node->get_parent() != nullptr) {
					score *= root->get_count() - node->get_count();
				}
				max_score = max(max_score, score);
				scores[i] = score;
			}
			return count(scores.begin(), scores.end(), max_score);
		}

		void TreeNode::add_child(TreeNode *node) {
			this->children.push_back(node);
			node->parent = this;
		}

		int TreeNode::dfs() {
			int ans = 1;
			for(auto *child: this->children) {
				ans += child->dfs();
			}
			this->count = ans;
			return ans;
		}

		const vector<TreeNode *> &TreeNode::get_children() const { return children; }

		int TreeNode::get_count() const { return count; }

		TreeNode *TreeNode::get_parent() const { return parent; }
	}// namespace count_nodes_with_the_highest_score

	namespace n_ary_tree_postorder_traversal {
		vector<int> Solution::postorder(Node *root) {
			if(root == nullptr) {
				return {};
			}
			vector<int> ans;
			for(auto *child: root->children) {
				auto res = postorder(child);
				ans.insert(ans.end(), res.begin(), res.end());
			}
			ans.push_back(root->val);
			return ans;
		}
	}// namespace n_ary_tree_postorder_traversal

	namespace max_area_of_island {
		int Solution::maxAreaOfIsland(vector<vector<int>> &grid) {
			const int m = grid.size();
			const int n = grid[0].size();
			auto uf     = UnionFind(m, n);
			int ans     = 0;
			for(int i = 0; i < m; i++) {
				for(int j = 0; j < n; j++) {
					if(grid[i][j] == 1) {
						const pair<int, int> p     = make_pair(i, j);
						ans                        = max(ans, uf.get_size(p));
						pair<int, int> siblings[4] = {
						        make_pair(i + 1, j),
						        make_pair(i - 1, j),
						        make_pair(i, j + 1),
						        make_pair(i, j - 1),
						};
						for(const auto sibling: siblings) {
							if(uf.contains(sibling) && grid[sibling.first][sibling.second] == 1 && !uf.same(p, sibling)) {
								uf.merge(p, sibling);
								ans = max(ans, uf.get_size(p));
							}
						}
					}
				}
			}
			return ans;
		}

		UnionFind::UnionFind(int m, int n)
		    : m(m), n(n) {
			parent = unordered_map<pair<int, int>,
			                       pair<int, int>,
			                       function<unsigned int(const pair<int, int> &)>>(
			        m * n,
			        [](const pair<int, int> &p) { return static_cast<unsigned int>(p.first * 50 + p.second); });
			size = unordered_map<pair<int, int>,
			                     int,
			                     function<unsigned int(const pair<int, int> &)>>(
			        m * n,
			        [](const pair<int, int> &p) { return static_cast<unsigned int>(p.first * 50 + p.second); });
			rank = unordered_map<pair<int, int>,
			                     int,
			                     function<unsigned int(const pair<int, int> &)>>(
			        m * n,
			        [](const pair<int, int> &p) { return static_cast<unsigned int>(p.first * 50 + p.second); });
			for(int i = 0; i < m; i++) {
				for(int j = 0; j < n; j++) {
					pair<int, int> p = make_pair(i, j);
					parent[p]        = p;
					size[p]          = 1;
					rank[p]          = 0;
				}
			}
		}

		pair<int, int> UnionFind::find(pair<int, int> val) {
			if(parent[val] != val) {
				parent[val] = find(parent[val]);
			}
			return parent[val];
		}

		void UnionFind::merge(pair<int, int> a, pair<int, int> b) {
			const auto pa = find(a);
			const auto pb = find(b);
			if(pa != pb) {
				const int sum = size[pa] + size[pb];
				if(rank[pa] > rank[pb]) {
					parent[pb] = pa;
				} else {
					parent[pa] = pb;
					if(rank[pa] == rank[pb]) {
						++rank[pb];
					}
				}
				size[pa] = sum;
				size[pb] = sum;
			}
		}

		bool UnionFind::same(pair<int, int> a, pair<int, int> b) { return find(a) == find(b); }

		bool UnionFind::contains(pair<int, int> p) const { return parent.contains(p); }

		int UnionFind::get_size(pair<int, int> p) { return size[find(p)]; }
	}// namespace max_area_of_island

	namespace find_all_k_distant_indices_in_an_array {
		vector<int> Solution::findKDistantIndices(vector<int> &nums, int key, int k) {
			set<int> key_set;
			set<int> ans_set;
			for(int i = 0; i < nums.size(); i++) {
				if(nums[i] == key) {
					key_set.insert(i);
				}
			}
			for(const auto ks: key_set) {
				for(int i = ks - k; i <= ks + k; i++) {
					if(0 <= i && i < nums.size()) {
						ans_set.insert(i);
					}
				}
			}
			return vector(ans_set.begin(), ans_set.end());
		}
	}// namespace find_all_k_distant_indices_in_an_array

	namespace count_artifacts_that_can_be_extracted {
		int Solution::digArtifacts(int n, vector<vector<int>> &artifacts, vector<vector<int>> &dig) {
			auto *grid = new bool *[n];
			for(int i = 0; i < n; i++) {
				grid[i] = new bool[n];
				memset(grid[i], 0, n * sizeof(bool));
			}
			for(auto i: dig) {
				grid[i[0]][i[1]] = true;
			}
			int ans = 0;
			for(auto artifact: artifacts) {
				bool flag = true;
				for(int i = artifact[0]; i <= artifact[2]; i++) {
					for(int j = artifact[1]; j <= artifact[3]; j++) {
						if(!grid[i][j]) {
							flag = false;
							break;
						}
					}
					if(!flag) {
						break;
					}
				}
				if(flag) {
					ans++;
				}
			}
			for(int i = 0; i < n; i++) {
				delete[] grid[i];
			}
			delete[] grid;
			return ans;
		}
	}// namespace count_artifacts_that_can_be_extracted

	namespace maximize_the_topmost_element_after_k_moves {
		int Solution::maximumTop(vector<int> &nums, int k) {
			if(nums.size() == 1 && k % 2 == 1) {
				return -1;
			}
			if(k > nums.size()) {
				int ans = -1;
				for(auto num: nums) {
					ans = max(ans, num);
				}
				return ans;
			}
			unordered_map<int, int> element_count;
			set<int> poped_elements;
			for(auto num: nums) {
				element_count[num]++;
			}
			for(int i = 0; i < nums.size() && i < k - 1; i++) {
				poped_elements.insert(nums[i]);
				element_count[nums[i]]--;
			}
			int ans = -1;
			if(k < nums.size()) {
				ans = nums[k];
			}
			int maximum = -1;
			for(const auto i = poped_elements.rbegin(); i != poped_elements.rend();) {
				maximum = *i;
				break;
			}
			return max(ans, maximum);
		}
	}// namespace maximize_the_topmost_element_after_k_moves

	namespace minimum_weighted_subgraph_with_the_required_paths {
		long long Solution::minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest) {
			auto *graph     = new vector<pair<int, int>>[n];
			auto *graph_rev = new vector<pair<int, int>>[n];
			for(int i = 0; i < n; i++) {
				graph[i]     = vector<pair<int, int>>();
				graph_rev[i] = vector<pair<int, int>>();
			}
			for(auto &edge: edges) {
				auto from   = edge[0];
				auto to     = edge[1];
				auto weight = edge[2];
				graph[from].emplace_back(to, weight);
				graph_rev[to].emplace_back(from, weight);
			}

			long long a = LLONG_MAX;
			vector dist_src1(n, LLONG_MAX);
			vector dist_src2(n, LLONG_MAX);
			vector dist_dest(n, LLONG_MAX);

			calc_dist(src1, graph, dist_src1);
			calc_dist(src2, graph, dist_src2);
			calc_dist(dest, graph_rev, dist_dest);

			long long ans = LLONG_MAX;

			for(int i = 0; i < n; ++i) {
				if(dist_src1[i] != LLONG_MAX && dist_src2[i] != LLONG_MAX && dist_dest[i] != LLONG_MAX) {
					ans = min(ans, dist_src1[i] + dist_src2[i] + dist_dest[i]);
				}
			}
			if(ans == LLONG_MAX) {
				ans = -1;
			}
			delete[] graph;
			delete[] graph_rev;
			return ans;
		}

		void Solution::calc_dist(int s, vector<pair<int, int>> *graph, vector<long long int> &dist) {
			priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
			dist[s] = 0;
			pq.emplace(0, s);
			while(!pq.empty()) {
				auto [weight, node] = pq.top();
				pq.pop();
				if(weight > dist[node]) {
					continue;
				}
				for(auto [next_node, next_weight]: graph[node]) {
					if(weight + next_weight < dist[next_node]) {
						dist[next_node] = weight + next_weight;
						pq.emplace(weight + next_weight, next_node);
					}
				}
			}
		}
	}// namespace minimum_weighted_subgraph_with_the_required_paths

	namespace utf_8_validation {
		bool Solution::validUtf8(vector<int> &data) {
			vector<int> len;
			for(const auto num: data) {
				if(num >> 7 == 0) {
					//0xxxxxxx
					len.push_back(1);
				} else if(num >> 3 == 30) {
					//11110xxx
					len.push_back(4);
				} else if(num >> 4 == 14) {
					//1110xxxx
					len.push_back(3);
				} else if(num >> 5 == 6) {
					//110xxxxx
					len.push_back(2);
				} else if(num >> 6 == 2) {
					//10xxxxxx
					len.push_back(-1);
				} else {
					return false;
				}
			}
			int count = 0;
			for(int i = 0; i < len.size(); i++) {
				if(count != 0) {
					if(len[i] != -1) {
						return false;
					}
				} else {
					count = len[i];
					if(count == -1) {
						return false;
					}
				}
				count--;
			}
			return count == 0;
		}
	}// namespace utf_8_validation

	namespace minimum_index_sum_of_two_lists {
		vector<string> Solution::findRestaurant(vector<string> &list1, vector<string> &list2) {
			unordered_map<string, int> restaurants;
			unordered_map<string, int> index1;
			unordered_map<string, int> index2;
			for(int i = 0; i < list1.size(); i++) {
				restaurants[list1[i]]++;
				index1[list1[i]] = i;
			}
			for(int i = 0; i < list2.size(); i++) {
				restaurants[list2[i]]++;
				index2[list2[i]] = i;
			}
			unordered_set<string> optional_restaurants;
			for(auto [restaurant, count]: restaurants) {
				if(count > 1) {
					optional_restaurants.insert(restaurant);
				}
			}
			int min_index_sum = INT_MAX;
			for(const auto &optional_restaurant: optional_restaurants) {
				int index_sum = index1[optional_restaurant] + index2[optional_restaurant];
				min_index_sum = min(min_index_sum, index_sum);
			}
			vector<string> ans;
			for(const auto &optional_restaurant: optional_restaurants) {
				int index_sum = index1[optional_restaurant] + index2[optional_restaurant];
				if(index_sum == min_index_sum) {
					ans.push_back(optional_restaurant);
				}
			}
			return ans;
		}
	}// namespace minimum_index_sum_of_two_lists

	namespace count_number_of_maximum_bitwise_or_subsets {
		int Solution::countMaxOrSubsets(vector<int> &nums) {
			int max = 0;
			for(const auto num: nums) {
				max |= num;
			}
			return dfs(0, max, nums);
		}

		int Solution::dfs(int current, int target, vector<int> nums) {
			if((current | target) == current) {
				return 1 << nums.size();
			}
			int sum         = 0;
			vector nums_cpy = nums;
			for(int i = 0; i < nums.size(); i++) {
				nums_cpy.erase(nums_cpy.begin());
				sum += dfs(current | nums[i], target, nums_cpy);
			}
			return sum;
		}
	}// namespace count_number_of_maximum_bitwise_or_subsets

	namespace all_oone_data_structure {
		AllOne::AllOne() {
			str_count = unordered_map<string, int>();
			count_str = map<int, unordered_set<string>>();
		}

		void AllOne::inc(const string &key) {
			const int prev = str_count[key]++;
			count_str[prev].erase(key);
			count_str[prev + 1].insert(key);
			if(count_str[prev].empty()) {
				count_str.erase(prev);
			}
			if(!count_str.empty()) {
				min = count_str.begin()->first;
				max = count_str.rbegin()->first;
			} else {
				min = 50000;
				max = 0;
			}
		}

		void AllOne::dec(const string &key) {
			const int prev = str_count[key]--;
			if(str_count[key] == 0) {
				str_count.erase(key);
			}
			count_str[prev].erase(key);
			if(count_str[prev].empty()) {
				count_str.erase(prev);
			}
			if(prev != 1) {
				count_str[prev - 1].insert(key);
			}
			if(!count_str.empty()) {
				min = count_str.begin()->first;
				max = count_str.rbegin()->first;
			} else {
				min = 50000;
				max = 0;
			}
		}

		string AllOne::getMaxKey() {
			if(str_count.empty()) {
				return "";
			}
			return *count_str[max].begin();
		}

		string AllOne::getMinKey() {
			if(str_count.empty()) {
				return "";
			}
			return *count_str[min].begin();
		}
	}// namespace all_oone_data_structure

	namespace longest_word_in_dictionary {
		string Solution::longestWord(vector<string> &words) {
			auto root = TrieNode('0');
			for(const auto &word: words) {
				root.insert(word);
			}
			return dfs("", &root);
		}

		string Solution::dfs(const string &str, TrieNode *node) {
			string ans = str;
			for(auto *next: node->nexts) {
				if(next != nullptr && next->end_of_word) {
					string ret = dfs(str + next->ch, next);
					if(ans.length() < ret.length()) {
						ans = ret;
					}
				}
			}
			return ans;
		}
	}// namespace longest_word_in_dictionary

	namespace simple_bank_system {
		Bank::Bank(vector<long long int> &balance) {
			accounts = unordered_map<int, long long>(balance.size());
			for(int i = 0; i < balance.size(); i++) {
				accounts[i + 1] = balance[i];
			}
		}

		bool Bank::transfer(int account1, int account2, long long int money) {
			if(!accounts.contains(account1) || !accounts.contains(account2)) {
				return false;
			}
			if(accounts[account1] < money) {
				return false;
			}
			accounts[account1] -= money;
			accounts[account2] += money;
			return true;
		}

		bool Bank::deposit(int account, long long int money) {
			if(!accounts.contains(account)) {
				return false;
			}
			accounts[account] += money;
			return true;
		}

		bool Bank::withdraw(int account, long long int money) {
			if(!accounts.contains(account)) {
				return false;
			}
			if(accounts[account] < money) {
				return false;
			}
			accounts[account] -= money;
			return true;
		}
	}// namespace simple_bank_system

	namespace construct_string_from_binary_tree {
		string Solution::tree2str(TreeNode *root) {
			ostringstream oss;
			oss << root->val;
			if(root->left != nullptr) {
				oss << '(' << tree2str(root->left) << ')';
			} else if(root->right != nullptr) {
				oss << "()";
			}
			if(root->right != nullptr) {
				oss << '(' << tree2str(root->right) << ')';
			}
			return oss.str();
		}
	}// namespace construct_string_from_binary_tree

	namespace maximize_number_of_subsequences_in_a_string {
		long long Solution::maximumSubsequenceCount(string text, string pattern) {
			long long ans   = 0;
			long long count = 0;
			vector<long long> p1count(text.length());
			long long p0count          = 0;
			long long p1c              = 0;
			p1count[text.length() - 1] = 0;
			for(int i = text.length() - 1; i >= 0; i--) {
				if(text[i] == pattern[1]) {
					count++;
				} else if(text[i] == pattern[0]) {
					p0count++;
				}
				if(i - 1 >= 0) {
					p1count[i - 1] = count;
				}
			}
			for(int i = 0; i < text.length(); i++) {
				if(text[i] == pattern[0]) {
					ans += p1count[i];
				}
			}
			ans += max(p0count, count);
			return ans;
		}
	}// namespace maximize_number_of_subsequences_in_a_string

	namespace minimum_operations_to_halve_array_sum {
		int Solution::halveArray(vector<int> &nums) {
			long double sum = 0;
			int ans         = 0;
			priority_queue<long double> pq;
			for(const auto num: nums) {
				pq.push(num);
				sum += num;
			}
			const long double target = sum / 2;
			while(sum > target) {
				auto num = pq.top();
				pq.pop();
				num /= 2;
				sum -= num;
				pq.push(num);
				ans++;
			}
			return ans;
		}
	}// namespace minimum_operations_to_halve_array_sum

	namespace minimum_white_tiles_after_covering_with_carpets {
		int Solution::minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
			const int n = floor.length();
			vector f(numCarpets + 1, vector<int>(n));
			f[0][0] = floor[0] % 2;
			for(int i = 1; i < n; ++i) {
				f[0][i] = f[0][i - 1] + floor[i] % 2;
			}
			for(int i = 1; i <= numCarpets; ++i) {
				// j < carpetLen 的 f[i][j] 均为 0
				for(int j = carpetLen; j < n; ++j) {
					f[i][j] = min(f[i][j - 1] + floor[j] % 2, f[i - 1][j - carpetLen]);
				}
			}
			return f[numCarpets][n - 1];
		}
	}// namespace minimum_white_tiles_after_covering_with_carpets

	namespace count_hills_and_valleys_in_an_array {
		int Solution::countHillValley(vector<int> &nums) {
			int ans      = 0;
			const auto u = unique(nums.begin(), nums.end());
			nums.erase(u, nums.end());
			for(int i = 1; i + 1 < nums.size(); i++) {
				if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1] || nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
					ans++;
				}
			}
			return ans;
		}
	}// namespace count_hills_and_valleys_in_an_array

	namespace count_collisions_on_a_road {
		int Solution::countCollisions(const string &directions) {
			int ans = 0;
			vector<char> status;
			vector<int> count;
			int current = 0;
			for(char ch: directions) {
				if(status.empty()) {
					status.push_back(ch);
					current++;
				} else {
					if(status.back() == ch) {
						current++;
					} else {
						status.push_back(ch);
						count.push_back(current);
						current = 1;
					}
				}
			}
			count.push_back(current);
			for(int i = 0; i + 1 < status.size(); i++) {
				if(status[i] == 'R' && status[i + 1] == 'L') {
					ans += count[i] + count[i + 1];
				} else if(status[i] == 'R' && status[i + 1] == 'S') {
					ans += count[i];
				} else if(status[i] == 'S' && status[i + 1] == 'L') {
					ans += count[i + 1];
				}
			}
			return ans;
		}
	}// namespace count_collisions_on_a_road

	namespace maximum_points_in_an_archery_competition {
		vector<int> Solution::maximumBobPoints(int numArrows, vector<int> &aliceArrows) {
			int maximum = 0;
			int max_n   = 0;
			for(unsigned int n = 1; n < 1 << 11; n++) {
				int rest  = numArrows;
				int score = 0;
				for(int i = 0; i <= 10; i++) {
					if((n & 1 << i) != 0) {
						score += 11 - i;
						rest -= aliceArrows[11 - i] + 1;
					}
					if(rest < 0) {
						goto NEXT_N;
					}
				}
				if(maximum < score) {
					maximum = score;
					max_n   = n;
				}
			NEXT_N:;
			}
			vector ans(aliceArrows.size(), 0);
			for(int i = 0; i <= 10; i++) {
				if((max_n & 1 << i) != 0) {
					numArrows -= aliceArrows[11 - i] + 1;
					ans[11 - i] = aliceArrows[11 - i] + 1;
				}
			}
			ans[0] += numArrows;
			return ans;
		}
	}// namespace maximum_points_in_an_archery_competition

	namespace the_time_when_the_network_becomes_idle {
		int Solution::networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience) {
			unordered_map<int, Node *> um;
			unordered_set<int> nodes;
			for(int i = 0; i < patience.size(); i++) {
				um[i] = new Node(i, patience[i]);
				nodes.insert(i);
			}
			for(auto edge: edges) {
				um[edge[0]]->linked.insert(edge[1]);
				um[edge[1]]->linked.insert(edge[0]);
			}
			auto comp = [](const pair<int, int> &s1, const pair<int, int> &s2) -> bool { return s1.second > s2.second; };
			priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq;
			pq.push(make_pair(0, 0));
			while(!nodes.empty()) {
				auto [num, len] = pq.top();
				pq.pop();
				if(nodes.contains(num)) {
					nodes.erase(num);
					Node *node = um[num];
					node->time = len;
					for(auto next: node->linked) {
						if(nodes.contains(next)) {
							pq.push(make_pair(next, len + 1));
						}
					}
				}
			}
			int ans = 0;
			for(auto [num, node]: um) {
				if(num != 0) {
					int resent_num = node->time * 2 / node->patience;
					if(node->time * 2 % node->patience == 0) {
						resent_num--;
					}
					ans = max(ans, resent_num * node->patience + 2 * node->time + 1);
				}
			}
			return ans;
		}
	}// namespace the_time_when_the_network_becomes_idle

	namespace two_sum_iv_input_is_a_bst {
		bool Solution::findTarget(TreeNode *root, int k) {
			set<int> s;
			unordered_map<int, int> count;
			queue<TreeNode *> que;
			que.push(root);
			while(!que.empty()) {
				const auto *node = que.front();
				que.pop();
				s.insert(node->val);
				count[node->val]++;
				if(node->left != nullptr) {
					que.push(node->left);
				}
				if(node->right != nullptr) {
					que.push(node->right);
				}
			}
			bool ans = false;
			for(auto it = s.begin(); it != s.end(); ++it) {
				int other = k - *it;
				if(other == *it) {
					if(count[other] > 1) {
						ans = true;
						break;
					}
				} else if(s.contains(other)) {
					ans = true;
					break;
				}
			}
			return ans;
		}
	}// namespace two_sum_iv_input_is_a_bst

	namespace remove_colored_pieces_if_both_neighbors_are_the_same_color {
		bool Solution::winnerOfGame(string colors) {
			int a_count = 0;
			int b_count = 0;
			vector vec(colors.length(), true);
			vec[0]                   = false;
			vec[colors.length() - 1] = false;
			for(int i = 0; i + 1 < colors.length(); i++) {
				if(colors[i] != colors[i + 1]) {
					vec[i]     = false;
					vec[i + 1] = false;
				}
			}
			for(int i = 0; i + 1 < colors.length(); i++) {
				if(vec[i]) {
					if(colors[i] == 'A') {
						a_count++;
					} else {
						b_count++;
					}
				}
			}
			return a_count > b_count;
		}
	}// namespace remove_colored_pieces_if_both_neighbors_are_the_same_color

	namespace k_th_smallest_in_lexicographical_order {
		int Solution::findKthNumber(int n, int k) {
			int curr = 1;
			k--;
			while(k > 0) {
				const int steps = getSteps(curr, n);
				if(steps <= k) {
					k -= steps;
					curr++;
				} else {
					curr = curr * 10;
					k--;
				}
			}
			return curr;
		}

		int Solution::getSteps(int curr, long n) {
			int steps  = 0;
			long first = curr;
			long last  = curr;
			while(first <= n) {
				steps += min(last, n) - first + 1;
				first = first * 10;
				last  = last * 10 + 9;
			}
			return steps;
		}
	}// namespace k_th_smallest_in_lexicographical_order

	namespace image_smoother {
		vector<vector<int>> Solution::imageSmoother(vector<vector<int>> &img) {
			const int m = img.size();
			const int n = img[0].size();
			auto ans    = vector(m, vector<int>(n));
			for(int i = 0; i < m; i++) {
				for(int j = 0; j < n; j++) {
					pair<int, int> cells[9] = {make_pair(i - 1, j - 1), make_pair(i - 1, j), make_pair(i - 1, j + 1),
					                           make_pair(i, j - 1), make_pair(i, j), make_pair(i, j + 1),
					                           make_pair(i + 1, j - 1), make_pair(i + 1, j), make_pair(i + 1, j + 1)};
					int sum                 = 0;
					int count               = 0;
					for(int k = 0; k < 9; k++) {
						auto [x, y] = cells[k];
						if(0 <= x && x < m && 0 <= y && y < n) {
							count++;
							sum += img[x][y];
						}
					}
					ans[i][j] = sum / count;
				}
			}
			return ans;
		}
	}// namespace image_smoother

	namespace factorial_trailing_zeroes {
		int Solution::trailingZeroes(int n) {
			unsigned int pow5   = 5;
			unsigned int pow2   = 2;
			unsigned int count5 = 0;
			unsigned int count2 = 0;
			while(n / pow5 != 0) {
				count5 += n / pow5;
				pow5 *= 5;
			}
			while(n / pow2 != 0) {
				count2 += n / pow2;
				pow2 *= 2;
			}
			return min(count2, count5);
		}
	}// namespace factorial_trailing_zeroes

	namespace baseball_game {
		int Solution::calPoints(vector<string> &ops) {
			vector<int> stk;
			for(const string &op: ops) {
				if(op == "+") {
					const int score1 = stk.back();
					const int score2 = *(stk.rbegin() + 1);
					stk.push_back(score1 + score2);
				} else if(op == "D") {
					stk.push_back(2 * stk.back());
				} else if(op == "C") {
					stk.pop_back();
				} else {
					stringstream ss;
					ss << op;
					int score;
					ss >> score;
					stk.push_back(score);
				}
			}
			int ans = 0;
			for(const auto score: stk) {
				ans += score;
			}
			return ans;
		}
	}// namespace baseball_game

	namespace minimum_deletions_to_make_array_beautiful {
		int Solution::minDeletion(vector<int> &nums) {
			vector<int> indexes;
			for(int i = 0; i + 1 < nums.size(); i++) {
				if(nums[i] == nums[i + 1]) {
					indexes.push_back(i);
				}
			}
			int ans   = 0;
			bool even = true;
			for(const auto index: indexes) {
				if(even && index % 2 == 0 || !even && index % 2 != 0) {
					ans++;
					even = !even;
				}
			}
			if((nums.size() - ans) % 2 != 0) {
				ans++;
			}
			return ans;
		}
	}// namespace minimum_deletions_to_make_array_beautiful

	namespace find_palindrome_with_fixed_length {
		unsigned long long qmi(unsigned long long m, unsigned long long k) {
			unsigned long long res = 1;
			unsigned long long t   = m;
			while(k != 0U) {
				if((k & 1) != 0U) {
					res = res * t;
				}
				t = t * t;
				k >>= 1;
			}
			return res;
		}

		vector<long long> Solution::kthPalindrome(vector<int> &queries, int intLength) {
			vector<long long> ans;
			if(intLength == 1) {
				for(auto query: queries) {
					if(query < 10) {
						ans.push_back(query);
					} else {
						ans.push_back(-1);
					}
				}
				return ans;
			}
			if(intLength == 2) {
				for(auto query: queries) {
					if(query < 10) {
						ans.push_back(query * 10 + query);
					} else {
						ans.push_back(-1);
					}
				}
				return ans;
			}
			int n = (intLength + 1) / 2;
			vector<unsigned long long> q10(n + 1);
			for(int i = 1; i <= n; i++) {
				q10[i] = qmi(10, n - i);
			}
			for(auto query: queries) {
				vector<unsigned long long> num;
				int n1 = query / q10[1] + 1;
				if(n1 == 10 && query % q10[1] == 0) {
					stringstream ss;
					for(int i = 0; i < intLength; i++) {
						ss << 9;
					}
					long long res;
					ss >> res;
					ans.push_back(res);
					continue;
				}
				if(n1 > 9) {
					ans.push_back(-1);
					continue;
				}
				if(n1 < 10 && query % q10[1] == 0) {
					n1--;
					query = (query - 1) % q10[1] + 1;
				} else {
					query %= q10[1];
				}
				num.push_back(n1);
				for(int i = 2; i <= n; i++) {
					int digit = query / q10[i];
					if(i == n) {
						digit--;
					} else if(query != q10[i] && query % q10[i] == 0) {
						digit--;
					} else if(query == q10[i]) {
						digit = 0;
					}
					query %= q10[i];
					num.push_back((digit + 10) % 10);
				}
				stringstream ss;
				for(int digit: num) {
					ss << digit;
				}
				int i = num.size() - 1;
				if(intLength % 2 != 0) {
					i--;
				}
				while(i >= 0) {
					ss << num[i];
					--i;
				}
				long long res;
				ss >> res;
				ans.push_back(res);
			}
			return ans;
		}
	}// namespace find_palindrome_with_fixed_length

	namespace find_missing_observations {
		vector<int> Solution::missingRolls(vector<int> &rolls, int mean, int n) {
			const int m = rolls.size();
			int sum     = (m + n) * mean;
			for(const auto roll: rolls) {
				sum -= roll;
			}
			if(sum < n || sum > 6 * n) {
				return {};
			}
			vector ans(n, sum / n);
			sum %= n;
			for(int i = 0; i < sum; i++) {
				ans[i]++;
			}
			return ans;
		}
	}// namespace find_missing_observations

	namespace binary_number_with_alternating_bits {
		bool Solution::hasAlternatingBits(int n) {
			stringstream ss;
			while(n != 0) {
				ss << n % 2;
				n /= 2;
			}
			string str;
			ss >> str;
			for(int i = 0; i + 1 < str.length(); i++) {
				if(str[i] == str[i + 1]) {
					return false;
				}
			}
			return true;
		}
	}// namespace binary_number_with_alternating_bits

	namespace maximize_the_confusion_of_an_exam {
		int Solution::maxConsecutiveAnswers(string answerKey, int k) {
			if(answerKey.length() == 1) {
				return 1;
			}
			vector<int> t_count(answerKey.length());
			vector<int> f_count(answerKey.length());
			int t_current = 0;
			int f_current = 0;
			for(int i = 0; i < t_count.size(); i++) {
				if(answerKey[i] == 'T') {
					t_current++;
				} else {
					f_current++;
				}
				t_count[i] = t_current;
				f_count[i] = f_current;
			}
			int l      = 1;
			int r      = answerKey.size();
			auto check = [&answerKey, &t_count, &f_count, &k](int len) -> bool {
				for(int i = 0; i + len <= answerKey.length(); i++) {
					int tc = t_count[i + len - 1] - (i - 1 >= 0 ? t_count[i - 1] : 0);
					int fc = f_count[i + len - 1] - (i - 1 >= 0 ? f_count[i - 1] : 0);
					if(min(tc, fc) <= k) {
						return true;
					}
				}
				return false;
			};
			while(l < r) {
				if(l + 1 == r) {
					if(check(r)) {
						return r;
					}
					return l;
				}
				const int mid = (l + r) / 2;
				if(check(mid)) {
					l = mid;
				} else {
					r = mid;
				}
			}
			return -1;
		}
	}// namespace maximize_the_confusion_of_an_exam

	namespace find_servers_that_handled_most_number_of_requests {
		vector<int> Solution::busiestServers(int k, vector<int> &arrival, vector<int> &load) {
			vector<int> ans;
			vector count(k, 0);
			set<int> available;
			for(int i = 0; i < k; i++) {
				available.insert(i);
			}
			priority_queue<event> events;
			for(int i = 0; i < arrival.size(); i++) {
				event e = {arrival[i], true, i};
				events.push(e);
			}
			while(!events.empty()) {
				event e = events.top();
				events.pop();
				if(e.start) {
					if(!available.empty()) {
						auto it = available.lower_bound(e.index % k);
						if(it == available.end()) {
							it = available.begin();
						}
						event next = {e.time + load[e.index], false, e.index, *it};
						events.push(next);
						available.erase(it);
					}
				} else {
					//end
					available.insert(e.server_index);
					count[e.server_index]++;
				}
			}
			const int maximum = *max_element(count.begin(), count.end());
			for(int i = 0; i < k; i++) {
				if(count[i] == maximum) {
					ans.push_back(i);
				}
			}
			return ans;
		}

		bool event::operator<(const event &e) const {
			if(this->time != e.time) {
				return this->time > e.time;
			}
			return this->start;
		}
	}// namespace find_servers_that_handled_most_number_of_requests

	namespace self_dividing_numbers {
		vector<int> Solution::selfDividingNumbers(int left, int right) {
			vector<int> ans;
			for(int i = left; i <= right; ++i) {
				stringstream ss;
				ss << i;
				char ch;
				bool flag = true;
				while(ss >> ch) {
					const int num = ch - '0';
					if(num == 0) {
						flag = false;
						break;
					}
					if(i % num != 0) {
						flag = false;
						break;
					}
				}
				if(flag) {
					ans.push_back(i);
				}
			}
			return ans;
		}
	}// namespace self_dividing_numbers

	namespace array_of_doubled_pairs {
		bool Solution::canReorderDoubled(vector<int> &arr) {
			multiset<int> positive;
			multiset<int, greater<>> negative;
			for(auto num: arr) {
				if(num >= 0) {
					positive.insert(num);
				} else {
					negative.insert(num);
				}
			}
			while(!positive.empty()) {
				const int num = *positive.begin();
				positive.erase(positive.begin());
				auto it = positive.find(num * 2);
				if(it == positive.end()) {
					return false;
				}
				positive.erase(it);
			}
			while(!negative.empty()) {
				const int num = *negative.begin();
				negative.erase(negative.begin());
				auto it = negative.find(num * 2);
				if(it == negative.end()) {
					return false;
				}
				negative.erase(it);

				negative.erase(it);
			}
			return true;
		}
	}// namespace array_of_doubled_pairs

	namespace strong_password_checker {
		int Solution::strongPasswordChecker(const string &password) {
			const int n    = password.length();
			bool has_lower = false;
			bool has_upper = false;
			bool has_digit = false;
			for(const char ch: password) {
				if(islower(ch) != 0) {
					has_lower = true;
				} else if(isupper(ch) != 0) {
					has_upper = true;
				} else if(isdigit(ch) != 0) {
					has_digit = true;
				}
			}
			const int categories = static_cast<int>(has_lower) + static_cast<int>(has_upper) + static_cast<int>(has_digit);

			if(n < 6) {
				return max(6 - n, 3 - categories);
			}
			if(n <= 20) {
				int replace  = 0;
				int count    = 0;
				char current = '#';

				for(const char ch: password) {
					if(ch == current) {
						++count;
					} else {
						replace += count / 3;
						count   = 1;
						current = ch;
					}
				}
				replace += count / 3;
				return max(replace, 3 - categories);
			}
			// 替换次数和删除次数
			int replace = 0;
			int remove  = n - 20;
			// k mod 3 = 1 的组数，即删除 2 个字符可以减少 1 次替换操作
			int rm2   = 0;
			int count = 0;
			char cur  = '#';

			for(const char ch: password) {
				if(ch == cur) {
					++count;
				} else {
					if(remove > 0 && count >= 3) {
						if(count % 3 == 0) {
							// 如果是 k % 3 = 0 的组，那么优先删除 1 个字符，减少 1 次替换操作
							--remove;
							--replace;
						} else if(count % 3 == 1) {
							// 如果是 k % 3 = 1 的组，那么存下来备用
							++rm2;
						}
						// k % 3 = 2 的组无需显式考虑
					}
					replace += count / 3;
					count = 1;
					cur   = ch;
				}
			}
			if(remove > 0 && count >= 3) {
				if(count % 3 == 0) {
					--remove;
					--replace;
				} else if(count % 3 == 1) {
					++rm2;
				}
			}
			replace += count / 3;

			// 使用 k % 3 = 1 的组的数量，由剩余的替换次数、组数和剩余的删除次数共同决定
			const int use2 = min({replace, rm2, remove / 2});
			replace -= use2;
			remove -= use2 * 2;
			// 由于每有一次替换次数就一定有 3 个连续相同的字符（k / 3 决定），因此这里可以直接计算出使用 k % 3 = 2 的组的数量
			const int use3 = min(replace, remove / 3);
			replace -= use3;
			remove -= use3 * 3;
			return n - 20 + max(replace, 3 - categories);
		}
	}// namespace strong_password_checker

	namespace number_of_ways_to_select_buildings {
		long long Solution::numberOfWays(string s) {
			const unsigned int n = s.length();
			vector<unsigned int> prev0(n, 0);
			vector<unsigned int> prev1(n, 0);
			vector<unsigned int> post0(n, 0);
			vector<unsigned int> post1(n, 0);
			unsigned current0 = 0;
			unsigned current1 = 0;
			for(int i = 0; i < n; i++) {
				prev0[i] = current0;
				prev1[i] = current1;
				if(s[i] == '0') {
					current0++;
				} else {
					current1++;
				}
			}
			current0 = 0;
			current1 = 0;
			for(int i = n - 1; i >= 0; i--) {
				post0[i] = current0;
				post1[i] = current1;
				if(s[i] == '0') {
					current0++;
				} else {
					current1++;
				}
			}
			long long ans = 0;
			for(unsigned i = 0; i < n; i++) {
				if(s[i] == '0') {
					ans += static_cast<long long>(prev1[i]) * post1[i];
				} else {
					ans += static_cast<long long>(prev0[i]) * post0[i];
				}
			}
			return ans;
		}
	}// namespace number_of_ways_to_select_buildings

	namespace sum_of_scores_of_built_strings {
		long long Solution::sumScores(string s) {
			const int n   = s.length();
			long long ans = n;
			int l         = 0;
			int r         = 0;
			vector z(n, 0);
			for(int i = 1; i < n; ++i) {
				if(i <= r && z[i - l] < r - i + 1) {
					z[i] = z[i - l];
				} else {
					z[i] = max(0, r - i + 1);
					while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
						++z[i];
					}
				}
				if(i + z[i] - 1 > r) {
					l = i;
					r = i + z[i] - 1;
				}
				ans += z[i];
			}
			return ans;
		}
	}// namespace sum_of_scores_of_built_strings

	/**
	 * \brief 6055. Minimum Number of Operations to Convert Time
	 */
	namespace minimum_number_of_operations_to_convert_time {
		int Solution::convertTime(string current, string correct) {
			const int current_h = (current[0] - '0') * 10 + (current[1] - '0');
			const int current_m = (current[3] - '0') * 10 + (current[4] - '0');
			const int correct_h = (correct[0] - '0') * 10 + (correct[1] - '0');
			const int correct_m = (correct[3] - '0') * 10 + (correct[4] - '0');
			int diff            = correct_h * 60 + correct_m - (current_h * 60 + current_m);
			if(diff < 0) {
				diff += 24 * 60;
			}
			int ans = 0;
			ans += diff / 60;
			diff %= 60;
			ans += diff / 15;
			diff %= 15;
			ans += diff / 5;
			diff %= 5;
			ans += diff;
			return ans;
		}
	}// namespace minimum_number_of_operations_to_convert_time

	/**
	 * \brief 5235. Find Players With Zero or One Losses
	 */
	namespace find_players_with_zero_or_one_losses {
		vector<vector<int>> Solution::findWinners(vector<vector<int>> &matches) {
			map<unsigned, unsigned> lose;
			for(auto match: matches) {
				lose[match[0]] += 0;
				lose[match[1]] += 1;
			}
			vector<vector<int>> ans(2);
			vector<int> ans1;
			vector<int> ans2;
			for(auto [player, count]: lose) {
				if(count == 0) {
					ans1.push_back(player);
				} else if(count == 1) {
					ans2.push_back(player);
				}
			}
			ans[0] = ans1;
			ans[1] = ans2;
			return ans;
		}
	}// namespace find_players_with_zero_or_one_losses

	/**
	 * \brief 5219. Maximum Candies Allocated to K Children
	 */
	namespace maximum_candies_allocated_to_k_children {
		int Solution::maximumCandies(vector<int> &candies, long long k) {
			sort(candies.begin(), candies.end());
			long long sum = 0;
			for(const auto candy: candies) {
				sum += candy;
			}
			int l = 1;
			int r = sum / k;
			if(sum < k) {
				return 0;
			}
			while(l < r) {
				if(l + 1 == r) {
					unsigned long long count = 0;
					for(auto it = candies.rbegin(); it != candies.rend() && *it >= r; ++it) {
						count += *it / r;
						if(count > k) {
							break;
						}
					}
					if(count > k) {
						return r;
					}
					return l;
				}
				const int m              = (l + r) / 2;
				unsigned long long count = 0;
				for(auto it = candies.rbegin(); it != candies.rend() && *it >= m; ++it) {
					count += *it / m;
					if(count > k) {
						break;
					}
				}
				if(count >= k) {
					l = m;
				} else if(count < k) {
					r = m;
				}
			}
			return (l + r) / 2;
		}
	}// namespace maximum_candies_allocated_to_k_children

	namespace encrypt_and_decrypt_strings {
		Encrypter::Encrypter(vector<char> &keys, vector<string> &values, vector<string> &dictionary) {
			for(int i = 0; i < keys.size(); ++i) {
				mp[keys[i] - 'a'] = values[i];
			}
			for(const auto &s: dictionary) {
				++count[encrypt(s)];
			}
		}

		string Encrypter::encrypt(const string &word1) const {
			string res;
			for(const char ch: word1) {
				const auto &s = mp[ch - 'a'];
				if(s.empty()) {
					return "";
				}
				res += s;
			}
			return res;
		}

		int Encrypter::decrypt(const string &word2) {
			if(count.contains(word2)) {
				count[word2] += 0;
				return count[word2];
			}
			// 防止把不在 cnt 中的字符串加进去
			return 0;
		}
	}// namespace encrypt_and_decrypt_strings

	namespace range_sum_query_mutable {
		NumArray::NumArray(vector<int> &nums)
		    : nums(nums) {
			const int n = nums.size();
			size        = sqrt(n);
			sum.resize((n + size - 1) / size);// n/size 向上取整
			for(int i = 0; i < n; i++) {
				sum[i / size] += nums[i];
			}
		}

		void NumArray::update(int index, int val) {
			sum[index / size] += val - nums[index];
			nums[index] = val;
		}

		int NumArray::sumRange(int left, int right) const {
			const int b1 = left / size;
			const int i1 = left % size;
			const int b2 = right / size;
			const int i2 = right % size;
			if(b1 == b2) {
				// 区间 [left, right] 在同一块中
				return accumulate(nums.begin() + b1 * size + i1, nums.begin() + b1 * size + i2 + 1, 0);
			}
			const int sum1 = accumulate(nums.begin() + b1 * size + i1, nums.begin() + b1 * size + size, 0);
			const int sum2 = accumulate(nums.begin() + b2 * size, nums.begin() + b2 * size + i2 + 1, 0);
			const int sum3 = accumulate(sum.begin() + b1 + 1, sum.begin() + b2, 0);
			return sum1 + sum2 + sum3;
		}
	}// namespace range_sum_query_mutable

	namespace process_restricted_friend_requests {
		vector<bool> Solution::friendRequests(int n, vector<vector<int>> &restrictions, vector<vector<int>> &requests) {
			UnionFind uf(n);
			vector<bool> ans(requests.size());
			auto check = [&uf, &restrictions](int x, int y) -> bool {
				x = uf.find(x);
				y = uf.find(y);
				if(x > y) {
					swap(x, y);
				}
				for(auto &restriction: restrictions) {
					int i = uf.find(restriction[0]);
					int j = uf.find(restriction[1]);
					if(i > j) {
						swap(i, j);
					}
					if(i == x && j == y) {
						return false;
					}
				}
				return true;
			};
			for(int i = 0; i < requests.size(); i++) {
				if(check(requests[i][0], requests[i][1])) {
					uf.unite(requests[i][0], requests[i][1]);
					ans[i] = true;
				} else {
					ans[i] = false;
				}
			}
			return ans;
		}
	}// namespace process_restricted_friend_requests

	namespace prime_number_of_set_bits_in_binary_representation {
		int Solution::countPrimeSetBits(int left, int right) {
			int ans = 0;
			const unordered_set primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
			for(unsigned i = left; i <= right; i++) {
				if(primes.contains(popcount(i))) {
					ans++;
				}
			}
			return ans;
		}
	}// namespace prime_number_of_set_bits_in_binary_representation

	namespace minimum_height_trees {
		vector<int> Solution::findMinHeightTrees(int n, vector<vector<int>> &edges) {
			if(n == 1) {
				return {0};
			}
			vector<vector<int>> adj(n);
			for(auto &edge: edges) {
				adj[edge[0]].emplace_back(edge[1]);
				adj[edge[1]].emplace_back(edge[0]);
			}

			vector parent(n, -1);
			/* 找到与节点 0 最远的节点 x */
			const int x = findLongestNode(0, parent, adj);
			/* 找到与节点 x 最远的节点 y */
			int y = findLongestNode(x, parent, adj);
			/* 求出节点 x 到节点 y 的路径 */
			vector<int> path;
			parent[x] = -1;
			while(y != -1) {
				path.emplace_back(y);
				y = parent[y];
			}
			const int m = path.size();
			if(m % 2 == 0) {
				return {path[m / 2 - 1], path[m / 2]};
			}
			return {path[m / 2]};
		}

		int Solution::findLongestNode(int u, vector<int> &parent, vector<vector<int>> &adj) {
			const int n = adj.size();
			queue<int> qu;
			vector<bool> visit(n);
			qu.emplace(u);
			visit[u] = true;
			int node = -1;

			while(!qu.empty()) {
				const int curr = qu.front();
				qu.pop();
				node = curr;
				for(auto &v: adj[curr]) {
					if(!visit[v]) {
						visit[v]  = true;
						parent[v] = curr;
						qu.emplace(v);
					}
				}
			}
			return node;
		}
	}// namespace minimum_height_trees

	namespace rotate_string {
		bool Solution::rotateString(string s, const string &goal) {
			if(s.length() != goal.length()) {
				return false;
			}
			s += s;
			return s.find(goal) != string::npos;
		}
	}// namespace rotate_string

	namespace n_ary_tree_level_order_traversal {
		vector<vector<int>> Solution::levelOrder(Node *root) {
			queue<pair<int, Node *>> q;
			vector<vector<int>> ans;
			if(root == nullptr) {
				return ans;
			}
			q.push(make_pair(0, root));
			while(!q.empty()) {
				auto [level, node] = q.front();
				if(ans.size() == level) {
					ans.emplace_back();
				}
				ans[level].push_back(node->val);
				q.pop();
				for(auto *next: node->children) {
					q.push(make_pair(level + 1, next));
				}
			}
			return ans;
		}
	}// namespace n_ary_tree_level_order_traversal

	namespace reaching_points {
		bool Solution::reachingPoints(int sx, int sy, int tx, int ty) {
			while(tx > sx && ty > sy && tx != ty) {
				if(tx > ty) {
					tx %= ty;
				} else {
					ty %= tx;
				}
			}
			if(tx == sx && ty == sy) {
				return true;
			}
			if(tx == sx) {
				return ty > sy && (ty - sy) % tx == 0;
			}
			if(ty == sy) {
				return tx > sx && (tx - sx) % ty == 0;
			}
			return false;
		}
	}// namespace reaching_points

	namespace maximum_product_after_k_increments {
		int Solution::maximumProduct(vector<int> &nums, int k) {
			priority_queue<int, vector<int>, greater<int>> pq;
			for(auto num: nums) {
				pq.push(num);
			}
			while(k-- != 0) {
				const int num = pq.top();
				pq.pop();
				pq.push(num + 1);
			}
			long long ans = 1;
			while(!pq.empty()) {
				const int num = pq.top();
				pq.pop();
				ans *= num;
				ans %= 1000000007;
			}
			return ans;
		}
	}// namespace maximum_product_after_k_increments

	namespace maximum_total_beauty_of_the_gardens {
		long long Solution::maximumBeauty(vector<int> &flowers, long long newFlowers, int target, int full, int partial) {
			const int n = flowers.size();
			sort(flowers.begin(), flowers.end());
			for(int i = 0; i < n; i++) {
				flowers[i] = min(flowers[i], target);
			}
			long long ans = 0;
			vector<long long> sum(n + 1, 0);///< 当前项之前的和
			for(int i = 0; i < n; i++) {
				sum[i + 1] = sum[i] + flowers[i];
			}
			for(int i = 0, j = 0; i <= n; i++) {
				const long long rest = newFlowers - (static_cast<long long>(target) * (n - i) - (sum[n] - sum[i]));///< 补齐后n-i项到target后剩余的
				if(rest >= 0) {
					while(j < i && rest >= static_cast<long long>(flowers[j]) * j - sum[j]) {
						//将前j项补齐到flowers[j]
						j++;
					}
					ans = max(ans, static_cast<long long>(full) * (n - i) + (j == 0 ? 0 : static_cast<long long>(partial) * min(static_cast<long long>(target - 1), (rest + sum[j]) / j)));
				}
				if(i < n && flowers[i] == target) {
					break;
				}
			}
			return ans;
		}
	}// namespace maximum_total_beauty_of_the_gardens

	namespace count_numbers_with_unique_digits {
		int Solution::countNumbersWithUniqueDigits(int n) {
			if(n == 0) {
				return 1;
			}
			vector<int> dp(n + 1);
			dp[1] = 9;
			for(int i = 2; i <= n; ++i) {
				dp[i] = dp[i - 1] * (10 - (i - 1));
			}
			int ans = 0;
			for(int i = 1; i <= n; ++i) {
				ans += dp[i];
			}
			return ans + 1;
		}
	}// namespace count_numbers_with_unique_digits

	namespace number_of_lines_to_write_string {
		vector<int> Solution::numberOfLines(vector<int> &widths, string s) {
			int lines   = 1;
			int current = 0;
			for(int i = 0; i < s.length(); i++) {
				if(current + widths[s[i] - 'a'] > 100) {
					current = 0;
					lines++;
				}
				current += widths[s[i] - 'a'];
			}
			return {lines, current};
		}
	}// namespace number_of_lines_to_write_string

	namespace permutation_in_string {
		bool Solution::checkInclusion(const string &s1, string s2) {
			if(s1.length() > s2.length()) {
				return false;
			}
			unordered_map<char, int> um1;
			unordered_map<char, int> um2;
			for(char ch: s1) {
				um1[ch]++;
			}
			for(int i = 0; i < s1.length(); i++) {
				um2[s2[i]]++;
			}
			if(um2 == um1) {
				return true;
			}
			for(int i = 0; i + s1.length() < s2.length(); i++) {
				um2[s2[i]]--;
				um2[s2[i + s1.length()]]++;
				if(um2[s2[i]] == 0) {
					um2.erase(s2[i]);
				}
				if(um2 == um1) {
					return true;
				}
			}
			return false;
		}
	}// namespace permutation_in_string

	namespace insert_delete_getrandom_o1 {
		RandomizedSet::RandomizedSet() {
			generator    = default_random_engine(time(nullptr));
			distribution = uniform_int_distribution(0, INT_MAX);
		}

		bool RandomizedSet::insert(int val) {
			if(static_cast<unsigned int>(map.contains(val)) != 0U) {
				return false;
			}
			nums.push_back(val);
			map[val] = nums.size() - 1;
			return true;
		}

		bool RandomizedSet::remove(int val) {
			if(static_cast<unsigned int>(map.contains(val)) == 0U) {
				return false;
			}
			const int index = map[val];
			const int last  = nums.back();
			nums[index]     = last;
			map[last]       = index;
			nums.pop_back();
			map.erase(val);
			return true;
		}

		int RandomizedSet::getRandom() { return nums[distribution(generator) % nums.size()]; }
	}// namespace insert_delete_getrandom_o1

	namespace projection_area_of_3d_shapes {
		int Solution::projectionArea(vector<vector<int>> &grid) {
			const int n  = grid.size();
			int xy       = 0;
			int xz       = 0;
			int yz       = 0;
			auto grid_xz = vector(51, vector(51, 0));
			auto grid_yz = vector(51, vector(51, 0));
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(grid[i][j] != 0) {
						xy++;
					}
					for(int k = 0; k < grid[i][j]; k++) {
						grid_xz[i][k] = 1;
						grid_yz[j][k] = 1;
					}
				}
			}
			for(int i = 0; i < 51; i++) {
				for(int j = 0; j < 51; j++) {
					if(grid_xz[i][j] != 0) {
						xz++;
					}
					if(grid_yz[i][j] != 0) {
						yz++;
					}
				}
			}
			return xy + yz + xz;
		}
	}// namespace projection_area_of_3d_shapes

	namespace design_parking_system {
		ParkingSystem::ParkingSystem(int big, int medium, int small)
		    : big(big), medium(medium), small(small) {}

		bool ParkingSystem::addCar(int carType) {
			switch(carType) {
				case 1: {
					if(big > 0) {
						big--;
						return true;
					}
					return false;
				}
				case 2: {
					if(medium > 0) {
						medium--;
						return true;
					}
					return false;
				}
				case 3: {
					if(small > 0) {
						small--;
						return true;
					}
					return false;
				}
				default: return false;
			}
		}
	}// namespace design_parking_system

	namespace range_sum_query_immutable {
		NumArray::NumArray(vector<int> &nums) {
			pref_sum    = vector<int>(nums.size());
			pref_sum[0] = nums[0];
			for(int i = 1; i < nums.size(); i++) {
				pref_sum[i] = pref_sum[i - 1] + nums[i];
			}
		}

		int NumArray::sumRange(int left, int right) const { return pref_sum[right] - (left - 1 >= 0 ? pref_sum[left - 1] : 0); }
	}// namespace range_sum_query_immutable

	namespace house_robber {
		int Solution::rob(vector<int> &nums) {
			if(nums.size() == 1) {
				return nums[0];
			}
			vector<int> dp(nums.size());
			dp[0] = nums[0];
			dp[1] = max(nums[0], nums[1]);
			for(int i = 2; i < nums.size(); i++) {
				dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
			}
			return dp[nums.size() - 1];
		}
	}// namespace house_robber

	namespace triangle {
		int Solution::minimumTotal(vector<vector<int>> &triangle) {
			vector<vector<int>> dp = triangle;
			for(int i = 1; i < triangle.size(); i++) {
				for(int j = 0; j < triangle[i].size(); j++) {
					if(j == 0) {
						dp[i][j] = dp[i - 1][j] + triangle[i][j];
					} else if(j == triangle[i].size() - 1) {
						dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
					} else {
						dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
					}
				}
			}
			int ans = dp.back()[0];
			for(int i = 0; i < dp.back().size(); i++) {
				ans = min(ans, dp.back()[i]);
			}
			return ans;
		}
	}// namespace triangle

	namespace lowest_common_ancestor_of_a_binary_search_tree {
		TreeNode *Solution::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
			auto *const tnp = new TreeNodeP(root->val);
			TreeNodeP *pp;
			TreeNodeP *qq;
			copy(root, tnp, p->val, q->val, &pp, &qq);
			TreeNodeP *current = pp;
			while(current != nullptr) {
				current->ed = true;
				current     = current->parent;
			}
			current = qq;
			while(current != nullptr) {
				if(current->ed) {
					return current->mirror;
				}
				current = current->parent;
			}
			return root;
		}

		void Solution::copy(TreeNode *tn, TreeNodeP *tnp, int low, int high, TreeNodeP **p, TreeNodeP **q) {
			tnp->mirror = tn;
			if(tn->val == low) {
				*p = tnp;
			} else if(tn->val == high) {
				*q = tnp;
			}
			if(tn->left != nullptr) {
				tnp->left         = new TreeNodeP(tn->left->val);
				tnp->left->parent = tnp;
				copy(tn->left, tnp->left, low, high, p, q);
			}
			if(tn->right != nullptr) {
				tnp->right         = new TreeNodeP(tn->right->val);
				tnp->right->parent = tnp;
				copy(tn->right, tnp->right, low, high, p, q);
			}
		}
	}// namespace lowest_common_ancestor_of_a_binary_search_tree

	namespace shuffle_an_array {
		vector<int> Solution::reset() { return nums; }

		vector<int> Solution::shuffle() const {
			vector<int> ans;
			vector<int> cpy = nums;
			while(!cpy.empty()) {
				const int idx = rand() % cpy.size();
				ans.emplace_back(cpy[idx]);
				cpy.erase(cpy.begin() + idx);
			}
			return ans;
		}

		Solution::Solution(vector<int> &nums)
		    : nums(nums) { srand(time(nullptr)); }
	}// namespace shuffle_an_array

	namespace find_all_anagrams_in_a_string {
		vector<int> Solution::findAnagrams(string s, const string &p) {
			vector<int> ans;
			unordered_map<char, int> um_p;
			for(char ch: p) {
				um_p[ch]++;
			}
			unordered_map<char, int> um_s;
			for(int i = 0; i < p.length(); i++) {
				um_s[s[i]]++;
			}
			if(um_s == um_p) {
				ans.emplace_back(0);
			}
			for(int i = p.length(); i < s.length(); i++) {
				um_s[s[i]]++;
				um_s[s[i - p.length()]]--;
				if(um_s[s[i - p.length()]] == 0) {
					um_s.erase(s[i - p.length()]);
				}
				if(um_s == um_p) {
					ans.emplace_back(i - p.length() + 1);
				}
			}
			return ans;
		}
	}// namespace find_all_anagrams_in_a_string

	namespace subarray_product_less_than_k {
		int Solution::numSubarrayProductLessThanK(vector<int> &nums, int k) {
			int ans  = 0;
			int prod = 1;
			int i    = 0;
			for(int j = 0; j < nums.size(); j++) {
				prod *= nums[j];
				while(i <= j && prod >= k) {
					prod /= nums[i];
					i++;
				}
				ans += j - i + 1;
			}
			return ans;
		}
	}// namespace subarray_product_less_than_k

	namespace minimum_size_subarray_sum {
		int Solution::minSubArrayLen(int target, vector<int> &nums) {
			int r   = nums.size() - 1;
			int l   = r;
			int sum = nums[r];
			int ans = 0;
			while(l >= 0 && l <= r) {
				if(nums[l] >= target) {
					return 1;
				}
				while(l - 1 >= 0 && sum + nums[l - 1] < target) {
					sum += nums[--l];
				}
				if(l - 1 >= 0) {
					l--;
					sum += nums[l];
					if(ans == 0) {
						ans = r - l + 1;
					} else {
						ans = min(ans, r - l + 1);
					}
				} else {
					break;
				}
				do {
					sum -= nums[r--];
					if(sum >= target) {
						ans = min(ans, r - l + 1);
					}
				} while(sum >= target && r >= l);
			}
			return ans;
		}
	}// namespace minimum_size_subarray_sum

	namespace populating_next_right_pointers_in_each_node_ii {
		Node *Solution::connect(Node *root) {
			if(root == nullptr) {
				return nullptr;
			}
			int prev_level  = 0;
			Node *prev_node = root;
			queue<pair<int, Node *>> q;
			if(root->left != nullptr) {
				q.emplace(1, root->left);
			}
			if(root->right != nullptr) {
				q.emplace(1, root->right);
			}
			while(!q.empty()) {
				auto [level, node] = q.front();
				q.pop();
				if(level == prev_level) {
					prev_node->next = node;
				}
				prev_level = level;
				prev_node  = node;
				if(node->left != nullptr) {
					q.emplace(level + 1, node->left);
				}
				if(node->right != nullptr) {
					q.emplace(level + 1, node->right);
				}
			}
			return root;
		}
	}// namespace populating_next_right_pointers_in_each_node_ii

	namespace subtree_of_another_tree {
		bool Solution::isSubtree(TreeNode *root, TreeNode *subRoot) {
			if(root == nullptr) {
				return false;
			}
			queue<TreeNode *> q;
			q.push(root);
			while(!q.empty()) {
				auto *const node = q.front();
				q.pop();
				if(equal(node, subRoot)) {
					return true;
				}
				if(node->left != nullptr) {
					q.push(node->left);
				}
				if(node->right != nullptr) {
					q.push(node->right);
				}
			}
			return false;
		}

		bool Solution::equal(TreeNode *tn1, TreeNode *tn2) {
			if(static_cast<int>(tn1 == nullptr) + static_cast<int>(tn2 == nullptr) == 1) {
				return false;
			}
			if(tn1 == nullptr && tn2 == nullptr) {
				return true;
			}
			if(tn1->val != tn2->val) {
				return false;
			}
			if(static_cast<int>(tn1->left == nullptr) + static_cast<int>(tn2->left == nullptr) == 1) {
				return false;
			}
			if(static_cast<int>(tn1->right == nullptr) + static_cast<int>(tn2->right == nullptr) == 1) {
				return false;
			}
			return equal(tn1->left, tn2->left) && equal(tn1->right, tn2->right);
		}
	}// namespace subtree_of_another_tree

	namespace shortest_path_in_binary_matrix {
		int Solution::shortestPathBinaryMatrix(vector<vector<int>> &grid) {
			int n       = grid.size();
			auto levels = vector(n, vector(n, -1));
			auto cmp    = [&n](const tuple<int, int, int> &t1, const tuple<int, int, int> &t2) {
                const auto &[level1, x1, y1] = t1;
                const auto &[level2, x2, y2] = t2;
                const int dx1                = abs(n - 1 - x1);
                const int dy1                = abs(n - 1 - y1);
                const int dx2                = abs(n - 1 - x2);
                const int dy2                = abs(n - 1 - y2);
                return level1 + dx1 + dy1 - min(dx1, dy1) > level2 + dx2 + dy2 - min(dx2, dy2);
			};
			priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> pq(cmp);
			if(grid[0][0] == 0 && grid[n - 1][n - 1] == 0) {
				pq.push(make_tuple(1, 0, 0));
			} else {
				return -1;
			}
			while(!pq.empty()) {
				auto [level, x, y] = pq.top();
				if(x == n - 1 && y == n - 1) {
					return level;
				}
				pq.pop();
				if(levels[x][y] == -1 || levels[x][y] > level) {
					levels[x][y] = level;
				} else {
					continue;
				}
				pair<int, int> nexts[8] = {make_pair(x - 1, y - 1), make_pair(x - 1, y), make_pair(x - 1, y + 1),
				                           make_pair(x, y - 1), make_pair(x, y + 1),
				                           make_pair(x + 1, y - 1), make_pair(x + 1, y), make_pair(x + 1, y + 1)};
				for(auto [next_x, next_y]: nexts) {
					if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && grid[next_x][next_y] == 0 && (levels[next_x][next_y] == -1 || levels[next_x][next_y] > level + 1)) {
						pq.push(make_tuple(level + 1, next_x, next_y));
					}
				}
			}
			return -1;
		}
	}// namespace shortest_path_in_binary_matrix

	namespace surrounded_regions {
		void Solution::solve(vector<vector<char>> &board) {
			const int m = board.size();
			const int n = board[0].size();
			for(int i = 0; i < n; i++) {
				if(board[0][i] == 'O') {
					dfs(board, 0, i);
				}
				if(board[m - 1][i] == 'O') {
					dfs(board, m - 1, i);
				}
			}
			for(int j = 0; j < m; j++) {
				if(board[j][0] == 'O') {
					dfs(board, j, 0);
				}
				if(board[j][n - 1] == 'O') {
					dfs(board, j, n - 1);
				}
			}
			for(int i = 0; i < m; i++) {
				for(int j = 0; j < n; j++) {
					if(board[i][j] == 'O') {
						board[i][j] = 'X';
					}
					if(board[i][j] == 'D') {
						board[i][j] = 'O';
					}
				}
			}
		}

		void Solution::dfs(vector<vector<char>> &board, int x, int y) {
			board[x][y]             = 'D';
			const int m             = board.size();
			const int n             = board[0].size();
			pair<int, int> nexts[4] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
			for(auto [next_x, next_y]: nexts) {
				if(next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && board[next_x][next_y] == 'O') {
					dfs(board, next_x, next_y);
				}
			}
		}
	}// namespace surrounded_regions

	namespace all_paths_from_source_to_target {
		vector<vector<int>> Solution::allPathsSourceTarget(vector<vector<int>> &graph) {
			vector<vector<int>> ans;
			dfs(graph, ans, 0);
			for(auto &path: ans) {
				path.push_back(0);
				path = vector(path.rbegin(), path.rend());
			}
			return ans;
		}

		int Solution::dfs(vector<vector<int>> &graph, vector<vector<int>> &ans, int cur) {
			int ret = 0;
			if(cur == graph.size() - 1) {
				ans.emplace_back(vector(1, cur));
				return 1;
			}
			for(const auto next: graph[cur]) {
				const int n = dfs(graph, ans, next);
				ret += n;
				for(int i = ans.size() - 1, j = 0; j < n; i--, j++) {
					ans[i].emplace_back(cur);
				}
			}
			return ret;
		}
	}// namespace all_paths_from_source_to_target

	namespace permutations_ii {
		vector<vector<int>> Solution::permuteUnique(vector<int> &nums) {
			vector<vector<int>> ans;
			set<vector<int>> s;
			dfs(s, vector<int>(), nums);
			ans.reserve(s.size());
			for(const auto &vec: s) {
				ans.emplace_back(vec);
			}
			return ans;
		}

		void Solution::dfs(set<vector<int>> &s, const vector<int> &current, vector<int> rest) {
			if(rest.empty()) {
				s.insert(current);
				return;
			}
			for(auto it = rest.begin(); it != rest.end(); ++it) {
				vector<int> next_current = current;
				vector<int> next_rest    = rest;
				next_current.push_back(*it);
				next_rest.erase(next_rest.begin() + (it - rest.begin()));
				dfs(s, next_current, next_rest);
			}
		}
	}// namespace permutations_ii

	namespace combination_sum {
		vector<vector<int>> Solution::combinationSum(vector<int> &candidates, int target) {
			sort(candidates.begin(), candidates.end());
			return recurse(candidates, target, 0);
		}

		vector<vector<int>> Solution::recurse(vector<int> &candidates, int target, int index) {
			vector<vector<int>> ans;
			for(int i = index; i < candidates.size(); i++) {
				auto &candidate = candidates[i];
				if(candidate == target) {
					ans.emplace_back(vector(1, candidate));
				} else if(target - candidate >= 1) {
					auto res = recurse(candidates, target - candidate, i);
					for(auto &vec: res) {
						vec.push_back(candidate);
						ans.push_back(vec);
					}
				}
			}
			return ans;
		}
	}// namespace combination_sum

	namespace combination_sum_ii {
		vector<vector<int>> Solution::combinationSum2(vector<int> &candidates, int target) {
			sort(candidates.begin(), candidates.end());
			const auto ret = recurse(candidates, target, -10);
			vector<vector<int>> ans(ret.size());
			for(int i = 0; i < ret.size(); i++) {
				ans[i] = vector<int>(ret[i].size());
				for(int j = 0; j < ret[i].size(); j++) {
					ans[i][j] = candidates[ret[i][j]];
				}
			}
			return ans;
		}

		vector<vector<int>> Solution::recurse(vector<int> &candidates, int target, int index) {
			vector<vector<int>> ans;
			for(int i = max(0, index + 1); i < candidates.size(); i++) {
				if(!(i > 0 && candidates[i] == candidates[i - 1] && index != i - 1)) {
					const auto &candidate = candidates[i];
					if(candidate == target) {
						ans.emplace_back(vector(1, i));
					} else if(target - candidate >= 1) {
						auto res = recurse(candidates, target - candidate, i);
						for(auto &vec: res) {
							vec.push_back(i);
							ans.push_back(vec);
						}
					}
				}
			}
			return ans;
		}
	}// namespace combination_sum_ii

	namespace house_robber_ii {
		int Solution::rob(vector<int> &nums) {
			if(nums.size() == 1) {
				return nums[0];
			}
			auto vec1 = vector(nums.begin(), nums.end() - 1);
			auto vec2 = vector(nums.begin() + 1, nums.end());
			return max(house_robber::Solution::rob(vec1), house_robber::Solution::rob(vec2));
		}
	}// namespace house_robber_ii

	namespace jump_game {
		bool Solution::canJump(vector<int> &nums) {
			vector can(nums.size(), false);
			can[0]   = true;
			int last = 0;
			for(int i = 0; i < nums.size(); i++) {
				if(can[i] && min(i + nums[i], static_cast<int>(nums.size() - 1)) > last) {
					for(int j = last + 1; j <= i + nums[i] && j < nums.size(); j++) {
						can[j] = true;
					}
					last = min(i + nums[i], static_cast<int>(nums.size() - 1));
				}
			}
			return can.back();
		}
	}// namespace jump_game

	namespace jump_game_ii {
		int Solution::jump(vector<int> &nums) {
			const int n = nums.size();
			int ans     = 0;
			int last    = n - 1;
			while(last != 0) {
				for(int i = 0; i < n; i++) {
					if(i + nums[i] >= last) {
						last = i;
						ans++;
						break;
					}
				}
			}
			return ans;
		}
	}// namespace jump_game_ii

	namespace unique_paths {
		int Solution::uniquePaths(int m, int n) {
			vector dp(m, vector(n, 0));
			dp[m - 1][n - 1] = 1;
			for(int i = m - 1; i >= 0; i--) {
				for(int j = n - 1; j >= 0; j--) {
					if(i + 1 < m) {
						dp[i][j] += dp[i + 1][j];
					}
					if(j + 1 < n) {
						dp[i][j] += dp[i][j + 1];
					}
				}
			}
			return dp[0][0];
		}
	}// namespace unique_paths

	namespace longest_palindromic_substring {
		string Solution::longestPalindrome(string s) {
			const int n = s.size();
			if(n < 2) {
				return s;
			}

			int maxLen = 1;
			int begin  = 0;
			// dp[i][j] 表示 s[i..j] 是否是回文串
			vector dp(n, vector<int>(n));
			// 初始化：所有长度为 1 的子串都是回文串
			for(int i = 0; i < n; i++) {
				dp[i][i] = 1;
			}
			// 递推开始
			// 先枚举子串长度
			for(int L = 2; L <= n; L++) {
				// 枚举左边界，左边界的上限设置可以宽松一些
				for(int i = 0; i < n; i++) {
					// 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
					const int j = L + i - 1;
					// 如果右边界越界，就可以退出当前循环
					if(j >= n) {
						break;
					}

					if(s[i] != s[j]) {
						dp[i][j] = 0;
					} else {
						if(j - i < 3) {
							dp[i][j] = 1;
						} else {
							dp[i][j] = dp[i + 1][j - 1];
						}
					}

					// 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
					if(dp[i][j] != 0 && j - i + 1 > maxLen) {
						maxLen = j - i + 1;
						begin  = i;
					}
				}
			}
			return s.substr(begin, maxLen);
		}
	}// namespace longest_palindromic_substring

	namespace arithmetic_slices {
		int Solution::numberOfArithmeticSlices(vector<int> &nums) {
			const int n = nums.size();
			vector<int> diff(n - 1);
			for(int i = 0; i < n - 1; i++) {
				diff[i] = nums[i + 1] - nums[i];
			}
			vector<int> consecutive;
			int prev = 0;
			int cnt  = 0;
			for(int i = 0; i < n - 1; i++) {
				if(diff[i] == diff[prev]) {
					cnt++;
				} else {
					consecutive.emplace_back(cnt);
					prev = i;
					cnt  = 1;
				}
			}
			consecutive.emplace_back(cnt);
			int ans = 0;
			for(const auto num: consecutive) {
				if(num >= 2) {
					ans += (num - 1) * num / 2;
				}
			}
			return ans;
		}
	}// namespace arithmetic_slices

	namespace decode_ways {
		int Solution::numDecodings(string s) {
			vector dp(s.length(), 0);
			for(int i = 0; i < dp.size(); i++) {
				bool ok = false;
				if('1' <= s[i] && s[i] <= '9') {
					dp[i] += i - 1 >= 0 ? dp[i - 1] : 1;
					ok = true;
				}
				if(i - 1 >= 0 && (s[i - 1] == '1' && '0' <= s[i] && s[i] <= '9' || s[i - 1] == '2' && '0' <= s[i] && s[i] <= '6')) {
					dp[i] += i - 2 >= 0 ? dp[i - 2] : 1;
					ok = true;
				}
				if(!ok) {
					return 0;
				}
			}
			return dp.back();
		}
	}// namespace decode_ways

	namespace word_break {
		bool Solution::wordBreak(const string &s, vector<string> &wordDict) {
			vector end(s.length(), false);
			TrieNode tn(0);
			for(const auto &word: wordDict) {
				tn.insert(word);
			}
			search(&tn, s, 0, end);
			for(int i = 1; i < s.length(); i++) {
				if(end[i - 1]) {
					search(&tn, s, i, end);
					if(end.back()) {
						return true;
					}
				}
			}
			return end.back();
		}

		void Solution::search(const TrieNode *tn, const string &s, int i, vector<bool> &end) {
			const TrieNode *node = tn;
			for(; i < s.length(); i++) {
				node = node->nexts[s[i] - 'a'];
				if(node == nullptr) {
					return;
				}
				if(node->end_of_word) {
					end[i] = true;
				}
			}
		}
	}// namespace word_break

	namespace longest_increasing_subsequence {
		int Solution::lengthOfLIS(vector<int> &nums) {
			const int n = nums.size();
			int ans     = 1;
			vector dp(n, 1);//length of longest increasing subsequence end with i
			for(int i = 0; i < n; i++) {
				for(int j = i + 1; j < n; j++) {
					if(nums[j] > nums[i]) {
						dp[j] = max(dp[j], dp[i] + 1);
					}
				}
				ans = max(ans, dp[i]);
			}
			return ans;
		}
	}// namespace longest_increasing_subsequence

	namespace number_of_longest_increasing_subsequence {
		int Solution::findNumberOfLIS(vector<int> &nums) {
			const int n = nums.size();
			vector dp(n, map<unsigned, unsigned>());//dp[i][j] = number of increasing subsequence end with i, length is j
			for(int i = 0; i < n; i++) {
				dp[i][1] = 1;
			}
			unsigned max_len = 1;
			for(int i = 0; i < n; i++) {
				for(int j = i + 1; j < n; j++) {
					auto &[len, cnt] = *dp[i].rbegin();
					if(nums[j] > nums[i]) {
						dp[j][len + 1] += cnt;
						max_len = max(max_len, len + 1);
					}
				}
			}
			unsigned ans = 0;
			for(int i = 0; i < n; i++) {
				ans += dp[i][max_len];
			}
			return ans;
		}
	}// namespace number_of_longest_increasing_subsequence

	namespace longest_common_subsequence {
		int Solution::longestCommonSubsequence(string text1, string text2) {
			vector dp(text1.length(), vector(text2.length(), 0));///< dp[i][j] = longest common subsequence of text1 end with i and text2 end with j
			for(int i = 0; i < text1.length(); i++) {
				for(int j = 0; j < text2.length(); j++) {
					if(text1[i] == text2[j]) {
						dp[i][j] = (i - 1 < 0 || j - 1 < 0 ? 0 : dp[i - 1][j - 1]) + 1;
					} else {
						dp[i][j] = max(i - 1 >= 0 ? dp[i - 1][j] : 0, j - 1 >= 0 ? dp[i][j - 1] : 0);
					}
				}
			}
			return dp.back().back();
		}
	}// namespace longest_common_subsequence

	namespace delete_operation_for_two_strings {
		int Solution::minDistance(const string &word1, const string &word2) {
			const int lcs = longest_common_subsequence::Solution::longestCommonSubsequence(word1, word2);
			return word1.length() + word2.length() - 2 * lcs;
		}
	}// namespace delete_operation_for_two_strings

	namespace edit_distance {
		int Solution::minDistance(string word1, string word2) {
			// dp[i][j] is the minimum number of operations required to convert word1[0..i] to word2[0..j]
			vector dp(word1.length() + 1, vector<int>(word2.length() + 1));
			// if word[i] == word2[j], dp[i][j] = dp[i-1][j-1]; else dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
			for(int j = 0; j <= word2.length(); j++) {
				dp[0][j] = j;
			}
			for(int i = 0; i <= word1.length(); i++) {
				dp[i][0] = i;
			}
			for(int i = 1; i <= word1.length(); i++) {
				for(int j = 1; j <= word2.length(); j++) {
					if(word1[i - 1] == word2[j - 1]) {
						dp[i][j] = dp[i - 1][j - 1];
					} else {
						dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
					}
				}
			}
			return dp.back().back();
		}
	}// namespace edit_distance

	namespace coin_change {
		int Solution::coinChange(vector<int> &coins, int amount) {
			vector dp(amount + 1, -1);
			dp[0] = 0;
			for(const auto &coin: coins) {
				if(coin <= amount) {
					dp[coin] = 1;
				}
			}
			for(unsigned i = 0; i <= amount; i++) {
				if(dp[i] > 0) {
					for(const auto &coin: coins) {
						if(i + coin <= static_cast<unsigned>(amount)) {
							if(dp[i + coin] == -1) {
								dp[i + coin] = dp[i] + 1;
							} else {
								dp[i + coin] = min(dp[i + coin], dp[i] + 1);
							}
						}
					}
				}
			}
			return dp[amount];
		}
	}// namespace coin_change

	namespace integer_break {
		int Solution::integerBreak(int n) {
			// dp[i] is the maximum product of i
			vector<int> dp(n + 1);
			// dp[i] = max(dp[i], dp[j] * dp[i - j])
			dp[2] = 1;
			dp[1] = 1;
			for(int i = 3; i <= n; i++) {
				for(int j = 1; j < i; j++) {
					dp[i] = max(dp[i], dp[j] * dp[i - j]);
					dp[i] = max(dp[i], j * dp[i - j]);
					dp[i] = max(dp[i], dp[j] * (i - j));
					dp[i] = max(dp[i], j * (i - j));
				}
			}
			return dp[n];
		}
	}// namespace integer_break

	namespace max_points_on_a_line {
		int Solution::maxPoints(vector<vector<int>> &points) {
			int ans = 0;
			for(auto &p1: points) {
				unordered_map<long double, int> us;
				int cnt = 0;
				for(auto &p2: points) {
					if(p2[0] != p1[0]) {
						us[static_cast<long double>(p2[1] - p1[1]) / static_cast<long double>(p2[0] - p1[0])]++;
					} else {
						cnt++;
					}
				}
				for(auto &[k, v]: us) {
					cnt = max(cnt, v + 1);
				}
				ans = max(ans, cnt);
			}
			return ans;
		}
	}// namespace max_points_on_a_line

	namespace group_anagrams {
		vector<vector<string>> Solution::groupAnagrams(vector<string> &strs) {
			vector<string> strs_sorted = strs;
			unordered_map<string, vector<string>> um;
			for(auto &str: strs_sorted) {
				sort(str.begin(), str.end());
				if(!um.contains(str)) {
					um[str] = vector<string>();
				}
			}
			for(int i = 0; i < strs.size(); i++) {
				um[strs_sorted[i]].emplace_back(strs[i]);
			}
			vector<vector<string>> ans;
			ans.reserve(um.size());
			for(auto &[k, v]: um) {
				ans.emplace_back(v);
			}
			return ans;
		}
	}// namespace group_anagrams

	namespace sort_colors {
		void Solution::sortColors(vector<int> &nums) { qsort(nums, 0, nums.size() - 1); }

		void Solution::qsort(vector<int> &nums, int l, int r) {
			if(l >= r) {
				return;
			}
			int lp          = l - 1;
			int rp          = r + 1;
			const int pivot = nums[(l + r) / 2];
			while(lp < rp) {
				while(nums[++lp] < pivot)
					;
				while(nums[--rp] > pivot)
					;
				if(lp < rp) {
					swap(nums[lp], nums[rp]);
				}
			}
			qsort(nums, l, rp);
			qsort(nums, rp + 1, r);
		}
	}// namespace sort_colors

	namespace top_k_frequent_elements {
		vector<int> Solution::topKFrequent(vector<int> &nums, int k) {
			unordered_map<int, int> um;
			for(auto num: nums) {
				um[num]++;
			}
			vector<int> vec(um.size());
			int i = 0;
			for(auto &[_, v]: um) {
				vec[i++] = v;
			}
			sort(vec.rbegin(), vec.rend());
			unordered_set<int> us;
			for(i = 0; i < k; i++) {
				us.insert(vec[i]);
			}
			vector<int> ans;
			for(auto [num, v]: um) {
				if(us.contains(v)) {
					ans.emplace_back(num);
				}
			}
			return ans;
		}
	}// namespace top_k_frequent_elements

	namespace kth_largest_element_in_an_array {
		int Solution::findKthLargest(vector<int> &nums, int k) {
			sort(nums.rbegin(), nums.rend());
			return nums[k - 1];
		}
	}// namespace kth_largest_element_in_an_array

	namespace merge_intervals {
		vector<vector<int>> Solution::merge(vector<vector<int>> &intervals) {
			vector<vector<int>> ans;
			auto comp = [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; };
			sort(intervals.begin(), intervals.end(), comp);
			int start = intervals[0][0];
			int end   = intervals[0][1];
			for(int i = 1; i < intervals.size(); i++) {
				if(intervals[i][0] <= end) {
					end = max(end, intervals[i][1]);
				} else {
					ans.emplace_back(vector{start, end});
					start = intervals[i][0];
					end   = intervals[i][1];
				}
			}
			ans.emplace_back(vector{start, end});
			return ans;
		}
	}// namespace merge_intervals

	namespace search_a_2d_matrix_ii {
		bool Solution::searchMatrix(vector<vector<int>> &matrix, int target) { return search(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1); }

		bool Solution::search(const vector<vector<int>> &matrix, int target, int x_start, int x_end, int y_start, int y_end) {
			const int minimum = min(x_end - x_start, y_end - y_start);
			vector<int> diag1(minimum + 1);
			for(int i = 0; i <= minimum; i++) {
				diag1[i] = matrix[x_start + i][y_start + i];
			}
			const auto it = lower_bound(diag1.begin(), diag1.end(), target);
			const int x   = x_start + it - diag1.begin();
			const int y   = y_start + it - diag1.begin();
			if(it != diag1.end()) {
				if(*it == target) {
					return true;
				}
				if(it == diag1.begin()) {
					return false;
				}
				if(search(matrix, target, x_start, x - 1, y, y_end)) {
					return true;
				}
				if(search(matrix, target, x, x_end, y_start, y - 1)) {
					return true;
				}
				if(search(matrix, target, x, x_end, y, y_end)) {
					return true;
				}
			} else {
				if(x > x_end && y > y_end) {
					return false;
				}
				if(x > x_end && search(matrix, target, x_start, x_end, y, y_end)) {
					return true;
				}
				if(y > y_end && search(matrix, target, x, x_end, y_start, y_end)) {
					return true;
				}
			}
			return false;
		}
	}// namespace search_a_2d_matrix_ii

	namespace serialize_and_deserialize_binary_tree {
		string Codec::serialize(TreeNode *root) const {
			if(root == nullptr) {
				return "[]";
			}
			vector<string> vec;
			ostringstream oss;
			oss << '[';
			queue<TreeNode *> q;
			q.push(root);
			while(!q.empty()) {
				const TreeNode *node = q.front();
				q.pop();
				if(node == nullptr) {
					vec.emplace_back("null");
					continue;
				}
				vec.emplace_back(to_string(node->val));
				q.push(node->left);
				q.push(node->right);
			}
			int end = vec.size() - 1;
			while(vec[end] == "null" && end > 0) {
				end--;
			}
			oss << vec[0];
			for(int i = 1; i <= end; i++) {
				oss << ',' << vec[i];
			}
			oss << ']';
			return oss.str();
		}

		TreeNode *Codec::deserialize(string data) const {
			if(data == "[]") {
				return nullptr;
			}
			vector<string> vec;
			data           = data.substr(1, data.size() - 2);
			const auto str = static_cast<char *>(malloc((data.length() + 1) * sizeof(char)));
			memcpy(str, data.c_str(), (data.length() + 1) * sizeof(char));
			for(const char *item = strtok(str, ","); item != nullptr; item = strtok(nullptr, ",")) {
				vec.emplace_back(string(item));
			}
			queue<TreeNode **> q;
			auto root = new TreeNode(stoi(vec[0]));
			q.push(&root);
			for(const auto &str: vec) {
				const auto node = q.front();
				q.pop();
				if(str == "null") {
					*node = nullptr;
				} else {
					*node = new TreeNode(stoi(str));
					q.push(&(*node)->left);
					q.push(&(*node)->right);
				}
			}
			return root;
		}
	}// namespace serialize_and_deserialize_binary_tree

	namespace task_scheduler {
		int Solution::leastInterval(vector<char> &tasks, int n) {
			if(n == 0) {
				return tasks.size();
			}
			int maximum = 0;
			int cycle   = 0;
			unordered_map<char, int> task_cnt;
			unordered_map<char, int> processing;
			for(char task: tasks) {
				task_cnt[task]++;
			}
			while(true) {
				bool finished = true;
				maximum       = 0;
				for(const auto &[task, cnt]: task_cnt) {
					if(cnt > 0) {
						finished = false;
					}
					if(processing[task] <= 0) {
						maximum = max(maximum, cnt);
					}
				}
				if(finished) {
					return cycle;
				}
				for(auto &[task, rest]: processing) {
					rest--;
				}
				for(auto &[task, cnt]: task_cnt) {
					if(maximum == cnt && processing[task] <= 0) {
						cnt--;
						processing[task] = n;
						break;
					}
				}
				cycle++;
			}
		}
	}// namespace task_scheduler

	namespace design_hashmap {
		MyHashMap::MyHashMap() {
			arr = array<list<pair<int, int>>, SZ>();
			for(unsigned i = 0; i < SZ; i++) {
				arr[i] = list<pair<int, int>>();
			}
		}

		void MyHashMap::put(int key, int value) {
			const unsigned slot = static_cast<unsigned>(key) % SZ;
			for(auto &[k, v]: arr[slot]) {
				if(k == key) {
					v = value;
					return;
				}
			}
			arr[slot].emplace_back(key, value);
		}

		int MyHashMap::get(int key) {
			const unsigned slot = static_cast<unsigned>(key) % SZ;
			for(auto &[k, v]: arr[slot]) {
				if(k == key) {
					return v;
				}
			}
			return -1;
		}

		void MyHashMap::remove(int key) {
			const unsigned slot = static_cast<unsigned>(key) % SZ;
			for(auto it = arr[slot].begin(); it != arr[slot].end(); ++it) {
				if(it->first == key) {
					arr[slot].erase(it);
					return;
				}
			}
		}
	}// namespace design_hashmap

	namespace spiral_matrix_ii {
		vector<vector<int>> Solution::generateMatrix(int n) {
			vector ans(n, vector(n, 0));
			int dir = 0;// 0-right 1-down 2-left 3->up
			int c   = 1;
			int x   = 0;
			int y   = 0;
			for(int i = 0; i < n * n; i++) {
				ans[x][y] = c++;
				bool flag = true;
			SLCT:
				int nx = x;
				int ny = y;
				switch(dir) {
					case 0:
						ny++;
						break;
					case 1:
						nx++;
						break;
					case 2:
						ny--;
						break;
					case 3:
						nx--;
						break;
				}
				if(flag && (nx < 0 || nx >= n || ny < 0 || ny >= n || ans[nx][ny] != 0)) {
					dir++;
					dir %= 4;
					flag = false;
					goto SLCT;
				}
				x = nx;
				y = ny;
			}
			return ans;
		}
	}// namespace spiral_matrix_ii

	namespace non_overlapping_intervals {
		int Solution::eraseOverlapIntervals(vector<vector<int>> &intervals) {
			if(intervals.empty()) {
				return 0;
			}

			sort(intervals.begin(), intervals.end(), [](const auto &u, const auto &v) { return u[1] < v[1]; });

			const int n = intervals.size();
			int right   = intervals[0][1];
			int ans     = 1;
			for(int i = 1; i < n; ++i) {
				if(intervals[i][0] >= right) {
					++ans;
					right = intervals[i][1];
				}
			}
			return n - ans;
		}
	}// namespace non_overlapping_intervals

	namespace product_of_array_except_self {
		vector<int> Solution::productExceptSelf(vector<int> &nums) {
			vector<int> left(nums.size());
			vector<int> right(nums.size());
			int c = 1;
			for(int i = 0; i < left.size(); i++) {
				left[i] = c;
				c *= nums[i];
			}
			c = 1;
			for(int i = left.size() - 1; i >= 0; i--) {
				right[i] = c;
				c *= nums[i];
			}
			vector<int> ans(nums.size());
			for(int i = 0; i < nums.size(); i++) {
				ans[i] = left[i] * right[i];
			}
			return ans;
		}
	}// namespace product_of_array_except_self

	namespace subarray_sum_equals_k {
		int Solution::subarraySum(vector<int> &nums, int k) {
			unordered_map<int, int> um;
			um[0]     = 1;
			int count = 0;
			int ps    = 0;
			for(const auto &num: nums) {
				ps += num;
				count += um[ps - k];
				um[ps]++;
			}
			return count;
		}
	}// namespace subarray_sum_equals_k

	namespace partition_labels {
		vector<int> Solution::partitionLabels(string s) {
			unordered_map<char, unsigned> last;
			vector<int> ans;
			for(int i = 0; i < s.length(); i++) {
				last[s[i]] = i;
			}
			for(int i = 0; i < s.length();) {
				unsigned last_pos = i;
				char ch           = s[i];
				for(int j = i; j <= last_pos; j++) {
					last_pos = max(last_pos, last[s[j]]);
				}
				ans.emplace_back(last_pos - i + 1);
				i = last_pos + 1;
			}
			return ans;
		}
	}// namespace partition_labels

	namespace repeated_dna_sequences {
		vector<string> Solution::findRepeatedDnaSequences(string s) {
			vector<unsigned short> vec(s.length());
			for(int i = 0; i < s.length(); i++) {
				switch(s[i]) {
					case 'A':
						vec[i] = 0;
						break;
					case 'C':
						vec[i] = 1;
						break;
					case 'G':
						vec[i] = 2;
						break;
					case 'T':
						vec[i] = 3;
						break;
				}
			}
			unsigned hsv = 0;
			if(s.length() < 10) {
				return {};
			}
			unordered_map<unsigned, string> um;
			unordered_map<unsigned, unsigned> cnt;
			for(int i = 0; i < 10; i++) {
				hsv *= 4;
				hsv += vec[i];
			}
			um[hsv]          = s.substr(0, 10);
			cnt[hsv]         = 1;
			const unsigned f = 262144;
			for(int i = 10; i < s.length(); i++) {
				hsv -= vec[i - 10] * f;
				hsv *= 4;
				hsv += vec[i];
				um[hsv] = s.substr(i - 9, 10);
				cnt[hsv]++;
			}
			vector<string> ans;
			for(auto &[k, v]: um) {
				if(cnt[k] > 1) {
					ans.emplace_back(v);
				}
			}
			return ans;
		}
	}// namespace repeated_dna_sequences

	namespace design_linked_list {
		MyLinkedList::MyLinkedList() {
			head = new ListNode();
			tail = head;
		}

		int MyLinkedList::get(int index) const {
			index += 1;
			if(index < 1) {
				return -1;
			}
			const ListNode *current = head;
			for(int i = 0; i < index && current != nullptr; i++) {
				current = current->next;
			}
			return current == nullptr ? -1 : current->val;
		}

		void MyLinkedList::addAtHead(int val) {
			auto node  = new ListNode(val);
			node->next = head->next;
			head->next = node;
			if(tail == head) {
				tail = node;
			}
		}

		void MyLinkedList::addAtTail(int val) {
			auto node  = new ListNode(val);
			tail->next = node;
			tail       = node;
		}

		void MyLinkedList::addAtIndex(int index, int val) {
			index += 1;
			if(index < 1) {
				return;
			}
			auto node         = new ListNode(val);
			ListNode *current = head;
			for(int i = 0; i < index - 1 && current != nullptr; i++) {
				current = current->next;
			}
			if(current == nullptr) {
				delete node;
				return;
			}
			node->next    = current->next;
			current->next = node;
			if(current == tail) {
				tail = node;
			}
		}

		void MyLinkedList::deleteAtIndex(int index) {
			index += 1;
			if(index < 1) {
				return;
			}
			ListNode *current = head;
			for(int i = 0; i < index - 1 && current != nullptr; i++) {
				current = current->next;
			}
			if(current == nullptr) {
				return;
			}
			const auto p = current->next;
			if(p == tail) {
				tail = current;
			}
			if(p != nullptr) {
				current->next = current->next->next;
				delete p;
			}
		}
	}// namespace design_linked_list

	namespace delete_node_in_a_bst {
		TreeNode *Solution::findMaximum(TreeNode *node) {
			TreeNode *current = node;
			while(current->right != nullptr) {
				prev    = current;
				current = current->right;
			}
			return current;
		}

		TreeNode *Solution::findMinimum(TreeNode *node) {
			TreeNode *current = node;
			while(current->left != nullptr) {
				prev    = current;
				current = current->left;
			}
			return current;
		}

		void Solution::remove(TreeNode *node) {
			if(node->right != nullptr) {
				prev      = node;
				auto rmin = findMinimum(node->right);
				node->val = rmin->val;
				remove(rmin);
				return;
			}
			if(node->left != nullptr) {
				prev      = node;
				auto lmax = findMaximum(node->left);
				node->val = lmax->val;
				remove(lmax);
				return;
			}
			if(prev != nullptr) {
				if(prev->left != nullptr && prev->left->val == node->val) {
					prev->left = nullptr;
				} else if(prev->right != nullptr && prev->right->val == node->val) {
					prev->right = nullptr;
				}
			} else {
				exit(-1);
			}
			//delete node;
		}

		TreeNode *Solution::deleteNode(TreeNode *root, int key) {
			if(root == nullptr) {
				return root;
			}
			TreeNode *current = root;
			while(current != nullptr && current->val != key) {
				if(current->val == key) {
					break;
				}
				prev = current;
				if(current->val < key) {
					current = current->right;
				} else {
					current = current->left;
				}
			}
			if(current == nullptr) {
				return root;
			}
			if(root->left == nullptr && root->right == nullptr) {
				return nullptr;
			}
			remove(current);
			return root;
		}
	}// namespace delete_node_in_a_bst
}// namespace leetcode
