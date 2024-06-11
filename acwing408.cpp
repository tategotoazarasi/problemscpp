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
}// namespace acwing