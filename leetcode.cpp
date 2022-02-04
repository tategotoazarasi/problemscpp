#include "leetcode.h"
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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
					return true;
				}
			}
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
			for(auto *node = head; node != nullptr; node = node->next, i++) {
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
			for(char *token = strtok(str, " "); token != nullptr; token = strtok(nullptr, " ")) {
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

	namespace number_of_rectangles_that_can_form_the_largest_square {
		int Solution::countGoodRectangles(vector<vector<int>> &rectangles) {
			map<int, int> m = map<int, int>();
			for(auto rectangle: rectangles) {
				int k = min(rectangle[0], rectangle[1]);
				m[k]++;
			}
			return (*m.rbegin()).second;
		}
	}// namespace number_of_rectangles_that_can_form_the_largest_square
}// namespace leetcode
