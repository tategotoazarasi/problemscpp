//
// Created by tategotoazarasi on 2021/12/29.
//

#include"leetcode.h"
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include <stack>
#include <sstream>

using namespace std;

namespace leetcode
{
	bool TreeNode::operator==(const TreeNode& node) const
	{
		if (this->left != nullptr && node.left == nullptr)
		{
			return false;
		}
		if (this->left == nullptr && node.left != nullptr)
		{
			return false;
		}
		if (this->right != nullptr && node.right == nullptr)
		{
			return false;
		}
		if (this->right == nullptr && node.right != nullptr)
		{
			return false;
		}
		if (this->left != nullptr && node.left != nullptr && (*this->left) != (*node.left))
		{
			return false;
		}
		if (this->right != nullptr && node.right != nullptr && (*this->right) != (*node.right))
		{
			return false;
		}
		return this->val == node.val;
	}

	bool TreeNode::operator!=(const TreeNode& node) const
	{
		return !((*this) == node);
	}

	namespace concatenated_words
	{
		vector<string> Solution::findAllConcatenatedWordsInADict(vector<string>& words)
		{
			sort(words.begin(), words.end(), [&](const string& a, const string& b)
			{
			  return a.size() < b.size();
			});
			auto ans = vector<string>();
			auto node = TrieNode(0);
			for (const string& word : words)
			{
				if (word.length() == 0)
				{
					continue;
				}
				if (node.dfs(&node, word, 0, false))
				{
					ans.push_back(word);
				}
				else
				{
					node.insert(word);
				}
			}
			return ans;
		}

		TrieNode::TrieNode(char ch)
		{
			this->ch = ch;
			this->is_end = false;
		}

		void TrieNode::insert(const string& str)
		{
			auto node = this->nexts[str[0] - 'a'];
			if ((node) == nullptr)
			{
				node = new TrieNode(str[0]);
				this->nexts[str[0] - 'a'] = node;
			}
			if (str.length() == 1)
			{
				node->is_end = true;
				return;
			}
			return node->insert(str.substr(1));
		}

		bool TrieNode::dfs(TrieNode* root, const string& str, int start, bool flag)
		{
			if (this->ch == 0)
			{
				//根节点
				auto node = this->nexts[str[start] - 'a'];
				if (node == nullptr)
				{
					return false;
				}
				if (node->dfs(root, str, start, flag))
				{
					return true;
				}
				return false;
			}
			//非根节点
			//到一个单词结束处
			if (this->is_end)
			{
				if (start == str.length() - 1)
				{
					return flag;
				}
				auto res = root->dfs(root, str, start + 1, true);
				if (res)
				{
					return true;
				}
			}
			TrieNode* node = nullptr;
			if (str[start + 1] - 'a' >= 0)
			{
				node = this->nexts[str[start + 1] - 'a'];
			}
			return node != nullptr && node->dfs(root, str, start + 1, flag);
		}
	}

	namespace excel_sheet_column_number
	{
		int Solution::titleToNumber(const std::string& columnTitle)
		{
			int sum = 0;
			int length = static_cast<int>(columnTitle.length());
			for (char c : columnTitle)
			{
				sum += static_cast<int>(static_cast<double>(c - 'A' + 1) * pow(26, length-- - 1));
			}
			return sum;
		}
	}

	namespace excel_sheet_column_title
	{
		string Solution::convertToTitle(int columnNumber)
		{
			auto ans = string();
			bool round = false;
			while (columnNumber != 0)
			{
				char ch;
				if (round)
				{
					ch = static_cast<char>(columnNumber % 26 + 63);
					round = false;
				}
				else ch = static_cast<char>(columnNumber % 26 + 64);
				if (ch == '@' && columnNumber >= 26)
				{
					ch = 'Z';
					round = true;
				}
				else if (ch == '?' && columnNumber >= 26)
				{
					ch = 'Y';
					round = true;
				}
				if ('A' <= ch && ch <= 'Z')
				{
					ans.insert(0, 1, ch);
				}
				columnNumber /= 26;
			}
			return ans;
		}
	}

	namespace majority_element
	{
		Solution::Solution()
		{
			this->m = std::map<int, int>();
		}

		int Solution::majorityElement(vector<int>& nums)
		{
			for (int i : nums)
			{
				if (m.contains(i))
				{
					m[i] = m[i] + 1;
					if (m[i] > nums.size() / 2)
					{
						return i;
					}
				}
				else
				{
					m[i] = 1;
				}
			}
			return 0;
		}
	}

	namespace count_special_quadruplets
	{
		int Solution::countQuadruplets(vector<int>& nums)
		{
			int sum = 0;
			for (int i = 3; i < nums.size(); i++)
			{
				for (int j = 0; j < i - 2; j++)
				{
					if (j == i)
					{
						continue;
					}
					for (int k = j + 1; k < i - 1; k++)
					{
						if (k == i)
						{
							continue;
						}
						for (int l = k + 1; l < i; l++)
						{
							if (l == i)
							{
								continue;
							}
							if (nums[k] + nums[j] + nums[l] == nums[i])
							{
								sum++;
							}
						}
					}
				}
			}
			return sum;
		}
	}

	namespace hand_of_straights
	{
		bool Solution::isNStraightHand(vector<int>& hand, int groupSize)
		{
			if (hand.size() % groupSize != 0)
			{
				return false;
			}
			if (groupSize == 1)
			{
				return true;
			}
			sort(hand.begin(), hand.end());
			auto len = hand.size() / groupSize;
			for (int i = 0; i < len; i++)
			{
				int current = *hand.begin();
				hand.erase(hand.begin());
				for (int j = 1; j < groupSize; j++)
				{
					auto next = find(hand.begin(), hand.end(), current + 1);
					if (next == hand.end())
					{
						return false;
					}
					current = *next;
					hand.erase(next);
				}
			}
			return true;
		}
	}

	namespace perfect_number
	{
		bool Solution::checkPerfectNumber(int num)
		{
			int sum = 0;
			int max = num;
			for (int i = 1; i < max; i++)
			{
				if (num % i == 0)
				{
					sum += i;
					if (i != 1)
					{
						sum += num / i;
					}
					max = num / i;
				}
			}
			return sum == num;
		}
	}

	namespace convert_bst_to_greater_tree
	{
		TreeNode* Solution::convertBST(TreeNode* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}
			FriendTreeNode* sum = copy(root);
			get_sum(sum);
			sum->val = sum->sum - (sum->left == nullptr ? 0 : sum->left->sum);
			convert(sum);
			return root;
		}

		FriendTreeNode* Solution::copy(TreeNode* node)
		{
			auto* ret = new FriendTreeNode(node->val, node);
			if (node->left != nullptr)
			{
				ret->left = copy(node->left);
			}
			if (node->right != nullptr)
			{
				ret->right = copy(node->right);
			}
			return ret;
		}

		void Solution::get_sum(FriendTreeNode* node)
		{
			if (node->left != nullptr)
			{
				get_sum(node->left);
				node->sum += node->left->sum;
			}
			if (node->right != nullptr)
			{
				get_sum(node->right);
				node->sum += node->right->sum;
			}
		}

		void Solution::convert(FriendTreeNode* sum_node)
		{
			if (sum_node->right != nullptr)
			{
				sum_node->right->val = sum_node->val - sum_node->friend_node->val -
					(sum_node->right->left == nullptr ? 0 : sum_node->right->left->sum);
				convert(sum_node->right);
			}
			if (sum_node->left != nullptr)
			{
				sum_node->left->val = sum_node->val + sum_node->left->friend_node->val +
					(sum_node->left->right == nullptr ? 0 : sum_node->left->right->sum);
				convert(sum_node->left);
			}
			sum_node->friend_node->val = sum_node->val;
		}
	}

	namespace convert_1d_array_into_2d_array
	{
		vector<vector<int>> Solution::construct2DArray(vector<int>& original, int m, int n)
		{
			if (original.size() != m * n)
			{
				return {
				};
			}
			auto ans = vector<vector<int>>();
			int count = 0;
			for (int i = 0; i < m; i++)
			{
				auto row = vector<int>();
				for (int j = 0; j < n; j++)
				{
					row.push_back(original[count++]);
				}
				ans.push_back(row);
			}
			return ans;
		}
	}

	namespace elimination_game
	{
		int Solution::lastRemaining(int n)
		{
			int num_amount = n;
			int loop_cnt = 0;
			int a0 = 1; //初项
			int d = 1; //差
			while (num_amount != 1)
			{
				//剩下的数目不为1时
				if (num_amount % 2 == 1)
				{
					// 奇数个数字
					a0 = a0 + d;
				}
				else if (num_amount % 2 == 0)
				{
					// 偶数个数字
					bool left_to_right = (loop_cnt % 2 == 0);
					if (left_to_right)
					{
						a0 = a0 + d;
					}
					else
						a0 = a0;
				}
				loop_cnt++;
				d *= 2;
				num_amount /= 2;
			}
			return a0;
		}
	}

	namespace check_if_all_as_appears_before_all_bs
	{
		bool Solution::checkString(string s)
		{
			bool flag = true;
			for (char ch : s)
			{
				if (ch == 'a')
				{
					if (!flag)
					{
						return false;
					}
				}
				else if (ch == 'b')
				{
					flag = false;
				}
			}
			return true;
		}
	}

	namespace number_of_laser_beams_in_a_bank
	{
		int Solution::numberOfBeams(vector<string>& bank)
		{
			if (bank.size() == 1)
			{
				return 0;
			}
			int count = 0;
			int i = 0;
			int count_i = deviceCount(bank[i]);
			int j = 1;
			int count_j = 0;
			while (i < j && i < bank.size() && j < bank.size())
			{
				if (deviceCount(bank[j]) == 0)
				{
					j++;
					continue;
				}
				count_j = deviceCount(bank[j]);
				count += count_i * count_j;
				count_i = count_j;
				i = j;
				j++;
			}
			return count;
		}

		int Solution::deviceCount(const string& str)
		{
			int count = 0;
			for (char c : str)
			{
				if (c == '1')
				{
					count++;
				}
			}
			return count;
		}
	}

	namespace destroying_asteroids
	{
		bool Solution::asteroidsDestroyed(int mass, vector<int>& asteroids)
		{
			long long m = mass;
			sort(asteroids.begin(), asteroids.end());
			for (int i : asteroids)
			{
				if (m < i)
				{
					return false;
				}
				m += i;
			}
			return true;
		}
	}

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
	namespace day_of_the_week
	{
		string Solution::dayOfTheWeek(int day, int month, int year)
		{
			const string output[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
			const int dayofmonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			int count = 5;
			count += (year - 1971) * 365;
			count += (year - 1) / 4 - 1970 / 4;
			for (int m = 0; m < month - 1; m++)
			{
				count += dayofmonths[m];
			}
			if (month > 2 && year % 4 == 0 && year % 100 != 0)
			{
				count++;
			}
			count += day - 1;
			count %= 7;
			return output[count];
		}
	}

	namespace cat_and_mouse
	{
		int Solution::catMouseGame(vector<vector<int>>& graph)
		{
			this->n = graph.size();
			this->graph = graph;
			memset(dp, -1, sizeof(dp));
			return getResult(1, 2, 0);
		}

		int Solution::getResult(int mouse, int cat, int turns)
		{
			if (turns == n * 2)
			{
				return DRAW;
			}
			if (dp[mouse][cat][turns] < 0)
			{
				if (mouse == 0)
				{
					dp[mouse][cat][turns] = MOUSE_WIN;
				}
				else if (cat == mouse)
				{
					dp[mouse][cat][turns] = CAT_WIN;
				}
				else
				{
					getNextResult(mouse, cat, turns);
				}
			}
			return dp[mouse][cat][turns];
		}

		void Solution::getNextResult(int mouse, int cat, int turns)
		{
			int curMove = turns % 2 == 0 ? mouse : cat;
			int defaultResult = curMove == mouse ? CAT_WIN : MOUSE_WIN;
			int result = defaultResult;
			for (int next : graph[curMove])
			{
				if (curMove == cat && next == 0)
				{
					continue;
				}
				int nextMouse = curMove == mouse ? next : mouse;
				int nextCat = curMove == cat ? next : cat;
				int nextResult = getResult(nextMouse, nextCat, turns + 1);
				if (nextResult != defaultResult)
				{
					result = nextResult;
					if (result != DRAW)
					{
						break;
					}
				}
			}
			dp[mouse][cat][turns] = result;
		}
	}

	namespace replace_all_s_to_avoid_consecutive_repeating_characters
	{
		string Solution::modifyString(string s)
		{
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == '?')
				{
					for (char ch = 'a'; ch < 'z' + 1; ch++)
					{
						if (0 <= i - 1 && s[i - 1] == ch)
						{
							continue;
						}
						if (i + 1 < s.size() && s[i + 1] == ch)
						{
							continue;
						}
						s[i] = ch;
						break;
					}
				}
			}
			return s;
		}
	}

	namespace simplify_path
	{
		string simplify_path::Solution::simplifyPath(string path)
		{
			char* str_cpy = new char[path.size() + 1];
			memcpy(str_cpy, path.c_str(), path.size() + 1);
			auto next = strtok(str_cpy, "/");
			auto stck = deque<string>();
			while (next != nullptr)
			{
				auto nextstr = string(next);
				if (nextstr == "..")
				{
					if (!stck.empty())
					{
						stck.pop_back();
					}
					next = strtok(nullptr, "/");
					continue;
				}
				if (nextstr == ".")
				{
					next = strtok(nullptr, "/");
					continue;
				}
				stck.emplace_back(next);
				next = strtok(nullptr, "/");
			}
			auto oss = ostringstream();
			if (stck.empty())
			{
				oss << '/';
			}
			else
			{
				while (!stck.empty())
				{
					auto pname = stck.front();
					oss << '/' << pname;
					stck.pop_front();
				}
			}

			return oss.str();
		}
	}

	namespace maximum_nesting_depth_of_the_parentheses
	{
		int Solution::maxDepth(string s)
		{
			int max = 0;
			int current = 0;
			for (char ch : s)
			{
				if (ch == '(')
				{
					current++;
				}
				else if (ch == ')')
				{
					current--;
				}
				if (max < current)
				{
					max = current;
				}
			}
			return max;
		}
	}
}
