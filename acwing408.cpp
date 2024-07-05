//
// Created by tategotoazarasi on 24-5-7.
//

#include "acwing408.h"
#include "templates.h"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

namespace acwing {
	namespace acwing3378 {
		int main(istream &cin, ostream &cout) {
			int n;
			int rule;
			cin >> n >> rule;
			unordered_map<student *, unsigned> index;
			vector<student *> students(n);
			for(int i = 0; i < n; i++) {
				students[i] = new student();
				cin >> students[i]->name >> students[i]->score;
				if(index.find(students[i]) == index.end())
					index[students[i]] = i;
			}
			sort(students.begin(), students.end(), [rule, &index](student *a, student *b) {
				if(a->score == b->score) {
					return index[a] < index[b];
				}
				if(rule == 0) {
					return a->score > b->score;
				} else {
					return a->score < b->score;
				}
			});
			for(const auto &s: students) {
				cout << s->name << ' ' << s->score << endl;
			}
			return 0;
		}
	}// namespace acwing3378

	namespace acwing3376 {
		int main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			vector<student> students(n);
			for(int i = 0; i < n; i++) {
				cin >> students[i].id >> students[i].score;
				students[i].id_numeric = stoi(students[i].id);
			}
			sort(students.begin(), students.end(), [](const student &a, const student &b) {
				if(a.score == b.score) {
					return a.id_numeric < b.id_numeric;
				}
				return a.score < b.score;
			});
			for(const auto &s: students) {
				cout << s.id << ' ' << s.score << endl;
			}
			return 0;
		}
	}// namespace acwing3376

	namespace acwing3374 {
		int main(istream &cin, ostream &cout) {
			int m, n;
			string x;
			cin >> m >> n >> x;
			if(x == "0") {
				cout << "0";
				return 0;
			}
			vector<unsigned short> input   = vector<unsigned short>();
			vector<unsigned short> ans     = vector<unsigned short>();
			queue<unsigned short> quotient = queue<unsigned short>();
			for(auto i = x.begin(); i != x.end(); i++) {
				if(isdigit(*i)) {
					input.push_back(*i - '0');
				} else if(isupper(*i)) {
					input.push_back(*i - 'A' + 10);
				}
			}
			do {
				unsigned int current = 0;
				quotient             = queue<unsigned short>();
				for(auto i = input.begin(); i != input.end(); i++) {
					current *= m;
					current += *i;
					quotient.push(current / n);
					current %= n;
				}
				while(!quotient.empty() && quotient.front() == 0) {
					quotient.pop();
				}
				ans.push_back(current);
				input = vector<unsigned short>(quotient.size());
				for(unsigned int i = 0; i < input.size(); i++) {
					input[i] = quotient.front();
					quotient.pop();
				}
			} while(!input.empty());
			for(auto i = ans.rbegin(); i != ans.rend(); i++) {
				if(*i < 10) {
					cout << *i;
				} else {
					cout << (char) (*i - 10 + 'a');
				}
			}
			return 0;
		}
	}// namespace acwing3374

	namespace acwing3757 {
		void rearrangedList(struct ListNode *head) {
			if(head == NULL || head->next == NULL)
				return;
			int len = 0;
			for(struct ListNode *p = head; p != NULL; p = p->next)
				len++;
			int mid            = (len + 1) / 2;
			struct ListNode *a = head;
			for(int i = 0; i < mid - 1; i++) {
				a = a->next;
			}
			struct ListNode *b = a->next;
			struct ListNode *c = b->next;
			a->next            = NULL;
			b->next            = NULL;
			while(c) {
				struct ListNode *tmp = c->next;
				c->next              = b;
				b                    = c;
				c                    = tmp;
			}
			struct ListNode *p = head;
			struct ListNode *q = b;
			while(q) {
				auto qq = q->next;
				// 插入结点
				q->next = p->next;
				p->next = q;
				// 移动p和q
				p = q->next;
				q = qq;
			}
		}
	}// namespace acwing3757

	namespace acwing3607 {
		int main(istream &cin, ostream &cout) {
			int year, day;
			int day_of_month[13]       = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			int day_of_month_leap[13]  = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			int start_day_of_month[14] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, INT_MAX};
			while(cin >> year >> day) {
				bool leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
				if(leap) {
					for(int i = 1; i <= 12; i++) {
						start_day_of_month[i] = start_day_of_month[i - 1] + day_of_month_leap[i - 1];
					}
				} else {
					for(int i = 1; i <= 12; i++) {
						start_day_of_month[i] = start_day_of_month[i - 1] + day_of_month[i - 1];
					}
				}
				cout << setw(4) << setfill('0') << year << '-';
				for(int i = 1; i <= 13; i++) {
					if(start_day_of_month[i] > day) {
						cout << setw(2) << setfill('0') << i - 1 << '-';
						day -= start_day_of_month[i - 1];
						day++;
						cout << setw(2) << setfill('0') << day << endl;
						break;
					}
				}
				memset(start_day_of_month, 0, sizeof(start_day_of_month));
				start_day_of_month[0]  = 1;
				start_day_of_month[13] = INT_MAX;
			}
			return 0;
		}
	}// namespace acwing3607

	namespace acwing3573 {
		int main(istream &cin, ostream &cout) {
			int t, year, month, day, a;
			int day_of_month[13]      = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			int day_of_month_leap[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			int(*day_of_month_p)[13]  = nullptr;

			cin >> t;
			while(t--) {
				cin >> year >> month >> day >> a;
				day_of_month_p = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? &day_of_month_leap : &day_of_month;
				day += a;
				while(day > (*day_of_month_p)[month]) {
					day -= (*day_of_month_p)[month];
					month++;
					if(month > 12) {
						month = 1;
						year++;
						day_of_month_p = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? &day_of_month_leap : &day_of_month;
					}
				}
				cout << setw(4) << setfill('0') << year << '-' << setw(2) << setfill('0') << month << '-' << setw(2) << setfill('0') << day << endl;
			}
			return 0;
		}
	}// namespace acwing3573

	namespace acwing3302_408 {
		int main(istream &cin, ostream &cout) {
			int x;
			char y;
			unordered_map<char, int> priority = {
			        {'+', 1},
			        {'-', 1},
			        {'*', 2},
			        {'/', 2}};
			stack<char> op = stack<char>();
			stack<int> num = stack<int>();
			while(!cin.eof() || !cin.fail() || !cin.bad()) {
				if(cin.peek() == EOF)
					break;
				if(isdigit(cin.peek())) {
					cin >> x;
					num.push(x);
				} else {
					cin >> y;
					if(y == '(') {
						op.push(y);
					} else if(y == ')') {
						while(!op.empty() && op.top() != '(') {
							int b = num.top();
							num.pop();
							int a = num.top();
							num.pop();
							char c = op.top();
							op.pop();
							if(c == '+') {
								num.push(a + b);
							} else if(c == '-') {
								num.push(a - b);
							} else if(c == '*') {
								num.push(a * b);
							} else if(c == '/') {
								num.push(a / b);
							}
						}
						op.pop();
					} else if(priority.find(y) != priority.end()) {
						while(!op.empty() && op.top() != '(' && priority[op.top()] >= priority[y]) {
							int b = num.top();
							num.pop();
							int a = num.top();
							num.pop();
							char c = op.top();
							op.pop();
							if(c == '+') {
								num.push(a + b);
							} else if(c == '-') {
								num.push(a - b);
							} else if(c == '*') {
								num.push(a * b);
							} else if(c == '/') {
								num.push(a / b);
							}
						}
						op.push(y);
					}
				}
			}
			while(!op.empty()) {
				int b = num.top();
				num.pop();
				int a = num.top();
				num.pop();
				char c = op.top();
				op.pop();
				if(c == '+') {
					num.push(a + b);
				} else if(c == '-') {
					num.push(a - b);
				} else if(c == '*') {
					num.push(a * b);
				} else if(c == '/') {
					num.push(a / b);
				}
			}
			cout << num.top();
			return 0;
		}
	}// namespace acwing3302_408

	namespace acwing3766 {
		int pathSum(TreeNode *root) {
			return pathSum(root, 0);
		}

		int pathSum(TreeNode *root, int level) {
			if(root == nullptr) {
				return 0;
			}
			if(root->left == nullptr && root->right == nullptr) {
				return level * root->val;
			}
			int leftVal  = pathSum(root->left, level + 1);
			int rightVal = pathSum(root->right, level + 1);
			return leftVal + rightVal;
		}
	}// namespace acwing3766

	namespace acwing148 {
		int main(istream &cin, ostream &cout) {
			priority_queue<int, vector<int>, greater<>> pq = priority_queue<int, vector<int>, greater<>>();
			int n;
			cin >> n;
			int x;
			while(n--) {
				cin >> x;
				pq.push(x);
			}
			int ans = 0;
			while(pq.size() > 1) {
				int a = pq.top();
				pq.pop();
				int b = pq.top();
				pq.pop();
				ans += a + b;
				pq.push(a + b);
			}
			cout << ans;
			return 0;
		}
	}// namespace acwing148

	namespace acwing836_408 {
		vector<int> root;

		int find(int x) {
			if(root[x] < 0)
				return x;
			else {
				int grand_parent = find(root[x]);
				root[x]          = grand_parent;
				return grand_parent;
			}
		}

		void merge(int x, int y) {
			int root_x = find(x);
			int root_y = find(y);
			if(root_x != root_y) {
				if(root[root_x] < root[root_y]) {
					root[root_x] += root[root_y];
					root[root_y] = root_x;
				} else {
					root[root_y] += root[root_x];
					root[root_x] = root_y;
				}
			}
		}

		int main(istream &cin, ostream &cout) {
			int n, m;
			cin >> n >> m;
			root = vector<int>(n + 1, -1);
			char op;
			int a, b;
			while(m--) {
				cin >> op >> a >> b;
				if(op == 'M') {
					merge(a, b);
				} else {
					cout << (find(a) == find(b) ? "Yes" : "No") << endl;
				}
			}
			return 0;
		}
	}// namespace acwing836_408

	namespace acwing18 {
		TreeNode *rebuild(vector<int> &inorder, int in_begin, int in_end, vector<int> &preorder, int pre_begin, int pre_end) {
			if(in_begin == in_end) {
				return new TreeNode(inorder[in_begin]);
			}
			TreeNode *root = new TreeNode(preorder[pre_begin]);

			int left_in_cursor  = in_begin;
			int left_pre_cursor = pre_begin + 1;

			if(inorder[in_begin] == preorder[pre_begin]) {
				root->left = nullptr;
			} else {
				unordered_set<int> left = unordered_set<int>();
				while(inorder[left_in_cursor] != preorder[pre_begin]) {
					left.insert(inorder[left_in_cursor]);
					left_in_cursor++;
				}
				while(left.find(preorder[left_pre_cursor]) != left.end()) {
					left_pre_cursor++;
				}
				root->left = rebuild(inorder, in_begin, left_in_cursor - 1, preorder, pre_begin + 1, left_pre_cursor - 1);
			}

			if(inorder[in_end] == preorder[pre_begin]) {
				root->right = nullptr;
			} else {
				root->right = rebuild(inorder, left_in_cursor + 1, in_end, preorder, left_pre_cursor, pre_end);
			}

			return root;
		}

		TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
			if(preorder.empty() || inorder.empty()) {
				return nullptr;
			}
			return rebuild(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1);
		}
	}// namespace acwing18

	/**
	 * @brief 3786. 二叉排序树
	 */
	namespace acwing3786 {
		TreeNode *root = nullptr;
		const int INF  = 2e9;

		int main(istream &cin, ostream &cout) {
			int n;
			cin >> n;
			while(n--) {
				int t, x;
				cin >> t >> x;
				if(t == 1)
					insert(root, x);
				else if(t == 2)
					remove(root, x);
				else if(t == 3)
					cout << get_pre(root, x) << endl;
				else
					cout << get_suc(root, x) << endl;
			}
			return 0;
		}

		// 插入操作
		void insert(TreeNode *&root, int x) {
			/*
        1. 递归找到x的待插入的位置
        2. 如果x < 当前root就递归到左子树，反之，递归到右子树。
    */
			if(!root)
				root = new TreeNode(x);
			// 如果发现数值相同的话就判断一下;
			if(root->val == x)
				return;
			else if(x < root->val)
				insert(root->left, x);
			else
				insert(root->right, x);
		}

		void remove(TreeNode *&root, int x) {
			/*
        1. 待删除的结点只有左子树。立即可推出，左子树上的结点都是小于待删除的结点的，我们只需要把待删除结点删了然后左子树接上待删除结点的父节点就可以了。
        2. 待删除的结点只有右子树。立即可推出，右子树上的结点都是大于待删除的结点的，我们只需要把待删除结点删了然后右子树接上待删除结点的父节点就可以了。
        3. 待删除的结点既有左子树又有右子树。这个比上两个情况麻烦一点，但也不麻烦，需要读者理解的是，怎么能删除结点后还不改变中序遍历的结果，并且操作代价最小，显而易见，我们根据待删除结点的左子树可以得到最右下角的最后结点满足$<x$并且最接近x的结点，把这个结点覆盖待删除的结点，然后把这个结点删除，就完成了我们的操作。
    */

			// 如果不存在直接return
			if(!root)
				return;
			if(x < root->val)
				remove(root->left, x);
			else if(x > root->val)
				remove(root->right, x);
			else {
				if(!root->left && !root->right)
					root = NULL;
				else if(!root->left)
					root = root->right;
				else if(!root->right)
					root = root->left;
				else {
					auto p = root->left;
					while(p->right)
						p = p->right;
					root->val = p->val;
					remove(root->left, p->val);
				}
			}
		}

		// 输出数值 x 的前驱(前驱定义为现有所有数中小于 x 的最大的数)。
		int get_pre(TreeNode *root, int x) {
			if(!root)
				return -INF;
			if(root->val >= x)
				return get_pre(root->left, x);
			else
				return max(root->val, get_pre(root->right, x));
		}

		// 输出数值 x 的后继(后继定义为现有所有数中大于 x 的最小的数)。
		int get_suc(TreeNode *root, int x) {
			if(!root)
				return INF;
			if(root->val <= x)
				return get_suc(root->right, x);
			else
				return min(root->val, get_suc(root->left, x));
		}
	}// namespace acwing3786

	namespace acwing149 {
		bool Compare::operator()(huff_tree *const &a, huff_tree *const &b) {
			if(a->val != b->val)
				return a->val > b->val;
			else
				return a->height > b->height;
		}

		int main(istream &cin, ostream &cout) {
			u_int64_t n, k, w;
			cin >> n >> k;
			priority_queue<huff_tree *, vector<huff_tree *>, Compare> pq;
			for(int i = 0; i < n; i++) {
				cin >> w;
				pq.push(new huff_tree(w, 1, k));
			}
			while((n - 1) % (k - 1)) {
				pq.push(new huff_tree(0, 1, k));
				n++;
			}
			while(pq.size() > 1) {
				huff_tree *ht = new huff_tree(0, 0, k);
				for(int i = 0; i < k && !pq.empty(); i++) {
					huff_tree *least = pq.top();
					ht->height       = max(ht->height, least->height + 1);
					ht->children[i]  = least;
					ht->val += least->val;
					pq.pop();
				}
				pq.push(ht);
			}
			huff_tree *root = pq.top();
			queue<pair<huff_tree *, u_int64_t>> q;
			q.push(make_pair(root, 0));
			u_int64_t min_level = 0;
			u_int64_t sum       = 0;
			while(!q.empty()) {
				auto [ht, level] = q.front();
				q.pop();
				bool flag = true;
				for(int i = 0; i < k; i++) {
					if(ht->children[i] != nullptr) {
						flag = false;
						q.push(make_pair(ht->children[i], level + 1));
					}
				}
				if(flag) {
					sum += ht->val * level;
					min_level = max(min_level, level);
				}
			}
			cout << sum << endl
			     << min_level << endl;
			return 0;
		}
	}// namespace acwing149

	/**
	 * @brief 831. KMP字符串
	 */
	namespace acwing831_408 {
		vector<int> get_next(string p) {
			vector<int> next(p.size(), 0);
			for(int i = 1, j = 0; i < p.size(); i++) {
				while(j && p[i] != p[j])
					j = next[j - 1];
				if(p[i] == p[j])
					j++;
				next[i] = j;
			}
			return next;
		}

		int main(istream &cin, ostream &cout) {
			int n, m;
			string p, s;
			cin >> n >> p >> m >> s;
			vector<int> next = get_next(p);
			for(int i = 0, j = 0; i < m; i++) {
				while(j && s[i] != p[j])
					j = next[j - 1];
				if(s[i] == p[j])
					j++;
				if(j == n) {
					cout << i - n + 1 << ' ';
					j = next[j - 1];
				}
			}
			return 0;
		}
	}// namespace acwing831_408

	/**
	 * @brief 3385. 玛雅人的密码
	 */
	namespace acwing3385 {
		int main(istream &cin, ostream &cout) {
			int n;
			string s;
			cin >> n >> s;
			unordered_set<string> used;
			queue<pair<string, int>> q = queue<pair<string, int>>();
			q.push(make_pair(s, 0));
			used.insert(s);
			while(!q.empty()) {
				auto [current_s, current_step] = q.front();
				if(current_s.find("2012") != string::npos) {
					cout << current_step;
					return 0;
				}
				q.pop();
				for(int i = 0, j = 1; j < n; i++, j++) {
					string next_s = current_s;
					swap(next_s[i], next_s[j]);
					if(used.find(next_s) == used.end()) {
						used.insert(next_s);
						q.push(make_pair(next_s, current_step + 1));
					}
				}
			}
			cout << -1;
			return 0;
		}
	}// namespace acwing3385

	/**
	 * @brief 3429. 全排列
	 */
	namespace acwing3429 {
		void dfs(vector<char> &stk, int p, ostream &cout, string s) {
			if(p == s.length()) {
				for(char c: stk) {
					cout << c;
				}
				cout << endl;
				return;
			}
			for(int i = 0; i < s.length(); i++) {
				bool contain = false;
				for(int j = 0; j < p; j++) {
					if(stk[j] == s[i]) {
						contain = true;
						break;
					}
				}
				if(!contain) {
					stk[p] = s[i];
					dfs(stk, p + 1, cout, s);
				}
			}
		}

		int main(istream &cin, ostream &cout) {
			string s;
			cin >> s;
			vector<char> stk = vector<char>(s.length(), 0);
			dfs(stk, 0, cout, s);
			return 0;
		}
	}// namespace acwing3429

	/**
	 * @brief 858. Prim算法求最小生成树
	 */
	namespace acwing858_408 {
		// Custom hash function for pair<int, int>
		template<class T1, class T2>
		size_t pair_hash::operator()(const pair<T1, T2> &p) const {
			auto h1 = hash<T1>{}(p.first);
			auto h2 = hash<T2>{}(p.second);
			return h1 ^ h2;
		}

		// Custom equal function for pair<int, int>
		template<class T1, class T2>
		bool pair_equal::operator()(const pair<T1, T2> &p1, const pair<T1, T2> &p2) const {
			return p1.first == p2.first && p1.second == p2.second;
		}

		// Custom comparator for tuple<int, int, int>
		bool tuple_compare::operator()(const tuple<int, int, int> &t1, const tuple<int, int, int> &t2) {
			return get<2>(t1) > get<2>(t2);
		}

		int main(istream &cin, ostream &cout) {
			int n, m;
			int ans = 0;
			unordered_set<int> mst;
			unordered_map<int, unordered_set<pair<int, int>, pair_hash, pair_equal>> g;
			priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, tuple_compare> pq;
			cin >> n >> m;
			while(m--) {
				int u, v, w;
				cin >> u >> v >> w;
				if(g.find(u) == g.end()) {
					g[u] = unordered_set<pair<int, int>, pair_hash, pair_equal>();
				}
				g[u].insert(make_pair(v, w));
				if(g.find(v) == g.end()) {
					g[v] = unordered_set<pair<int, int>, pair_hash, pair_equal>();
				}
				g[v].insert(make_pair(u, w));
			}
			mst.insert(g.begin()->first);
			for(const auto &p: g[g.begin()->first]) {
				pq.push(make_tuple(g.begin()->first, p.first, p.second));
			}
			while(!pq.empty()) {
				auto [u, v, w] = pq.top();
				pq.pop();
				bool u_in = mst.find(u) != mst.end();
				bool v_in = mst.find(v) != mst.end();
				if(u_in && v_in)
					continue;
				int to_insert = u_in ? v : u;
				mst.insert(to_insert);
				ans += w;
				for(const auto &p: g[to_insert]) {
					if(mst.find(p.first) != mst.end() && mst.find(to_insert) != mst.end())
						continue;
					pq.push(make_tuple(to_insert, p.first, p.second));
				}
			}
			if(mst.size() == n) {
				cout << ans;
			} else {
				cout << "impossible";
			}
			return 0;
		}
	}// namespace acwing858_408

	/**
	 * @brief 849. Dijkstra求最短路 I
	 */
	namespace acwing849_408 {
		int main(istream &cin, ostream &cout) {
			int n, m;
			cin >> n >> m;
			unordered_map<int, unordered_map<int, int>> g = unordered_map<int, unordered_map<int, int>>();
			unordered_set<int> visited                    = unordered_set<int>();
			while(m--) {
				int x, y, z;
				cin >> x >> y >> z;
				if(g[x].count(y) == 0 || g[x][y] > z) {
					g[x][y] = z;// Only keep the smallest weight for multiple edges
				}
			}
			visited.insert(1);
			// Custom comparator for priority_queue to prioritize smaller weights
			auto cmp = [](pair<int, int> left, pair<int, int> right) {
				return left.second > right.second;// Compare by distance
			};
			priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
			pq.emplace(1, 0);
			while(!pq.empty()) {
				auto [u, d] = pq.top();
				pq.pop();
				if(u != 1 && (visited.find(u) != visited.end()))
					continue;
				visited.insert(u);
				if(u == n) {
					cout << d;
					return 0;
				}
				for(auto [v, w]: g[u]) {
					if(visited.find(v) != visited.end())
						continue;
					pq.emplace(v, d + w);
				}
			}
			cout << -1;
			return 0;
		}
	}// namespace acwing849_408

	/**
	 * @brief 854. Floyd求最短路
	 */
	namespace acwing854_408 {
		int main(istream &cin, ostream &cout) {
			int n, m, k;
			cin >> n >> m >> k;
			vector<vector<int>> g = vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MAX));
			for(int i = 1; i <= n; i++) {
				g[i][i] = 0;
			}
			while(m--) {
				int x, y, z;
				cin >> x >> y >> z;
				g[x][y] = min(g[x][y], z);
			}
			for(int k = 1; k <= n; k++) {
				for(int i = 1; i <= n; i++) {
					for(int j = 1; j <= n; j++) {
						if(g[i][k] != INT_MAX && g[k][j] != INT_MAX) {
							g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
						}
					}
				}
			}
			while(k--) {
				int x, y;
				cin >> x >> y;
				if(g[x][y] == INT_MAX) {
					cout << "impossible" << endl;
				} else {
					cout << g[x][y] << endl;
				}
			}
			return 0;
		}
	}// namespace acwing854_408

	/**
	 * @brief 848. 有向图的拓扑序列
	 */
	namespace acwing848_408 {
		int main(istream &cin, ostream &cout) {
			ostringstream oss;
			int n, m;
			cin >> n >> m;
			vector<unordered_set<int>> g = vector<unordered_set<int>>(n + 1, unordered_set<int>());
			vector<short> in             = vector<short>(n + 1, 0);
			while(m--) {
				int x, y;
				cin >> x >> y;
				if(g[x].find(y) != g[x].end())
					continue;
				g[x].insert(y);
				in[y]++;
			}
			bool flag = true;
			while(flag) {
				for(int i = 1; i <= n; i++) {
					if(in[i] == 0) {
						flag = false;
						oss << i << ' ';
						for(int j: g[i]) {
							in[j]--;
						}
						in[i] = -1;
					}
				}
				if(flag) {
					break;
				}
				flag = true;
			}
			for(int i = 1; i <= n; i++) {
				if(in[i] != -1) {
					cout << -1;
					return 0;
				}
			}
			cout << oss.str();
			return 0;
		}
	}// namespace acwing848_408

	/**
	 * @brief 3402. 等差数列
	 */
	namespace acwing3402 {
		int main(istream &cin, ostream &cout) {
			int n, m;
			cin >> n >> m;
			vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
			unordered_set<int> filled_rows = unordered_set<int>();
			unordered_set<int> filled_cols = unordered_set<int>();
			vector<int> row_cnt            = vector<int>(n + 1, 0);
			vector<int> col_cnt            = vector<int>(m + 1, 0);
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= m; j++) {
					cin >> a[i][j];
					if(a[i][j] > 0) {
						row_cnt[i]++;
						col_cnt[j]++;
					}
				}
			}
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= m; j++) {
					if(row_cnt[i] == n) {
						filled_rows.insert(i);
					}
					if(col_cnt[j] == m) {
						filled_cols.insert(j);
					}
				}
			}
			vector<vector<int>> a_cpy(a.begin(), a.end());
			queue<pair<bool, int>> q = queue<pair<bool, int>>();// <is_row,index>
			for(int i = 1; i < n; i++) {
				if(row_cnt[i] > 1) {
					filled_rows.insert(i);
					q.push(make_pair(true, i));
				}
			}
			for(int i = 1; i < m; i++) {
				if(col_cnt[i] > 1) {
					filled_cols.insert(i);
					q.push(make_pair(false, i));
				}
			}
			while(!q.empty()) {
				auto [is_row, index] = q.front();
				q.pop();
				if(is_row) {
					int l = 0;
					int r = 0;
					for(int j = 1; j <= m; j++) {
						if(a[index][j] > 0) {
							if(l == 0) {
								l = j;
							} else if(r == 0) {
								r = j;
							} else {
								break;
							}
						}
					}
					int d = (a[index][r] - a[index][l]) / (r - l);
					for(int j = 1; j <= m; j++) {
						if(a[index][j] == 0) {
							a[index][j] = a[index][l] + (j - l) * d;
							col_cnt[j]++;
							if(col_cnt[j] > 1 && filled_cols.find(j) == filled_cols.end()) {
								filled_cols.insert(j);
								q.emplace(false, j);
							}
						}
					}
				} else {
					int l = 0;
					int r = 0;
					for(int i = 1; i <= n; i++) {
						if(a[i][index] > 0) {
							if(l == 0) {
								l = i;
							} else if(r == 0) {
								r = i;
							} else {
								break;
							}
						}
					}
					int d = (a[r][index] - a[l][index]) / (r - l);
					for(int i = 1; i <= n; i++) {
						if(a[i][index] == 0) {
							a[i][index] = a[l][index] + (i - l) * d;
							row_cnt[i]++;
							if(row_cnt[i] > 1 && filled_rows.find(i) == filled_rows.end()) {
								filled_rows.insert(i);
								q.emplace(true, i);
							}
						}
					}
				}
			}
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= m; j++) {
					if(a_cpy[i][j] != a[i][j]) {
						cout << i << ' ' << j << ' ' << a[i][j] << endl;
					}
				}
			}
			return 0;
		}
	}// namespace acwing3402

	/**
	 * @brief 3472. 八皇后
	 */
	namespace acwing3472 {
		void dfs(vector<vector<bool>> board, int current_row, vector<string> &ans, vector<int> &ans_stk) {
			if(current_row == 8) {
				ostringstream oss;
				for(int i = 0; i < 8; i++) {
					oss << ans_stk[i] + 1;
				}
				ans.push_back(oss.str());
				return;
			}
			for(int k = 0; k < 8; k++) {
				if(board[current_row][k]) {
					vector<vector<bool>> next_board = vector<vector<bool>>(board.begin(), board.end());
					for(int i = 0; i < 8; i++) {
						for(int j = 0; j < 8; j++) {
							if(i == current_row || j == k || i + j == current_row + k || i - j == current_row - k) {
								next_board[i][j] = false;
							}
						}
					}
					ans_stk.push_back(k);
					dfs(next_board, current_row + 1, ans, ans_stk);
					ans_stk.pop_back();
				}
			}
		}
		int main(istream &cin, ostream &cout) {
			int n, b;
			cin >> n;
			vector<vector<bool>> board = vector<vector<bool>>(8, vector<bool>(8, true));
			vector<string> ans         = vector<string>();
			vector<int> ans_stk        = vector<int>();
			dfs(board, 0, ans, ans_stk);
			while(n--) {
				cin >> b;
				cout << ans[b - 1] << endl;
			}
			return 0;
		}
	}// namespace acwing3472

	/**
	 * @brief 3439. 首字母大写
	 */
	namespace acwing3439 {
		int main(istream &cin, ostream &cout) {
			bool ready = true;
			while(cin) {
				char c;
				c = cin.get();
				if(!cin) {
					break;
				}
				if(ready && islower(c)) {
					cout << (char) toupper(c);
				} else {
					cout << c;
				}
				ready = c == ' ';
			}
			return 0;
		}
	}// namespace acwing3439

	/**
	 * @brief 3379. 反序输出
	 */
	namespace acwing3379 {
		int main(istream &cin, ostream &cout) {
			string s;
			while(cin >> s) {
				ranges::reverse(s.begin(), s.end());
				cout << s << endl;
			}
			return 0;
		}
	}// namespace acwing3379

	/**
	 * @brief 3390. 特殊乘法
	 */
	namespace acwing3390 {
		int main(istream &cin, ostream &cout) {
			string a, b;
			cin >> a >> b;
			vector<int> a_vec(a.length(), 0);
			vector<int> b_vec(b.length(), 0);
			for(int i = 0; i < a.length(); i++) {
				a_vec[i] = a[i] - '0';
			}
			for(int i = 0; i < b.length(); i++) {
				b_vec[i] = b[i] - '0';
			}
			int sum = 0;
			for(int i = 0; i < a.length(); i++) {
				for(int j = 0; j < b.length(); j++) {
					sum += a_vec[i] * b_vec[j];
				}
			}
			cout << sum;
			return 0;
		}
	}// namespace acwing3390

	/**
	 * @brief 3397. 众数
	 */
	namespace acwing3397 {
		int main(istream &cin, ostream &cout) {
			int n, m;
			cin >> n >> m;
			vector<map<int, int>> a = vector<map<int, int>>(m, map<int, int>());
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					char c;
					cin >> c;
					int x = c - '0';
					if(a[j].find(x) == a[j].end()) {
						a[j][x] = 1;
					} else {
						a[j][x]++;
					}
				}
			}
			for(int i = m - 1; i >= 0; i--) {
				int max_val = 0;
				int max_key = 0;
				for(auto &p: a[i]) {
					if(p.second > max_val) {
						max_val = p.second;
						max_key = p.first;
					}
				}
				cout << max_key << endl;
			}
			return 0;
		}
	}// namespace acwing3397
}// namespace acwing