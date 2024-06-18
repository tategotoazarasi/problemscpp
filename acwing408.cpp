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
}// namespace acwing